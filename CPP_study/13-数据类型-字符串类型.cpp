
/*
	1 C++初识

	2 数据类型

		2.6 字符串型

			作用：用于表示一串字符

			两种风格

				C风格字符串： char 变量名[] = "字符串值"
				C++风格字符串： string 变量名 = "字符串值"
*/

#include <iostream>

using namespace std;

int main()
{
	// C
	// 注意：C风格的字符串要用双引号括起来
	char str1[] = "C hello world";
	cout << str1 << endl;

	// C++
	// 注意：C++风格字符串，需要加入头文件 #include<string>
	string str = "CPP hello world";
	cout << str << endl;

	return 0;
}