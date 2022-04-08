---
title: "Bảo mật trong VPC"
description: "Amazon cung cấp 2 features để bảo mật(network security) và theo dõi(monitoring). NACL giống như 1 firewall để control traffic vào/ra subnet"
keywords: ["Network ACLs", "NACL trong AWS"]
author:
  fullname: Phan Văn Đức
  username: ducpv
  avatar: "/configs/author/ducpv.jpg"
category:
  name: "Khóa học AWS từ cơ bản đến nâng cao"
  slug: "aws"
chapter:
  name: "Virtual Private Cloud"
  slug: "vpc"
position: 20
---

## Security

- Amazon cung cấp 2 features để bảo mật(network security) và theo dõi(monitoring)
- **Security group and NACL** dùng cho network security, **Flow logs** cho network monitoring
- **Security group** hoạt động như firewall level của EC2
- **NACL - Network Access Control Lists** hoạt động như firewall level của subnet
- **Flow logs** cung cấp thông tin về network traffic

### Network ACLs (NACLs)

![NACL-network access control lists](https://user-images.githubusercontent.com/29729545/146217503-9914d98e-6d78-4f74-81e4-a619320da7be.png)

- NACL giống như 1 firewall để control traffic vào/ra subnet.
- Mỗi subnet trong VPC được liên kết với ít nhất 1 NACLs, mặc định khi tạo mới VPC sẽ tự động tạo 1 NACLs
- VPC, NACLs mặc định sẽ allow tất cả traffic inbound và outbound
- Bạn cũng có thể tạo 1 custome NACLs, nhưng mặc định nó sẽ block tất cả inbound/outbound cho đến khi thêm rule mới
- NACL có thế gán tới nhiều subnet, tuy nhiên 1 subnet chỉ có thể được gán bởi 1 NACL ở 1 thời điểm. Khi bạn gán với 1 NACL mới, những cái cũ sẽ bị gỡ bỏ.
- Một network ACL chứa 1 danh sách các quy tắc được đánh số. Bắt đầu bởi rule có số nhỏ nhất, để xác định lưu lượng mạng đươc cho phép ra vào. **Số nào càng nhỏ thì độ ưu tiên càng cao.** Số lớn nhất mà bạn có thể sử dụng cho 1 rule là **32766**
- NACL phân biệt rõ inbound, outbound rule. Ban có thể allow hay denied rule
- **Stateless**, có nghĩa là những traffic được allowed ở inbound thì KHÔNG tự động được allowed ở outbound
