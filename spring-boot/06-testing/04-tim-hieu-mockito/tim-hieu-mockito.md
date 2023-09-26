---
title: "Tìm hiểu Mockito: giả lập trong Unit Testing Java"
description: "Trong bài viết này, chúng ta sẽ tìm hiểu về Mockito - một thư viện phổ biến được sử dụng để giả lập các đối tượng và hành vi trong quá trình kiểm thử ứng dụng Java"
chapter:
  name: "Testing"
  slug: "chuong-06-testing"
category:
  name: "SpringBoots"
  slug: "springboots"
image: https://kungfutech.edu.vn/thumbnail.png
position: 4
---

Trong quá trình phát triển phần mềm, kiểm thử là một phần quan trọng để đảm bảo tính ổn định và chất lượng của ứng dụng. Trong bài viết này, chúng ta sẽ tìm hiểu về Mockito - một thư viện phổ biến được sử dụng để giả lập các đối tượng và hành vi trong quá trình kiểm thử ứng dụng Java.

## Tại sao cần sử dụng Mockito?

Khi bạn viết unit tests, mục tiêu là kiểm tra một phần của mã nguồn (một class hoặc một phương thức) mà không phụ thuộc vào các thành phần ngoại vi như cơ sở dữ liệu, giao diện người dùng, hoặc dịch vụ web. Điều này giúp đảm bảo rằng mã nguồn của bạn hoạt động đúng cách và không bị ảnh hưởng bởi các yếu tố bên ngoài. Mockito ra đời để giúp bạn thực hiện điều này một cách dễ dàng.

### Ví dụ về tại sao cần mock

Suppose bạn có một class `PaymentService` phụ thuộc vào một đối tượng `PaymentGateway` để thực hiện thanh toán. Bạn muốn kiểm tra xem `PaymentService` hoạt động đúng cách khi gọi `makePayment()` mà không thực sự thực hiện thanh toán thực tế (vì bạn không muốn tiêu tiền thật khi chạy unit test).

```java
public class PaymentService {
    private PaymentGateway paymentGateway;

    public PaymentService(PaymentGateway paymentGateway) {
        this.paymentGateway = paymentGateway;
    }

    public boolean processPayment(double amount) {
        // Some payment logic
        return paymentGateway.makePayment(amount);
    }
}
```

Trong trường hợp này, bạn muốn giả lập `PaymentGateway` để kiểm tra hành vi của `PaymentService` mà không thực sự gửi yêu cầu thanh toán đến cổng thanh toán thật sự.

## Cài đặt Mockito

Để sử dụng Mockito trong dự án Java của bạn, bạn cần thêm thư viện Mockito vào tệp `pom.xml` (đối với Maven) hoặc thêm vào `classpath` của dự án.

```xml
<!--Thêm dependency cho Mockito-->
<dependency>
    <groupId>org.mockito</groupId>
    <artifactId>mockito-core</artifactId>
    <version>3.12.4</version>
    <scope>test</scope>
</dependency>
```

## Cơ bản về Giả lập (Mocking)

### Tạo đối tượng giả lập

Để tạo một đối tượng giả lập (mock object), bạn có thể sử dụng `Mockito.mock()` hoặc đánh dấu một biến bằng `@Mock`. Dưới đây là ví dụ sử dụng cả hai cách:

```java
import org.junit.Test;
import org.mockito.Mock;
import org.mockito.Mockito;

public class MockingExample {

    @Mock
    private MyService myService; // Đánh dấu biến là một mock object

    @Test
    public void testMockCreation() {
        MyService mockService = Mockito.mock(MyService.class); // Tạo một mock object
        assertNotNull(mockService);
    }
}
```

### Thiết lập hành vi cho đối tượng giả lập

Sử dụng `Mockito.when().thenReturn()` hoặc các phương thức tương tự, bạn có thể thiết lập hành vi cho đối tượng giả lập. Ví dụ:

```java
import org.junit.Test;
import org.mockito.Mockito;

public class MockingExample {

    @Test
    public void testMockBehavior() {
        MyService mockService = Mockito.mock(MyService.class);

        // Thiết lập hành vi cho mock object
        Mockito.when(mockService.doSomething()).thenReturn("Hello, Mockito!");

        // Kiểm tra hành vi
        String result = mockService.doSomething();
        assertEquals("Hello, Mockito!", result);
    }
}
```

### Kiểm tra gọi phương thức

Bạn cũng có thể kiểm tra xem một phương thức đã được gọi bao nhiêu lần và với tham số nào bằng cách sử dụng các phương thức kiểm tra của Mockito như `Mockito.verify()`.

