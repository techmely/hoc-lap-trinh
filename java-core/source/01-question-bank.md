---
title: "Tổng hợp các câu hỏi java"
description: ""
keywords:
  [
    "Tổng hợp các câu hỏi java",
    "các câu hỏi java",
    "Tong hop cac cau hoi java",
    "cac cau hoi java",
  ]
chapter:
  name: "Tài nguyên"
  slug: "chuong-07-tai-nguyen"
category:
  name: "Java"
  slug: "java"
image: https://user-images.githubusercontent.com/29374426/146175674-fa7e09f7-4e42-485e-a2b5-8c664601b203.png
position: 1
---

## Question blank

QN=1
(300)
is a set of java API for executing SQL statements.

A. ODBC

B. JDBC

C. JAVADB

D. None of the others

**ANSWER: B**

MIX
CHOICES:
No

QN=2
(311)
method is used to wait for a client to initiate communications.

A. wait()

B. accept()

C. listen()

D.

**ANSWER: B**

MIX
CHOICES:
Yes

QN=3
(7259)
drivers that are written partly in the Java programming
language and partly in native code. These drivers use a native client library specific to the data source to which they connect. Again, because of the native code, their portability is limite
D.
A. Type 2

B. Type 3

C. Type 1

D. Type 4

**ANSWER: A**

MIX
CHOICES:
Yes

QN=4
(7261)
drivers that are pure Java and implement the network
protocol for a specific data source. The client connects directly to the data source.

A. Type 4

B. Type 3

C. Type 2

D. Type 1

**ANSWER: A**

MIX
CHOICES:
Yes

QN=5
(7260)
drivers that use a pure Java client and communicate with a
middleware server using a database-independent protocol. The middleware server then communicates the client's requests to the data source.

A. Type 3

B. Type 2

C. Type 1

D. Type 4

**ANSWER: A**

MIX
CHOICES:
Yes

QN=6 (7258)
drivers that implement the JDBC API as a mapping to another data access API, such as ODBC. Drivers of this type are generally

dependent on a native library, which limits their portability.

A. Type 1

B. Type 2

C. Type 3

D. Type 4

**ANSWER: A**

MIX
CHOICES:
Yes

QN=7
(1513)

1. public class A {
2. public String doit(int x, int y) {
3. return “a”;
4. }
5.
6. public String doit(int... vals) {
7. return “b”;
8. }
9. }

Given: 25. A a=new A(); 26. System.out.println(a.doit(4, 5));

What is the result? (Choose one.)

A. Line 26 prints “a” to System.out.

B. Line 26 prints “b” to System.out.

C. An exception is thrown at line 26 at runtime.

D. Compilation of class A will fail due to an error in line 6.

**ANSWER: A**
MARK:
1

MIX
CHOICES:
Yes

QN=8 (1525)

1. public class A {
2. public void method1() {
3. B b=new B();
4. b.method2();

5. // more code here
6. }
   7.}

7. public class B {
8. public void method2() {
9. C c=new C();
10. c.method3();
11. // more code here
12. }
    7.}

13. public class C {
14. public void method3() {
15. // more code here
16. }
    5.}

17. try {
18. A a=new A();
19. a.method1();
20. }catch (Exception e) {
21. System.out.print(”an error occurred”);
22. }

Which two are true if a NullPointerException is thrown on line 3 of class
C? (Choose two.)

A. The application will crash.

B. The code on line 29 will be execute
D.
C. The code on line 5 of class A will execute.

D. The code on line 5 of class B will execute.
e.
The exception will be propagated back to line 27.
f.

**ANSWER: B**E
MARK:
2

MIX
CHOICES:
Yes

QN=9

1. try
   {
   (152)
2. // assume s is previously defined

3. URL u = new URL(s);

4. // in is an ObjectInputStream

5. Object o = in.readObject();

6. System.out.println("Success");

7. }
8. catch (MalformedURLException e) {
9. System.out.println("Bad URL");
10. }
11. catch (StreamCorruptedException e) {
12. System.out.println("Bad file contents");
13. }
14. catch (Exception e) {
15. System.out.println("General exception");
16. }
17. finally {
18. System.out.println("Doing finally part");
19. }
20. System.out.println("Carrying on");

Where:
IOException extends Exception StreamCorruptedException extends IOException MalformedURLException extends IOException

What lines are output if the constructor at line 3 throws a
MalformedURLException? (Choose three.)

A. Success

B. Bad URL

C. Bad file contents

D. General exception
e.
Doing finally part
f.
Carrying on
**ANSWER: B**EF
MARK:
2

MIX
CHOICES:
Yes

QN=10 (153)

1. try {
2. // assume s is previously defined
3. URL u = new URL(s);
4. // in is an ObjectInputStream
5. Object o = in.readObject();
6. System.out.println("Success");
7. }
8. catch (MalformedURLException e) {
9. System.out.println("Bad URL");
10. }

11. catch (StreamCorruptedException e) {
12. System.out.println("Bad file contents");
13. }
14. catch (Exception e) {
15. System.out.println("General exception");
16. }
17. finally {
18. System.out.println("Doing finally part");
19. }
20. System.out.println("Carrying on");

What lines are output if the methods at lines 3 and 5 complete successfully without throwing any exceptions? (Choose three.)

A. Success

B. Bad URL

C. Bad file contents

D. General exception
e.
Doing finally part
f.
Carrying on
**ANSWER: A**EF
MARK:
2

MIX
CHOICES:
Yes

QN=11 (1417)

```java
interface Foo {
  int bar();
}
public class Beta {
  class A implements Foo {
    public int bar() { return 1; }
    }
```

Which three statements are true? (Choose three.)

A. Compilation fails.

B. The code compiles and the output is 2.

C. If lines 16, 17 and 18 were removed, compilation would fail.

D. If lines 24, 25 and 26 were removed, compilation would fail.
e.
If lines 16, 17 and 18 were removed, the code would compile and the
output would be 2.
f.
If lines 24, 25 and 26 were removed, the code would compile and the
output would be 1.
**ANSWER: B**EF
MARK:
2

MIX
CHOICES:
Yes

QN=12 (1527)

```java
public class ClassA {
  public void methodA() {
    ClassB classB = new ClassB();
    classB.getValue();
    }
}
```

And:

```java
class ClassB {
  public ClassC classC;
  public String getValue() {
    return classC.getValue();
  }
}
```

And:

```java
class ClassC {
  public String value;
  public String getValue() {
    value = “ClassB”;
    return value;
  }
}

ClassA a = new ClassA();
a.methodA();
```

What is the result? (Choose one.)

A. Compilation fails.

B. ClassC is displaye
D.
C. The code runs with no output.

D. An exception is thrown at runtime.

**ANSWER: D**
MARK:
2

MIX
CHOICES:
Yes

QN=13 11.

```java
public class Bootchy {
int bootch;

String snootch;
public Bootchy() {
this(”snootchy”);
System.out.print(”first “);
}
public Bootchy(String snootch) {
this(420, “snootchy”);

System.out.print(”second “);
}

public Bootchy(int bootch, String snootch) {
this.bootch = bootch;
this.snootch = snootch;
System.out.print(”third “);
}

public static void main(String[] args) {
Bootchy b = new Bootchy();
System.out.print(b.snootch +“ “ + b.bootch);
}
}
```

What is the result? (Choose one.)

A. snootchy 420 third second first

B. snootchy 420 first second third

C. first second third snootchy 420

D. third second first snootchy 420
e.
third first second snootchy 420
f.
first second first third snootchy 420
**ANSWER: D**
MARK:
1

MIX
CHOICES:
Yes

QN=14
(306)
A dialog prevents user input to other windows in the application
unitl the dialog is close
D.
A. Modal

B. Non-Modal

C. Unmodel

D. None of the above

**ANSWER: A**

MIX
CHOICES:
No

QN=15
(239)
A file is created with the following code:

1. FileOutputStream fos = new FileOutputStream("datafile");
2. DataOutputStream dos = new DataOutputStream(fos);
3. for (int i=0; i<500; i++)
4. dos.writeInt(i);

You would like to write code to read back the data from this file. Which solutions will work? (Choose two.)

A. Construct a FileInputStream, passing the name of the file. Onto the
FileInputStream, chain a DataInputStream, and call its readInt() metho
D.
B. Construct a FileReader, passing the name of the file. Call the file reader’s
readInt() metho
D.
C. Construct a RandomAccessFile, passing the name of the file. Call the
random access file’s readInt() metho
D.

D. Construct a FileReader, passing the name of the file. Onto the FileReader,
chain a DataInputStream, and call its readInt() metho
D.
**ANSWER: A**C
MARK:
1

MIX
CHOICES:
Yes

QN=16
(198)
A Java monitor must either extend Thread or implement Runnable.

A. True

B. False

C.

D.

**ANSWER: B**

MIX
CHOICES:
Yes

QN=17
(196)
A monitor called mon has 10 threads in its waiting pool; all these waiting
threads have the same priority. One of the threads is thr1. How can you notify thr1 so that it alone moves from the Waiting state to the Ready state? (Choose one.)

A. Execute notify(thr1); from within synchronized code of mon.

B. Execute mon.notify(thr1); from synchronized code of any object.

C. Execute thr1.notify(); from synchronized code of any object.

D. Execute thr1.notify(); from any code (synchronized or not) of any object.
e.
You cannot specify which thread will get notifie
D. f.

**ANSWER: E**
MARK:
1

MIX
CHOICES:
Yes

QN=18 (1426)
A programmer needs to create a logging method that can accept an arbitrary number of arguments. For example, it may be called in these

ways:

logIt(”log message 1 “);
logIt(”log message2”,”log message3”);
logIt(”log message4”, “log message5”, “log message6“);

Which declaration satisfies this requirement? (Choose one.)

A. public void logIt(String \* msgs)

B. public void logIt(String [] msgs)

C. public void logIt(String... msgs)

D. public void logIt(String msg1, String msg2, String msg3)

**ANSWER: C**
MARK:
1

MIX
CHOICES:
Yes

QN=19
(45)
A signed data type has an equal number of non-zero positive and negative
values available.

A. True

B. False

C.

D.

**ANSWER: B**

MIX
CHOICES:
Yes

QN=20
(194)
A thread wants to make a second thread ineligible for execution. To do
this, the first thread can call the yield() method on the second threa
D.
A. True

B. False

C.

D.

**ANSWER: B**

MIX
CHOICES:
Yes

QN=21
(195)
A thread’s run() method includes the following lines:

1. try {
2. sleep(100);
3. } catch (InterruptedException e) { }

Assuming the thread is not interrupted, which one of the following statements is correct?

A. The code will not compile, because exceptions cannot be caught in a
thread’s run() metho
D.
B. At line 2, the thread will stop running. Execution will resume in, at most,
100 milliseconds.

C. At line 2, the thread will stop running. It will resume running in exactly
100 milliseconds.

D. At line 2, the thread will stop running. It will resume running some time
after 100 milliseconds have elapse
D.
**ANSWER: D**
MARK:
1

MIX
CHOICES:
Yes

QN=22
(7264)
A(n) object is used to submit a query to a database

A. Command

B. Connection

C. Statement

D. DriverManager

**ANSWER: C**
MARK:
1

MIX
CHOICES:
Yes

QN=23
(7263)
A(n) object is uses to obtain a Connection to a Database

A. ConnectionManager

B. DatabaseManager

C. DriverManager

D. JDBCManager

**ANSWER: C**
MARK:
1

MIX
CHOICES:
Yes

QN=24
(66)
After execution of the following code fragment, what are the values of the
variables x, a, and b?

1. int x, a = 6, b = 7;
2. x = a++ + b++;

A. x = 15, a = 7, b = 8

B. x = 15, a = 6, b = 7

C. x = 13, a = 7, b = 8

D. x = 13, a = 6, b = 7

**ANSWER: C**

MIX
CHOICES:
Yes

QN=25 (1410)
Assume that country is set for each class. Given:

10. public class Money {
11. private String country, name;
12. public String getCountry() { return country; }
    13.}
    and:
13. class Yen extends Money {
14. public String getCountry() { return super.country; }
15. }
16. class Euro extends Money {
17. public String getCountry(String timeZone) {
18. return super.getCountry();

19. }
20. }

Which two are correct? (Choose two.)

A. Yen returns correct Country value.

B. Euro returns correct Country value.

C. An exception is thrown at runtime.

D. Yen and Euro both return correct Country value.
e.
Compilation fails because of an error at line 25.
f.
Compilation fails because of an error at line 30.
**ANSWER: B**E
MARK:
2

MIX
CHOICES:
Yes

QN=26
(46)
Choose the valid identifiers from those listed here. (Choose all that apply.)

A. BigOlLongStringWithMeaninglessName

B. $int

C. bytes

D. $1
e.
finalist
f.

**ANSWER: A**BCDE

MIX
CHOICES:
Yes

QN=27 (1520)
Class SomeException:

1. public class SomeException {
2. }

Class A:

1. public class A {
2. public void doSomething() { }
3. }

Class B:

1. public class B extends A {
2. public void doSomething() throws SomeException { }
3. }

Which is true about the two classes? (Choose one.)

A. Compilation of both classes will fail.

B. Compilation of both classes will succee
D.
C. Compilation of class A will fail. Compilation of class B will succee
D.
D. Compilation of class B will fail. Compilation of class A will succee
D.
**ANSWER: D**
MARK:
1

MIX
CHOICES:
Yes

QN=28
(1521)
Class TestException:

1. public class TestException extends Exception {
2. }

Class A:

1. public class A {
2.
3. public String sayHello(String name) throws TestException {
4.
5. if(name == null) {
6. throw new TestException();
7. }
8.
9. return “Hello “+ name;
10. }
11.
12. }
    A programmer wants to use this code in an application:
13. A a=new A();
14. System.out.println(a.sayHello(”John”));

Which two are true? (Choose two.)

A. Class A will not compile.

B. Line 46 can throw the unchecked exception TestException.

C. Line 45 can throw the unchecked exception TestException.

D. Line 46 will compile if the enclosing method throws a TestException.
e.
Line 46 will compile if enclosed in a try block, where TestException is
caught.
f.

**ANSWER: D**E
MARK:
2

MIX CHOICES:
Yes

QN=29
(50)
Consider the following application:

1. class Q6 {
2. public static void main(String args[]) {
3. Holder h = new Holder();
4. h.held = 100;
5. h.bump(h);
6. System.out.println(h.held);
7. }
8. }
9.
10. class Holder {
11. public int held;
12. public void bump(Holder theHolder) {
13. theHolder.held++;
    14 }
14. }
15. }
    What value is printed out at line 6?

A. 0

