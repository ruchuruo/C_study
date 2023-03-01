
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

			所谓值传递，就是函数调用时实参将数值传入给形参

			值传递时，如果形参发生，并不会影响实参

			总结： 值传递时，形参是修饰不了实参的
*/

#include <iostream>

using namespace std;

void swap(int num1, int num2)
{
	cout << "交换前：" << endl;
	cout << "num1 = " << num1 << endl;
	cout << "num2 = " << num2 << endl;

	int temp = num1;
	num1 = num2;
	num2 = temp;

	cout << "交换后：" << endl;
	cout << "num1 = " << num1 << endl;
	cout << "num2 = " << num2 << endl;

	//return ; 当函数声明时候，不需要返回值，可以不写return
}

int main()
{
	int a = 10;
	int b = 20;

	swap(a, b);

	cout << "mian中的 a = " << a << endl;
	cout << "mian中的 b = " << b << endl;

	return 0;
}