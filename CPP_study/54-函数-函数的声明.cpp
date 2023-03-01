
/*
	1 C++初识

	2 数据类型

	3 运算符

	4 程序流程结构

	5 数组

	6 函数

		6.1 概述

		6.2 函数的定义

		6.3 函数的调用

		6.4 值传递

		6.5 函数的常见样式

		6.6 函数的声明

			作用： 告诉编译器函数名称及如何调用函数。函数的实际主体可以单独定义。

			函数的声明可以多次，但是函数的定义只能有一次
*/

#include <iostream>

using namespace std;

//声明
//声明可以多次，定义只能一次
int max(int a, int b);
int max(int a, int b);


int main()
{
	int a = 100;
	int b = 200;

	cout << max(a, b) << endl;

	return 0;
}


//定义
int max(int a, int b)
{
	return a > b ? a : b;
}