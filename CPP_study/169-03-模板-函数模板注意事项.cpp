
/*
	第1阶段C++ 匠心之作 从0到1入门

	第2阶段实战-通讯录管理

	第3阶段-C++核心编程

	第4阶段实战-基于多态的企业职工系统

	第5阶段-C++提高编程

		1 模板

			1.1 模板的概念

			1.2 函数模板

					1.2.1 函数模板语法

					1.2.2 函数模板注意事项

						注意事项：

							自动类型推导，必须推导出一致的数据类型T,才可以使用

							模板必须要确定出T的数据类型，才可以使用

						总结：

							使用模板时必须确定出通用数据类型T，并且能够推导出一致的类型
*/

#include <iostream>

using namespace std;

//利用模板提供通用的交换函数
template<class T>
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}


// 1、自动类型推导，必须推导出一致的数据类型T,才可以使用
void test01()
{
	int a = 10;
	int b = 20;
	char c = 'c';

	mySwap(a, b); // 正确，可以推导出一致的T
	//mySwap(a, c); // 错误，推导不出一致的T类型
}


// 2、模板必须要确定出T的数据类型，才可以使用
template<class T>
void func()
{
	cout << "func 调用" << endl;
}

void test02()
{
	//func(); //错误，模板不能独立使用，必须确定出T的类型
	func<int>(); //利用显示指定类型的方式，给T一个类型，才可以使用该模板

	/*
		一寸照片模板不能直接使用，必须确定人的脑袋
	*/
}





// 不同类型参数

template<typename T, typename W>
void fun(T a, W b)
{
	cout << a << endl;
	cout << b << endl;
}

void test99()
{
	int a = 10;
	char b = 'c';

	fun<int, char>(a, b);
}





int main()
{
	test01();
	test02();

	test99();

	return 0;
}