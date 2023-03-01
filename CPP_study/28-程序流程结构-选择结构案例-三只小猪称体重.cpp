
/*
	1 C++初识

	2 数据类型

	3 运算符

	4 程序流程结构

		4.1 选择结构

			4.1.1 if语句

			练习案例： 三只小猪称体重

				有三只小猪ABC，请分别输入三只小猪的体重，并且判断哪只小猪最重？
*/

#include <iostream>

using namespace std;

int main()
{
	int pig_a = 0;
	int pig_b = 0;
	int pig_c = 0;

	cout << "猪a的体重>";
	cin >> pig_a;

	cout << "猪b的体重>";
	cin >> pig_b;

	cout << "猪c的体重>";
	cin >> pig_c;

	if (pig_a > pig_b)
	{
		if (pig_a > pig_c)
		{
			cout << "a最重" << endl;
		}
		else
		{
			cout << "c最重" << endl;
		}
	}
	else
	{
		if (pig_b > pig_c)
		{
			cout << "b最重" << endl;
		}
		else
		{
			cout << "c最重" << endl;
		}
	}

	return 0;
}