
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

		7.4 空指针和野指针

		7.5 const修饰指针

		7.6 指针和数组

			作用：利用指针访问数组中元素
*/

#include <iostream>

using namespace std;

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };

	int* p = arr;  //指向数组的指针

	cout << "第一个元素： " << arr[0] << endl;
	cout << "指针访问第一个元素： " << *p << endl;

	for (int i = 0; i < 10; i++)
	{
		//利用指针遍历数组
		cout << *p << endl;
		p++;
	}

	return 0;
}