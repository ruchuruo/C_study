
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

				学习目标：

					掌握常用的拷贝和替换算法

				算法简介：

					copy       // 容器内指定范围的元素拷贝到另一容器中
					replace    // 将容器内指定范围的旧元素修改为新元素
					replace_if // 容器内指定范围满足条件的元素替换为新元素
					swap       // 互换两个容器的元素

				5.4.1 copy

					功能描述：
					
						容器内指定范围的元素拷贝到另一容器中

					函数原型：

						copy(iterator beg, iterator end, iterator dest);
						// 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
						// beg  开始迭代器
						// end  结束迭代器
						// dest 目标起始迭代器

					总结：利用copy算法在拷贝时，目标容器记得提前开辟空间
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
	vector<int> vTarget;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	// 扩容
	vTarget.resize(v.size());

	// 拷贝
	copy(v.begin(), v.end(), vTarget.begin());

	// 遍历 打印
	for_each(vTarget.begin(), vTarget.end(), myPrint);
	cout << endl;
}

int main()
{
	test01();

	return 0;
}