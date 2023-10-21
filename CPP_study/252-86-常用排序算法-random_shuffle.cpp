
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

					功能描述：

						洗牌 指定范围内的元素随机调整次序

					函数原型：

						random_shuffle(iterator beg, iterator end);
							// 指定范围内的元素随机调整次序
							// beg 开始迭代器
							// end 结束迭代器

					总结：random_shuffle洗牌算法比较实用，使用时记得加随机数种子
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
	// 随机数种子
	srand((unsigned int)time(NULL));

	vector<int> v;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	// 洗牌
	random_shuffle(v.begin(), v.end());

	// 遍历 打印
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;
}

int main()
{
	test01();

	return 0;
}