
/*
	1 C++初识

	2 数据类型

	3 运算符

	4 程序流程结构

	5 数组

	6 函数

	7 指针

	8 结构体

		8.1 结构体基本概念

		8.2 结构体定义和使用

		8.3 结构体数组

			作用：将自定义的结构体放入到数组中方便维护

			语法： struct 结构体名 数组名[元素个数] = { {} , {} , ... {} }
*/

#include <iostream>

using namespace std;

//结构体定义
struct student
{
	//成员列表
	string name;//姓名
	int age;	//年龄
	int score;	//分数
};

int main()
{
	//结构体数组
	struct student arr[3] =
	{
		{"张三",18,80 },
		{"李四",19,60 },
		{"王五",20,70 }
	};

	arr[2].name = "赵六";

	for (int i = 0; i < 3; i++)
	{
		cout << " 姓名：" << arr[i].name
			 << " 年龄：" << arr[i].age
			 << " 分数：" << arr[i].score << endl;
	}

	return 0;
}