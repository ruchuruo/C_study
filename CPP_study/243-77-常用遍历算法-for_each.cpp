
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

			概述:

				算法主要是由头文件 <algorithm> <functional> <numeric> 组成。
				<algorithm> 是所有STL头文件中最大的一个，范围涉及到比较、 交换、查找、遍历操作、复制、修改等等
				<numeric> 体积很小，只包括几个在序列上面进行简单数学运算的模板函数
				<functional> 定义了一些模板类,用以声明函数对象。

			5.1 常用遍历算法

				学习目标：

					掌握常用的遍历算法

				算法简介：

					for_each  //遍历容器
					transform //搬运容器到另一个容器中

				5.1.1 for_each

					功能描述：

						实现遍历容器

					函数原型：

						for_each(iterator beg, iterator end, _func);
							// 遍历算法 遍历容器元素
							// beg   开始迭代器
							// end   结束迭代器
							// _func 函数或者函数对象

					总结：for_each在实际开发中是最常用遍历算法，需要熟练掌握
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 普通函数
void print01(int val)
{
	cout << val << " ";
}

// 仿函数
class print02
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

void test01()
{
	vector<int> v;

	// 添加数据到容器
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	// 遍历容器 使用普通函数
	for_each(v.begin(), v.end(), print01);

	cout << endl;

	// 遍历容器 使用仿函数
	for_each(v.begin(), v.end(), print02());
}

int main()
{
	test01();

	return 0;
}