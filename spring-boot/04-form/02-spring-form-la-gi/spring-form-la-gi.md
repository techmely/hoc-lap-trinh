---
title: "Spring Form là gì?"
description: "Spring MVC cung cấp thư viện thẻ giúp việc buộc dữ liệu từ bean vào các điều khiển trở nên dễ dàng hơn. Ưu điểm của Spring form.."
chapter:
  name: "Form"
  slug: "chuong-04-form"
category:
  name: "Spring Boot"
  slug: "spring-boot"
image: https://kungfutech.edu.vn/thumbnail.png
position: 2
---

## Spring Form

![springform](https://1.bp.blogspot.com/-OCMnQs3ddyU/XgGHSerSuXI/AAAAAAAAATQ/TjN5MUE3MRoIyhrQ0qQ_unaqbchik_QHACEwYBhgL/s1600/Screen%2BShot%2B2019-12-24%2Bat%2B10.33.44%2BAM.png)

Spring MVC cung cấp thư viện thẻ giúp việc buộc dữ liệu từ bean vào các điều khiển trở nên dễ dàng hơn.
Ưu điểm của Spring form:

- Cung cấp cơ chế buộc dữ liệu lên các điều khiển
- Form đơn giản, rõ ràng, dễ hiểu
- Khi thay đổi dữ liệu trong bean thì dữ liệu trên các điều khiển cũng thay đổi theo
- Cấp dữ liệu vào các list control trở nên rất đơn giản
- Kiểm và hiển thị lỗi dễ dàng

Để sử dụng các thẻ form ta cần khai báo:

```java
 <%@ taglib uri="http://www.springframework.org/tags/form" prefix="form"%>
```

Thẻ form được sử dụng để tạo một form. Ngoài các thuộc tính cơ bản của một thẻ form trong HTML, thẻ form còn có thêm thuộc tính quan trọng là: commandName hoặc modelAttribute, đây là tên của model được liên kết với form.
Thuộc tính commandName và modelAttribute có tác dụng giống nhau, với commandName là cách dùng cũ và modelAttribute là cách dùng mới.
Ví dụ:
![viduspringform](https://1.bp.blogspot.com/-iZgO7zjwRyw/XgEmB2h-cvI/AAAAAAAAARo/CUIivDU-LygUj4ol672SkCvk-2rdi5DDQCLcBGAsYHQ/s1600/c1.png)

Spring-form chỉ hỗ trợ một số thẻ, các thẻ còn lại chúng ta vẫn sử dụng html.
![tag spring-form](https://scontent.fhan2-4.fna.fbcdn.net/v/t1.15752-9/278236342_411137320446425_7256730851039102424_n.png?_nc_cat=105&ccb=1-5&_nc_sid=ae9488&_nc_ohc=uN4v66gBlk0AX_Z15WA&_nc_ht=scontent.fhan2-4.fna&oh=03_AVL6Bl54deh_Crc9SDZFqLa59GX_g5NnzqALVshpToDq6w&oe=62919F0F)

Các thẻ trên đều có một số thuộc tính quan trọng sau:

- **path**: được gán giá trị là tên của thuộc tính được liên kết với trường hiện tại.
- **items**: được gán giá trị là danh sách các hạng mục của các trường như select, options, radiobuttons, checkboxes.

Ví dụ:
**path** chứa giá trị là id, mà id là thuộc tính của lớp User.
![vidupath](https://1.bp.blogspot.com/-2_3uLCFQspI/XgEmHXSG1bI/AAAAAAAAARs/ugPhHMGGChEtEnGr0DV47Ii4J0vOywzWgCLcBGAsYHQ/s1600/c2.png)
**items** chứa giá trị hobbiesArray, mà hobbiesArray là thuộc tính của lớp User.
![viduitems](https://1.bp.blogspot.com/-MYmKUMLn1TE/XgEmLsB4vDI/AAAAAAAAARw/B9CtdJ8N5XEA7wQLp_Y5Jj2KVV04K45RQCLcBGAsYHQ/s1600/c3.png)
