
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

		8.4 结构体指针

			作用：通过指针访问结构体中的成员

			利用操作符 -> 可以通过结构体指针访问结构体属性

			总结：结构体指针可以通过 -> 操作符 来访问结构体中的成员

			来自弹幕：也可以用(*p).naem访问，等价p->name
*/

#include <iostream>

using namespace std;

//结构体定义
struct student
{
	//成员列表
	string name;  //姓名
	int age;      //年龄
	int score;    //分数
};


int main()
{
	struct student stu = { "张三",18,100, };

	struct student* p = &stu;

	p->score = 80; //指针通过 -> 操作符可以访问成员

	cout << "姓名：" << p->name << " 年龄：" << p->age << " 分数：" << p->score << endl;

	return 0;
}