
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

				4.6.1 继承的基本语法

				4.6.2 继承方式

				4.6.3 继承中的对象模型

					问题：从父类继承过来的成员，哪些属于子类对象中？

					利用工具查看：

						Visual Studio 2017 文件夹下
							VS 2017的开发人员命令提示符
							(英文是：Developer command prompt for VS)

						打开工具窗口后，定位到当前CPP文件的盘符
							D:
							cd D:\ruchuruo\C\C_Study\CPP_study

						输入 dir 查看当前目录下的内容

						然后输入： cl /d1 reportSingleClassLayout查看的类名 所属文件名
						翻译：     cl /d1 报告  单个  类   的布局
						示例：     cl /d1 reportSingleClassLayoutSon 129-47-类和对象-继承-继承中的对象模型.cpp
						|                                        ↑
						|                                        类名Son

						(也可以 视图->终端->开发者命令提示，直接输入最后一条命令就行了)


						显示：
							D:\ruchuruo\C\C_Study\CPP_study>cl /d1 reportSingleClassLayoutSon 129-47-类和对象-继承-继承中的对象模型.cpp
							用于 x86 的 Microsoft (R) C/C++ 优化编译器 19.32.31332 版
							版权所有(C) Microsoft Corporation。保留所有权利。

							129-47-类和对象-继承-继承中的对象模型.cpp

							class Son       size(16):
									+---
							 0      | +--- (base class Base)
							 0      | | m_A
							 4      | | m_B
							 8      | | m_C
									| +---
							12      | m_D
									+---
							D:\VisualStudio\IDE\VC\Tools\MSVC\14.32.31326\include\ostream(301): warning C4530: 使用了 C++ 异常处理程序，但未启用展开语义。请指定 /EHsc
							D:\VisualStudio\IDE\VC\Tools\MSVC\14.32.31326\include\ostream(294): note: 在编译 类 模板 成员函数“std::basic_ostream<char,std::char_traits<char>> &std::basic_ostream<char,std::char_traits<char>>::operator <<(unsigned int)”时
							129-47-类和对象-继承-继承中的对象模型.cpp(81): note: 查看对正在编译的函数 模板 实例化“std::basic_ostream<char,std::char_traits<char>> &std::basic_ostream<char,std::char_traits<char>>::operator <<(unsigned int)”的引用
							129-47-类和对象-继承-继承中的对象模型.cpp(81): note: 查看对正在编译的 类 模板 实例化“std::basic_ostream<char,std::char_traits<char>>”的引用
							Microsoft (R) Incremental Linker Version 14.32.31332.0
							Copyright (C) Microsoft Corporation.  All rights reserved.

							/out:129-47-类和对象-继承-继承中的对象模型.exe
							129-47-类和对象-继承-继承中的对象模型.obj


					结论： 父类中私有成员也是被子类继承下去了，只是由编译器给隐藏后访问不到
*/

#include <iostream>

using namespace std;

class Base
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C; //私有成员只是被隐藏了，但是还是会继承下去
};

//公共继承
class Son :public Base
{
public:
	int m_D;
};

void test01()
{
	cout << "sizeof Son = " << sizeof(Son) << endl;// 16
}

int main()
{
	test01();

	return 0;
}

/*
	来自弹幕：父亲把银行卡给你了，给不给密码看心情。但你确实拿到银行卡了。
*/