
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

				3.5.1 stack 基本概念

				3.5.2 stack 常用接口

					功能描述：栈容器常用的对外接口

					构造函数：

						stack<T> stk;            //stack采用模板类实现， stack对象的默认构造形式
						stack(const stack &stk); //拷贝构造函数

					赋值操作：

						stack& operator=(const stack &stk); //重载等号操作符

					数据存取：

						push(elem); //向栈顶添加元素
						pop();      //从栈顶移除第一个元素
						top();      //返回栈顶元素

					大小操作：

						empty(); //判断堆栈是否为空
						size();  //返回栈的大小

					总结：

						入栈          --- push
						出栈          --- pop
						返回栈顶      --- top
						判断栈是否为空 --- empty
						返回栈大小     --- size
*/

#include <iostream>
#include <stack>

using namespace std;

void test01()
{
	stack<int> s;

	// 入栈
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);

	cout << "栈大小 " << s.size() << endl;

	// 栈不为空就查看栈顶，并出栈
	while (!s.empty())
	{
		cout << s.top() << endl;
		s.pop();
	}

	cout << "栈大小 " << s.size() << endl;
}

int main()
{
	test01();

	return 0;
}