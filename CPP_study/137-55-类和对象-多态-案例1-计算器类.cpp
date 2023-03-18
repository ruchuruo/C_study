
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

					案例描述：

						分别利用普通写法和多态技术，设计实现两个操作数进行运算的计算器类

					多态的优点：

						代码组织结构清晰
						可读性强
						利于前期和后期的扩展以及维护

					总结：C++开发提倡利用多态设计程序架构，因为多态优点很多

                    在实际开发中 提倡 开闭原则，对扩展进行开放，对修改进行关闭
*/

#include <iostream>

using namespace std;

//普通实现
class Calculator
{
public:
    int getResult(string oper)
    {
        if (oper == "+") {
            return m_Num1 + m_Num2;
        }
        else if (oper == "-") {
            return m_Num1 - m_Num2;
        }
        else if (oper == "*") {
            return m_Num1 * m_Num2;
        }
        //如果要提供新的运算，需要修改源码
    }
public:
    int m_Num1;
    int m_Num2;
};

void test01()
{
    //普通实现测试
    Calculator c;
    c.m_Num1 = 10;
    c.m_Num2 = 10;
    cout << c.m_Num1 << " + " << c.m_Num2 << " = " << c.getResult("+") << endl;

    cout << c.m_Num1 << " - " << c.m_Num2 << " = " << c.getResult("-") << endl;

    cout << c.m_Num1 << " * " << c.m_Num2 << " = " << c.getResult("*") << endl;
}



//多态实现
//抽象计算器类 (Abstract - 抽象的)
//多态优点：代码组织结构清晰，可读性强，利于前期和后期的扩展以及维护
class AbstractCalculator
{
public:

    // 虚函数
    virtual int getResult()
    {
        return 0;
    }

    int m_Num1;
    int m_Num2;
};

//加法计算器
class AddCalculator :public AbstractCalculator
{
public:
    int getResult()
    {
        return m_Num1 + m_Num2;
    }
};

//减法计算器
class SubCalculator :public AbstractCalculator
{
public:
    int getResult()
    {
        return m_Num1 - m_Num2;
    }
};

//乘法计算器
class MulCalculator :public AbstractCalculator
{
public:
    int getResult()
    {
        return m_Num1 * m_Num2;
    }
};


void test02()
{
    // 多态使用条件：父类指针或引用指向子类对象
    // 上章节是 父类引用指向子类对象
    // 这里是   父类指针指向子类对象

    //创建加法计算器
    AbstractCalculator* abc = new AddCalculator;
    abc->m_Num1 = 10;
    abc->m_Num2 = 10;
    cout << abc->m_Num1 << " + " << abc->m_Num2 << " = " << abc->getResult() << endl;
    delete abc;  //用完了记得销毁

    //创建减法计算器
    abc = new SubCalculator;
    abc->m_Num1 = 10;
    abc->m_Num2 = 10;
    cout << abc->m_Num1 << " - " << abc->m_Num2 << " = " << abc->getResult() << endl;
    delete abc;

    //创建乘法计算器
    abc = new MulCalculator;
    abc->m_Num1 = 10;
    abc->m_Num2 = 10;
    cout << abc->m_Num1 << " * " << abc->m_Num2 << " = " << abc->getResult() << endl;
    delete abc;
}

int main()
{
    test01();

    test02();

    return 0;
}

/*
    来自弹幕：知道为什么不建议修改吗，因为原本就不知道怎么就能运行起来的，你还敢该源码
*/