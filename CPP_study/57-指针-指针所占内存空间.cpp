
/*
	1 C++初识

	2 数据类型

	3 运算符

	4 程序流程结构

	5 数组

	6 函数

	7 指针

		7.1 指针的基本概念

		7.2 指针变量的定义和使用

		7.3 指针所占内存空间

			提问：指针也是种数据类型，那么这种数据类型占用多少内存空间？

			总结：所有指针类型在32位操作系统下是4个字节
*/

#include <iostream>

using namespace std;

int main()
{
	int a = 10;

	int* p;
	p = &a; //指针指向数据a的地址

	cout << *p << endl; //* 解引用
	cout << sizeof(p) << endl;
	cout << sizeof(char*) << endl;
	cout << sizeof(float*) << endl;
	cout << sizeof(double*) << endl;

	return 0;
}