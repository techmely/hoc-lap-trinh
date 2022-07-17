## Question blank

QN=1
(300)
is a set of java API for executing SQL statements.
a. ODBC
b. JDBC
c. JAVADB
d. None of the others

Answer: B
MARK:
0.5

MIX
CHOICES:
No

QN=2
(311)
method is used to wait for a client to initiate communications.
a. wait()
b. accept()
c. listen()
d.

Answer: B
MARK:
0.5

MIX
CHOICES:
Yes

QN=3
(7259)
drivers that are written partly in the Java programming
language and partly in native code. These drivers use a native client library specific to the data source to which they connect. Again, because of the native code, their portability is limited. a. Type 2
b. Type 3

c. Type 1
d. Type 4

Answer: A
MARK:
0.5

MIX
CHOICES:
Yes

QN=4
(7261)
drivers that are pure Java and implement the network
protocol for a specific data source. The client connects directly to the data source.
a. Type 4
b. Type 3
c. Type 2
d. Type 1

Answer: A
MARK:
0.5

MIX
CHOICES:
Yes

QN=5
(7260)
drivers that use a pure Java client and communicate with a
middleware server using a database-independent protocol. The middleware server then communicates the client's requests to the data source.
a. Type 3
b. Type 2
c. Type 1
d. Type 4

Answer: A
MARK:
0.5

MIX
CHOICES:
Yes

QN=6 (7258)
drivers that implement the JDBC API as a mapping to another data access API, such as ODBC. Drivers of this type are generally

dependent on a native library, which limits their portability.
a. Type 1
b. Type 2
c. Type 3
d. Type 4

Answer: A
MARK:
0.5

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
a. Line 26 prints “a” to System.out.
b. Line 26 prints “b” to System.out.
c. An exception is thrown at line 26 at runtime.
d. Compilation of class A will fail due to an error in line 6.

Answer: A
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
a. The application will crash.
b. The code on line 29 will be executed. c. The code on line 5 of class A will execute.
d. The code on line 5 of class B will execute.
e.
The exception will be propagated back to line 27.
f.

Answer: BE
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
a. Success
b. Bad URL
c. Bad file contents
d. General exception
e.
Doing finally part
f.
Carrying on
Answer: BEF
MARK:
2

MIX
CHOICES:
Yes

QN=10 (153)

```java
try {
// assume s is previously defined
URL u = new URL(s);
// in is an ObjectInputStream
Object o = in.readObject();
System.out.println("Success");
}
catch (MalformedURLException e) {
System.out.println("Bad URL");
}

 catch (StreamCorruptedException e) {
 System.out.println("Bad file contents");
 }
 catch (Exception e) {
 System.out.println("General exception");
 }
 finally {
 System.out.println("Doing finally part");
 }
 System.out.println("Carrying on");
```

What lines are output if the methods at lines 3 and 5 complete successfully without throwing any exceptions? (Choose three.)
a. Success
b. Bad URL
c. Bad file contents
d. General exception
e.
Doing finally part
f.
Carrying on
Answer: AEF
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

    public int fubar( Foo foo) { return foo.bar(); }
    public void testFoo() {

      class A implements Foo {
        public int bar() { return 2; }
      }
      System.out.println( fubar( new A()));
    }


  public static void main( String[] argv) {
    new Beta().testFoo();
 }
}
```

Which three statements are true? (Choose three.)
a. Compilation fails.
b. The code compiles and the output is 2.
c. If lines 16, 17 and 18 were removed, compilation would fail.
d. If lines 24, 25 and 26 were removed, compilation would fail.
e.
If lines 16, 17 and 18 were removed, the code would compile and the
output would be 2.
f.
If lines 24, 25 and 26 were removed, the code would compile and the
output would be 1.
Answer: BEF
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
a. Compilation fails.
b. ClassC is displayed. c. The code runs with no output.
d. An exception is thrown at runtime.

Answer: D
MARK:
2

MIX
CHOICES:
Yes

QN=13 11.
public class Bootchy {
(1515) 12.

```java
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
a. snootchy 420 third second first
b. snootchy 420 first second third
c. first second third snootchy 420
d. third second first snootchy 420
e.
third first second snootchy 420
f.
first second first third snootchy 420
Answer: D
MARK:
1

MIX
CHOICES:
Yes

QN=14
(306)
A dialog prevents user input to other windows in the application
unitl the dialog is closed. a. Modal
b. Non-Modal
c. Unmodel
d. None of the above

Answer: A
MARK:
0.5

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
a. Construct a FileInputStream, passing the name of the file. Onto the
FileInputStream, chain a DataInputStream, and call its readInt() method. b. Construct a FileReader, passing the name of the file. Call the file reader’s
readInt() method. c. Construct a RandomAccessFile, passing the name of the file. Call the
random access file’s readInt() method.
d. Construct a FileReader, passing the name of the file. Onto the FileReader,
chain a DataInputStream, and call its readInt() method.

Answer: AC
MARK:
1

MIX
CHOICES:
Yes

QN=16
(198)
A Java monitor must either extend Thread or implement Runnable.
a. True
b. False
c.
d.

Answer: B
MARK:
0.5

MIX
CHOICES:
Yes

QN=17
(196)
A monitor called mon has 10 threads in its waiting pool; all these waiting
threads have the same priority. One of the threads is thr1. How can you notify thr1 so that it alone moves from the Waiting state to the Ready state? (Choose one.)
a. Execute notify(thr1); from within synchronized code of mon.
b. Execute mon.notify(thr1); from synchronized code of any object.
c. Execute thr1.notify(); from synchronized code of any object.
d. Execute thr1.notify(); from any code (synchronized or not) of any object.
e.
You cannot specify which thread will get notified. f.

Answer: E
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
a. public void logIt(String \* msgs)
b. public void logIt(String [] msgs)
c. public void logIt(String... msgs)
d. public void logIt(String msg1, String msg2, String msg3)

Answer: C
MARK:
1

MIX
CHOICES:
Yes

QN=19
(45)
A signed data type has an equal number of non-zero positive and negative
values available.
a. True
b. False
c.
d.

Answer: B
MARK:
0.5

MIX
CHOICES:
Yes

QN=20
(194)
A thread wants to make a second thread ineligible for execution. To do
this, the first thread can call the yield() method on the second thread. a. True
b. False
c.
d.

Answer: B
MARK:
0.5

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
a. The code will not compile, because exceptions cannot be caught in a
thread’s run() method. b. At line 2, the thread will stop running. Execution will resume in, at most,
100 milliseconds.
c. At line 2, the thread will stop running. It will resume running in exactly
100 milliseconds.
d. At line 2, the thread will stop running. It will resume running some time
after 100 milliseconds have elapsed.

Answer: D
MARK:
1

MIX
CHOICES:
Yes

QN=22
(7264)
A(n) object is used to submit a query to a database
a. Command
b. Connection
c. Statement
d. DriverManager

Answer: C
MARK:
1

MIX
CHOICES:
Yes

QN=23
(7263)
A(n) object is uses to obtain a Connection to a Database
a. ConnectionManager
b. DatabaseManager
c. DriverManager
d. JDBCManager

Answer: C
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
   a. x = 15, a = 7, b = 8
   b. x = 15, a = 6, b = 7
   c. x = 13, a = 7, b = 8
   d. x = 13, a = 6, b = 7

Answer: C
MARK:
0.5

MIX
CHOICES:
Yes

QN=25 (1410)
Assume that country is set for each class. Given:

```java
public class Money {
private String country, name;
public String getCountry() { return country; }
}
```

and:

```java
class Yen extends Money {
public String getCountry() { return super.country; }
}
class Euro extends Money {
public String getCountry(String timeZone) {
return super.getCountry();

}
}
```

Which two are correct? (Choose two.)
a. Yen returns correct Country value.
b. Euro returns correct Country value.
c. An exception is thrown at runtime.
d. Yen and Euro both return correct Country value.
e.
Compilation fails because of an error at line 25.
f.
Compilation fails because of an error at line 30.
Answer: BE
MARK:
2

MIX
CHOICES:
Yes

QN=26
(46)
Choose the valid identifiers from those listed here. (Choose all that apply.)
a. BigOlLongStringWithMeaninglessName
b. $int
c. bytes
d. $1
e.
finalist
f.

Answer: ABCDE
MARK:
0.5

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
a. Compilation of both classes will fail.
b. Compilation of both classes will succeed. c. Compilation of class A will fail. Compilation of class B will succeed. d. Compilation of class B will fail. Compilation of class A will succeed.

Answer: D
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
a. Class A will not compile.
b. Line 46 can throw the unchecked exception TestException.
c. Line 45 can throw the unchecked exception TestException.
d. Line 46 will compile if the enclosing method throws a TestException.
e.
Line 46 will compile if enclosed in a try block, where TestException is
caught.
f.

Answer: DE
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
    a. 0
    b. 1
    c. 100
    d. 101

Answer: D
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
    a. 0.0
    b. 1.0
    c. 12.3
    d. 11.3

Answer: C
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
   a. Test t = new Test();
   b. Test t = new Test(1);
   c. Test t = new Test(1, 2);
   d. Test t = new Test(1, 2, 3);
   e.
   Test t = (new Base()).new Test(1);
   f.

Answer: BC
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
   a. Base() { }
   b. Base(int j) { }
   c. Base(int j, int k) { }
   d. Base(int j, int k, int l) { }

Answer: AC
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
    a. Line 5 will not compile, because void methods cannot be overridden.
    b. Line 12 will not compile, because no version of crunch() takes a char
    argument.
    c. The code will compile but will throw an exception at line 12.
    d. The code will compile and produce the following output: int version.
    e.
    The code will compile and produce the following output: String version.
    f.

Answer: D
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
a. Value is 5Value is 6
b. This value is 5This value is 6
c. Value is 5This value is 6
d. This value is 5Value is 6
e.
I was passed 5I was passed 6
f.

Answer: C
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
   a. Line 4
   b. Line 5
   c. Line 6
   d. Line 7

