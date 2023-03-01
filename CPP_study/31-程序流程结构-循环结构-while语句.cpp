
/*
	1 C++初识

	2 数据类型

	3 运算符

	4 程序流程结构

		4.1 选择结构

		4.2 循环结构

			4.2.1 while循环语句

				作用：满足循环条件，执行循环语句

				语法： while(循环条件){ 循环语句 }

				解释：只要循环条件的结果为真，就执行循环语句

				注意：在执行循环语句时候，程序必须提供跳出循环的出口，否则出现死循环
*/

#include <iostream>

using namespace std;

int main()
{
	int num = 0;
	while (num < 10)
	{
		cout << "num = " << num << endl;
		num++;
	}

	return 0;
}