
/*
	1 C++初识

	2 数据类型

	3 运算符

	4 程序流程结构

	5 数组

		5.1 概述

		5.2 一维数组

		5.3 二维数组

			5.3.1 二维数组定义方式

			5.3.2 二维数组数组名

			5.3.3 二维数组应用案例

				考试成绩统计：

					案例描述：有三名同学（张三，李四，王五），在一次考试中的成绩分别如下表，请分别输出三名同学的总成绩

					|      | 语文 | 数学 | 英语 |
					| ---- | ---- | ---- | ---- |
					| 张三 | 100  | 100  | 100  |
					| 李四 | 90   | 50   | 100  |
					| 王五 | 60   | 70   | 80   |
*/

#include <iostream>

using namespace std;

void test1()
{
	// 参考答案：

	int scores[3][3] =
	{
		{100,100,100},
		{90,50,100},
		{60,70,80},
	};

	string names[3] = { "张三","李四","王五" };

	for (int i = 0; i < 3; i++)
	{
		int sum = 0;
		for (int j = 0; j < 3; j++)
		{
			sum += scores[i][j];
		}
		cout << names[i] << "同学总成绩为： " << sum << endl;
	}
}

void test2()
{

}

int main()
{
	// 参考答案：
	test1();

	cout << "-------- -------- -------- --------" << endl;

	test2();

	return 0;
}