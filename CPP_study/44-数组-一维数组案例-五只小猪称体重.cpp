
/*
	1 C++初识

	2 数据类型

	3 运算符

	4 程序流程结构

	5 数组

		5.1 概述

		5.2 一维数组

			5.2.1 一维数组定义方式

			5.2.2 一维数组数组名

			练习案例1：五只小猪称体重

				案例描述：

					在一个数组中记录了五只小猪的体重，如：int arr[5] = {300,350,200,400,250};

					找出并打印最重的小猪体重。
*/

#include <iostream>

using namespace std;

void test1()
{
	// 创建5只小猪的体重
	int arr[5] = { 300,350,200,400,250 };

	// 从数组中找到最大值
	// 先设定最大值为0
	int max = 0;

	for (int i = 0; i < 5; i++)
	{
		// 如果数组中的元素比 max 大，就将数组元素赋值给 max
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}

	// 打印最大值
	cout << max << endl;
}

void test2()
{
	int arr[5] = { 300,350,200,400,250 };

	int max = 0;

	for (int i = 0; i < 5; i++)
	{
		max = (max < arr[i] ? arr[i] : max);
	}

	cout << max << endl;
}

void test3()
{
	int arr[5] = { 0 };

	int compare = 0;
	int arrSize = sizeof(arr) / sizeof(arr[0]);

	for (int i = 0; i < arrSize; i++)
	{
		cout << "输入小猪 " << i + 1 << " 的体重>";

		cin >> arr[i];

		if (arr[i] > compare)
		{
			compare = arr[i];
		}
	}

	cout << compare << endl;
}

int main()
{
	test1();

	cout << "-------- -------- -------- --------" << endl;

	// 其他版本
	test2();

	cout << "-------- -------- -------- --------" << endl;

	// 其他版本
	test3();

	return 0;
}