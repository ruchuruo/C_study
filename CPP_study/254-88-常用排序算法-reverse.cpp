
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

				5.3.1 sort

				5.3.2 random_shuffle

				5.3.3 merge

				5.3.4 reverse

					功能描述：

						将容器内元素进行反转

					函数原型：
						reverse(iterator beg, iterator end);
						// 反转指定范围的元素
						// beg 开始迭代器
						// end 结束迭代器

					总结：reverse反转区间内元素，面试题可能涉及到
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
	vector<int> v;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	for_each(v.begin(), v.end(), myPrint);
	cout << endl;

	// 反转
	reverse(v.begin(), v.end());

	for_each(v.begin(), v.end(), myPrint);
	cout << endl;
}

int main()
{
	test01();

	return 0;
}