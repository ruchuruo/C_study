
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

				4.3.2 算术仿函数

				4.3.3 关系仿函数

				4.3.4 逻辑仿函数

					功能描述：

						实现逻辑运算

					函数原型：

						template<class T> bool logical_and<T> //逻辑与
						template<class T> bool logical_or<T>  //逻辑或
						template<class T> bool logical_not<T> //逻辑非

					总结：逻辑仿函数实际应用较少，了解即可
*/

#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
using namespace std;

// 逻辑非
void test01()
{
	vector<bool> v;
	v.push_back(true);
	v.push_back(false);
	v.push_back(true);
	v.push_back(false);

	for (vector<bool>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	// 取反，放到容器v2中

	vector<bool> v2;

	// 扩大v2空间，否则报错
	v2.resize(v.size());

	// v搬运到v2，transform函数之后介绍
	transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());

	for (vector<bool>::iterator it = v2.begin(); it != v2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	// 逻辑非
	test01();

	return 0;
}