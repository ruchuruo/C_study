
/*
	1 C++初识

	2 数据类型

	3 运算符

		3.2 赋值运算符

			作用：用于将表达式的值赋给变量

			赋值运算符包括以下几个符号：

				|   运算符   |   术语   |   示例     |   结果    |
				| ---------- | -------- | ---------- | --------- |
				| =          | 赋值     | a=2; b=3;  | a=2; b=3; |
				| +=         | 加等于   | a=0; a+=2; | a=2;      |
				| -=         | 减等于   | a=5; a-=3; | a=2;      |
				| *=         | 乘等于   | a=2; a*=2; | a=4;      |
				| /=         | 除等于   | a=4; a/=2; | a=2;      |
				| %=         | 模等于   | a=3; a%2;  | a=1;      |
*/

#include <iostream>

using namespace std;

int main()
{
	//赋值运算符

	// =
	int a = 10;
	a = 100;
	cout << "a = " << a << endl;

	// +=
	a = 10;
	a += 2; // a = a + 2;
	cout << "a = " << a << endl;

	// -=
	a = 10;
	a -= 2; // a = a - 2
	cout << "a = " << a << endl;

	// *=
	a = 10;
	a *= 2; // a = a * 2
	cout << "a = " << a << endl;

	// /=
	a = 10;
	a /= 2;  // a = a / 2;
	cout << "a = " << a << endl;

	// %=
	a = 10;
	a %= 2;  // a = a % 2;
	cout << "a = " << a << endl;

	return 0;
}