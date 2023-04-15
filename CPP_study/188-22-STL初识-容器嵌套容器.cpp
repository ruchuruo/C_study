
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

				2.5.1 vector存放内置数据类型

				2.5.2 Vector存放自定义数据类型

				2.5.3 Vector容器嵌套容器

					学习目标：容器中嵌套容器，我们将所有数据进行遍历输出

					会类似二维数组
						[1][2][3][4][5]
						[1][2][3][4][5]
						[1][2][3][4][5]
						[1][2][3][4][5]
*/

#include <iostream>
#include <vector>   // 容器 vector 的头文件

using namespace std;

void test01()
{
	// 大容器
	vector<vector<int>> V;

	// 小容器
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<int> v4;

	// 向 小容器 中添加 数据
	for (int i = 0; i < 5; i++)
	{
		v1.push_back(i + 1);
		v2.push_back(i + 2);
		v3.push_back(i + 3);
		v4.push_back(i + 4);
	}

	// 向 大容器 中添加 小容器
	V.push_back(v1);
	V.push_back(v2);
	V.push_back(v3);
	V.push_back(v4);

	// 遍历所有数据
	for (vector<vector<int>>::iterator it = V.begin(); it != V.end(); it++)
	{
		// (*it) == vector<int>
		for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++)
		{
			cout << (*vit) << " ";
		}

		cout << endl;
	}
}

int main()
{
	test01();

	return 0;
}