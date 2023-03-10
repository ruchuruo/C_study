
/*
	1 C++初识

	2 数据类型

	3 运算符

		3.3 比较运算符

			作用：用于表达式的比较，并返回一个真值或假值

			比较运算符有以下符号：

				|   运算符   |   术语   |   示例   |   结果   |
				| ---------- | -------- | -------- | -------- |
				| ==         | 相等于   | 4 == 3   | 0        |
				| !=         | 不等于   | 4 != 3   | 1        |
				| <          | 小于     | 4 < 3    | 0        |
				| >          | 大于     | 4 > 3    | 1        |
				| <=         | 小于等于 | 4 <= 3   | 0        |
				| >=         | 大于等于 | 4 >= 1   | 1        |

			注意：C和C++ 语言的比较运算中，“真”用数字“1”来表示， “假”用数字“0”来表示。
*/

#include <iostream>

using namespace std;

int main()
{
	int a = 10;
	int b = 20;

	// 不加括号 << 就会跟 a 匹配，输出 a，但是后面紧跟着 == 号 计算机就不懂你什么意思了

	cout << (a == b) << endl; // 0 

	cout << (a != b) << endl; // 1

	cout << (a > b) << endl; // 0

	cout << (a < b) << endl; // 1

	cout << (a >= b) << endl; // 0

	cout << (a <= b) << endl; // 1

	return 0;
}