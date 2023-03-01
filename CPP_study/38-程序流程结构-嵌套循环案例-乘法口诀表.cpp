
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

			4.2.3 for循环语句

			练习案例：敲桌子

			4.2.4 嵌套循环

			练习案例：乘法口诀表

				案例描述：利用嵌套循环，实现九九乘法表
*/

#include <iostream>

using namespace std;

int main()
{
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << i << " * " << j << " = " << i * j << " ";
		}

		cout << endl;
	}

	return 0;
}