Answer: C
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
a. The source code must be compiled with the -source 1.5 flag.
b. The application must be run with the -enableassertions flag or another
assertionenabling flag.
c. The args array must have exactly zero elements.
d. The args array must have one or more elements.

Answer: BD
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
a. After line 2 executes, the StringBuffer object is garbage collected. b. After line 3 executes, the StringBuffer object is garbage collected. c. After line 2 executes, the StringBuffer object is eligible for garbage
collection.
d. After line 3 executes, the StringBuffer object is eligible for garbage
collection.

Answer: C
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
   a. Line 6 will not compile; an explicit cast is required to convert a Cat to a
   Washer.
   b. Line 7 will not compile, because you cannot cast an interface to a class.
   c. The code will compile and run, but the cast in line 7 is not required and can
   be eliminated. d. The code will compile but will throw an exception at line 7, because
   runtime conversion from an interface to a class is not permitted. e.
   The code will compile but will throw an exception at line 7, because the
   runtime class of wawa cannot be converted to type SwampThing.
   f.

Answer: E
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
a. Line 5 will not compile.
b. Line 6 will not compile.
c. The code will compile but will throw an exception at line 6.
d. The code will compile and run.
e.
The code will compile and run, but the cast in line 6 is not required and can
be eliminated. f.

Answer: D
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
   a. i = 0 j = 0
   b. i = 0 j = 1
   c. i = 0 j = 2
   d. i = 1 j = 0
   e.
   i = 1 j = 1
   f.
   i = 1 j = 2

Answer: BCDF
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
a. i = 0 j = 0
b. i = 0 j = 1
c. i = 0 j = 2
d. i = 1 j = 0
e.
i = 1 j = 1
f.
i = 1 j = 2
Answer: D
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
a. Line 6 will not compile; an explicit cast is required to convert a Raccoon to

a Washer.
b. Line 7 will not compile; an explicit cast is required to convert a Washer to
a SwampThing.
c. The code will compile and run.
d. The code will compile but will throw an exception at line 7, because
runtime conversion from an interface to a class is not permitted. e.
The code will compile but will throw an exception at line 7, because the
runtime class of w cannot be converted to type SwampThing.
f.

Answer: B
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
a. a
b. b
c. c
d. d
e.
e
f.
f
Answer: ABCE
MARK:
1

MIX
CHOICES:
Yes

QN=44 Consider the following line of code:

(49)

int[] x = new int[25];

After execution, which statements are true? (Choose two.)
a. x[24] is 0
b. x[24] is undefined
c. x[25] is 0
d. x[0] is null
e.
x.length is 25
f.

Answer: AE
MARK:
0.5

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
a. float aMethod(float a, float b) {...}
b. public int aMethod(int a, int b) throws Exception {...}
c. public float aMethod(float a, float b) throws Exception {...}
d. public float aMethod(float p, float q) {...}

Answer: BD
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
a. public int aMethod(int a, int b) { }
b. public float aMethod(float a, float b) { }
c. public float aMethod(float a, float b, int c) throws Exception { }
d. public float aMethod(float c, float d) { }
e.
private float aMethod(int a, int b, int c) { }
f.

Answer: ACE
MARK:
1

MIX
CHOICES:
Yes

QN=47
(1517)
Give:

```java
 public static Iterator reverse(List list) {
 Collections.reverse(list);
 return list.iterator();
 }
 public static void main(String[] args) {
 List list = new ArrayList();
 list.add(” 1”); list.add(”2”); list.add(”3”);
 for (Object obj: reverse(list))
 System.out.print(obj + “,”);
 }
```

‘What is the result? (Choose one.)
a. 3, 2, 1,
b. 1, 2, 3,
c. Compilation fails.
d. The code runs with no output.
e.
An exception is thrown at runtime.
f.

Answer: C
MARK:
1

MIX
CHOICES:
Yes

QN=48
(212)
Given a string constructed by calling s = new String("xyzzy"), which of the
calls modifies the string? (Choose one.)
a. s.append("aaa");
b. s.trim();
c. s.substring(3);
d. s.replace(‘z’, ‘a’);
e.
s.concat(s);
f.
None of the above
Answer: F
MARK:
1

MIX
CHOICES:
No

QN=49
(231)
Given arrays a1 and a2, which call returns true if a1 and a2 have the same
length, and a1[i].equals(a2[i]) for every legal index i? (Choose one.)
a. java.util.Arrays.equals(a1, a2);
b. java.util.Arrays.compare(a1, a2);
c. java.util.List.compare(a1, a2);
d.

Answer: A
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
a. iAmPublic
b. iAmPrivate
c. iAmStatic
d. iAmTransient

e.
iAmVolatile
f.

Answer: ABE
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
   a. line 3: public; line 8: private
   b. line 3: protected; line 8: private
   c. line 3: default; line 8: private
   d. line 3: private; line 8: protected
   e.
   line 3: public; line 8: protected
   f.

Answer: D
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
a. Spice sp = Spice.NUTMEG; Object ob = sp;
b. Spice sp = Spice.NUTMEG; Object ob = (Object)sp;
c. Object ob = new Object(); Spice sp = ob
d. Object ob = new Object(); Spice sp = (Spice)ob;
e.
String ob = new String(); Spice sp = ob;
f.

Answer: ABD
MARK:
1

MIX
CHOICES:
Yes

QN=53
(224)
Given the following:

`List<String> names = new ArrayList<String>();`

which of the following are legal? (Choose two.)
a. Iterator<String> iter = names.iterator();
b. for (String s:names)
c. while (String s:names)
d.

Answer: AB
MARK:
0.5

MIX
CHOICES:
Yes

QN=54
(1524)
Given:

```java
 static class A {
 void process() throws Exception { throw new Exception(); }
 }
 static class B extends A {
 void process() { System.out.println(”B “); }
 }
public static void main(String[] args) {
 A a=new B();
 a.process();
 }
```

What is the result? (Choose one.)
a. B
b. The code runs with no output.
c. An exception is thrown at runtime.
d. Compilation fails because of an error in line 15.
e.
Compilation fails because of an error in line 18.
f.
Compilation fails because of an error in line 19.
Answer: F

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
a. 2
b. 3
c. 1 2
d. 2 3
e.
1 2 3
f.
Compilation fails.
Answer: D
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
a. public interface B extends A { }
b. public interface B implements A {}

c. public interface B instanceOf A {}
d. public interface B inheritsFrom A { }

Answer: A
MARK:
0.5

MIX
CHOICES:
Yes

QN=57
(1420)
Given:

```java
 abstract public class Employee {
 protected abstract double getSalesAmount();
 public double getCommision() {
 return getSalesAmount() \* 0.15;
 }
 }
 class Sales extends Employee {
 // insert method here
 }
```

Which two methods, inserted independently at line 17, correctly complete the Sales class? (Choose two.)
a. double getSalesAmount() { return 1230.45; }
b. public double getSalesAmount() { return 1230.45; }
c. private double getSalesAmount() { return 1230.45; }
d. protected double getSalesAmount() { return 1230.45; }

Answer: BD
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
a. Line 16 is never executed. b. An exception is thrown at runtime.
c. Line 13 creates a File object named “d.”
d. Line 14 creates a File object named “f.’
e.
Line 13 creates a directory named “d” in the file system.
f.
Line 16 creates a directory named “d” and a file ‘f’ within it in the file
system.
Answer: BCD
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
a. Direction d = NORTH;
b. Nav.Direction d = NORTH;
c. Direction d = Direction.NORTH;
d. Nav.Direction d = Nav.Direction.NORTH;

Answer: D
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
a. Foo { public int bar() { return 1; } }
b. new Foo { public int bar() { return 1; } }
c. new Foo() { public int bar(){return 1; } }
d. new class Foo { public int bar() { return 1; } }

Answer: C
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
a. StackOverflowError
b. NullPointerException

c. NumberFormatException
d. IllegalArgumentException
e.
ExceptionlnlnitializerError
f.

Answer: A
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
    a. Shape s = new Shape(); s.setAnchor(10,10); s.draw();
    b. Circle c = new Shape(); c.setAnchor(10,10); c.draw();
    c. Shape s = new Circle(); s.setAnchor(10,10); s.draw();
    d. Shape s = new Circle(); s->setAnchor(10,10); s->draw();
    e.
    Circle c = new Circle(); c.Shape.setAnchor(10,10); c.Shape.draw();
    f.

Answer: C
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
a. 1 2 3
b. Compilation fails because of an error in line 12.
c. Compilation fails because of an error in line 13.
d. Compilation fails because of an error in line 14.
e.
A ClassCastException is thrown at runtime.
f.

Answer: A
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
a. Test
b. Exception
c. Compilation fails.
d. NullPointerException

Answer: C
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
a. 0.0
b. Compilation fails.
c. A ParseException is thrown by the parse method at runtime.
d. A NumberFormatException is thrown by the parse method at runtime.

Answer: B
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
a. 0
b. 1
c. 4
d. Compilation fails.
e.
An exception is thrown at runtime.
f.

Answer: D
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
a. Passed
Stuff
b. Stuff
Passed
c. passed
An AssertionError is thrown with the word “stuff” added to the stack trace.
d. passed
An AssertionError is thrown without the word “stuff” added to the stack trace.
e.
passed
An AssertionException is thrown with the word “stuff” added to the stack trace.
f.
passed
An AssertionException is thrown without the word “stuff” added to the stack trace.
Answer: C
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
a. collie
b. harrier
c. Compilation fails.
d. collie harrier
e.
An exception is thrown at runtime.
f.

Answer: D
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
a. Compilation fails.
b. An exception is thrown at runtime.
c. doStuff x = 6 main x = 6
d. doStuff x = 5 main x = 5
e.
doStuff x = 5 main x = 6
f.
doStuff x = 6 main x = 5
Answer: D
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
a. Compilation fails.
b. An exception is thrown at runtime.
c. doStuffx = 6 main x = 6
d. doStuffx = 5 main x = 5
e.
doStuffx = 5 main x = 6
f.
doStuffx = 6 main x = 5
Answer: D
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
a. The class is fully encapsulated. b. The code demonstrates polymorphism.
c. The ownerName variable breaks encapsulation.
d. The cardlD and limit variables break polymorphism.
e.
The setCardlnformation method breaks encapsulation.
f.

