
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

			结构体属于用户 自定义的数据类型，允许用户存储不同的数据类型

		8.2 结构体定义和使用

			语法：struct 结构体名 { 结构体成员列表 }；

			通过结构体创建变量的方式有三种：

				struct 结构体名 变量名
				struct 结构体名 变量名 = { 成员1值 ， 成员2值...}
				定义结构体时顺便创建变量

			总结1：定义结构体时的关键字是struct，不可省略
			总结2：创建结构体变量时，关键字struct可以省略
			总结3：结构体变量利用操作符 ''.'' 访问成员

			来自弹幕：虽然现在struct和class一样（除了成员默认共有）struct的好处就是虚函数表不会攻击（压根没有），不用多态所以效率高（多态拖运行速度）
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
}stu3; //结构体变量创建方式3 


int main()
{
	//结构体变量创建方式1
	struct student stu1; //struct 关键字可以省略

	stu1.name = "张三";
	stu1.age = 18;
	stu1.score = 100;

	cout << "姓名：" << stu1.name << " 年龄：" << stu1.age << " 分数：" << stu1.score << endl;

	//结构体变量创建方式2
	struct student stu2 = { "李四",19,60 };

	cout << "姓名：" << stu2.name << " 年龄：" << stu2.age << " 分数：" << stu2.score << endl;


	stu3.name = "王五";
	stu3.age = 18;
	stu3.score = 80;


	cout << "姓名：" << stu3.name << " 年龄：" << stu3.age << " 分数：" << stu3.score << endl;

	return 0;
}