# Java SE 学习笔记

## 学习路线规划

### 第一阶段：Java基础
1. **变量、数据类型、运算符** ✅
2. **控制流程语句** ✅
3. **数组** ✅

### 第二阶段：面向对象核心 ⭐⭐⭐
4. **类与对象** ✅
5. **封装、继承、多态** ✅ ⭐⭐⭐
6. **抽象类与接口** ✅ ⭐⭐⭐

### 第三阶段：Java高级特性
7. **异常处理** ✅
8. **常用类（String、包装类）** ✅
9. **IO流** ✅
10. **多线程** ✅
11. **网络编程** ✅
12. **反射与注解** ✅

---

## 知识点详解

### 1. 变量、数据类型、运算符 ✅

#### 1.1 变量

**变量**是存储数据的基本单元，就像一个带标签的盒子。

**声明和初始化：**
```java
// 方式1：先声明后赋值
int age;
age = 25;

// 方式2：声明时直接初始化（推荐）
String name = "张三";
double height = 1.75;
```

**命名规则：**
- 由字母、数字、下划线、$组成
- 不能以数字开头
- 不能使用Java保留字（如 `if`、`class`、`public` 等）
- 建议使用有意义的名称（驼峰命名法：`studentName`）

#### 1.2 数据类型

Java是**强类型语言**，数据类型分为两大类：

**基本数据类型（8种）：**

| 数据类型 | 关键字 | 占用空间 | 取值范围 | 示例 |
|---------|--------|---------|---------|------|
| 字节型 | byte | 1字节 | -128 ~ 127 | `byte b = 100;` |
| 短整型 | short | 2字节 | -32768 ~ 32767 | `short s = 1000;` |
| 整型 | int | 4字节 | -21亿 ~ 21亿 | `int i = 100000;` |
| 长整型 | long | 8字节 | 很大范围 | `long l = 100000L;` |
| 单精度浮点 | float | 4字节 | 小数 | `float f = 3.14f;` |
| 双精度浮点 | double | 8字节 | 高精度小数 | `double d = 3.14159;` |
| 字符型 | char | 2字节 | 单个字符 | `char c = 'A';` |
| 布尔型 | boolean | 1字节 | true/false | `boolean flag = true;` |

**引用数据类型：**
- String（字符串）：`String name = "Hello";`
- 数组、类、接口等

**类型转换：**
```java
// 自动类型转换（从小到大，安全）
int i = 100;
double d = i;  // int自动转为double

// 强制类型转换（从大到小，可能丢失精度）
double pi = 3.14159;
int num = (int) pi;  // 结果为3
```

#### 1.3 运算符

**算术运算符：**
```java
int a = 10, b = 3;
a + b   // 加法：13
a - b   // 减法：7
a * b   // 乘法：30
a / b   // 除法：3（整数除法）
a % b   // 取余：1
++a     // 自增：先加1再使用
a++     // 自增：先使用再加1
```

**关系运算符：**
```java
5 > 3    // true
5 < 3    // false
5 >= 5   // true
5 == 5   // true（注意是两个等号！）
5 != 3   // true
```

**逻辑运算符：**
```java
true && false  // 短路与：false
true || false  // 短路或：true
!true          // 逻辑非：false
```

**赋值运算符：**
```java
num += 5;   // 等价于 num = num + 5
num -= 3;   // 等价于 num = num - 3
num *= 2;   // 等价于 num = num * 2
```

**三元运算符：**
```java
// 语法：条件 ? 值1 : 值2
int max = (a > b) ? a : b;
```

#### 1.4 练习示例
```java
package t1;

public class Main {
    public static void main(String[] args) {
        String name = "Trae";
        int age = 1;
        double height = 1.2;
        boolean isStudent = false;
        double weight = 65;

        System.out.println("十年后的年龄：" + (age + 10));

        // 计算BMI
        double bmi = weight / (height * height);
        System.out.println("BMI：" + bmi);

        // 判断是否成年
        boolean isAdult = age >= 18;
        System.out.println("是否成年：" + isAdult);
    }
}
```

---

### 2. 控制流程语句 ✅

控制流程语句用于控制程序的执行顺序，让程序能够根据条件做出决策或重复执行某些操作。

#### 2.1 顺序结构

代码从上到下依次执行：

```java
int a = 10;
int b = 20;
int c = a + b;  // 先计算a+b，再赋值给c
System.out.println(c);  // 输出30
```

#### 2.2 分支结构

**if 语句：**

```java
// 单分支
if (条件) {
    // 条件为true时执行
}

// 双分支
if (条件) {
    // 条件为true时执行
} else {
    // 条件为false时执行
}

// 多分支
if (条件1) {
    // 条件1为true时执行
} else if (条件2) {
    // 条件2为true时执行
} else {
    // 所有条件都不满足时执行
}
```

**switch 语句：**

```java
switch (表达式) {
    case 值1:
        // 执行代码
        break;
    case 值2:
        // 执行代码
        break;
    default:
        // 所有case都不匹配时执行
        break;
}
```

**注意：每个case后面要加 `break`，否则会"穿透"执行下一个case！**

#### 2.3 循环结构

**for 循环：**

```java
for (初始化; 条件判断; 更新) {
    // 循环体
}

// 示例：打印1到5
for (int i = 1; i <= 5; i++) {
    System.out.println(i);
}

// 计算1到100偶数的和
int sum = 0;
for (int i = 1; i <= 100; i++) {
    if (i % 2 == 0) {
        sum += i;
    }
}
```

**while 循环：**

```java
while (条件) {
    // 循环体
}
```

**do...while 循环：**

```java
do {
    // 循环体
} while (条件);  // 先执行一次，再判断条件
```

**break 和 continue：**

- `break`：跳出整个循环
- `continue`：跳过本次循环，继续下一次

#### 2.4 嵌套循环

循环内部再包含循环：

```java
// 打印直角三角形
for (int i = 1; i <= 5; i++) {
    for (int j = 1; j <= i; j++) {
        System.out.print('*');
    }
    System.out.println();
}
```

