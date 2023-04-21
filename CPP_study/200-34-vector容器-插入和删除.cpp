
/*
	第1阶段C++ 匠心之作 从0到1入门

	第2阶段实战-通讯录管理

	第3阶段-C++核心编程

	第4阶段实战-基于多态的企业职工系统

	第5阶段-C++提高编程

		1 模板

		2 STL初识

		3 STL- 常用容器

			3.1 string容器

			3.2 vector容器

				3.2.1 vector基本概念

				3.2.2 vector构造函数

				3.2.3 vector赋值操作

				3.2.4 vector容量和大小

				3.2.5 vector插入和删除

					功能描述：

						对vector容器进行插入、删除操作

					函数原型：

						push_back(ele);                                  //尾部插入元素ele
						pop_back();                                      //删除最后一个元素
						insert(const_iterator pos, ele);                 //迭代器指向位置pos插入元素ele
						insert(const_iterator pos, int count,ele);       //迭代器指向位置pos插入count个元素ele
						erase(const_iterator pos);                       //删除迭代器指向的元素
						erase(const_iterator start, const_iterator end); //删除迭代器从start到end之间的元素
						clear();                                         //删除容器中所有元素

					总结：

						尾插 --- push_back
						尾删 --- pop_back
						插入 --- insert (位置迭代器)
						删除 --- erase （位置迭代器）
						清空 --- clear
*/

#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	vector<int> v1;

	// 尾插
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);
	printVector(v1);

	// 尾删
	v1.pop_back();
	printVector(v1);

	// pos插入
	v1.insert(v1.begin(), 166);
	printVector(v1);

	// pos插入 多个相同数据
	v1.insert(v1.begin(), 2, 266);
	printVector(v1);

	// pos删除
	v1.erase(v1.begin());
	printVector(v1);

	// pos删除 多个数据
	//vector<int>::iterator itBegin = v1.begin();
	//v1.erase(v1.begin(), itBegin + 5);
	v1.erase(v1.begin(), v1.begin() + 5);
	printVector(v1);

	// 清空
	v1.clear();
	printVector(v1);
}

int main()
{
	test01();

	return 0;
}