---
title: "Giới thiệu Javascript"
description: "Javascript là ngôn ngữ lập trình bậc cao, cực kỳ linh hoạt được sử dụng chủ yếu để tao ra ứng dụng chạy trên trình duyệt web."
chapter:
  name: "Giới thiệu Javascript"
  slug: "chuong-01-gioi-thieu-javascript"
image: https://kungfutech.edu.vn/thumbnail.png
position: 1
---

Javascript là ngôn ngữ lập trình bậc cao, cực kỳ linh hoạt được sử dụng chủ yếu để tao ra ứng dụng chạy trên trình duyệt web. Được tạo ra bởi Brendan Eich vào năm 1995. Nó thể viết code ở text editor và chạy nó trực tiếp trên trình duyệt mà không cần phải trải qua quá trình biên dịch như C++ hoặc Java.

Javascript tập trung nâng cao sự tương tác của người dùng với trang web. Bạn có thể làm cho trang web trở nên sống động và tăng tính tương tác hơn. Trong các ứng dụng web, người ta hay dùng JS để làm các hiệu ứng đặc biệt như sliders, pop-ups, hoặc xác thực dữ liệu các form (form validations) trước khi gửi dữ liệu lên server .v.v...


Vì nó cực kỳ linh hoạt, nên gần như rất nhiều lĩnh vực mà Js có thể tạo nên:

