


/*
	%d - 整形
	%f - 浮点
	%lf - double

	变量分类
		局部变量		大括号 内 定义的变量都叫 局部变量
		全局变量		大括号 外 定义的变量都叫 全局变量

		当 局部变量 和 全局变量 名字冲突的情况下 局部变量 优先
		

	scanf_s函数
		VS编译器提供的 不说C语言标准规定的
*/

// scanf报错解决办法
// 源文件第一行加上：#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

// 全局变量
int a = 100;

int main()
{
	// 创建一个变量
	// 类型 变量名 = 0;(推荐)
	// 类型 变量名;(不推荐)
	int age = 20;
	double weight = 75.3;

	age = age + 1;
	weight = weight - 10;
	printf("%d\n", age);
	printf("%lf\n", weight);


	// 局部变量
	int a = 10;

	printf("%d\n", a);



	// 求两个整数的和
	// scanf函数是输入函数
	int aa = 0;
	int bb = 0;
	int sum = 0;
	scanf("%d %d", &aa, &bb);
	sum = aa + bb;
	printf("sum = %d\n", sum);















	return 0;
}