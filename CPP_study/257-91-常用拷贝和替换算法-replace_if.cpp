
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

				5.4.3 replace_if

					功能描述:

						将区间内满足条件的元素，替换成指定元素

					函数原型：

						replace_if(iterator beg, iterator end, _pred, newvalue);
							// 按条件替换元素，满足条件的替换成指定元素
							// beg      开始迭代器
							// end      结束迭代器
							// _pred    谓词
							// newvalue 替换的新元素

					总结：replace_if按条件查找，可以利用仿函数灵活筛选满足的条件
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void myPrint(int val)
{
	cout << val << " ";
}

// 谓词
class Greater20
{
public:
	bool operator()(int val)
	{
		return val > 20;
	}
};

void test01()
{
	vector<int> v;

	v.push_back(10);
	v.push_back(10);
	v.push_back(20);
	v.push_back(20);
	v.push_back(30);
	v.push_back(30);
	v.push_back(40);
	v.push_back(40);

	// 遍历 打印
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;

	// 将大于20的数替换成999

	replace_if(v.begin(), v.end(), Greater20(), 999);

	// 遍历 打印
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;
}

int main()
{
	test01();

	return 0;
}