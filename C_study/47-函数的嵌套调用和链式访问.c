

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



		函数返回类型	 ----------------函数的参数------------------
		 ↓			↓                                           ↓
		char *strcpy(char *strDestination, const char *strSource);
				↑
			  函数名


		函数的参数
			函数调用传输的参数 叫 实际参数
			函数定义接收的参数 叫 形式参数

			实参
				真实传给函数的参数，叫实际参数。实参可以是：常量 变量 表达式 函数等。
				无论实参是何种类型的量，在进行函数调用时，它们都必须有确定的值，以便把他们这些值传送给形式参数

			形参
				形式参数是指函数名后括号中的变量 因为形式参数只有在函数被调用的过程中才实例化(分配内存单元)，
				所以叫形式参数。形式参数当函数调用完成之后就自动销毁。因此形式参数只在函数中有效


		函数的调用
			传值调用
				函数的形参和实参分别占有不同内存块，对形参的修改不会影响实参

			传址调用
				传址调用是吧函数外部创建变量的内存地址传递给函数参数的一种调用函数的方式。
				这种传参方式可以让函数和函数外边的变量建立起正真的联系，也就是函数内部可以直接操作函数外部的变量。



		函数的嵌套调用和链式访问
			嵌套调用
				函数不能嵌套定义 例如:
					int test1()
					{
						int test2()
						{
					
						}
					}

				函数可以嵌套调用 例如
					int test1()
					{
						test2();
					}

					int test3()
					{
						test1();
					}

			链式访问
				把一个函数的返回值作为另外一个函数的参数




		函数的声明和定义
			函数声明
				1.告诉编译器有一个函数叫什么，参数是什么，返回类型是什么。具体无关紧要
				2.函数的声明一般出现在函数的使用之前。要满足先声明后使用。
				3.函数的声明一般要放在头文件中

			函数定义
				函数的定义是指函数的具体实现，交待函数的功能实现
*/

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

#include <string.h>


#include "test.h"

//假设 导入静态库.lib
//#pragma comment(lib, "test.lib")
// 静态库是.c 和 .h文件编译产生的


int main()
{
	// 求字符串长度
	int len = strlen("abc");
	printf("%d\n", len);

	// 链式访问
	printf("%d\n", strlen("abc")); 

	char arr1[20] = { 0 };
	char arr2[] = "bit";
	strcpy(arr1, arr2);
	printf("%s\n", arr1);
	printf("%s\n", strcpy(arr1, arr2));

	// printf函数返回的是打印在屏幕上的字符的个数
	printf("%d", printf("%d", printf("%d", 43)));












	int a = 10;
	int b = 20;
	// 函数声明
	int Add(int, int);

	int c = Add(a, b);
	printf("\n%d\n", c);


	









	return 0;
}

int Add(int x, int y)
{
	return x + y;
}