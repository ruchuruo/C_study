
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

				学习目标：

					掌握常用的排序算法

				算法简介：

					sort           // 对容器内元素进行排序
					random_shuffle // 洗牌 指定范围内的元素随机调整次序
					merge          // 容器元素合并，并存储到另一容器中
					reverse        // 反转指定范围的元素

				5.3.1 sort

					功能描述：

						对容器内元素进行排序

					函数原型：

						sort(iterator beg, iterator end, _Pred);
						// 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
						// beg   开始迭代器
						// end   结束迭代器
						// _Pred 谓词

					总结：sort属于开发中最常用的算法之一，需熟练掌握
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

	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(20);
	v.push_back(40);

	// 排序 升序
	sort(v.begin(), v.end());

	// 遍历 打印
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;


	// 排序 降序 关系仿函数greater<T>
	sort(v.begin(), v.end(), greater<int>());

	// 遍历 打印
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;
}

int main()
{
	test01();

	return 0;
}