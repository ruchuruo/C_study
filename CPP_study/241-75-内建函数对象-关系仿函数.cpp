
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

					功能描述：

						实现关系对比

					仿函数原型：
					
						template<class T> bool equal_to<T>      //等于
						template<class T> bool not_equal_to<T>  //不等于
						template<class T> bool greater<T>       //大于
						template<class T> bool greater_equal<T> //大于等于
						template<class T> bool less<T>          //小于
						template<class T> bool less_equal<T>    //小于等于

					总结：

						关系仿函数中最常用的就是greater<>大于

						因为 sort 源码中有两个重载版本，一个是需要 谓词(Pred)，
						另一个不需要，不需要谓词的 sort 中用了 less<T>小于，
						所以 sort 默认是从小到大，因为默认是小于，所以大于更常用
*/

#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

class MyCompare
{
public:
	bool operator()(int v1, int v2)
	{
		return v1 > v2;
	}
};

// 大于
void test01()
{
	vector<int> v;

	v.push_back(10);
	v.push_back(30);
	v.push_back(40);
	v.push_back(20);
	v.push_back(50);

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	// 排序 降序，使用自定义函数对象
	//sort(v.begin(), v.end(), MyCompare());

	// 排序 降序，使用内建函数对象
	sort(v.begin(), v.end(), greater<int>());

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	// 大于
	test01();

	return 0;
}