B. 1

C. 100

D. 101

**ANSWER: D**
MARK:
1

MIX
CHOICES:
Yes

QN=30 (51)
Consider the following application:

1. class Q7 {
2. public static void main(String args[]) {
3. double d = 12.3;
4. Decrementer dec = new Decrementer();
5. dec.decrement(d);
6. System.out.println(d);
7. }
8. }
9.
10. class Decrementer {

11. public void decrement(double decMe) {
12. decMe = decMe - 1.0;
13. }
14. }
    What value is printed out at line 6?

A. 0.0

B. 1.0

C. 12.3

D. 11.3

**ANSWER: C**
MARK:
1

MIX
CHOICES:
Yes

QN=31
(173)
Consider the following class definition:

1. public class Test extends Base {
2. public Test(int j) {
3. }
4. public Test(int j, int k) {
5. super(j, k);
6. }
7. }
   Which of the following are legitimate calls to construct instances of the
   Test class? (Choose two.)

A. Test t = new Test();

B. Test t = new Test(1);

C. Test t = new Test(1, 2);

D. Test t = new Test(1, 2, 3);
e.
Test t = (new Base()).new Test(1);
f.

**ANSWER: B**C
MARK:
1

MIX
CHOICES:
Yes

QN=32 (174)
Consider the following class definition:

1. public class Test extends Base {
2. public Test(int j) {
3. }
4. public Test(int j, int k) {

5. super(j, k);
6. }
7. }
   Which of the following forms of constructor must exist explicitly in the definition of the Base class? Assume Test and Base are in the same package. (Choose two.)

A. Base() { }

B. Base(int j) { }

C. Base(int j, int k) { }

D. Base(int j, int k, int l) { }

**ANSWER: A**C
MARK:
1

MIX
CHOICES:
Yes

QN=33
(131)
Consider the following class:

1. class Cruncher {
2. void crunch(int i) {
3. System.out.println("int version");
4. }
5. void crunch(String s) {
6. System.out.println("String version");
7. }
8.
9. public static void main(String args[]) {
10. Cruncher crun = new Cruncher();
11. char ch = ‘p’;
12. crun.crunch(ch);
13. }
14. }
    Which of the following statements is true? (Choose one.)

A. Line 5 will not compile, because void methods cannot be overridden.

B. Line 12 will not compile, because no version of crunch() takes a char
argument.

C. The code will compile but will throw an exception at line 12.

D. The code will compile and produce the following output: int version.
e.
The code will compile and produce the following output: String version.
f.

**ANSWER: D**
MARK:
2

MIX
Yes

CHOICES:

QN=34
(172)
Consider the following classes, declared in separate source files:

1. public class Base {
2. public void method(int i) {
3. System.out.print(“Value is “ + i);
4. }
5. }
6. public class Sub extends Base {
7. public void method(int j) {
8. System.out.print(“This value is “ + j);
9. }
10. public void method(String s) {
11. System.out.print(“I was passed “ + s);
12. }
13. public static void main(String args[]) {
14. Base b1 = new Base();
15. Base b2 = new Sub();
16. b1.method(5);
17. b2.method(6);
18. }
19. }

What output results when the main method of the class Sub is run?(Choose one.)

A. Value is 5Value is 6

B. This value is 5This value is 6

C. Value is 5This value is 6

D. This value is 5Value is 6
e.
I was passed 5I was passed 6
f.

**ANSWER: C**
MARK:
2

MIX
CHOICES:
Yes

QN=35 (133)
Consider the following code. Which line will not compile? (Choose one.)

1. Object ob = new Object();
2. String[] stringarr = new String[50];
3. Float floater = new Float(3.14f);
4. ob = stringarr;

5. ob = stringarr[5];
6. floater = ob;
7. ob = floater;

A. Line 4

B. Line 5

C. Line 6

D. Line 7

**ANSWER: C**
MARK:
1

MIX
CHOICES:
Yes

QN=36
(156)
Consider the following code:

1. public class Assertification {
2. public static void main(String[] args) {
3. assert args.length == 0;
   4 }
4. }

Which of the following conditions must be true in order for the code to throw an AssertionError?
Assume you are using release 5.0. (Choose two.)

A. The source code must be compiled with the -source 1.5 flag.

B. The application must be run with the -enableassertions flag or another
assertionenabling flag.

C. The args array must have exactly zero elements.

D. The args array must have one or more elements.

**ANSWER: B**D
MARK:
1

MIX
CHOICES:
Yes

QN=37 (64)
Consider the following code:

1. StringBuffer sbuf = new StringBuffer();
2. sbuf = null;
3. System.gc();

Choose true statement. (Choose one.)

A. After line 2 executes, the StringBuffer object is garbage collecte
D.
B. After line 3 executes, the StringBuffer object is garbage collecte
D.
C. After line 2 executes, the StringBuffer object is eligible for garbage
collection.

D. After line 3 executes, the StringBuffer object is eligible for garbage
collection.

**ANSWER: C**
MARK:
1

MIX
CHOICES:
Yes

QN=38
(135)
Consider the following code:

1. Cat sunflower;
2. Washer wawa;
3. SwampThing pogo;
4.
5. sunflower = new Cat();
6. wawa = sunflower;
7. pogo = (SwampThing)wawa;
   Which of the following statements is true? (Choose one.) Where:
   Mammal extends Animal
   Cat, SwampThing extends Mammal
   Cat implements Washer

A. Line 6 will not compile; an explicit cast is required to convert a Cat to a
Washer.

B. Line 7 will not compile, because you cannot cast an interface to a class.

C. The code will compile and run, but the cast in line 7 is not required and can
be eliminate
D.
D. The code will compile but will throw an exception at line 7, because
runtime conversion from an interface to a class is not permitte
D. e.
The code will compile but will throw an exception at line 7, because the
runtime class of wawa cannot be converted to type SwampThing.
f.

**ANSWER: E**
MARK:
2

MIX
Yes

CHOICES:

QN=39
(134)
Consider the following code:

1. Dog rover, fido;
2. Animal anim;
3.
4. rover = new Dog();
5. anim = rover;
6. fido = (Dog)anim;

Where:
Mammal extends Animal
Dog extends Mammal

Which of the following statements is true? (Choose one.)

A. Line 5 will not compile.

B. Line 6 will not compile.

C. The code will compile but will throw an exception at line 6.

D. The code will compile and run.
e.
The code will compile and run, but the cast in line 6 is not required and can
be eliminate
D. f.

**ANSWER: D**
MARK:
1

MIX
CHOICES:
Yes

QN=40
(147)
Consider the following code:

1. for (int i = 0; i < 2; i++) {
2. for (int j = 0; j < 3; j++) {
3. if (i == j) {
4. continue;
5. }
6. System.out.println("i = " + i + " j = " + j);
7. }
8. }
   Which lines would be part of the output? (Choose four.)

A. i = 0 j = 0

B. i = 0 j = 1

C. i = 0 j = 2

D. i = 1 j = 0
e.
i = 1 j = 1
f.
i = 1 j = 2

**ANSWER: B**CDF
MARK:
1

MIX
CHOICES:
Yes

QN=41
(148)
Consider the following code:

1. outer: for (int i = 0; i < 2; i++) {
2. for (int j = 0; j < 3; j++) {
3. if (i == j) {
4. continue outer;
5. }
6. System.out.println("i = " + i + " j = " + j);
7. }
8. }

Which lines would be part of the output? (Choose one.)

A. i = 0 j = 0

B. i = 0 j = 1

C. i = 0 j = 2

D. i = 1 j = 0
e.
i = 1 j = 1
f.
i = 1 j = 2
**ANSWER: D**
MARK:
1

MIX
CHOICES:
Yes

QN=42
(136)
Consider the following code:

1. Raccoon rocky;
2. SwampThing pogo;
3. Washer w;
4.
5. rocky = new Raccoon();
6. w = rocky;
7. pogo = w;

Which of the following statements is true? (Choose one.) Where:
Mammal extends Animal
Dog, Raccoon, Swamp Thing extends Mammal
Raccoon implements Washer

A. Line 6 will not compile; an explicit cast is required to convert a Raccoon to

a Washer.

B. Line 7 will not compile; an explicit cast is required to convert a Washer to
a SwampThing.

C. The code will compile and run.

D. The code will compile but will throw an exception at line 7, because
runtime conversion from an interface to a class is not permitte
D. e.
The code will compile but will throw an exception at line 7, because the
runtime class of w cannot be converted to type SwampThing.
f.

**ANSWER: B**
MARK:
2

MIX
CHOICES:
Yes

QN=43
(175)
Consider the following definition:

1. public class Outer {
2. public int a = 1;
3. private int b = 2;
4. public void method(final int c) {
5. int d = 3, f=10;
6. class Inner {
7. private void iMethod(int e) {
8.
9. }
10. }
11. }
12. }

Which variables can be referenced at line 8? (Choose four.)

A. a

B. b

C. c

D. d
e.
e
f.
f
**ANSWER: A**BCE
MARK:
1

MIX
CHOICES:
Yes

QN=44 Consider the following line of code:

(49)

int[] x = new int[25];

After execution, which statements are true? (Choose two.)

A. x[24] is 0

B. x[24] is undefined

C. x[25] is 0

D. x[0] is null
e.
x.length is 25
f.

**ANSWER: A**E

MIX
CHOICES:
Yes

QN=45
(169)
Consider these classes, defined in separate source files:

1. public class Test1 {
2. public float aMethod(float a, float b) throws IOException {.. }
3. }

4. public class Test2 extends Test1 {
5. 3.}

Which of the following methods would be legal (individually) at line 2 in class Test2? (Choose two)

A. float aMethod(float a, float b) {...}

B. public int aMethod(int a, int b) throws Exception {...}

C. public float aMethod(float a, float b) throws Exception {...}

D. public float aMethod(float p, float q) {...}

**ANSWER: B**D
MARK:
1

MIX
CHOICES:
Yes

QN=46 (167)
Consider this class:

1. public class Test1 {
2. public float aMethod(float a, float b) {

3. }
4.
5. }

Which of the following methods would be legal if added (individually) at line 4? (Choose three.)

A. public int aMethod(int a, int b) { }

B. public float aMethod(float a, float b) { }

C. public float aMethod(float a, float b, int c) throws Exception { }

D. public float aMethod(float c, float d) { }
e.
private float aMethod(int a, int b, int c) { }
f.

**ANSWER: A**CE
MARK:
1

MIX
CHOICES:
Yes

QN=47
(1517)
Give:

11. public static Iterator reverse(List list) {
12. Collections.reverse(list);
13. return list.iterator();
14. }
15. public static void main(String[] args) {
16. List list = new ArrayList();
17. list.add(” 1”); list.add(”2”); list.add(”3”);
18. for (Object obj: reverse(list))
19. System.out.print(obj + “,”);
20. }

‘What is the result? (Choose one.)

A. 3, 2, 1,

B. 1, 2, 3,

C. Compilation fails.

D. The code runs with no output.
e.
An exception is thrown at runtime.
f.

**ANSWER: C**
MARK:
1

MIX
CHOICES:
Yes

QN=48
(212)
Given a string constructed by calling s = new String("xyzzy"), which of the
calls modifies the string? (Choose one.)

A. s.append("aaa");

B. s.trim();

C. s.substring(3);

D. s.replace(‘z’, ‘a’);
e.
s.concat(s);
f.
None of the above
**ANSWER: F**
MARK:
1

MIX
CHOICES:
No

QN=49
(231)
Given arrays a1 and a2, which call returns true if a1 and a2 have the same
length, and a1[i].equals(a2[i]) for every legal index i? (Choose one.)

A. java.util.Arrays.equals(a1, a2);

B. java.util.Arrays.compare(a1, a2);

C. java.util.List.compare(a1, a2);

D.

**ANSWER: A**
MARK:
1

MIX
CHOICES:
Yes

QN=50
(248)
Given the following class:
public class Xyz implements java.io.Serializable {
public int iAmPublic; private int iAmPrivate; static int iAmStatic; transient int iAmTransient; volatile int iAmVolatile;

}
Assuming the class does not perform custom serialization, which fields are written when an instance of Xyz is serialized? (Choose three.)

A. iAmPublic

B. iAmPrivate

C. iAmStatic

D. iAmTransient

e.
iAmVolatile
f.

**ANSWER: A**BE
MARK:
1

MIX
CHOICES:
Yes

QN=51
(113)
Given the following code, and making no other changes, which
combination of access modifiers (public, protected, or private) can legally be placed before aMethod() on line 3 and be placed before aMethod() on line 8? (Choose one.)

1. class SuperDuper
2. {
3. void aMethod() { }
4. }
5.
6. class Sub extends SuperDuper
7. {
8. void aMethod() { }
9. }

A. line 3: public; line 8: private

B. line 3: protected; line 8: private

C. line 3: default; line 8: private

D. line 3: private; line 8: protected
e.
line 3: public; line 8: protected
f.

**ANSWER: D**
MARK:
1

MIX
CHOICES:
Yes

QN=52
(187)
Given the following code, which of the following will compile? (Choose
three.)

enum Spice { NUTMEG, CINNAMON, CORIANDER, ROSEMARY; }

A. Spice sp = Spice.NUTMEG; Object ob = sp;

B. Spice sp = Spice.NUTMEG; Object ob = (Object)sp;

C. Object ob = new Object(); Spice sp = ob

D. Object ob = new Object(); Spice sp = (Spice)ob;
e.
String ob = new String(); Spice sp = ob;
f.

**ANSWER: A**BD
MARK:
1

MIX
CHOICES:
Yes

QN=53
(224)
Given the following:

List<String> names = new ArrayList<String>();

which of the following are legal? (Choose two.)

A. Iterator<String> iter = names.iterator();

B. for (String s:names)

C. while (String s:names)

D.

**ANSWER: A**B

MIX
CHOICES:
Yes

QN=54
(1524)
Given:

11. static class A {
12. void process() throws Exception { throw new Exception(); }
13. }
14. static class B extends A {
15. void process() { System.out.println(”B “); }
16. }
    17.public static void main(String[] args) {
17. A a=new B();
18. a.process();
19. }

What is the result? (Choose one.)

A. B

B. The code runs with no output.

C. An exception is thrown at runtime.

D. Compilation fails because of an error in line 15.
e.
Compilation fails because of an error in line 18.
f.
Compilation fails because of an error in line 19.
**ANSWER: F**

MARK:
2

MIX
CHOICES:
Yes

QN=55
(1407)
Given:

public class Bar {
public static void main(String [] args) {
int x =5;
boolean b1 = true; boolean b2 = false; if((x==4) && !b2)
System.out.print("l "); System.out.print("2 ");
if ((b2 = true) && b1) System.out.print("3");
}
}

