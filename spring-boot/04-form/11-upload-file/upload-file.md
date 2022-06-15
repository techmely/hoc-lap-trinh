---
title: "Upload file trong Spring Boot"
description: "Upload file trong Spring Boot."
keywords: [
    "khóa học Spring cơ bản",
     "Upload file trong Spring Boot",
      "Upload file spring boots",
      "cach Upload file spring boots",
      "lam the nao Upload file spring boots",
      "gioi han upload file spring boots"
      ]
chapter:
  name: "form"
  slug: "chuong-04-form"
category:
  name: "spring"
  slug: "spring"
image: https://kungfutech.edu.vn/thumbnail.png
position: 11
---

## Hướng dẫn upload file trong Spring Boot

Nếu mọi người muốn lưu trữ một ảnh vào trong cơ sở dữ liệu mọi người sẽ chọn cách nào? Mã hóa ảnh và lưu vào cơ sở dữ liệu hay là chúng ta sẽ lưu đường dẫn của nó. Mình sẽ chọn cách là lưu đường dẫn của file ảnh vào trong cơ sở dữ liệu và bài viết này mình sẽ hướng dẫn upload file trong Spring Boot. Những kiến thức liên quan đến bài viết như Lombok, Builder Pattern. Ngoài ra các bạn sau khi làm theo bài viết này còn có thể tự viết cho mình một project upload file trong Spring Boot sử dụng API.

### Cài đặt thư viện

Mọi người tạo ứng dụng Spring Boot và thêm một số thư viện như sau:

```
    implementation 'org.springframework.boot:spring-boot-starter-data-jpa'
    implementation 'org.springframework.boot:spring-boot-starter-data-jdbc'
    implementation 'org.springframework.boot:spring-boot-starter-thymeleaf'
    implementation 'org.springframework.boot:spring-boot-starter-web'
    compileOnly 'org.projectlombok:lombok'
    runtimeOnly 'mysql:mysql-connector-java'
    annotationProcessor 'org.projectlombok:lombok'
    testImplementation('org.springframework.boot:spring-boot-starter-test') {
        exclude group: 'org.junit.vintage', module: 'junit-vintage-engine'
    }

```

### Cấu hình file application.properties

Ở file application.properties chúng ta cấu hình như sau:

```
spring.datasource.driver-class-name=com.mysql.cj.jdbc.Driver
spring.datasource.url=jdbc:mysql://localhost:3306/product_management
spring.datasource.username=root
spring.datasource.password=123456
spring.jpa.show-sql=true
spring.jpa.hibernate.ddl-auto=none
spring.jpa.properties.hibernate.hbm2ddl.auto=update
spring.jpa.properties.hibernate.dialect=org.hibernate.dialect.MySQL5Dialect
upload.path=E:\\image\\
spring.servlet.multipart.max-file-size=5MB
spring.servlet.multipart.max-request-size=5MB
spring.resources.static-locations=file:///${upload.path}
```

Trong đó **upload.path** được cấu hình để lữu trữ ảnh sau khi upload xong. Mọi người có thể thay đổi lại đường dẫn theo ý muốn của mình.
**spring.servlet.multipart.max-file-size**: kích cỡ file lưu trữ tối đa.
**spring.servlet.multipart.max-request-size**: kích thước file upload lên server tối đa.
**spring.resources.static-locations=file: ///${upload.path}**: cấu hình đường dẫn file tĩnh đến ảnh của Spring Boot
### Hướng dẫn upload file trong SpringBoot
#### Model
Chúng ta tạo 2 file class lần lượt là Product và ProductFrom sử dụng Builder Pattern trong đó Product sẽ là Entity được tạo trong cơ sở dữ liệu có kiểu dữ liệu của thuộc tính image là String còn ProductForm là một class trung gian để lưu trữ ảnh dưới dạng MultipartFile. 

