
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

		7.8 指针、数组、函数

			案例描述：封装一个函数，利用冒泡排序，实现对整型数组的升序排序

			例如数组：int arr[10] = { 4,3,6,9,1,2,10,8,7,5 };

			总结：当数组名传入到函数作为参数时，被退化为指向首元素的指针
*/

#include <iostream>

using namespace std;

//冒泡排序函数
void bubbleSort(int* arr, int len)  //int * arr 也可以写为int arr[]
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

//打印数组函数
void printArray(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << endl;
	}
}

int main()
{
	int arr[10] = { 4,3,6,9,1,2,10,8,7,5 };
	int len = sizeof(arr) / sizeof(int);

	bubbleSort(arr, len);

	printArray(arr, len);

	return 0;
}