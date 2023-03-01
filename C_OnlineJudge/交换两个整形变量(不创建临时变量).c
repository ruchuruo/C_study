/*
	交换两个整形变量(不创建临时变量)
		不允许创建临时变量，交换两个整数的内容
*/

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

// 以下如果数值过大会溢出
void f1(int a, int b)
{
	printf("交换前：a = %d, b = %d\n", a, b);
	a = a + b;// a = 10 + 20 = 30
	b = a - b;// b = 30 - 20 = 10
	a = a - b;// a = 30 - 10 = 20
	printf("交换后：a = %d, b = %d\n", a, b);
}

void f2(int a, int b)
{
	printf("交换前：a = %d, b = %d\n", a, b);
	a = a ^ b;
	b = a ^ b;// a ^ b ^ b
	a = a ^ b;// a ^ b ^ a
	printf("交换后：a = %d, b = %d\n", a, b);
}

int main()
{
	int a = 10;
	int b = 20;
	f1(a, b);
	f2(a, b);

	return 0;
}