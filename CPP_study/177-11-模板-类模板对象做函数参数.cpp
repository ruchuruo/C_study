
/*
	第1阶段C++ 匠心之作 从0到1入门

	第2阶段实战-通讯录管理

	第3阶段-C++核心编程

	第4阶段实战-基于多态的企业职工系统

	第5阶段-C++提高编程
		
		本阶段主要针对C++ 泛型编程 和 STL 技术做详细讲解，探讨C++更深层的使用

		1 模板

			1.1 模板的概念

			1.2 函数模板

			1.3 类模板

				1.3.1 类模板语法

				1.3.2 类模板与函数模板区别

				1.3.3 类模板中成员函数创建时机

				1.3.4 类模板对象做函数参数

					学习目标：

						类模板实例化出的对象，向函数传参的方式

					一共有三种传入方式：

						指定传入的类型 --- 直接显示对象的数据类型
						参数模板化     --- 将对象中的参数变为模板进行传递
						整个类模板化   --- 将这个对象类型 模板化进行传递

					总结：

						通过类模板创建的对象，可以有三种方式向函数中进行传参
						使用比较广泛是第一种：指定传入的类型
*/

#include <iostream>

using namespace std;

//类模板
template<class NameType, class AgeType = int>
class Person
{
public:
    Person(NameType name, AgeType age)
    {
        this->mName = name;
        this->mAge = age;
    }
    void showPerson()
    {
        cout << "name: " << this->mName << " age: " << this->mAge << endl;
    }
public:
    NameType mName;
    AgeType mAge;
};

//1、指定传入的类型 (类型：Person<string, int>，引用，变量名：p)
void printPerson1(Person<string, int>& p)
{
    p.showPerson();
}
void test01()
{
    Person<string, int> p("孙悟空", 100);
    printPerson1(p);
}

//2、参数模板化 (<string, int > 变成模板 <T1, T2>)
template <class T1, class T2>
void printPerson2(Person<T1, T2>& p)
{
    p.showPerson();
    cout << "T1的类型为： " << typeid(T1).name() << endl;// string
    cout << "T2的类型为： " << typeid(T2).name() << endl;// int
}
void test02()
{
    Person <string, int >p("猪八戒", 90);
    printPerson2(p);
}

//3、整个类模板化 (将整个 Person <string, int > 变成模板 T)
template<class T>
void printPerson3(T& p)
{
    cout << "T的类型为： " << typeid(T).name() << endl;// class Person
    p.showPerson();
}
void test03()
{
    Person <string, int >p("唐僧", 30);
    printPerson3(p);
}

int main()
{
    //1、指定传入的类型
    test01();

    //2、参数模板化
    test02();

    //3、整个类模板化
    test03();

    return 0;
}