#### 2.5 练习示例
```java
package t2;

public class Main {
    public static void main(String[] args) {
        func1();           // 输出：2550（偶数和）
        func2();           // 输出：15（累加超过100时的数字）
        func3(91);         // 输出：优秀
        func4();           // 打印三角形
    }

    public static void func1() {
        int sum = 0;
        for (int i = 1; i <= 100; i++) {
            if (i % 2 == 0) {
                sum += i;
            }
        }
        System.out.println(sum);
    }

    public static void func2() {
        int sum = 0;
        int i = 1;
        while (true) {
            sum += i;
            if (sum > 100) {
                break;
            }
            i++;
        }
        System.out.println(i);
    }

    public static void func3(double score) {
        switch ((int)(score / 10)) {
            case 10:
            case 9:
                System.out.println("优秀");
                break;
            case 8:
                System.out.println("良好");
                break;
            case 7:
                System.out.println("一般");
                break;
            case 6:
                System.out.println("及格");
                break;
            default:
                System.out.println("不及格");
                break;
        }
    }

    public static void func4() {
        for (int i = 1; i <= 5; i++) {
            for (int j = 1; j <= i; j++) {
                System.out.print('*');
            }
            System.out.println();
        }
    }
}
```

输出结果：
```
2550
15
优秀
*
**
***
****
*****
```

---

### 3. 数组 ✅

**数组**是用于存储多个相同类型数据的容器，就像一排连续的储物柜，每个柜子都有固定的编号（索引）。

#### 3.1 一维数组

**声明和初始化：**
```java
// 方式1：先声明，后赋值
int[] arr;
arr = new int[5];  // 创建长度为5的数组，元素默认值为0

// 方式2：声明时直接初始化
int[] arr2 = {1, 2, 3, 4, 5};

// 方式3：使用 new 关键字
int[] arr3 = new int[]{1, 2, 3, 4, 5};
```

**访问和遍历：**
```java
int[] arr = {10, 20, 30, 40, 50};

// 访问元素（索引从0开始）
System.out.println(arr[0]);  // 输出：10

// 普通for循环
for (int i = 0; i < arr.length; i++) {
    System.out.println(arr[i]);
}

// 增强for循环（foreach）
for (int num : arr) {
    System.out.println(num);
}
```

#### 3.2 二维数组

**声明和初始化：**
```java
// 方式1：指定行列
int[][] matrix = new int[3][4];  // 3行4列

// 方式2：直接初始化
int[][] matrix2 = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};
```

**遍历：**
```java
for (int i = 0; i < matrix.length; i++) {
    for (int j = 0; j < matrix[i].length; j++) {
        System.out.print(matrix[i][j] + " ");
    }
    System.out.println();
}
```

#### 3.3 Arrays工具类

```java
import java.util.Arrays;

int[] arr = {3, 1, 4, 1, 5, 9, 2, 6};

Arrays.toString(arr);      // 转字符串：[3, 1, 4, 1, 5, 9, 2, 6]
Arrays.sort(arr);          // 排序
Arrays.fill(arr, 10);     // 填充
Arrays.copyOf(arr, 10);   // 复制（可扩容）
Arrays.binarySearch(arr, 5);  // 二分查找（需先排序）
```

#### 3.4 练习示例
```java
package t3;

import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        func1();
        func2();
        func3();
    }

    public static void func1() {
        int[] num = new int[10];
        int sum = 0;
        int maxx = Integer.MIN_VALUE;  // 初始为最小值
        int minn = Integer.MAX_VALUE;  // 初始为最大值

        for (int i = 0; i < num.length; i++) {
            num[i] = i + 1;
            sum += num[i];
            maxx = Math.max(maxx, num[i]);
            minn = Math.min(minn, num[i]);
        }

        double avg = (double) sum / num.length;
        System.out.println("和：" + sum);
        System.out.println("平均数：" + avg);
        System.out.println("最大值：" + maxx);
        System.out.println("最小值：" + minn);
    }

    public static void func2() {
        int[] num = {5, 2, 8, 1, 9, 3, 7, 4, 6};
        Arrays.sort(num);

        for (int i = 0; i < num.length; i++) {
            System.out.print(num[i] + " ");
        }
        System.out.println();

        int idx = Arrays.binarySearch(num, 7);
        System.out.println("7的索引为：" + idx);
    }

    public static void func3() {
        int[][] num = new int[3][3];
        for (int i = 1; i <= 9; i++) {
            int row = (i - 1) / 3;
            int col = (i - 1) % 3;
            num[row][col] = i;
        }

        int sum = 0;
        for (int i = 0; i < num.length; i++) {
            for (int j = 0; j < num[i].length; j++) {
                System.out.print(num[i][j] + " ");
                if (i == j) {
                    sum += num[i][j];  // 主对角线求和
                }
            }
            System.out.println();
        }
        System.out.println("主对角线和：" + sum);
    }
}
```

输出结果：
```
和：55
平均数：5.5
最大值：10
最小值：1
1 2 3 4 5 6 7 8 9 
7的索引为：6
1 2 3 
4 5 6 
7 8 9 
主对角线和：15
```

---

### 4. 类与对象 ✅

**类**是对一类事物的抽象描述，是创建对象的模板。**对象**是类的具体实例。

#### 4.1 类的定义

```java
public class 类名 {
    // 属性（成员变量）
    // 方法（成员方法）
}
```

#### 4.2 成员变量 vs 局部变量

| 区别 | 成员变量 | 局部变量 |
|-----|---------|---------|
| 定义位置 | 类中，方法外 | 方法内部 |
| 默认值 | 有默认值 | 无默认值 |
| 作用域 | 整个类 | 当前方法 |
| 内存 | 堆内存 | 栈内存 |

#### 4.3 构造方法

- 方法名**必须与类名相同**
- **没有返回值类型**
- 用于初始化对象

```java
public class Student {
    String name;
    int age;

    // 无参构造
    public Student() {
    }

    // 有参构造
    public Student(String name, int age) {
        this.name = name;
        this.age = age;
    }
}
```

#### 4.4 this关键字

`this` 指向当前对象，用于区分成员变量和局部变量：

```java
public Student(String name, int age) {
    this.name = name;  // this.name = 成员变量，name = 参数
    this.age = age;
}
```

