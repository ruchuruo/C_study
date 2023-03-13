
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

				4.5.4 赋值运算符重载

					c++编译器至少给一个类添加4个函数

						默认构造函数(无参，函数体为空)
						默认析构函数(无参，函数体为空)
						默认拷贝构造函数，对属性进行值拷贝
						赋值运算符 operator=, 对属性进行值拷贝

					如果类中有属性指向堆区，做赋值操作时也会出现深浅拷贝问题

                    (第3阶段-C++核心编程  4.2.5 深拷贝与浅拷贝)
                        浅拷贝带来的问题就是 堆区 内存重复释放，
                        两个指针保存的是同一个地址，在判断里 (m_Age != NULL)，确实不为空，但是是野指针

                        |int* m_Age            int* m_Age
                        |          ↘        ↙
                        |            0x66CCFF
*/

#include <iostream>

using namespace std;

class Person
{
public:

    Person(int age)
    {
        //将年龄数据开辟到堆区
        m_Age = new int(age);
    }

    //重载赋值运算符 
    Person& operator=(Person& p)
    {
        //编译器提供的代码是浅拷贝
        //m_Age = p.m_Age;

        // 先判断是否有属性在堆区，如果有先释放干净，然后再深拷贝
        if (m_Age != NULL)
        {
            delete m_Age;
            m_Age = NULL;
        }

        //提供深拷贝 解决浅拷贝的问题
        m_Age = new int(*p.m_Age);

        //返回自身
        return *this;

        /*
            来自弹幕：
                1.注意:这里的重载函数的参数一定要以引用或者指针的形式传入!!
                2.不然在传入的时候进行了一次拷贝将赋值右边p2的值传入的时候临时变量记录的p2的属性m_Age的地址
                3.而出了赋值运算符重载函数会进行一次析构 这时p2的属性new出来的空间已经被释放了
                4.最后结束调用虽然你深拷贝了但是程序还是会崩
        */
    }


    ~Person()
    {
        if (m_Age != NULL)
        {
            delete m_Age;
            m_Age = NULL;
        }
    }

    //年龄的指针
    int* m_Age;

};


void test01()
{
    /*
        内置数据类型赋值
            a = 10;
            b = 20;
            c = 30;

            c = b = a;

            a等于10
            b等于10
            c等于10
    */

    Person p1(18);

    Person p2(20);

    Person p3(30);

    p3 = p2 = p1; //赋值操作 // 链式编程

    cout << "p1的年龄为：" << *p1.m_Age << endl;

    cout << "p2的年龄为：" << *p2.m_Age << endl;

    cout << "p3的年龄为：" << *p3.m_Age << endl;
}

int main()
{
    test01();

    //int a = 10;
    //int b = 20;
    //int c = 30;

    //c = b = a;
    //cout << "a = " << a << endl;
    //cout << "b = " << b << endl;
    //cout << "c = " << c << endl;

    return 0;
}