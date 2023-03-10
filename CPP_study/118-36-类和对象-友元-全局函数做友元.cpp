
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

				生活中你的家有客厅(Public)，有你的卧室(Private)

				客厅所有来的客人都可以进去，但是你的卧室是私有的，也就是说只有你能进去

				但是呢，你也可以允许你的好闺蜜好基友进去。

				在程序里，有些私有属性 也想让类外特殊的一些函数或者类进行访问，就需要用到友元的技术

				友元的目的就是让一个函数或者类 访问另一个类中私有成员

				友元的关键字为 friend

				友元的三种实现

					全局函数做友元
					类做友元
					成员函数做友元

				4.4.1 全局函数做友元
*/

#include <iostream>

using namespace std;

class Building
{
	//告诉编译器 goodGay全局函数 是 Building类的好朋友，可以访问类中的私有内容
	friend void goodGay(Building* building);

public:

	Building()
	{
		this->m_SittingRoom = "客厅";
		this->m_BedRoom = "卧室";
	}


public:
	string m_SittingRoom; //客厅

private:
	string m_BedRoom; //卧室
};


void goodGay(Building* building)
{
	cout << "好基友正在访问： " << building->m_SittingRoom << endl;
	cout << "好基友正在访问： " << building->m_BedRoom << endl;
}


void test01()
{
	Building b;
	goodGay(&b);
}

int main()
{
	test01();

	return 0;
}