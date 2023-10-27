
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

				5.4.1 copy

				5.4.2 replace

					功能描述：

						将容器内指定范围的旧元素修改为新元素

					函数原型：

						replace(iterator beg, iterator end, oldvalue, newvalue);
							// 将区间内旧元素 替换成 新元素
							// beg      开始迭代器
							// end      结束迭代器
							// oldvalue 旧元素
							// newvalue 新元素

					总结：replace会替换区间内满足条件的元素
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 仿函数
struct MyPrint
{
	void operator()(int val)
	{
		cout << val << " ";
	}
};

void test01()
{
	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(10);
	v.push_back(40);
	v.push_back(10);
	v.push_back(60);
	v.push_back(10);
	v.push_back(80);

	// 遍历 打印
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;

	// 将10替换成999
	replace(v.begin(), v.end(), 10, 999);

	// 遍历 打印
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;
}

int main()
{
	test01();

	return 0;
}