/*
	字符串逆序
		编写一个函数 逆序字符串(char* string) (非递归实现)

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
	int left = 0;
	int right = 数组长度(str) - 1;

	while (left < right)
	{
		char 容器 = str[left];
		str[left] = str[right];
		str[right] = 容器;
		left++;
		right--;
	}
}

int main()
{
	char arr[] = "abcdef";
	逆序字符串(arr);// 数组名arr是数组arr首元素的地址

	printf("%s\n", arr);


	return 0;
}