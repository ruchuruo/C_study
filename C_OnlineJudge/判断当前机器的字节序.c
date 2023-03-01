/*
	设计一个小程序来判断当前机器的字节序
*/

#include <stdio.h>

int 大小端()
{
	// 设计一个小程序来判断当前机器的字节序
	int a = 1;

	// 只拿第一个字节
	char* p = (char*)&a;// 强制类型转换 &a取出的是一个整形的地址
	if (*p == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

// 简化
int 大小端2()
{

	int a = 1;
	char* p = (char*)&a;
	return *p;// 返回1小端，返回0大端
}

int main()
{
	int ret = 大小端2();
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