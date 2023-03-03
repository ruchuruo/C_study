
/*
	第1阶段C++ 匠心之作 从0到1入门

	第2阶段实战-通讯录管理

	第3阶段-C++核心编程

		1 内存分区模型

		2 引用

			2.1 引用的基本使用

			2.2 引用注意事项

			2.3 引用做函数参数

			2.4 引用做函数返回值

			2.5 引用的本质

			2.6 常量引用

				作用：常量引用主要用来修饰形参，防止误操作

				在函数形参列表中，可以加 const修饰形参，防止形参改变实参
*/

#include <iostream>

using namespace std;

//引用使用的场景，通常用来修饰形参
void showValue(const int& v)
{
	//v += 10;
	cout << v << endl;
}

int main()
{
	//int& ref = 10;  引用本身需要一个合法的内存空间，因此这行错误
	//加入const就可以了，编译器优化(修改)代码为：int temp = 10; const int& ref = temp;
	const int& ref = 10;

	//ref = 100;  //加入const后不可以修改变量
	cout << ref << endl;

	//函数中利用常量引用防止误操作修改实参
	int a = 10;
	showValue(a);

	return 0;
}