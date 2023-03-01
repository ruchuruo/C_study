
/*
	第1阶段C++ 匠心之作 从0到1入门

	第2阶段实战-通讯录管理

	第3阶段-C++核心编程

		1 内存分区模型

			1.1 程序运行前

			1.2 程序运行后

			1.3 new操作符

				C++中利用 new 操作符在堆区开辟数据

				堆区开辟的数据，由程序员手动开辟，手动释放，释放利用操作符 delete

				语法： new 数据类型

				利用new创建的数据，会返回该数据对应的类型的指针
*/

#include <iostream>

using namespace std;



int* 基本语法_func()
{
	// new 返回的是该数据类型的指针
	int* a = new int(10);
	return a;
}
void 基本语法()
{
	int* p = 基本语法_func();

	cout << *p << endl;
	cout << *p << endl;

	//利用delete释放堆区数据
	delete p;

	//cout << *p << endl; //报错，释放的空间不可访问
}



void 开辟数组()
{
	// 10 个元素
	int* arr = new int[10];

	for (int i = 0; i < 10; i++)
	{
		arr[i] = i + 100;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;
	}

	//释放数组 delete 后加 []
	// 来自弹幕：delete arr操作只会释放第一个地址指向的空间，数组后的空间没有被释放。所以要用delete[] arr
	delete[] arr;
}



int main()
{
	基本语法();

	开辟数组();

	return 0;
}