---
title: "Ứng dụng quản lý khách hàng: Kỹ thuật Phân trang và lọc"
description: "Pagination va Filter Là quá trình kết nối một chuỗi các trang đích có nội dung tương tự nhau."
keywords:
  [
    "Phân trang và lọc",
    "Phân trang và lọc trong spring boots",
    "Phân trang và lọc la gi spring boots",
    "Phân trang la gi spring boots",
    "Phân trang co tac dung gi spring boots",
    "lọc co tac dung gi spring boots",
    "lọc là gì spring boots",
    "Pagination là gì spring boots",
    "Filter là gì spring boots",
    "Pagination và Filter trong spring boots"
    ]
chapter:
  name: "Spring data JPA"
  slug: "06-spring-data-jpa"
category:
  name: "SpringBoots"
  slug: "springboots"
image: https://kungfutech.edu.vn/thumbnail.png
position: 5
---
## Ứng dụng quản lý khách hàng: Kỹ thuật Phân trang và lọc

![phantrangvaloc](https://1.bp.blogspot.com/-OCMnQs3ddyU/XgGHSerSuXI/AAAAAAAAATQ/GrgP9UJW-Y8C9LP0kgliqyjUXUOACFq2gCPcBGAYYCw/s1600/Screen%2BShot%2B2019-12-24%2Bat%2B10.33.44%2BAM.png)
### Sắp xếp trong spring data jpa
Để sắp xếp trong spring data jpa ta có khá nhiều cách ví dụ tìm kiếm tất cả các đối tượng customer và sắp xếp theo thứ tự name giảm dần(DESC)

- Đặt tên method(Query Creation)
```
List<Customer>findAllByOrderByName Desc();
```

- Sử dụng câu query bên trong @Query
```
@Query("SELECT * FROM Customer ORDER BY e.name DESC")
List<Customer>findAll();
```

- Sử dụng tham số Sort trong method:
```
@Query("SELECT * FROM Customere")
List<Customer>findAll(Sort sort);
```

- Muốn sắp xếp như nào thì ta sửa tham số sort theo điều kiện đó,ởđây sắp xếp theo name giảm dần sẽ là
```
Sort sort=Sort.by("name").descending();
```
### Phân trang trong spring data jpa
Để phân trang trong spring data jpa,trong method truy vấn, thay vì trả về 1 stream hay 1 list thì trả về 1 page
Ví dụ:
```
@Query("SELECT * FROM Customere")
Page<Customer>findCustomers(Pageable pageable);
```
Trong đó:
- Pageable sẽ chứa các thông tin phân trang như số phần tử được lấy,vị trí trang được lấy
- Page sẽ chứa kết quả trả về(gồm số phần tử,danh sách các phần tử)
- Pageable là 1 interface, để tạo nó ta sử dụng PageRequest
  
Ví dụ tạo pageable với thông tin là page thứ 1 với 10 phần tử:
```
Pageable pageable=PageRequest.of(1,10);
```
Ngoài ra bạn cũng có thể sắp xếp các phần tử trong page bằng cách thêm tham số sort vào trong pageable:
```
Sort sort = Sort.by("name").descending();
Pageable pageable = PageRequest.of(1,10,sort);
```