#### 4.5 练习示例
```java
// Phone.java
package t4;

public class Phone {
    private String brand;
    private double price;
    private String color;

    public Phone() {
    }

    public Phone(String brand, double price, String color) {
        this.brand = brand;
        this.price = price;
        this.color = color;
    }

    public void call(String name) {
        System.out.println("正在给" + name + "打电话");
    }

    public void sendMessage(String content) {
        System.out.println("正在给" + content + "发短信");
    }

    public void showInfo() {
        System.out.println("手机品牌是：" + brand +
                "，价格是：" + price +
                "，颜色是：" + color);
    }

    public String getBrand() {
        return brand;
    }

    public void setBrand(String brand) {
        this.brand = brand;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }
}
```

```java
// Main.java
package t4;

public class Main {
    public static void main(String[] args) {
        // 使用无参构造
        Phone p1 = new Phone();
        p1.setBrand("华为");
        p1.setPrice(1999);
        p1.setColor("蓝色");
        p1.showInfo();
        p1.call("任正非");

        // 使用有参构造
        Phone p2 = new Phone("三星", 2999, "黑色");
        p2.showInfo();
        p2.call("三星创始人");
    }
}
```

输出结果：
```
手机品牌是：华为，价格是：1999.0，颜色是：蓝色
正在给任正非打电话
手机品牌是：三星，价格是：2999.0，颜色是：黑色
正在给三星创始人打电话
```

---

5. **封装、继承、多态** ✅ ⭐⭐⭐

### 面向对象三大特性

#### 5.1 封装（Encapsulation）

**把东西包装起来，对外只暴露必要的接口，隐藏内部实现细节。**

**实现方式：**
1. `private` 修饰属性（隐藏）
2. `public` 提供 getter/setter（受控访问）

```java
public class Person {
    private String name;
    private int age;

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        if (age < 0 || age > 150) {
            System.out.println("年龄不合法！");
            return;
        }
        this.age = age;
    }
}
```

**封装的好处：** 数据安全、数据隐藏、易于维护

#### 5.2 继承（Inheritance）

**子类继承父类，获得父类的属性和方法。**

**语法：** `class 子类 extends 父类 {}`

```java
public class Animal {
    public String name;
    public void eat() {
        System.out.println("动物在吃东西");
    }
}

public class Dog extends Animal {
    public void bark() {
        System.out.println("狗在汪汪叫");
    }
}
```

**方法重写（Override）：** 子类重写父类方法

```java
public class Cat extends Animal {
    @Override
    public void eat() {
        System.out.println("猫在吃鱼");
    }
}
```

**super关键字：** 访问父类成员

```java
public class Dog extends Animal {
    @Override
    public void eat() {
        super.eat();  // 调用父类的 eat()
        System.out.println("狗在吃狗粮");
    }
}
```

**继承特点：**
- 单继承：一个类只能有一个直接父类
- 子类不能继承父类的构造方法，但可以用 `super()` 调用

#### 5.3 多态（Polymorphism）

**同一个方法调用，不同对象产生不同行为。**

**三个必要条件：**
1. 继承
2. 重写
3. 向上转型（父类引用指向子类对象）

```java
// 向上转型
Animal a1 = new Dog();
Animal a2 = new Cat();
a1.eat();  // 输出：狗在吃狗粮
a2.eat();  // 输出：猫在吃猫粮
```

**向下转型：** 调用子类特有方法

```java
Animal animal = new Dog();
Dog dog = (Dog) animal;  // 向下转型
dog.bark();

// 用 instanceof 检查类型
if (animal instanceof Dog) {
    Dog d = (Dog) animal;
    d.bark();
}
```

#### 5.4 练习示例
```java
// Person.java
package t5;

public class Person {
    private String name;
    private int age;

    public void work() {
        System.out.println("人在工作");
    }

    public Person() {
    }

    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }
}
```

```java
// Teacher.java
package t5;

public class Teacher extends Person {
    public Teacher() {
    }

    public Teacher(String name, int age) {
        super(name, age);
    }

    @Override
    public void work() {
        System.out.println("老师在教学");
    }

    public void teach() {
        System.out.println("老师上Python课");
    }
}
```

```java
// Student.java
package t5;

public class Student extends Person {
    public Student() {
    }

    public Student(String name, int age) {
        super(name, age);
    }

    @Override
    public void work() {
        System.out.println("学生在学习");
    }

    public void study() {
        System.out.println("学生在学习Python");
    }
}
```

```java
// Main.java
package t5;

public class Main {
    public static void main(String[] args) {
        // 向上转型：多态
        Person p1 = new Teacher("Trae", 1);
        Person p2 = new Student("Cursor", 2);

        p1.work();  // 输出：老师在教学
        p2.work();  // 输出：学生在学习

        // 向下转型：调用子类特有方法
        if (p1 instanceof Teacher) {
            Teacher t = (Teacher) p1;
            t.teach();  // 输出：老师上Python课
        }

        if (p2 instanceof Student) {
            Student s = (Student) p2;
            s.study();  // 输出：学生在学习Python
        }
    }
}
```

---

### 6. 抽象类与接口 ✅ ⭐⭐⭐

#### 6.1 抽象类（Abstract Class）

**抽象类是不能直接实例化的类，用于被子类继承。**

**特点：**
- 用 `abstract` 修饰
- 可以有抽象方法（没有方法体）
- 也可以有普通方法
- 不能直接创建对象（`new`）
- 子类必须重写所有抽象方法

```java
public abstract class Animal {
    protected String name;

    public Animal(String name) {
        this.name = name;
    }

    public abstract void eat();  // 抽象方法

    public void sleep() {         // 普通方法
        System.out.println(name + "在睡觉");
    }
}
```

#### 6.2 接口（Interface）

**接口是一种更纯粹的抽象，只定义行为，不关心实现。**

**特点：**
- 用 `interface` 修饰
- 接口中的方法默认是抽象的
- 类用 `implements` 实现接口
- 一个类可以实现多个接口
- JDK8后可以有默认方法和静态方法

```java
public interface Playable {
    void play();  // 抽象方法
}
```

#### 6.3 抽象类 vs 接口

| 区别 | 抽象类 | 接口 |
|-----|-------|-----|
| 关键字 | `abstract class` | `interface` |
| 继承/实现 | `extends` | `implements` |
| 多继承 | ❌ 不支持 | ✅ 支持多实现 |
| 方法 | 抽象 + 普通 | 默认抽象，JDK8+有默认方法 |
| 属性 | 任意属性 | 只能是常量 |
| 构造方法 | ✅ 有 | ❌ 没有 |

