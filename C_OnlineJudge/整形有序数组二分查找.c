#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{

	// 3.在一个有序数组中查找具体的某个数字n。编写int binsearch(int x, int v[], int n);功能：在v[] <= v[1] <= v[2] <=...<= v[n-1]的数组中查找x
	// 假如 1 2 3 4 5 6 7 8 9 10 中找 7
	// 二分查找
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int k = 7;//要查找的数字

	// 在arr这个有序数组中查找k的值

	//计算数组元素个数
	int sz = sizeof(arr) / sizeof(arr[0]);
	// 确定左下标
	int left = 0;
	// 确定右下标
	int right = sz - 1;

	// 找到数组平均值的下标
	//arr[mid]


	while (left <= right)
	{
		// 计算数组下标平均值
		int mid = (left + right) / 2;

		// 比较 小右大左
		if (arr[mid] < k)
		{
			left = mid + 1;
		}
		else if (arr[mid] > k)
		{
			right = mid - 1;
		}
		else
		{
			printf("找到：%d\n", arr[mid]);
			break;
		}
	}
	if (left > right)
	{
		printf("找不到\n");
	}

	return 0;
}