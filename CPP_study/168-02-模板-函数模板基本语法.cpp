
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

				C++另一种编程思想称为 泛型编程 ，主要利用的技术就是模板

				C++提供两种模板机制: 函数模板 和 类模板

					1.2.1 函数模板语法

						函数模板作用：

							建立一个通用函数，其函数 返回值类型 和 形参类型 可以不具体制定，用一个虚拟的类型来代表。

						语法：

							template<typename T>
							函数声明或定义

							示例：
								template<typename T>
								void mySwap(T& a, T& b)

								( template<typename T> 后 紧跟函数声明或定义 )

						解释：

							template --- 声明创建模板

							typename --- 表明其后面的符号是一种数据类型，可以用class代替

							T        --- 通用的数据类型，名称可以替换，通常为大写字母

						总结：

							函数模板利用关键字 template
							使用函数模板有两种方式：自动类型推导、显示指定类型
							模板的目的是为了提高复用性，将类型参数化
*/

#include <iostream>

using namespace std;

//交换整型函数
void swapInt(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

//交换浮点型函数
void swapDouble(double& a, double& b)
{
	double temp = a;
	a = b;
	b = temp;
}

//利用模板提供通用的交换函数
template<typename T>
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

void test01()
{
	int a = 10;
	int b = 20;

	//swapInt(a, b);

	//利用模板实现交换
	//1、自动类型推导(编译器去猜T的类型)
	mySwap(a, b);

	//2、显示指定类型(<>中指定T的类型)
	mySwap<int>(a, b);

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

}

int main()
{
	test01();

	return 0;
}