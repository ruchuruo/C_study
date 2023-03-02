
/*
	第1阶段C++ 匠心之作 从0到1入门

	第2阶段实战-通讯录管理

	第3阶段-C++核心编程

		1 内存分区模型

		2 引用

			2.1 引用的基本使用

			2.2 引用注意事项

				引用必须初始化
				引用在初始化后，不可以改变

				假设 c 和 a 绑定后，c 就不能再和 b 等其他绑定了
*/

#include <iostream>

using namespace std;

int main()
{
    int a = 10;
    int b = 20;
    //int &c; //错误，引用必须初始化
    int& c = a; //一旦初始化后，就不可以更改
    c = b; //这是赋值操作，不是更改引用

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    return 0;
}