**选择原则：**
- **"是一个"的关系** → 用抽象类（Dog is an Animal）
- **"能做什么"的功能** → 用接口（Drawable, Clickable）

#### 6.4 练习示例
```java
// Playable.java - 接口
package t6;

public interface Playable {
    void play();
}
```

```java
// Pet.java - 抽象类
package t6;

public abstract class Pet {
    private String name;
    private int age;

    public Pet() {
    }

    public Pet(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public abstract void eat();

    public void sleep() {
        System.out.println("正在睡觉~~~");
    }
}
```

```java
// Cat.java
package t6;

public class Cat extends Pet implements Playable {
    public Cat() {
        super();
    }

    public Cat(String name, int age) {
        super(name, age);
    }

    @Override
    public void eat() {
        System.out.println("猫吃猫粮");
    }

    @Override
    public void play() {
        System.out.println("猫玩毛线球");
    }
}
```

```java
// Dog.java
package t6;

public class Dog extends Pet implements Playable {
    public Dog() {
        super();
    }

    public Dog(String name, int age) {
        super(name, age);
    }

    @Override
    public void eat() {
        System.out.println("狗吃骨头");
    }

    @Override
    public void play() {
        System.out.println("狗玩飞盘");
    }
}
```

```java
// Main.java
package t6;

public class Main {
    public static void main(String[] args) {
        Pet p1 = new Cat("哈基米", 3);
        Pet p2 = new Dog("哈基汪", 2);

        p1.eat();
        p1.sleep();
        ((Playable) p1).play();

        p2.eat();
        p2.sleep();
        ((Playable) p2).play();
    }
}
```

输出结果：
```
猫吃猫粮
正在睡觉~~~
猫玩毛线球
狗吃骨头
正在睡觉~~~
狗玩飞盘
```

---

### 7. 异常处理 ✅

**异常**是程序运行过程中发生的错误，Java提供了完善的异常处理机制。

#### 7.1 异常的分类

```
Throwable
├── Error（错误）：程序无法处理，如内存溢出
└── Exception（异常）：程序可以处理
    ├── RuntimeException（运行时异常）：空指针、数组越界
    └── 其他异常（编译时异常）：IO异常、网络异常
```

#### 7.2 异常处理方式

**try...catch...finally：**
```java
try {
    // 可能出现异常的代码
} catch (异常类型 e) {
    e.printStackTrace();  // 处理异常
} finally {
    // 无论是否异常都会执行
}
```

**throw 和 throws：**
```java
// throw：手动抛出异常
public void setAge(int age) {
    if (age < 0) {
        throw new IllegalArgumentException("年龄不能为负数");
    }
}

// throws：声明异常
public void readFile() throws IOException {
    // 代码
}
```

#### 7.3 练习示例
```java
// Calculator.java
package t7;

public class Calculator {
    public double divide(int a, int b) {
        if (b == 0) {
            throw new ArithmeticException("除数不能为零");
        }
        return a / b;
    }
}
```

```java
// Student.java
package t7;

public class Student {
    private String name;
    private int age;

    public Student() {
    }

    public Student(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        if (age < 0 || age > 150) {
            throw new IllegalArgumentException("年龄输入错误");
        }
        this.age = age;
    }
}
```

```java
// Main.java
package t7;

public class Main {
    public static void main(String[] args) {
        Calculator c = new Calculator();

        try {
            System.out.println(c.divide(10, 0));
        } catch (ArithmeticException e) {
            e.printStackTrace();
        }

        Student s2 = new Student();
        s2.setAge(20);
        System.out.println(s2.getAge());

        Student s1 = new Student();
        try {
            s1.setAge(-5);
            System.out.println(s1.getAge());
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
```

---

### 8. 常用类（String、包装类）✅

#### 8.1 String类

**String的创建方式：**
```java
// 直接赋值（字符串常量池）
String s1 = "hello";

// new创建（堆内存）
String s2 = new String("hello");
```

**常用方法：**
```java
String s = "Hello Java";

s.length();                      // 长度
s.charAt(0);                     // 获取字符
s.indexOf("Java");              // 查找子串位置
s.toUpperCase();                // 转大写
s.toLowerCase();                // 转小写
s.replace("Java", "Python");    // 替换
s.substring(6);                 // 截取
s.split(" ");                   // 分割
s.equals("hello java");         // 比较内容
s.startsWith("He");            // 是否以...开头
s.contains("World");           // 是否包含
```

**StringBuilder（可变字符串）：**
```java
StringBuilder sb = new StringBuilder();
sb.append("hello");
sb.append(" world");
sb.reverse();
System.out.println(sb.toString());
```

#### 8.2 包装类

**基本类型对应的包装类：**
| 基本类型 | 包装类 |
|---------|--------|
| int | Integer |
| double | Double |
| char | Character |
| boolean | Boolean |
| ... | ... |

**自动装箱和拆箱：**
```java
Integer i = 10;      // 自动装箱
int n = i;           // 自动拆箱
```

**字符串转换：**
```java
int num = Integer.parseInt("123");  // String → int
String str = String.valueOf(123);    // int → String
```

#### 8.3 练习示例
```java
package t8;

public class Main {
    public static void main(String[] args) {
        func1();
        System.out.println(stringReverse("abcde"));
        func2();
        func3();
    }

    public static void func1() {
        String s = "Hello java";
        System.out.println("s的长度为：" + s.length());
        System.out.println("全部转为大写：" + s.toUpperCase());
        String s1 = s.replace("java", "python");
        System.out.println("替换后的字符串为：" + s1);
        boolean startWithHello = s.startsWith("Hello");
        System.out.println("是否以Hello开头：" + startWithHello);
        int indexJava = s.indexOf("java");
        String re = s.substring(indexJava, indexJava + "java".length());
        System.out.println("截取java的结果：" + re);
    }

    public static String stringReverse(String s) {
        StringBuilder sb = new StringBuilder(s);
        sb.reverse();
        return sb.toString();
    }

    public static void func2() {
        String s = "hello world hello java hello";
        int indexHello = 0, cntL = 0, cntHello = 0;

        while ((indexHello = s.indexOf("hello", indexHello)) != -1) {
            cntHello++;
            indexHello += "hello".length();
        }
        System.out.println("hello出现的次数为：" + cntHello);

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'l') {
                cntL++;
            }
        }
        System.out.println("l出现的次数为：" + cntL);
    }

    public static void func3() {
        String s = "123";
        int si = Integer.parseInt(s) + 100;
        System.out.println(si);

        int i = 100;
        String is = Integer.toString(i) + "是个数字";
        System.out.println(is);
    }
}
```

