
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

		5 STL- 常用算法

			5.1 常用遍历算法

			5.2 常用查找算法

			5.3 常用排序算法

			5.4 常用拷贝和替换算法

				5.4.1 copy

				5.4.2 replace

				5.4.3 replace_if

				5.4.4 swap

					功能描述：

						互换两个容器的元素

					函数原型：

						swap(container c1, container c2);
							// 互换两个容器的元素
							// c1容器1
							// c2容器2

					总结：swap交换容器时，注意交换的容器要同种类型
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void myPrint(int val)
{
	cout << val << " ";
}

void test01()
{
	vector<int> v1;
	vector<int> v2;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 10);
	}

	// 遍历 打印
	for_each(v1.begin(), v1.end(), myPrint);
	cout << endl;

	// 互换
	swap(v1, v2);

	// 遍历 打印
	for_each(v1.begin(), v1.end(), myPrint);
	cout << endl;
}

int main()
{
	test01();

	return 0;
}