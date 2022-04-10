---
title: "Mô hình MVC"
description: ""
keywords:
  [
    "Phân biệt giữa Get và Post"
  ]
chapter:
  name: "Tổng quan về Spring"
  slug: "07-dependency-injection"
category:
  name: "SpringBoots"
  slug: "springboots"
image: https://kungfutech.edu.vn/thumbnail.png
position: 7
---

![Dependency Injection](https://1.bp.blogspot.com/-FYPUWhwwCbM/Xf7C4MxUsgI/AAAAAAAAAQo/RCI3w2QmRokvmt9TuK05qxBfbuWW-LKfQCLcBGAsYHQ/s640/Design-Patterns-Explained-%25E2%2580%2593-Dependency-Injection-with-Code-Examples-881x440.png)
### DI là gì

DI là design pattern một cách để hiện thực loC, trong đó các module phụ thuộc (dependency) sẽ được tiêm (inject) vào module cấp cao. 
Có thể hiểu DI một cách đơn giản như sau:

Các module không giao tiếp trực tiếp với nhau, mà thông qua interface. Module cấp thấp sẽ thực thi interface, module cấp cao sẽ gọi module cấp thấp thông qua
interface.
Ví dụ: Để giao tiếp với CSDL ta có interface IDatabase, các module cấp thấp là XMLDatabase, SQLDatabase. Module cấp cao là CustomerBusiness sẽ chỉ sử dụnginterface
IDatabase.

Việc khởi tạo các module cấp thấp sẽ do DI container thực hiện.
Ví dụ: Trong module CustomerBusiness, ta sẽ không khởi tạo IDatabase db = new XMLDatabase(), việc này sẽ do DI container thực hiện. Module CustomerBusiness sẽ không 
biết gì về module XMLDatabase hay SQLDatabase. 

Việc module gắn với interface nào sẽ được confic trong code hoặc trong file xml DI được dùng để làm giảm sự phụ thuộc giữa các module, dễ dàng hơn trong việc thay 
đổi module, bảo trì code và kiểm thử.

### Có 3 dạng DI
- Constructor Injection: Các dependency sẽ được container tiêm vào một lớp thông quan phương thức khởi tạo của lớp đó.
- Setter Injection: Các dependency sẽ được truyền vào một lớp thông qua các hàm setter.
- Interface Injection: Lớp cần tiêm sẽ thực thi một interface. Interface nay chứa một hàm tên inject. Container sẽ tiêm dependency vào một lớp thông qua việc gọi hàm inject của interface đó.

DI thường áp dụng với những dự án lớp vì đảm bảo code dễ bảo trì, dễ thay đổi, hầu hết các framework nổi tiếng như laravel, spring, struts 2, asp.net .v.v đều hỗ 
trợ hoặc tích hợp sẵn DI.
