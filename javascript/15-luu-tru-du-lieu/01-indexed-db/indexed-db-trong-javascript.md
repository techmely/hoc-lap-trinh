---
title: "Tìm hiểu Javascript IndexedDB là gì"
description: "IndexedDB là một dạng kho lưu trữ dữ liệu ở phía trình duyệt người dùng (tương tự local storage, session storage hay cookie). Thường được sử dụng để lưu trữ dữ liệu lớn và thực hiện các thao tác tìm kiếm với hiệu năng cao tại chính trình duyệt."
keywords: [
"Javascript IndexedDB là gì",
"IndexedDB trong javascript",
"tim hieu javascript indexeddb la gi trong javascript",
"indexeddb co tac dung gi trong javascript",
"IndexedDB vs localStorage trong javascript",
"IndexedDB max size trong javascript",
"kho lưu trữ dữ liệu trong javascript",
"JavaScript IndexedDB"
]
chapter:
  name: "Lưu trữ dữ liệu"
  slug: "chuong-15-luu-tru-du-lieu"
category:
  name: "Javascript"
  slug: "javascript"
image: https://kungfutech.edu.vn/thumbnail.png
position: 1
---

Có thể bạn đã nghe thấy nhiều loại cơ sở dữ liệu (database) trên trình duyệt như [PouchDB](http://pouchdb.com/), [LocalForage](https://localforage.github.io/localForage/), [Dexie](http://dexie.org/), [Lovefield](https://google.github.io/lovefield/), [LokiJS](http://lokijs.org/), [AlaSQL](http://alasql.org/), [ForerunnerDB](http://forerunnerdb.com/), [YDN-DB](http://dev.yathit.com/ydn-db/index.html)... Thực tế thì các database đó chỉ là những thư viện đóng gói (wrapping) lại 3 loại database trên trình duyệt. Đó là: [LocalStorage](https://developer.mozilla.org/en-US/docs/Web/API/Storage/LocalStorage), [Web SQL](https://www.w3.org/TR/webdatabase/), [IndexedDB](https://developer.mozilla.org/en-US/docs/Web/API/IndexedDB_API). Việc tìm hiểu các database gốc sẽ giúp bạn hiểu rõ được bản chất của các cơ sở dữ liệu đó. Qua đó, bạn có thể tự xây dựng những thư viện của riêng mình. Tuy nhiên, bài viết này sẽ chỉ tập chung vào **JavaScript IndexedDB**. Tại sao vậy? Chúng ta sẽ cùng nhau tìm hiểu sau đây.

## IndexedDB là gì?

- IndexedDB là một API cấp thấp cho việc lưu trữ dữ liệu phía client.
- Dữ liệu lưu trữ có thể là những dữ liệu có cấu trúc, bao gồm file hay [blob](https://developer.mozilla.org/en-US/docs/Web/API/Blob).

## Tại sao lại tìm hiểu JavaScript IndexedDB?

- IndexedDB sử dụng công nghệ [index db](https://en.wikipedia.org/wiki/Database_index) để nâng cao hiệu quả tìm kiếm, giúp tìm kiếm dữ liệu nhanh hơn.
- IndexedDB hoạt động theo kiểu bất đồng bộ (asynchronous) và còn hỗ trợ sử dụng trong [Web Worker](/bai-viet/javascript/web-worker-api-trong-javascript), giúp tránh việc block [DOM](/bai-viet/javascript/dom-la-gi). Qua đó, trình duyệt chạy sẽ mượt hơn.
- Trong khi LocalStorage chỉ hỗ trợ dung lượng tối đa là 5MB thì IndexedDB hỗ trợ lên đến 50MB. Và khi dùng [quá 50MB này](https://support.mozilla.org/en-US/questions/818987#answer-180011), trình duyệt sẽ yêu cầu permission từ người dùng để có thể tăng thêm dung lượng lưu trữ.

## Những khái niệm cơ bản trong JavaScript IndexedDB

---

- IndexedDB lưu trữ dữ liệu theo kiểu **key-value**. Trong đó, value có thể là những object có cấu trúc phức tạp và key có thể là thuộc tính của object. Bạn có thể áp dụng **Indexes**, sử dụng bất kỳ thuộc tính nào của object để tìm kiếm nhanh hơn, cũng như là việc [sắp xếp](/bai-viet/javascript/sap-xep-mang-trong-javascript).
- IndexedDB được xây dựng dựa trên [Transaction](https://developer.mozilla.org/en-US/docs/Web/API/IndexedDB_API/Basic_Concepts_Behind_IndexedDB#gloss_transaction). IndexedDB API cung cấp nhiều [object](/bai-viet/javascript/object-la-gi-object-trong-javascript) như indexes, tables, cursors,... nhưng mỗi object phải được gắn liền với một transaction.
- IndexedDB API hầu hết là **bất đồng bộ (asynchronous)**. Các API không cung cấp dữ liệu bởi việc **return**, do đó, bạn cần phải truyền vào một hàm callback. Và việc của bạn cần làm là gửi đi request. Khi request được xử lý xong, IndexedDB sẽ trả lại kết quả thông qua hàm callback kia. Bạn sẽ biết được là request thành công hay thất bại. Và thành công thì dữ liệu nhận được là gì. Cơ chế hoạt động tương tự như [XMLHttpRequest](/bai-viet/javascript/network-requests).
- IndexedDB sử dụng nhiều **requests**. Requests là những đối tượng nhận sự kiện thành công hay thất bại của DOM. Chúng có các thuộc tính **onsuccess**, **onerror**. Bạn có thể gọi hàm **addEventListener()** và **removeEventListener()** với chúng.
- IndexedDB là **hướng đối tượng**. Vì vậy, IndexedDB không phải là dạng cơ sở dữ liệu quan hệ với bảng, dòng, cột,...
- IndexedDB là cơ sở dữ liệu dạng [NoSQL](https://en.wikipedia.org/wiki/NoSQL).
- IndexedDB cũng dựa trên chính sách **same-orgin**. Nghĩa là file script thực thi phải nằm trên cùng tên miền, protocol (**http** hay **https**), và cổng (**port**).

## Một số định nghĩa quan trọng khi dùng IndexedDB

### Database

- Database là một kho chứa thông tin, bao gồm một hay nhiều object stores.
- Mỗi database bắt buộc phải có 2 thông số là:
  - Name (tên): xác định database ứng với mỗi origin. Name có thể là bất kỳ string nào, kể cả [string](/bai-viet/javascript/cac-kieu-du-lieu-trong-javascript) rỗng.
  - Current verion (phiên bản hiện tại): Khi database được tạo ra, nếu không chỉ rõ thì giá trị current version sẽ là 1. Và tại mỗi thời điểm, database version sẽ chỉ có một giá trị.

### Object store

- Là cơ chế mà dựa vào đó, dữ liệu được lưu trong database.
- Object store lưu giữ các bản ghi, là các cặp key-value.
- Mỗi object store trong cùng một database phải có tên khác nhau.

### Version

- Khi một database được tạo ra, version của nó là 1.
- Mỗi database sẽ chỉ có một version ở một thời điểm. Vì vậy, khi muốn nâng cấp database, thì bạn cần phải thay đổi giá trị của version bởi một số tự nhiên lớn hơn. Khi đó, transaction **versionchange** bắt đầu và [event](/bai-viet/javascript/mot-so-event-javascript) **upgradeneeded** sẽ được gọi.

### Database connection

- Database connection là một tiến trình được tạo ra bởi việc mở một database.
- Mỗi database có thể có nhiều connection cùng một lúc.

### Transaction

- Transaction là một tiến trình gồm hai bước là truy cập dữ liệu (data-access) và điều chỉnh dữ liệu (data-modification).
- Bất kể mọi việc (đọc, chỉnh sửa dữ liệu) đều phải được thực hiện trong một Transaction.

### Request

- Request là tiến trình mà bởi nó, việc đọc hay ghi dữ liệu trên database được hoàn thành.
- Mỗi request sẽ đại diện cho một tiến trình đọc hoặc ghi.

### Index

- Index là một object store dùng để tìm kiếm bản ghi ở một object store khác (gọi là **referenced object store**).
- Mỗi bản ghi trong một **Index** chỉ có thể trỏ tới một bản ghi ở **referenced object store**.
- Tuy nhiên, nhiều Indexes có thể tham chiếu tới một object store giống nhau. Mỗi khi object store này thay đổi thì các Indexes kia sẽ tự động thay đổi.

### Key path

- Key path xác định nơi mà trình duyệt lấy ra key ở trong một object store hay index.
- Key path hợp lệ có thể là: một string rỗng, một định danh JavaScript, nhiều định danh JavaScript phân cách bởi dấu chấm hay là một [mảng](/bai-viet/javascript/mang-array-trong-javascript) chứa các phần tử là một trong các kiểu kia. Và key path thì không được bao gồm dấu cách.

## Cách sử dụng JavaScript IndexedDB

---

- Tham khảo code [SimpleIndexedDB.js](https://github.com/completejavascript/simple-indexdb-js/blob/master/SimpleIndexedDB.js) - một bản wrapper đơn giản của IndexedDB.

### Kiểm tra trình duyệt hỗ trợ hay không?

Dưới đây là đoạn code để kiểm tra trình duyệt bạn đang dùng có hỗ trợ IndexedDB hay không.

```js
//prefixes of implementation that we want to test
window.indexedDB =
  window.indexedDB ||
  window.mozIndexedDB ||
  window.webkitIndexedDB ||
  window.msIndexedDB;

/**
 * prefixes of window.IDB objects
 * IDBTransaction interface of the IndexedDB API provides a static,
 * asynchronous transaction on a database using event handler attributes.
 */
window.IDBTransaction =
  window.IDBTransaction ||
  window.webkitIDBTransaction ||
  window.msIDBTransaction;

window.IDBKeyRange =
  window.IDBKeyRange || window.webkitIDBKeyRange || window.msIDBKeyRange;

if (!window.indexedDB) {
  window.alert("Your browser doesn't support a stable version of IndexedDB.");
}
```

### Open database

IndexedDB cung cấp 2 APIs để open database như sau:

```js
var IDBOpenDBRequest = indexedDB.open(name);
var IDBOpenDBRequest = indexedDB.open(name, version);
```

Sau đó, implement 3 hàm **onsuccess**, **onerror** và **onupgradeneeded** của IDBOpenDBRequest để lắng nghe các sự kiện tương ứng là **success** (mở database thành công), **error** (mở database bị lỗi), **upgradeneeded** (mở database thành công nhưng cần phải cập nhật lại với version mới nhất hiện tại).

Ví dụ:

```js
// Implement in SimpleSindexedDB.js
this.open = function (
  onsuccess,
  onerror,
  onupgradeneeded,
  objName,
  keyPath,
  objData
) {
  this.objName = objName;
  this.request = window.indexedDB.open(this.dbName, this.dbVersionNumber);
  var self = this;

  this.request.onerror = function (event) {
    onerror();
  };

  this.request.onsuccess = function (event) {
    // here: this = request
    self.db = this.result;
    onsuccess();
  };

  this.request.onupgradeneeded = function (event) {
    var db = event.target.result;
    var objectStore = db.createObjectStore(objName, { keyPath: keyPath });
    if (objData != undefined) {
      for (var i in objData) {
        objectStore.add(objData[i]);
      }
    }
    onupgradeneeded();
  };
};

// Implement in main.js
const INDEXED_DB_NAME = "employee_db";
var firstname, email, id;
var simpleIndexedDb;

var objData = [
  { id: "1", name: "lam", email: "lam@whatever.com" },
  { id: "2", name: "phong", email: "phong@whatever.com" },
];

var objName = "employee";
var keyPath = "id";

function init() {
  firstname = document.querySelector('[name="firstname"]');
  email = document.querySelector('[name="email"]');
  id = document.querySelector('[name="id"]');

  simpleIndexedDb = new SimpleIndexedDB(INDEXED_DB_NAME);
  simpleIndexedDb.open(
    openDBSuccess,
    openDBError,
    openDBUpgradeNeeded,
    objName,
    keyPath,
    objData
  );
}

function openDBSuccess() {
  console.log("open db success");
}

function openDBError() {
  console.log("open db error");
}

function openDBUpgradeNeeded() {
  console.log("open db upgradedneeded");
}
```

### Quét toàn bộ dữ liệu một object store trong database

Để quét toàn bộ dữ liệu trong một object store, sử dụng **[cursor](https://developer.mozilla.org/en-US/docs/Web/API/IDBCursor)**.

Ví dụ:

```js
// Implement in SimpleSindexedDB.js
this.readAll = function (callback) {
  var objectStore = this.db.transaction(this.objName).objectStore(this.objName);

  objectStore.openCursor().onsuccess = function (event) {
    var cursor = event.target.result;
    if (cursor) {
      callback(cursor);
      cursor.continue();
    } else {
      console.log("No more entries!");
    }
  };
};

// Implement in main.js
function showAll() {
  simpleIndexedDb.readAll(function (cursor) {
    console.log(cursor.key, cursor.value.name, cursor.value.email);
  });
}
```

### Lấy ra một bản ghi dựa vào key trong JavaScript IndexedDB

Để lấy ra một bản ghi trong object store của database, sử dụng phương thức **[get](https://developer.mozilla.org/en-US/docs/Web/API/IDBObjectStore/get)**.

Ví dụ:

```js
// Implement in SimpleSindexedDB.js
this.read = function (id) {
  var transaction = this.db.transaction([this.objName]);
  var objectStore = transaction.objectStore(this.objName);
  var keySearch = "" + id;

  return new Promise(function (resolve, reject) {
    var request = objectStore.get(id);
    request.onerror = function (event) {
      reject(event);
    };
    request.onsuccess = function (event) {
      resolve(request.result);
    };
  });
};

// Implement in main.js
function read() {
  simpleIndexedDb.read(getId()).then(
    (result) => console.log("read success", result),
    (event) => console.log("read error", event)
  );
}
```

### Thêm một bản ghi vào object store database

Để thêm vào một bản ghi cho object store của database, sử dụng phương thức **[add](https://developer.mozilla.org/en-US/docs/Web/API/IDBObjectStore/add)**.

Ví dụ:

```js
// Implement in SimpleSindexedDB.js
this.add = function (objData) {
  var transaction = this.db.transaction([this.objName], "readwrite");
  var objectStore = transaction.objectStore(this.objName);

  return new Promise(function (resolve, reject) {
    var request = objectStore.add(objData);
    request.onsuccess = function (event) {
      resolve(event);
    };

    request.onerror = function (event) {
      reject(event);
    };
  });
};

// Implement in main.js
function save() {
  var data = {
    id: getId(),
    name: getName(),
    email: getEmail(),
  };
  console.log("save", data);

  simpleIndexedDb.add(data).then(
    (event) => console.log("add success", event),
    (error) => console.log("add error", error)
  );
}
```

### Xoá đi một bản ghi trong object store database dựa vào key

Để xoá đi một bản ghi tỏng object store database, sử dụng phương thức **[delete](https://developer.mozilla.org/en-US/docs/Web/API/IDBObjectStore/delete)**.

Ví dụ:

```js
// Implement in SimpleSindexedDB.js
this.remove = function (id) {
  var transaction = this.db.transaction([this.objName], "readwrite");
  var objectStore = transaction.objectStore(this.objName);
  var keySearch = "" + id;

  return new Promise(function (resolve, reject) {
    var request = objectStore.delete(id);
    request.onerror = function (event) {
      reject(event);
    };
    request.onsuccess = function (event) {
      resolve(event);
    };
  });
};

// Implement in main.js
function remove() {
  simpleIndexedDb.remove(getId()).then(
    (event) => console.log("remove success", event),
    (event) => console.log("remove error", event)
  );
}
```

## Kết luận

Trên đây, mình đã giới thiệu với bạn những kiến thức cơ bản cần nhớ về JavaScript IndexedDB. Tuy nhiên, để giải thích chi tiết về index db thì thật sự không biết phải giải thích như thế nào.

Vì vậy, nếu có phần nào bạn cảm thấy không hiểu thì có thể đặt câu hỏi trong phần bình luận.

## Tham khảo

- Ví dụ trên [github](https://github.com/completejavascript/simple-indexdb-js), [codepen](https://codepen.io/completejavascript/full/LeBzyb).
- [IndexedDB, WebSQL, LocalStorage – what blocks the DOM?](https://nolanlawson.com/2015/09/29/indexeddb-websql-localstorage-what-blocks-the-dom/)
- [IndexedDB API](https://developer.mozilla.org/en-US/docs/Web/API/IndexedDB_API)
- [Basic concepts behind IndexedDB](https://developer.mozilla.org/en-US/docs/Web/API/IndexedDB_API/Basic_Concepts_Behind_IndexedDB)
- [Using IndexedDB](https://developer.mozilla.org/en-US/docs/Web/API/IndexedDB_API/Using_IndexedDB)
