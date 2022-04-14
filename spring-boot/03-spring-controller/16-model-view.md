---
title: "Phân biệt giữa Get và Post"
description: "GET và POST là hai kỹ thuật phổ biến để gửi dữ liệu đến server và browser cần chúng để giao tiếp với server. Hai phương thức này khác biệt ở chỗ phương thức GET thêm dữ liệu được mã hóa vào URI trong khi trong với phương thức POST, dữ liệu được nối vào phần body chứ không phải URI."
keywords:
  [
    "Phân biệt giữa Get và Post",
    "post la gi",
    "get la gi",
    "get va post trong springboot",
    "get data la gi",
    "put va post khac nhau nhu the nao",
    "du ieu truyen di bang phuong thuc get",
    "du ieu truyen di bang phuong thuc post"
  ]
chapter:
  name: "Tổng quan về ứng dụng web"
  slug: "01-tong-quan-ve-ung-dung-web"
category:
  name: "SpringBoots"
  slug: "springboots"
image: https://kungfutech.edu.vn/thumbnail.png
position: 16
---
![springboot](https://1.bp.blogspot.com/-OCMnQs3ddyU/XgGHSerSuXI/AAAAAAAAATQ/TjN5MUE3MRoIyhrQ0qQ_unaqbchik_QHACEwYBhgL/s1600/Screen%2BShot%2B2019-12-24%2Bat%2B10.33.44%2BAM.png)
Công việc cuối cùng mà một action phải thực hiện là chọn View để hiển thị và chia sẽ dữ liệu với view này.Vì vậy kết quả return của một action thường là ModelAndView. Đối tượng này mang trong mình nó một đối tượng chứa dữ liệu (được gọi là thuộc tính model) và tên của một view để chỉ rõ view cần hiển thị.
View thì cần đúng một cái, nhưng dữ liệu được chia sẽ giữa action và view có thể cần nhiều hơn một đối tượng hoặc không cần nên kết quả của Action khá đa dạng:
- ModelAndView: mang cả model và view
- String: chỉ mang view còn model sẽ được chia sẽ tách riêng qua ModelMap
- Void: không hiễn thị kết quả bằng view mà sử dụng mã gửi trực tiếp qua đối tượng HttpServletResponse.

#### Return ModelAndView
Action sau sẽ trả về ModelAndView mang theo view có tên là success và model có tên là user được sinh ra từ lớp AccountInfo. Hơn thế nữa, ModelAndView còn đính kèm một attribute có tên message.
```
@GetMapping("/greetingaccount")
public ModelAndView greetingAccount(){
  Account account = new Account("van@codelean.vn", "Ha Van");
  ModelAndView modelAndView = new ModelAndView("success", "user", account),
  modelAndView.addObject("message", "Dang ky thanh cong");
  return modelAndView;
```
Ở phía view có thể hiễn thị dữ liệu được chia sẽ từ action này theo một số cách sau:
Truy xuất và hiễn thị email và message trên trang jsp bằng cách sử dụng EL:
  - ${user.email}
  - ${message}
Buộc dữ liệu lên form spring
```
<form:form commandName="user">
  Email: <form:input path="email"/>
</form:form>
```
