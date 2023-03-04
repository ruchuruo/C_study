
/*
	第1阶段C++ 匠心之作 从0到1入门

	第2阶段实战-通讯录管理

	第3阶段-C++核心编程

		1 内存分区模型

		2 引用

		3 函数提高

			3.1 函数默认参数

			3.2 函数占位参数

			3.3 函数重载

				3.3.1 函数重载概述

				3.3.2 函数重载注意事项

					引用作为重载条件
					函数重载碰到函数默认参数
*/

#include <iostream>

using namespace std;

//函数重载注意事项
//1、引用作为重载条件

void func(int& a)
{
	cout << "func (int &a) 调用 " << endl;
}

void func(const int& a)
{
	cout << "func (const int &a) 调用 " << endl;
}


//2、函数重载碰到函数默认参数

void func2(int a, int b = 10)
{
	cout << "func2(int a, int b = 10) 调用" << endl;
}

void func2(int a)
{
	cout << "func2(int a) 调用" << endl;
}

int main()
{
	int a = 10;

	func(a); //调用无const
	func(10);//调用有const


	//func2(10); //碰到默认参数产生歧义(二义性)，需要避免

	return 0;
}