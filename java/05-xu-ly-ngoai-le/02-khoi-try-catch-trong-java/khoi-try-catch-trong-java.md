---
title: "Khối try-catch trong Java"
description: "Khối try trong Java được sử dụng để bao quanh code mà có thể ném một Exception, nó phải được sử dụng bên trong phương thức, khối try phải được theo sau bởi hoặc khối catch hoặc khối finally"
chapter:
  name: "Xử lý ngoại lệ"
  slug: "chuong-05-xu-ly-ngoai-le"
category:
  name: "Java"
  slug: "java"
image: https://help.sap.com/doc/saphelp_nw75/7.5.5/en-US/0e/cf95afe85a470193719866cabd50db/loioc52db5d8c14148c2adec3d36716dea51_LowRes.png
position: 2
---

Khối try trong Java được sử dụng để bao quanh code mà có thể ném một `Exception`. Nó phải được sử dụng bên trong phương thức. Khối `try` phải được theo sau bởi hoặc khối `catch` hoặc khối `finally`.

## Khi nào cần sử dụng try catch trong Java

Khi thực thi một đoạn code Java nào đó, các lỗi khác nhau có thể xảy ra như:

- Lỗi do chính coder tạo ra
- Lỗi cú pháp
- Lỗi logic
- ... những lỗi mà chúng ta có thể không lường trước.

Ví dụ:

- Người dùng nhập dữ liệu không hợp lệ
- Truy cập vượt quá chỉ số mảng
- Chia một số cho 0 ……

Khi xảy ra lỗi, ngoại lệ, Java thông thường sẽ dừng thực thi chương trình và đưa ra một thông báo, hay nói cách khác là Java ném ra một exception – Ngoại lệ.

Quá trình xử lý `exception` được gọi là catch `exception` (bắt ngoại lệ), nếu `Runtime System` không xử lý được ngoại lệ thì chương trình sẽ kết thúc. Khối lệnh `try` trong java được sử dụng để chứa một đoạn code thực thi mà có thế trong quá trình thực thi nó sẽ xảy ra một ngoại lệ.

Sau một khối lệnh `try`, bạn phải khai báo khối lệnh `catch` hoặc `finally`, hoặc cả hai. Khối `catch` trong java được sử dụng để xử lý nếu xảy ra `Exception`, nếu không thì nó bị bỏ qua. Khối `catch` phải được sử dụng ngay sau khối `try`. Bạn có thể sử dụng nhiều khối `catch` với nhưng chỉ có một khối try duy nhất.

## Cú pháp của try catch trong Java

Cú pháp của try catch trong Java:

```java
try {
  // code có thể ném ra ngoại lệ
} catch(Exception_class_Name ex) {
  // code xử lý ngoại lệ
}
```

Cú pháp của try finally trong Java

```java
try {
  // code có thể ném ra ngoại lệ
} finally {
  // code trong khối này luôn được thực thi
}
```

Cú pháp của try catch finally trong Java

```java
try {
  // code có thể ném ra ngoại lệ
} catch(Exception_class_Name_1 ex) {
  // code xử lý ngoại lệ 1
} catch(Exception_class_Name_2 ex) {
  // code xử lý ngoại lệ 2
} catch(Exception_class_Name_n ex) {
  // code xử lý ngoại lệ n
} finally {
  // code trong khối này luôn được thực thi
}
```

## Ví dụ sử dụng try catch trong Java

<div class="example">trường hợp không có xử lý ngoại lệ</div>

```java
public class TestTryCatch1 {
    public static void main(String args[]) {
        int data = 50 / 0;  // ném ra ngoại lê ở đây
        System.out.println("rest of the code...");
    }
}
```

<content-result>
    <code>Exception in thread "main" java.lang.ArithmeticException: / by zero  at vn.tpv.exception1.TestTryCatch1.main(TestTryCatch1.java:5)</code>
</content-result>

Trong ví dụ trên, phần còn lại của code không được thực thi (dòng chữ "rest of the code..." không được in ra màn hình). Tất cả các lệnh không được thực thi sau khi xảy ra ngoại lệ. Khi giải quyết xử lý ngoại lệ

```java
public class TestTryCatch2 {
    public static void main(String args[]) {
        try {
            int data = 50 / 0;
        } catch (ArithmeticException e) {
            System.out.println(e);
        }
        System.out.println("rest of the code...");
    }
}
```

<content-result>
    <code>java.lang.ArithmeticException:</code>
    <code>by zero rest of the code...</code>
</content-result>

Trong ví dụ này, phần còn lại của code được thực thi nghĩa là dòng chữ "rest of the code..." được in ra màn hình.
