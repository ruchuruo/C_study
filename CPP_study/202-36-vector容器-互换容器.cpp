
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

				3.2.6 vector数据存取

				3.2.7 vector互换容器

					功能描述：

						实现两个容器内元素进行互换

					函数原型：

						swap(vec); // 将vec与本身的元素互换

					总结：swap可以使两个容器互换，可以达到实用的收缩内存效果
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
	vector<int> v2;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(9 - i);
	}

	cout << "交换前" << endl;
	printVector(v1);
	printVector(v2);

	// 将vec与本身的元素互换
	v1.swap(v2);

	cout << "交换后" << endl;
	printVector(v1);
	printVector(v2);
}

// 实用的收缩内存
void test02()
{
	cout << endl;

	vector<int> v;

	for (int i = 0; i < 10000; i++)
	{
		v.push_back(i);
	}

	cout << "v的容量 " << v.capacity() << endl;
	cout << "v的大小 " << v.size() << endl;
	cout << endl;

	/*
		resize(int num);       //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。
						       //如果容器变短，则末尾超出容器长度的元素被删除。

		resize(int num, elem); //重新指定容器的长度为num，若容器变长，则以elem值填充新位置。
							   //如果容器变短，则末尾超出容器长度的元素被删除
	*/
	v.resize(3);

	cout << "v的容量 " << v.capacity() << endl;
	cout << "v的大小 " << v.size() << endl;
	cout << endl;

	// 巧用swap收缩内存
	/*
		匿名对象
		vector<int>(v)

		用对象 v 拷贝构造了 匿名对象
		vector<int> x(v)

		容器交换
		.swap(v)
			
			|   交换前
			|       v → [ ][ ][ ][ ][ ][ ][ ][ ][ ]......
			|
			|       x → [ ][ ][ ]
			|
			|   交换后
			|       x → [ ][ ][ ][ ][ ][ ][ ][ ][ ]......
			|
			|       v → [ ][ ][ ]
			|
			|       指针指向位置交换
			|       匿名对象特点：当前行代码指向完立即释放
	*/
	vector<int>(v).swap(v);

	cout << "v的容量 " << v.capacity() << endl;
	cout << "v的大小 " << v.size() << endl;
}

int main()
{
	test01();

	test02();

	return 0;
}

/*
	来自弹幕：卸磨杀驴?
*/