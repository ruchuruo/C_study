
/*
	第1阶段C++ 匠心之作 从0到1入门

	第2阶段实战-通讯录管理

	第3阶段-C++核心编程

		1 内存分区模型

		2 引用

		3 函数提高

		4 类和对象

			4.1 封装

			4.2 对象的初始化和清理

			4.3 C++对象模型和this指针

			4.4 友元

			4.5 运算符重载

				4.5.1 加号运算符重载

				4.5.2 左移运算符重载

				4.5.3 递增运算符重载

					作用： 通过重载递增运算符，实现自己的整型数据

                    总结： 前置递增返回引用，后置递增返回值
*/

#include <iostream>

using namespace std;

class MyInteger
{

    friend ostream& operator<<(ostream& out, MyInteger myint);

public:
    MyInteger()
    {
        m_Num = 0;
    }

    //前置++
    MyInteger& operator++()
    {
        //先++
        m_Num++;

        //再返回
        return *this;

        /*
            返回引用是因为要对同一个数进行操作
            int a = 0;
            cout << ++(++a) << endl;// 2
            cout << a << endl;      // 2
        */
    }

    //后置++，(无法重载仅按返回类型区分的函数)(第3阶段-C++核心编程  3.2 函数占位参数)
    MyInteger operator++(int)
    {
        //先记录当时结果
        MyInteger temp = *this; //记录当前本身的值，然后让本身的值加1，但是返回的是以前的值，达到先返回后++；

        // 递增
        m_Num++;

        // 返回记录的结果
        return temp;

        /*
            返回值是因为返回的是局部的对象
        */
    }

private:
    int m_Num;
};

// 为了 cout 在左侧只能全局函数
ostream& operator<<(ostream& out, MyInteger myint)
{
    out << myint.m_Num;
    return out;
}


//前置++ 先++ 再返回
void test01()
{
    MyInteger myInt;
    cout << ++myInt << endl;
    cout << myInt << endl;
}

//后置++ 先返回 再++
void test02()
{
    MyInteger myInt;
    cout << myInt++ << endl;
    cout << myInt << endl;
}

int main()
{
    test01();

    test02();

    return 0;
}

/*
    函数占位参数 https://www.cnblogs.com/songhe364826110/p/11521451.html

        在C++中可以为函数提供占位参数

            占位参数只有参数类型声明，而没有参数名声明
            一般情况下，在函数体内部无法使用占位参数


        C++中函数占位参数的意义：占位参数与默认参数结合起来使用，兼容C语言程序中可能出现的不规范写法。

            示例1：C语言不规范写法

                #include <stdio.h>

                在C语言中，该函数可以接受任意个数、任意类型的参数,
                void func(void)才表示不接受任何参数.

                void func()
                {

                }

                int main()
                {
                    func(1);
                    func(2, 3);

                    return 0;
                }


            示例2：结合使用占位参数和默认参数，以最小的改动，将示例1代码移植到C++中

                #include <stdio.h>

                void func(int x, int = 0);

                void func(int x, int)
                {

                }

                int main()
                {
                    func(1);
                    func(2, 3);

                    return 0;
                }
*/

















































/*
    来自弹幕：c++是c后置++（狗头）
*/