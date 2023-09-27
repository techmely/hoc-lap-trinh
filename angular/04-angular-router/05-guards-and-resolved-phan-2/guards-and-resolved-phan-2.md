---
title: "Guards and Resolvers Phần 2"
description: "Trong ngày hôm nay chúng ta sẽ tiếp tục với các guard như CanDeactivate và CanLoad."
chapter:
  name: "Angular Router"
  slug: "chuong-04-angular-router"
image: https://kungfutech.edu.vn/thumbnail.png
position: 5
---

## Route Guards

Route Guards để giải quyết câu hỏi, liệu tôi có được phép redirect đến URL này hay không.

> If all guards return true, navigation will continue. If any guard returns false, navigation will be cancelled. If any guard returns a UrlTree, current navigation will be cancelled and a new navigation will be kicked off to the UrlTree returned from the guard.

Angular Router cung cấp một số guards như sau:

- Activate components:

```ts
interface CanActivate {
  canActivate(
    route: ActivatedRouteSnapshot,
    state: RouterStateSnapshot
  ):
    | Observable<boolean | UrlTree>
    | Promise<boolean | UrlTree>
    | boolean
    | UrlTree;
}
```

```ts
interface CanActivateChild {
  canActivateChild(
    childRoute: ActivatedRouteSnapshot,
    state: RouterStateSnapshot
  ):
    | Observable<boolean | UrlTree>
    | Promise<boolean | UrlTree>
    | boolean
    | UrlTree;
}
```

- Deactivate components:

```ts
interface CanDeactivate<T> {
  canDeactivate(
    component: T,
    currentRoute: ActivatedRouteSnapshot,
    currentState: RouterStateSnapshot,
    nextState?: RouterStateSnapshot
  ):
    | Observable<boolean | UrlTree>
    | Promise<boolean | UrlTree>
    | boolean
    | UrlTree;
}
```

- Load children (lazy loading route):

```ts
interface CanLoad {
  canLoad(
    route: Route,
    segments: UrlSegment[]
  ):
    | Observable<boolean | UrlTree>
    | Promise<boolean | UrlTree>
    | boolean
    | UrlTree;
}
```

Trong Day 30 chúng ta đã tìm hiểu guard để biết được có được phép activate các components hay không, vậy còn trường hợp muốn check xem có được phép deactivate hay không thì sao.

### CanDeactivate

Giả sử chúng ta có chức năng edit bài viết, khách hàng yêu cầu thêm một điều là khi người ta đã thay đổi một cái gì đó mà chưa save thông tin lại, và nếu người dùng redirect sang một trang khác, thì sẽ phải hỏi người dùng xem có thật sự muốn rời khỏi trang hay không.

Giả sử phần config routing của chúng ta sẽ có từ bài trước như sau:

```ts
const routes: Routes = [
  {
    path: "article",
    component: ArticleComponent,
    children: [
      {
        path: "",
        component: ArticleListComponent,
      },
      {
        path: ":slug",
        component: ArticleDetailComponent,
      },
      {
        path: ":slug/edit",
        component: ArticleEditComponent,
        canActivate: [CanEditArticleGuard],
      },
    ],
  },
];
```

Lúc này chúng ta có thể thêm một service, và nó sẽ implement CanDeactivate guard để check như sau.

```ts
import { Injectable } from "@angular/core";
import {
  ActivatedRouteSnapshot,
  RouterStateSnapshot,
  CanDeactivate,
  UrlTree,
} from "@angular/router";
import { Observable } from "rxjs";
import { ArticleEditComponent } from "./article-edit/article-edit.component";

@Injectable({
  providedIn: "root",
})
export class CanLeaveEditGuard implements CanDeactivate<ArticleEditComponent> {
  canDeactivate(
    component: ArticleEditComponent,
    currentRoute: ActivatedRouteSnapshot,
    currentState: RouterStateSnapshot,
    nextState?: RouterStateSnapshot
  ):
    | Observable<boolean | UrlTree>
    | Promise<boolean | UrlTree>
    | boolean
    | UrlTree {
    return true; // replace with actual logic
  }
}
```

