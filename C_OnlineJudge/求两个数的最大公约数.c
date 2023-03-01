/*
	求两个数的最大公约数
		同时整除这两个数

		最大公约数不会超过18，从两个数中最小的数开始往下找
			18
			17
			16
			15
			↓

*/

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int m = 0;
	int n = 0;
	int max = 0;

	printf("请输入两个整数\n");
	scanf("%d %d", &m, &n);//24 18

	// 假设最大公约数就是m和n的较小值
	if (m > n)
	{
		max = n;
	}
	else
	{
		max = m;
	}


	while (1)
	{
		if (m % max == 0 && n % max == 0)
		{
			printf("最大公约数是：%d", max);
			break;
		}
		max--;
	}

	return 0;
}