/*
	计算
	1/1 - 1/2 + 1/3 - 1/4 + 1/5......+ 1/99 - 1/100
	的值

*/

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

// 方法1

//int main()
//{
//	int i = 0;
//	double sum = 0.0;
//
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 2 == 0)
//		{
//			sum = sum - 1.0 / i;
//		}
//		else
//		{
//			sum = sum + 1.0 / i;
//		}
//	}
//	printf("%lf\n", sum);
//	return 0;
//}



// 方法2

int main()
{
	int i = 0;
	double sum = 0.0;
	int flag = 1;

	for (i = 1; i <= 100; i++)
	{
			sum = sum + flag*1.0 / i;// 下一次加上一个正数或负数
			flag = -flag;// 正变负 负变正
	}
	printf("%lf\n", sum);
	return 0;
}