```java
import org.junit.Test;
import org.mockito.Mockito;

public class MockingExample {

    @Test
    public void testMethodCall() {
        MyService mockService = Mockito.mock(MyService.class);

        // Gọi phương thức
        mockService.doSomething();

        // Kiểm tra xem phương thức đã được gọi đúng 1 lần hay không
        Mockito.verify(mockService, times(1)).doSomething();
    }
}
```

## Sử dụng Mockito trong thực tế

### Giả lập đối tượng phụ thuộc

Khi bạn muốn kiểm tra một class có phụ thuộc vào một đối tượng khác, bạn có thể giả lập đối tượng phụ thuộc đó để kiểm tra hành vi của class chính. Ví dụ:

```java
public class OrderService {
    private PaymentGateway paymentGateway;

    public OrderService(PaymentGateway paymentGateway) {
        this.paymentGateway = paymentGateway;
    }

    public boolean placeOrder(double amount) {
        // Some order processing logic
        return paymentGateway.makePayment(amount);
    }
}
```

Trong unit test của `OrderService`, bạn có thể giả lập `PaymentGateway` để kiểm tra hành vi của `placeOrder()` mà không thực sự gửi thanh toán.

### Spy (Giả lập một phần đối tượng thật)

Spy cho phép bạn sử dụng một đối tượng thực tế nhưng theo dõi và giả lập một số phương thức c

ụ thể của nó. Điều này hữu ích khi bạn muốn giữ nguyên một phần thực thi thật của đối tượng, ví dụ: log hoặc logic xử lý. Ví dụ:

```java
import org.junit.Test;
import org.mockito.Spy;
import org.mockito.Mockito;

public class SpyExample {

    @Spy
    private List<String> list = new ArrayList<>();

    @Test
    public void testSpy() {
        list.add("one");
        list.add("two");

        // Spy vẫn ghi lại các phương thức thực thi thật
        assertEquals(2, list.size());

        // Spy cho phép bạn thay đổi hành vi cho các phương thức giả lập
        Mockito.when(list.size()).thenReturn(100);

        assertEquals(100, list.size());
    }
}
```

### Captor (Ghi lại tham số)

Captor cho phép bạn ghi lại các tham số được truyền vào một phương thức khi gọi nó để kiểm tra sau đó. Điều này hữu ích khi bạn muốn kiểm tra tham số của phương thức được gọi. Ví dụ:

```java
import org.junit.Test;
import org.mockito.ArgumentCaptor;
import org.mockito.Captor;
import org.mockito.Mock;
import org.mockito.Mockito;

public class CaptorExample {

    @Mock
    private List<Object> list;

    @Captor
    private ArgumentCaptor<Object> captor;

    @Test
    public void testCaptor() {
        list.add(1);

        // Ghi lại tham số của phương thức add
        Mockito.verify(list).add(captor.capture());

        // Kiểm tra tham số đã được ghi lại
        assertEquals(1, captor.getValue());
    }
}
```

### Inject Mock (Tiêm Mock)

Khi bạn muốn tiêm một đối tượng giả lập vào một đối tượng thực tế để kiểm tra hành vi của nó, bạn có thể sử dụng `@InjectMocks`. Ví dụ:

```java
@RunWith(MockitoJUnitRunner.class)
public class InjectMockExample {

    @Mock
    private DatabaseDriver driver;

    @InjectMocks
    private SuperService superService;

    @Test(expected = SQLException.class)
    public void testInjectMock() throws SQLException {
        // Giả lập cho driver trả về một danh sách (3,2,1) khi được gọi
        Mockito.doReturn(Arrays.asList(3, 2, 1)).when(driver).get();

        // Kiểm tra hành vi của superService
        assertEquals(driver, superService.getDriver());
        assertEquals(Arrays.asList(1, 2, 3), superService.getObjects());

        // Giả lập cho driver ném ra một exception
        Mockito.when(driver.get()).thenThrow(SQLException.class);
        superService.getObjects();
    }
}
```

::alert{type="success"}
Mockito là một thư viện mạnh mẽ cho việc giả lập trong kiểm thử đơn vị Java. Nó cho phép bạn kiểm tra hành vi của các class và phương thức mà không cần phụ thuộc vào các thành phần ngoại vi thực tế. Bằng cách sử dụng Mockito, bạn có thể đảm bảo tính ổn định của mã nguồn và tối ưu hóa quy trình phát triển phần mềm của mình. Đừng ngần ngại sử dụng Mockito để viết các unit test mạnh mẽ và đáng tin cậy cho ứng dụng của bạn.
::
