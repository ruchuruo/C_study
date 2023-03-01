
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

			4.3.3 goto语句

				作用：可以无条件跳转语句

				语法： goto 标记;

				解释：如果标记的名称存在，执行到goto语句时，会跳转到标记的位置

				注意：在程序中不建议使用goto语句，以免造成程序流程混乱

				标记名称一般用大写，用小写也没问题
*/

#include <iostream>

using namespace std;

int main()
{
	cout << "1" << endl;

	goto FLAG;

	cout << "2" << endl;
	cout << "3" << endl;
	cout << "4" << endl;

FLAG:

	cout << "5" << endl;

	return 0;
}