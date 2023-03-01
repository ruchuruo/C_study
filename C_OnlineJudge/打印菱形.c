/*
	打印菱形
		在屏幕上打印菱形
			*
		   ***
		  *****
		 *******
		*********
		 *******
		  *****
		   ***
		    *
*/

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int 行 = 0;
	int i = 0;

	printf("请输入要打印的行数\n");
	scanf("%d", &行);

	//上
	for (i = 0; i < 行; i++)
	{
		// 打印一行
		// 空格
		int j = 0;
		for (j = 0; j < 行 - 1 - i; j++)
		{
			printf(" ");
		}

		// *
		for (j = 0; j < i * 2 + 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}


	//下
	for (i = 0; i < 行 - 1; i++)
	{
		// 打印一行
		// 空格
		int j = 0;
		for (j = 0; j <= i ; j++)
		{
			printf(" ");
		}
		
		// *
		for (j = 0; j < 2 * (行 - 1 - i) - 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	return 0;
}