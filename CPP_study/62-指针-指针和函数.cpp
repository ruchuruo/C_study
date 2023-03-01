
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

		7.7 指针和函数

			作用：利用指针作函数参数，可以修改实参的值

			总结：如果不想修改实参，就用值传递，如果想修改实参，就用地址传递
*/

#include <iostream>

using namespace std;

//值传递
void swap1(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}

//地址传递
void swap2(int* p1, int* p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

int main()
{
	int a = 10;
	int b = 20;
	swap1(a, b); // 值传递不会改变实参

	swap2(&a, &b); //地址传递会改变实参

	cout << "a = " << a << endl;

	cout << "b = " << b << endl;

	return 0;
}