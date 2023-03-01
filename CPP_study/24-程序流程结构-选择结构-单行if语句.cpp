
/*
	1 C++初识

	2 数据类型

	3 运算符

	4 程序流程结构

		C/C++支持最基本的三种程序运行结构：顺序结构、选择结构、循环结构

		顺序结构：程序按顺序执行，不发生跳转
		选择结构：依据条件是否满足，有选择的执行相应功能
		循环结构：依据条件是否满足，循环多次执行某段代码

		4.1 选择结构

			4.1.1 if语句

				作用：执行满足条件的语句

				if语句的三种形式

					单行格式if语句
						单行格式if语句：if(条件){ 条件满足执行的语句 }

					多行格式if语句
						多行格式if语句：if(条件){ 条件满足执行的语句 }else{ 条件不满足执行的语句 };

					多条件的if语句
						多条件的if语句：if(条件1){ 条件1满足执行的语句 }else if(条件2){条件2满足执行的语句}... else{ 都不满足执行的语句}

				注意：if条件表达式后不要加分号
*/

#include <iostream>

using namespace std;

void test1()
{
	//选择结构-单行if语句
	//输入一个分数，如果分数大于600分，视为考上一本大学，并在屏幕上打印

	int score = 0;
	cout << "请输入一个分数：" << endl;
	cin >> score;

	cout << "您输入的分数为： " << score << endl;

	//if语句
	//注意事项，在if判断语句后面，不要加分号
	if (score > 600)
	{
		cout << "我考上了一本大学！！！" << endl;
	}
}

void test2()
{
	// 多行格式if语句

	int score = 0;

	cout << "请输入考试分数：" << endl;

	cin >> score;

	if (score > 600)
	{
		cout << "我考上了一本大学" << endl;
	}
	else
	{
		cout << "我未考上一本大学" << endl;
	}
}

void test3()
{
	// 多条件的if语句

	int score = 0;

	cout << "请输入考试分数：" << endl;

	cin >> score;

	if (score > 600)
	{
		cout << "我考上了一本大学" << endl;
	}
	else if (score > 500)
	{
		cout << "我考上了二本大学" << endl;
	}
	else if (score > 400)
	{
		cout << "我考上了三本大学" << endl;
	}
	else
	{
		cout << "我未考上本科" << endl;
	}
}

void test4()
{
	/*
		嵌套if语句

		案例需求：
			提示用户输入一个高考考试分数，根据分数做如下判断
			分数如果大于600分视为考上一本，大于500分考上二本，大于400考上三本，其余视为未考上本科；
			在一本分数中，如果大于700分，考入北大，大于650分，考入清华，大于600考入人大。
	*/

	int score = 0;

	cout << "请输入考试分数：" << endl;

	cin >> score;

	if (score > 600)
	{
		cout << "我考上了一本大学" << endl;
		if (score > 700)
		{
			cout << "我考上了北大" << endl;
		}
		else if (score > 650)
		{
			cout << "我考上了清华" << endl;
		}
		else
		{
			cout << "我考上了人大" << endl;
		}

	}
	else if (score > 500)
	{
		cout << "我考上了二本大学" << endl;
	}
	else if (score > 400)
	{
		cout << "我考上了三本大学" << endl;
	}
	else
	{
		cout << "我未考上本科" << endl;
	}
}

int main()
{
	// 单行格式if语句
	test1();

	cout << "-------- -------- -------- --------" << endl;

	// 多行格式if语句
	test2();

	cout << "-------- -------- -------- --------" << endl;

	// 多条件的if语句
	test3();

	cout << "-------- -------- -------- --------" << endl;

	// 嵌套if语句：在if语句中，可以嵌套使用if语句，达到更精确的条件判断
	test4();

	return 0;
}