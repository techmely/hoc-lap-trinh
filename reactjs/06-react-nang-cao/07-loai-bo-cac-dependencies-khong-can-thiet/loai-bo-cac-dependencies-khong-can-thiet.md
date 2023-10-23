---
title: "Loại bỏ các dependencies không cần thiết"
description: "Các dependencies không cần thiết có thể làm cho effect của bạn chạy quá thường xuyên hoặc thậm chí tạo ra một vòng lặp vô hạn. Trong bài viết này, chúng ta sẽ tìm hiểu và loại bỏ các dependencies không cần thiết từ các effect của bạn"
chapter:
  name: "React nâng cao"
  slug: "chuong-06-react-nang-cao"
image: https://kungfutech.edu.vn/thumbnail.png
position: 7
---

Khi bạn viết một effect trong React, linter sẽ kiểm tra xem bạn đã bao gồm tất cả các giá trị phản ứng (như props và state) mà effect đọc trong danh sách các dependencies của nó chưa. Điều này đảm bảo rằng effect của bạn vẫn đồng bộ với các props và state mới nhất của component của bạn. Các dependencies không cần thiết có thể làm cho effect của bạn chạy quá thường xuyên hoặc thậm chí tạo ra một vòng lặp vô hạn. Trong bài viết này, chúng ta sẽ tìm hiểu và loại bỏ các dependencies không cần thiết từ các effect của bạn.

### Các dependencies cần phải phù hợp với code

Khi bạn viết một effect, bạn trước tiên xác định cách bắt đầu và kết thúc mọi thứ mà bạn muốn effect của mình thực hiện:

```jsx
const serverUrl = 'https://localhost:1234';

function ChatRoom({ roomId }) {
  useEffect(() => {
    const connection = createConnection(serverUrl, roomId);
    connection.connect();
    return () => connection.disconnect();
    // ...
}
```

Sau đó, nếu bạn để các dependencies của effect trống ([]), linter sẽ đề xuất danh sách dependencies chính xác:

```jsx
useEffect(() => {
  const connection = createConnection(serverUrl, roomId);
  connection.connect();
  return () => connection.disconnect();
}, []); // <-- Sửa lỗi ở đây!
```

Hãy điền vào danh sách dependencies dựa vào những gì linter nói:

```jsx
useEffect(() => {
  const connection = createConnection(serverUrl, roomId);
  connection.connect();
  return () => connection.disconnect();
}, [roomId]); // ✅ Tất cả các dependencies được khai báo
```

Các effect "phản ứng" đối với các giá trị phản ứng. Vì roomId là một giá trị phản ứng (có thể thay đổi do việc kết xuất lại), linter kiểm tra xem bạn đã chỉ định nó là một dependencies chưa. Nếu roomId nhận giá trị khác, React sẽ đồng bộ lại effect của bạn. Điều này đảm bảo rằng cuộc trò chuyện vẫn kết nối với phòng đã chọn và "phản ứng" với thay đổi trong danh sách thả xuống:

```jsx
const [roomId, setRoomId] = useState("general");
```

Để loại bỏ một dependencies, bạn phải "chứng minh" cho linter rằng nó không cần phải là một dependencies. Ví dụ, bạn có thể di chuyển roomId ra khỏi component của bạn để chứng minh rằng nó không còn phản ứng và sẽ không thay đổi trong các lần kết xuất lại:

```jsx
const serverUrl = "https://localhost:1234";
const roomId = "music"; // Không còn phải phản ứng nữa

function ChatRoom() {
  useEffect(() => {
    const connection = createConnection(serverUrl, roomId);
    connection.connect();
    return () => connection.disconnect();
  }, []); // ✅ Tất cả các dependencies đã được khai báo
  // ...
}
```

Bây giờ khi roomId không còn là một giá trị phản ứng (và không thay đổi trong các lần kết xuất lại), nó không còn cần phải là một dependencies:

```jsx
useEffect(() => {
  const connection = createConnection(serverUrl, roomId);
  connection.connect();
  return () => connection.disconnect();
}, []);
```

Tại sao bạn có thể chỉ định một danh sách dependencies trống ([]) bây giờ? Hiệu ứng của bạn thực sự không dependencies vào bất kỳ giá trị phản ứng nào nữa, vì vậy thực sự không cần chạy lại khi bất kỳ props hoặc state của component nào thay đổi.

### Để thay đổi các dependencies, hãy thay đổi code

Một biểu hiện tiêu biểu trong quá trình làm việc của bạn là:

