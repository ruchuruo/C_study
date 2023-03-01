

/*

	函数
		本章节主要掌握函数的基本使用和递归
			1.函数是什么
			2.库函数
			3.自定义函数
			4.函数参数
			5.函数调用
			6.函数的嵌套调用和链式访问
			7.函数的声明和定义
			8.函数递归

		C语言中函数的分类
			1.库函数
			2.自定义函数

		C语言常用的库函数
			IO函数(输入输出函数)			printf scanf getchar putchar
			字符串操作函数				strcmp strlen
			字符操作函数					toupper
			内存操作函数					memcpy memcmp memset
			时间/日期函数				time
			数学函数						sqrt pow
			其他库函数					
*/

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

// strcpy
#include <string.h>

int main()
{
	char arr1[20] = { 0 };
	char arr2[] = "hello bit";
	// 吧arr2的字符串拷贝到arr1
	//     目的地
	strcpy(arr1, arr2);
	printf("%s\n", arr1);// 打印arr1这个字符串 %s 以字符串的格式来打印



	// memory - 记忆 - 内存
	// memset - 内存设置
	// 
	// 
	char arr3[] = "hello bit2";
	//设置 arr3, 'x', 前5个字节
	memset(arr3, 'x', 5);
	printf("%s\n", arr3);


	return 0;
}