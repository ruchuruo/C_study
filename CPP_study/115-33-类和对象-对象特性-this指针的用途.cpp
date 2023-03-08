
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

				4.3.1 成员变量和成员函数分开存储

				4.3.2 this指针概念

					通过4.3.1我们知道在C++中成员变量和成员函数是分开存储的。
					每一个非静态成员函数只会诞生一份函数实例，也就是说多个同类型的对象会共用一块代码。
					那么问题是：这一块代码是如何区分那个对象调用自己的呢？

					c++通过提供特殊的对象指针，this指针，解决上述问题。this指针指向被调用的成员函数所属的对象。

					this指针是隐含每一个非静态成员函数内的一种指针。
					this指针不需要定义，直接使用即可。

					this指针的用途：

						当形参和成员变量同名时，可用this指针来区分
						在类的非静态成员函数中返回对象本身，可使用return *this
*/

#include <iostream>

using namespace std;

class Person
{
public:

	Person(int age)
	{
		//1、当形参和成员变量同名时，可用this指针来区分
		this->age = age;
	}

	Person& PersonAddPerson(Person p)
	{
		this->age += p.age;

		//返回对象本身
		return *this;

		/*
			来自弹幕：如果不用引用的方式返回，相当于返回与p2不同的另一个Person（只是age都是20），那么后续的加年龄操作与p2就没有关系了
			来自弹幕：不引用就会直接使用复制构造函数，因为*this这个对象会在函数结束后销毁
			来自弹幕：引用指向本身内存，不用引用就是拷贝了，而拷贝指向另一个内存
		*/
	}

	int age;
};

void test01()
{
	Person p1(10);
	cout << "p1.age = " << p1.age << endl;

	Person p2(10);

	// 链式编程思想
	// p2.PersonAddPerson(p1) 函数 返回的还是 p2 就能继续套娃
	p2.PersonAddPerson(p1).PersonAddPerson(p1).PersonAddPerson(p1);

	cout << "p2.age = " << p2.age << endl;
}

int main()
{
	test01();

	return 0;
}