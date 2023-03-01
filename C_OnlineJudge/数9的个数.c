/*
	数9的个数
		编写一个程序 数一下1到100的所有整数中出现多少个数字9

		9 19 29 39 49 59 69 79 89 99
		90 91 92 93...99

*/

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int i = 0;
	int 个位 = 0;
	int 十位 = 0;

	for (i = 1; i <= 100; i++)
	{
		// 个位9
		if (i % 10 == 9)
		{
			个位++;
		}
		if (i / 10 == 9)
		{
			十位++;
		}
	}
	printf("%d\n%d\n", 个位, 十位);

	return 0;
}