Answer: C
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
a. Compilation fails due to an error in line 23.
b. Compilation fails due to an error in line 29.
c. A ClassCastException occurs in line 29.
d. A ClassCastException occurs in line 31.
e.
The value of all four objects prints in natural order.
f.

Answer: B
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
a. The instance gets garbage collected. b. The code on line 33 throws an exception.
c. The code on line 35 throws an exception.
d. The code on line 31 throws an exception.
e.
The code on line 33 executes successfully.
f.

Answer: BCE
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
a. c
b. a
c. ab
d. ac
e.
bc
f.
abc
Answer: D

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
a. Line 57 will print the value 2.
b. Line 57 will print the value 3.
c. Compilation will fail because of an error in line 55.
d. Compilation will fail because of an error in line 56.

Answer: B
MARK:
0.5

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
a. java test
b. java -ea test
c. java test file1
d. java -ea test file1
e.
java -ea test file1 file2
f.
java -ea:test test file1
Answer: BE
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
a. String s = “123456789”; s = (s-”123”).replace(1,3,”24”) - “89”;
b. StringBuffer s = new StringBuffer(”123456789”);
s.delete(0,3).replace( 1,3, “24”).delete(4,6);
c. StringBuffer s = new StringBuffer(”123456789”);
s.substring(3,6).delete( 1 ,3).insert( 1, “24”);
d. StringBuilder s = new StringBuilder(”123456789”);
s.substring(3,6).delete( 1 ,2).insert( 1, “24”);
e.
StringBuilder s = new StringBuilder(”123456789”);
s.delete(0,3).delete( 1 ,3).delete(2,5).insert( 1, “24”);
f.

Answer: BE
MARK:
1

MIX
CHOICES:
Yes

