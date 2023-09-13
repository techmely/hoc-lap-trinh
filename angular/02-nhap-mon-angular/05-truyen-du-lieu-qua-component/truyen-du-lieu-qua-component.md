---
title: "Truyền dữ liệu giữa các component"
description: "Trong các ứng dụng thực tế, đôi khi chúng ta sẽ có những component mà không cần truyền gì vào nó vẫn sẽ hoạt động, nhưng có rất nhiều component mà khi thiết kế chúng ta mong muốn có thể tái sử dụng cao hơn, tùy thuộc vào các properties được truyền vào mà sẽ hiển thị, xử lý tương ứng."
chapter:
  name: "Nhập môn Angular"
  slug: "chuong-02-nhap-mon-angular"
category:
  name: "Angular"
  slug: "angular"
image: https://kungfutech.edu.vn/thumbnail.png
position: 5
---

Làm sao để có thể tạo một component mà nó có thể nhận vào các properties.
Đầu tiên, chúng ta sẽ đi tạo component trước, nếu bạn vẫn chưa biết cách tạo thì có thể Google hoặc xem lại chương 1.
Chúng ta sẽ dùng lệnh để generate 1 component tên là progress-bar

```bash
ng g c progress-bar
```

Đó là cách viết tắt, hoặc có thể tường minh hơn là:

```bash
ng generate component progress-bar
```

Thế là xong, chúng ta đã có một component để bắt đầu.

## @input decorator

Để thêm một property cho phép thiết lập progress hiện tại của thanh progress-bar, chúng ta có thể khai báo một property cho class và thêm một móc móc (decorator) như sau:

```typescript
export class ProgressBarComponent implements OnInit {
  @Input() progress = 0;
  constructor() {}
  ngOnInit() {}
}
```

Đơn giản thế là chúng ta đã có thể báo cho Angular biết rằng, chúng ta cần component này nhận vào một property tên là progress, và giá trị mặc định của nó bằng 0.
Bây giờ, chúng ta có thể thêm một số property khác cho component như property về màu sắc chẳng hạn.

```typescript
export class ProgressBarComponent implements OnInit {
  @Input() backgroundColor: string;
  @Input() progressColor: string;
  @Input() progress = 0;
  constructor() {}
  ngOnInit() {}
}
```

Như vậy, component của chúng ta sẽ có thể nhận vào 3 `properties`, với `property progress` sẽ có thể chứa giá trị default bằng 0.
Lưu ý rằng, `@Input` được gọi là một `property decorator`, nó sẽ gắn thêm meta data cho property ngay phía sau nó.
Nếu bạn không khai báo decorator `@Input` thì sẽ không thể nhận giá trị truyền vào từ `component` khác, vì Angular sẽ không biết cách để binding, và do đó property của bạn chỉ là một property bình thường của class.

Khi đã có `component` và khai báo input rồi thì làm sao để sử dụng. Các bạn cần nhớ lại `property binding` ở trong những buổi đầu tiên, lúc này chỉ cần dùng cú pháp vuông vuông để `binding` cho `property` các bạn muốn là được rồi.

```html
<app-progress-bar
  [progress]="15"
  [backgroundColor]="'#9e9e9e'"
  [progressColor]="'#2e8b57'"
>
</app-progress-bar>
```

Đây là component progress-bar của chúng ta.

```typescript
import { Component, OnInit, Input } from "@angular/core";

@Component({
  selector: "app-progress-bar",
  template: `
    <div
      class="progress-bar-container"
      [style.backgroundColor]="backgroundColor"
    >
      <div
        class="progress"
        [style]="{
          backgroundColor: progressColor,
          width: progress + '%'
        }"
      ></div>
    </div>
  `,
  styles: [
    `
      .progress-bar-container,
      .progress {
        height: 20px;
      }

      .progress-bar-container {
        width: 100%;
      }
    `,
  ],
})
export class ProgressBarComponent implements OnInit {
  @Input() backgroundColor: string;
  @Input() progressColor: string;
  @Input() progress = 0;
  constructor() {}
  ngOnInit() {}
}
```

## Constructor và ngOnInit trong angular

