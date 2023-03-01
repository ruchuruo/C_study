
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

		8.5 结构体嵌套结构体

			作用： 结构体中的成员可以是另一个结构体

			例如：每个老师辅导一个学员，一个老师的结构体中，记录一个学生的结构体

			总结：在结构体中可以定义另一个结构体作为成员，用来解决实际问题
*/

#include <iostream>

using namespace std;

//学生结构体定义
struct student
{
	//成员列表
	string name;//姓名
	int age;	//年龄
	int score;	//分数
};

//教师结构体定义
struct teacher
{
	//成员列表
	int id; //职工编号
	string name;  //教师姓名
	int age;   //教师年龄
	struct student stu; //子结构体 学生
};


int main()
{
	struct teacher t1;
	t1.id = 10000;
	t1.name = "老王";
	t1.age = 40;

	t1.stu.name = "张三";
	t1.stu.age = 18;
	t1.stu.score = 100;

	cout << "教师 职工编号： " << t1.id << " 姓名： " << t1.name << " 年龄： " << t1.age << endl;

	cout << "辅导学员 姓名： " << t1.stu.name << " 年龄：" << t1.stu.age << " 考试分数： " << t1.stu.score << endl;

	return 0;
}