/*
	字符串逆序
		编写一个函数 逆序字符串(char* string) (递归实现)

		实现：将参数字符串中的字符反向排列，不是逆序打印
		要求：不能使用C函数库中的字符串操作函数

		如
			char arr[] = "abcdef";
			逆序之后数组的内容变成：fedcba


		思路
			a和f交换
			b和e交换
			c和d交换

			char arr[] = "abcdef";
			要找到a和f就要定义一个下标

			left       right
			↓              ↓
			f  e  d  c  b  a
			a  b  c  d  e  f

		注意
			当把bcde交给 逆序字符串() 函数的时候不好交
			它往后看的时候后面不是\0会以为后面有个a

			所以先不把a移上去 主动在后面放个\0
			这时候bcde就能看成一个简单的字符串

			把bcde交给 逆序字符串() 函数
			逆序完成再把a移上去

*/

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

#include <string.h>

int 数组长度(char* str)
{
	int 计数器 = 0;
	while (*str != '\0')
	{
		计数器++;
		str++;// 向后找一个字符
	}
	return 计数器;
}

void 逆序字符串(char* str)
{
	int 长度 = 数组长度(str);

	char 容器 = *str;			//1
	*str = *(str + 长度 - 1);	//2
	*(str + 长度 - 1) = '\0';	//3
	if (数组长度(str + 1) >= 2)
	{
		逆序字符串(str + 1);			//4
	}
	*(str + 长度 - 1) = 容器;	//5
}

int main()
{
	char arr[] = "abcdef";
	逆序字符串(arr);// 数组名arr是数组arr首元素的地址

	printf("%s\n", arr);


	return 0;
}