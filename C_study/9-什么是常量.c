


/*
	常量分为以下几种
		字面常量
		const 修饰的常变量
		#define 定义的标识符常量
		枚举常量
*/
#include <stdio.h>

#define MAX 32767

int main()
{
	// 字面常量
	3.14;
	'abcd';

	// const 修饰的常变量
	const int num = 10;// 常变量 具有常属性(不能被改变的属性)
	const int n = 10;
	//int arr[n] = { 0 };// n是变量 这里不行


	// #define 定义的标识符常量
	//MAX = 100;// #define的不能改
	int a = MAX;
	printf("a = %d\n", a);



	// 枚举常量 - 可以一一列举的常量
	// enum 枚举关键字
	// 性别
	enum Sex
	{
		// 这种枚举类型的变量的 未来可能取值
		// 枚举常量
		男 = 5,//	赋初值
		女,
		保密
	};
	// 只能取值常量中的值
	enum Sex s = 男;

	printf("%d\n", 男);		// 0
	printf("%d\n", 女);		// 1
	printf("%d\n", 保密);	// 2

	return 0;
}