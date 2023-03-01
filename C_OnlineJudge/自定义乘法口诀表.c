/*
	乘法口诀表
		1*1=1
		2*1=2 2*2=4
		3*1=3 3*2=6 3*3=9
		......

		实现一个函数，打印乘法口诀表，口诀表的行数和列数可自定义
		如
			输入9 输出9*9口诀表
			输入12 输出12*12口诀表

*/

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>


void 乘法口诀表(int n)
{
	int i = 0;
	int j = 0;

	// 行
	for (i = 1; i <= n; i++)
	{
		// 打印一行
		for (j = 1; j <= i; j++)
		{
			printf("%d*%d=%-2d ", i, j, i * j);
		}
		// 换行
		printf("\n");
	}
}

int main()
{
	int n = 0;

	printf("输入要打印 乘法口诀表 的行数\n");
	scanf("%d", &n);

	乘法口诀表(n);





	return 0;
}