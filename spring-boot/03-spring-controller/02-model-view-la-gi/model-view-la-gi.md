---
title: "Model and View là gì"
description: "Là sự kết hợp của 2 khía cạnh truyền dữ liệu và view."
keywords:
  [
    "Model and View",
    "post la gi",
    "get la gi",
    "get va post trong springboot",
    "get data la gi",
    "put va post khac nhau nhu the nao",
    "du ieu truyen di bang phuong thuc get",
    "du ieu truyen di bang phuong thuc post",
  ]
chapter:
  name: "Spring controller"
  slug: "chuong-03-spring-controller"
category:
  name: "Spring Boot"
  slug: "spring-boot"
image: https://kungfutech.edu.vn/thumbnail.png
position: 1
---

## Model and View

![springboot](https://1.bp.blogspot.com/-OCMnQs3ddyU/XgGHSerSuXI/AAAAAAAAATQ/TjN5MUE3MRoIyhrQ0qQ_unaqbchik_QHACEwYBhgL/s1600/Screen%2BShot%2B2019-12-24%2Bat%2B10.33.44%2BAM.png)

Công việc cuối cùng mà một action phải thực hiện là chọn View để hiển thị và chia sẽ dữ liệu với view này.Vì vậy kết quả return của một action thường là ModelAndView. Đối tượng này mang trong mình nó một đối tượng chứa dữ liệu (được gọi là thuộc tính model) và tên của một view để chỉ rõ view cần hiển thị.
View thì cần đúng một cái, nhưng dữ liệu được chia sẽ giữa action và view có thể cần nhiều hơn một đối tượng hoặc không cần nên kết quả của Action khá đa dạng:

- ModelAndView: mang cả model và view
- String: chỉ mang view còn model sẽ được chia sẽ tách riêng qua ModelMap
- Void: không hiễn thị kết quả bằng view mà sử dụng mã gửi trực tiếp qua đối tượng HttpServletResponse.

#### Return ModelAndView

Action sau sẽ trả về ModelAndView mang theo view có tên là success và model có tên là user được sinh ra từ lớp AccountInfo. Hơn thế nữa, ModelAndView còn đính kèm một attribute có tên message.

```java
@GetMapping("/greetingaccount")
public ModelAndView greetingAccount(){
  Account account = new Account("techmely@kungfutechh.vn", "Ha Van");
  ModelAndView modelAndView = new ModelAndView("success", "user", account),
  modelAndView.addObject("message", "Dang ky thanh cong");
  return modelAndView;
```

Ở phía view có thể hiễn thị dữ liệu được chia sẽ từ action này theo một số cách sau:
Truy xuất và hiễn thị email và message trên trang jsp bằng cách sử dụng EL:

- ${user.email}
- ${message}
  Buộc dữ liệu lên form spring

```xml
<form:form commandName="user">
  Email: <form:input path="email"/>
</form:form>
```

#### Return String

Thay vì kết quả của action trả về ModelAndView thì trường hợp này chỉ trả về String chỉ ra tên view muốn hiển thị, còn model và thuộc tính đính kèm được đặt trong ModelMap. Với cách viết này sẽ linh hoạt hơn vì tách rời view và model do đó được sử dụng nhiều hơn.

```java
@GetMapping("/greeting")
public String greeting(@RequestParam String username, Model model){
  model.addAttribute("username", username);
  return "index";
```

#### Return void

Đôi khi một action chỉ thực hiện một công việc logic nào đó mà không cần có một view để hiễn thị kết quả. Trong trường hợp đó action không trả kết quả gì là lựa chọn tốt nhất. Ví dụ sau đây khi gọi action thì bạn sẽ nhận được kết quả hiển thị trên trang web là "Hello World" mà không cần phải xây dựng View.

```java
@RequestMapping (value=" myaction")
public void mymethod (HttpservletResponse response) throws IOException {
      PrintWriter out = response.getWriter();
      out.println ("Hello World !");
```
