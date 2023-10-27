
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

				学习目标：

					掌握常用的算术生成算法

				注意：

					算术生成算法属于小型算法，使用时包含的头文件为 #include <numeric>

				算法简介：

					accumulate // 计算容器元素累计总和
					fill       // 向容器中添加元素

				5.5.1 accumulate

					功能描述：

						计算区间内 容器元素累计总和

					函数原型：

						accumulate(iterator beg, iterator end, value);
							// 计算容器元素累计总和
							// beg   开始迭代器
							// end   结束迭代器
							// value 起始值(起始累加值)

					总结：accumulate使用时头文件注意是 numeric，这个算法很实用
*/

#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

void test01()
{
	vector<int> v;

	for (int i = 0; i <= 100; i++)
	{
		v.push_back(i);
	}

	// 计算总和

	int ret =
		accumulate(v.begin(), v.end(), 0);

	cout << ret << endl;
}

int main()
{
	test01();

	return 0;
}