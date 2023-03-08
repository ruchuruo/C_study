
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

			4.3 C++对象模型和this指针

				4.3.1 成员变量和成员函数分开存储

				4.3.2 this指针概念

				4.3.3 空指针访问成员函数

				4.3.4 const修饰成员函数

					常函数：
						成员函数后加const后我们称为这个函数为常函数
						常函数内不可以修改成员属性
						成员属性声明时加关键字mutable后，在常函数中依然可以修改

					常对象：
						声明对象前加const称该对象为常对象
						常对象只能调用常函数
*/

#include <iostream>

using namespace std;

class Person
{
public:
    Person()
    {
        m_A = 0;
        m_B = 0;
    }

    //this指针的本质是一个指针常量，指针的指向不可修改
    //如果想让指针指向的值也不可以修改，需要声明常函数
    void ShowPerson() const
    {
        //const Type* const pointer;
        //this = NULL;     // 指针常量 不能修改指针的指向 Person* const this;
        //this->m_A = 100; // 但是this指针指向的对象的数据是可以修改的

        //const修饰成员函数，表示指针指向的内存空间的数据不能修改，除了mutable修饰的变量
        this->m_B = 100;
    }

    void MyFunc()
    {
        m_A = 10000;
    }

public:
    int m_A;
    mutable int m_B; //可修改 可变的
};


//const修饰对象  常对象
void test01()
{
    const Person person; //常量对象  
    cout << person.m_A << endl;

    //person.mA = 100; //常对象不能修改成员变量的值,但是可以访问
    person.m_B = 100; //但是常对象可以修改mutable修饰成员变量

    // 常对象 只能调用 常函数
    // 常对象是为了不修改成员变量，但是普通函数可以修改成员变量，所以不允许 常对象 调用 普通函数
    //person.MyFunc();
}

int main()
{
    test01();

    return 0;
}