What is the result? (Choose one.)

A. 2

B. 3

C. 1 2

D. 2 3
e.
1 2 3
f.
Compilation fails.
**ANSWER: D**
MARK:
1

MIX
CHOICES:
Yes

QN=56
(1418)
Given:

1. public interface A {
2. String DEFAULT_GREETING = “Hello World”;
3. public void method1();
4. }

A programmer wants to create an interface called B that has A as its parent. Which interface declaration is correct? (Choose one.)

A. public interface B extends A { }

B. public interface B implements A {}

C. public interface B instanceOf A {}

D. public interface B inheritsFrom A { }

**ANSWER: A**

MIX
CHOICES:
Yes

QN=57
(1420)
Given:

10. abstract public class Employee {
11. protected abstract double getSalesAmount();
12. public double getCommision() {
13. return getSalesAmount() \* 0.15;
14. }
15. }
16. class Sales extends Employee {
17. // insert method here
18. }

Which two methods, inserted independently at line 17, correctly complete the Sales class? (Choose two.)

A. double getSalesAmount() { return 1230.45; }

B. public double getSalesAmount() { return 1230.45; }

C. private double getSalesAmount() { return 1230.45; }

D. protected double getSalesAmount() { return 1230.45; }

**ANSWER: B**D
MARK:
1

MIX
CHOICES:
Yes

QN=58 (1530)
Given:

10. class MakeFile {
11. public static void main(String[] args) {
12. try {
13. File directory = new File(”d”);
14. File file = new File(directory,”f”);
15. if(!file.exists()) {

16. file.createNewFile();
17. }
18. }catch (IOException e) {
19. e.printStackTrace ();
20. }
21. }
22. }

The current directory does NOT contain a directory named “d.” Which three are true? (Choose three.)

A. Line 16 is never execute
D.
B. An exception is thrown at runtime.

C. Line 13 creates a File object named “d.”

D. Line 14 creates a File object named “f.’
e.
Line 13 creates a directory named “d” in the file system.
f.
Line 16 creates a directory named “d” and a file ‘f’ within it in the file
system.
**ANSWER: B**CD
MARK:
2

MIX
CHOICES:
Yes

QN=59
(1415)
Given:

10. class Nav{
11. public enum Direction { NORTH, SOUTH, EAST, WEST }
12. }
13. public class Sprite{
14. // insert code here
15. }

Which code, inserted at line 14, allows the Sprite class to compile? (Choose one.)

A. Direction d = NORTH;

B. Nav.Direction d = NORTH;

C. Direction d = Direction.NORTH;

D. Nav.Direction d = Nav.Direction.NORTH;

**ANSWER: D**
MARK:
1

MIX
CHOICES:
Yes

QN=60
(1416)
Given:

10. interface Foo { int bar(); }
11. public class Sprite {
12. public int fubar( Foo foo) { return foo.bar(); }
13. public void testFoo() {
14. fubar(
15. // insert code here
16. );
17. }
18. }

Which code, inserted at line 15, allows the class Sprite to compile? (Choose one.)

A. Foo { public int bar() { return 1; } }

B. new Foo { public int bar() { return 1; } }

C. new Foo() { public int bar(){return 1; } }

D. new class Foo { public int bar() { return 1; } }

**ANSWER: C**
MARK:
1

MIX
CHOICES:
Yes

QN=61
(1528)
Given:

10. public class ClassA {
11. public void count(int i) {
12. count(++i);
13. }
14. } And:
15. ClassA a = new ClassA();
16. a.count(3);

Which exception or error should be thrown by the virtual machine? (Choose one.)

A. StackOverflowError

B. NullPointerException

C. NumberFormatException

D. IllegalArgumentException
e.
ExceptionlnlnitializerError
f.

**ANSWER: A**
MARK:
1

MIX
CHOICES:
Yes

QN=62
(1419)
Given:

11. public abstract class Shape {
12. int x;
13. int y;
14. public abstract void draw();
15. public void setAnchor(int x, int y) {
16. this.x = x;
17. this.y = y;
18. }
19. }
    and a class Circle that extends and fully implements the Shape class. Which is correct? (Choose one.)

A. Shape s = new Shape(); s.setAnchor(10,10); s.draw();

B. Circle c = new Shape(); c.setAnchor(10,10); c.draw();

C. Shape s = new Circle(); s.setAnchor(10,10); s.draw();

D. Shape s = new Circle(); s->setAnchor(10,10); s->draw();
e.
Circle c = new Circle(); c.Shape.setAnchor(10,10); c.Shape.draw();
f.

**ANSWER: C**
MARK:
1

MIX
CHOICES:
Yes

QN=63 (1425)
Given:

11. public static void main(String[] args) {
12. Object obj =new int[] { 1,2,3 };
13. int[] someArray = (int[])obj;
14. for (int i: someArray) System.out.print(i +" ");
15. }

What is the result? (Choose one.)

A. 1 2 3

B. Compilation fails because of an error in line 12.

C. Compilation fails because of an error in line 13.

D. Compilation fails because of an error in line 14.
e.
A ClassCastException is thrown at runtime.
f.

**ANSWER: A**
MARK:
1

MIX
CHOICES:
Yes

QN=64
(1526)
Given:

11. public static void main(String[] args) {
12. try {
13. args=null;
14. args[0] = “test”;
15. System.out.println(args[0]);
16. }catch (Exception ex) {
17. System.out.println(”Exception”);
18. }catch (NullPointerException npe) {
19. System.out.println(”NullPointerException”);
20. }
21. }

What is the result? (Choose one.)

A. Test

B. Exception

C. Compilation fails.

D. NullPointerException

**ANSWER: C**
MARK:
1

MIX
CHOICES:
Yes

QN=65 (1421)
Given:

11. public static void parse(String str) {

12. try {
13. float f= Float.parseFloat(str);
14. } catch (NumberFormatException nfe) {
15. f = 0;
16. } finally {
17. System.out.println(f);
18. }
19. }
20. public static void main(String[] args) {
21. parse("invalid");
22. }

What is the result? (Choose one.)

A. 0.0

B. Compilation fails.

C. A ParseException is thrown by the parse method at runtime.

D. A NumberFormatException is thrown by the parse method at runtime.

**ANSWER: B**
MARK:
1

MIX
CHOICES:
Yes

QN=66
(1532)
Given:

11. String test = “This is a test”;
12. String[] tokens = test.split(”\s”);
13. System.out.println(tokens.length);

What is the result? (Choose one.)

A. 0

B. 1

C. 4

D. Compilation fails.
e.
An exception is thrown at runtime.
f.

**ANSWER: D**
MARK:
1

MIX
CHOICES:
Yes

QN=67
(1519)
Given:

12. public class AssertStuff {
13. public static void main(String [] args) {
14. int x= 5;
15. int y= 7;
16. assert (x > y): “stuff”;
17. System.out.println(”passed”);
18. }
19. }

And these command line invocations:

java AssertStuff java -ea AssertStuff

What is the result? (Choose one.)

A. Passed
Stuff

B. Stuff
Passed

C. passed
An AssertionError is thrown with the word “stuff” added to the stack trace.

D. passed
An AssertionError is thrown without the word “stuff” added to the stack trace.
e.
passed
An AssertionException is thrown with the word “stuff” added to the stack trace.
f.
passed
An AssertionException is thrown without the word “stuff” added to the stack trace.
**ANSWER: C**
MARK:
1

MIX
CHOICES:
Yes

QN=68 (1516)
Given:

12. public class Test {
13. public enum Dogs {collie, harrier};
14. public static void main(String [] args) {
15. Dogs myDog = Dogs.collie;
16. switch (myDog) {

17. case collie:
18. System.out.print(”collie “);
19. case harrier:
20. System.out.print(”harrier “);
21. }
22. }
23. }

What is the result? (Choose one.)

A. collie

B. harrier

C. Compilation fails.

D. collie harrier
e.
An exception is thrown at runtime.
f.

**ANSWER: D**
MARK:
1

MIX
CHOICES:
Yes

QN=69
(1414)
Given:

13. public class Pass {
14. public static void main(String [] args) {
15. int x = 5;
16. Pass p = new Pass();
17. p.doStuff(x);
18. System.out.print(" main x = "+ x);
19. }
20.
21. void doStuff(int x) {
22. System.out.print("doStuff x = "+ x++);
23. }
24. }

What is the result? (Choose one.)

A. Compilation fails.

B. An exception is thrown at runtime.

C. doStuff x = 6 main x = 6

D. doStuff x = 5 main x = 5
e.
doStuff x = 5 main x = 6
f.
doStuff x = 6 main x = 5
**ANSWER: D**
MARK:
1

MIX
CHOICES:
Yes

QN=70
(1413)
Given:

13. public class Pass {
14. public static void main(String [] args) {
15. int x = 5;
16. Pass p = new Pass();
17. p.doStuff(x);
18. System.out.print(" main x = "+ x);
19. }
20.
21. void doStuff(int x) {
22. System.out.print("doStuffx = "+ x++);
23. }
24. }

What is the result? (Choose one.)

A. Compilation fails.

B. An exception is thrown at runtime.

C. doStuffx = 6 main x = 6

D. doStuffx = 5 main x = 5
e.
doStuffx = 5 main x = 6
f.
doStuffx = 6 main x = 5
**ANSWER: D**
MARK:
1

MIX
CHOICES:
Yes

QN=71 (1409)
Given:

20. public class CreditCard {
21. private String cardlD;
22. private Integer limit;
23. public String ownerName;
24. public void setCardlnformation(String cardlD,
25. String ownerName,
26. Integer limit) {
27. this.cardlD = cardlD;
28. this.ownerName = ownerName;
29. this.limit = limit;

30. }
31. }

Which is true? (Choose one.)

A. The class is fully encapsulate
D.
B. The code demonstrates polymorphism.

C. The ownerName variable breaks encapsulation.

D. The cardlD and limit variables break polymorphism.
e.
The setCardlnformation method breaks encapsulation.
f.

**ANSWER: C**
MARK:
1

MIX
CHOICES:
Yes

QN=72
(1412)
Given:

23. Object [] myObjects = {
24. new Integer(12),
25. new String(”foo”),
26. new Integer(5),
27. new Boolean(true)
28. };
29. java.util.Array.sort(myObjects);
30. for( int i=0; i<myObjects.length; i++) {
31. System.out.print(myObjects[i].toString());
32. System.out.print(” “);
33. }

What is the result? (Choose one.)

A. Compilation fails due to an error in line 23.

B. Compilation fails due to an error in line 29.

C. A ClassCastException occurs in line 29.

D. A ClassCastException occurs in line 31.
e.
The value of all four objects prints in natural order.
f.

**ANSWER: B**
MARK:
2

MIX
CHOICES:
Yes

QN=73 Given:

(1408)

31. // some code here
32. try {
33. // some code here
34. } catch (SomeException se) {
35. // some code here
36. } finally {
37. // some code here
38. }

Under which three circumstances will the code on line 37 be executed? (Choose three.)

A. The instance gets garbage collecte
D.
B. The code on line 33 throws an exception.

C. The code on line 35 throws an exception.

D. The code on line 31 throws an exception.
e.
The code on line 33 executes successfully.
f.

**ANSWER: B**CE
MARK:
1

MIX
CHOICES:
Yes

QN=74
(1522)
Given:

33. try {
34. // some code here
35. }catch (NullPointerException e1) {
36. System.out.print(”a”);
37. }catch (RuntimeException e2) {
38. System.out.print(”b”);
39. } finally {
40. System.out.print(”c”);
41. }

What is the result if a NullPointerException occurs on line 34? (Choose one.)

A. c

B. a

C. ab

D. ac
e.
bc
f.
abc
**ANSWER: D**

MARK:
1

MIX
CHOICES:
Yes

QN=75
(1422)
Given:

55. int []x= {1, 2,3,4, 5};
56. int y[] =x;
57. System.out.println(y[2]);

Which is true? (Choose one.)

A. Line 57 will print the value 2.

B. Line 57 will print the value 3.

C. Compilation will fail because of an error in line 55.

D. Compilation will fail because of an error in line 56.

**ANSWER: B**

MIX
CHOICES:
Yes

QN=76
(1518)
Given:

8. public class test {
9. public static void main(String [] a) {
10. assert a.length == 1;
11. }
    12.}

Which two will produce an AssertionError? (Choose two.)

A. java test

B. java -ea test

C. java test file1

D. java -ea test file1
e.
java -ea test file1 file2
f.
java -ea:test test file1
**ANSWER: B**E
MARK:
1

MIX
Yes

CHOICES:

QN=77
(1529)
Given:

1. public class TestString3 {
2. public static void main(String[] args) {
3. // insert code here
4. System.out.println(s);
5. }
6. }

Which two code fragments, inserted independently at line 3, generate the output 4247? (Choose two.)

A. String s = “123456789”; s = (s-”123”).replace(1,3,”24”) - “89”;

B. StringBuffer s = new StringBuffer(”123456789”);
s.delete(0,3).replace( 1,3, “24”).delete(4,6);

C. StringBuffer s = new StringBuffer(”123456789”);
s.substring(3,6).delete( 1 ,3).insert( 1, “24”);

D. StringBuilder s = new StringBuilder(”123456789”);
s.substring(3,6).delete( 1 ,2).insert( 1, “24”);
e.
StringBuilder s = new StringBuilder(”123456789”);
s.delete(0,3).delete( 1 ,3).delete(2,5).insert( 1, “24”);
f.

**ANSWER: B**E
MARK:
1

MIX
CHOICES:
Yes

