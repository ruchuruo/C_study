/*
	打印素数
		写一个代码打印100-200之间的素数

		素数 - 质数
		只能被1和本身整除

		拿2到i-1之间的数字去试除，看能不能整除，能就不是

*/

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int i = 0;
	int j = 0;

	for (i = 100; i <= 200; i++)
	{
		for (j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				break;
			}
		}
		// 跳出来到这
		if (i == j)
		{
			printf("%d ", i);// 素数
		}
	}
	return 0;
}