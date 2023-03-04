
/*
	第1阶段C++ 匠心之作 从0到1入门

	第2阶段实战-通讯录管理

	第3阶段-C++核心编程

		1 内存分区模型

		2 引用

		3 函数提高

		4 类和对象

			4.1 封装

				4.1.1 封装的意义

				4.1.2 struct和class区别

					在C++中 struct和class唯一的区别就在于 默认的访问权限不同

					区别：
						struct 默认权限为公共
						class 默认权限为私有
*/

#include <iostream>

using namespace std;

class C1
{
	int  m_A; //默认是私有权限
};

struct C2
{
	int m_A;  //默认是公共权限
};

int main()
{
	C1 c1;
	//c1.m_A = 10; //错误，访问权限是私有

	C2 c2;
	c2.m_A = 10; //正确，访问权限是公共

	return 0;
}