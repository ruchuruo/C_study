
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

			5.2.3 冒泡排序

				作用： 最常用的排序算法，对数组内元素进行排序

				比较相邻的元素。如果第一个比第二个大，就交换他们两个。
				对每一对相邻元素做同样的工作，执行完毕后，找到第一个最大值。
				重复以上的步骤，每次比较次数-1，直到不需要比较

				排序轮数：0 1 2 3 4 5 6 7
				对比次数：8 7 6 5 4 3 2 1

				排序总轮数   = 元素个数 - 1
				每轮对比次数 = 元素个数 - 排序轮数 - 1
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

int main()
{
	// 示例： 将数组 { 4,2,8,0,5,7,1,3,9 } 进行升序排序

	int arr[9] = { 4,2,8,0,5,7,1,3,9 };

	arrPrint(arr, (sizeof(arr) / sizeof(arr[0])));

	// 开始排序
	// 排序总轮数 = 元素个数 - 1
	for (int i = 0; i < 9 - 1; i++)
	{
		// 每轮对比次数 = 元素个数 - 排序轮数 - 1
		for (int j = 0; j < 9 - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	arrPrint(arr, (sizeof(arr) / sizeof(arr[0])));

	return 0;
}