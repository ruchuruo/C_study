

/*
	数组作为函数参数
		往往写代码的时候，会将数组作为参数传个函数，比如：我要实现一个冒泡排序 函数将一个整形数组排序。
			冒泡排序
				两两相邻的元素进行比较，并且可能的话需要交换

				最大的数或最小的数像水里的泡泡一样升上去
				9 8 7 6 5 4 3 2 1 0
				8 9 7 6 5 4 3 2 1 0
				8 7 9 6 5 4 3 2 1 0
				8 7 6 9 5 4 3 2 1 0
				8 7 6 5 9 4 3 2 1 0			一趟冒泡排序
				8 7 6 5 4 9 3 2 1 0
				8 7 6 5 4 3 9 2 1 0
				8 7 6 5 4 3 2 9 1 0
				8 7 6 5 4 3 2 1 9 0
				8 7 6 5 4 3 2 1 0 9

				8 7 6 5 4 3 2 1 0 | 9
				7 8 6 5 4 3 2 1 0 | 9
				7 6 8 5 4 3 2 1 0 | 9
				7 6 5 8 4 3 2 1 0 | 9
				7 6 5 4 8 3 2 1 0 | 9		二趟
				7 6 5 4 3 8 2 1 0 | 9
				7 6 5 4 3 2 8 1 0 | 9
				7 6 5 4 3 2 1 8 0 | 9
				7 6 5 4 3 2 1 0 8 | 9

				10个数字 - 9趟
				n		  n - 1

				1趟
					10个数字待排序	9对比较

				2趟
					9个数字待排序	8对比较
*/

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

void 泡泡(int arr[], int sz)// 形参arr本质是指针
{


	// 确定趟数
	int i = 0;
	for (i = 0; i < sz - 1; i++)
	{
		// 一趟冒泡排序的过程
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				// 交换
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

int main()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };

	// 计算数组元素个数
	int sz = sizeof(arr) / sizeof(arr[0]);

	// 排序为升序 - 冒泡排序
	泡泡(arr, sz);// 数组传参的时候，传递的是首元素地址


	return 0;
}