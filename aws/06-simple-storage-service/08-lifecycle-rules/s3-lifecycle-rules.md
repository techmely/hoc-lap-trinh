---
title: "Giới thiệu S3 Lifecycle Rules"
description: "Chúng ta có thể chuyển đổi Object một cách linh hoạt giữa các storage classes trong Amazon S3. Lifecycle configuration có thể giúp bạn tự động hóa việc chuyển đổi Object"
chapter:
  name: "Simple Storage Serivce"
  slug: "chap-06-s3"
image: https://docs.aws.amazon.com/AmazonS3/latest/userguide/images/lifecycle-transitions-v3.png
position: 58
---

## S3 chuyển đổi giữa Storage Classes

Chúng ta có thể chuyển đổi Object một cách linh hoạt giữa các storage classes trong Amazon S3. **Lifecycle configuration có thể giúp bạn tự động hóa việc chuyển đổi Object**

![S3 chuyển đổi giữa Storage Classes
](https://docs.aws.amazon.com/AmazonS3/latest/userguide/images/lifecycle-transitions-v3.png)

- Khi Object không còn được thường xuyên truy cập, bạn có thể chuyển chúng sang Standard_IA...
- S3 standard là loại storage class linh hoạt nhất
- Ngược lại S3 Glacier Deep Archive là loại không thể chuyển đổi thành các storage class khác

## S3 Lifecycle Rules là gì

**Transition actions**

Định nghĩa những actions chuyển đổi Object sang Storage Class khác. Ví dụ:

- Chuyển Objects sang Standard IA class sau 60 ngày kể từ ngày tạo
- Chuyển Objects sang Glacier Deep Archive sau 365 ngày kể từ ngày tạo

**Expiration actions**

Dùng để configure Objects sẽ hết hạn (xóa đi) sau một thời gian nhất định. Ví dụ:

- Những log file có thể cấu hình để xóa đi sau 365 ngày.
- Xóa đi những version cũ của object (nếu enable versioning)
- Xóa những multi-part uploads ở trạng thái in-complete (chưa hoàn thành)

::alert{type="infor"}

<ul>
<li>Rules có thể tạo cho một prefix cụ thể (VD: s3://my-bucket/images/*)</li>
  <li>Rules cũng có thể tạo cho một Object tag cụ thể (VD: Object có tag là Name:Family)</li>
</ul>
::
