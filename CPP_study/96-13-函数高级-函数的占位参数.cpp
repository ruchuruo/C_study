
/*
	第1阶段C++ 匠心之作 从0到1入门

	第2阶段实战-通讯录管理

	第3阶段-C++核心编程

		1 内存分区模型

		2 引用

		3 函数提高

			3.1 函数默认参数

			3.2 函数占位参数

				C++中函数的形参列表里可以有占位参数，用来做占位，调用函数时必须填补该位置

				语法： 返回值类型 函数名 (数据类型){}

				在现阶段函数的占位参数存在意义不大，但是后面的课程中会用到该技术

				来自弹幕：P123 递增运算符重载会用到占位参数
*/

#include <iostream>

using namespace std;

//函数占位参数 ，占位参数也可以有默认参数：func(int a, int = 10)
void func(int a, int)
{
	cout << "this is func" << endl;
}

// 来自弹幕：《可恶，究竟是谁等于10！》
void func2(int a, int = 10)
{
	cout << "this is func2" << endl;
}

int main()
{
	func(10, 10); //占位参数必须填补

	func2(10);

	return 0;
}