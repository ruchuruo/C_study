
/*
	第1阶段C++ 匠心之作 从0到1入门

	第2阶段实战-通讯录管理

	第3阶段-C++核心编程

		1 内存分区模型

		2 引用

		3 函数提高

		4 类和对象

			4.1 封装

			4.2 对象的初始化和清理

				4.2.1 构造函数和析构函数

				4.2.2 构造函数的分类及调用

					两种分类方式：

						按参数分为： 有参构造和无参构造

						按类型分为： 普通构造和拷贝构造

					三种调用方式：

						括号法

						显示法

						隐式转换法
*/

#include <iostream>

using namespace std;

//1、构造函数分类
// 按照参数分类分为 有参和无参构造   无参又称为默认构造函数
// 按照类型分类分为 普通构造和拷贝构造

class Person
{
public:
    //无参（默认）构造函数
    Person()
    {
        cout << "无参构造函数!" << endl;
    }
    //有参构造函数
    Person(int a)
    {
        age = a;
        cout << "有参构造函数!" << endl;
    }
    //拷贝构造函数
    Person(const Person& p)
    {
        age = p.age;
        cout << "拷贝构造函数!" << endl;
    }
    //析构函数
    ~Person()
    {
        cout << "析构函数!" << endl;
    }

public:
    int age;
};



//2、构造函数的调用
//调用无参构造函数
void test01()
{
    Person p; //调用无参构造函数
}

//调用有参的构造函数
void test02()
{
    //2.1  括号法，常用
    Person p1(10);
    //注意1：调用无参构造函数不能加括号，如果加了编译器认为这是一个函数声明
    //Person p2();

    //2.2 显式法
    Person p2 = Person(10);
    Person p3 = Person(p2);
    //Person(10)单独写就是匿名对象  当前行结束之后，马上析构

    //2.3 隐式转换法
    Person p4 = 10; // Person p4 = Person(10); 
    Person p5 = p4; // Person p5 = Person(p4); 

    //注意2：不能利用 拷贝构造函数 初始化匿名对象 编译器认为是对象声明
    //Person p5(p4);
}

void test3()
{
    // 1. 括号法，常用
    Person p1;    // 默认构造函数调用
    Person p2(10);// 有参构造函数调用
    Person p3(p2);// 拷贝构造函数调用

    // 注意1：调用无参构造函数不能加括号，如：Person p();，如果加了编译器认为这是一个函数声明


    // 2. 显式法
    Person p10;              // 默认构造函数调用
    Person p20 = Person(100);// 有参构造函数调用
    Person p30 = Person(p20);// 拷贝构造函数调用

    // Person(10)单独写就是匿名对象，当前行结束之后，马上析构
    //     → --<Code>-- ← 
    //     → Person(10) ← 有参构造函数调用
    //     → --<Code>-- ← 析构函数调用
    // 
    // 相当于：
    //     Person(100)对象无名 起名为 p20
    //     Person(p20)对象无名 起名为 p30
    // 
    // 注意2：不能利用 拷贝构造函数 初始化匿名对象，编译器认为是对象声明
    //     Person(p30); 等价于 Person p30;
    // 
    // 来自弹幕：匿名对象 vector容器交换会用到！！！大家关注这里啊！！！


    // 3. 隐式转换法
    Person p100;       // 默认构造函数调用
    Person p200 = 1000;// 有参构造函数调用，相当于显式法： Person p200 = Person(1000);
    Person p300 = p200;// 拷贝构造函数调用，相当于显式法： Person p300 = Person(p200);
}

int main()
{
    //调用无参构造函数
    //test01();

    //调用有参的构造函数
    //test02();

    // 总结
    test3();

    return 0;
}