
/*
	第1阶段C++ 匠心之作 从0到1入门

	第2阶段实战-通讯录管理

	第3阶段-C++核心编程

		1 内存分区模型

		2 引用

		3 函数提高

		4 类和对象

			4.1 封装

			4.2 对象的初始化和清理

			4.3 C++对象模型和this指针

			4.4 友元

			4.5 运算符重载

				4.5.1 加号运算符重载

				4.5.2 左移运算符重载

				4.5.3 递增运算符重载

				4.5.4 赋值运算符重载

				4.5.5 关系运算符重载

				4.5.6 函数调用运算符重载

					函数调用运算符 () 也可以重载
					由于重载后使用的方式非常像函数的调用，因此称为仿函数
					仿函数没有固定写法，非常灵活

					在 STL 里用得比较多

						  第4阶段实战-基于多态的企业职工系统
						  第5阶段-C++提高编程
						→ 第6阶段实战-基于STL泛化编程的演讲比赛
*/

#include <iostream>

using namespace std;

class MyPrint
{
public:
	void operator()(string text)
	{
		cout << text << endl;
	}

};
void test01()
{
	//重载的（）操作符 也称为仿函数
	MyPrint myFunc;
	myFunc("hello world");
}


class MyAdd
{
public:
	int operator()(int v1, int v2)
	{
		return v1 + v2;
	}
};
void test02()
{
	MyAdd add;
	int ret = add(10, 10);
	cout << "ret = " << ret << endl;

	//匿名对象调用  
	cout << "MyAdd()(100,100) = " << MyAdd()(100, 100) << endl;

	/*
		匿名对象调用

			类型 加 () 是匿名对象
			(100, 100) 是重载
	*/
}


int main()
{
	test01();
	test02();

	return 0;
}