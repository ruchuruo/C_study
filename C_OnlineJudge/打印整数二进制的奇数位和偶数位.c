/*
	打印整数二进制的奇数位和偶数位
		获取一个整数二进制序列中所有的偶数位和奇数位，分别打印出二进制序列
*/

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int n = 0;
	printf("请输入\n");
	scanf("%d", &n);

	// 获取n的二进制中的偶数位
	int i = 0;
	for (i = 31; i >= 1; i -= 2)
	{
		printf("%d ", (n >> i) & 1);
	}

	printf("\n");

	// 获取n的二进制中的奇数位
	for (i = 30; i >= 0; i -= 2)
	{
		printf("%d ", (n >> i) & 1);
	}

	return 0;
}