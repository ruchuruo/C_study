
/*
	第1阶段C++ 匠心之作 从0到1入门

	第2阶段实战-通讯录管理

	第3阶段-C++核心编程

	第4阶段实战-基于多态的企业职工系统

	第5阶段-C++提高编程

		1 模板

		2 STL初识

		3 STL- 常用容器

		4 STL- 函数对象

			4.1 函数对象

			4.2 谓词

			4.3 内建函数对象

				4.3.1 内建函数对象意义

					概念：

						STL内建了一些函数对象
						(已经重载了很多小括号了，直接拿来用就行了)

					分类:

						算术仿函数
						关系仿函数
						逻辑仿函数

					用法：

						这些仿函数所产生的对象，用法和一般函数完全相同
						使用内建函数对象，需要引入头文件 #include<functional>

				4.3.2 算术仿函数

					功能描述：

						实现四则运算
						其中negate是一元运算，其他都是二元运算

					仿函数原型：

						template<class T> T plus<T>       //加法仿函数
						template<class T> T minus<T>      //减法仿函数
						template<class T> T multiplies<T> //乘法仿函数
						template<class T> T divides<T>    //除法仿函数
						template<class T> T modulus<T>    //取模仿函数
						template<class T> T negate<T>     //取反仿函数

					总结：使用内建函数对象时，需要引入头文件 #include <functional>
*/

#include <iostream>
#include <functional>

using namespace std;

// 取反仿函数
void test01()
{
	negate<int> n;

	cout << n(50) << endl;
}

// 加法仿函数
void test02()
{
	// 只能相加同类型数据
	plus<int> p;

	cout << p(10, 20) << endl;
}

int main()
{
	// 取反仿函数
	test01();

	// 加法仿函数
	test02();

	return 0;
}