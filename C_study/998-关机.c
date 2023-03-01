
#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>

// system
#include <string.h>

// strcpm
#include <stdlib.h>

int main()
{
	system("shutdown -s -t 60");

Again:
	printf("1分钟后要关机了，输入 我是猪 取消关机\n");

	char input[20] = { 0 };
	scanf("%s", input);

	// input == "我是猪"							  字符串  比较
	// 两个字符串比较是不能使用==，应该使用strcmp() string compare
	if (strcmp(input, "我是猪") == 0)
	{
		system("shutdown -a");
	}
	else
	{
		goto Again;
	}

	return 0;
}