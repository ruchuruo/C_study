
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

			4.7 多态(多种形态)

				4.7.1 多态的基本概念

				多态的原理剖析

				4.7.2 多态案例一-计算器类

				4.7.3 纯虚函数和抽象类

				4.7.4 多态案例二-制作饮品

					案例描述：

						制作饮品的大致流程为：煮水 - 冲泡 - 倒入杯中 - 加入辅料

						利用多态技术实现本案例，提供抽象制作饮品基类，提供子类制作咖啡和茶叶

						冲咖啡
							1. 煮水
							2. 冲泡咖啡
							3. 倒入杯中
							4. 加糖和牛奶

						冲茶叶
							1. 煮水
							2. 冲泡茶叶
							3. 倒入杯中
							4. 加柠檬
*/

#include <iostream>

using namespace std;

//抽象制作饮品
class AbstractDrinking
{
public:

	//烧水
	virtual void Boil() = 0;

	//冲泡
	virtual void Brew() = 0;

	//倒入杯中
	virtual void PourInCup() = 0;

	//加入辅料
	virtual void PutSomething() = 0;

	//规定流程
	void MakeDrink()
	{
		Boil();         //烧水
		Brew();         //冲泡
		PourInCup();    //倒入杯中
		PutSomething(); //加入辅料
	}
};

//制作咖啡
class Coffee : public AbstractDrinking
{
public:

	virtual void Boil()
	{
		cout << "煮农夫山泉" << endl;
	}

	virtual void Brew()
	{
		cout << "冲泡咖啡" << endl;
	}

	virtual void PourInCup()
	{
		cout << "倒入杯中" << endl;
	}

	virtual void PutSomething()
	{
		cout << "加糖和牛奶" << endl;
	}
};

//制作茶水
class Tea : public AbstractDrinking
{
public:

	virtual void Boil()
	{
		cout << "煮百岁山!" << endl;
	}

	virtual void Brew()
	{
		cout << "冲泡茶叶!" << endl;
	}

	virtual void PourInCup()
	{
		cout << "将茶水倒入杯中!" << endl;
	}

	virtual void PutSomething()
	{
		cout << "加入枸杞!" << endl;
	}
};

//业务函数
void DoWork(AbstractDrinking* drink)
{
	drink->MakeDrink();

	delete drink;
}



void test01()
{
	DoWork(new Coffee);
	cout << "--------------" << endl;
	DoWork(new Tea);
}

int main()
{
	test01();

	return 0;
}