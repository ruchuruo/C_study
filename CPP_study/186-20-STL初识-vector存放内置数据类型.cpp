
/*
	第1阶段C++ 匠心之作 从0到1入门

	第2阶段实战-通讯录管理

	第3阶段-C++核心编程

	第4阶段实战-基于多态的企业职工系统

	第5阶段-C++提高编程

		1 模板

		2 STL初识

			2.1 STL的诞生

			2.2 STL基本概念

			2.3 STL六大组件

			2.4 STL中容器、算法、迭代器

			2.5 容器算法迭代器初识

				了解STL中容器、算法、迭代器概念之后，我们利用代码感受STL的魅力

				STL中最常用的容器为Vector，可以理解为数组，下面我们将学习如何向这个容器中插入数据、并遍历这个容器

				2.5.1 vector存放内置数据类型

					容器： vector

					算法： for_each

					迭代器： vector<int>::iterator
*/

#include <iostream>
#include <vector>   // 容器 vector 的头文件
#include <algorithm>// 标准算法头文件

using namespace std;

void myPrint(int val)
{
	cout << val << " ";
}

void test01()
{
	// 需要头文件 <vector>
	vector<int> v;

	// 尾插
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);



	// 通过 迭代器 访问容器中的数据
	// begin() 起始迭代器，指向容器中第一个元素
	//  ↓
	// [10][20][30][40]
	vector<int>::iterator itBegin = v.begin();

	// end() 结束迭代器，指向容器中最后一个元素的下一个位置
	//                  ↓
	// [10][20][30][40][??]
	vector<int>::iterator itEnd = v.end();



	// 遍历
	// 方式1
	while (itBegin != itEnd)
	{
		// 解引用 itBegin
		cout << *itBegin << " ";
		itBegin++;
	}
	cout << endl;

	// 方式2
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	// 方式3 利用STL提供的遍历算法，需要头文件 <algorithm>
	/*
		template <class InputIterator, class Function>
		Function for_each(InputIterator first, InputIterator last, Function fn);
		                                起始                 结束           函数
			
		参数
			first, last
				Input iterators to the initial and final positions in a sequence. The range used is [first,last), which contains all the elements between first and last, including the element pointed by first but not the element pointed by last.
				将迭代器输入到序列中的初始位置和最终位置。使用的范围是 ，它包含 和 之间的所有元素，包括 指向的元素，但不包括指向的元素。

			fn
				Unary function that accepts an element in the range as argument.
				This can either be a function pointer or a move constructible function object.
				Its return value, if any, is ignored.
				接受范围内的元素作为参数的一元函数。
				这可以是函数指针或移动可构造函数对象。
				它的返回值（如果有）将被忽略。

		返回值
			C++98
				Returns fn.

			C++11
				Returns fn, as if calling std::move(fn).
	*/
	for_each(v.begin(), v.end(), myPrint);
}

int main()
{
	test01();

	return 0;
}

/*
	来自弹幕：看完STL可以看《STL源码剖析》
*/