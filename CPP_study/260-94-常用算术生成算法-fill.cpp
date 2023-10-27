
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

				5.5.1 accumulate

				5.5.2 fill

					功能描述：

						向容器中填充指定的元素

					函数原型：

						fill(iterator beg, iterator end, value);
							// 向容器中填充元素
							// beg   开始迭代器
							// end   结束迭代器
							// value 填充的值

					总结：利用fill可以将容器区间内元素填充为 指定的值
*/

#include <iostream>
#include <numeric>
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

	// 扩容
	v.resize(10);

	// 遍历 打印
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;

	// 填充999
	fill(v.begin(), v.end(), 999);

	// 遍历 打印
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;
}

int main()
{
	test01();

	return 0;
}