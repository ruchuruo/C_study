/*
	求两个数二进制中不同位的个数
		编程实现：两个int(32位)整数m和n的二进制表达中，有多少个位(bit)不同
		输入例子：1999 2299
		输出例子：7
*/

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int f1(int m, int n)
{
	int 计数器 = 0;
	int i = 0;
	for (i = 0; i < 32; i++)
	{
		if (((m >> i) & 1) != ((n >> i) & 1))
		{
			计数器++;
		}
	}
	return 计数器;
}


// 改进
// 统计一下ret的二进制中有几个1，就说明m和n的二进制位中有几个位不同
int f2(int n)
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
	int m = 1999;
	int n = 2299;

	int ret = f1(m, n);
	printf("%d\n", ret);
	

	int ret2 = m ^ n;// 相同为0 相异为1
	int count = f2(ret2);
	printf("%d\n", count);

	return 0;
}