QN=78
(1514)
Given: 10. class Line { 11. public static class Point { } 12. } 13. 14. class Triangle { 15. // insert code here 16. }

Which code, inserted at line 15, creates an instance of the Point class defined in Line? (Choose one.)

A. Point p = new Point();

B. Line.Point p = new Line.Point();

C. The Point class cannot be instatiated at line 15.

D. Line l = new Line() ; Point p = new l.Point();

**ANSWER: B**
MARK:
1

MIX
CHOICES:
Yes

QN=79
(1406)
Given: 10. public class Bar { 11. static void foo(int...x) { 12. // insert code here 13. } 14. }

Which two code fragments, inserted independently at line 12, will allow the class to compile? (Choose two.)

A. foreach(x) System.out.println(z);

B. for(int z : x) System.out.println(z);

C. while( x.hasNext()) System.out.println( x.next());

D. for( int i=0; i< x.length; i++ ) System.out.println(x[i]);

**ANSWER: B**D
MARK:
1

MIX
CHOICES:
Yes

QN=80
(1405)
Given: 11. public interface Status { 12. /_ insert code here _/ int MY_VALUE = 10; 13. }

Which three are valid on line 12? (Choose three.)

A. final

B. static

C. native

D. public
e.
protected
f.
abstract
**ANSWER: A**BD
MARK:
1

MIX CHOICES:
Yes

QN=81
(1523)
Given:
class A {
public void process() { System.out.print("A "); }
public static void main(String[] args) {
try { ((A)new B()).process(); }
catch (Exception e) { System.out.print("Exception "); }
}
}
class B extends A {
public void process() throws RuntimeException {
super.process();
if (true) throw new RuntimeException(); System.out.print("B");
}
}

What is the result? (Choose one.)

A. Exception

B. A Exception

C. A Exception B

D. A B Exception
e.
Compilation fails because of an error in line: public void process() throws
RuntimeException
f.
Compilation fails because of an error in line: try { ((A)new
B()).process(); }
**ANSWER: B**
MARK:
2

MIX
CHOICES:
Yes

QN=82
(209)
How can you ensure that multithreaded code does not deadlock? (Choose
one.)

A. Synchronize access to all shared variables.

B. Make sure all threads yield from time to time.

C. Vary the priorities of your threads.

D. There is no single technique that can guarantee non-deadlocking code.

**ANSWER: D**
MARK:
1

MIX
CHOICES:
Yes

QN=83
(52)
How can you force garbage collection of an object? (Choose one.)

A. Garbage collection cannot be force
D.
B. Call System.gc().

C. Call System.gc(), passing in a reference to the object to be garbage-
collecte
D.
D. Call Runtime.gc().
e.
Set all references to the object to new values (null, for example).
f.

**ANSWER: A**
MARK:
1

MIX
CHOICES:
Yes

QN=84
(208)
How do you prevent shared data from being corrupted in a multithreaded
environment? (Choose one.)

A. Mark all variables as synchronize
D.
B. Mark all variables as volatile.

C. Use only static variables.

D. Access the variables only via synchronized methods.

**ANSWER: D**
MARK:
1

MIX
CHOICES:
Yes

QN=85
(236)
How do you use the File class to list the contents of a directory? (Choose
one.)

A. String[] contents = myFile.list();

B. File[] contents = myFile.list();

C. StringBuilder[] contents = myFile.list();

D. The File class does not provide a way to list the contents of a directory.

**ANSWER: A**

MARK:
1

MIX
CHOICES:
Yes

QN=86
(237)
How many bytes does the following code write to file dest? (Choose one.)

1. try {
2. FileOutputStream fos = newFileOutputStream("dest");
3. DataOutputStream dos = new DataOutputStream(fos);
4. dos.writeInt(3);
5. dos.writeFloat(0.0001f);
6. dos.close();
7. fos.close();
8. }
9. catch (IOException e) { }

A. 2

B. 8

C. 12

D. 16
e.
The number of bytes depends on the underlying system.
f.

**ANSWER: B**
MARK:
1

MIX
CHOICES:
Yes

QN=87
(204)
How many locks does an object have? (Choose one.)

A. One

B. One for each method

C. One for each synchronized method

D. One for each non-static synchronized method

**ANSWER: A**

MIX
CHOICES:
Yes

QN=88
(48)
If all three top-level elements occur in a source file, they must appear in
which order? (Choose one.)

A. Imports, package declarations, classes/interfaces/enums

B. Classes/interfaces/enums, imports, package declarations

C. Package declaration must come first; order for imports and
class/interfaces/enum definitions is not significant

D. Package declaration, imports, class/interface/enum definitions.
e.
Imports must come first; order for package declarations and
class/interface/enum definitions is not significant
f.

**ANSWER: D**

MIX
CHOICES:
Yes

QN=89
(123)
If class Y extends class X, the two classes are in different packages, and
class X has a protected method called abby(), then any instance of Y may call the abby() method of any
other instance of Y.

A. True

B. False

C.

D.

**ANSWER: B**
MARK:
1

MIX
CHOICES:
Yes

QN=90 (197)
If you attempt to compile and execute the following application, will it ever print out the message In xxx?

1. class TestThread3 extends Thread {
2. public void run() {
3. System.out.println("Running");
4. System.out.println("Done");
5. }
6.
7. private void xxx() {
8. System.out.println(“In xxx”);
9. }

10.
11. public static void main(String args[]) {
12. TestThread3 ttt = new TestThread3();
13. ttt.xxx();
14. ttt.start();
15. }
16. }

A. Yes

B. No

C.

D.

**ANSWER: A**
MARK:
1

MIX
CHOICES:
Yes

QN=91
(1877)
If you need a Set implementation that provides value-ordered iteration,
which class should you use? (Choose one.)

A. HashSet

B. LinkedHashSet

C. TreeSet

D.

**ANSWER: C**

MIX
CHOICES:
Yes

QN=92
(1875)
In order for objects in a List to be sorted, those objects must implement
which interface and method? (Choose one.)

A. Comparable interface and its compareTo metho
D.
B. Comparable interface and its compare method

C. Compare interface and its compareTo method

D. Comparable interface and its equals method

**ANSWER: A**
MARK:
1

MIX
CHOICES:
Yes

QN=93
(218)
In the following code fragment, after execution of line 1, sbuf references
an instance of the StringBuffer class. After execution of line 2, sbuf still references the same instance.

1. StringBuffer sbuf = new StringBuffer("FPT");
2. sbuf.append("-University");

A. True

B. False

C.

D.

**ANSWER: A**

MIX
CHOICES:
Yes

QN=94
(217)
In the following code fragment, after execution of line 1, sbuf references
an instance of the StringBuffer class. After execution of line 2, sbuf still references the same instance.

1. StringBuffer sbuf = new StringBuffer("FPT");
2. sbuf.insert(3, "-University");

A. True

B. False

C.

D.

**ANSWER: A**

MIX
CHOICES:
Yes

QN=95 (130)
In the following code, what are the possible types for variable result? (Choose the most complete true answer.)

1. byte b = 11;
2. short s = 13;
3. result = b \* ++s;

A. byte, short, int, long, float, double

B. boolean, byte, short, char, int, long, float, double

C. byte, short, char, int, long, float, double

D. byte, short, char
e.
int, long, float, double
f.

**ANSWER: E**
MARK:
1

MIX
CHOICES:
Yes

QN=96
(7266)
Interface helps manage the connection between a Java program and a
database.

A. ResultSet

B. DriverManager

C. Statement

D. Connection

**ANSWER: D**
MARK:
1

MIX
CHOICES:
Yes

QN=97
(76)
Is it possible to define a class called Thing so that the following method
can return true under certain circumstances?
boolean weird(Thing s) { Integer x = new Integer(5); return s.equals(x);
}

A. Yes

B. No

C.

D.

**ANSWER: A**

MIX
CHOICES:
Yes

QN=98
(205)
Is it possible to write code that can execute only if the current thread owns
multiple locks?

A. Yes

B. No

C.

D.

**ANSWER: A**

MIX
CHOICES:
Yes

QN=99
(301)
JDBC supports and models.

A. Single-tier and two-tier

B. Two-tier and three-tier

C. Three-tier and four-tier

D. None of the others

**ANSWER: B**
MARK:
1

MIX
CHOICES:
No

QN=100
(305)
MVC is short call of

A. Model-View-Controller

B. Multiple-View-Controller

C. Metal-View-Controller

D.

**ANSWER: A**

MIX
CHOICES:
Yes

QN=101
(129)
public class Test{
public static void main(String[] args){
byte b = 2; byte b1 = 3; b = b \* b1;
System.out.println("b="+b);
}
}

What is the output?

A. b=6

B. No output because of compile error at line: b = b \* b1;

C. No output because of compile error at line: System.out.println("b="+b);

D. No output because of compile error at line: byte b = 2;
e.
No output because of compile error at line: byte b = 3;
f.

**ANSWER: B**
MARK:
1

MIX
CHOICES:
Yes

QN=102
(77)
public class Test{
public static void main(String[] args){ Object ob1= new Object(); Object ob2= new Object();
if(ob1.equals(ob2)) System.out.println("ob1 equals ob2"); if(ob1==ob2) System.out.println("ob1==ob2"); System.out.println("Have a nice day!");
}

}

What is the output?

A. ob1 equals ob2
Have a nice day!

B. ob1==ob2
Have a nice day!

C. Have a nice day!

D. No output

**ANSWER: C**
MARK:
1

MIX
CHOICES:
Yes

QN=103
(4924)
public class Test{
public static void main(String[] args){ Object ob1= new Object(); Object ob2= ob1;
if(ob1.equals(ob2)) System.out.println("ob1 equals ob2"); if(ob1==ob2) System.out.println("ob1==ob2"); System.out.println("Have a nice day!");
}

}

What is the output?

A. ob1 equals ob2
ob1==ob2
Have a nice day!

B. ob1 equals ob2
Have a nice day!

C. ob1==ob2
Have a nice day!

D. None of the above

**ANSWER: A**
MARK:
1

MIX
CHOICES:
No

QN=104 (4925)
public class Test{
public static void main(String[] args){ String s1 = "xyz";
String s2 = "xyz";
if (s1 == s2) System.out.println("Line 4"); if (s1.equals(s2)) System.out.println("Line 6");

}
}

What is the output?

A. Line 4
Line 6

B. Line 4

C. Line 6

D. No output, compile error
e.
No output
f.

**ANSWER: A**
MARK:
1

MIX
CHOICES:
Yes

QN=105
(219)
public class Test{
public static void main(String[] args){ String s1 = "xyz";
String s2 = new String("xyz");
if (s1 == s2) System.out.println("Line 4"); if (s1.equals(s2)) System.out.println("Line 6");
}
}

What is the output?

A. Line 4
Line 6

B. Line 4

C. Line 6

D. No output, compile error
e.
No output
f.

**ANSWER: C**
MARK:
1

MIX
CHOICES:
Yes

QN=106 (4926)
public class Test{
public static void main(String[] args){

String s1 = "xyz";
String s2 = new String(s1);
s2.intern();
if (s1 == s2) System.out.println("Line 4");
if (s1.equals(s2)) System.out.println("Line 6");
}
}

What is the output?

A. Line 4

B. Line 6

C. Line 4
Line 6

D. No output, compile error
e.
No output
f.

**ANSWER: B**
MARK:
1

MIX
CHOICES:
Yes

QN=107
(220)
public class Test{
public static void main(String[] args){ String s1 = "xyz";
String s2 = new String(s1);
s2=s2.intern();
if (s1 == s2) System.out.println("Line 4");
if (s1.equals(s2)) System.out.println("Line 6");
}
}

What is the output? (choose 1)

A. Line 4

B. Line 6

C. Line 4
Line 6

D. No output, compile error
e.
No output
f.

**ANSWER: C**

MARK:
1

MIX
CHOICES:
Yes

QN=108
(4941)
Select correct statement about RMI. (choose 1)

A. allow programmers to develop distributed Java programs with the same
syntax and semantics used for non-distributed programs.

B. use object serialization to marshal and unmarshal parameters, supporting
true object-oriented polymorphism.

C. RMI applications are often comprised of two separate programs: a server
and a client.

D. All the above

**ANSWER: D**
MARK:
1

MIX
CHOICES:
No

QN=109
(4943)
Select correct statement(s) about remote class.(choose one)

A. It must extend java.rmi.server.UnicastRemoteObject.

B. It must implement the remote interface.

C. It is the class whose methods provide services to clients.

D. All the others choices

**ANSWER: D**
MARK:
1

MIX
CHOICES:
Yes

QN=110
(4942)
Select correct statements about remote interface. (choose 1)

A. A remote interface is an interface that describes the remotely accessible
methods of a remote object.

B. All remote interfaces must extend java.rmi.Remote.

C. All methods in a remote interface must throw java.rmi.RemoteException

D. The type of a remote reference is a remote interface
e.
All the others choices
f.

**ANSWER: E**
MARK:
1

MIX
CHOICES:
Yes

QN=111
(4939)
Select INCORRECT statement about serialization. (choose 1)

A. The process of writing an object is called serialization.

B. To serialize an object, first create an instance of
java.io.ObjectOutputStream.

C. When an Object Output Stream serializes an object that contains references
to another object, every referenced object is not serialized along with the original object.

D. When an object is serialized, it will probably be deserialized by a different
JVM.

**ANSWER: C**
MARK:
1

MIX
CHOICES:
Yes

QN=112
(4940)
Select INCORRECT statement about deserialize. (choose 1)

A. Any JVM that tries to deserialize an object must have access to that
object’s class definition.

B. We use readObject() method of ObjectOutputStream class to deserialize.

C. The readObject method deserializes the next object in the stream and
traverses its references to other objects recursively to deserialize all objects that are reachable from it.

D.

**ANSWER: B**
MARK:
1

MIX
CHOICES:
Yes

QN=113
(4944)
Select incorrect statement about RMI server.(choose 1)

A. An RMI server is an application that creates one or more remote objects
and makes them available to clients.

B. An RMI server performs two tasks:

1. Create an instance of the remote object.
2. Bind the remote object to a name.

C. The RMI registry is a program that associates names with RMI services. A
server specifies a name for every remote object it provides.

D. A client accesses a remote object by specifying only the server name.

**ANSWER: D**
MARK:
1

MIX
CHOICES:
Yes

QN=114
(4938)
Select incorrect statement about ServerSocket class. (choose 1)

A. The most useful form of the ServerSocket constructor is public
ServerSocket(int portNumber)

B. A server socket, on the other hand, makes itself available and then waits
for clients to initiate connections.

C. To make the new object available for client connections, call its accept()
method, which returns an instance of ServerSocket

D. There is no way to know how long the accept() call will take.

**ANSWER: C**
MARK:
1

MIX
CHOICES:
Yes

QN=115
(4937)
Select incorrect statement about Socket class. (choose 1)

A. The java.net.Socket class contains code that knows how to find and
communicate with a server through UDP.

B. One of its constructors is: public Socket(String servername, int
portNumber)

C. You do not directly read from or write to a socket

D. The java.net.Socket class contains code that knows how to find and
communicate with a server through TCP.

**ANSWER: A**
MARK:
1

MIX
CHOICES:
Yes

QN=116
(7257)
Select the correct statement about JDBC two-tier processing model.

A. A user's commands are delivered to the database or other data source, and
the results of those statements are sent back to the user.

B. Two-tier is referred to as a client/server configuration, with the user's
machine as the Server, and the machine housing the data source as the
Client.

C. User's commands are sent to a "middle tier" of services, which then sends
the commands to the data source.

D.

**ANSWER: A**
MARK:
1

MIX
CHOICES:
Yes

QN=117
(7265)
SQL keyword is followed by the selection criteria that specify the
rows to select in a query

A. FROM

B. ORDER BY

C. HAVING

D. WHERE

**ANSWER: D**
MARK:
1

MIX
CHOICES:
Yes

QN=118
(7262)
Statement objects return SQL query results as objects

A. DataSet

B. ResultSet

C. RecordSet

D. RowSet

**ANSWER: B**
MARK:
1

MIX
CHOICES:
Yes

QN=119
(4927)
Study the statements:
1)When a JDBC connection is created, it is in auto-commit mode
2)Once auto-commit mode is disabled, no SQL statements will be committed until you call the method commit explicitly

A. Only statement 1 is true

B. Only statement 2 is true

C. Both 1 and 2 are true

D. Both 1 and 2 are not true

**ANSWER: C**
MARK:
1

MIX
CHOICES:
Yes

QN=120
(160)
Suppose a method called finallyTest() consists of a try block, followed by a
catch block, followed by a finally block. Assuming the JVM doesn’t crash and the code does not execute a System.exit() call, under what circumstances will the finally block not begin to execute? (Choose one.)

A. The try block throws an exception, and the catch block also throws an
exception.

B. The try block throws an exception that is not handled by the catch block.

C. The try block throws an exception, and the catch block calls finallyTest()
in a way that causes another exception to be thrown.

D. If the JVM doesn't crash and the code does not execute a System.exit() call,
the finally block will always execute.

**ANSWER: D**
MARK:
1

MIX
CHOICES:
Yes

QN=121
(56)
Suppose a source file contains a large number of import statements and one
class definition. How do the imports affect the time required to load the class? (Choose one.)

A. Class loading takes no additional time.

B. Class loading takes slightly more time.

C. Class loading takes significantly more time.

D.

**ANSWER: A**
MARK:
1

MIX
CHOICES:
Yes

QN=122
(55)
Suppose a source file contains a large number of import statements. How
do the imports affect the time required to compile the source file? (Choose one.)

A. Compilation takes no additional time.

B. Compilation takes slightly more time.

C. Compilation takes significantly more time.

D.

**ANSWER: B**
MARK:
1

MIX
CHOICES:
Yes

QN=123
(247)
Suppose class A extends Object; Class B extends A; and class C extends B.
Of these, only class C implements java.io.Externalizable. Which of the following must be true in order to avoid an exception during deserialization of an instance of C? (Choose one.)

A. A must have a no-args constructor.

B. B must have a no-args constructor.

C. C must have a no-args constructor.

D. There are no restrictions regarding no-args constructors.

**ANSWER: C**
MARK:
2

MIX
CHOICES:
Yes

QN=124
(246)
Suppose class A extends Object; class B extends A; and class C extends B.
Of these, only class C implements java.io.Serializable. Which of the following must be true in order to avoid an exception during deserialization of an instance of C? (Choose one.)

A. A must have a no-args constructor.

B. B must have a no-args constructor.

C. C must have a no-args constructor.

D. There are no restrictions regarding no-args constructors.

**ANSWER: B**
MARK:
2

MIX
CHOICES:
Yes

QN=125
(122)
Suppose class A has a method called doSomething(), with default access.
Suppose class B extends A and overrides doSomething(). Which access modes may not apply to B’s version of doSomething()? (Choose one)

A. public

B. private

C. protected

D. Default

**ANSWER: B**
MARK:
1

MIX
CHOICES:
Yes

QN=126
(117)
Suppose class Supe, in package packagea, has a method called
doSomething(). Suppose class Subby, in package packageb, overrides doSomething(). What access modes may Subby’s version of the method have? (Choose two.)

A. public

B. protected

C. Default

D. private

**ANSWER: A**B
MARK:
1

MIX
CHOICES:
Yes

QN=127
(190)
Suppose class X contains the following method:

void doSomething(int a, float b) { … }

Which of the following methods may appear in class Y, which extends X? (Choose one.)

A. public void doSomething(int a, float b) { … }

B. private void doSomething(int a, float b) { … }

C. public void doSomething(int a, float b) throws java.io.IOException { … }

D. private void doSomething(int a, float b) throws java.io.IOException { … }

**ANSWER: A**

MIX
CHOICES:
Yes

QN=128
(119)
Suppose interface Inty defines five methods. Suppose class Classy declares
that it implements Inty but does not provide implementations for any of the five interface methods. Which are true? (Choose two.)

A. The class will not compile.

B. The class will compile if it is declared publi
C.
C. The class will compile if it is declared abstract.

D. The class may not be instantiate
D.
**ANSWER: C**D
MARK:
1

MIX
CHOICES:
Yes

QN=129
(222)
Suppose prim is an int and wrapped is an Integer. Which of the following
are legal Java statements? (Choose one.)

A. prim = wrapped;

B. wrapped = prim;

C. prim = new Integer(9);

D. wrapped = 9;
e.
All the above
f.

**ANSWER: E**
MARK:
1

MIX
CHOICES:
No

QN=130
(158)
Suppose salaries is an array containing floats. Which of the following are
valid loop control statements for processing each element of salaries? (Choose one.)

A. for (float f:salaries)

B. for (int i:salaries)

C. for (float f::salaries)

D. for (int i::salaries)

**ANSWER: A**

MIX
CHOICES:
Yes

QN=131
(139)
Suppose the declared type of x is a class, and the declared type of y is an
interface. When is the assignment x = y; legal? (Choose one.)

A. When the type of x is Object

B. When the type of x is an array

C. Always

D. Never

**ANSWER: A**
MARK:
1

MIX
CHOICES:
Yes

QN=132
(140)
Suppose the type of xarr is an array of XXX, and the type of yarr is an
array of YYY. When is the assignment xarr = yarr; legal? (Choose one.)

A. Sometimes

B. Always

C. Never

D. None of the others choices

**ANSWER: A**
MARK:
1

MIX
CHOICES:
No

QN=133
(183)
Suppose x and y are of type TrafficLightState, which is an enum. What is
the best way to test whether x and y refer to the same constant? (Choose one.)

A. if (x == y)

B. if (x.equals(y))

C. if (x.toString().equals(y.toString()))

D. if (x.hashCode() == y.hashCode())

**ANSWER: A**

MIX
CHOICES:
Yes

QN=134
(245)
Suppose you are writing a class that will provide custom deserialization.
The class implements java.io.Serializable (not java.io.Externalizable). What access mode should the readObject() method have? (Choose one.)

A. public

B. protected

C. default

D. private

**ANSWER: D**
MARK:
1

MIX
CHOICES:
Yes

QN=135
(243)
Suppose you are writing a class that will provide custom serialization. The
class implements java.io.Serializable (not java.io.Externalizable). What access mode should the writeObject() method have? (Choose one.)

A. public

B. protected

C. default

D. private

**ANSWER: D**
MARK:
1

MIX
CHOICES:
Yes

QN=136
(211)
Suppose you want to create a custom thread class by extending
java.lang.Thread in order to provide some special functionality. Which of the following must you do? (Choose one.)

A. Declare that your class implements java.lang.Runnable.

B. Override run().

C. Override start().

D. Make sure that all access to all data is via synchronized methods.

**ANSWER: B**

MIX
CHOICES:
Yes

QN=137 (214)
Suppose you want to write a class that offers static methods to compute hyperbolic trigonometric functions. You decide to subclass java.lang.Math and provide the new functionality as a set of static methods. Which one

statement is true about this strategy?

A. The strategy works.

B. The strategy works, provided the new methods are publi
C.
C. The strategy works, provided the new methods are not private.

D. The strategy fails because you cannot subclass java.lang.Math.
e.
The strategy fails because you cannot add static methods to a subclass.
f.

**ANSWER: D**
MARK:
1

MIX
CHOICES:
Yes

QN=138
(304)
Swing components cannot be combined with AWT components.

A. True

B. False

C.

D.

**ANSWER: A**

MIX
CHOICES:
Yes

QN=139
(299)
The class is the primary class that has the driver information.

A. DriverManager

B. Driver

C. ODBCDriver

D. None of the others

**ANSWER: A**
MARK:
1

MIX
CHOICES:
No

QN=140 The class is used to implement a pull-down menu that provides a

(307)
number of items to select from.

A. MenuBar

B. Menu

C. MenuItem

D. PopUp

**ANSWER: B**

MIX
CHOICES:
Yes

QN=141
(1876)
The element method alters the contents of a Queue.

A. True

B. False

C.

D.

**ANSWER: B**

MIX
CHOICES:
Yes

QN=142
(303)
The Swing component classes can be found in the
package.

A. javax.swing

B. java.swing

C. javax.swings

D. javax.Swing

**ANSWER: A**

MIX
CHOICES:
Yes

QN=143 There are two classes in Java to enable communication using datagrams

(310)
namely.

A. DataPacket and DataSocket

B. DatagramPacket and DatagramSocket

C. DatagramPack and DatagramSock

D.

**ANSWER: A**

MIX
CHOICES:
Yes

QN=144
(115)
This question concerns the following class definition:

1. package abcde;
2.
3. public class Bird {
4. protected static int referenceCount = 0;
5. public Bird() { referenceCount++; }
6. protected void fly() { /_ Flap wings, etc. _/ }
7. static int getRefCount() { return referenceCount; }
8. }
   Which statement is true about class Bird and the following class Parrot? (Choose one.)
9. package abcde;
10.
11. class Parrot extends abcde.Bird {
12. public void fly() {
13. /_ Parrot-specific flight code. _/
14. }
15. public int getRefCount() {
16. return referenceCount;
17. }
18. }

A. Compilation of Parrot.java fails at line 4 because method fly() is protected
in the superclass, and classes Bird and Parrot are in the same package.

B. Compilation of Parrot.java fails at line 4 because method fly() is protected
in the superclass and public in the subclass, and methods may not be overridden to be more publi
C.
C. Compilation of Parrot.java fails at line 7 because method getRefCount() is
static in the superclass, and static methods may not be overridden to be nonstati
C.
D. Compilation of Parrot.java succeeds, but a runtime exception is thrown if
method fly() is ever called on an instance of class Parrot.
e.
Compilation of Parrot.java succeeds, but a runtime exception is thrown if

method getRefCount() is ever called on an instance of class Parrot.
f.

**ANSWER: C**
MARK:
2

MIX
CHOICES:
Yes

QN=145
(116)
This question concerns the following class definition:

1. package abcde;
2.
3. public class Bird {
4. protected static int referenceCount = 0;
5. public Bird() { referenceCount++; }
6. protected void fly() { /_ Flap wings, etc. _/ }
7. static int getRefCount() { return referenceCount; }
8. }
   Which statement is true about class Bird and the following class
   Nightingale? (Choose one.)
9. package singers;
10.
11. class Nightingale extends abcde.Bird {
12. Nightingale() { referenceCount++; }
13.
14. public static void main(String args[]) {
15. System.out.print("Before: " + referenceCount);
16. Nightingale florence = new Nightingale();
17. System.out.println(" After: " + referenceCount);
18. florence.fly();
19. }
20. }

A. The program will compile and execute. The output will be Before: 0 After: 21.
B. The program will compile and execute. The output will be Before: 0 After: 22.
C. Compilation of Nightingale will fail at line 4 because static members
cannot be overridden.

D. Compilation of Nightingale will fail at line 10 because method fly() is
protected in the superclass.
e.
Compilation of Nightingale will succeed, but an exception will be thrown
at line 10, because method fly() is protected in the superclass.
f.

**ANSWER: A**
MARK:
2

MIX CHOICES:
Yes

QN=146
(191)
This question involves IOException, AWTException, and EOFException.
They are all checked exception types. IOException and AWTException extend Exception, and EOFException extends OException.

Suppose class X contains the following method:

void doSomething() throws IOException{ … }

Which of the following methods may appear in class Y, which extends X? (Choose three.)

A. void doSomething() { … }

B. void doSomething() throws AWTException { … }

C. void doSomething() throws EOFException { … }

D. void doSomething() throws IOException, EOFException { … }

**ANSWER: A**CD
MARK:
1

MIX
CHOICES:
Yes

QN=147
(4930)
URL referring to databases use the form:

A. protocol:subprotocol:datasoursename

B. protocol:datasoursename

C. jdbc:odbc:datasoursename

D. jdbc:datasoursename

**ANSWER: A**
MARK:
1

MIX
CHOICES:
Yes

QN=148 (142)
What are the legal types for whatsMyType? (Choose one.)

short s = 10;

whatsMyType = !s;

A. short

B. int

C. There are no possible legal types.

D. long
e.
char
f.
byte
**ANSWER: C**
MARK:
1

MIX
CHOICES:
Yes

QN=149
(75)
What does the following code do?
Integer i = null;
if (i != null & i.intValue() == 5) System.out.println("Value is 5");

A. Prints “Value is 5”.

B. Throws an exception.

C. Compile error

D.

**ANSWER: B**
MARK:
1

MIX
CHOICES:
Yes

QN=150
(238)
What does the following code fragment print out at line 9? (Choose one.)

1. FileOutputStream fos = new FileOutputStream("xx");
2. for (byte b=10; b<50; b++)
3. fos.write(b);
4. fos.close();
5. RandomAccessFile raf = new RandomAccessFile("xx", "r");
6. raf.seek(10);
7. int i = raf.read();
8. raf.close()
9. System.out.println(“i = “ + i);

A. The output is i = 30.

B. The output is i = 20.

C. The output is i = 10.

D. There is no output because the code throws an exception at line 1.
e.
There is no output because the code throws an exception at line 5.
f.

**ANSWER: B**
MARK:
1

MIX
CHOICES:
Yes

QN=151
(126)
What does the following code print?
public class A
{
static int x;
public static void main(String[] args) { A that1 = new A();
A that2 = new A();
that1.x = 5; that2.x = 1000; x = -1;
System.out.println(x);
}
}

A. 0

B. 5

C. 1000

D. -1

**ANSWER: D**
MARK:
1

MIX
CHOICES:
Yes

QN=152 (251)
What happens when you try to compile and run the following application? (Choose one.)

1. import java.io.\*;
2.
3. public class Xxx {
4. public static void main(String[] args) {
5. try {
6. File f = new File("xxx.ser");
7. FileOutputStream fos = new FileOutputStream(f);

8. ObjectOutputStream oos = new ObjectOutputStream(fos);
9. oos.writeObject(new Object());
10. oos.close();
11. fos.close();
12. }
13. catch (Exception x) { }
14. }
15. }

A. Compiler error at line 9.

B. An exception is thrown at line 9.

C. An exception is thrown at line 10.

D. No compiler error and no exception.

**ANSWER: B**
MARK:
1

MIX
CHOICES:
Yes

QN=153
(59)
What happens when you try to compile and run the following code?
public class Q {
static String s;
public static void main(String[] args) { System.out.println(">>" + s + "<<");
}
}

A. The code does not compile

B. The code compiles, and prints out >><<

C. The code compiles, and prints out >>null<<

D.

**ANSWER: C**

MIX
CHOICES:
Yes

QN=154 (230)
What happens when you try to compile and run this application? (Choose one.)

1. import java.util.\*;
2.

3. public class Apple {
4. public static void main(String[] a) {
5. Set<Apple> set = new TreeSet<Apple>();
6. set.add(new Apple());
7. set.add(new Apple());
8. set.add(new Apple());
9. }
10. }

A. Compiler error.

B. An exception is thrown at line 6.

C. An exception is thrown at line 7.

D. An exception is thrown at line 8.
e.
No exception is thrown.
f.

**ANSWER: C**
MARK:
1

MIX
CHOICES:
Yes

QN=155
(86)
What is -50 >> 2

A. A negative number with very large magnitude.

B. A positive number with very large magnitude.

C. -13

D. -25
e.
13
f.
25
**ANSWER: C**
MARK:
1

MIX
CHOICES:
Yes

QN=156
(72)
What is 7 % -4?

A. -3

B. 3

C. -4

D. 4

**ANSWER: B**

MIX
CHOICES:
Yes

QN=157
(71)
What is -8 % 5?

A. -3

B. 3

C. -2

D. 2

**ANSWER: A**

MIX
CHOICES:
Yes

QN=158
(146)
What is the difference between the rules for method-call conversion and
the rules for assignment conversion? (Choose one.)

A. There is no difference; the rules are the same.

B. Method-call conversion supports narrowing, assignment conversion does
not.

C. Assignment conversion supports narrowing, method-call conversion does
not.

D. Method-call conversion supports narrowing if the method declares that it
throws ClassCastException.

**ANSWER: A**
MARK:
1

MIX
CHOICES:
Yes

QN=159 (109)
What is the minimal modification that will make this code compile correctly? (Choose one.)

1. final class Aaa
2. {
3. int xxx;
4. void yyy() { xxx = 1; }

5. }
6.
7.
8. class Bbb extends Aaa
9. {
10. final Aaa finalref = new Aaa();
11.
12. final void yyy()
13. {
14. System.out.println("In method yyy()");
15. finalref.xxx = 12345;
16. }
17. }

A. On line 1, remove the final modifier.

B. On line 10, remove the final modifier.

C. Remove line 15.

D. On lines 1 and 10, remove the final modifier.
e.
The code will compile as is. No modification is neede
D. f.

**ANSWER: A**
MARK:
2

MIX
CHOICES:
Yes

QN=160
(54)
What is the range of values that can be assigned to a variable of type byte?
(Choose one.)

A. Depends on the underlying hardware

B. 0 through 2^8 − 1

C. 0 through 2^16 − 1

D. −2^7 through 2^7 − 1
e.
−2^15 through 2^15 − 1
f.

**ANSWER: D**

MIX
CHOICES:
Yes

QN=161
(53)
What is the range of values that can be assigned to a variable of type short?
(Choose one.)

A. Depends on the underlying hardware

B. 0 through 2^16 − 1

C. 0 through 2^32 − 1

D. −2^15 through 2^15 − 1
e.
−2^31 through 2^31 − 1
f.

**ANSWER: D**

MIX
CHOICES:
Yes

QN=162
(242)
What is the result of attempting to compile and execute the following code
fragment? Assume that the code fragment is part of an application that has write permission in the current working directory. Also assume that before execution, the current working directory does not contain a file called datafile. (Choose one.)

1. try {
2. RandomAccessFile raf = new
3. RandomAccessFile("datafile" ,"rw");
4. BufferedOutputStream bos = new BufferedOutputStream(raf);
5.
6. DataOutputStream dos = new DataOutputStream(bos);
7.
8. dos.writeDouble(Math.PI);
9. dos.close();
10. bos.close();
11. raf.close();
12. }
13. catch (IOException e) { }

A. The code fails to compile.

B. The code compiles but throws an exception at line 4.

C. The code compiles and executes but has no effect on the local file system.

D. The code compiles and executes; afterward, the current working directory
contains a file called datafile.

**ANSWER: A**
MARK:
2

MIX
CHOICES:
Yes

QN=163 (83)
What is the return type of the instanceof operator?

A. A reference

B. A class

C. An int

D. A boolean

**ANSWER: D**

MIX
CHOICES:
Yes

QN=164
(249)
What method of the java.io.File class can create a file on the hard drive?
(Choose one.)

A. newFile()

B. makeFile()

C. makeNewFile()

D. createFile()
e.
createNewFile()
f.

**ANSWER: E**

MIX
CHOICES:
Yes

QN=165
(74)
What results from attempting to compile and run the following code?

1. public class Conditional {
2. public static void main(String args[]) {
3. int x = 4;
4. System.out.println("value is " + ((x > 4) ? 99.99 : 9));
5. }
6. }

A. The output: value is 99.99

B. The output: value is 9

C. The output: value is 9.0

D. A compiler error at line 4

**ANSWER: C**
MARK:
1

MIX
Yes

CHOICES:

QN=166
(73)
What results from running the following code?

1. public class Xor {
2. public static void main(String args[]) {
3. byte b = 10; // 00001010 binary
4. byte c = 15; // 00001111 binary
5. b = (byte)(b ^ c);
6. System.out.println("b contains " + b);
7. }
8. }

A. The output: b contains 10

B. The output: b contains 5

C. The output: b contains 250

D. The output: b contains 245

**ANSWER: B**
MARK:
1

MIX
CHOICES:
Yes

QN=167
(150)
What would be the output from this code fragment?

1. int x = 0, y = 4, z = 5;
2. if (x > 2) {
3. if (y < 5) {
4. System.out.println("message one");
5. }
6. else {
7. System.out.println("message two");
8. }
9. }
10. else if (z > 5) {
11. System.out.println("message three");
12. }
13. else {
14. System.out.println("message four");
15. }

A. message one

B. message two

C. message three

D. message four

**ANSWER: D**
MARK:
1

MIX
CHOICES:
Yes

QN=168
(78)
When a byte is added to a char, what is the type of the result?

A. byte

B. char

C. int

D. short
e.
You can’t add a byte to a char.
f.

**ANSWER: C**

MIX
CHOICES:
Yes

QN=169
(144)
When a negative byte is cast to a long, what are the possible values of the
result? (Choose one.)

A. Positive

B. Zero

C. Negative

D. All the above

**ANSWER: C**

MIX
CHOICES:
No

QN=170
(143)
When a negative long is cast to a byte, what are the possible values of the
result? (Choose one.)

A. Positive

B. Zero

C. Negative

D. All the above

**ANSWER: D**

MIX
CHOICES:
No

QN=171
(79)
When a short is added to a float, what is the type of the result?

A. short

B. int

C. float

D. You can’t add a short to a float.

**ANSWER: C**

MIX
CHOICES:
Yes

QN=172
(1531)
When comparing java.io.BufferedWriter to java.io.FileWriter, which
capability exists as a method in only one of the two? (Choose one.)

A. closing the stream

B. flushing the stream

C. writing to the stream

D. marking a location in the stream
e.
writing a line separator to the stream
f.

**ANSWER: E**
MARK:
1

MIX
CHOICES:
Yes

QN=173
(165)
When does an exception's stack trace get recorded in the exception object?
(Choose one.)

A. When the exception is constructed

B. When the exception is thrown

C. When the exception is caught

D. When the exception’s printStackTrace() method is called

**ANSWER: A**
MARK:
1

MIX
CHOICES:
Yes

QN=174
(163)
When is it appropriate to pass a cause to an exception's constructor?
(Choose one.)

A. Always

B. When the exception is being thrown in response to catching of a different
exception type

C. When the exception is being thrown from a public method

D. When the exception is being thrown from a private method

**ANSWER: B**
MARK:
1

MIX
CHOICES:
Yes

QN=175
(166)
When is it appropriate to write code that constructs and throws an error?
(Choose one.)

A. When a public method’s preconditions are violated

B. When a public method’s postconditions are violated

C. When a nonpublic method’s preconditions are violated

D. When a nonpublic method’s postconditions are violated
e.
Never
f.

**ANSWER: E**
MARK:
1

MIX
CHOICES:
Yes

QN=176
(141)
When is x & y an int? (Choose one).

A. Always

B. Sometimes

C. When neither x nor y is a float, a long, or a double

D. None of the others

**ANSWER: B**
MARK:
1

MIX
CHOICES:
No

QN=177
(308)
When the user attempts to close the frame window, event in
generate
D.
A. window closing

B. window resize

C. window move

D. window close
e.
window closed
f.

**ANSWER: A**
MARK:
1

MIX
CHOICES:
Yes

QN=178
(312)
When the user selects a menu item, event is generate
D.
A. Select event

B. Action event

C. Item event

D. None of the others

**ANSWER: B**
MARK:
1

MIX
CHOICES:
No

QN=179
(5694)
When you compile a program written in the Java programming language,
the compiler converts the human-readable source file into platform- independent code that a Java Virtual Machine can understand. What is this platform-independent code called?

A. bytecode

B. binary code

C. machine code

D. cpu instruction

**ANSWER: A**
MARK:
1

MIX
CHOICES:
Yes

QN=180
(313)
Whenever a method does not want to handle exceptions using the try
block, the is use
D.
A. throws

B. throw

C. throwable

D. nothrows

**ANSWER: A**

MIX
CHOICES:
Yes

QN=181
(7267)
Which are the correct statements used for getting connection object to
connect to SQL Server database?

A. String url ="jdbc:odbc:data_source_name"; Connection con =
DriverManager.getConnection (url, “user", "password");

B. String url ="odbc:jdbc:data_source_name"; Connection con =
DriverManager.getConnection (url, “user", "password");

C. String url ="jdbc:data_source_name:odbc"; Connection con =
DriverManager.getConnection (url, “user", "password");

D.

**ANSWER: A**
MARK:
1

MIX
CHOICES:
Yes

QN=182
(1879)
Which class and static method can you use to convert an array to a List?
(Choose one.)

A. Arrays.asList

B. Arrays.toList

C. Arrays.createList

D. Arrays.makeList

**ANSWER: A**

MIX
CHOICES:
Yes

QN=183
(302)
Which is four-step approach to help you organize your GUI thinking.
(Choose one.)

A. Identify needed components.
Isolate regions of behavior. Sketch the GUI.
Choose layout managers.

B. Choose layout managers.
Identify needed components. Isolate regions of behavior. Sketch the GUI.

C. Identify needed components.
Choose layout managers. Isolate regions of behavior. Sketch the GUI.

D.

**ANSWER: A**
MARK:
1

MIX
CHOICES:
Yes

QN=184
(4928)
Which is the four steps are used in working with JDBC?

A. 1)Connect to the database
2)Create a statement and execute the query
3)Look at the result set
4)Close connection

