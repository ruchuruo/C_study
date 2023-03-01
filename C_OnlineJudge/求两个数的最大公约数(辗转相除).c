/*
	求两个数的最大公约数
		同时整除这两个数
		
		m % n不等于0，就把n的值赋给m，t的值赋给n，然后继续
		如果t为0那最大公约数就是n
			m		n		t
			24	%	18	=	6
			18	%	6	=	0

*/

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int m = 0;
	int n = 0;
	int t = 0;

	printf("请输入两个整数\n");
	scanf("%d %d", &m, &n);//24 18

	// m % n 的结果不为0就进入循环
	while (m % n)
	{
		t = m % n;
		m = n;
		n = t;
	}
	printf("最大公约数：%d", n);


	return 0;
}