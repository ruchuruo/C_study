
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

			4.6 继承

			4.7 多态(多种形态)

				4.7.1 多态的基本概念

				多态的原理剖析

				4.7.2 多态案例一-计算器类

				4.7.3 纯虚函数和抽象类

				4.7.4 多态案例二-制作饮品

				4.7.5 虚析构和纯虚析构

					多态使用时，如果子类中有属性开辟到堆区，那么父类指针在释放时无法调用到子类的析构代码

					解决方式：将父类中的析构函数改为虚析构或者纯虚析构

					虚析构和纯虚析构共性：

						可以解决父类指针释放子类对象
						都需要有具体的函数实现

					虚析构和纯虚析构区别：

						如果是纯虚析构，该类属于抽象类，无法实例化对象

					虚析构语法：

						virtual ~类名(){}

					纯虚析构语法：

						virtual ~类名() = 0;

						类名::~类名(){}

					总结：

						1. 虚析构或纯虚析构就是用来解决通过父类指针释放子类对象

						2. 如果子类中没有堆区数据，可以不写为虚析构或纯虚析构

						3. 拥有纯虚析构函数的类也属于抽象类

                    来自弹幕：语法强制纯虚析构函数必须有函数实现,因为有时父类也有一些数据开辟在堆区
                    来自弹幕：既要使用纯虚函数，又要释放父类在堆区中的数据，就需要使用类内纯虚函数声明，类外写实现的写法
*/

#include <iostream>

using namespace std;

class Animal
{
public:

    Animal()
    {
        cout << "Animal 构造函数调用！" << endl;
    }

    virtual void Speak() = 0;

    // 父类指针指向子类对象，delete 父类指针的时候 并不会走子类的析构
    //通过父类指针去释放，会导致子类对象可能清理不干净，造成内存泄漏
    //怎么解决？给基类增加一个虚析构函数
    //虚析构函数就是用来解决通过父类指针释放子类对象

    //析构函数加上virtual关键字，变成虚析构函数
    //virtual ~Animal()
    //{
    //	cout << "Animal虚析构函数调用！" << endl;
    //}

    // 纯虚析构，需要声明 也需要实现
    virtual ~Animal() = 0;
};

Animal::~Animal()
{
    cout << "Animal 纯虚析构函数调用！" << endl;
}

//和包含普通纯虚函数的类一样，包含了纯虚析构函数的类也是一个抽象类。不能够被实例化。

class Cat : public Animal
{
public:
    Cat(string name)
    {
        cout << "Cat构造函数调用！" << endl;
        m_Name = new string(name);
    }

    virtual void Speak()
    {
        cout << *m_Name << "小猫在说话!" << endl;
    }

    ~Cat()
    {
        cout << "Cat析构函数调用!" << endl;

        if (this->m_Name != NULL)
        {
            delete m_Name;
            m_Name = NULL;
        }
    }

public:
    string* m_Name;
};

void test01()
{
    Animal* animal = new Cat("Tom");
    animal->Speak();

    // 父类指针指向子类对象，delete 父类指针的时候 并不会走子类的析构
    //通过父类指针去释放，会导致子类对象可能清理不干净，造成内存泄漏
    //怎么解决？给基类增加一个虚析构函数
    //虚析构函数就是用来解决通过父类指针释放子类对象
    delete animal;
}

int main()
{
    test01();

    return 0;
}