B. 1)Load driver
2)Create a statement and execute the query
3)Look at the result set
4)Close connection

C. 1)Create a statement and execute the query
2)Load driver
3)Look at the result set
4)Close connection

D. 1)Create a statement and execute the query
2)Create the connection
3)Look at the result set
4)Close connection

**ANSWER: A**
MARK:
1

MIX
CHOICES:
Yes

QN=185
(7256)
Which JDBC processing model that requires a JDBC driver that can
communicate with the particular data source being accessed?

A. two-tier

B. three-tier

C. one-tier

D. four-tier

**ANSWER: A**
MARK:
1

MIX
CHOICES:
Yes

QN=186
(229)
Which line of code tells a scanner called sc to use a single digit as a
delimiter? (Choose one.)

A. sc.useDelimiter("d");

B. sc.useDelimiter("\d");

C. sc.useDelimiter("\\d");

D. sc.useDelimiter("d+");
e.
sc.useDelimiter("\d+");
f.
sc.useDelimiter("\\d+");
**ANSWER: C**

MARK:
1

MIX
CHOICES:
Yes

QN=187
(1411)
Which Man class properly represents the relationship "Man has the best
friend who is a Dog"? (Choose one.)

A. class Man extends Dog { }

B. class Man implements Dog { }

C. class Man { private BestFriend dog; }