---

### 9. IO流 ✅

**IO流**用于处理输入输出操作，包括文件的读写、数据的传输等。

#### 9.1 IO流的分类

```
IO流
├── 输入流（Input）：读取数据到程序
└── 输出流（Output）：把数据从程序写出

字节流（处理任意文件）
├── InputStream
└── OutputStream

字符流（处理文本文件）
├── Reader
└── Writer
```

#### 9.2 常用流类

| 流类 | 说明 |
|-----|------|
| FileInputStream/FileOutputStream | 字节流文件读写 |
| FileReader/FileWriter | 字符流文件读写 |
| BufferedReader/BufferedWriter | 缓冲流，高效读写 |

#### 9.3 try-with-resources（自动关闭流）

```java
try (BufferedReader br = new BufferedReader(new FileReader("file.txt"));
     BufferedWriter bw = new BufferedWriter(new FileWriter("output.txt"))) {
    
    String line;
    while ((line = br.readLine()) != null) {
        bw.write(line);
        bw.newLine();
    }
    
} catch (IOException e) {
    e.printStackTrace();
}
```

#### 9.4 练习示例
```java
package A1;

import java.io.*;

public class Main {
    public static void main(String[] args) {
        // 写入文件
        try (BufferedWriter bw = new BufferedWriter(
                new FileWriter("note\\src\\A1\\hello.txt", true))) {
            bw.write("Hello Java!");
            bw.newLine();
            bw.write("这是第二行内容。");
            bw.newLine();
        } catch (Exception e) {
            e.printStackTrace();
        }

        // 读取并显示文件
        try (BufferedReader br = new BufferedReader(
                new FileReader("note\\src\\A1\\hello.txt"))) {
            String line;
            while ((line = br.readLine()) != null) {
                System.out.println(line);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }

        // 文件复制
        try (BufferedReader br = new BufferedReader(
                new FileReader("note\\src\\A1\\hello.txt"));
             BufferedWriter bw = new BufferedWriter(
                new FileWriter("note\\src\\A1\\tar.txt"))) {
            String line;
            while ((line = br.readLine()) != null) {
                bw.write(line);
                bw.newLine();
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
```

---

### 10. 多线程 ✅

**多线程**允许程序同时执行多个任务，提高效率和响应能力。

#### 10.1 进程与线程

- **进程**：正在运行的程序（如：打开一个QQ）
- **线程**：进程中的执行单元（如：QQ同时聊天、传文件、听音乐）

#### 10.2 线程的创建方式

**方式1：继承Thread类**
```java
class MyThread extends Thread {
    @Override
    public void run() {
        // 线程任务
    }
}
Thread t = new MyThread();
t.start();
```

**方式2：实现Runnable接口（推荐）**
```java
class MyRunnable implements Runnable {
    @Override
    public void run() {
        // 线程任务
    }
}
Thread t = new Thread(new MyRunnable());
t.start();
```

#### 10.3 线程同步（synchronized）

多个线程访问共享资源时，需要同步防止数据安全问题。

```java
synchronized (this) {
    if (tickets > 0) {
        System.out.println(name + "卖出第" + tickets + "张票");
        tickets--;
    }
}
```

#### 10.4 练习示例
```java
package A2;

// 打印数字的线程
class MyThread1 extends Thread {
    @Override
    public void run() {
        for (int i = 1; i <= 10; i++) {
            System.out.println("线程" + getName() + " " + i);
        }
    }
}

// 打印字母的线程
class MyThread2 extends Thread {
    @Override
    public void run() {
        for (int i = 0; i < 'J' - 'A' + 1; i++) {
            System.out.println("线程" + getName() + " " + (char) ('A' + i));
        }
    }
}

// 抢票系统
class MyRunnable implements Runnable {
    private int count = 100;
    private int now = 1;

    @Override
    public void run() {
        String name = Thread.currentThread().getName();
        while (true) {
            synchronized (this) {
                if (now <= count) {
                    System.out.println(name + "售出了第" + now + "张票。");
                    now++;
                } else {
                    break;
                }
            }
            try {
                Thread.sleep(10);
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }
}

public class Main {
    public static void main(String[] args) {
        MyThread1 t1 = new MyThread1();
        MyThread2 t2 = new MyThread2();
        t1.start();
        t2.start();

        MyRunnable r = new MyRunnable();
        Thread ticket1 = new Thread(r, "北京站");
        Thread ticket2 = new Thread(r, "上海站");
        Thread ticket3 = new Thread(r, "天津站");
        ticket1.start();
        ticket2.start();
        ticket3.start();
    }
}
```

---

### 11. 网络编程 ✅

**网络编程**让程序通过网络进行通信，实现客户端和服务器的数据交换。

#### 11.1 网络通信基础概念

**生活中的例子 - 打电话：**
```
你（客户端）                        朋友（服务器）
   |                                    |
   |-- 拨号连接（connect）-------------->|
   |                                    |
   |<-- 接通（accept）------------------|
   |                                    |
   |-- 说:你好（发送数据）------------->|
   |                                    |
   |<-- 回应:你好（接收数据）-----------|
   |                                    |
   |-- 挂电话（关闭连接）-------------->|
```

**核心概念：**
- **IP地址**：设备的唯一标识（如：192.168.1.1）
- **端口号**：应用程序的唯一标识（0-65535）
- **Socket（套接字）**：电话号码 = IP + 端口

#### 11.2 TCP三次握手四次挥手

```
三次握手（建立连接）：
客户端 -------- SYN -------------> 服务器
客户端 <------- SYN+ACK ----------- 服务器
客户端 -------- ACK -------------> 服务器
    【连接建立完成】

四次挥手（断开连接）：
客户端 -------- FIN -------------> 服务器
客户端 <------- ACK --------------- 服务器
客户端 <------- FIN --------------- 服务器
客户端 -------- ACK -------------> 服务器
    【连接断开完成】
```

