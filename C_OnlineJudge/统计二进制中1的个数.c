/*
	统计二进制中1的个数
		写一个函数返回参数二进制中1的个数
		输入一个整数，输出该数32位二进制表示中1的个数，其中负数用补码表示

		NumberOf1()就是计算参数n的二进制补码中有几个1

		123
		123 % 10 = 3
		123 / 10 = 12
		12  % 10 = 2
		12  / 10 = 1
		1   % 10 = 1
		1   / 10 = 0

		15 --		  00001111
		15 % 2 = 1
		15 / 2 = 7 -- 00000111
		7  % 2 = 1
		7  / 2 = 3 -- 00000011
		3  % 2 = 1 -- 00000001
		3  / 2 = 1 -- 00000001
*/

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

// 以下输入-1计算不正确
//int NumberOf1(int n)
//{
//	int 计数器 = 0;
//	while (n)
//	{
//		if (n % 2 == 1)
//		{
//			计数器++;
//		}
//		n = n / 2;
//	}
//	return 计数器;
//}

// 修改 unsigned 会认为最高位的1 不是代表符号 -（负号）了。没有高位符号位这个说法了。全是数字位
//int NumberOf1(unsigned int n)
//{
//	int 计数器 = 0;
//	while (n)
//	{
//		if (n % 2 == 1)
//		{
//			计数器++;
//		}
//		n = n / 2;
//	}
//	return 计数器;
//}

// 方法2
//int NumberOf1(int n)
//{
//	int 计数器 = 0;
//	int i = 0;
//	for(i = 0; i < 32; i++)
//	{
//		if (((n >> i) & 1) == 1)
//		{
//			计数器++;
//		}
//	}
//	return 计数器;
//}

// 方法3
int NumberOf1(int n)
{
	int 计数器 = 0;
	while (n)
	{
		n = n & (n - 1);
		计数器++;
	}
	return 计数器;
}

int main()
{
	int n = -1;
	int ret = NumberOf1(n);
	printf("ret = %d\n", ret);

	return 0;
}