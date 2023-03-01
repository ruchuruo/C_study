


/*
	define 是一个预处理指令
		1.define 定义符号，定义标识符常量
		2.define 定义宏
*/

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

// define 定义标识符常量
#define Max 1000




// 2.define 定义宏
#define Add(x,y) x+y
//严谨写法
// x,y可能是一个表达式，应该括起来，(x) + (y)是一个宏体，也应该括起来
#define Add2(x,y) ((x) + (y))

int main()
{
	// define 定义标识符常量
	printf("%d\n", Max);




	// 2.define 定义宏
	printf("%d\n", 4*Add(2, 3));
	//			   4*2+3

	//
	printf("%d\n", 4 * Add2(2, 3));

	return 0;
}