- Web App: [ReactJS](https://react.dev/), [VueJS](https://vuejs.org/), [Svelte](https://svelte.dev/), [Astro](https://astro.build/), [Solid](https://www.solidjs.com/)...
- Mobile App: Có thể tạo ra được các ứng dụng di động chạy được đa nền tảng, như IOS và Android, điển hình có thể kể đến là [React Native](https://reactnative.dev/), [Ionic](https://ionicframework.com/), và [NativeScript](https://nativescript.org/)
- Desktop App: Js cho phép lập trình viên tạo ra được các ứng dụng trên Desktop dựa trên website một cách dễ dàng, điển hình là [Tauri](https://tauri.app/),  [Electron](https://electronjs.org/) và [NeutralinoJS](https://neutralino.js.org/)
- Server-side app: Không chỉ ở mỗi website, JS đã được nâng tầm để đáp ứng nhu cầu của cộng đồng, xây các ứng dụng ở phía server như [Nodejs](https://nodejs.org/en), [Bun](https://bun.sh/), và [Deno](https://deno.com/)
- Graphic/Game: Nhắc đến game, JS ThreeJs, [BabylonJs](https://www.babylonjs.com/), [Phaser](https://phaser.io/), [PlayCanvas](https://playcanvas.com/), [GDevelop](https://gdevelop.io/), [Pixijs](https://pixijs.com/), [MelonJs](https://melonjs.org/)...
- Internet of Things(IoT): Vâng, JS có thể giúp bạn lập trình và điều khiển các thiết bị IoT, như nhà thông minh(smart home) và tự động hoá các quy trình làm việc của máy móc trong nhà máy sản xuất.
- Machine Learning: JS có thể dùng để train và deploy Machine Learning models. Gần đây nổi nhất là [Hugging Face](https://huggingface.co/) và [TensorFlow](https://www.tensorflow.org/).
- Virtual Reality(VR) & Augmented Reality(AR): Để tạo ra trải nghiệm vượt bậc trên browser, những công cụ như [AFrame](https://aframe.io/) và [BabylonJs](https://www.babylonjs.com/) sẽ giúp chúng ta xây dựng được những thứ không tưởng!
- Web Scraping: Nếu muốn đi lấy dữ liệu từ bên ngoài về(website, video, hình ảnh, thông tin...), hãy sử dụng các thư viện như [Cheerio](https://cheerio.js.org/), [Puppeteer](https://pptr.dev) hoặc [Playwight](https://playwright.dev).
- Automation: Với một số thao tác lặp đi lặp lại, như việc release sản phẩm theo định kỳ, hoặc chạy cron job vào một thời điểm nào đó, thì Js sẽ giúp bạn!
....

Và còn rất rất nhiều các lĩnh vực mà Javascript có thể làm được nữa!

## Javascript Engine

Khi nghe từ Engine, đó hẳn là 1 cái gì đó cao siêu và phức tạp. Nhưng nếu để phải giải thích cho một người mới học JS, thì đó nên là:

1. Engine được tạo ra với mục đích đọc -> Phân tích câu lệnh, cú pháp code
2. Nó chuyển đổi, biên dịch những dòng code đó sang mã mà máy tính có thể hiểu được(dãy số 0 và 1, VD: 000110101001100010101010110)
3. Máy chạy phần code và truyền tải thông điệp tới người dùng

Còn nếu muốn hiểu sâu sâu hơn nữa, thì bạn có thể đọc chi tiết về [V8](https://vi.wikipedia.org/wiki/Chrome_V8) Engine mà Chrome/Opera sử dung, hay [SpiderMonkey](https://en.wikipedia.org/wiki/SpiderMonkey) trong FireFox, hoặc [Nitro](https://vi.wikipedia.org/wiki/WebKit#JavaScriptCore) cho Safari.


![Khoá học javascript cơ bản](https://user-images.githubusercontent.com/29374426/156755813-bd4d0c75-d34c-4585-9423-42fdb45b66d0.png)

## Lịch sử Javascript

Javascript được tạo bởi lập trình viên kỳ cựu Brendan Eich, giới thiệu lần đầu năm 1995, xuất hiện trên trình duyệt Netscape, một trình duyệt phổ biến thời bấy giờ.

Ban đầu, ngôn ngữ lập trình này được gọi là LiveScript, sau này mới đổi tên thành Javascript. Mới đọc tên thì nhiều người sẽ nhầm tưởng Javascript có "họ hàng" với Java. Nhưng thực tế, hai ngôn ngữ này không hề có liên quan gì tới nhau cả, cây gia phả của chúng không hề chung gốc. Java là ngôn ngữ lập trình hướng đối tượng phức tạp, còn Javascript là một ngôn ngữ kịch bản (scripting language). Cú pháp của Javascript chủ yếu có hơi hướng ảnh hưởng từ ngôn ngữ C.

Điển hình nhất trong lịch sử của Javascript cho đến tận bây giờ đó là việc ra mắt ES6 vào 2015, nó dường như đã dịch chuyển cả một nền công nghiệp lập trình lúc bấy giờ. Và từ đó đến nay, Javascript như là 1 vị vua của ngôn ngữ lập trình với hàng loạt sản phẩm, thư viện, framework được sinh ra từ nó!

Để tìm hiểu sâu hơn, bạn có thể xem thêm phần lịch sử ra mắt các [phiên bản của ECMAScript](https://en.wikipedia.org/wiki/ECMAScript_version_history), và sự tương thích của ES6 so với các engine ở  [ở đây](https://kangax.github.io/compat-table/es6)

## Tại sao nên học Javascript?

Trước khi bạn quyết định đầu tư học một ngôn ngữ lập trình, đặc biệt với người chưa từng biết một ngôn ngữ lập trình nào, có thể bạn sẽ đắn đo, băn khoăn liệu mình có nên lao đầu vào ngôn ngữ lập trình này không? Liệu tương lai ngôn ngữ này có phát triển hay không?

Dưới đây là một số lý do để bạn bỏ công sức đầu tư học Javascript.

### Là ngôn ngữ lập trình phổ biến nhất

Khi bạn định hướng nghề nghiệp trong tương lai, việc chọn một ngôn ngữ lập trình phổ biến để theo đuổi là lựa chọn không hề tồi chút nào. Cũng giống như bạn đi kinh doanh, bán hàng vậy. Không ai dại gì lại đi bán mặt hàng mà thị trường không có nhu cầu sử dụng cả.

Theo một khảo sát mới nhất của Stackoverflow.com (website hỏi đáp dành cho lập trình viên lớn nhất thế giới) cho thấy, Javascript là ngôn ngữ lập trình phổ biến nhất, được rất nhiều lập trình viên chuyên nghiệp tin tưởng.

Không chỉ front-end, ngay cả các dự án back-end cũng ngày càng lựa chọn Javascript nhiều hơn.

### Javascript rất dễ học

Với tính mềm dẻo, linh hoạt, Javascript rất dễ học, đặc biệt là cho người mới học lập trình. Javascript biến các chi tiết phức tạp thành các bản tóm tắt, giúp mọi thứ trở nên dễ dàng hơn với người mới.

Không giống như các ngôn ngữ lập trình bậc cao khác, Javascript mang nhiều cảm giác về ngôn ngữ tự nhiên hơn. Tức là bạn nói sao thì viết như vậy

### Tài nguyên học có sẵn rất nhiều

Khi tiếp cận bất kỳ kỹ thuật mới nào, việc quan trọng đầu tiên phải nghĩ tới đó là tài liệu hướng dẫn có đầy đủ không! Mình từng tham dự một dự án mà sử dụng một framework cổ xưa, tài liệu chính chủ còn không có (chắc tác giả cũng bỏ rơi nó luôn), lúc đó mới thấu hiểu nỗi đau khổ khi không có tài liệu.

Với ngôn ngữ Javascipt nói chung, các JS frameworks như React, Vue... nói riêng thì đều có tài liệu hướng dẫn rất chi tiết và đầy đủ (cả chính chủ lẫn của cộng đồng). Do đó, bạn sẽ không gặp phải bất kỳ khó khăn nào trong việc tìm kiếm tài liệu hỗ trợ bạn trong việc học.

Ngoài ra, trên internet còn có hàng ngàn tutorial miễn phí để bạn có thể tham khảo. Tuy nhiên, việc dễ dàng tiếp cận hàng ngàn tài liệu cũng khiến bạn dễ bị bối rối, hỗn loạn kiến thức. Đó là lý do bạn tìm tới cuốn sách này.

### Một ngôn ngữ cho tất cả

Nếu trước đây, Javascript được sinh ra chỉ để xây dựng các trang web, thì nay đã khác. Javascript giờ đây có thể xây dựng mọi ứng dụng từ client-side tới back-end, các ứng dụng/game mobile, ứng dụng trên PC, kể cả các ứng dụng trên cloud, AI (Trí tuệ nhân tạo)...

Do đó, thay vì bạn phải đầu tư học rất nhiều ngôn ngữ, giờ bạn chỉ cần tập trung học Javascript cho thật tốt là đủ "cân cả bản đồ".

### Tiềm năng phát triển sự nghiệp lớn

Với việc ngày càng có nhiều doanh nghiệp và tổ chức chuyển sang sử dụng Javascript cho sản phẩm của mình. Do đó, nhu cầu tuyển dụng lập trình viên Javascript cũng tăng lên rất nhiều.

Theo một khảo sát của Devskiller.com, 70% các công ty công nghệ muốn tuyển một lập trình viên Javascript.

Ở Việt Nam thì sao? Đảo qua một loạt các trang tuyển dụng lớn như Vietnamworks, ITviec... nhu cầu tuyển lập trình viên React, Angular, Vue, NodeJS... rất nhiều, mức lương cũng rất cao (toàn trên 2k$ cho một senior developer).

Tóm lại, theo đánh giá của mình, việc chọn Javascript là ngôn ngữ lập trình chính cho sự nghiệp là một lựa chọn đáng giá, xứng đáng với mồ hôi nước mắt. Ok, giờ là lúc chúng ta cùng nhau chinh phục Javascript thôi!

## Ưu điểm của Javascript

Để nói về ưu điểm của một ngôn ngữ lập trình thì có thể kể hàng chục trang giấy. Bởi vì, mỗi ngôn ngữ được tạo ra, tác giả đều sẽ cố gắng tối ưu, thiết kế sao cho tốt nhất. Không phải ngẫu nhiên mà Javascript được cộng đồng đón nhận rộng rãi đến như vậy

Tuy vậy, để bạn hiểu được thế mạnh của Javascript, mình sẽ liệt kê một số nét đặc trưng khiến Javascript nổi bật hơn các ngôn ngữ lập trình khác

### Tích hợp sẵn trong hầu hết các trình duyệt

Không giống như nhiều ngôn ngữ phát triển web khác, ví dụ flash, Java... người dùng muốn sử dụng được thì phải cài đặt thêm plugin cho trình duyệt.

Javascript thì khác, hầu hết trình duyệt hiện đại đều đã tích hợp sẵn. Do đó, việc bạn sử dụng JS để phát triển ứng dụng sẽ rất thuận lợi.

### Một ngôn ngữ lập trình vô cùng linh hoạt

Rất nhiều lập trình viên thích trường phái functional programming. Functional Programming một phương pháp lập trình dựa trên các hàm toán học (function), tránh việc thay đổi giá trị của dữ liệu. Nó có nhiều lợi ích như : các khối xử lý độc lập dễ tái sử dụng, thuận lợi cho việc thay đổi logic hoặc tìm lỗi chương trình.

Javascript là ngôn ngữ sinh ra là để dành cho functional programming.

Hai trong số tính năng nối bật nhất của Javascript là cho phép gán một hàm cho bất kỳ biến nào và tạo một hàm chấp nhận tham số là một hàm khác.

### Khả năng tự detect trình duyệt và hệ điều hành

Đôi khi, trong một số ứng dụng, bạn gặp vấn đề và cần phải viết mã nguồn tương thích với từng trình duyệt web hoặc hệ điều hành. Javascript được thiết kế để có thể tự nhận biết được chạy trên trình duyệt gì, hệ điều hành nào.

Điều này, cho phép bạn dễ dàng điều chỉnh mã nguồn để ứng dụng đáp ứng và tương thích với mọi hệ điều hành.

### Hỗ trợ cả lập trình hướng đối tượng (OOP)

Lập trình hướng đối tượng cũng là một trường phái lập trình rất phổ biến, khi tất cả mọi thứ của ứng dụng đều xoay quanh đối tượng (Object - Class). Javascript cung cấp rất nhiều công cụ để bạn làm việc với đối tượng, đồng thời nó cũng dễ học, dễ sử dụng.

Nói một cách chính xác hơn, có thể coi Javascript là ngôn ngữ dựa trên đối tượng, vì lý do:

- Không hỗ trợ đầy đủ các đặc điểm của OOP như: đa hình, kế thừa
- Có sẵn kiểu dữ liệu đối tượng. Ví dụ: JavaScript có sẵn đối tượng window...

### Học một ngôn ngữ dùng mọi nơi

Phần này mình chỉ nhắc lại thôi. Nếu trước đây, Javascript được tạo ra chỉ để phát triển các ứng dụng front-end chạy trên trình duyệt thì giờ đây mọi chuyện đã khác. Có thể bạn chưa biết, trước đây một full stack developer cần phải học rất nhiều ngôn ngữ lập trình. Có thể kể tên nhẹ nhàng như: front-end thì có javascript, back-end thì có PHP, JAVA, Ruby, Golang..., ứng dụng mobile thì có Java, Kotlin, Swift... rất nhiều ngôn ngữ phải học.

Nhưng ngày nay, bạn chỉ cần học duy nhất Javascript là đủ. Biết Javascript, bạn có thể xây dựng các ứng dụng web (cái này tất nhiên rồi), xây dựng ứng dụng phía back-end (nhờ Node.JS), xây dựng ứng dụng mobile (React Native, Ionic...)