QN=78
(1514)
Given: 10. class Line { 11. public static class Point { } 12. } 13. 14. class Triangle { 15. // insert code here 16. }

Which code, inserted at line 15, creates an instance of the Point class defined in Line? (Choose one.)
a. Point p = new Point();
b. Line.Point p = new Line.Point();
c. The Point class cannot be instatiated at line 15.
d. Line l = new Line() ; Point p = new l.Point();

Answer: B
MARK:
1

MIX
CHOICES:
Yes

QN=79
(1406)
Given: 10. public class Bar { 11. static void foo(int...x) { 12. // insert code here 13. } 14. }

Which two code fragments, inserted independently at line 12, will allow the class to compile? (Choose two.)
a. foreach(x) System.out.println(z);
b. for(int z : x) System.out.println(z);
c. while( x.hasNext()) System.out.println( x.next());
d. for( int i=0; i< x.length; i++ ) System.out.println(x[i]);

Answer: BD
MARK:
1

MIX
CHOICES:
Yes

QN=80
(1405)
Given: 11. public interface Status { 12. /_ insert code here _/ int MY_VALUE = 10; 13. }

Which three are valid on line 12? (Choose three.)
a. final
b. static
c. native
d. public
e.
protected
f.
abstract
Answer: ABD
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
a. Exception
b. A Exception
c. A Exception B
d. A B Exception
e.
Compilation fails because of an error in line: public void process() throws
RuntimeException
f.
Compilation fails because of an error in line: try { ((A)new
B()).process(); }
Answer: B
MARK:
2

MIX
CHOICES:
Yes

QN=82
(209)
How can you ensure that multithreaded code does not deadlock? (Choose
one.)
a. Synchronize access to all shared variables.
b. Make sure all threads yield from time to time.
c. Vary the priorities of your threads.
d. There is no single technique that can guarantee non-deadlocking code.

Answer: D
MARK:
1

MIX
CHOICES:
Yes

QN=83
(52)
How can you force garbage collection of an object? (Choose one.)
a. Garbage collection cannot be forced. b. Call System.gc().
c. Call System.gc(), passing in a reference to the object to be garbage-
collected. d. Call Runtime.gc().
e.
Set all references to the object to new values (null, for example).
f.

Answer: A
MARK:
1

MIX
CHOICES:
Yes

QN=84
(208)
How do you prevent shared data from being corrupted in a multithreaded
environment? (Choose one.)
a. Mark all variables as synchronized. b. Mark all variables as volatile.
c. Use only static variables.
d. Access the variables only via synchronized methods.

Answer: D
MARK:
1

MIX
CHOICES:
Yes

QN=85
(236)
How do you use the File class to list the contents of a directory? (Choose
one.)
a. String[] contents = myFile.list();
b. File[] contents = myFile.list();
c. StringBuilder[] contents = myFile.list();
d. The File class does not provide a way to list the contents of a directory.

Answer: A

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
   a. 2
   b. 8
   c. 12
   d. 16
   e.
   The number of bytes depends on the underlying system.
   f.

Answer: B
MARK:
1

MIX
CHOICES:
Yes

QN=87
(204)
How many locks does an object have? (Choose one.)
a. One
b. One for each method
c. One for each synchronized method
d. One for each non-static synchronized method

Answer: A
MARK:
0.5

MIX
CHOICES:
Yes

QN=88
(48)
If all three top-level elements occur in a source file, they must appear in
which order? (Choose one.)
a. Imports, package declarations, classes/interfaces/enums
b. Classes/interfaces/enums, imports, package declarations
c. Package declaration must come first; order for imports and
class/interfaces/enum definitions is not significant
d. Package declaration, imports, class/interface/enum definitions.
e.
Imports must come first; order for package declarations and
class/interface/enum definitions is not significant
f.

Answer: D
MARK:
0.5

MIX
CHOICES:
Yes

QN=89
(123)
If class Y extends class X, the two classes are in different packages, and
class X has a protected method called abby(), then any instance of Y may call the abby() method of any
other instance of Y.
a. True
b. False
c.
d.

Answer: B
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
    a. Yes
    b. No
    c.
    d.

Answer: A
MARK:
1

MIX
CHOICES:
Yes

QN=91
(1877)
If you need a Set implementation that provides value-ordered iteration,
which class should you use? (Choose one.)
a. HashSet
b. LinkedHashSet
c. TreeSet
d.

Answer: C
MARK:
0.5

MIX
CHOICES:
Yes

QN=92
(1875)
In order for objects in a List to be sorted, those objects must implement
which interface and method? (Choose one.)
a. Comparable interface and its compareTo method. b. Comparable interface and its compare method
c. Compare interface and its compareTo method
d. Comparable interface and its equals method

Answer: A
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
   a. True
   b. False
   c.
   d.

Answer: A
MARK:
0.5

MIX
CHOICES:
Yes

QN=94
(217)
In the following code fragment, after execution of line 1, sbuf references
an instance of the StringBuffer class. After execution of line 2, sbuf still references the same instance.

1. StringBuffer sbuf = new StringBuffer("FPT");
2. sbuf.insert(3, "-University");
   a. True
   b. False
   c.
   d.

Answer: A
MARK:
0.5

MIX
CHOICES:
Yes

QN=95 (130)
In the following code, what are the possible types for variable result? (Choose the most complete true answer.)

1. byte b = 11;
2. short s = 13;
3. result = b \* ++s;
   a. byte, short, int, long, float, double
   b. boolean, byte, short, char, int, long, float, double
   c. byte, short, char, int, long, float, double
   d. byte, short, char
   e.
   int, long, float, double
   f.

Answer: E
MARK:
1

MIX
CHOICES:
Yes

QN=96
(7266)
Interface helps manage the connection between a Java program and a
database.
a. ResultSet
b. DriverManager
c. Statement
d. Connection

Answer: D
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
a. Yes
b. No
c.
d.

Answer: A
MARK:
0.5

MIX
CHOICES:
Yes

QN=98
(205)
Is it possible to write code that can execute only if the current thread owns
multiple locks?
a. Yes
b. No
c.
d.

Answer: A
MARK:
0.5

MIX
CHOICES:
Yes

QN=99
(301)
JDBC supports and models.
a. Single-tier and two-tier
b. Two-tier and three-tier
c. Three-tier and four-tier
d. None of the others

Answer: B
MARK:
1

MIX
CHOICES:
No

QN=100
(305)
MVC is short call of
a. Model-View-Controller
b. Multiple-View-Controller
c. Metal-View-Controller
d.

Answer: A
MARK:
0.5

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
a. b=6
b. No output because of compile error at line: b = b \* b1;
c. No output because of compile error at line: System.out.println("b="+b);
d. No output because of compile error at line: byte b = 2;
e.
No output because of compile error at line: byte b = 3;
f.

Answer: B
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
a. ob1 equals ob2
Have a nice day!
b. ob1==ob2
Have a nice day!
c. Have a nice day!
d. No output

Answer: C
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
a. ob1 equals ob2
ob1==ob2
Have a nice day!
b. ob1 equals ob2
Have a nice day!
c. ob1==ob2
Have a nice day!
d. None of the above

Answer: A
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
a. Line 4
Line 6
b. Line 4
c. Line 6
d. No output, compile error
e.
No output
f.

Answer: A
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
a. Line 4
Line 6
b. Line 4
c. Line 6
d. No output, compile error
e.
No output
f.

Answer: C
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
a. Line 4
b. Line 6
c. Line 4
Line 6
d. No output, compile error
e.
No output
f.

Answer: B
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
a. Line 4
b. Line 6
c. Line 4
Line 6
d. No output, compile error
e.
No output
f.

Answer: C

MARK:
1

MIX
CHOICES:
Yes

QN=108
(4941)
Select correct statement about RMI. (choose 1)
a. allow programmers to develop distributed Java programs with the same
syntax and semantics used for non-distributed programs.
b. use object serialization to marshal and unmarshal parameters, supporting
true object-oriented polymorphism.
c. RMI applications are often comprised of two separate programs: a server
and a client.
d. All the above

Answer: D
MARK:
1

MIX
CHOICES:
No

QN=109
(4943)
Select correct statement(s) about remote class.(choose one)
a. It must extend java.rmi.server.UnicastRemoteObject.
b. It must implement the remote interface.
c. It is the class whose methods provide services to clients.
d. All the others choices

Answer: D
MARK:
1

MIX
CHOICES:
Yes

QN=110
(4942)
Select correct statements about remote interface. (choose 1)
a. A remote interface is an interface that describes the remotely accessible
methods of a remote object.
b. All remote interfaces must extend java.rmi.Remote.
c. All methods in a remote interface must throw java.rmi.RemoteException

d. The type of a remote reference is a remote interface
e.
All the others choices
f.

Answer: E
MARK:
1

MIX
CHOICES:
Yes

QN=111
(4939)
Select INCORRECT statement about serialization. (choose 1)
a. The process of writing an object is called serialization.
b. To serialize an object, first create an instance of
java.io.ObjectOutputStream.
c. When an Object Output Stream serializes an object that contains references
to another object, every referenced object is not serialized along with the original object.
d. When an object is serialized, it will probably be deserialized by a different
JVM.

Answer: C
MARK:
1

MIX
CHOICES:
Yes

QN=112
(4940)
Select INCORRECT statement about deserialize. (choose 1)
a. Any JVM that tries to deserialize an object must have access to that
object’s class definition.
b. We use readObject() method of ObjectOutputStream class to deserialize.
c. The readObject method deserializes the next object in the stream and
traverses its references to other objects recursively to deserialize all objects that are reachable from it.
d.

Answer: B
MARK:
1

MIX
CHOICES:
Yes

QN=113
(4944)
Select incorrect statement about RMI server.(choose 1)
a. An RMI server is an application that creates one or more remote objects
and makes them available to clients.
b. An RMI server performs two tasks:

1. Create an instance of the remote object.
2. Bind the remote object to a name.
   c. The RMI registry is a program that associates names with RMI services. A
   server specifies a name for every remote object it provides.
   d. A client accesses a remote object by specifying only the server name.

Answer: D
MARK:
1

MIX
CHOICES:
Yes

QN=114
(4938)
Select incorrect statement about ServerSocket class. (choose 1)
a. The most useful form of the ServerSocket constructor is public
ServerSocket(int portNumber)
b. A server socket, on the other hand, makes itself available and then waits
for clients to initiate connections.
c. To make the new object available for client connections, call its accept()
method, which returns an instance of ServerSocket
d. There is no way to know how long the accept() call will take.

Answer: C
MARK:
1

MIX
CHOICES:
Yes

QN=115
(4937)
Select incorrect statement about Socket class. (choose 1)
a. The java.net.Socket class contains code that knows how to find and
communicate with a server through UDP.
b. One of its constructors is: public Socket(String servername, int
portNumber)

c. You do not directly read from or write to a socket
d. The java.net.Socket class contains code that knows how to find and
communicate with a server through TCP.

Answer: A
MARK:
1

MIX
CHOICES:
Yes

QN=116
(7257)
Select the correct statement about JDBC two-tier processing model.
a. A user's commands are delivered to the database or other data source, and
the results of those statements are sent back to the user.
b. Two-tier is referred to as a client/server configuration, with the user's
machine as the Server, and the machine housing the data source as the
Client.
c. User's commands are sent to a "middle tier" of services, which then sends
the commands to the data source.
d.

Answer: A
MARK:
1

MIX
CHOICES:
Yes

QN=117
(7265)
SQL keyword is followed by the selection criteria that specify the
rows to select in a query
a. FROM
b. ORDER BY
c. HAVING
d. WHERE

Answer: D
MARK:
1

MIX
CHOICES:
Yes

QN=118
(7262)
Statement objects return SQL query results as objects
a. DataSet
b. ResultSet
c. RecordSet
d. RowSet

Answer: B
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
a. Only statement 1 is true
b. Only statement 2 is true
c. Both 1 and 2 are true
d. Both 1 and 2 are not true

Answer: C
MARK:
1

MIX
CHOICES:
Yes

QN=120
(160)
Suppose a method called finallyTest() consists of a try block, followed by a
catch block, followed by a finally block. Assuming the JVM doesn’t crash and the code does not execute a System.exit() call, under what circumstances will the finally block not begin to execute? (Choose one.)
a. The try block throws an exception, and the catch block also throws an
exception.
b. The try block throws an exception that is not handled by the catch block.
c. The try block throws an exception, and the catch block calls finallyTest()
in a way that causes another exception to be thrown.
d. If the JVM doesn't crash and the code does not execute a System.exit() call,
the finally block will always execute.

Answer: D
MARK:
1

MIX
CHOICES:
Yes

QN=121
(56)
Suppose a source file contains a large number of import statements and one
class definition. How do the imports affect the time required to load the class? (Choose one.)
a. Class loading takes no additional time.
b. Class loading takes slightly more time.
c. Class loading takes significantly more time.
d.

Answer: A
MARK:
1

MIX
CHOICES:
Yes

QN=122
(55)
Suppose a source file contains a large number of import statements. How
do the imports affect the time required to compile the source file? (Choose one.)
a. Compilation takes no additional time.
b. Compilation takes slightly more time.
c. Compilation takes significantly more time.
d.

Answer: B
MARK:
1

MIX
CHOICES:
Yes

QN=123
(247)
Suppose class A extends Object; Class B extends A; and class C extends B.
Of these, only class C implements java.io.Externalizable. Which of the following must be true in order to avoid an exception during deserialization of an instance of C? (Choose one.)
a. A must have a no-args constructor.

b. B must have a no-args constructor.
c. C must have a no-args constructor.
d. There are no restrictions regarding no-args constructors.

Answer: C
MARK:
2

MIX
CHOICES:
Yes

QN=124
(246)
Suppose class A extends Object; class B extends A; and class C extends B.
Of these, only class C implements java.io.Serializable. Which of the following must be true in order to avoid an exception during deserialization of an instance of C? (Choose one.)
a. A must have a no-args constructor.
b. B must have a no-args constructor.
c. C must have a no-args constructor.
d. There are no restrictions regarding no-args constructors.

Answer: B
MARK:
2

MIX
CHOICES:
Yes

QN=125
(122)
Suppose class A has a method called doSomething(), with default access.
Suppose class B extends A and overrides doSomething(). Which access modes may not apply to B’s version of doSomething()? (Choose one)
a. public
b. private
c. protected
d. Default

Answer: B
MARK:
1

MIX
CHOICES:
Yes

QN=126
(117)
Suppose class Supe, in package packagea, has a method called
doSomething(). Suppose class Subby, in package packageb, overrides doSomething(). What access modes may Subby’s version of the method have? (Choose two.)
a. public
b. protected
c. Default
d. private

Answer: AB
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
a. public void doSomething(int a, float b) { … }
b. private void doSomething(int a, float b) { … }
c. public void doSomething(int a, float b) throws java.io.IOException { … }
d. private void doSomething(int a, float b) throws java.io.IOException { … }

Answer: A
MARK:
0.5

MIX
CHOICES:
Yes

QN=128
(119)
Suppose interface Inty defines five methods. Suppose class Classy declares
that it implements Inty but does not provide implementations for any of the five interface methods. Which are true? (Choose two.)
a. The class will not compile.
b. The class will compile if it is declared public. c. The class will compile if it is declared abstract.
d. The class may not be instantiated.

Answer: CD
MARK:
1

MIX
CHOICES:
Yes

QN=129
(222)
Suppose prim is an int and wrapped is an Integer. Which of the following
are legal Java statements? (Choose one.)
a. prim = wrapped;
b. wrapped = prim;
c. prim = new Integer(9);
d. wrapped = 9;
e.
All the above
f.

Answer: E
MARK:
1

MIX
CHOICES:
No

QN=130
(158)
Suppose salaries is an array containing floats. Which of the following are
valid loop control statements for processing each element of salaries? (Choose one.)
a. for (float f:salaries)
b. for (int i:salaries)
c. for (float f::salaries)
d. for (int i::salaries)

Answer: A
MARK:
0.5

MIX
CHOICES:
Yes

QN=131
(139)
Suppose the declared type of x is a class, and the declared type of y is an
interface. When is the assignment x = y; legal? (Choose one.)
a. When the type of x is Object
b. When the type of x is an array
c. Always
d. Never

Answer: A
MARK:
1

MIX
CHOICES:
Yes

QN=132
(140)
Suppose the type of xarr is an array of XXX, and the type of yarr is an
array of YYY. When is the assignment xarr = yarr; legal? (Choose one.)
a. Sometimes
b. Always
c. Never
d. None of the others choices

Answer: A
MARK:
1

MIX
CHOICES:
No

QN=133
(183)
Suppose x and y are of type TrafficLightState, which is an enum. What is
the best way to test whether x and y refer to the same constant? (Choose one.)
a. if (x == y)
b. if (x.equals(y))
c. if (x.toString().equals(y.toString()))
d. if (x.hashCode() == y.hashCode())

Answer: A
MARK:
0.5

MIX
CHOICES:
Yes

QN=134
(245)
Suppose you are writing a class that will provide custom deserialization.
The class implements java.io.Serializable (not java.io.Externalizable). What access mode should the readObject() method have? (Choose one.)
a. public
b. protected
c. default

d. private

Answer: D
MARK:
1

MIX
CHOICES:
Yes

QN=135
(243)
Suppose you are writing a class that will provide custom serialization. The
class implements java.io.Serializable (not java.io.Externalizable). What access mode should the writeObject() method have? (Choose one.)
a. public
b. protected
c. default
d. private

Answer: D
MARK:
1

MIX
CHOICES:
Yes

QN=136
(211)
Suppose you want to create a custom thread class by extending
java.lang.Thread in order to provide some special functionality. Which of the following must you do? (Choose one.)
a. Declare that your class implements java.lang.Runnable.
b. Override run().
c. Override start().
d. Make sure that all access to all data is via synchronized methods.

Answer: B
MARK:
0.5

MIX
CHOICES:
Yes

QN=137 (214)
Suppose you want to write a class that offers static methods to compute hyperbolic trigonometric functions. You decide to subclass java.lang.Math and provide the new functionality as a set of static methods. Which one

statement is true about this strategy?
a. The strategy works.
b. The strategy works, provided the new methods are public. c. The strategy works, provided the new methods are not private.
d. The strategy fails because you cannot subclass java.lang.Math.
e.
The strategy fails because you cannot add static methods to a subclass.
f.

Answer: D
MARK:
1

MIX
CHOICES:
Yes

QN=138
(304)
Swing components cannot be combined with AWT components.
a. True
b. False
c.
d.

Answer: A
MARK:
0.5

MIX
CHOICES:
Yes

QN=139
(299)
The class is the primary class that has the driver information.
a. DriverManager
b. Driver
c. ODBCDriver
d. None of the others

Answer: A
MARK:
1

MIX
CHOICES:
No

QN=140 The class is used to implement a pull-down menu that provides a

(307)
number of items to select from.
a. MenuBar
b. Menu
c. MenuItem
d. PopUp

Answer: B
MARK:
0.5

MIX
CHOICES:
Yes

QN=141
(1876)
The element method alters the contents of a Queue.
a. True
b. False
c.
d.

Answer: B
MARK:
0.5

MIX
CHOICES:
Yes

QN=142
(303)
The Swing component classes can be found in the
package.
a. javax.swing
b. java.swing
c. javax.swings
d. javax.Swing

Answer: A
MARK:
0.5

MIX
CHOICES:
Yes

QN=143 There are two classes in Java to enable communication using datagrams

(310)
namely.
a. DataPacket and DataSocket
b. DatagramPacket and DatagramSocket
c. DatagramPack and DatagramSock
d.

Answer: A
MARK:
0.5

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
    a. Compilation of Parrot.java fails at line 4 because method fly() is protected
    in the superclass, and classes Bird and Parrot are in the same package.
    b. Compilation of Parrot.java fails at line 4 because method fly() is protected
    in the superclass and public in the subclass, and methods may not be overridden to be more public. c. Compilation of Parrot.java fails at line 7 because method getRefCount() is
    static in the superclass, and static methods may not be overridden to be nonstatic. d. Compilation of Parrot.java succeeds, but a runtime exception is thrown if
    method fly() is ever called on an instance of class Parrot.
    e.
    Compilation of Parrot.java succeeds, but a runtime exception is thrown if

method getRefCount() is ever called on an instance of class Parrot.
f.

Answer: C
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
    a. The program will compile and execute. The output will be Before: 0 After:
21. b. The program will compile and execute. The output will be Before: 0 After:
22. c. Compilation of Nightingale will fail at line 4 because static members
    cannot be overridden.
    d. Compilation of Nightingale will fail at line 10 because method fly() is
    protected in the superclass.
    e.
    Compilation of Nightingale will succeed, but an exception will be thrown
    at line 10, because method fly() is protected in the superclass.
    f.

Answer: A
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
a. void doSomething() { … }
b. void doSomething() throws AWTException { … }
c. void doSomething() throws EOFException { … }
d. void doSomething() throws IOException, EOFException { … }

Answer: ACD
MARK:
1

MIX
CHOICES:
Yes

QN=147
(4930)
URL referring to databases use the form:
a. protocol:subprotocol:datasoursename
b. protocol:datasoursename
c. jdbc:odbc:datasoursename
d. jdbc:datasoursename

Answer: A
MARK:
1

MIX
CHOICES:
Yes

QN=148 (142)
What are the legal types for whatsMyType? (Choose one.)

short s = 10;

whatsMyType = !s;
a. short
b. int
c. There are no possible legal types.
d. long
e.
char
f.
byte
Answer: C
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
a. Prints “Value is 5”.
b. Throws an exception.
c. Compile error
d.

Answer: B
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
   a. The output is i = 30.
   b. The output is i = 20.
   c. The output is i = 10.

d. There is no output because the code throws an exception at line 1.
e.
There is no output because the code throws an exception at line 5.
f.

Answer: B
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
a. 0
b. 5
c. 1000
d. -1

Answer: D
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
    a. Compiler error at line 9.
    b. An exception is thrown at line 9.
    c. An exception is thrown at line 10.
    d. No compiler error and no exception.

Answer: B
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
a. The code does not compile
b. The code compiles, and prints out >><<
c. The code compiles, and prints out >>null<<
d.

Answer: C
MARK:
0.5

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
    a. Compiler error.
    b. An exception is thrown at line 6.
    c. An exception is thrown at line 7.
    d. An exception is thrown at line 8.
    e.
    No exception is thrown.
    f.

Answer: C
MARK:
1

MIX
CHOICES:
Yes

QN=155
(86)
What is -50 >> 2
a. A negative number with very large magnitude.
b. A positive number with very large magnitude.
c. -13
d. -25
e.
13
f.
25
Answer: C
MARK:
1

MIX
CHOICES:
Yes

QN=156
(72)
What is 7 % -4?
a. -3
b. 3
c. -4
d. 4

Answer: B

MARK:
0.5

MIX
CHOICES:
Yes

QN=157
(71)
What is -8 % 5?
a. -3
b. 3
c. -2
d. 2

Answer: A
MARK:
0.5

MIX
CHOICES:
Yes

QN=158
(146)
What is the difference between the rules for method-call conversion and
the rules for assignment conversion? (Choose one.)
a. There is no difference; the rules are the same.
b. Method-call conversion supports narrowing, assignment conversion does
not.
c. Assignment conversion supports narrowing, method-call conversion does
not.
d. Method-call conversion supports narrowing if the method declares that it
throws ClassCastException.

Answer: A
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
    a. On line 1, remove the final modifier.
    b. On line 10, remove the final modifier.
    c. Remove line 15.
    d. On lines 1 and 10, remove the final modifier.
    e.
    The code will compile as is. No modification is needed. f.

Answer: A
MARK:
2

MIX
CHOICES:
Yes

QN=160
(54)
What is the range of values that can be assigned to a variable of type byte?
(Choose one.)
a. Depends on the underlying hardware
b. 0 through 2^8 − 1
c. 0 through 2^16 − 1
d. −2^7 through 2^7 − 1
e.
−2^15 through 2^15 − 1
f.

Answer: D
MARK:
0.5

MIX
CHOICES:
Yes

QN=161
(53)
What is the range of values that can be assigned to a variable of type short?
(Choose one.)
a. Depends on the underlying hardware
b. 0 through 2^16 − 1

c. 0 through 2^32 − 1
d. −2^15 through 2^15 − 1
e.
−2^31 through 2^31 − 1
f.

Answer: D
MARK:
0.5

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
    a. The code fails to compile.
    b. The code compiles but throws an exception at line 4.
    c. The code compiles and executes but has no effect on the local file system.
    d. The code compiles and executes; afterward, the current working directory
    contains a file called datafile.

Answer: A
MARK:
2

MIX
CHOICES:
Yes

QN=163 (83)
What is the return type of the instanceof operator?

a. A reference
b. A class
c. An int
d. A boolean

Answer: D
MARK:
0.5

MIX
CHOICES:
Yes

QN=164
(249)
What method of the java.io.File class can create a file on the hard drive?
(Choose one.)
a. newFile()
b. makeFile()
c. makeNewFile()
d. createFile()
e.
createNewFile()
f.

Answer: E
MARK:
0.5

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
   a. The output: value is 99.99
   b. The output: value is 9
   c. The output: value is 9.0
   d. A compiler error at line 4

Answer: C
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
   a. The output: b contains 10
   b. The output: b contains 5
   c. The output: b contains 250
   d. The output: b contains 245

Answer: B
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
    a. message one
    b. message two
    c. message three
    d. message four

Answer: D
MARK:
1

MIX
CHOICES:
Yes

QN=168
(78)
When a byte is added to a char, what is the type of the result?
a. byte
b. char
c. int
d. short
e.
You can’t add a byte to a char.
f.

Answer: C
MARK:
0.5

MIX
CHOICES:
Yes

QN=169
(144)
When a negative byte is cast to a long, what are the possible values of the
result? (Choose one.)
a. Positive
b. Zero
c. Negative
d. All the above

Answer: C
MARK:
0.5

MIX
CHOICES:
No

QN=170
(143)
When a negative long is cast to a byte, what are the possible values of the
result? (Choose one.)
a. Positive
b. Zero
c. Negative
d. All the above

Answer: D
MARK:
0.5

MIX
CHOICES:
No

QN=171
(79)
When a short is added to a float, what is the type of the result?
a. short
b. int
c. float
d. You can’t add a short to a float.

Answer: C
MARK:
0.5

MIX
CHOICES:
Yes

QN=172
(1531)
When comparing java.io.BufferedWriter to java.io.FileWriter, which
capability exists as a method in only one of the two? (Choose one.)
a. closing the stream
b. flushing the stream
c. writing to the stream
d. marking a location in the stream
e.
writing a line separator to the stream
f.

Answer: E
MARK:
1

MIX
CHOICES:
Yes

QN=173
(165)
When does an exception's stack trace get recorded in the exception object?
(Choose one.)
a. When the exception is constructed
b. When the exception is thrown
c. When the exception is caught
d. When the exception’s printStackTrace() method is called

Answer: A
MARK:
1

MIX
CHOICES:
Yes

QN=174
(163)
When is it appropriate to pass a cause to an exception's constructor?
(Choose one.)
a. Always
b. When the exception is being thrown in response to catching of a different
exception type
c. When the exception is being thrown from a public method
d. When the exception is being thrown from a private method

Answer: B
MARK:
1

MIX
CHOICES:
Yes

QN=175
(166)
When is it appropriate to write code that constructs and throws an error?
(Choose one.)
a. When a public method’s preconditions are violated
b. When a public method’s postconditions are violated
c. When a nonpublic method’s preconditions are violated
d. When a nonpublic method’s postconditions are violated
e.
Never
f.

Answer: E
MARK:
1

MIX
CHOICES:
Yes

QN=176
(141)
When is x & y an int? (Choose one).
a. Always
b. Sometimes
c. When neither x nor y is a float, a long, or a double

d. None of the others

Answer: B
MARK:
1

MIX
CHOICES:
No

QN=177
(308)
When the user attempts to close the frame window, event in
generated. a. window closing
b. window resize
c. window move
d. window close
e.
window closed
f.

Answer: A
MARK:
1

MIX
CHOICES:
Yes

QN=178
(312)
When the user selects a menu item, event is generated. a. Select event
b. Action event
c. Item event
d. None of the others

Answer: B
MARK:
1

MIX
CHOICES:
No

QN=179
(5694)
When you compile a program written in the Java programming language,
the compiler converts the human-readable source file into platform- independent code that a Java Virtual Machine can understand. What is this platform-independent code called?
a. bytecode

b. binary code
c. machine code
d. cpu instruction

Answer: A
MARK:
1

MIX
CHOICES:
Yes

QN=180
(313)
Whenever a method does not want to handle exceptions using the try
block, the is used. a. throws
b. throw
c. throwable
d. nothrows

Answer: A
MARK:
0.5

MIX
CHOICES:
Yes

QN=181
(7267)
Which are the correct statements used for getting connection object to
connect to SQL Server database?
a. String url ="jdbc:odbc:data_source_name"; Connection con =
DriverManager.getConnection (url, “user", "password");
b. String url ="odbc:jdbc:data_source_name"; Connection con =
DriverManager.getConnection (url, “user", "password");
c. String url ="jdbc:data_source_name:odbc"; Connection con =
DriverManager.getConnection (url, “user", "password");
d.

Answer: A
MARK:
1

MIX
CHOICES:
Yes

QN=182
(1879)
Which class and static method can you use to convert an array to a List?
(Choose one.)
a. Arrays.asList
b. Arrays.toList
c. Arrays.createList
d. Arrays.makeList

Answer: A
MARK:
0.5

MIX
CHOICES:
Yes

QN=183
(302)
Which is four-step approach to help you organize your GUI thinking.
(Choose one.)
a. Identify needed components.
Isolate regions of behavior. Sketch the GUI.
Choose layout managers.
b. Choose layout managers.
Identify needed components. Isolate regions of behavior. Sketch the GUI.
c. Identify needed components.
Choose layout managers. Isolate regions of behavior. Sketch the GUI.
d.

Answer: A
MARK:
1

MIX
CHOICES:
Yes

QN=184
(4928)
Which is the four steps are used in working with JDBC?
a. 1)Connect to the database
2)Create a statement and execute the query
3)Look at the result set
4)Close connection

b. 1)Load driver
2)Create a statement and execute the query
3)Look at the result set
4)Close connection
c. 1)Create a statement and execute the query
2)Load driver
3)Look at the result set
4)Close connection
d. 1)Create a statement and execute the query
2)Create the connection
3)Look at the result set
4)Close connection

