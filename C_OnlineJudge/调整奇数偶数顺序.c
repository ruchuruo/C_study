/*
	调整奇数偶数顺序
		调整数组使奇数全部都位于偶数前面

		输入一个整数数组，实现一个函数，来调整该数组中数字的顺序，
		使得数组中所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分

		思路：

			从前往后找，
				找到1 不动，找到2 要到前面去

			从后往前找，
				找到10 不动，找到9 要到前面去

			交换，
				2 和 9 交换

			如果给的数组 全偶数 或 全奇数，找到最后一位还是符合条件就进入循环，
			左++ 和 右-- 会越界访问，所以要加上 &&(左 < 右)
*/

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

void 移动(int arr[], int sz)
{
	int 左 = 0;
	int 右 = sz - 1;

	while (左 < 右)
	{
		// 从前往后找一个偶数
		while ((左 < 右) && (arr[左] % 2 == 1))// 找到偶数余数就是0，退出循环
		{
			左++;
		}

		// 从后往前找一个奇数
		while ((左 < 右) && (arr[右] % 2 == 0))
		{
			右--;
		}

		// 交换
		if (左 < 右)
		{
			int 临时 = arr[左];
			arr[左] = arr[右];
			arr[右] = 临时;
		}
	}
}

void 打印(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);

	移动(arr, sz);
	打印(arr, sz);

	return 0;
}