
/*
	结构体
		可以让c语言创建新的类型出来

			// 创建一个学生
				struct 学生
				{
					// 注意括号里面的是数组的长度，也就是有多少个name，数组老师后面会讲
					char 名字[20];
					int 年龄;
					double 成绩;
				};

			// 创建一个书的类型
				struct 书
				{
					char 名字[20];
					float 价格;
					char 书号[30];
				}

*/


#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>






// 创建一个学生
struct 学生
{
	// 注意括号里面的是数组的长度，也就是有多少个name，数组老师后面会讲
	char 名字[20];// 成员变量
	int 年龄;
	double 成绩;
};

// 创建一个书的类型
struct 书
{
	char 名字[20];
	float 价格;
	char 书号[30];
};

int main()
{
	struct 学生 s = { "张三", 20, 85.5 };// 结构体的创建和初始化
	printf("1:%s %d %lf\n", s.名字, s.年龄, s.成绩);//结构体变量.成员变量


	struct 学生* ps = &s;
	printf("2:%s %d %lf\n", (*ps).名字, (*ps).年龄, (*ps).成绩);
	printf("3:%s %d %lf\n", ps->名字, ps->年龄, ps->成绩);// 结构体指针->成员变量名


	return 0;
}