D. class Man { private Dog bestFriend; }
e.
class Man { private Dog<bestFriend> }
f.
class Man { private BestFriend<dog> }
**ANSWER: D**
MARK:
1

MIX
CHOICES:
Yes

QN=188
(189)
Which methods return an enum constant’s name? (Choose two.)

A. getName()

B. name()

C. toString()

D. nameString()
e.
getNameString()
f.

**ANSWER: B**C

MIX
CHOICES:
Yes

QN=189
(114)
Which modifier or modifiers should be used to denote a variable that
should not be written out as part of its class's persistent state? (Choose the shortest possible answer.)

A. private

B. protected

C. private protected

D. transient
e.
volatile
f.

**ANSWER: D**
MARK:
1

MIX
CHOICES:
Yes

QN=190
(162)
Which of the following are legal argument types for a switch statement?
(Choose three.)

A. byte

B. int

C. long

D. float
e.
char
f.
String
**ANSWER: A**BE

MIX
CHOICES:
Yes

QN=191
(177)
Which of the following are legal enums? (Choose three.)

A. enum Animals { LION, TIGER, BEAR }

B. enum Animals {
int age;
LION, TIGER, BEAR;
}

C. enum Animals {
LION, TIGER, BEAR;
int weight;
}

D. enum Animals {
LION(450), TIGER(450), BEAR;
int weight; Animals(int w) {
weight = w;
}
}
e.
enum Animals {
LION(450), TIGER(450), BEAR;
int weight; Animals() { } Animals(int w) {
weight = w;

}
}
f.

**ANSWER: A**CE
MARK:
1

MIX
CHOICES:
Yes

QN=192
(57)
Which of the following are legal import statements? (Choose two.)

A. import java.util.Vector;

B. static import java.util.Vector.\_;

C. import static java.util.Vector.\_;

D. import java.util.Vector static;

**ANSWER: A**C

MIX
CHOICES:
Yes

QN=193
(149)
Which of the following are legal loop constructions? (Choose one.)

A. while (int i<7) {
i++;
System.out.println("i is " + i);
}

B. int i = 3;
while (i) {
System.out.println("i is " + i);
}

C. int j = 0;
for (int k=0, j+k != 10; j++,k++) { System.out.println("j=" + j + ", k=" + k);
}

D. int j=0;
do {
System.out.println("j=" + j++);
if (j==3) continue loop;
} while (j<10);

