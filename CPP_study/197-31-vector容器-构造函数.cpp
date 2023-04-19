
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

					功能：

						vector数据结构和数组非常相似，也称为单端数组

					vector与普通数组区别：

						不同之处在于数组是静态空间，而vector可以动态扩展

					动态扩展：

						并不是在原空间之后续接新空间，而是找更大的内存空间，然后将原数据拷贝新空间，释放原空间

							|        vector容器
							|                                                 push_back() →
							|             front()                 back()                    ↘
							|        +--------------------------------------                ↙
							|        |                    -------------→                  ←
							|        |    [ 1 ][ 2 ]     [ 3 ][ 4 ][ 5 ]
							|        |                ↑                                   →
							|        +----------------|---------------------                ↘
							|      ↑        ↑         |              ↑       ↑              ↙
							|      |        |       [ 6 ]            |       | pop_back() ←
							|      |    v.begin()  insert()     v.rbegin()   |
							|   v.rend()                                  v.end()

						vector容器的迭代器是支持随机访问的迭代器

				3.2.2 vector构造函数

					功能描述：

						创建vector容器

					函数原型：

						vector<T> v;                //采用模板实现类实现，默认构造函数
						vector(v.begin(), v.end()); //将v[begin(), end())区间中的元素拷贝给本身。
						vector(n, elem);            //构造函数将n个elem拷贝给本身。
						vector(const vector &vec);  //拷贝构造函数。

					总结：vector的多种构造方式没有可比性，灵活使用即可
*/

#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int>& v)
{

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	//采用模板实现类实现，默认构造函数
	vector<int> v1; //无参构造
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);

	//将v[begin(), end())区间中的元素拷贝给本身。
	vector<int> v2(v1.begin(), v1.end());
	printVector(v2);

	//构造函数将n个elem拷贝给本身。
	vector<int> v3(10, 100);
	printVector(v3);

	//拷贝构造函数。
	vector<int> v4(v3);
	printVector(v4);
}

int main()
{
	test01();

	return 0;
}