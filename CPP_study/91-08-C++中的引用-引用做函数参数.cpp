
/*
	第1阶段C++ 匠心之作 从0到1入门

	第2阶段实战-通讯录管理

	第3阶段-C++核心编程

		1 内存分区模型

		2 引用

			2.1 引用的基本使用

			2.2 引用注意事项

			2.3 引用做函数参数

				作用：函数传参时，可以利用引用的技术让形参修饰实参

				优点：可以简化指针修改实参

				总结：通过引用参数产生的效果同按地址传递是一样的。引用的语法更清楚简单
*/

#include <iostream>

using namespace std;

//1. 值传递
void mySwap01(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

//2. 地址传递
void mySwap02(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

//3. 引用传递
void mySwap03(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a = 10;
    int b = 20;

    //1. 值传递
    mySwap01(a, b);
    cout << "a:" << a << " b:" << b << endl;

    //2. 地址传递
    mySwap02(&a, &b);
    cout << "a:" << a << " b:" << b << endl;

    //3. 引用传递
    mySwap03(a, b);
    cout << "a:" << a << " b:" << b << endl;

    return 0;
}