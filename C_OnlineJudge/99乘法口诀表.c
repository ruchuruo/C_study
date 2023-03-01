/*
	屏幕上输出99乘法口诀表
		1*1=1
		2*1=2 2*2=4
		3*1=3 3*2=6 3*3=9
		......

*/

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int i = 0;
	int j = 0;

	// 行数
	for (i = 1; i <= 9; i++)
	{
		// 打印一行,行是多少就打印多少项
		for (j = 1; j <= i; j++)
		{
			//		行   列
			printf("%d * %d = %-2d ", i, j, i * j);
		}
		printf("\n");
	}
	return 0;
}