1. Trước hết, bạn thay đổi code của effect hoặc cách khai báo các giá trị phản ứng của bạn.
2. Sau đó, bạn tuân theo linter và điều chỉnh danh sách dependencies để phù hợp với code bạn đã thay đổi.
3. Nếu bạn không hài lòng với danh sách các dependencies, bạn quay lại bước đầu tiên (và thay đổi code một lần nữa).

Phần cuối quan trọng. Nếu bạn muốn thay đổi danh sách các dependencies, hãy thay đổi code xung quanh trước tiên. Bạn có thể coi danh sách dependencies là danh sách tất cả các giá trị phản ứng được sử dụng trong code của effect của bạn. Bạn không chọn xem đặt gì vào danh sách đó. Danh sách miêu tả code của bạn. Để thay đổi danh sách dependencies, hãy thay đổi code.

### Mối nguy hiểm khi tắt linter cho dependencies

Nếu bạn có một code nguồn hiện có, bạn có thể có một số effect mà tắt linter như sau:

```jsx
useEffect(() => {
  // ...
  // 🔴 Tránh tắt linter như thế này:
  // eslint-ignore-next-line react-hooks/exhaustive-deps
}, []);
```

Khi các dependencies không phù hợp với code, có nguy cơ rất cao là sẽ xuất hiện lỗi. Bằng cách tắt linter, bạn "nói dối" React về các giá trị mà effect của bạn dependencies vào.

Thay vào đó, hãy sử dụng các kỹ thuật dưới đây.

### Loại bỏ các dependencies không cần thiết

Mỗi khi bạn điều chỉnh danh sách các dependencies của effect để phản ánh code, hãy xem xét danh sách các dependencies. Có hợp lý khi effect của bạn chạy lại khi bất kỳ trong số các dependencies này thay đổi không? Đôi khi, câu trả lời là "không":

1. Bạn có thể muốn thực hiện lại các phần khác nhau của effect của mình dưới các điều kiện khác nhau.
2. Bạn có thể muốn chỉ đọc giá trị mới nhất của một số dependencies thay vì "phản ứng" lại sự thay đổi của nó.
3. Một dependencies có thể thay đổi quá thường xuyên không cố ý vì nó là một đối tượng hoặc hàm.

Để tìm ra giải pháp đúng, bạn cần trả lời một số câu hỏi về effect của bạn. Hãy cùng xem qua chúng.

### Có nên di chuyển code này vào trình xử lý sự kiện không?

Điều đầu tiên bạn nên xem xét là liệu code này có nên là một effect không.

Hãy tưởng tượng một biểu mẫu. Khi gửi biểu mẫu, bạn đặt biến trạng thái "submitted" thành true. Bạn cần gửi yêu cầu POST và hiển thị thông báo. Bạn đã đặt logic này bên trong một effect mà "phản ứng" với submitted là true:

```jsx
function Form() {
  const [submitted, setSubmitted] = useState(false);

  useEffect(() => {
    if (submitted) {
      // 🔴 Tránh: Logic cụ thể cho sự kiện nằm bên trong effect
      post("/api/register");
      showNotification("Successfully registered!");
    }
  }, [submitted]);

  function handleSubmit() {
    setSubmitted(true);
  }

  // ...
}
```

Sau đó, bạn muốn thiết kế thông báo dựa trên chủ đề hiện tại, vì vậy bạn đọc chủ đề hiện tại. Vì chủ đề được khai báo trong cơ thể component, đó là một giá trị phản ứng, vì vậy bạn thêm nó vào danh sách các dependencies:

```jsx
function Form() {
  const [submitted, setSubmitted] = useState(false);
  const theme = useContext(ThemeContext);

  useEffect(() => {
    if (submitted) {
      // 🔴 Tránh: Logic cụ thể cho sự kiện nằm bên trong effect
      post('/api/register');
      showNotification('Successfully registered!', theme);
    }
  }, [submitted, theme]); // ✅ Tất cả các dependencies đã được kh

ai báo

  function handleSubmit() {
    setSubmitted(true);
  }

  // ...
}
```

Nhưng bằng cách làm điều này, bạn đã giới thiệu một lỗi. Hãy tưởng tượng bạn gửi biểu mẫu trước và sau đó chuyển đổi giữa các chủ đề Tối và Sáng. Chủ đề sẽ thay đổi, effect sẽ chạy lại và vì vậy nó sẽ hiển thị thông báo cùng một lần nữa!