**ANSWER: C**
MARK:
1

MIX
CHOICES:
Yes

QN=194
(161)
Which of the following are legal loop definitions? (Choose one.)

A. while (int a = 0) { /_ whatever _/ }

B. while (int a == 0) { /_ whatever _/ }

C. do { /_ whatever _/ } while (int a = 0)

D. do { /_ whatever _/ } while (int a == 0)
e.
for (int a==0; a<100; a++) { /_ whatever _/ }
f.
None of the above.
**ANSWER: F**
MARK:
1

MIX
CHOICES:
No

QN=195
(159)
Which of the following are legal? (Choose three.)

A. for (int i=0, j=1; i<10; i++, j++)

B. for (int i=0, j=1;; i++, j++)

C. for (int i=0, float j=1; ; i++, j++)

D. for (String s = ""; s.length()<10; s += '!')
e.
while(1)
f.

**ANSWER: A**BD
MARK:
1

MIX
CHOICES:
Yes

QN=196
(62)
Which of the following are legal? (Choose two.)

A. double d = 1.2d;

B. double d = 1.2D;

C. double d = 1.2d5;

D. double d = 1.2D5;

**ANSWER: A**B

MIX
CHOICES:
Yes

QN=197
(61)
Which of the following are legal? (Choose two.)

A. int a = abcd;

B. int b = ABCD;

C. int c = 0xabcd;

D. int d = 0XABCD;
e.
int f = 0ABCD;
f.

**ANSWER: C**D

MIX
CHOICES:
Yes

QN=198
(63)
Which of the following are legal? (Choose two.)

A. char c = 0x1234;

B. char c = \u1234;

C. char c = '\u1234';

D.

**ANSWER: A**C

MIX
CHOICES:
Yes

QN=199
(223)
Which of the following are legal? (Choose two.)

A. List<String> theList = new Vector<String>;

B. List<String> theList = new Vector<String>();

C. Vector <String> theVec = new Vector<String>;

D. Vector <String> theVec = new Vector<String>();

**ANSWER: B**D

MIX
CHOICES:
Yes

QN=200
(228)
Which of the following are methods of the java.util.SortedMap interface?
(Choose three.)

A. first

B. last

C. headMap

D. tailMap
e.
subMap
f.

**ANSWER: C**DE
MARK:
1

MIX
CHOICES:
Yes

QN=201
(227)
Which of the following are methods of the java.util.SortedSet interface?
(Choose one.)

A. first

B. last

C. headSet

D. tailSet
e.
subSet
f.
All the above
**ANSWER: F**
MARK:
1

MIX
CHOICES:
No

QN=202
(250)
Which of the following are true? (Choose one.)

A. System.out has a println() metho
D.
B. System.out has a format() metho
D.
C. System.err has a println() metho
D.
D. System.err has a format () metho
D. e.
All the above

f.

**ANSWER: E**

MIX
CHOICES:
No

QN=203
(207)
Which of the following are true? (Choose one.)

A. The JVM runs until there is only one daemon threa
D.
B. The JVM runs until there are no daemon threads.

C. The JVM runs until there is only one non-daemon threa
D.
D. The JVM runs until there are no non-daemon threads.

**ANSWER: D**
MARK:
1

MIX
CHOICES:
Yes

QN=204
(206)
Which of the following are true? (Choose three.)

A. When an application begins running, there is one daemon thread, whose
job is to execute main().

B. When an application begins running, there is one non-daemon thread,
whose job is to execute main().

C. A thread created by a daemon thread is initially also a daemon threa
D.
D. A thread created by a non-daemon thread is initially also a non-daemon
threa
D.
**ANSWER: B**CD
MARK:
1

MIX
CHOICES:
Yes

QN=205
(210)
Which of the following are true? (Choose two.)

A. When you declare a method to be synchronized, the method always
synchronizes on the lock of the current object.

B. When you declare a method to be synchronized, you can specify the object
on whose lock the method should synchronize.

C. When you declare a block of code inside a method to be synchronized, the
block always synchronizes on the lock of the current object.

D. When you declare a block of code inside a method to be synchronized, you
can specify the object on whose lock the block should synchronize.

**ANSWER: A**D
MARK:
1

MIX
CHOICES:
Yes

QN=206
(185)
Which of the following are true? (Choose two.)

A. An enum definition should declare that it extends java.lang.Enum.

B. An enum may be subclasse
D.
C. An enum may contain public method definitions.

D. An enum may contain private dat
A.
**ANSWER: C**D

MIX
CHOICES:
Yes

QN=207
(65)
Which of the following are true? (Choose two.)

A. Primitives are passed by reference.

B. Primitives are passed by value.

C. References are passed by reference.

D. References are passed by value.

**ANSWER: B**D

MIX
CHOICES:
Yes

QN=208
(188)
Which of the following are true? (Choose two.)

A. An anonymous inner class may implement at most one interface.

B. An anonymous inner class may implement arbitrarily many interfaces.

C. An anonymous inner class may extend a parent class other than Object.

D. An anonymous inner class that implements one interface may extend a
parent class other than Object.
e.
An anonymous inner class that implements several interfaces may extend a
parent class other than Object.
f.

**ANSWER: A**C
MARK:
1

MIX
CHOICES:
Yes

QN=209
(253)
Which of the following are valid arguments to the DataInputStream
constructor? (Choose one.)

A. File

B. FileReader

C. FileInputStream

D. RandomAccessFile

**ANSWER: C**

MIX
CHOICES:
Yes

QN=210
(252)
Which of the following are valid mode strings for the RandomAccessFile
constructor? (Choose one.)

A. "r"

B. "rw"

C. "rws"

D. "rwd"
e.
All the above
f.

**ANSWER: E**
MARK:
1

MIX
CHOICES:
No

QN=211
(203)
Which of the following calls may be made from a non-static synchronized
method? (Choose one.)

A. A call to the same method of the current object.

B. A call to the same method of a different instance of the current class.

C. A call to a different synchronized method of the current object.

D. A call to a static synchronized method of the current class.
e.
All the above
f.

**ANSWER: E**
MARK:
1

MIX
CHOICES:
No

QN=212
(226)
Which of the following classes implement java.util.List? (Choose two.)

A. java.util.ArrayList

B. java.util.HashMap

C. java.util.TreeSet

D. java.util.Stack

**ANSWER: A**D

MIX
CHOICES:
Yes

QN=213
(1878)
Which of the following classes implements a FIFO Queue? (Choose one.)

A. HashSet

B. LinkedList

C. PriorityQueue

D. CopyOnWriteArraySet

**ANSWER: B**
MARK:
1

MIX
CHOICES:
Yes

QN=214
(107)
Which of the following declarations are illegal? (Choose three.)

A. default String s;

B. transient int i = 41;

C. public final static native int w();

D. abstract double d;
e.
abstract final double hyperbolicCosine();
f.

**ANSWER: A**DE

MIX
CHOICES:
Yes

QN=215
(68)
Which of the following expressions are legal? (Choose two.)

A. int x = 6; x = !x;

B. int x = 6; if (!(x > 3)) {}

C. int x = 6; x = ~x;

D.

**ANSWER: B**C

MIX
CHOICES:
Yes

QN=216
(70)
Which of the following expressions are legal? (Choose two.)

A. String x = "Hello"; int y = 9; x += y;

B. String x = "Hello"; int y = 9; if (x == y) {}

C. String x = "Hello"; int y = 9; x = x + y;

D. String x = "Hello"; int y = 9; y = y + x;

**ANSWER: A**C

MIX
CHOICES:
Yes

QN=217
(69)
Which of the following expressions results in a positive value in x?
(Choose one.)

A. int x = –1; x = x >>> 5;

B. int x = –1; x = x >>> 32;

C. byte x = –1; x = x >>> 5;

D. int x = –1; x = x >> 5;

**ANSWER: A**

MIX
CHOICES:
Yes

QN=218
(1874)
Which of the following interfaces does not allow duplicate objects?
(Choose one.)

A. Queue

B. Set

C. List

D.

**ANSWER: B**

MIX
CHOICES:
Yes

QN=219
(155)
Which of the following is not appropriate situations for assertions?
(Choose one)

A. Preconditions of a public method

B. Postconditions of a public method

C. Preconditions of a private method

D. Postconditions of a private method

**ANSWER: A**
MARK:
1

MIX
CHOICES:
Yes

QN=220
(5695)
Which of the following is NOTa valid comment:

A. /\*_ comment _/

B. /_ comment _/

C. /\* comment

D. // comment

**ANSWER: C**
MARK:
1

MIX
CHOICES:
Yes

QN=221
(157)
Which of the following is the most appropriate way to handle invalid
arguments in a public method?

A. Throw java.lang.InvalidArgumentException.

B. Throw java.lang.IllegalArgumentException.

C. Check for argument validity in an assert statement, which throws
AssertionError when the arguments are invali
D.
D. Use non-assert code to check for argument validity. If invalid arguments
are detected, explicitly throw AssertionError.

**ANSWER: B**
MARK:
1

MIX
CHOICES:
Yes

QN=222
(240)
Which of the following is true? (Choose one.)

A. Readers have methods that can read and return floats and doubles.

B. Readers have methods that can read and return floats.

C. Readers have methods that can read and return doubles.

D. Readers have methods that can read and return ints.
e.
None of the above
f.

**ANSWER: E**
MARK:
1

MIX No
CHOICES:

QN=223
(184)
Which of the following is(are) true? (Choose one.)

A. An enum definition may contain the main() method of an application.

B. You can call an enum’s toString() metho
D.
C. You can call an enum’s wait() metho
D.
D. You can call an enum’s notify() metho
D. e.
All the above
f.

**ANSWER: E**
MARK:
1

MIX
CHOICES:
No

QN=224
(84)
Which of the following may appear on the left-hand side of an instanceof
operator?

A. A reference

B. A class

C. An interface

D. A variable of primitive type

**ANSWER: A**
MARK:
1

MIX
CHOICES:
Yes

QN=225
(85)
Which of the following may appear on the right-hand side of an instanceof
operator? (Choose two.)

A. A reference

B. A class

C. An interface

D. A variable of primitive type
e.
The name of a primitive type
f.

**ANSWER: B**C
MARK:
1

MIX CHOICES:
Yes

QN=226
(120)
Which of the following may be declared final? (Choose two.)

A. Classes

B. Interfaces

C. Methods

D.

**ANSWER: A**C

MIX
CHOICES:
Yes

QN=227
(58)
Which of the following may be statically imported? (Choose two.)

A. Package names

B. Static method names

C. Static field names

D. Method-local variable names

**ANSWER: B**C

MIX
CHOICES:
Yes

QN=228
(121)
Which of the following may follow the static keyword? (Choose three.)

A. Class definitions

B. Data

C. Methods

D. Code blocks enclosed in curly brackets
e.
Variables
f.

**ANSWER: B**CD

MIX CHOICES:
Yes

QN=229
(137)
Which of the following may legally appear as the new type (between the
parentheses) in a cast operation? (Choose one.)

A. Classes

B. Interfaces

C. Arrays of classes

D. Arrays of interfaces
e.
All of the others
f.

**ANSWER: E**
MARK:
1

MIX
CHOICES:
No

QN=230
(138)
Which of the following may legally appear as the new type (between the
parentheses) in a cast operation? (Choose one.)

A. Abstract classes

B. Final classes

C. Primitives

D. All of the above

**ANSWER: D**
MARK:
1

MIX
CHOICES:
No

QN=231
(202)
Which of the following may not be synchronized? (Choose one.)

A. Blocks within methods

B. Static methods

C. Blocks within static methods

D. Classes

**ANSWER: D**
MARK:
1

MIX CHOICES:
Yes

QN=232
(186)
Which of the following may override a method whose signature is void
xyz(float f)? (Choose two.)

A. void xyz(float f)

B. public void xyz(float f)

C. private void xyz(float f)

D. public int xyz(float f)
e.
private int xyz(float f)
f.

**ANSWER: A**B
MARK:
1

MIX
CHOICES:
Yes

QN=233
(199)
Which of the following methods in the Thread class are deprecated?
(Choose one.)

A. suspend() and resume()

B. wait() and notify()

C. start() and stop()

D. sleep() and yield()

**ANSWER: A**
MARK:
1

MIX
CHOICES:
Yes

QN=234
(81)
Which of the following operations might throw an ArithmeticException?
(Choose one.)

A.

> > B. > >
> >
> > > C. > > > <<
> > >
> > > D. > > > None of these
> > >
> > > ANSWER: > > > D
> > > MARK:
> > > 0.5

MIX CHOICES:
Yes

QN=235
(82)
Which of the following operations might throw an ArithmeticException?
(Choose one.)

A.

- B.

* C.

- D. /
  e.
  None of the others
  f.

**ANSWER: D**

MIX
CHOICES:
No

QN=236
(145)
Which of the following operators can perform promotion on their
operands? (Choose three.)

A.

- B.

* C. ++

D. \* - e.
~
f.
!
**ANSWER: A**BE
MARK:
1

MIX
CHOICES:
Yes

QN=237
(182)
Which of the following restrictions apply to anonymous inner classes?
(Choose one.)

A. They must be defined inside a code block.

B. They may only read and write final variables of the enclosing class.

C. They may only call final methods of the enclosing class.

D. They may not call the enclosing class’ synchronized methods.

**ANSWER: A**
MARK:
1

MIX CHOICES:
Yes

QN=238
(164)
Which of the following should always be caught? (Choose one.)

A. Runtime exceptions

B. Checked exceptions

C. Assertion errors

D. Errors other than assertion errors

**ANSWER: B**

MIX
CHOICES:
Yes

QN=239
(47)
Which of the following signatures are valid for the main() method entry
point of an application? (Choose two.)

A. public static void main()

B. public static void main(String arg[])

C. public void main(String [] arg)

D. public static void main(String[] args)
e.
public static int main(String [] arg)
f.

**ANSWER: B**D

MIX
CHOICES:
Yes

QN=240
(201)
Which of the following statements about the wait() and notify() methods is
true? (Choose one.)

A. The wait() and notify() methods can be called outside synchronized code.

B. The programmer can specify which thread should be notified in a notify()
method call.

C. The thread that calls wait() goes into the monitor’s pool of waiting threads.

D. The thread that calls notify() gives up the lock.

**ANSWER: C**
MARK:
1

MIX
CHOICES:
Yes

QN=241
(200)
Which of the following statements about threads is true? (Choose one.)

A. Every thread starts executing with a priority of 5.

B. Threads inherit their priority from their parent threa
D.
C. Threads are guaranteed to run with the priority that you set using the
setPriority() metho
D.
D. Thread priority is an integer ranging from 1 to 100.

