
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

					功能描述：

						两个容器元素合并，并存储到另一容器中

					函数原型：

						merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
						// 容器元素合并，并存储到另一容器中
						// 注意: 两个容器必须是有序的
						// beg1 容器1开始迭代器
						// end1 容器1结束迭代器
						// beg2 容器2开始迭代器
						// end2 容器2结束迭代器
						// dest 目标容器开始迭代器

					总结：merge合并的两个容器必须的有序序列，合并完成后还是有序
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
	vector<int> vTarget;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 10);
	}

	// 扩容
	vTarget.resize(v1.size() + v2.size());

	// 合并
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

	// 遍历 打印
	for_each(vTarget.begin(), vTarget.end(), myPrint);
	cout << endl;
}

int main()
{
	test01();

	return 0;
}