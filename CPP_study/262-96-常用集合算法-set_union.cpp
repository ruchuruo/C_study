
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

			5.5 常用算术生成算法

			5.6 常用集合算法

				5.6.1 set_intersection

				5.6.2 set_union

					功能描述：

						求两个集合的并集

						|   v1 [0][1][2][3][4][5 ][6 ][7 ][8 ][9 ]
						|   v2 [5][6][7][8][9][10][11][12][13][14]
						|
						|   v1和v2的交集(重复元素      ) [5][6][7][8][9]
						|   v1和v2的并集(不重复元素合并) [0][1][2][3][4][5 ][6 ][7 ][8 ][9 ][10][11][12][13][14]

					函数原型：

						set_union(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
							// 求两个集合的并集
							// 注意:两个集合必须是有序序列
							// beg1 容器1开始迭代器
							// end1 容器1结束迭代器
							// beg2 容器2开始迭代器
							// end2 容器2结束迭代器
							// dest 目标容器开始迭代器

					总结：

						求并集的两个集合必须的有序序列
						目标容器开辟空间需要两个容器相加
						set_union返回值既是并集中最后一个元素的位置
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
		v1.push_back(i);     // 0 ~ 9
		v2.push_back(i + 5); // 5 ~ 14
	}

	// 目标容器扩容
	// 特殊情况：两个容器没有相同的数
	// 扩容到两个容器相加大小
	vTarget.resize(v1.size() + v2.size());

	// 求并集
	vector<int>::iterator itEnd =
		set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

	// 遍历 打印
	for_each(vTarget.begin(), itEnd, myPrint);
	cout << endl;
}

int main()
{
	test01();

	return 0;
}