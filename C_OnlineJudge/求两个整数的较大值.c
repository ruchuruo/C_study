/*
	求两个整数的较大值
		写一个函数求两个整数的较大值
		如
			输入:10 20
			输出较大值:20

*/

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>



int intMAX(int x, int y)
{
	if (x > y)
	{
		return x;
	}
	else
	{
		return y;
	}
}

int main()
{
	int a = 0;
	int b = 0;

	printf("请输入两个整数\n");
	scanf("%d %d", &a, &b);

	int m = intMAX(a, b);
	printf("%d\n", m);



	return 0;
}