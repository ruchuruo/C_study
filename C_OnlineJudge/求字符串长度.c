/*

*/

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

#include <string.h>

// 练习2
// 编写函数不允许创建临时变量，求字符串长度
// 
// 模拟实现一个strlen函数
//int 字符串长度(char*数组)
//{
//	int 个数 = 0;
//	while (*数组 != '\0')
//	{
//		个数++;
//		数组++;
//	}
//	return 个数;
//}
// 递归
// 字符串长度("abc")
// 1 + 字符串长度("bc")
// 1 + 1 +字符串长度("c")
// 1 + 1 + 1 + 字符串长度("")
// 1 + 1 + 1 + 0 = 3
// 地址+1表示到下一个元素。
// 数组++ 是先使用再运算，这里是要先运算再使用
// ++数组 也不行，因为这是指针，自增运算改变了指针的位置，会改变实参
int 字符串长度(char* 数组)
{
	if (*数组 != '\0')
	{
		return 1 + 字符串长度(数组 + 1);
	}
	else
	{
		return 0;
	}
}

int main()
{
	// 练习2
	// 编写函数不允许创建临时变量，求字符串长度
	// 
	// 模拟实现一个strlen函数
	// ['a'] ['b'] ['c'] ['\0']
	char arr[] = "bit";
	printf("%d\n", 字符串长度(arr));

	return 0;
}