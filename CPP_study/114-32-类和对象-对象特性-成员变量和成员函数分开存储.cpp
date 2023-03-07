
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

				4.3.1 成员变量和成员函数分开存储

					在C++中，类内的成员变量和成员函数分开存储

					只有非静态成员变量才属于类的对象上

                    空对象占用内存空间为 1 字节，
                    C++编译器会给每个 空对象 也分配1个字节空间，是为了区分空对象占用内存的位置，
                    每一个 空对象 都有一个独一无二的内存空间。
*/

#include <iostream>

using namespace std;

class Person
{
public:
    Person()
    {
        mA = 0;
    }

    //非静态成员变量占对象空间
    int mA;

    //静态成员变量不占对象空间
    static int mB;

    //函数也不占对象空间，所有函数共享一个函数实例
    void func()
    {
        cout << "mA:" << this->mA << endl;
    }

    //静态成员函数也不占对象空间
    static void sfunc()
    {
    }
};

int main()
{
    cout << sizeof(Person) << endl;

    return 0;
}