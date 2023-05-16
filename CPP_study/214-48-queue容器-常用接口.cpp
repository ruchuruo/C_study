
/*
	第1阶段C++ 匠心之作 从0到1入门

	第2阶段实战-通讯录管理

	第3阶段-C++核心编程

	第4阶段实战-基于多态的企业职工系统

	第5阶段-C++提高编程

		1 模板

		2 STL初识

		3 STL- 常用容器

			3.1 string容器

			3.2 vector容器

			3.3 deque容器

			3.4 案例-评委打分

			3.5 stack容器

			3.6 queue 容器

				3.6.1 queue 基本概念

				3.6.2 queue 常用接口

					功能描述：栈容器常用的对外接口

					构造函数：

						queue<T> que;                       //queue采用模板类实现，queue对象的默认构造形式
						queue(const queue &que);            //拷贝构造函数

					赋值操作：

						queue& operator=(const queue &que); //重载等号操作符

					数据存取：

						push(elem);                         //往队尾添加元素
						pop();                              //从队头移除第一个元素
						back();                             //返回最后一个元素
						front();                            //返回第一个元素

					大小操作：

						empty();                            //判断堆栈是否为空
						size();                             //返回栈的大小

					总结：

						入队          --- push
						出队          --- pop
						返回队头元素   --- front
						返回队尾元素   --- back
						判断队是否为空 --- empty
						返回队列大小   --- size
*/

#include <iostream>
#include <queue>

using namespace std;


class Person
{
public:
	Person(string name, int age):m_Name(name), m_Age(age) {}
public:
	string m_Name;
	int m_Age;
};


void test01()
{
	queue<Person> q;

	// 准备数据
	Person p1("刘一", 20);
	Person p2("陈二", 30);
	Person p3("张三", 40);
	Person p4("李四", 50);

	// 入队
	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);

	cout << "队列大小 " << q.size() << endl;

	// 判断队列不为空，查看对头 和 队尾，然后出队
	while (!q.empty())
	{
		cout << "队头：" << q.front().m_Name << " " << q.front().m_Age << endl;

		cout << "队尾：" << q.back().m_Name << " " << q.back().m_Age << endl;

		q.pop();
	}

	cout << "队列大小 " << q.size() << endl;
}

int main()
{
	test01();

	return 0;
}