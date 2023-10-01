
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

			4.1 函数对象

			4.2 谓词

				4.2.1 谓词概念

					概念：

						返回bool类型的仿函数称为谓词
						如果operator()接受一个参数，那么叫做一元谓词
						如果operator()接受两个参数，那么叫做二元谓词

				4.2.2 一元谓词

					总结：参数只有一个的谓词，称为一元谓词
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class GreaterFive
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};

void test01()
{
	vector<int> v;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	// 查找容器中大于5的数字
	// find_if(_InIt _First, const _InIt _Last, _Pr _Pred)
	// find_if(第一, 第二, 谓词)
	// 参数中看见 Pred 表示需要谓词
	// 这里传入一个匿名的函数对象 GreaterFive()
	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());

	if (it == v.end())
	{
		cout << "未找到" << endl;
	}
	else
	{
		cout << "找到 " << *it << endl;
	}
}

int main()
{
	test01();

	return 0;
}