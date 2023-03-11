
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

					作用：可以输出自定义数据类型

                    比如：
                        p 里有 m_A
                        cout << p << endl; 直接输出 p 里的 m_A

                    总结：重载左移运算符配合友元可以实现输出自定义数据类型
*/

#include <iostream>

using namespace std;

class Person
{
    friend ostream& operator<<(ostream& out, Person& p);

public:

    Person(int a, int b)
    {
        this->m_A = a;
        this->m_B = b;
    }

    // 成员函数 实现不了
    // 
    // void operator<<(Person& p){} 需要两个对象，没这么多对象
    // 或
    // void operator<<(cout){}      p.operator<<(cout) 简化后 p << cout 不是我们想要的效果

private:
    int m_A;
    int m_B;
};

//全局函数实现左移重载
//ostream对象只能有一个，所以要引用
// 来自弹幕：输出流不能拷贝，也就是说要传入输出流对象参数只能地址传递，不能值传递。
// 来自弹幕：流对象不能复制只能引用，记住就好了
ostream& operator<<(ostream& out, Person& p)
{
    out << "a:" << p.m_A << " b:" << p.m_B;
    return out;
}

void test()
{
    Person p1(10, 20);

    // 函数调用之后返回的是viod就不能继续函数调用，
    // 因为正常的cout输出一个数据后返回的还是cout就可以继续输出下一个数据，
    // 例如：p2.PersonAddPerson(p1).PersonAddPerson(p1).PersonAddPerson(p1);
    cout << p1 << "hello world" << endl; //链式编程

    /*
        来自弹幕：
            因为如果要链式调用，返回值就要作为下一个调用的参数，参数和返回值就必须要统一，仅此而已
            在之前的加法运算符重载调用链式就可以很好说明这点，把返回值和参数都设为同一种类型
            但是这里的ostream类型必须是引用类型，所以返回值必须是引用
            就可以链式调用，【个人理解，谢谢】
    */
}

int main()
{
    test();

    return 0;
}

/*
    来自弹幕：
        友元可以的话还是尽量少用，因为类的作用之一就是封装数据，防止其它未经允许的访问和修改。
        但是友元就相当于在封装好的类上开个缺口。
        如果一个类里面有很多个友元，那么就相当于开了很多个缺口，封装的作用就会大打折扣。
*/