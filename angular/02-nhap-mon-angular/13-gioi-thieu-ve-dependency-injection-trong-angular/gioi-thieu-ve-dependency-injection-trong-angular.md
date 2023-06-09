---
title: "Giới thiệu Dependency Injection trong Angular"
description: "Dependency Injection (DI) là một pattern rất quan trọng trong lập trình, có thể bạn đã nghe qua những Spring Framework của Java hay ASP.NET có support DI, vậy với Frontend application thì có thật sự cần thiết? Hiện nay có rất nhiều Frontend Framework có support DI, Angular sử dụng rất nhiều và nó có riêng một DI framework được thiết kế để đáp ứng được yêu cầu về mặt như kiến trúc hệ thống của Angular."
keywords: ["Dependency Injection trong Angular", "Dependency Injection là gì"]
chapter:
  name: "Nhập môn Angular"
  slug: "chuong-02-nhap-mon-angular"
category:
  name: "Angular"
  slug: "angular"
image: https://kungfutech.edu.vn/thumbnail.png
position: 13
---

## Dependency Injection là gì?

Dependency Injection (DI) là một pattern rất quan trọng trong lập trình, có thể bạn đã nghe qua những Spring Framework của Java hay ASP.NET có support DI, vậy với Frontend application thì có thật sự cần thiết?

Hiện nay có rất nhiều Frontend Framework có support DI, Angular sử dụng rất nhiều và nó có riêng một DI framework được thiết kế để đáp ứng được yêu cầu về mặt như kiến trúc hệ thống của Angular.

## DI là gì?

Giả sử chúng ta đang làm ứng dụng giỏ hàng của một trang thương mại điện tử, thông thường chúng ta có thể tách những phần xử lý business ra thành một class để giảm responsibility của component, cũng như tăng tính reuseable của phần business logic đó.

Lúc này chúng ta có thể có các thành phần như sau:

```ts
class ProductModel {
  sku: string;
  name: string;
  price: number;
}

interface CartItem {
  product: ProductModel;
  quantity: number;
}

class CartService {
  selectedProducts: CartItem[] = [];
  calculateTotal(): number {
    return this.selectedProducts.reduce(
      (total, item) => item.product.price * item.quantity + total,
      0
    );
  }
  addToCart(): void {
    // logic here
  }
}

class ProductComponent {
  cartService: CartService;
}
```

Các bạn có thể thấy rằng, class `ProductComponent` của chúng ta bị phụ thuộc vào (depend on) class `CartService`. Khi `ProductComponent` cần call các method của `CartService` chúng ta cần khởi tạo hoặc yêu cầu để lấy về một instance của service đó.

### Khởi tạo bên trong `ProductComponent`

Để khởi tạo instance của một class bên trong một class khác, chúng ta có thể chỉ cần `new` là được.

```ts
class ProductComponent {
  cartService: CartService;
  constructor() {
    this.cartService = new CartService();
  }
}

// tương đương với

class ProductComponent {
  cartService: CartService = new CartService();
}
```

Nếu trong trường hợp như trên, rõ ràng chúng ta bị ràng buộc chặt chẽ giữa hai class (Tight Coupling), nếu bạn muốn thay đổi implementation khác của `CartService` thì bắt buộc phải sửa code của `ProductComponent`, và sẽ kéo theo phải test lại cả hai class.

### Injection (Request để lấy về instance)

Nếu bằng một cách nào đó, chúng ta gửi một request rồi từ một container nào đó sẽ cung cấp instance cho chúng ta thì sao.

```ts
class ProductComponent {
  cartService: CartService;
  constructor(cartService: CartService) {
    this.cartService = cartService;
  }
}

// tương đương cú pháp sau trong TypeScript
class ProductComponent {
  constructor(public cartService: CartService) {}
}
```

Và chúng ta sẽ có một container có thể biết cách khởi tạo và provide cho các request của các class như sau:

```ts
(function container() {
  const service = new CartService(); // và các dependencies của CartService nếu có
  const productComp = new ProductComponent(service);
  // other code logic
})();
```

Lúc này bạn có thể thấy class `ProductComponent` không hề biết gì về các khởi tạo CartService như thế nào. Nó gửi request cho Inversion of Control (đảo ngược sự điều khiển hay đảo ngược sự phụ thuộc, viết tắt là IoC) container, từ đó nó có thể lấy được instance mà nó mong muốn.

Trong trường hợp bạn muốn đổi implementation cũng rất dễ dàng và hoàn toàn không cần viết lại class `ProductComponent`.

Các bạn có thể đoán được mẫu thiết kế trên chính là Dependency Injection, chi tiết hơn đó là constructor injection.

## DI trong Angular

Trong Angular, DI bao gồm ba thành phần sau đây:

- Injector: là một object có chứa các API để chúng ta có thể lấy về các instances đã tạo hoặc tạo các instances của các phụ thuộc.

- Provider: giống như một công thức để Injector có thể biết làm thế nào để tạo một instance của một phụ thuộc.

- Dependency: là một object (có thể là function, một value thông thường) của một kiểu dữ liệu cần phải khởi tạo.

Bạn có thể cung cấp `injectors` với `providers` ở nhiều levels khác nhau trong app, bằng một trong ba cách sau:

- Trong `@Injectable()` decorator cho service đó.

- Trong `@NgModule()` decorator (providers array) đối với NgModule.

- Trong `@Component()` decorator (providers array) đối với component hoặc directive (Chúng ta sẽ tìm hiểu chi tiết về Directive sau).

Ví dụ về cách provide `CartService`:

```ts
@Injectable({
  providedIn: "root",
})
export class CartService {
  // properties and methods
}
```

```ts
@Component({
  selector: "app-product",
  templateUrl: "./product.component.html",
  styleUrls: ["./product.component.css"],
})
export class ProductComponent implements OnInit {
  constructor(private cartService: CartService) {}

  ngOnInit() {
    console.log(this.cartService.calculateTotal());
  }
}
```

Với `@Injectable` decorator, chúng ta đã thêm metadata để Angular biết được cách để tạo instance của `CartService` khi có một class nào đó request như `ProductComponent`. Và thông tin `providedIn: 'root'` sẽ chỉ cách cho Angular biết rằng chúng ta mong muốn service này sẽ có một instance (singleton) cho suốt toàn bộ app.

## Override Provider trong angular

Giờ đây nếu hệ thống yêu cầu chúng ta thay vì lưu trữ tính toán thông tin giỏ hàng ở client, thì sẽ call đến một external datasource (API chẳng hạn) để thao tác như **Thêm vào giỏ hàng**, **Tính tổng tiền**. Lúc này về mặt coding, chúng ta sẽ tuân thủ theo đúng những gì class `CartService` đang có (public APIs của CartService), chỉ khác về mặt implementation như sau:

```ts
@Injectable()
export class CartExtService {
  calculateTotal(): number {
    // call external datasource
    // return data from exteral datasource
    return Math.random() * 100;
  }
  addToCart(): void {
    // logic here
  }
}
```

Bạn chỉ cần có thế và có thể tiến hành override, mà không cần sửa đổi lại code của `ProductComponent` như sau:

```ts
@NgModule({
  // other metadata
  providers: [
    {
      provide: CartService,
      useClass: CartExtService,
    },
  ],
})
export class AppModule {}
```

Hoặc có thể override vào `@Injectable` của service

```ts
@Injectable({
  providedIn: "root",
  useClass: CartExtService,
})
export class CartService {
  // logic here
}
```

## Lời kết

Như vậy, trong bài này chúng ta đã làm quen về khái niệm cũng như cách sử dụng cơ bản của Dependency Injection trong Angular.
