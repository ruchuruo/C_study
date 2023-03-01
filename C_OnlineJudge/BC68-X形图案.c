/*
	打印用 * 组成的X形图案

	多组输入，一个整数(2~20)，表示输出的行数，也表示组成 X 的反斜线和正斜线的长度

	输入5
	输出：
		*   *
		 * *
		  *
		 * *
		*   *
	
	输入6
	输出：
		 *    *
		  *  *
		   **
		   **
		  *  *
		 *    *
	
*/
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int n = 0;

	printf("开始输入ctrl+c停止>");
	while (scanf("%d", &n) != EOF)
	{
		int i = 0;
		for (i = 0; i < n; i++)
		{
			int j = 0;
			for (j = 0; j < n; j++)
			{
				if (i == j)
				{
					printf("*");
				}
				else if (i + j == n - 1)
				{
					printf("*");
				}
				else
				{
					printf(" ");
				}
			}
			printf("\n");
		}
	}

	return 0;
}