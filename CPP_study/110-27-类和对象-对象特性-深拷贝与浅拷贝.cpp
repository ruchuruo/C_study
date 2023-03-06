
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

				4.2.1 构造函数和析构函数

				4.2.2 构造函数的分类及调用

				4.2.3 拷贝构造函数调用时机

				4.2.4 构造函数调用规则

				4.2.5 深拷贝与浅拷贝

					深浅拷贝是面试经典问题，也是常见的一个坑

						浅拷贝：简单的赋值拷贝操作

						深拷贝：在堆区重新申请空间，进行拷贝操作

						总结：如果属性有在堆区开辟的，一定要自己提供拷贝构造函数，防止浅拷贝带来的问题

                        浅拷贝带来的问题就是 堆区 内存重复释放，栈区先进后出
                        来自弹幕：去杀一个已经死掉的人
*/

#include <iostream>

using namespace std;

class Person
{
public:
    //无参（默认）构造函数
    Person()
    {
        cout << "无参构造函数!" << endl;
    }
    //有参构造函数
    Person(int age, int height)
    {

        cout << "有参构造函数!" << endl;

        m_age = age;
        m_height = new int(height);

    }
    //拷贝构造函数  
    Person(const Person& p)
    {
        cout << "拷贝构造函数!" << endl;

        // 编译器 默认拷贝构造函数，对属性进行值拷贝(浅拷贝)
        //     m_age = p.m_age;
        //     m_height = p.m_height;// 有问题
        // 
        //如果不利用深拷贝在堆区创建新内存，会导致浅拷贝带来的重复释放堆区问题
        m_age = p.m_age;
        m_height = new int(*p.m_height);// 用自己的 m_height 指向 new 开辟的新空间，新空间里存放了 p.m_height 解引用出来的值
    }

    //析构函数
    ~Person()
    {
        cout << "析构函数!" << endl;
        if (m_height != NULL)
        {
            delete m_height;
        }
    }
public:
    int m_age;
    int* m_height;
};

void test01()
{
    Person p1(18, 180);

    Person p2(p1);

    cout << "p1的年龄： " << p1.m_age << " 身高： " << *p1.m_height << endl;

    cout << "p2的年龄： " << p2.m_age << " 身高： " << *p2.m_height << endl;
}

int main()
{
    test01();

    return 0;
}