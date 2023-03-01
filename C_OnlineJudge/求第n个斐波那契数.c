/*

*/

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

#include <string.h>

// 练习4
// 求第n个斐波那契数(不考虑溢出)
// 前两个数之和是斐波那契数
// 1 1 2 3 5 8 13 21 34 55
// 
// 公式
//		   --- n <= 2 , 1
//		   |
// Fib(n) -|
//		   |
//		   --- n > 2  , Fib(n - 1) + Fib(n - 2)
// 效率太低 - 重复大量计算
//													50
//							49												48
//				48						47						47						46
//		47				46		46				45		46				45		45				44
//
//
// 递归可以求解 但是效率低
//int Fib(int n2)
//{
//	if (n2 <= 2)
//	{
//		return 1;
//	}
//	else
//	{
//		return Fib(n2 - 1) + Fib(n2 - 2);
//	}
//}
// 
// 循环
// 1	1	2	3	5	8	13	21	34	55
// a	b	c
//		a	b	c
//			a	b	c
// 
int Fib(int n2)
{
	int a = 1;
	int b = 1;
	int c = 1;
	while (n2 > 2)
	{
		c = a + b;
		a = b;
		b = c;
		n2--;
	}
	return c;
}

int main()
{
	// 练习4
	// 求第n个斐波那契数(不考虑溢出)
	// 前两个数之和是斐波那契数
	// 1 1 2 3 5 8 13 21 34 55
	// 
	// 公式
	//		   --- n <= 2 , 1
	//		   |
	// Fib(n) -|
	//		   |
	//		   --- n > 2  , Fib(n - 1) + Fib(n - 2)
	int n2 = 0;
	printf("斐波那契>");
	scanf("%d", &n2);
	int ret2 = Fib(n2);
	printf("%d\n", ret2);

	return 0;
}