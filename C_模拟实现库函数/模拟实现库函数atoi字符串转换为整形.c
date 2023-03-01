/*
	int atoi (const char * str);

	意外情况
		1. 空指针
		2. 空字符串
		3. 非数字字符
		4. 超出整形范围
		......

	正常情况只有一种，其他都是意外情况
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>

enum 状态
{
	非法,// 0
	合法 // 1
};

// state 记录的是 my_atoi 返回的值是合法转化的值，还是非法的状态
enum 状态 state = 非法;// 非法情况多，合法情况再置成合法

int my_atoi(const char* s)
{
	// 正负号+-，1正，-1负
	int 标志 = 0;
	
	// 空指针
	if (s == NULL)
	{
		return 0;
	}

	// 空字符串
	if (*s == '\0')
	{
		return 0;
	}

	// 跳过空白字符
	// int isspace ( int c );
	while (isspace(*s))// 是空白字符就返回非0值
	{
		s++;// 跳过一个字符
	}

	// 正负号+-
	if (*s == '+')
	{
		标志 = 1;
		s++;
	}
	else if(*s == '-')
	{
		标志 = -1;
		s++;
	}

	// 处理数字字符的转换
	// int isdigit ( int c );
	// 如果 c 确实是十进制数字，则不同于零的值（即 true）。否则为零（即假）。
	long long n = 0;
	while (isdigit(*s))// 检查字符是否为十进制数字
	{
		n = n * 10 + 标志 * (*s - '0');// 字符变量之间的相减就是对应的ASCII对应相减。

		if (n > INT_MAX || n < INT_MIN)// 判断是否超出整形
		{
			return 0;
		}

		s++;
	}

	// 非数字字符 或 \0
	if (*s == '\0')
	{
		// \0
		state = 合法;
		return (int)n;
	}
	else
	{
		// 非数字字符
		return (int)n;
	}
}

int main()
{
	char* p1 = "1234";
	char* p2 = "-1234";
	// const char* p3 = "12345";// "12345"是常量字符串，严格意义上不允许修改，如果指针p不加const，可以修改它所指向的东西

	int ret1 = atoi(p1);
	int ret2 = atoi(p2);

	printf("%d\n", ret1);
	printf("%d\n", ret2);

	// -------- -------- -------- --------

	const char* p3 = "   -12a";
	int ret3 = my_atoi(p3);
	if (state == 合法)
	{
		printf("合法：%d\n", ret3);
	}
	else
	{
		printf("非法：%d\n", ret3);
	}
	
	return 0;
}