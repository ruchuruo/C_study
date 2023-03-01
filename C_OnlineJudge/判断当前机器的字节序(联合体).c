/*
	设计一个小程序来判断当前机器的字节序

	使用联合体
*/

#include <stdio.h>

int 大小端()
{
	union U
	{
		char c;
		int i;
	}u;

	u.i = 1;

	return u.c;
}

int main()
{
	int ret = 大小端();
	if (ret == 1)
	{
		printf("小端\n");
	}
	else
	{
		printf("大端\n");
	}

	return 0;
}