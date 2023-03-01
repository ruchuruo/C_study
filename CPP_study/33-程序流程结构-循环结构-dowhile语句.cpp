
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

				作用： 满足循环条件，执行循环语句

				语法： do{ 循环语句 } while(循环条件);

				注意：与while的区别在于 do...while会先执行一次循环语句，再判断循环条件

				总结：与while循环区别在于，do...while先执行一次循环语句，再判断循环条件
*/

#include <iostream>

using namespace std;

int main()
{
	int num = 0;

	do
	{
		cout << num << endl;
		num++;

	} while (num < 10);

	return 0;
}