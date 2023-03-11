
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

			4.4 友元

			4.5 运算符重载

				运算符重载概念：对已有的运算符重新进行定义，赋予其另一种功能，以适应不同的数据类型

				4.5.1 加号运算符重载

					作用：实现两个自定义数据类型相加的运算

                    比如：
                        p3 = p1 + p2
                        p3的m_A = p1的m_A + p2的m_A

                        通过自己写的成员函数，实现两个对象相加属性后，返回新的对象

                            Person PersonAddPerson(Person &p)
                            {
                                Person temp;
                                temp.m_A = this->m_A + p.m_A;
                                temp.m_B = this->m_B + p.m_B;
                                return temp;
                            }

                        函数名字可以叫其他的，所以编译器提供了 operator，operator 加 运算符 替换函数名

                            Person operator+(const Person& p)
                            {
                                Person temp;
                                temp.m_A = this->m_A + p.m_A;
                                temp.m_B = this->m_B + p.m_B;
                                return temp;
                            }

                        成员函数运算符重载本质调用
                            Person p3 = p1.operaor+(p2)
                            简化成
                            Person p3 = p1 + p2;

                        全局函数运算符重载本质调用
                            Person p3 = operaor+(p1, p2)
                            简化成
                            Person p3 = p1 + p2;

					总结1：对于内置的数据类型的表达式的的运算符是不可能改变的
					总结2：不要滥用运算符重载
*/

#include <iostream>

using namespace std;

class Person
{
public:
    Person() {};

    Person(int a, int b)
    {
        this->m_A = a;
        this->m_B = b;
    }

    //成员函数实现 + 号运算符重载
    Person operator+(const Person& p)
    {
        Person temp;
        temp.m_A = this->m_A + p.m_A;
        temp.m_B = this->m_B + p.m_B;
        return temp;
    }


public:
    int m_A;
    int m_B;
};

//全局函数实现 + 号运算符重载
//Person operator+(const Person& p1, const Person& p2) {
//	Person temp(0, 0);
//	temp.m_A = p1.m_A + p2.m_A;
//	temp.m_B = p1.m_B + p2.m_B;
//	return temp;
//}

//运算符重载 可以发生函数重载 
Person operator+(const Person& p2, int val)
{
    Person temp;
    temp.m_A = p2.m_A + val;
    temp.m_B = p2.m_B + val;
    return temp;
}

void test()
{
    Person p1(10, 10);
    Person p2(20, 20);

    //成员函数方式
    Person p3 = p2 + p1;  //相当于 p2.operaor+(p1)
    cout << "mA:" << p3.m_A << " mB:" << p3.m_B << endl;


    Person p4 = p3 + 10; //相当于 operator+(p3,10)
    cout << "mA:" << p4.m_A << " mB:" << p4.m_B << endl;
}

int main()
{
    test();

    return 0;
}

















































/*
    画图工具写代码时
        来自弹幕：我就服，这样写代码，还这么快，还标准，，，
        来自弹幕：那你可能不知道谁是杜聚宾
*/