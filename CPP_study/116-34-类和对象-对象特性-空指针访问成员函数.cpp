
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

					C++中空指针也是可以调用成员函数的，但是也要注意有没有用到this指针

					如果用到this指针，需要加以判断保证代码的健壮性
*/

#include <iostream>

using namespace std;

//空指针访问成员函数
class Person
{
public:

    void ShowClassName()
	{
        cout << "我是Person类!" << endl;
    }

    void ShowPerson()
	{
        if (this == NULL)
		{
            return;
        }

		// 成员属性内默认是 this->mAge
        cout << mAge << endl;
    }

public:
    int mAge;
};

void test01()
{
    Person* p = NULL;
    p->ShowClassName(); //空指针，可以调用成员函数
    p->ShowPerson();    //但是如果成员函数中用到了this指针，就不可以了

	// 来自弹幕：你连女朋友都没有，怎么会有女朋友的年龄
}

int main()
{
    test01();

    return 0;
}