#### 11.3 TCP通信原理

```
客户端                          服务器
  |                              |
  |------- new Socket(IP,端口) -->|
  |                              |
  |<------- accept() ------------|
  |                              |
  |------- 发送数据 ------------->|
  |                              |
  |<------- 接收数据 ------------|
  |                              |
  |------- close() ------------->|
```

#### 11.4 TCP通信核心代码

**重要：Socket管道只能传字节！**

**服务器端（ServerSocket）：**
```java
// 1. 创建服务器，监听端口
ServerSocket server = new ServerSocket(端口);

// 2. 等待客户端连接（阻塞）
Socket client = server.accept();

// 3. 获取输入流（收消息）
InputStream is = client.getInputStream();
BufferedReader reader = new BufferedReader(new InputStreamReader(is));

// 4. 获取输出流（发消息）
OutputStream os = client.getOutputStream();
PrintWriter writer = new PrintWriter(os, true);

// 5. 关闭资源
client.close();
server.close();
```

**客户端（Socket）：**
```java
// 1. 连接服务器
Socket socket = new Socket("服务器IP", 端口);

// 2. 获取输出流（发消息）
OutputStream os = socket.getOutputStream();
PrintWriter writer = new PrintWriter(os, true);

// 3. 获取输入流（收消息）
InputStream is = socket.getInputStream();
BufferedReader reader = new BufferedReader(new InputStreamReader(is));

// 4. 关闭资源
socket.close();
```

#### 11.5 练习示例（你的代码）

```java
// SimpleServer.java
package A3;

import java.io.*;
import java.net.*;

public class SimpleServer {
    public static void main(String[] args) {
        ServerSocket ss = null;
        Socket s = null;

        try {
            ss = new ServerSocket(9999);
            System.out.println("===服务器启动===");
            s = ss.accept();
            System.out.println("===服务器已连接===");

            BufferedReader br = new BufferedReader(
                new InputStreamReader(s.getInputStream()));
            String msg = br.readLine();
            System.out.println("===服务器已接收消息：" + msg + "===");

            PrintWriter writer = new PrintWriter(s.getOutputStream(), true);
            writer.println("收到消息：" + msg);

        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            System.out.println("===服务器已关闭===");
            try {
                if (s != null) s.close();
                if (ss != null) ss.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}
```

```java
// Client.java
package A3;

import java.io.*;
import java.net.*;

public class Client {
    public static void main(String[] args) {
        Socket s = null;

        try {
            System.out.println("===客户端启动===");
            s = new Socket("localhost", 9999);
            System.out.println("===服务器已连接===");

            PrintWriter pw = new PrintWriter(s.getOutputStream(), true);
            pw.println("hello,server");

            BufferedReader br = new BufferedReader(
                new InputStreamReader(s.getInputStream()));
            String response = br.readLine();
            System.out.println("===服务器回应：" + response + "===");

        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            try {
                if (s != null) s.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}
```

**运行步骤：**
1. 先运行 `SimpleServer` → 输出：`===服务器启动===`（等待中...）
2. 再运行 `Client` → 输出：`===客户端启动===` 和 `===服务器已连接===`
3. 服务器端输出：`===服务器已连接===` 和 `===服务器已接收消息：hello,server===`

#### 11.6 你的代码亮点

1. **资源管理意识强** - try-catch-finally 结构完整
2. **理解Socket通信原理** - "socket管道只能传字节"这个概念很到位！
3. **使用装饰流** - BufferedReader、InputStreamReader、PrintWriter 组合使用
4. **代码规范** - 变量命名清晰，注释明确

---

#### 11.7 TCP一传多（多线程聊天）

**一传一的问题：** 只能服务一个客户端

**一传多的原理：** 为每个客户端创建新线程

```
客户端1 ─────────────────────┐
客户端2 ───> 服务器 ──────────┼──> 线程1、线程2、线程3
客户端3 ─────────────────────┘
```

**服务器端（多线程版本）：**

```java
// MultiServer.java
package A4_TCP;

import java.net.*;
import java.io.*;

public class MultiServer {
    public static void main(String[] args) {
        ServerSocket ss = null;

        try {
            ss = new ServerSocket(9999);
            System.out.println("===服务器已启动===");
            while (true) {
                // 等待客户端连接（阻塞）
                Socket s = ss.accept();
                System.out.println("客户端连接：" + s.getPort());
                // 为每个客户端创建新线程处理
                new Thread(new clientThread(s)).start();
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    // 处理客户端的内部类
    public static class clientThread implements Runnable {
        private Socket s;

        public clientThread(Socket s) {
            this.s = s;
        }

        public void run() {
            // 使用try-with-resources自动关闭资源
            try (
                    InputStream is = s.getInputStream();
                    InputStreamReader isr = new InputStreamReader(is);
                    BufferedReader br = new BufferedReader(isr);

                    OutputStream os = s.getOutputStream();
                    OutputStreamWriter osw = new OutputStreamWriter(os);
                    PrintWriter pw = new PrintWriter(osw, true)
            ) {
                String msg;
                while ((msg = br.readLine()) != null) {
                    if (msg.equals("exit")) {
                        System.out.println("客户端" + s.getInetAddress() + "已退出");
                        break;
                    }
                    pw.println("===服务器收到" + s.getPort() + "消息===");
                    System.out.println("===服务器收到" + s.getPort() + "消息===" + msg);
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }
}
```

**客户端：**

```java
// MultiClient.java
package A4_TCP;

import java.io.*;
import java.net.*;
import java.util.Scanner;

public class MultiClient {
    public static void main(String[] args) {
        Socket s = null;
        try {
            s = new Socket("localhost", 9999);

            InputStream is = s.getInputStream();
            InputStreamReader isr = new InputStreamReader(is);
            BufferedReader br = new BufferedReader(isr);

            OutputStream os = s.getOutputStream();
            OutputStreamWriter osw = new OutputStreamWriter(os);
            PrintWriter pw = new PrintWriter(osw, true);

            Scanner sc = new Scanner(System.in);

            // 接收消息（启动新线程）
            Thread receive = new Thread(() -> {
                try {
                    String response;
                    while ((response = br.readLine()) != null) {
                        System.out.println("服务器回应：" + response);
                    }
                } catch (Exception e) {
                    System.out.println("连接已断开");
                }
            });
            receive.start();

            // 发送消息
            String msg;
            System.out.println("===用户" + s.getLocalPort() + "请输入消息(exit退出):");
            while ((msg = sc.nextLine()) != null) {
                if (msg.equals("exit")) {
                    System.out.println("已退出===");
                    pw.println(s.getLocalPort() + "已离线！");
                    break;
                }
                pw.println(msg);
            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            try {
                if (s != null) {
                    s.close();
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }
}
```

