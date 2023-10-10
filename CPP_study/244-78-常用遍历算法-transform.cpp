
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

				5.1.1 for_each

				5.1.2 transform

					功能描述：

						搬运容器到另一个容器中

					函数原型：

						transform(iterator beg1, iterator end1, iterator beg2, _func);
							//beg1  源容器开始迭代器
							//end1  源容器结束迭代器
							//beg2  目标容器开始迭代器
							//_func 函数或者函数对象(搬运期间可以做一些运算)

					总结： 搬运的目标容器必须要提前开辟空间，否则无法正常搬运
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 仿函数 搬运
class transf
{
public:
	int operator()(int val)
	{
		// 搬运期间不需要做运算，直接返回
		//return val;

		// 搬运期间进行运算
		return val + 100;
	}
};

// 仿函数 打印
class print01
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

void test01()
{
	// 源容器
	vector<int> v;

	// 添加数据到 源容器
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	// 目标容器
	vector<int> v2;

	// 搬运前需要扩展空间
	v2.resize(v.size());

	// 搬运
	transform(v.begin(), v.end(), v2.begin(), transf());

	// 遍历
	for_each(v2.begin(), v2.end(), print01());

	cout << endl;
}

int main()
{
	test01();

	return 0;
}