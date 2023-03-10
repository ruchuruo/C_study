

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



		函数递归
			什么是递归？(函数自己调用自己)
				程序调用自身的编程技巧称为递归(recursion)。递归作为一种算法在程序设计语言中广泛应用。
				一个过程或函数在其定义或说明中有直接或间接调用自身的一种方法，它通常把一个大型复杂的
				问题层层转化为一个与原问题相似的规模较小的问题来求解，递归策略只需少量的程序就可以描述
				出解题过程所需要的多次重复计算，大大地减少了程序的代码量。递归的主要思考方式在于：大事化小

			递归的两个必要条件(必要 不充足)
				1.存在限制条件，当满足这个限制条件的时候，递归便不在继续
				2.每次递归调用之后越来越接近这个限制条件

			每次调用函数都会在栈区开辟一个新空间
			写递归代码的时候
				1.不能死递归，要有跳出条件，每次递归要逼近跳出条件
				2.递归层次不能太深，不然也会栈溢出


		https://stackoverflow.com/
		程序员的知乎
*/

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//int main()
//{
//	// 这就是递归，死循环，错误的示范
//	printf("hehe\n");
//	main();
//	return 0;
//}











// 练习1																 千百 十个
// 接受一个整形值(无符号)，按照顺序打印它的每一位。例如输入：1234，输出：1 2 3 4
// 打印(1234) 
// 打印(123)   4
// 打印(12)  3 4
// 打印(1) 2 3 4
// 
void 打印(unsigned int x)
{
	if (x > 9)
	{
		打印(x / 10);// 这里的结果再传给void 打印(unsigned int x)
	}
	printf("%d ", x % 10);
}





int main()
{
	// 练习1																 千百 十个
	// 接受一个整形值(无符号)，按照顺序打印它的每一位。例如输入：1234，输出：1 2 3 4
	// 1234 % 10 =			  4
	// 1234 / 10 = 123 % 10 = 3
	// 123  / 10 = 12  % 10 = 2
	// 12   / 10 = 1   % 10 = 1
	// 1    / 10 = 0

	//无符号 整形
	unsigned int num = 0;
	printf("请输入数字>");
	// %u 无符号整形
	scanf("%u", &num);

	// 递归 - 函数自己调用自己
	打印(num);// 打印 函数可以打印参数部分数字的每一位











	// 练习2
	// 编写函数不允许创建临时变量，求字符串长度
	// 



	return 0;
}