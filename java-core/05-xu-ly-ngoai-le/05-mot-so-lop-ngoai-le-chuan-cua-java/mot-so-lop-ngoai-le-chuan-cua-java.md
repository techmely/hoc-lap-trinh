---
title: "Một số lớp ngoại lệ chuẩn của Java"
description: "Bài này chúng ta sẽ tìm hiểu về một số lớp ngoại lệ chuẩn của Java, tự học lập trình java, chia sẻ kiến thức về java"
chapter:
  name: "Xử lý ngoại lệ"
  slug: "chuong-05-xu-ly-ngoai-le"
category:
  name: "Java"
  slug: "java"
image: https://help.sap.com/doc/saphelp_nw75/7.5.5/en-US/0e/cf95afe85a470193719866cabd50db/loioc52db5d8c14148c2adec3d36716dea51_LowRes.png
position: 5
---

Bảng dưới đây là một số lớp ngoại lệ chuẩn trong java

|       Tên lớp ngoại lệ        | Ý nghĩa                                                                                                  |
| :---------------------------: | :------------------------------------------------------------------------------------------------------- |
|           Throwable           | Đây là lớp cha của mọi lớp ngoại lệ trong Java                                                           |
|           Exception           | Đây là lớp con trực tiếp của lớp Throwable, nó mô tả một ngoại lệ tổng quát có thể xẩy ra trong ứng dụng |
|       RuntimeException        | Lớp cơ sở cho nhiều ngoại lệ java.lang                                                                   |
|      ArthmeticException       | Lỗi về số học, ví dụ như ‘chia cho 0’.                                                                   |
|    IllegalAccessException     | Lớp không thể truy cập.                                                                                  |
|   IllegalArgumentException    | Đối số không hợp lệ.                                                                                     |
| ArrayIndexOutOfBoundsExeption | Lỗi truy cập ra ngoài mảng.                                                                              |
|     NullPointerException      | Khi truy cập đối tượng null.                                                                             |
|       SecurityException       | Cơ chế bảo mật không cho phép thực hiện.                                                                 |
|    ClassNotFoundException     | Không thể nạp lớp yêu cầu.                                                                               |
|     NumberFormatException     | Việc chuyển đối từ chuỗi sang số không thành công.                                                       |
|         AWTException          | Ngoại lệ về AWT                                                                                          |
|          IOException          | Lớp cha của các lớp ngoại lệ I/O                                                                         |
|     FileNotFoundException     | Không thể định vị tập tin                                                                                |
|         EOFException          | Kết thúc một tập tin.                                                                                    |
|     NoSuchMethodException     | Phương thức yêu cầu không tồn tại.                                                                       |
|     InterruptedException      | Khi một luồng bị ngắt.                                                                                   |
