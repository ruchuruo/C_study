


#include <stdio.h>

// 3.写一个函数，实现一个整形有序数组的二分查找
// 这里形参的数组不需要设定大小，无意义
int 二分查找(int arr[], int 查找, int 数组个数)
{
	int 左下标 = 0;
	int 右下标 = 数组个数 - 1;

	while (左下标 <= 右下标)
	{
		int 中下标 = (左下标 + 右下标) / 2;

		if (arr[中下标] > 查找)
		{
			右下标 = 中下标 - 1;
		}
		else if (arr[中下标] < 查找)
		{
			左下标 = 中下标 + 1;
		}
		else
		{
			return 中下标;
		}
	}
	return -1;// 找不到

}

int main()
{
	// 3.写一个函数，实现一个整形有序数组的二分查找
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int 查找 = 7;
	int 数组个数 = sizeof(arr) / sizeof(arr[0]);
	// 找到就返回下标 找不到就返回-1
	int ret = 二分查找(arr, 查找, 数组个数);
	if (ret == -1)
	{
		printf("\n找不到\n");
	}
	else
	{
		printf("\n找到 下标%d\n", ret);
	}
	// 
	// 改造 错误
	//int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	//int 查找 = 7;
	//// 找到就返回下标 找不到就返回-1
	//// 数组arr传参 实际传递的不是数组本身 仅仅传过去了数组首元素的地址
	//int ret = 二分查找(arr, 查找);
	//if (ret == -1)
	//{
	//	printf("\n找不到\n");
	//}
	//else
	//{
	//	printf("\n找到 下标%d\n", ret);
	//}

	return 0;
}