
/*
	1 C++初识

	2 数据类型

	3 运算符

	4 程序流程结构

		4.1 选择结构

		4.2 循环结构

		4.3 跳转语句

			4.3.1 break语句

			4.3.2 continue语句

				作用：在 循环语句 中，跳过本次循环中余下尚未执行的语句，继续执行下一次循环

				注意：continue并没有使整个循环终止，而break会跳出循环
*/

#include <iostream>

using namespace std;

int main()
{

	for (int i = 0; i < 100; i++)
	{
		if (i % 2 == 0)
		{
			continue;
		}
		cout << i << endl;
	}

	return 0;
}