Sau đó chúng ta sẽ thêm guard vào config routing như đối với `CanActivate` trong ngày hôm trước.

```ts
const routes: Routes = [
  {
    path: "article",
    component: ArticleComponent,
    children: [
      // other configurations
      {
        path: ":slug/edit",
        component: ArticleEditComponent,
        canActivate: [CanEditArticleGuard],
        canDeactivate: [CanLeaveEditGuard], // <== this is an array, we can have multiple guards
      },
    ],
  },
];
```

Giờ đây mỗi khi người dùng navigate ra khỏi màn hình edit này, Angular Router sẽ chạy `CanLeaveEditGuard.canDeactivate`, do đó chúng ta có thể check những điều kiện cần thiết để có thể cho phép redirect hay không.

```ts
@Injectable({
  providedIn: "root",
})
export class CanLeaveEditGuard implements CanDeactivate<ArticleEditComponent> {
  canDeactivate(
    component: ArticleEditComponent,
    currentRoute: ActivatedRouteSnapshot,
    currentState: RouterStateSnapshot,
    nextState?: RouterStateSnapshot
  ):
    | Observable<boolean | UrlTree>
    | Promise<boolean | UrlTree>
    | boolean
    | UrlTree {
    return !component.isEditing;
  }
}
```

![image](https://github.com/techmely/hoc-lap-trinh/assets/29374426/69ba2cf6-7bc5-48de-a0aa-4c2e4e0b8f58)

Để tăng tính reuse của guard, chúng ta có thể sử dụng implement interface như sau.

```ts
import {
  ActivatedRouteSnapshot,
  RouterStateSnapshot,
  CanDeactivate,
  UrlTree,
} from "@angular/router";
import { Observable } from "rxjs";

export interface CheckDeactivate {
  checkDeactivate(
    currentRoute: ActivatedRouteSnapshot,
    currentState: RouterStateSnapshot,
    nextState?: RouterStateSnapshot
  ):
    | Observable<boolean | UrlTree>
    | Promise<boolean | UrlTree>
    | boolean
    | UrlTree;
}
```

Sau đó component của chúng ta sẽ chịu trách nhiệm implement logic này.

```ts
@Injectable({
  providedIn: "root",
})
export class CanLeaveEditGuard implements CanDeactivate<CheckDeactivate> {
  canDeactivate(
    component: CheckDeactivate,
    currentRoute: ActivatedRouteSnapshot,
    currentState: RouterStateSnapshot,
    nextState?: RouterStateSnapshot
  ):
    | Observable<boolean | UrlTree>
    | Promise<boolean | UrlTree>
    | boolean
    | UrlTree {
    return component.checkDeactivate(currentRoute, currentState, nextState);
  }
}
```

```ts
export class ArticleEditComponent implements OnInit, CheckDeactivate {
  slug$ = this.activatedRoute.paramMap.pipe(
    map((params) => params.get("slug"))
  );

  isEditing = false;

  constructor(private activatedRoute: ActivatedRoute) {}

  ngOnInit() {}

  checkDeactivate(
    currentRoute: ActivatedRouteSnapshot,
    currentState: RouterStateSnapshot,
    nextState?: RouterStateSnapshot
  ):
    | Observable<boolean | UrlTree>
    | Promise<boolean | UrlTree>
    | boolean
    | UrlTree {
    return !this.isEditing;
  }
}
```

Full code: https://stackblitz.com/edit/angular-100-days-of-code-day-31-01?file=src%2Fapp%2Farticle%2Farticle-edit%2Farticle-edit.component.ts

Trường hợp cần thiết chúng ta hoàn toàn có thể hiển thị confirm dialog để hỏi người dùng xem có muốn rời khỏi trang hay không.

```ts
export class ArticleEditComponent implements OnInit, CheckDeactivate {
  slug$ = this.activatedRoute.paramMap.pipe(
    map((params) => params.get("slug"))
  );

  isEditing = false;

  constructor(
    private activatedRoute: ActivatedRoute,
    private dialog: MatDialog
  ) {}

  ngOnInit() {}

  openDialog() {
    const ref = this.dialog.open(ConfirmDialogComponent, {
      data: {
        title: "Do you want to leave this page?",
      },
    });
    return ref.afterClosed();
  }

  checkDeactivate(
    currentRoute: ActivatedRouteSnapshot,
    currentState: RouterStateSnapshot,
    nextState?: RouterStateSnapshot
  ):
    | Observable<boolean | UrlTree>
    | Promise<boolean | UrlTree>
    | boolean
    | UrlTree {
    return !this.isEditing || this.openDialog();
  }
}
```

Full code: https://stackblitz.com/edit/angular-100-days-of-code-day-31-02?file=src%2Fapp%2Farticle%2Farticle-edit%2Farticle-edit.component.ts

![image](https://github.com/techmely/hoc-lap-trinh/assets/29374426/113399e7-343f-4995-bce6-2672d098f0e7)

### CanLoad

Đối với các lazy load route, chúng ta có thể kiểm tra trước ở frontend, nếu thỏa mãn điều kiện mới cho phép tải về.

Ví dụ, application của chúng ta có chức năng cho admin vào xem để quản lý. Đối với người dùng thông thường, chúng ta không cần thiết phải tải phần code của route `/admin` về. Lúc đó `CanLoad` sẽ là một guard hữu ích cho chúng ta sử dụng.

```ts
import { Injectable } from "@angular/core";
import {
  CanLoad,
  UrlSegment,
  Route,
  RouterStateSnapshot,
  UrlTree,
} from "@angular/router";
import { Observable } from "rxjs";

@Injectable({
  providedIn: "root",
})
export class CanLoadAdminGuard implements CanLoad {
  canLoad(
    route: Route,
    segments: UrlSegment[]
  ):
    | Observable<boolean | UrlTree>
    | Promise<boolean | UrlTree>
    | boolean
    | UrlTree {
    return true;
  }
}
```

```ts
const routes: Routes = [
  {
    path: "admin",
    loadChildren: () =>
      import("./admin/admin.module").then((m) => m.AdminModule),
    canLoad: [CanLoadAdminGuard], // <== this is an array, we can have multiple guards
  },
  {
    path: "",
    redirectTo: "article",
    pathMatch: "full",
  },
];
```

Từ đây chúng ta có thể implement các logic để check xem có thể load về hay không, ví dụ như sau:

```ts
@Injectable({
  providedIn: "root",
})
export class CanLoadAdminGuard implements CanLoad {
  constructor(private userService: UserService) {}
  canLoad(
    route: Route,
    segments: UrlSegment[]
  ):
    | Observable<boolean | UrlTree>
    | Promise<boolean | UrlTree>
    | boolean
    | UrlTree {
    return this.userService.currentUser.isAdmin;
  }
}
```

![image](https://github.com/techmely/hoc-lap-trinh/assets/29374426/19b5adfd-4de0-40db-bb2e-a1dde2933b1b)

## Lời kết

Trong bài này chúng ta đã biết thêm một số guard khác khá hữu ích để check xem có thể deactivate, load hay không.

## Code sample

- https://stackblitz.com/edit/angular-100-days-of-code-day-31-01?file=src%2Fapp%2Farticle%2Farticle-edit%2Farticle-edit.component.ts
- https://stackblitz.com/edit/angular-100-days-of-code-day-31-02?file=src%2Fapp%2Farticle%2Farticle-edit%2Farticle-edit.component.ts
- https://stackblitz.com/edit/angular-100-days-of-code-day-31-03?file=src%2Fapp%2Fcan-load-admin.guard.ts
