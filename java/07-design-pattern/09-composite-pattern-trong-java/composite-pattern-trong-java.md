---
title: "Composite Pattern trong Java"
description: "Composite Pattern cho phép bạn xử lý tất cả các đối tượng giống nhau như là một đối tượng đơn lẻ hoặc một tập hợp"
chapter:
  name: "Design Pattern"
  slug: "chuong-07-design-pattern"
category:
  name: "Java"
  slug: "java"
image: https://user-images.githubusercontent.com/29374426/146175674-fa7e09f7-4e42-485e-a2b5-8c664601b203.png
position: 9
---

**Composite Pattern** là một mẫu [design pattern](/bai-viet/java/design-pattern-la-gi-design-pattern-trong-java) trong lập trình Java.

## Composite Pattern là gì?

**Composite Pattern** cho phép bạn xử lý tất cả các đối tượng giống nhau như là một đối tượng đơn lẻ hoặc một tập hợp. Nó thường được sử dụng khi bạn có một cấu trúc cây hoặc phân cấp, và bạn muốn thực hiện các hoạt động trên toàn bộ cây hoặc một phần của nó một cách đồng nhất.

Ví dụ: Nếu bạn có một thư mục chứa tệp tin và thư mục con, thì **Composite Pattern** cho phép bạn xử lý thư mục và tệp tin như là một đối tượng đơn, ngay cả khi thư mục chứa nhiều thư mục con và tệp tin.

## Composite Pattern UML Diagram

![Composite Pattern UML Diagram](https://github.com/techmely/hoc-lap-trinh/assets/29374426/e6a94794-f3fe-4338-a3e8-231117056fca)

Dưới đây là sơ đồ UML của **Composite Pattern**:

```scss
+-----------------+       +---------------------+
|    Component   |       |       Composite      |
+-----------------+       +---------------------+
| + operation()  |       | + add(Component c)  |
|                 |       | + remove(Component c)|
|                 |       | + getChild(int i)    |
+-----------------+       +---------------------+
           |                       |        |
           |                       |        |
+----------+---------+    +----------------+
|   Leaf           |    |   Leaf             |
+-----------------+    +----------------+
| + operation()  |    | + operation()    |
+-----------------+    +----------------+
```

- **Component**: Đây là giao diện hoặc lớp cơ sở chung cho tất cả các thành phần trong cây cấu trúc. Nó định nghĩa các phương thức chung mà các lớp con phải triển khai.
- **Composite**: Đây là lớp chứa một tập hợp các thành phần con và triển khai các phương thức chung từ **Component**. Nó có thể chứa nhiều **Leaf** và/hoặc **Composite**.
- **Leaf**: Đây là các lớp lá cuối cùng của cây cấu trúc. Chúng không có các thành phần con, và thực hiện các phương thức từ **Component**.

## Ví dụ về Composite Pattern

Giả sử bạn quản lý một dự án phần mềm và dự án này được chia thành nhiều công việc (Tasks) con. Bạn muốn tính tổng thời gian cần thiết cho dự án dựa trên thời gian của từng công việc và cả dự án.

![Ví dụ về Composite Pattern](https://github.com/techmely/hoc-lap-trinh/assets/29374426/e0a22f68-61f4-4c62-8726-869b7e620756)

### Các Lớp

```java
public abstract class TaskItem {
  public abstract double getTime();
}

public class Task extends TaskItem {
  String name;
  double time;

  // Constructor, getter và setter
  // ...

  @Override
  public double getTime() {
    return time;
  }
}

public class Project extends TaskItem {
  String name;
  ArrayList<TaskItem> subTasks = new ArrayList<>();

  // Constructor, getter và setter
  // ...

  @Override
  public double getTime() {
    double time = 0;
    for (TaskItem task : subTasks) {
      time += task.getTime();
    }
    return time;
  }

  public void addTask(TaskItem taskItem) {
    subTasks.add(taskItem);
  }

  public void removeTask(TaskItem taskItem) {
    subTasks.remove(taskItem);
  }
}
```

### Sử dụng Composite Pattern

```java
public class MainApp {
  public static void main(String[] args) {
    Task task1 = new Task("Task 1", 50);
    Task task2 = new Task("Task 2", 34);
    Task task3 = new Task("Task 3", 65);
    Task task4 = new Task("Task 4", 23);

    ArrayList<TaskItem> subTasks = new ArrayList<>();
    subTasks.add(task1);
    subTasks.add(task2);

    Project project1 = new Project("Project 1", subTasks);

    subTasks = new ArrayList<>();
    subTasks.add(task3);
    subTasks.add(task4);

    Project project2 = new Project("Project 2", subTasks);

    ArrayList<TaskItem> projects = new ArrayList<>();
    projects.add(project1);
    projects.add(project2);

    Project mainProject = new Project("Main Project", projects);

    System.out.println("Total time for Main Project: " + mainProject.getTime());
  }
}
```

**Composite Pattern** cho phép bạn tính tổng thời gian của dự án chính (`Main Project`) dựa trên thời gian của từng công việc và các dự án con bên trong nó một cách dễ dàng.
