/*
	计算一个数的每位之和
		写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和
		如
			DigitSum(1729)，则返回1+7+2+9，它的和是 19
			输入：1729，输出：19

*/

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int DigitSum(int x)
{
	if (x > 9)
	{
		return DigitSum(x / 10) + (x % 10);
	}
	else
	{
		return x;
	}
}

int main()
{
	int num = 0;
	printf("请输入数字>");
	scanf("%u", &num);

	int sum = DigitSum(num);
	printf("%d\n", sum);





	return 0;
}