Khi làm việc các bạn có thể thấy rằng Angular giới thiệu một số method gọi là life-cycle, chúng làm nhiệm vụ gì.
Theo như lẽ thông thường, con người từ khi sinh ra đến khi chết đi sẽ đều trải qua một số sự kiện trọng đại trong đời, ví du: sinh ra, đầy tháng, sinh nhật hàng năm, kết hôn, chết đi. Tương tự như thế trong ứng dụng Angular sẽ có vòng đời cho các component. Angular được xây dựng xung quanh Component và Directive, ở một thời điểm có thể có 1 component được khởi tạo, một thời điểm khác chúng lại được xóa đi khỏi view, và có một số “sự kiện” khác cũng được xảy ra, do đó Angular cung cấp cho chúng ta một số method mà chúng ta chỉ việc khai báo cho component/directive, còn lại Angular sẽ tự call khi có những sự kiện tương ứng xảy ra.
Ở trong code phía trên, chúng ta được giới thiệu constructor và ngOnInit, vậy chúng giống và khác nhau gì?

Constructor là hàm tạo của một class, nó là một function đặc biệt mà khi bạn khởi tạo một instance của class thì nó sẽ được tự động chạy, và chỉ chạy duy nhất một lần.
ngOninit là một life-cycle method, nó sẽ được Angular tự động gọi khi component được khởi tạo, sau khi constructor chạy và sau khi các input đã được binding.
Do đó nếu bạn binding cho một property ở template của component cha, thì ở constructor của component con bạn sẽ chưa nhận được giá trị mà bạn đã binding, nhưng ở ngOnInit thì bạn sẽ có thể nhận được.

Trong thực tế, Angular khuyến cáo hạn chế code ở constructor, constructor làm càng ít nhiệm vụ càng tôt, hãy để ngOnInit lo tiếp phần việc còn lại.

## Thay đổi giá trị của input

Giả sử trong trường hợp nào đó mà chúng ta không biết người dùng binding những dữ liệu có hợp lệ không (điều này hoàn toàn có thể xảy ra như trường hợp người dùng truyền data kiểu any vào chẳng hạn), và chúng ta muốn validate Input thì có cách nào không?

Lúc này bạn sẽ dễ dàng validate lần đầu tiên ở trong ngOnInit được. Nhưng như thế ở các lần sau ngOnInit không chạy lại thì cũng không phải là giải pháp toàn diện. Đây chính là lúc mà bạn có thể sử dụng life-cycle tiếp theo là ngOnChanges.

ngOnChanges sẽ chạy lại mỗi khi có một input nào bị thay đổi, nó sẽ được tự động gọi bởi Angular, do đó chúng ta có thể validate property progress như sau:

```typescript
export class ProgressBarComponent implements OnInit, OnChanges {
  @Input() backgroundColor: string;
  @Input() progressColor: string;
  @Input() progress = 0;

  constructor() {}

  ngOnChanges(changes: SimpleChanges) {
    if ("progress" in changes) {
      if (typeof changes["progress"].currentValue !== "number") {
        const progress = Number(changes["progress"].currentValue);
        if (Number.isNaN(progress)) {
          this.progress = 0;
        } else {
          this.progress = progress;
        }
      }
    }
  }

  ngOnInit() {}
}
```

Trong trường hợp bạn không thích dùng ngOnChanges, chúng ta có thể sử dụng getter/setter để làm điều này.

```typescript
export class ProgressBarComponent implements OnInit {
  @Input() backgroundColor: string;
  @Input() progressColor: string;
  private $progress = 0;
  @Input()
  get progress(): number {
    return this.$progress;
  }
  set progress(value: number) {
    if (typeof value !== "number") {
      const progress = Number(value);
      if (Number.isNaN(progress)) {
        this.$progress = 0;
      } else {
        this.$progress = progress;
      }
    } else {
      this.$progress = value;
    }
  }

  constructor() {}

  ngOnInit() {}
}
```

## Lời kết

Như vậy trong bài này, chúng ta sẽ phải tìm hiểu cách để khai báo input binding cho một component, từ đó giúp dễ dàng thiết kế các component có tính tái sử dụng cao.
