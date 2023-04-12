
/*
	第1阶段C++ 匠心之作 从0到1入门

	第2阶段实战-通讯录管理

	第3阶段-C++核心编程

	第4阶段实战-基于多态的企业职工系统

	第5阶段-C++提高编程

		1 模板

			1.1 模板的概念

			1.2 函数模板

			1.3 类模板

				1.3.1 类模板语法

				1.3.2 类模板与函数模板区别

				1.3.3 类模板中成员函数创建时机

				1.3.4 类模板对象做函数参数

				1.3.5 类模板与继承

					当类模板碰到继承时，需要注意一下几点：

						当子类继承的父类是一个类模板时，子类在声明的时候，要指定出父类中T的类型
						如果不指定，编译器无法给子类分配内存
						如果想灵活指定出父类中T的类型，子类也需变为类模板

					总结：如果父类是类模板，子类需要指定出父类中T的数据类型
*/

#include <iostream>

using namespace std;

template<class T>
class Base
{
	T m;
};

//class Son:public Base  //错误，c++编译需要给子类分配内存，必须知道父类中T的类型才可以向下继承
class Son :public Base<int> //必须指定一个类型
{
};
void test01()
{
	Son c;
}

//类模板继承类模板 ,可以用T2指定父类中的T类型
template<class T1, class T2>
class Son2 :public Base<T2>
{
public:
	Son2()
	{
		cout << typeid(T1).name() << endl;
		cout << typeid(T2).name() << endl;
	}

public:
	T1 obj;
};

void test02()
{
	Son2<int, char> child1;
}


int main()
{
	test01();

	test02();

	return 0;
}