Product.java
```java
package com.example.demo.model;

import lombok.Data;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;

@Entity
@Data
public class Product {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    private String name;

    private String description;

    private String image;

    public Product(ProductBuilder productBuilder) {
        this.name = productBuilder.name;
        this.description = productBuilder.description;
        this.image = productBuilder.image;
    }

    public Product() {
    }

    public static class ProductBuilder {
        private final String name;
        private String description;
        private String image;

        public ProductBuilder(String name) {
            this.name = name;
        }

        public ProductBuilder description(String description) {
            this.description = description;
            return this;
        }

        public ProductBuilder image(String image) {
            this.image = image;
            return this;
        }

        public Product build() {
            return new Product(this);
        }
    }
}
```
ProductForm.java
```java
package com.example.demo.model;

import lombok.Data;
import org.springframework.web.multipart.MultipartFile;

@Data
public class ProductForm {
    private Long id;
    private String name;
    private String description;
    private MultipartFile image;

    public ProductForm() {
    }

    public ProductForm(ProductFormBuilder productFormBuilder) {
        this.name = productFormBuilder.name;
        this.description = productFormBuilder.description;
        this.image = productFormBuilder.image;
    }

    public static class ProductFormBuilder {
        private final String name;
        private String description;
        private MultipartFile image;

        public ProductFormBuilder(String name) {
            this.name = name;
        }

        public ProductFormBuilder description(String description) {
            this.description = description;
            return this;
        }

        public ProductFormBuilder image(MultipartFile image) {
            this.image = image;
            return this;
        }

        public ProductForm build() {
            return new ProductForm(this);
        }
    }
}
```
#### Repository
ProductRepository.java
```java
package com.example.demo.repository;

import com.example.demo.model.Product;
import org.springframework.data.repository.CrudRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface IProductRepository extends CrudRepository<Product, Long> {
}
```
#### Service
GeneralService.java
```java
package com.example.demo.service;

import java.util.Optional;

public interface GeneralService<T> {
    Iterable<T> findAll();

    Optional<T> findById(Long id);

    T save(T t);

    void remove(Long id);
}
```
IProductService.java
```java
package com.example.demo.service;

import com.example.demo.model.Product;

public interface IProductService extends GeneralService<Product> {
}
```
ProductService.java
```java
package com.example.demo.service;

import com.example.demo.model.Product;
import com.example.demo.repository.IProductRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.Optional;

@Service
public class ProductService implements IProductService {
    @Autowired
    private IProductRepository productRepository;

    @Override
    public Iterable<Product> findAll() {
        return productRepository.findAll();
    }

    @Override
    public Optional<Product> findById(Long id) {
        return productRepository.findById(id);
    }

    @Override
    public Product save(Product product) {
        return productRepository.save(product);
    }

    @Override
    public void remove(Long id) {
        productRepository.deleteById(id);
    }
}
```
ProductController.java
```java
package com.example.demo.controller;

import com.example.demo.model.Product;
import com.example.demo.model.ProductForm;
import com.example.demo.service.IProductService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Controller;
import org.springframework.util.FileCopyUtils;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.multipart.MultipartFile;
import org.springframework.web.servlet.ModelAndView;
import org.springframework.web.servlet.view.RedirectView;

import java.io.File;
import java.io.IOException;
import java.util.List;

@Controller
@RequestMapping("/products")
public class ProductController {
    @Autowired
    private IProductService productService;

    @Value("${upload.path}")
    private String fileUpload;

    @GetMapping
    public ModelAndView home(){
        ModelAndView modelAndView = new ModelAndView("/product/list");
        List<Product> products = (List<Product>) productService.findAll();
        modelAndView.addObject("products", products);
        modelAndView.addObject("message", "Thanh cong");
        return modelAndView;
    }
    @GetMapping("/create")
    public ModelAndView showFormCreate(){
        ModelAndView modelAndView = new ModelAndView("/product/create");
        modelAndView.addObject("product", new ProductForm());
        return modelAndView;
    }

    @PostMapping("/create")
    public RedirectView createProduct(@ModelAttribute ProductForm product){
        Product product1 = new Product.ProductBuilder(product.getName())
                .description(product.getDescription()).build();
        MultipartFile multipartFile = product.getImage();
        String fileName = multipartFile.getOriginalFilename();
        try {
            FileCopyUtils.copy(product.getImage().getBytes(), new File(this.fileUpload + fileName));
        } catch (IOException e) {
            e.printStackTrace();
        }
        product1.setImage(fileName);
        productService.save(product1);
        return new RedirectView("");
    }
}
```
Sử dụng **@Value** để lấy giá trị đường dẫn từ file application.properties.
### Thymleaf
list.html
```html
<!DOCTYPE html>
<html xmlns:th="http://www.thymeleaf.org">
<head>
    <meta charset="UTF-8">
    <title>Title</title>
</head>
<body>
<h1>Tasks</h1>
<table border="1px">
    <thead>
    <tr>
        <th>
            Name
        </th>
        <th>
            Description
        </th>
        <th>
            Image
        </th>
    </tr>
    </thead>
    <tbody>
    <tr th:each="product: ${products}">
        <td th:text="${product.getName()}"></td>
        <td th:text="${product.getDescription()}"></td>
        <td>
            <img th:src="${product.image}">
        </td>
    </tr>
    </tbody>
</table>
</body>
</html>
```
create.html
```html
<!DOCTYPE html>
<html xmlns:th="http://www.thymeleaf.org">
<head>
    <meta charset="UTF-8">
    <title>Create new product</title>
</head>
<body>
<h1>Create new product</h1>
<form method="post" th:object="${product}" enctype="multipart/form-data">
    <table>
        <tr>
            <td>Name</td>
            <td><input type="text" th:field="*{name}"></td>
        </tr>
        <tr>
            <td>Desciption</td>
            <td><input type="text" th:field="*{description}"></td>
        </tr>
        <tr>
            <td>Image</td>
            <td><input type="file" th:field="*{image}"></td>
        </tr>
        <tr>
            <td></td>
            <td><input type="submit" value="Create"></td>
        </tr>
    </table>
</form>
</body>
</html>
```
Vậy là bạn đã có lưu được đường dẫn ảnh vào trong cơ sở dữ liệu và lưu trữ file tại máy mình. Hi vọng bài viết này sẽ giúp ích cho mọi người trong việc xử lý lưu trữ file ảnh trong Spring Boot.














