Answer: A
MARK:
1

MIX
CHOICES:
Yes

QN=185
(7256)
Which JDBC processing model that requires a JDBC driver that can
communicate with the particular data source being accessed?
a. two-tier
b. three-tier
c. one-tier
d. four-tier

Answer: A
MARK:
1

MIX
CHOICES:
Yes

QN=186
(229)
Which line of code tells a scanner called sc to use a single digit as a
delimiter? (Choose one.)
a. sc.useDelimiter("d");
b. sc.useDelimiter("\d");
c. sc.useDelimiter("\\d");
d. sc.useDelimiter("d+");
e.
sc.useDelimiter("\d+");
f.
sc.useDelimiter("\\d+");
Answer: C

MARK:
1

MIX
CHOICES:
Yes

QN=187
(1411)
Which Man class properly represents the relationship "Man has the best
friend who is a Dog"? (Choose one.)
a. class Man extends Dog { }
b. class Man implements Dog { }
c. class Man { private BestFriend dog; }
d. class Man { private Dog bestFriend; }
e.
class Man { private Dog<bestFriend> }
f.
class Man { private BestFriend<dog> }
Answer: D
MARK:
1

MIX
CHOICES:
Yes

QN=188
(189)
Which methods return an enum constant’s name? (Choose two.)
a. getName()
b. name()
c. toString()
d. nameString()
e.
getNameString()
f.