**运行步骤：**
1. 运行 `MultiServer` → 服务器启动
2. 运行 `MultiClient` 多次 → 启动多个客户端
3. 每个客户端都可以独立聊天

**你的代码亮点：**
- 使用**Lambda表达式**启动接收线程 ✅
- **内部类**封装客户端处理逻辑 ✅
- **PrintWriter的autoFlush** - `new PrintWriter(osw, true)` 中的 `true` 表示自动刷新 ✅

---

#### 11.8 UDP通信

**UDP vs TCP对比：**

| 特性 | TCP | UDP |
|-----|-----|-----|
| 连接 | 面向连接（打电话） | 无连接（发短信） |
| 可靠性 | 可靠 | 不可靠，可能丢包 |
| 速度 | 较慢 | 较快 |
| 数据单位 | 字节流 | 数据报（DatagramPacket） |
| 适用场景 | 文件传输、聊天 | 视频通话、游戏 |

**发送端：**

```java
// UDPSender.java
package A5_UDP;

import java.io.*;
import java.net.*;
import java.util.*;

public class UDPSender {
    public static void main(String[] args) {
        DatagramSocket socket = null;
        Scanner sc = new Scanner(System.in);

        try {
            socket = new DatagramSocket();
            System.out.println("===请输入发送的信息===");
            String msg = sc.nextLine();

            // 将字符串转换为字节数组
            byte[] data = msg.getBytes("UTF-8");

            // 创建数据包，指定目标地址和端口
            InetAddress address = InetAddress.getByName("localhost");
            DatagramPacket packet = new DatagramPacket(
                data,
                data.length,
                address,
                9999
            );

            // 发送数据包
            socket.send(packet);
            System.out.println("发送成功：" + msg);

            // 接收响应
            byte[] buf = new byte[1024 * 8];
            DatagramPacket dp = new DatagramPacket(buf, buf.length);
            socket.receive(dp);

            String response = new String(
                dp.getData(),
                0,
                dp.getLength(),
                "UTF-8"
            );
            System.out.println("收到来自" + dp.getAddress().getHostAddress() + "的消息：" + response);

        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            try {
                if (socket != null) {
                    socket.close();
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }
}
```

**接收端：**

```java
// UDPReceiver.java
package A5_UDP;

import java.net.DatagramPacket;
import java.net.DatagramSocket;

public class UDPReceiver {
    public static void main(String[] args) {
        DatagramSocket socket = null;
        try {
            // 创建UDP Socket，绑定端口
            socket = new DatagramSocket(9999);
            System.out.println("===UDP接收端启动(端口号" + socket.getLocalPort() + ")===");

            // 创建数据包容器（接收数据）
            byte[] buf = new byte[1024 * 8];
            DatagramPacket dp = new DatagramPacket(buf, buf.length);

            // 接收数据包（阻塞）
            socket.receive(dp);
            String msg = new String(
                dp.getData(),
                0,
                dp.getLength(),
                "UTF-8"
            );
            System.out.println("收到来自" + dp.getAddress().getHostAddress() + "的消息：" + msg);

            // 发送响应
            String response = "收到";
            byte[] buf2 = response.getBytes("UTF-8");
            DatagramPacket dp2 = new DatagramPacket(
                buf2,
                buf2.length,
                dp.getAddress(),  // 回复给发送者
                dp.getPort()      // 回复到发送者的端口
            );
            socket.send(dp2);
            System.out.println("已发送");

        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            if (socket != null) {
                socket.close();
            }
        }
    }
}
```

**UDP核心类说明：**
- **DatagramSocket**：UDP的Socket，类似TCP的ServerSocket/Socket
- **DatagramPacket**：数据包，封装了数据、目标地址、端口

**你的代码亮点：**
- 使用**Scanner**获取用户输入 ✅
- 正确的**UTF-8编码**处理中文 ✅
- **两处DatagramPacket参数不同**：
  - 第一个：空容器，用于**接收**
  - 第二个：有数据，用于**发送**，并指定回复目标 ✅

---

#### 11.9 TCP文件传输

**原理：** 读取本地文件，通过TCP发送

**服务器端（接收文件）：**

```java
// FileServer.java
package A6_TCP_FILE;

import java.io.*;
import java.net.*;

public class FileServer {
    public static void main(String[] args) {
        System.out.println("===文件服务器启动===");
        try (
            ServerSocket ss = new ServerSocket(9999);
            Socket s = ss.accept();
            FileOutputStream fos = new FileOutputStream("note\\src\\A6_TCP_FILE\\tar.txt");
            InputStream is = s.getInputStream();
            BufferedInputStream bis = new BufferedInputStream(is);
        ) {
            System.out.println("===服务器已启动===");
            System.out.println("客户端连接：" + s.getPort() + "准备接收文件");

            // 接收文件数据
            byte[] buf = new byte[1024 * 8];
            int len;
            while ((len = bis.read(buf)) != -1) {
                fos.write(buf, 0, len);
            }
            System.out.println("文件接收完毕");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
```

**客户端（发送文件）：**

```java
// FileClient.java
package A6_TCP_FILE;

import java.io.*;
import java.net.*;

public class FileClient {
    public static void main(String[] args) {
        try (
             Socket s = new Socket("localhost", 9999);
             OutputStream os = s.getOutputStream();
             BufferedOutputStream bos = new BufferedOutputStream(os);
             FileInputStream fis = new FileInputStream("note\\src\\A6_TCP_FILE\\lover.txt");
        ) {
            System.out.println("===客户端启动===");
            byte[] bf = new byte[1024 * 8];
            int len;
            while ((len = fis.read(bf)) != -1) {
                bos.write(bf, 0, len);
            }
            bos.flush();  // 确保数据发送出去
            System.out.println("文件发送完毕");

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
```

