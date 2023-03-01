/*
	有一个有序数字序列，从小到大排序，将一个新输入的数插入到序列中，保证插入新数后，序列仍然是升序。

	第一行输入一个整数(0 <= N <= 50)
	第二行输入N个升序排列的整数，输入用空格分隔的N个整数
	第三行输入想要进行插入的一个整数

	输出为一行，N+1个有序排列的整数

	输入：5
	输入：1 6 9 22 30
	输入：8
	输出：1 6 8 9 22 30


	思路
		8和最后一个整数比较
						  8<
			[1][6][9][22][30]

		最后一个整数向后移动
					      8<
			[1][6][9][22][ ][30]

		8向前继续比较
					  8<
			[1][6][9][ ][22][30]

		8大于前面的数
			       8>
			[1][6][8][9][22][30]

*/
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

void 方法1()
{
	printf("开始输入ctrl+c停止>");

	int arr[51] = { 0 };

	// 输入N
	int n = 0;
	scanf("%d", &n);

	// 输入N个升序排列的整数
	int i = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	// 输入要插入的数据
	int m = 0;
	scanf("%d", &m);

	// 输入数据
	for (i = n - 1; i >= 0; i--)
	{
		if (arr[i] > m)
		{
			arr[i + 1] = arr[i];
		}
		else
		{
			arr[i + 1] = m;
			break;
		}
	}

	// 处理插入的数据小于所有数据
	if (i < 0)
	{
		arr[0] = m;
	}

	// 输出
	for (i = 0; i < n + 1; i++)
	{
		printf("%d ", arr[i]);
	}
}

void 方法2()
{
	printf("开始输入ctrl+c停止>");

	int arr[51] = { 0 };

	// 输入N
	int n = 0;
	scanf("%d", &n);

	// 输入N个升序排列的整数
	int i = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	// 输入要插入的数据
	int m = 0;
	scanf("%d", &m);

	// 输入数据
	for (i = n - 1; i >= 0; i--)
	{
		if (arr[i] > m)
		{
			arr[i + 1] = arr[i];
		}
		else
		{
			break;
		}
	}

	// 统一在这插入数据
	arr[i + 1] = m;

	// 输出
	for (i = 0; i < n + 1; i++)
	{
		printf("%d ", arr[i]);
	}
}

int main()
{
	//方法1();

	方法2();

	return 0;
}