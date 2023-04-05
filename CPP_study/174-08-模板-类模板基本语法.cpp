
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

			1.3 类模板

				1.3.1 类模板语法

					类模板作用：

						建立一个通用类，类中的成员 数据类型可以不具体制定，用一个虚拟的类型来代表。

					语法：

						template<typename T>
						类

					解释：

						template --- 声明创建模板

						typename --- 表面其后面的符号是一种数据类型，可以用class代替

						T --- 通用的数据类型，名称可以替换，通常为大写字母

					总结：类模板和函数模板语法相似，在声明模板template后面加类，此类称为类模板
*/

#include <iostream>

using namespace std;

//类模板
template<class NameType, class AgeType>
class Person
{
public:
	Person(NameType name, AgeType age)
	{
		this->mName = name;
		this->mAge = age;
	}
	void showPerson()
	{
		cout << "name: " << this->mName << " age: " << this->mAge << endl;
	}
public:
	NameType mName;
	AgeType mAge;
};

void test01()
{
	// 指定NameType 为string类型，AgeType 为 int类型
	Person<string, int> P1("孙悟空", 999);

	P1.showPerson();
}

int main()
{
	test01();

	return 0;
}