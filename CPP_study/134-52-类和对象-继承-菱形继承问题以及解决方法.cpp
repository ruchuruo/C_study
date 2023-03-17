
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

			4.6 继承

				4.6.1 继承的基本语法

				4.6.2 继承方式

				4.6.3 继承中的对象模型

				4.6.4 继承中构造和析构顺序

				4.6.5 继承同名成员处理方式

				4.6.6 继承同名静态成员处理方式

				4.6.7 多继承语法

				4.6.8 菱形继承

					菱形继承概念：

						两个派生类继承同一个基类

						又有某个类同时继承者两个派生类

						这种继承被称为菱形继承，或者钻石继承

					典型的菱形继承案例：

						|     动物
						|     ↙↘
						|   羊    驼
						|     ↘↙
						|    草泥马

					菱形继承问题：
						羊继承了动物的数据，驼同样继承了动物的数据，当草泥马使用数据时，就会产生二义性。
						草泥马继承自动物的数据继承了两份，其实我们应该清楚，这份数据我们只需要一份就可以。

					总结：
						菱形继承带来的主要问题是子类继承两份相同的数据，导致资源浪费以及毫无意义
						利用虚继承可以解决菱形继承问题


					虚继承 前
						class SheepTuo size(8):
							+---
						 0  | +--- (base class Sheep)
						 0  | | +--- (base class Animal)
						 0  | | | m_Age
							| | +---
							| +---
						 4  | +--- (base class Tuo)
						 4  | | +--- (base class Animal)
						 4  | | | m_Age
							| | +---
							| +---
							+---
						......

					虚继承 后
						class SheepTuo size(12):
							+--- 
						 0  | +--- (base class Sheep)
						 0  | | {vbptr}
							| +---
						 4  | +--- (base class Tuo)
						 4  | | {vbptr}
							| +---
							+---
							+--- (virtual base Animal)
						 8  | m_Age
							+---

						SheepTuo::$vbtable@Sheep@:
						 0  | 0
						 1  | 8 (SheepTuo(Sheep+0)Animal)
						......


					vbptr 虚基类指针
						v   - virtual 虚
						b   - base    基类
						ptr - pointer 指针

						虚基类指针 会 指向 vbtable 虚基类表格

					vbtable 虚基类表格
						v     - virtual 虚
						b     - base    基类
						table -         表格

						表中记录了偏移量

						SheepTuo::$vbtable@Sheep@:
						 0  | 0
						 1  | 8 (SheepTuo(Sheep+0)Animal)
								↑
								偏移量

						0 + 8 就指向了 m_Age

						 0  | +--- (base class Sheep)
						 0  | | {vbptr}
						 ↓
						 .
						 .
						 .
						 ↓
							+--- (virtual base Animal)
						 8  | m_Age

					所以这个数据只有一份
*/

#include <iostream>

using namespace std;

class Animal
{
public:
	int m_Age;
};

//继承前加virtual关键字后，变为虚继承
//此时公共的父类Animal称为虚基类
// 这样数据只有一份了
class Sheep : virtual public Animal {};
class Tuo : virtual public Animal {};
class SheepTuo : public Sheep, public Tuo {};

void test01()
{
	SheepTuo st;
	st.Sheep::m_Age = 100;
	st.Tuo::m_Age = 200;

	cout << "st.Sheep::m_Age = " << st.Sheep::m_Age << endl;
	cout << "st.Tuo::m_Age = " << st.Tuo::m_Age << endl;

	// 此时多了一个访问方式
	cout << "st.m_Age = " << st.m_Age << endl;
}


int main()
{
	test01();

	return 0;
}

/*
	驼 的英文单词知道是什么吗？不知道是吧。OK啊 不知道我告诉你啊 tuo 驼，
	啊 好那这个就是汉语拼音，我也不知道这个英文是啥，那咱就用汉语拼音来补它，对吧

	SheepTuo《组 装》
*/