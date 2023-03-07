
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

				4.2.3 拷贝构造函数调用时机

				4.2.4 构造函数调用规则

				4.2.5 深拷贝与浅拷贝

				4.2.6 初始化列表

				4.2.7 类对象作为类成员

					C++类中的成员可以是另一个类的对象，我们称该成员为 对象成员

					例如：
						class A {}
						class B
						{
							A a；
						}

					B类中有对象A作为成员，A为对象成员，
					那么当创建B对象时，A与B的构造和析构的顺序是谁先谁后？

                    先有胳膊腿，再组成人
                    来自弹幕：先有子体，才能组成母体；母体释放，子体才能恢复自由释放
                    来自弹幕：原因就是人构造的时候会用到手机，所以必须先手机，而人析构的时候也可能用到手机，所以后析构手机
                    来自弹幕：构造时类对象先进栈,析构时就是出栈顺序了
*/

#include <iostream>

using namespace std;

class Phone
{
public:
    Phone(string name)
    {
        m_PhoneName = name;
        cout << "Phone构造" << endl;
    }

    ~Phone()
    {
        cout << "Phone析构" << endl;
    }

    string m_PhoneName;

};


class Person
{
public:

    //初始化列表可以告诉编译器调用哪一个构造函数
    // m_Phone(pName) 等于 Phone m_Phone = pName 隐式转换法
    Person(string name, string pName) :m_Name(name), m_Phone(pName)
    {
        cout << "Person构造" << endl;
    }

    ~Person()
    {
        cout << "Person析构" << endl;
    }

    void playGame()
    {
        cout << m_Name << " 使用" << m_Phone.m_PhoneName << " 牌手机! " << endl;
    }

    string m_Name;
    Phone m_Phone;

};


void test01()
{
    //当类中成员是其他类对象时，我们称该成员为 对象成员
    //构造的顺序是 ：先调用对象成员的构造，再调用本类构造
    //析构顺序与构造相反
    Person p("张三", "苹果X");
    p.playGame();

}


int main()
{
    test01();

    return 0;
}