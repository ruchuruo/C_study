
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

			练习案例2：数组元素逆置

				案例描述：请声明一个5个元素的数组，并且将元素逆置.

				(如原数组元素为：1,3,2,5,4;逆置后输出结果为:4,5,2,3,1);
*/

#include <iostream>

using namespace std;

void arrPrint(int arr[], int arrSize)
{
	for (int i = 0; i < arrSize; i++)
	{
		cout << arr[i] << " ";
	}

	cout << endl;
}

void test1()
{
	int arr[5] = { 1,3,2,5,4 };

	int start = 0;// 起始元素下标
	int end = sizeof(arr) / sizeof(arr[0]) - 1;// 末尾元素下标

	arrPrint(arr, (sizeof(arr) / sizeof(arr[0])));

	// 起始元素 和 末尾元素 互换
	// 来自弹幕：start根本没必要，浪费了，只要for(int i=0;i<=(end+1)/2;i++){互换语句}
	while (start < end)
	{
		// 临时变量记录 起始元素
		int tmp = arr[start];

		// 末尾元素 赋值给 起始元素
		arr[start] = arr[end];

		// 临时变量 赋值给 末尾元素
		arr[end] = tmp;

		// 起始位置++，末尾位置--
		start++;
		end--;
	}

	arrPrint(arr, (sizeof(arr) / sizeof(arr[0])));
}

void test2()
{
	int arr[5] = { 1,2,3,4,5 };

	int tmp = 0;
	int arrSize = sizeof(arr) / sizeof(arr[0]);
	int left = 0;
	int right = arrSize - 1;

	arrPrint(arr, arrSize);

	while (left < right)
	{
		tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;

		left++;
		right--;
	}

	arrPrint(arr, arrSize);
}

int main()
{
	test1();

	cout << "-------- -------- -------- --------" << endl;

	// 其他版本
	test2();

	return 0;
}