
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

				案例描述：从1开始数到数字100， 如果数字个位含有7，或者数字十位含有7，或者该数字是7的倍数，我们打印敲桌子，其余数字直接打印输出。
*/

#include <iostream>

using namespace std;

void test1()
{
	// 先输出 1 到 100
	for (int i = 0; i <= 100; i++)
	{
		// 从这 100 个数字中找到特殊数字
		// 特殊数字 7的倍数，个位有7，十位有7
		// 7的倍数 (% 7)
		// 个位有7 (% 10 = 7)
		// 十位有7 (/ 10 = 7)
		if (i % 7 == 0 || i % 10 == 7 || i / 10 == 7)
		{
			cout << i << "敲桌子" << endl;
		}
		else
		{
			cout << i << endl;
		}
	}
}

void test2()
{
	int size = 100;	// 最大数字
	int desk = 7;	// 敲桌子
	int tmp = 0;	// 临时变量，用作计算

	for (int i = 0; i <= size; i++)
	{
		tmp = i;

		if (tmp % desk == 0)
		{
			cout << i << "敲桌子(倍数*)" << endl;
		}
		else
		{
			while (tmp >= desk)
			{
				if (tmp % 10 == desk)
				{
					cout << i << "敲桌子(位数%)" << endl;
				}

				tmp = tmp / 10;
			}
		}
	}
}



int main()
{
	
	test1();

	cout << "-------- -------- -------- --------" << endl;

	// 其他版本
	test2();

	return 0;
}