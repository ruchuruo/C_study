
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

				作用：引用是可以作为函数的返回值存在的

				注意：不要返回局部变量引用

				用法：函数调用作为左值
*/

#include <iostream>

using namespace std;

//返回局部变量引用
int& test01()
{
    int a = 10; //局部变量
    return a;
}

//返回静态变量引用
int& test02()
{
    static int a = 20;// 静态变量，存放在 全局区，全局区 上的数据在程序结束后由系统释放
    return a;
}

int main()
{
    //不能返回局部变量的引用
    int& ref = test01();
    cout << "ref = " << ref << endl;// 随机值
    cout << "ref = " << ref << endl;// 随机值

    //如果函数做左值，那么必须返回引用
    int& ref2 = test02();
    cout << "ref2 = " << ref2 << endl;
    cout << "ref2 = " << ref2 << endl;

    test02() = 1000;// 如果函数的返回值是引用，这个函数调用可以作为左值

    cout << "ref2 = " << ref2 << endl;
    cout << "ref2 = " << ref2 << endl;

    /*
        test02() = 1000; 之后，返回的是a的引用，
        相当于是返回变量a，相当于 a = 1000

        int& ref2 = test02(); 之后，ref2 是a的别名。

        test02() = 1000; 相当于是 原名a 赋值 1000，
        cout << "ref2 = " << ref2 << endl; 别名访问内存。
    */

    // 来自弹幕：返回负数的！把编译器改成Debug x86

    // 左值 = 右值

    return 0;
}