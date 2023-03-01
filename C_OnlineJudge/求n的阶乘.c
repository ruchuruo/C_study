/*

*/

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

#include <string.h>

// 递归与迭代
// 练习3
// 求n的阶乘(不考虑溢出)
// n!
// 1*2*3*...*n
// 
// 阶乘数学公式
//		   --- n <= 1 , 1
//		   |
// Fac(n) -|
//		   |
//		   --- n > 1  , n * Fac(n - 1)
int Fac(int n)
{
	if (n <= 1)
	{
		return 1;
	}
	else
	{
		return n * Fac(n - 1);
	}
}

int main()
{
	// 递归与迭代
	// 练习3
	// 求n的阶乘(不考虑溢出)
	// n!
	// 1*2*3*...*n
	// 
	// 阶乘数学公式
	//		   --- n <= 1 , 1
	//		   |
	// Fac(n) -|
	//		   |
	//		   --- n > 1  , n * Fac(n - 1)
	//int n = 0;
	//int i = 0;
	//int ret = 1;
	//printf("阶乘>")
	//scanf("%d", &n);
	//// 循环也可也称谓迭代
	//for (i = 1; i <= n; i++)
	//{
	//	ret = ret * i;
	//}
	//printf("%d\n", ret);

	int n = 0;
	printf("阶乘>");
	scanf("%d", &n);
	int ret = Fac(n);
	printf("%d\n", ret);

	return 0;
}