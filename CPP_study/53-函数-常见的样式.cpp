
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

			常见的函数样式有4种

				无参无返
				有参无返
				无参有返
				有参有返
*/

#include <iostream>

using namespace std;

//函数常见样式
//1、 无参无返
void test01()
{
	//void a = 10; //无类型不可以创建变量,原因无法分配内存
	cout << "this is test01" << endl;
	//test01(); 函数调用
}

//2、 有参无返
void test02(int a)
{
	cout << "this is test02" << endl;
	cout << "a = " << a << endl;
}

//3、无参有返
int test03()
{
	cout << "this is test03 " << endl;
	return 10;
}

//4、有参有返
int test04(int a, int b)
{
	cout << "this is test04 " << endl;
	int sum = a + b;
	return sum;
}

int main()
{

	return 0;
}