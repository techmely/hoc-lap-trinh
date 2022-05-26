---
title: "Expression Language."
description: "EL là sự rút ngắn tuyệt vời trong việc viết code, làm việc với các thuộc tính đặt trong các phạm vi (như
page, request, session và application)"
keywords:
  [
    "spring expression language la gi",
    "spring expression language dung lam gi",
    "cach du dung spring expression language",
    "kien truc spring boot",
    "expression language trong spring boot",
    "rut ngan code trong spring boots",
    "expression language trong spring boot là gì"
  ]
chapter:
  name: "Form"
  slug: "04-form"
category:
  name: "SpringBoots"
  slug: "springboots"
image: https://kungfutech.edu.vn/thumbnail.png
position: 8
---
## Expression Language

![expressionlanguage](https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcRx_QhMvFajTTjZzExmny2ahl2McbLx5wJFbw&usqp=CAU)
### Tổng quát
Là một ngôn ngữ biểu đạt. Nó rất mạnh mẽ trong hoạt động của nó và cung cấp hỗ trợ cho các truy vấn và thao tác với một biểu đồ đối tượng trong thời gian chạy. Tính năng này được phát hành cùng với Spring 3.0 vào năm 2009.
### Cú pháp : ${expr}
Ở đây expr chỉ định chính biểu thức. Các toán tử phổ biến nhất trong JSP EL là . và [] . Hai toán tử này cho phép bạn truy cập các thuộc tính khác nhau của Java Beans và các đối tượng JSP tích hợp sẵn.
<content-example>
- ${salary * 2}: nhân đôi giá trị của thuộc tính salary và trả về giá trị của biểu thức salary * 2
- ${param.salary}: trả về giá trị của tham số salary
- ${employee.salary}: trả về giá trị của thuộc tính salary thuộc đối tượng employee
- ${sessionScope ["salary"]}: trả về giá trị của thuộc tính là salary đặt trong session
</content-example>
Một ví dụ khác thao tác với controller:
<content-example>
```
Controller
@RequestMapping ("/techmely/demo")
public String sayHelloWithTechMely (ModelMap model, HttpSession session){
      session.setAttribute ("name", "techmely");
      model.addAttribute ("age", 1)
}
View
<li>
name:${name}, 
salary: ${salary}, 
sessionScope.name: ${sessionScope.name}, 
sessionScope.age:Ş{sessionScope.age}
</li>
```
</content-example>
<content-result>
name                        : codeleanvn, 
age                           :1,
sessionScope.name : codeleanvn,
sessionScope.age    :

</content-result>

### Ưu điểm

-  Có thể rút ngắn code.
-  Lập trình viên chỉ cần quan tâm đến việc viết các biểu thức trong một số tệp thuộc tính nhất định.
-  Tương thích và đi kèm nhiều tính năng: Biểu thức chính quy, toán tử, biến,.....

## Truy xuất thuộc tính của bean

Nếu thuộc tính là một bean thì EL cho phép truy xuất các thuộc tính một cách đơn giản.
### Cú pháp: ${bean.property}
Với cú pháp này trả về giá trị của thuộc tính propery của thuộc tính bean. Có nghĩa là trả về giá trị của phương thức bean.getProperty()
<content-example>
${customer.name} trả về customer.getName()

Controller
```
@RequestMapping ("/techmely/demoEL")
public String demo2 (ModelMap model){
     Student student=new Student ("techmely", 10.0, "APP");
    model.addAttribute ("student", student);
     return "el/sample";
}
```
View
```
<li>name:${student.name}, mark: ${student.mark }</li>
```
</content-example>

<content-result>
name: techmely, 
mark: 10.0
</content-result>

