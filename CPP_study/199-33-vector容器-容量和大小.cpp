
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

					功能描述：

						对vector容器的容量和大小操作

					函数原型：

						empty();               //判断容器是否为空

						capacity();            //容器的容量

						size();                //返回容器中元素的个数

						resize(int num);       //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。
										       //如果容器变短，则末尾超出容器长度的元素被删除。

						resize(int num, elem); //重新指定容器的长度为num，若容器变长，则以elem值填充新位置。
											   //如果容器变短，则末尾超出容器长度的元素被删除

					总结：

						判断是否为空 --- empty
						返回元素个数 --- size
						返回容器容量 --- capacity
						重新指定大小 --- resize
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
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);

	if (v1.empty())
	{
		cout << "v1为空" << endl;
	}
	else
	{
		cout << "v1不为空" << endl;
		cout << "v1的容量 = " << v1.capacity() << endl;
		cout << "v1的大小 = " << v1.size() << endl;
	}

	//resize 重新指定大小 ，若指定的更大，默认用0填充新位置，可以利用重载版本替换默认填充
	v1.resize(15, 666);
	printVector(v1);

	//resize 重新指定大小 ，若指定的更小，超出部分元素被删除
	v1.resize(5);
	printVector(v1);
}

int main()
{
	test01();

	return 0;
}