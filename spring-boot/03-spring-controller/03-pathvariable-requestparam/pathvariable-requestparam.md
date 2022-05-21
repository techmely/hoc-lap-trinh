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
    "cach su dung requestparam va pathvariable",
  ]
chapter:
  name: "Spring controller"
  slug: "chuong-03-spring-controller"
category:
  name: "Spring Boot"
  slug: "spring-boot"
image: https://kungfutech.edu.vn/thumbnail.png
position: 3
---

## Request Parameter và Path Variable

![springboot](https://1.bp.blogspot.com/-OCMnQs3ddyU/XgGHSerSuXI/AAAAAAAAATQ/TjN5MUE3MRoIyhrQ0qQ_unaqbchik_QHACEwYBhgL/s1600/Screen%2BShot%2B2019-12-24%2Bat%2B10.33.44%2BAM.png)

Cả **Request Parameter** và **Path Variable** đều sử dụng để gửi giá trị tới server. Cả hai đều là một phần của URL. Chúng ta sẽ cùng tìm hiểu các khái niệm, thuộc tính và sự khác nhau của chúng ngay sau đây.

### 1. Request Parameter

**Request Parameter** có dữ liệu theo cặp (key = value) được phân tách bằng dấu &.
<content-example>Ví dụ:
URL sau mang một request parameter là name với giá trị là techmely
http://localhost:8080/techmely?name=techmely

- key = name
  value = techmely

URL mang nhiều request parameter được biểu diễn trên như sau
http://localhost:8080/techmely?param1=techmely&param2=hoclaptrinh

- key = param1
  value = techmely
- key = param2
  value = hoclaptrinh
  </content-example>

Để nhận giá trị của một request parameter sử dụng annotation @RequestParam như sau:

```
public String getValueWithRequestParam(@RequestParam(value="param1", required=true) String param1){
    ...
}
```

Ở đây annotation @RequestParam để khai báo là sẽ sử dụng nó để lấy các giá trị trên URL.
Một số thuộc tính của annotation :

- value="param1" : Khai báo để lấy giá trị tên là "param1" trên trình duyệt. Như vậy ứng với giá trị "techmely" trên trình duyệt sẽ gán vào giá trị String param1
- require = true : Thì chúng ta bắt buộc là trên url phải có tham số param1.

### 2. Path Variable

Với @PathVariable không cần key truyền trên URL chỉ cần value.
<content-example>Ví dụ:
URL sau mang giá trị là hoclaptrinh được gán trên URL
http://localhost:8080/techmely/hoclaptrinh

- value = hoclaptrinh
  </content-example>

Để sử dụng @PathVariable cần thêm biến thuộc tính value của annotation @RequestMapping

```
@RequestMapping(value="/getValueWithPathVariable/{name}",method = GET)
public String getValueWithPathVariable(@PathVariable String name, Model model){
    model.addAttribute("name", name);
    return "index";
}
```

- value=”/getValueWithPathVariable/{name}” :Khi sử dụng nó sẽ map với trình duyệt có định dạng là getValueWithPathVariable/hoclaptrinh
- @PathVariable chúng ta sẽ lấy giá trị là hoclaptrinh từ trình duyệt và gắn vào biến String name.

### 3. Kết luận

Cả 2 cách trên đều thực hiện chung một nhiệm vụ là lấy các tham số từ người dùng truyền lên. Bạn sử dụng cái nào cũng làm được mục đích của mình. Tuy nhiên tuỳ vào thiết kế của một hệ thống mà lựa chọn Request Param hoặc Path Variable để sử dụng mới đem lại hiệu quả cao
