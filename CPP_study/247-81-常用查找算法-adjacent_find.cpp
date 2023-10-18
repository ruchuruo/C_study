
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

				5.2.1 find

				5.2.2 find_if

				5.2.3 adjacent_find

					功能描述：

						查找相邻重复元素

					函数原型：

						adjacent_find(iterator beg, iterator end);
							// 查找相邻重复元素,找到返回相邻元素的第一个位置的迭代器，找不到返回结束迭代器位置
							// beg 开始迭代器
							// end 结束迭代器

					总结：面试题中如果出现查找相邻重复元素，记得用STL中的adjacent_find算法
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void test01()
{
	vector<int> v;

	v.push_back(0);
	v.push_back(2);
	v.push_back(0);
	v.push_back(5);
	v.push_back(1);
	v.push_back(4);
	v.push_back(3);
	v.push_back(3);

	// 查找
	vector<int>::iterator it =
		adjacent_find(v.begin(), v.end());

	// 判断是否找到
	if (it == v.end())
	{
		cout << "未找到" << endl;
	}
	else
	{
		cout << *it << endl;
	}
}

int main()
{
	test01();

	return 0;
}