**ANSWER: B**
MARK:
1

MIX
CHOICES:
Yes

QN=242
(125)
Which of the following statements are true? (Choose one.)

A. A final class must be instantiate
D.
B. A final class may only contain final methods.

C. A final class may not contain non-final data fields.

D. A final class may not be extende
D.
**ANSWER: D**
MARK:
1

MIX
CHOICES:
Yes

QN=243
(176)
Which of the following statements are true? (Choose one.)

A. Given that Inner is a nonstatic class declared inside a public class Outer
and that appropriate constructor forms are defined, an instance of Inner can be constructed like this: new Outer().new Inner()

B. If an anonymous inner class inside the class Outer is defined to implement
the interface ActionListener, it can be constructed like this: new
Outer().new ActionListener()

C. Given that Inner is a nonstatic class declared inside a public class Outer

and that appropriate constructor forms are defined, an instance of Inner can
be constructed in a static method like this: new Inner()

D. An anonymous class instance that implements the interface MyInterface
can be constructed and returned from a method like this:

1. return new MyInterface(int x) {
2. int x;
3. public MyInterface(int x) {
4. this.x = x;
5. }
6. };

**ANSWER: A**
MARK:
1

MIX
CHOICES:
Yes

QN=244
(118)
Which of the following statements are true? (Choose one.)

A. An abstract class may be instantiate
D.
B. An abstract class must contain at least one abstract metho
D.
C. An abstract class must contain at least one abstract data fiel
D.
D. An abstract class must be overridden.
e.
An abstract class must declare that it implements an interface.
f.
None of the above
**ANSWER: F**
MARK:
1

MIX
CHOICES:
No

QN=245
(232)
Which of the following statements are true? (Choose two.)

A. StringBuilder is generally faster than StringBuffer.

B. StringBuffer is generally faster than StringBuilder.

C. StringBuilder is threadsafe; StringBuffer is not.

D. StringBuffer is threadsafe; StringBuilder is not.

**ANSWER: A**D
MARK:
1

MIX
CHOICES:
Yes

QN=246
(108)
Which of the following statements are true?
1)An abstract class may not have any final methods.
2)A final class may not have any abstract methods.

A. Only statement 1

B. Only statement 2

C. Both statement 1 and 2

D.

**ANSWER: B**
MARK:
1

MIX
CHOICES:
No

QN=247
(127)
Which of the following statements is correct? (Choose one.)

A. Only primitives are converted automatically; to change the type of an
object reference, you have to do a cast.

B. Only object references are converted automatically; to change the type of a
primitive, you have to do a cast.

C. Arithmetic promotion of object references requires explicit casting.

D. Both primitives and object references can be both converted and cast.
e.
Casting of numeric types may require a runtime check.
f.

**ANSWER: D**
MARK:
1

MIX
CHOICES:
Yes

QN=248
(110)
Which of the following statements is true? (Choose one.)

A. Transient methods may not be overridden.

B. Transient methods must be overridden.

C. Transient classes may not be serialize
D.
D. Transient variables must be stati
C. e.
Transient variables are not serialize
D.
f.

**ANSWER: E**
MARK:
1

MIX
CHOICES:
Yes

QN=249
(132)
Which of the following statements is true? (Choose one.)

A. Object references can be converted in assignments but not in method calls.

B. Object references can be converted in method calls but not in assignments.

C. Object references can be converted in both method calls and assignments,
but the rules governing these conversions are very different.

D. Object references can be converted in both method calls and assignments,
and the rules governing these conversions are identical.
e.
Object references can never be converte
D. f.

**ANSWER: D**
MARK:
1

MIX
CHOICES:
Yes

QN=250
(233)
Which of the statements below are true? (Choose one.)

A. UTF characters are all 8 bits.

B. UTF characters are all 16 bits.

C. UTF characters are all 24 bits.

D. Unicode characters are all 16 bits.
e.
Bytecode characters are all 16 bits.
f.

**ANSWER: D**
MARK:
1

MIX
CHOICES:
Yes

QN=251
(235)
Which of the statements below are true? (Choose one.)

A. To change the current working directory, call the setWorkingDirectory()
method of the File class.

B. To change the current working directory, call the cd() method of the File

class.

C. To change the current working directory, call the
changeWorkingDirectory() method of the File class.

D. None of the above

**ANSWER: D**
MARK:
1

MIX
CHOICES:
No

QN=252
(234)
Which of the statements below are true? (Choose one.)

A. When you construct an instance of File, if you do not use the file-naming
semantics of the local machine, the constructor will throw an IOException.

B. When you construct an instance of File, if the corresponding file does not
exist on the local file system, one will be create
D.
C. When an instance of File is garbage collected, the corresponding file on the
local file system is delete
D.
D. None of the above.

**ANSWER: D**
MARK:
1

MIX
CHOICES:
No

QN=253
(128)
Which one line in the following code will not compile?

1. byte b = 5;
2. char c = ‘5’;
3. short s = 55;
4. int i = 555;
5. float f = 555.5f;
6. b = s;
7. i = c;
8. if (f > b)
9. f = i;

A. Line 5

B. Line 2

C. Line 3

D. Line 7

e.
Line 9
f.
Line 6
**ANSWER: F**
MARK:
1

MIX
CHOICES:
Yes

QN=254
(193)
Which one statement is always true about the following application?

1. class HiPri extends Thread {
2. HiPri() {
3. setPriority(10);
4. }
5.
6. public void run() {
7. System.out.println(
8. "Another thread starting up.");
9. while (true) { }
10. }
11.
12. public static void main(String args[]) {
13. HiPri hp1 = new HiPri();
14. HiPri hp2 = new HiPri();
15. HiPri hp3 = new HiPri();
16. hp1.start();
17. hp2.start();
18. hp3.start();
19. }
20. }

A. When the application is run, thread hp1 will execute; threads hp2 and hp3
will never get the CPU.

B. When the application is run, thread hp1 will execute to completion, thread
hp2 will execute to completion, then thread hp3 will execute to completion.

C. When the application is run, all three threads (hp1, hp2, and hp3) will
execute concurrently, taking time-sliced turns in the CPU.

D. None of the above scenarios can be guaranteed to happen in all cases.

**ANSWER: D**
MARK:
1

MIX
CHOICES:
No

QN=255
(215)
Which one statement is true about the following code fragment? (choose 1)

1. import java.lang.Math;
2. Math myMath = new Math();
3. System.out.println("cosine of 0.123 = " + myMath.cos(0.123));

A. Compilation fails at line 2.

B. Compilation fails at line 3

C. Compilation succeeds, although the import on line 1 is not necessary.
During execution, an exception is thrown at line 3

D. Compilation succeeds. The import on line 1 is necessary. During
execution, an exception is thrown at line 3
e.
Compilation succeeds and no exception is thrown during execution.
f.

**ANSWER: A**
MARK:
1

MIX
CHOICES:
Yes

QN=256
(216)
Which one statement is true about the following code fragment?

1. String s = "FPT";
2. StringBuffer s1 = new StringBuffer("FPT");
3. if (s.equals(s1))
4. s1 = null;
5. if (s1.equals(s))
6. s = null;

A. Compilation fails at line 1 because the String constructor must be called
explicitly.

B. Compilation fails at line 3 because s and s1 have different types.

C. Compilation succeeds. During execution, an exception is thrown at line 3.

D. Compilation succeeds. During execution, an exception is thrown at line 5.
e.
Compilation succeeds. No exception is thrown during execution.
f.

**ANSWER: E**
MARK:
1

MIX
CHOICES:
Yes

QN=257 (213)
Which one statement is true about the following code?

1. String s1 = "abc" + "def";

2. String s2 = new String(s1);
3. if (s1 == s2)
4. System.out.println("== succeeded");
5. if (s1.equals(s2))
6. System.out.println(".equals() succeeded");

A. Lines 4 and 6 both execute.

B. Line 4 executes and line 6 does not.

C. Line 6 executes and line 4 does not.

D. Neither line 4 nor line 6 executes.

**ANSWER: C**
MARK:
1

MIX
CHOICES:
Yes

QN=258
(192)
Which one statement is true concerning the following code?

1. class Greebo extends java.util.Vector implements Runnable {
2.
3. public void run(String message) {
4. System.out.println("in run() method: " + message);
5.
6. }
7. }
8.
9. class GreeboTest {
10. public static void main(String args[]) {
11. Greebo g = new Greebo();
12. Thread t = new Thread(g);
13. t.start();
14. }
15. }

A. There will be a compiler error, because class Greebo does not correctly
implement the Runnable interface.

B. There will be a compiler error at line 13, because you cannot pass a
parameter to the constructor of a Threa
D.
C. The code will compile correctly but will crash with an exception at line 13.

D. The code will compile correctly but will crash with an exception at line 14.
e.
The code will compile correctly and will execute without throwing any
exceptions.
f.

**ANSWER: A**
MARK:
2

MIX
CHOICES:
Yes

QN=259
(151)
Which statement is true about the following code fragment? (Choose one.)

1. int j = 2;
2. switch (j) {
3. case 2:
4. System.out.println("value is two");
5. case 2 + 1:
6. System.out.println("value is three");
7. break;
8. default:
9. System.out.println("value is " + j);
10. break;
11. }

A. The code is illegal because of the expression at line 5.

B. The acceptable types for the variable j, as the argument to the switch()
construct, could be any of byte, short, int, or long.

C. The output would be the text value is two.

D. The output would be the text value is two followed by the text value is
three.
e.
The output would be the text value is two, followed by the text value is
three, followed by the text value is 2.
f.

**ANSWER: D**
MARK:
1

MIX
CHOICES:
Yes

QN=260
(80)
Which statement is true about the following method?
int selfXor(int i) {
return i ^ i;
}

A. It always returns 0.

B. It always returns 1.

C. It always an int where every bit is 1.

D. The returned value varies depending on the argument.

**ANSWER: A**
MARK:
1

MIX
CHOICES:
Yes

QN=261
(111)
Which statement is true about this application? (Choose one.)

1. class StaticStuff
   2 {
2. static int x = 10;
3.
4. static { x += 5; }
5.
6. public static void main(String args[])
7. {
8. System.out.println("x = " + x);
9. }
10.
11. static {x /= 5; }
12. }

A. Lines 5 and 12 will not compile because the method names and return
types are missing.

B. Line 12 will not compile because you can only have one static initializer.

C. The code compiles and execution produces the output x = 10.

D. The code compiles and execution produces the output x = 15.
e.
The code compiles and execution produces the output x = 3.
f.

**ANSWER: E**
MARK:
1

MIX
CHOICES:
Yes

QN=262 (112)
Which statement is true about this code? (Choose one.)

1. class HasStatic
2. {
3. private static int x = 100;
4.
5. public static void main(String args[])
6. {
7. HasStatic hs1 = new HasStatic();
8. hs1.x++;
9. HasStatic hs2 = new HasStatic();
10. hs2.x++;
11. hs1 = new HasStatic();
12. hs1.x++;

13. HasStatic.x++;
14. System.out.println("x = " + x);
15. }
16. }

A. Line 8 will not compile because it is a static reference to a

variable.

B. Line 13 will not compile because it is a static reference to a private
variable.

C. The program compiles and the output is x = 102.

D. The program compiles and the output is x = 103.
e.
The program compiles and the output is x = 104.
f.

**ANSWER: E**
MARK:
1

MIX
CHOICES:
Yes

QN=263
(4929)
Which statements about JDBC are NOT true? (choose 2)

A. JDBC is a Java API for executing SQL statements.

B. JDBC provides a standard API for tool/database developers and makes it
possible to write database applications using a pure Java API.

C. It consists of a set of classes and interfaces written in the Java
programming language.

D. The combination of Java and JDBC lets a programmer write it once and
run it anywhere.
e.
JDBC is a Java database system.
f.
JDBC is a Java API for connecting to any kind of DBMS
**ANSWER: E**F
MARK:
1

MIX
CHOICES:
Yes

QN=264
(1423)
Which two code fragments correctly create and initialize a static array of
int elements? (Choose two.)

A. static final int[] a = { 100,200 };

B. static final int[] a; static { a=new int[2]; a[0]=100; a[1]=200; }

C. static final int[] a = new int[2] { 100,200 };

D. static final int[] a; static void init() {a=new int[3];a[0]=100; a[1]=200;}

**ANSWER: A**B
MARK:
1

MIX
CHOICES:
Yes

QN=265
(1873)
Which two of the following interfaces are at the top of the hierarchies in
the Java Collections Framework? (Choose two.)

A. Set

B. Map

C. Queue

D. SortedMap
e.
Collection
f.
List
**ANSWER: B**E
MARK:
1

MIX
CHOICES:
Yes

QN=266
(241)
You execute the following code in an empty directory. What is the result?
(Choose one.)

1. File f1 = new File("dirname");
2. File f2 = new File(f1, "filename");

A. A new directory called dirname is created in the current working directory.

B. A new directory called dirname is created in the current working directory.
A new file called filename is created in directory dirname.

C. A new directory called dirname and a new file called filename are created,
both in the current working directory.

D. A new file called filename is created in the current working directory.
e.
No directory is created, and no file is create
D. f.

**ANSWER: E**
MARK:
1

MIX
CHOICES:
Yes

QN=267 (171)
You have been given a design document for a veterinary registration system for implementation in Java. It states:

"A pet has an owner, a registration date, and a vaccination-due date. A cat
is a pet that has a flag indicating if it has been neutered, and a textual description of its markings."
Given that the Pet class has already been defined and you expect the Cat class to be used freely throughout the application, how would you make the opening declaration of the Cat class, up
to but not including the first opening brace? Use only these words and spaces: boolean, Cat, class, Date, extends, Object, Owner, Pet, private, protected, public, String.
(Choose one.)

A. protected class Cat extends Owner

B. public class Cat extends Object

C. public class Cat extends Pet

D. private class Cat extends Pet

**ANSWER: C**
MARK:
2

MIX
CHOICES:
Yes

QN=268
(170)
You have been given a design document for a veterinary registration
system for implementation in Java. It states:
"A pet has an owner, a registration date, and a vaccination-due date. A cat
is a pet that has a flag indicating whether it has been neutered, and a textual description of its markings."
Given that the Pet class has already been defined, which of the following fields would be appropriate for inclusion in the Cat class as members? (Choose two.)

A. Pet thePet;

B. Date registered;

C. Date vaccinationDue;

D. Cat theCat;
e.
boolean neutered;
f.
String markings;
**ANSWER: E**F
MARK:
2

MIX
CHOICES:
Yes

```

```
