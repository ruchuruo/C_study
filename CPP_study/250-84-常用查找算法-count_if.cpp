
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

				5.2.1 find

				5.2.2 find_if

				5.2.3 adjacent_find

				5.2.4 binary_search

				5.2.5 count

				5.2.6 count_if

					功能描述：

						按条件统计元素个数

					函数原型：

						count_if(iterator beg, iterator end, _Pred);
							// 按条件统计元素出现次数
							// beg   开始迭代器
							// end   结束迭代器
							// _Pred 谓词

					总结：按值统计用count，按条件统计用count_if
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 自定义数据类型
class Person
{
public:
	Person(string name, int age) :m_Name(name), m_Age(age) {}

	string m_Name;
	int m_Age;
};

// 谓词
class Greater20
{
public:
	bool operator()(int val)
	{
		return val > 20;
	}

	bool operator()(const Person& p)
	{
		return p.m_Age > 20;
	}
};

// 内置数据类型
void test01()
{
	vector<int> v;

	v.push_back(10);
	v.push_back(40);
	v.push_back(30);
	v.push_back(20);
	v.push_back(40);
	v.push_back(20);

	// 统计大于20的数
	int num =
		count_if(v.begin(), v.end(), Greater20());

	cout << num << endl;
}

// 自定义数据类型
void test02()
{
	vector<Person> v;

	// 创建数据
	Person p1("刘备", 10);
	Person p2("关于", 10);
	Person p3("张飞", 10);
	Person p4("赵云", 20);
	Person p5("曹操", 30);

	// 插入数据
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	// 统计年龄大于20的人
	int num =
		count_if(v.begin(), v.end(), Greater20());

	cout << num << endl;
}

int main()
{
	// 内置数据类型
	test01();

	// 自定义数据类型
	test02();

	return 0;
}