Vấn đề ở đây là điều này không nên là một effect. Bạn muốn gửi yêu cầu POST và hiển thị thông báo dựa trên việc gửi biểu mẫu, đó là một tương tác cụ thể. Để chạy một số code dựa trên tương tác cụ thể, đặt logic đó trực tiếp vào trình xử lý sự kiện tương ứng:

```jsx
function Form() {
  const theme = useContext(ThemeContext);

  function handleSubmit() {
    // ✅ Tốt: Logic cụ thể cho sự kiện được gọi từ trình xử lý sự kiện
    post("/api/register");
    showNotification("Successfully registered!", theme);
  }

  // ...
}
```

Bây giờ code đã nằm trong một trình xử lý sự kiện, không còn phản ứng nữa - vì vậy nó sẽ chỉ chạy khi người dùng gửi biểu mẫu. Tìm hiểu thêm về cách lựa chọn giữa trình xử lý sự kiện và effect và cách xóa effect không cần thiết.

### Effect của bạn có đang thực hiện một số việc không liên quan không?

Câu hỏi tiếp theo bạn nên đặt cho chính mình là liệu effect của bạn có đang thực hiện một số công việc không liên quan.

Hãy tưởng tượng bạn đang tạo một biểu mẫu vận chuyển nơi người dùng cần chọn thành phố và khu vực của họ. Bạn lấy danh sách các thành phố từ máy chủ theo đất nước đã chọn để hiển thị chúng trong danh sách thả xuống:

```jsx
function ShippingForm({ country }) {
  const [cities, setCities] = useState(null);
  const [city, setCity] = useState(null);

  useEffect(() => {
    let ignore = false;
    fetch(`/api/cities?country=${country}`)
      .then(response => response.json())
      .then(json => {
        if (!ignore) {
          setCities(json);
        }
      });
    return () => {
      ignore = true;
    };
  }, [country]); // ✅ Tất cả các dependencies đã được khai báo

  // ...
```

Đây là một ví dụ tốt về lấy dữ liệu trong một effect. Bạn đồng bộ hóa trạng thái thành phố với mạng dựa trên prop country đã chọn. Bạn không thể làm điều này trong một trình xử lý sự kiện vì bạn cần phải tải khi ShippingForm được hiển thị và bất cứ khi nào country thay đổi (bất kể tương tác nào gây ra điều này).

Bây giờ, giả sử bạn đang thêm một hộp thả xuống thứ hai cho khu vực thành phố, mà nên tải danh sách khu vực cho thành phố hiện tại. Bạn có thể bắt đầu bằng cách thêm một cuộc gọi tải danh sách khu vực thứ hai bên trong cùng một effect:

```jsx
function ShippingForm({ country }) {
  const [cities, setCities] = useState(null);
  const [city, setCity] = useState(null);
  const [areas, setAreas] = useState(null);

  useEffect(() => {
    let ignore = false;
    fetch(`/api/cities?country=${country}`)
      .then(response => response.json())
      .then(json => {
        if (!ignore) {
          setCities(json);
        }
      });
    // 🔴 Tránh: Một effect duy nhất đồng bộ hóa hai quy trình độc lập
    if (city) {
      fetch(`/api/areas?city=${city}`)
        .then(response => response.json())
        .then(json => {
          if (!ignore) {
            setAreas(json);
          }
        });
    }
    return () => {
      ignore = true;
    };
  }, [country, city]); // ✅ Tất cả các dependencies đã được khai báo

  // ...
```

Tuy nhiên, vì effect này hiện sử dụng biến trạng thái city, bạn đã phải thêm city vào danh sách các dependencies. Điều này, lặp lại, đã gây ra một vấn đề: khi người dùng chọn một thành phố khác, effect sẽ chạy lại và gọi fetchCities(country) một lần nữa. Kết quả là bạn sẽ phải tải danh sách thành phố nhiều lần không cần thiết.

Vấn đề với code này là bạn đang đồng bộ hóa hai quy trình không liên quan:

1. Bạn muốn đồng bộ hóa trạng thái thành phố với mạng dựa trên prop country đã chọn. Bạn thực hiện điều này trong useEffect thứ nhất, và nó hoạt động hoàn hảo.
2. Bạn muốn đồng bộ hóa danh sách khu vực với thành phố hiện tại, nhưng điều này không cần phải được đặt trong effect. Thay vào đó, bạn nên sử dụng trình xử lý sự kiện được gọi khi thành phố thay đổi.

Điều này làm cho code sạch hơn và tránh sự trùng lặp không cần thiết:

```jsx
function ShippingForm({ country }) {
  const [cities, setCities] = useState(null);
  const [city, setCity] = useState(null);
  const [areas, setAreas] = useState(null);

  useEffect(() => {
    let ignore = false;
    fetch(`/api/cities?country=${country}`)
      .then((response) => response.json())
      .then((json) => {
        if (!ignore) {
          setCities(json);
        }
      });
    return () => {
      ignore = true;
    };
  }, [country]); // ✅ Tất cả các dependencies đã được khai báo

  // ✅ Tốt: Trình xử lý sự kiện thay đổi thành phố
  function handleCityChange(newCity) {
    setCity(newCity);
    fetch(`/api/areas?city=${newCity}`)
      .then((response) => response.json())
      .then((json) => {
        if (!ignore) {
          setAreas(json);
        }
      });
  }

  // ...
}
```

Bây giờ việc tải danh sách khu vực chỉ xảy ra khi người dùng thay đổi thành phố, và code đã trở nên sạch sẽ hơn.

### Hãy nói không với đối tượng và hàm

Trong ví dụ trước, bạn đã thấy cách tránh đồng bộ hóa không cần thiết bằng cách chuyển sang việc sử dụng các biến cơ sở thay vì đối tượng hoặc hàm. Tuy nhiên, đôi khi bạn không thể tránh khỏi việc đồng bộ hóa đối tượng hoặc hàm. Hãy xem xét ví dụ sau:

```jsx
function ProfilePage({ user }) {
  const [settings, setSettings] = useState(user.settings);

  useEffect(() => {
    // 🔴 Tránh: Đối tượng settings thay đổi, nhưng không thay đổi props.user.settings
    setSettings(user.settings);
  }, [user.settings]); // 🔴 Thụ động đồng bộ hóa với đối tượng

  // ...
}
```

Trong ví dụ này, bạn đang cố gắng đồng bộ hóa settings của trang cá nhân với props.user.settings bằng cách sử dụng useEffect. Tuy nhiên, vấn đề ở đây là props.user.settings là một đối tượng và không thay đổi khi bạn thay đổi giá trị bên trong đối tượng (ví dụ: user.settings.language = 'fr'). Do đó, effect này sẽ luôn chạy lại mỗi khi bạn cập nhật user.settings.

Một giải pháp là sử dụng giá trị nguyên thủy thay vì đối tượng:

```jsx
function ProfilePage({ user }) {
  const [settings, setSettings] = useState(user.settings);

  useEffect(() => {
    // ✅ Tốt: Sử dụng giá trị nguyên thủy thay vì đối tượng
    setSettings(user.settings);
  }, [user.settings]);

  // ...
}
```

Nhưng điều này không phải lúc nào cũng khả thi. Nếu bạn cần truy cập các phần tử cụ thể của đối tượng hoặc sử dụng các phương thức của đối tượng, bạn sẽ cần sử dụng đối tượng. Trong trường hợp này, bạn có thể chuyển hướng để tạo ra một effect tương tự như trước đó và sử dụng giá trị nguyên thủy trong trạng thái cục bộ để theo dõi các thay đổi:

```jsx
function ProfilePage({ user }) {
  const [settings, setSettings] = useState(user.settings);

  useEffect(() => {
    // ✅ Tốt: Sử dụng trạng thái cục bộ để theo dõi các thay đổi
    setSettings(user.settings);
  }, [user.settings]);

  useEffect(() => {
    // ✅ Tốt: Xử lý các thay đổi trong trạng thái cục bộ
    if (settings.language === "fr") {
      // Do something in French
    } else {
      // Do something in other languages
    }
  }, [settings]);

  // ...
}
```

Bằng cách sử dụng các effect này một cách riêng lẻ, bạn có thể kiểm soát chính xác khi nào bạn muốn thực hiện các thay đổi trong trạng thái cục bộ dựa trên các giá trị đối tượng.

::alert{type="success"}

- Loại bỏ các dependencies không cần thiết trong effect của bạn là một quá trình quan trọng để tối ưu hóa hiệu suất ứng dụng React của bạn và tránh các vấn đề liên quan đến vòng lặp không mong muốn. Điều quan trọng là hiểu rõ cách làm việc của linter và tuân theo hướng dẫn trên để điều chỉnh danh sách dependencies của effect sao cho phù hợp với code của bạn.
- Hãy nhớ rằng để loại bỏ các dependencies không cần thiết, bạn nên đặt code của bạn trước. Điều này giúp bạn xác định chính xác những giá trị nào là cần thiết cho effect của bạn. Tuyệt đối không nên tắt linter cho dependencies một cách không cân nhắc, vì điều này có thể dẫn đến lỗi không mong muốn và khó xác định.

::
