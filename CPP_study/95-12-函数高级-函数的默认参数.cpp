
/*
	第1阶段C++ 匠心之作 从0到1入门

	第2阶段实战-通讯录管理

	第3阶段-C++核心编程

		1 内存分区模型

		2 引用

		3 函数提高

			3.1 函数默认参数

				在C++中，函数的形参列表中的形参是可以有默认值的。

				语法： 返回值类型 函数名 （参数= 默认值）{}
*/

#include <iostream>

using namespace std;

//1. 如果某个位置参数有默认值，那么从这个位置往后，从左向右，必须都要有默认值
// 来自弹幕：传参的值和函数默认参数同时存在时，传参的值会覆盖函数的初始参数
int func(int a, int b = 10, int c = 10)
{
	return a + b + c;
}


//2. 如果函数声明有默认值，函数实现的时候就不能有默认参数
// 声明 和 实现 只能有一个有默认参数
int func2(int a = 10, int b = 10);	// 声明
int func2(int a, int b)				// 实现
{
	return a + b;
}

int main()
{
	cout << "ret = " << func(20, 20) << endl;
	cout << "ret = " << func(100) << endl;

	return 0;
}