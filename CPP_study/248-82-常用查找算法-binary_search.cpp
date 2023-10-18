
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

				5.2.4 binary_search

					功能描述：

						查找指定元素是否存在

					函数原型：

						bool binary_search(iterator beg, iterator end, value);
							// 查找指定的元素，查到 返回true 否则false
							// 注意: 在无序序列中不可用
							// beg   开始迭代器
							// end   结束迭代器
							// value 查找的元素

					总结：二分查找法查找效率很高，值得注意的是查找的容器中元素必须的有序序列
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void test01()
{
	vector<int> v;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	// 查找9
	bool ret =
		binary_search(v.begin(), v.end(), 9);

	// 判断是否找到
	if (ret == false)
	{
		cout << "未找到" << endl;
	}
	else
	{
		cout << "找到" << endl;
	}
}

int main()
{
	test01();

	return 0;
}