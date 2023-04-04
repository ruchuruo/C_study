
/*
	第1阶段C++ 匠心之作 从0到1入门

	第2阶段实战-通讯录管理

	第3阶段-C++核心编程

	第4阶段实战-基于多态的企业职工系统

	第5阶段-C++提高编程
		
		本阶段主要针对C++ 泛型编程 和 STL 技术做详细讲解，探讨C++更深层的使用

		1 模板

			1.1 模板的概念

			1.2 函数模板

					1.2.1 函数模板语法

					1.2.2 函数模板注意事项

					1.2.3 函数模板案例

					1.2.4 普通函数与函数模板的区别

					1.2.5 普通函数与函数模板的调用规则

					1.2.6 模板的局限性

						局限性：

							模板的通用性并不是万能的

						例如：

							template<class T>
							void f(T a, T b)
							{
								a = b;
							}

						在上述代码中提供的赋值操作，如果传入的a和b是一个数组，就无法实现了

						再例如：

							template<class T>
							void f(T a, T b)
							{
								if(a > b) { ... }
							}

						在上述代码中，如果T的数据类型传入的是像Person这样的自定义数据类型，也无法正常运行

						因此C++为了解决这种问题，提供模板的重载，可以为这些特定的类型提供具体化的模板

						总结：

							利用具体化的模板，可以解决自定义类型的通用化
							学习模板并不是为了写模板，而是在STL能够运用系统提供的模板
*/

#include <iostream>

using namespace std;

class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};

//普通函数模板
template<class T>
bool myCompare(T& a, T& b)
{
	if (a == b)
	{
		return true;
	}
	else
	{
		return false;
	}
}


//具体化，显示具体化的原型和定意思以template<>开头，并通过名称来指出类型
//具体化优先于常规模板
template<> bool myCompare(Person& p1, Person& p2)
{
	if (p1.m_Name == p2.m_Name && p1.m_Age == p2.m_Age)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void test01()
{
	int a = 10;
	int b = 20;

	//内置数据类型可以直接使用通用的函数模板
	bool ret = myCompare(a, b);

	if (ret)
	{
		cout << "a == b " << endl;
	}
	else
	{
		cout << "a != b " << endl;
	}
}

void test02()
{
	Person p1("Tom", 10);
	Person p2("Tom", 10);

	//自定义数据类型，不会调用普通的函数模板
	//可以创建具体化的Person数据类型的模板，用于特殊处理这个类型
	bool ret = myCompare(p1, p2);

	if (ret)
	{
		cout << "p1 == p2 " << endl;
	}
	else
	{
		cout << "p1 != p2 " << endl;
	}
}

int main()
{
	test01();

	test02();

	return 0;
}