**你的代码亮点：**
- 使用**BufferedInputStream/BufferedOutputStream**提高传输效率 ✅
- **bos.flush()** 确保数据发送出去 ✅
- **try-with-resources** 自动管理资源 ✅

---

#### 11.10 网络编程总结

**你学到的内容：**

| 知识点 | 难度 | 代码实现 |
|-------|------|---------|
| TCP一传一 | ⭐ | SimpleServer + Client |
| TCP一传多 | ⭐⭐ | MultiServer + MultiClient |
| UDP通信 | ⭐⭐ | UDPSender + UDPReceiver |
| TCP文件传输 | ⭐⭐⭐ | FileServer + FileClient |

**核心类总结：**

| 类 | 作用 |
|----|------|
| ServerSocket | 服务器监听端口 |
| Socket | 客户端连接服务器/服务器与客户端通信 |
| DatagramSocket | UDP的Socket |
| DatagramPacket | UDP的数据包 |
| InputStream/OutputStream | 字节流输入/输出 |
| BufferedReader/PrintWriter | 字符流包装 |

---

### 12. 反射与注解 ✅

**反射与注解**是Java的高级特性，被广泛应用于框架开发（Spring、Hibernate等）。

#### 12.1 反射（Reflection）

**什么是反射？**

反射是Java提供的一种机制，允许程序在**运行时**动态获取类的信息，创建对象，调用方法，操作属性。

**生活中的例子：**
- 普通方式：像打电话，你知道要打给谁，知道他是做什么的
- 反射方式：像黑箱操作，你可以动态地探索对象的内部结构

**反射的核心类：**
```
Class：表示一个类的"镜子"
├── Field：表示属性
├── Method：表示方法
└── Constructor：表示构造方法
```

#### 12.2 获取Class对象的三种方式

```java
// 方式1：类名.class
Class<?> c1 = Student.class;

// 方式2：对象.getClass()
Student s = new Student();
Class<?> c2 = s.getClass();

// 方式3：Class.forName("全类名")
Class<?> c3 = Class.forName("com.example.Student");
```

#### 12.3 反射的基本操作

**创建对象：**
```java
Class<?> clazz = Class.forName("com.example.Student");
// 使用无参构造
Object obj = clazz.newInstance();

// 使用有参构造
Constructor<?> constructor = clazz.getConstructor(String.class, int.class);
Object obj2 = constructor.newInstance("张三", 20);
```

**调用方法：**
```java
Method method = clazz.getMethod("方法名", 参数类型.class);
method.invoke(obj, 参数值);
```

**操作属性：**
```java
Field field = clazz.getDeclaredField("属性名");
field.setAccessible(true); // 打破封装
field.set(obj, 值);
```

#### 12.4 注解（Annotation）

**什么是注解？**

注解是代码中的**标记**，就像给代码贴标签一样，不影响程序运行，但可以被编译器或框架读取。

**常见内置注解：**
```java
@Override   // 标记重写方法
@Deprecated  // 标记已过时
@SuppressWarnings  // 抑制警告
```

**自定义注解：**
```java
// 定义注解
@Target(ElementType.METHOD)        // 注解用在方法上
@Retention(RetentionPolicy.RUNTIME) // 运行时保留
public @interface MyAnnotation {
    String value() default "默认值";  // 注解属性
}

// 使用注解
@MyAnnotation("这是一个注解")
public void test() {
}
```

**注解属性类型：**
- 基本类型
- String
- Class
- 枚举
- 注解
- 以上类型的数组

#### 12.5 练习示例（你的代码）

**Person.java：**
```java
// B1/Person.java
package B1;

public class Person {
    private String name;
    private int age;

    @MyAnnotation
    public void showInfo() {
        System.out.println("姓名是：" + name +
                "，年龄是：" + age);
    }

    public Person() {
    }

    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }
}
```

**MyAnnotation.java（自定义注解）：**
```java
// B1/MyAnnotation.java
package B1;

import java.lang.annotation.ElementType;
import java.lang.annotation.*;

@Target(ElementType.METHOD)           // 作用范围：方法
@Retention(RetentionPolicy.RUNTIME)   // 保留到运行时
public @interface MyAnnotation {
    // 注解属性（可以定义多个）
}
```

**Main.java（反射测试）：**
```java
// B1/Main.java
package B1;

import java.lang.reflect.*;

public class Main {
    public static void main(String[] args) {
        try {
            // 方式1：Class.forName + 反射操作
            Class<?> c = Class.forName("B1.Person");
            Object obj = c.newInstance();

            // 反射调用setName方法
            Method m = c.getMethod("setName", String.class);
            m.invoke(obj, "小玉");

            // 反射操作私有属性age
            Field f = c.getDeclaredField("age");
            f.setAccessible(true);  // 打破private封装
            f.set(obj, 20);

            // 反射调用showInfo方法
            m = c.getMethod("showInfo");
            m.invoke(obj);

            // 方式2：类名.class + 有参构造
            Class<?> c1 = Person.class;
            Constructor<?> constructor = c1.getConstructor(String.class, int.class);
            Object obj1 = constructor.newInstance("小花", 19);
            Method m1 = c1.getMethod("showInfo");
            m1.invoke(obj1);

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
```

**输出结果：**
```
姓名是：小玉，年龄是：20
姓名是：小花，年龄是：19
```

#### 12.6 你的代码亮点

1. **两种获取Class的方式** - `Class.forName()` 和 `类名.class` ✅
2. **反射调用方法** - `getMethod() + invoke()` ✅
3. **反射操作私有属性** - `getDeclaredField() + setAccessible(true)` ✅
4. **自定义注解** - `@Target` + `@Retention` + `@interface` ✅
5. **有参构造反射** - `getConstructor() + newInstance()` ✅

#### 12.7 反射与注解的常见应用场景

| 场景 | 说明 |
|-----|------|
| Spring框架 | 通过反射创建Bean，通过注解标记组件 |
| MyBatis | 通过反射读取SQL映射 |
| JUnit | 通过反射执行@Test标记的测试方法 |
| JSON解析 | 通过反射将JSON映射到对象属性 |

---

**恭喜完成Java SE全部知识点！** 🎉
