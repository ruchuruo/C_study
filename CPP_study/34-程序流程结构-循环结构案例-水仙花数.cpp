
/*
	1 C++初识

	2 数据类型

	3 运算符

	4 程序流程结构

		4.1 选择结构

		4.2 循环结构

			4.2.1 while循环语句

			while循环练习案例：猜数字

			4.2.2 do...while循环语句

			练习案例：水仙花数

				案例描述：水仙花数是指一个 3 位数，它的每个位上的数字的 3次幂之和等于它本身

				例如：1^3 + 5^3+ 3^3 = 153

				请利用do...while语句，求出所有3位数中的水仙花数

				思路：
					所有的三位数 100 到 999

					获取每个位

					个位^3 + 十位^3 + 百位^3 = 本身


				库函数 pow

					<cmath> (math.h)
					double pow (double base, double exponent);

					Raise to power
					Returns base raised to the power exponent:

					base ^ exponent

					提升权力
					返回提高到幂指数的基数：

					基数 ^ 指数


					参数
						base
						基础
						Base value.
						基值。

						exponent
						指数
						Exponent value.
						指数值。

					返回值
						The result of raising base to the power exponent.

						If the base is finite negative and the exponent is finite but not an integer value, it causes a domain error.
						If both base and exponent are zero, it may also cause a domain error on certain implementations.
						If base is zero and exponent is negative, it may cause a domain error or a pole error (or none, depending on the library implementation).
						The function may also cause a range error if the result is too great or too small to be represented by a value of the return type.
						
						提高权力的结果.

						如果 是有限负数，而 是有限的但不是整数值，则会导致域错误。
						如果两者均为零，则还可能导致某些实现出现域错误。
						如果为零且为负数，则可能会导致域错误或极点错误（或无，具体取决于库实现）。
						如果结果太大或太小而无法用返回类型的值表示，则该函数也可能导致范围错误。baseexponentbaseexponentbaseexponentbaseexponent

*/

#include <iostream>

using namespace std;

void test1()
{
	int num = 100;

	do
	{
		int a = 0; // 个位
		int b = 0; // 十位
		int c = 0; // 百位

		a = num % 10;
		b = num / 10 % 10;
		c = num / 100;

		if (a * a * a + b * b * b + c * c * c == num)
		{
			cout << num << endl;
		}

		num++;

	} while (num < 1000);
}

// 更好的
void test2()
{
	int i = 0;
	for (i = 0; i <= 100000; i++)
	{
		//判断i是否会自幂数
		// 1.计算i的位数 - n
		int 位数 = 1;
		int tmp = i;
		while (tmp / 10)
		{
			位数++;
			tmp = tmp / 10;
		}

		// 2.计算i的每一位的n次方之和
		tmp = i;
		int 和 = 0;
		while (tmp)
		{
			和 += pow(tmp % 10, 位数);
			tmp = tmp / 10;// 去掉某一位
		}

		// 3.判断
		if (和 == i)
		{
			printf("%d\n", i);
		}
	}
}

int main()
{

	test1();

	cout << "-------- -------- -------- --------" << endl;

	// 更好的
	test2();

	return 0;
}