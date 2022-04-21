---
title: "Request Parameter và Path Variable"
description: "Là hai annotation được sử dụng để truy cập dữ liệu từ các request. Chúng được sử dụng vào những mục đích trong những trường hợp khác nhau."
keywords:
  [
    "requestparam va pathvariable trong spring boot",
    "requestparam spring boot",
    "pathvariable spring boot",
    "requestparam object spring boot",
    "pathvariable spring boot la gi",
    "requestparam spring boot la gi",
    "get all request parameters in spring boot",
    "khac nhau giua pathvariable vs requestparameter trong spring boot",
    "Cach lay du lieu tu URL trong spring boot",
    "cach su dung requestparam va pathvariable"
  ]
chapter:
  name: "Spring Controller"
  slug: "03-spring-controller"
category:
  name: "SpringBoots"
  slug: "springboots"
image: https://kungfutech.edu.vn/thumbnail.png
position: 19
---
![springboot](https://1.bp.blogspot.com/-OCMnQs3ddyU/XgGHSerSuXI/AAAAAAAAATQ/TjN5MUE3MRoIyhrQ0qQ_unaqbchik_QHACEwYBhgL/s1600/Screen%2BShot%2B2019-12-24%2Bat%2B10.33.44%2BAM.png)

 Cả **Request Parameter** và **Path Variable** đều sử dụng để gửi giá trị tới server. Cả hai đều là một phần của URL. 
 Request Parameter có dữ liệu theo cặp (key = value) được phân tách bằng dấu &.
<content-example>Ví dụ: URL sau mang một request parameter là name với giá trị là techmely
http://localhost:8080/techmely?name=techmely
  - key = name
  - value = techmely
</content-example>

Để nhận giá trị của một request parameter sử dụng annotation @RequestParam như sau:
```
public String getvaluewithRequestParam(@RequestParam String name){
    ...
}
```
Ngoài ra còn có thể sử dụng annotation @PathVariable:
```
public String getvaluewithPathVariable(@PathVariable String name){
    ...
}
```
http://localhost:8080/getvaluewithpathvariable/techmely
- value = techmely

Với @PathVariable không cần key truyền trên URL chỉ cần value.
Để sử dụng @PathVariable cần thêm biến thuộc tính value của annotation @RequestMapping
```
@RequestMapping(value="/getvaluewithpathvariable/{name}",method = GET)
public String getvaluewithPathVariable(@PathVariable String name, Model model){
    model.addAttribute("name", name);
    return "index";
}
```