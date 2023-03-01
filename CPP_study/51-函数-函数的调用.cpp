
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

			功能：使用定义好的函数

			语法： 函数名（参数）

			总结：函数定义里小括号内称为形参，函数调用时传入的参数称为实参
*/

#include <iostream>

using namespace std;

// 示例：定义一个加法函数，实现两个数相加
// 函数定义
int add(int num1, int num2)// 定义中的num1,num2称为形式参数，简称形参
{
	int sum = num1 + num2;

	return sum;
}

int main()
{
	int a = 10;
	int b = 10;

	//调用add函数
	int sum = add(a, b);//调用时的a，b称为实际参数，简称实参

	cout << "sum = " << sum << endl;

	a = 100;
	b = 100;

	sum = add(a, b);
	cout << "sum = " << sum << endl;

	return 0;
}