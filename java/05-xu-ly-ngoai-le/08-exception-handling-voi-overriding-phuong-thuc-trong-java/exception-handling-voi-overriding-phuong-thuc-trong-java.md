---
title: "Exception handling với overriding method"
description: "Bài này chúng ta sẽ tìm hiểu về xử lý exception với overriding phương thức trong Java"
chapter:
  name: "Xử lý ngoại lệ"
  slug: "chuong-05-xu-ly-ngoai-le"
category:
  name: "Java"
  slug: "java"
image: https://miro.medium.com/max/1200/1*jJK-9alfR2vnBbXgkDMmkw.png
position: 8
---

## Nếu phương thức của lớp cha không khai báo một exception

Nếu phương thức của lớp cha không khai báo một exception thì phương thức ghi đè của lớp con không thể khai báo `Checked Exception`

```java
import java.io.*;
class Parent{
  void msg(){System.out.println("parent");}
}

class TestExceptionChild extends Parent{
  void msg()throws IOException{
    System.out.println("TestExceptionChild");
  }
  public static void main(String args[]){
   Parent p=new TestExceptionChild();
   p.msg();
  }
}
```

::result

Compile Time Error

::

Nếu phương thức của lớp cha không khai báo một exception thì phương thức ghi đè của lớp con không thể khai báo `Checked Exception` nhưng có thể khai báo `Unchecked Exception`.

```java
import java.io.*;
class Parent{
  void msg(){System.out.println("parent");}
}

class TestExceptionChild1 extends Parent{
  void msg()throws ArithmeticException{
    System.out.println("child");
  }
  public static void main(String args[]){
   Parent p=new TestExceptionChild1();
   p.msg();
  }
}
```

::result

child

::

## Nếu phương thức lớp cha khai báo một exception

Nếu phương thức lớp cha khai báo một exception thì phương thức ghi đè của lớp con có thể khai báo cùng `exception` đó, `exception` của lớp con, hoặc không khai báo `exception` nào, nhưng không thể khai báo `exception` cha.

Ví dụ trường hợp phương thức ghi đè của lớp con khai báo exception cha

```java
import java.io.*;
class Parent{
  void msg()throws ArithmeticException{System.out.println("parent");}
}

class TestExceptionChild2 extends Parent{
  void msg()throws Exception{System.out.println("child");}

  public static void main(String args[]){
   Parent p=new TestExceptionChild2();
   try{
   p.msg();
   }catch(Exception e){}
  }
}
```

::result

Compile Time Error

::

Ví dụ trường hợp phương thức ghi đè của lớp con khai báo cùng exception đó

```java
import java.io.*;
class Parent{
  void msg()throws Exception{System.out.println("parent");}
}

class TestExceptionChild3 extends Parent{
  void msg()throws Exception{System.out.println("child");}

  public static void main(String args[]){
   Parent p=new TestExceptionChild3();
   try{
   p.msg();
   }catch(Exception e){}
  }
}
```

::result

child

::

Ví dụ trường hợp phương thức ghi đè của lớp con khai báo exception của lớp con

```java
import java.io.*;
class Parent{
  void msg()throws Exception{System.out.println("parent");}
}

class TestExceptionChild4 extends Parent{
  void msg()throws ArithmeticException{System.out.println("child");}

  public static void main(String args[]){
   Parent p=new TestExceptionChild4();
   try{
   p.msg();
   }catch(Exception e){}
  }
}
```

::result

child

::

Ví dụ trường hợp phương thức ghi đè của lớp con không khai báo exception nào

```java
import java.io.*;
class Parent{
  void msg()throws Exception{System.out.println("parent");}
}

class TestExceptionChild5 extends Parent{
  void msg(){System.out.println("child");}

  public static void main(String args[]){
   Parent p=new TestExceptionChild5();
   try{
   p.msg();
   }catch(Exception e){}
  }
}
```

::result

child

::
