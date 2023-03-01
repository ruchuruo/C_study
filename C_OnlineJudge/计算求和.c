/*
	计算求和
		求Sn = a + aa + aaa + aaaa + aaaaa的前5项之和，其中a是一个数字

		例如： 2 + 22 + 222 + 2222 + 22222

		2 + (2*10+2) + (22*10+2)......
*/
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int a = 0;
	int n = 0;
	int sum = 0;
	int ret = 0;// 一项

	printf("a组成的前n项之和>");
	scanf("%d %d", &a, &n);

	int i = 0;
	for (i = 0; i < n; i++)
	{
		// 算出一项
		ret = ret * 10 + a;
		sum = sum + ret;
	}
	printf("%d\n", sum);

	return 0;
}