Answer: BC
MARK:
0.5

MIX
CHOICES:
Yes

QN=189
(114)
Which modifier or modifiers should be used to denote a variable that
should not be written out as part of its class's persistent state? (Choose the shortest possible answer.)
a. private
b. protected
c. private protected
d. transient
e.
volatile
f.

Answer: D
MARK:
1

MIX
CHOICES:
Yes

QN=190
(162)
Which of the following are legal argument types for a switch statement?
(Choose three.)
a. byte
b. int
c. long
d. float
e.
char
f.
String
Answer: ABE
MARK:
0.5

MIX
CHOICES:
Yes

QN=191
(177)
Which of the following are legal enums? (Choose three.)
a. enum Animals { LION, TIGER, BEAR }
b. enum Animals {
int age;
LION, TIGER, BEAR;
}
c. enum Animals {
LION, TIGER, BEAR;
int weight;
}
d. enum Animals {
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

Answer: ACE
MARK:
1

MIX
CHOICES:
Yes

QN=192
(57)
Which of the following are legal import statements? (Choose two.)
a. import java.util.Vector;
b. static import java.util.Vector._;
c. import static java.util.Vector._;
d. import java.util.Vector static;

Answer: AC
MARK:
0.5

MIX
CHOICES:
Yes

QN=193
(149)
Which of the following are legal loop constructions? (Choose one.)
a. while (int i<7) {
i++;
System.out.println("i is " + i);
}
b. int i = 3;
while (i) {
System.out.println("i is " + i);
}
c. int j = 0;
for (int k=0, j+k != 10; j++,k++) { System.out.println("j=" + j + ", k=" + k);
}
d. int j=0;
do {
System.out.println("j=" + j++);
if (j==3) continue loop;
} while (j<10);

Answer: C
MARK:
1

MIX
CHOICES:
Yes

QN=194
(161)
Which of the following are legal loop definitions? (Choose one.)
a. while (int a = 0) { /_ whatever _/ }
b. while (int a == 0) { /_ whatever _/ }
c. do { /_ whatever _/ } while (int a = 0)
d. do { /_ whatever _/ } while (int a == 0)
e.
for (int a==0; a<100; a++) { /_ whatever _/ }
f.
None of the above.
Answer: F
MARK:
1

MIX
CHOICES:
No

QN=195
(159)
Which of the following are legal? (Choose three.)
a. for (int i=0, j=1; i<10; i++, j++)
b. for (int i=0, j=1;; i++, j++)
c. for (int i=0, float j=1; ; i++, j++)
d. for (String s = ""; s.length()<10; s += '!')
e.
while(1)
f.

Answer: ABD
MARK:
1

MIX
CHOICES:
Yes

QN=196
(62)
Which of the following are legal? (Choose two.)
a. double d = 1.2d;
b. double d = 1.2D;
c. double d = 1.2d5;
d. double d = 1.2D5;

Answer: AB
MARK:
0.5

MIX
CHOICES:
Yes

QN=197
(61)
Which of the following are legal? (Choose two.)
a. int a = abcd;
b. int b = ABCD;
c. int c = 0xabcd;
d. int d = 0XABCD;
e.
int f = 0ABCD;
f.

Answer: CD
MARK:
0.5

MIX
CHOICES:
Yes

QN=198
(63)
Which of the following are legal? (Choose two.)
a. char c = 0x1234;
b. char c = \u1234;
c. char c = '\u1234';
d.

Answer: AC
MARK:
0.5

MIX
CHOICES:
Yes

QN=199
(223)
Which of the following are legal? (Choose two.)
a. List<String> theList = new Vector<String>;
b. List<String> theList = new Vector<String>();
c. Vector <String> theVec = new Vector<String>;
d. Vector <String> theVec = new Vector<String>();

Answer: BD
MARK:
0.5

MIX
CHOICES:
Yes

QN=200
(228)
Which of the following are methods of the java.util.SortedMap interface?
(Choose three.)
a. first
b. last
c. headMap
d. tailMap
e.
subMap
f.

Answer: CDE
MARK:
1

MIX
CHOICES:
Yes

QN=201
(227)
Which of the following are methods of the java.util.SortedSet interface?
(Choose one.)
a. first
b. last
c. headSet
d. tailSet
e.
subSet
f.
All the above
Answer: F
MARK:
1

MIX
CHOICES:
No

QN=202
(250)
Which of the following are true? (Choose one.)
a. System.out has a println() method. b. System.out has a format() method. c. System.err has a println() method. d. System.err has a format () method. e.
All the above

f.

Answer: E
MARK:
0.5

MIX
CHOICES:
No

QN=203
(207)
Which of the following are true? (Choose one.)
a. The JVM runs until there is only one daemon thread. b. The JVM runs until there are no daemon threads.
c. The JVM runs until there is only one non-daemon thread. d. The JVM runs until there are no non-daemon threads.

Answer: D
MARK:
1

MIX
CHOICES:
Yes

QN=204
(206)
Which of the following are true? (Choose three.)
a. When an application begins running, there is one daemon thread, whose
job is to execute main().
b. When an application begins running, there is one non-daemon thread,
whose job is to execute main().
c. A thread created by a daemon thread is initially also a daemon thread. d. A thread created by a non-daemon thread is initially also a non-daemon
thread.

Answer: BCD
MARK:
1

MIX
CHOICES:
Yes

QN=205
(210)
Which of the following are true? (Choose two.)
a. When you declare a method to be synchronized, the method always
synchronizes on the lock of the current object.

b. When you declare a method to be synchronized, you can specify the object
on whose lock the method should synchronize.
c. When you declare a block of code inside a method to be synchronized, the
block always synchronizes on the lock of the current object.
d. When you declare a block of code inside a method to be synchronized, you
can specify the object on whose lock the block should synchronize.

Answer: AD
MARK:
1

MIX
CHOICES:
Yes

QN=206
(185)
Which of the following are true? (Choose two.)
a. An enum definition should declare that it extends java.lang.Enum.
b. An enum may be subclassed. c. An enum may contain public method definitions.
d. An enum may contain private data.

Answer: CD
MARK:
0.5

MIX
CHOICES:
Yes

QN=207
(65)
Which of the following are true? (Choose two.)
a. Primitives are passed by reference.
b. Primitives are passed by value.
c. References are passed by reference.
d. References are passed by value.

Answer: BD
MARK:
0.5

MIX
CHOICES:
Yes

QN=208
(188)
Which of the following are true? (Choose two.)
a. An anonymous inner class may implement at most one interface.
b. An anonymous inner class may implement arbitrarily many interfaces.
c. An anonymous inner class may extend a parent class other than Object.
d. An anonymous inner class that implements one interface may extend a
parent class other than Object.
e.
An anonymous inner class that implements several interfaces may extend a
parent class other than Object.
f.

Answer: AC
MARK:
1

MIX
CHOICES:
Yes

QN=209
(253)
Which of the following are valid arguments to the DataInputStream
constructor? (Choose one.)
a. File
b. FileReader
c. FileInputStream
d. RandomAccessFile

Answer: C
MARK:
0.5

MIX
CHOICES:
Yes

QN=210
(252)
Which of the following are valid mode strings for the RandomAccessFile
constructor? (Choose one.)
a. "r"
b. "rw"
c. "rws"
d. "rwd"
e.
All the above
f.

Answer: E
MARK:
1

MIX
CHOICES:
No

QN=211
(203)
Which of the following calls may be made from a non-static synchronized
method? (Choose one.)
a. A call to the same method of the current object.
b. A call to the same method of a different instance of the current class.
c. A call to a different synchronized method of the current object.
d. A call to a static synchronized method of the current class.
e.
All the above
f.

Answer: E
MARK:
1

MIX
CHOICES:
No

QN=212
(226)
Which of the following classes implement java.util.List? (Choose two.)
a. java.util.ArrayList
b. java.util.HashMap
c. java.util.TreeSet
d. java.util.Stack

Answer: AD
MARK:
0.5

MIX
CHOICES:
Yes

QN=213
(1878)
Which of the following classes implements a FIFO Queue? (Choose one.)
a. HashSet
b. LinkedList
c. PriorityQueue
d. CopyOnWriteArraySet

Answer: B
MARK:
1

MIX
CHOICES:
Yes

QN=214
(107)
Which of the following declarations are illegal? (Choose three.)
a. default String s;
b. transient int i = 41;
c. public final static native int w();
d. abstract double d;
e.
abstract final double hyperbolicCosine();
f.

Answer: ADE
MARK:
0.5

MIX
CHOICES:
Yes

QN=215
(68)
Which of the following expressions are legal? (Choose two.)
a. int x = 6; x = !x;
b. int x = 6; if (!(x > 3)) {}
c. int x = 6; x = ~x;
d.

Answer: BC
MARK:
0.5

MIX
CHOICES:
Yes

QN=216
(70)
Which of the following expressions are legal? (Choose two.)
a. String x = "Hello"; int y = 9; x += y;
b. String x = "Hello"; int y = 9; if (x == y) {}
c. String x = "Hello"; int y = 9; x = x + y;
d. String x = "Hello"; int y = 9; y = y + x;

Answer: AC
MARK:
0.5

MIX
CHOICES:
Yes

QN=217
(69)
Which of the following expressions results in a positive value in x?
(Choose one.)
a. int x = –1; x = x >>> 5;
b. int x = –1; x = x >>> 32;
c. byte x = –1; x = x >>> 5;
d. int x = –1; x = x >> 5;

Answer: A
MARK:
0.5

MIX
CHOICES:
Yes

QN=218
(1874)
Which of the following interfaces does not allow duplicate objects?
(Choose one.)
a. Queue
b. Set
c. List
d.

Answer: B
MARK:
0.5

MIX
CHOICES:
Yes

QN=219
(155)
Which of the following is not appropriate situations for assertions?
(Choose one)
a. Preconditions of a public method
b. Postconditions of a public method
c. Preconditions of a private method
d. Postconditions of a private method

Answer: A
MARK:
1

MIX
CHOICES:
Yes

QN=220
(5695)
Which of the following is NOTa valid comment:
a. /\*_ comment _/
b. /_ comment _/
c. /\* comment
d. // comment

Answer: C
MARK:
1

MIX
CHOICES:
Yes

QN=221
(157)
Which of the following is the most appropriate way to handle invalid
arguments in a public method?
a. Throw java.lang.InvalidArgumentException.
b. Throw java.lang.IllegalArgumentException.
c. Check for argument validity in an assert statement, which throws
AssertionError when the arguments are invalid. d. Use non-assert code to check for argument validity. If invalid arguments
are detected, explicitly throw AssertionError.

Answer: B
MARK:
1

MIX
CHOICES:
Yes

QN=222
(240)
Which of the following is true? (Choose one.)
a. Readers have methods that can read and return floats and doubles.
b. Readers have methods that can read and return floats.
c. Readers have methods that can read and return doubles.
d. Readers have methods that can read and return ints.
e.
None of the above
f.

Answer: E
MARK:
1

MIX No
CHOICES:

QN=223
(184)
Which of the following is(are) true? (Choose one.)
a. An enum definition may contain the main() method of an application.
b. You can call an enum’s toString() method. c. You can call an enum’s wait() method. d. You can call an enum’s notify() method. e.
All the above
f.

Answer: E
MARK:
1

MIX
CHOICES:
No

QN=224
(84)
Which of the following may appear on the left-hand side of an instanceof
operator?
a. A reference
b. A class
c. An interface
d. A variable of primitive type

Answer: A
MARK:
1

MIX
CHOICES:
Yes

QN=225
(85)
Which of the following may appear on the right-hand side of an instanceof
operator? (Choose two.)
a. A reference
b. A class
c. An interface
d. A variable of primitive type
e.
The name of a primitive type
f.

Answer: BC
MARK:
1

MIX CHOICES:
Yes

QN=226
(120)
Which of the following may be declared final? (Choose two.)
a. Classes
b. Interfaces
c. Methods
d.

Answer: AC
MARK:
0.5

MIX
CHOICES:
Yes

QN=227
(58)
Which of the following may be statically imported? (Choose two.)
a. Package names
b. Static method names
c. Static field names
d. Method-local variable names

Answer: BC
MARK:
0.5

MIX
CHOICES:
Yes

QN=228
(121)
Which of the following may follow the static keyword? (Choose three.)
a. Class definitions
b. Data
c. Methods
d. Code blocks enclosed in curly brackets
e.
Variables
f.

Answer: BCD
MARK:
0.5

MIX CHOICES:
Yes

QN=229
(137)
Which of the following may legally appear as the new type (between the
parentheses) in a cast operation? (Choose one.)
a. Classes
b. Interfaces
c. Arrays of classes
d. Arrays of interfaces
e.
All of the others
f.

Answer: E
MARK:
1

MIX
CHOICES:
No

QN=230
(138)
Which of the following may legally appear as the new type (between the
parentheses) in a cast operation? (Choose one.)
a. Abstract classes
b. Final classes
c. Primitives
d. All of the above

Answer: D
MARK:
1

MIX
CHOICES:
No

QN=231
(202)
Which of the following may not be synchronized? (Choose one.)
a. Blocks within methods
b. Static methods
c. Blocks within static methods
d. Classes

Answer: D
MARK:
1

MIX CHOICES:
Yes

QN=232
(186)
Which of the following may override a method whose signature is void
xyz(float f)? (Choose two.)
a. void xyz(float f)
b. public void xyz(float f)
c. private void xyz(float f)
d. public int xyz(float f)
e.
private int xyz(float f)
f.

Answer: AB
MARK:
1

MIX
CHOICES:
Yes

QN=233
(199)
Which of the following methods in the Thread class are deprecated?
(Choose one.)
a. suspend() and resume()
b. wait() and notify()
c. start() and stop()
d. sleep() and yield()

Answer: A
MARK:
1

MIX
CHOICES:
Yes

QN=234
(81)
Which of the following operations might throw an ArithmeticException?
(Choose one.)
a.

> > b. > >
> >
> > > c. > > > <<
> > > d. > > > None of these

Answer: D
MARK:
0.5

MIX CHOICES:
Yes

QN=235
(82)
Which of the following operations might throw an ArithmeticException?
(Choose one.)
a.

- b.

* c.

- d. /
  e.
  None of the others
  f.

Answer: D
MARK:
0.5

MIX
CHOICES:
No

QN=236
(145)
Which of the following operators can perform promotion on their
operands? (Choose three.)
a.

- b.

* c. ++
  d. \* - e.
  ~
  f.
  !
  Answer: ABE
  MARK:
  1

MIX
CHOICES:
Yes

QN=237
(182)
Which of the following restrictions apply to anonymous inner classes?
(Choose one.)
a. They must be defined inside a code block.
b. They may only read and write final variables of the enclosing class.
c. They may only call final methods of the enclosing class.
d. They may not call the enclosing class’ synchronized methods.

Answer: A
MARK:
1

MIX CHOICES:
Yes

QN=238
(164)
Which of the following should always be caught? (Choose one.)
a. Runtime exceptions
b. Checked exceptions
c. Assertion errors
d. Errors other than assertion errors

Answer: B
MARK:
0.5

MIX
CHOICES:
Yes

QN=239
(47)
Which of the following signatures are valid for the main() method entry
point of an application? (Choose two.)
a. public static void main()
b. public static void main(String arg[])
c. public void main(String [] arg)
d. public static void main(String[] args)
e.
public static int main(String [] arg)
f.

Answer: BD
MARK:
0.5

MIX
CHOICES:
Yes

QN=240
(201)
Which of the following statements about the wait() and notify() methods is
true? (Choose one.)
a. The wait() and notify() methods can be called outside synchronized code.
b. The programmer can specify which thread should be notified in a notify()
method call.
c. The thread that calls wait() goes into the monitor’s pool of waiting threads.
d. The thread that calls notify() gives up the lock.

Answer: C
MARK:
1

MIX
CHOICES:
Yes

QN=241
(200)
Which of the following statements about threads is true? (Choose one.)
a. Every thread starts executing with a priority of 5.
b. Threads inherit their priority from their parent thread. c. Threads are guaranteed to run with the priority that you set using the
setPriority() method. d. Thread priority is an integer ranging from 1 to 100.

Answer: B
MARK:
1

MIX
CHOICES:
Yes

QN=242
(125)
Which of the following statements are true? (Choose one.)
a. A final class must be instantiated. b. A final class may only contain final methods.
c. A final class may not contain non-final data fields.
d. A final class may not be extended.

Answer: D
MARK:
1

MIX
CHOICES:
Yes

QN=243
(176)
Which of the following statements are true? (Choose one.)
a. Given that Inner is a nonstatic class declared inside a public class Outer
and that appropriate constructor forms are defined, an instance of Inner can be constructed like this: new Outer().new Inner()
b. If an anonymous inner class inside the class Outer is defined to implement
the interface ActionListener, it can be constructed like this: new
Outer().new ActionListener()
c. Given that Inner is a nonstatic class declared inside a public class Outer

and that appropriate constructor forms are defined, an instance of Inner can
be constructed in a static method like this: new Inner()
d. An anonymous class instance that implements the interface MyInterface
can be constructed and returned from a method like this:

1. return new MyInterface(int x) {
2. int x;
3. public MyInterface(int x) {
4. this.x = x;
5. }
6. };

Answer: A
MARK:
1

MIX
CHOICES:
Yes

QN=244
(118)
Which of the following statements are true? (Choose one.)
a. An abstract class may be instantiated. b. An abstract class must contain at least one abstract method. c. An abstract class must contain at least one abstract data field. d. An abstract class must be overridden.
e.
An abstract class must declare that it implements an interface.
f.
None of the above
Answer: F
MARK:
1

MIX
CHOICES:
No

QN=245
(232)
Which of the following statements are true? (Choose two.)
a. StringBuilder is generally faster than StringBuffer.
b. StringBuffer is generally faster than StringBuilder.
c. StringBuilder is threadsafe; StringBuffer is not.
d. StringBuffer is threadsafe; StringBuilder is not.

Answer: AD
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
a. Only statement 1
b. Only statement 2
c. Both statement 1 and 2
d.

Answer: B
MARK:
1

MIX
CHOICES:
No

QN=247
(127)
Which of the following statements is correct? (Choose one.)
a. Only primitives are converted automatically; to change the type of an
object reference, you have to do a cast.
b. Only object references are converted automatically; to change the type of a
primitive, you have to do a cast.
c. Arithmetic promotion of object references requires explicit casting.
d. Both primitives and object references can be both converted and cast.
e.
Casting of numeric types may require a runtime check.
f.

Answer: D
MARK:
1

MIX
CHOICES:
Yes

QN=248
(110)
Which of the following statements is true? (Choose one.)
a. Transient methods may not be overridden.
b. Transient methods must be overridden.
c. Transient classes may not be serialized. d. Transient variables must be static. e.
Transient variables are not serialized.
f.

Answer: E
MARK:
1

MIX
CHOICES:
Yes

QN=249
(132)
Which of the following statements is true? (Choose one.)
a. Object references can be converted in assignments but not in method calls.
b. Object references can be converted in method calls but not in assignments.
c. Object references can be converted in both method calls and assignments,
but the rules governing these conversions are very different.
d. Object references can be converted in both method calls and assignments,
and the rules governing these conversions are identical.
e.
Object references can never be converted. f.

Answer: D
MARK:
1

MIX
CHOICES:
Yes

QN=250
(233)
Which of the statements below are true? (Choose one.)
a. UTF characters are all 8 bits.
b. UTF characters are all 16 bits.
c. UTF characters are all 24 bits.
d. Unicode characters are all 16 bits.
e.
Bytecode characters are all 16 bits.
f.

Answer: D
MARK:
1

MIX
CHOICES:
Yes

QN=251
(235)
Which of the statements below are true? (Choose one.)
a. To change the current working directory, call the setWorkingDirectory()
method of the File class.
b. To change the current working directory, call the cd() method of the File

class.
c. To change the current working directory, call the
changeWorkingDirectory() method of the File class.
d. None of the above

Answer: D
MARK:
1

MIX
CHOICES:
No

QN=252
(234)
Which of the statements below are true? (Choose one.)
a. When you construct an instance of File, if you do not use the file-naming
semantics of the local machine, the constructor will throw an IOException.
b. When you construct an instance of File, if the corresponding file does not
exist on the local file system, one will be created. c. When an instance of File is garbage collected, the corresponding file on the
local file system is deleted. d. None of the above.

Answer: D
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
   a. Line 5
   b. Line 2
   c. Line 3
   d. Line 7

e.
Line 9
f.
Line 6
Answer: F
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
    a. When the application is run, thread hp1 will execute; threads hp2 and hp3
    will never get the CPU.
    b. When the application is run, thread hp1 will execute to completion, thread
    hp2 will execute to completion, then thread hp3 will execute to completion.
    c. When the application is run, all three threads (hp1, hp2, and hp3) will
    execute concurrently, taking time-sliced turns in the CPU.
    d. None of the above scenarios can be guaranteed to happen in all cases.

Answer: D
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
   a. Compilation fails at line 2.
   b. Compilation fails at line 3
   c. Compilation succeeds, although the import on line 1 is not necessary.
   During execution, an exception is thrown at line 3
   d. Compilation succeeds. The import on line 1 is necessary. During
   execution, an exception is thrown at line 3
   e.
   Compilation succeeds and no exception is thrown during execution.
   f.

Answer: A
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
   a. Compilation fails at line 1 because the String constructor must be called
   explicitly.
   b. Compilation fails at line 3 because s and s1 have different types.
   c. Compilation succeeds. During execution, an exception is thrown at line 3.
   d. Compilation succeeds. During execution, an exception is thrown at line 5.
   e.
   Compilation succeeds. No exception is thrown during execution.
   f.

Answer: E
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
   a. Lines 4 and 6 both execute.
   b. Line 4 executes and line 6 does not.
   c. Line 6 executes and line 4 does not.
   d. Neither line 4 nor line 6 executes.

Answer: C
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
    a. There will be a compiler error, because class Greebo does not correctly
    implement the Runnable interface.
    b. There will be a compiler error at line 13, because you cannot pass a
    parameter to the constructor of a Thread. c. The code will compile correctly but will crash with an exception at line 13.
    d. The code will compile correctly but will crash with an exception at line 14.
    e.
    The code will compile correctly and will execute without throwing any
    exceptions.
    f.

Answer: A
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
    a. The code is illegal because of the expression at line 5.
    b. The acceptable types for the variable j, as the argument to the switch()
    construct, could be any of byte, short, int, or long.
    c. The output would be the text value is two.
    d. The output would be the text value is two followed by the text value is
    three.
    e.
    The output would be the text value is two, followed by the text value is
    three, followed by the text value is 2.
    f.

Answer: D
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
a. It always returns 0.
b. It always returns 1.
c. It always an int where every bit is 1.
d. The returned value varies depending on the argument.

Answer: A
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
    a. Lines 5 and 12 will not compile because the method names and return
    types are missing.
    b. Line 12 will not compile because you can only have one static initializer.
    c. The code compiles and execution produces the output x = 10.
    d. The code compiles and execution produces the output x = 15.
    e.
    The code compiles and execution produces the output x = 3.
    f.

Answer: E
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
    a. Line 8 will not compile because it is a static reference to a

variable.
b. Line 13 will not compile because it is a static reference to a private
variable.
c. The program compiles and the output is x = 102.
d. The program compiles and the output is x = 103.
e.
The program compiles and the output is x = 104.
f.

Answer: E
MARK:
1

MIX
CHOICES:
Yes

QN=263
(4929)
Which statements about JDBC are NOT true? (choose 2)
a. JDBC is a Java API for executing SQL statements.
b. JDBC provides a standard API for tool/database developers and makes it
possible to write database applications using a pure Java API.
c. It consists of a set of classes and interfaces written in the Java
programming language.
d. The combination of Java and JDBC lets a programmer write it once and
run it anywhere.
e.
JDBC is a Java database system.
f.
JDBC is a Java API for connecting to any kind of DBMS
Answer: EF
MARK:
1

MIX
CHOICES:
Yes

QN=264
(1423)
Which two code fragments correctly create and initialize a static array of
int elements? (Choose two.)
a. static final int[] a = { 100,200 };
b. static final int[] a; static { a=new int[2]; a[0]=100; a[1]=200; }
c. static final int[] a = new int[2] { 100,200 };
d. static final int[] a; static void init() {a=new int[3];a[0]=100; a[1]=200;}

Answer: AB
MARK:
1

MIX
CHOICES:
Yes

QN=265
(1873)
Which two of the following interfaces are at the top of the hierarchies in
the Java Collections Framework? (Choose two.)
a. Set
b. Map
c. Queue
d. SortedMap
e.
Collection
f.
List
Answer: BE
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
   a. A new directory called dirname is created in the current working directory.
   b. A new directory called dirname is created in the current working directory.
   A new file called filename is created in directory dirname.
   c. A new directory called dirname and a new file called filename are created,
   both in the current working directory.
   d. A new file called filename is created in the current working directory.
   e.
   No directory is created, and no file is created. f.

Answer: E
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
a. protected class Cat extends Owner
b. public class Cat extends Object
c. public class Cat extends Pet
d. private class Cat extends Pet

Answer: C
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
a. Pet thePet;
b. Date registered;
c. Date vaccinationDue;
d. Cat theCat;
e.
boolean neutered;
f.
String markings;
Answer: EF
MARK:
2

MIX
CHOICES:
Yes
