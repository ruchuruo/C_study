/*
	第1阶段C++ 匠心之作 从0到1入门

	第2阶段实战-通讯录管理

	第3阶段-C++核心编程

		本阶段主要针对C++ 面向对象 编程技术做详细讲解，探讨C++中的核心和精髓。

		1 内存分区模型

			C++程序在执行时，将内存大方向划分为4个区域

				代码区：存放函数体的二进制代码，由操作系统进行管理的，
				全局区：存放全局变量和静态变量以及常量
				栈区：由编译器自动分配释放,存放函数的参数值,局部变量等
				堆区：由程序员分配和释放,若程序员不释放,程序结束时由操作系统回收

			内存四区意义：

				不同区域存放的数据，赋予不同的生命周期,给我们更大的灵活编程

			1.1 程序运行前

				在程序编译后，生成了exe可执行程序，未执行该程序前分为两个区域

				代码区:

					存放 CPU 执行的机器指令

					代码区是共享的，共享的目的是对于频繁被执行的程序，只需要在内存中有一份代码即可

					代码区是只读的，使其只读的原因是防止程序意外地修改了它的指令

				全局区:

					全局变量和静态变量存放在此

					全局区还包含了常量区,字符串常量和其他常量也存放在此

					该区域的数据在程序结束后由操作系统释放

				总结：

					C++中在程序运行前分为全局区和代码区
					代码区特点是共享和只读
					全局区中存放全局变量、静态变量、常量
					常量区中存放 const修饰的全局常量 和 字符串常量
*/

#include <iostream>

using namespace std;

//全局变量
int g_a = 10;
int g_b = 10;

//全局常量
const int c_g_a = 10;
const int c_g_b = 10;

int main()
{
	//局部变量
	int a = 10;
	int b = 10;

	//打印地址
	cout << "局部变量a地址为： " << (int)&a << endl;// 局部变量 存放在 栈区
	cout << "局部变量b地址为： " << (int)&b << endl;// 局部变量 存放在 栈区

	cout << "全局变量g_a地址为： " << (int)&g_a << endl;// 全局变量 和 静态变量 存放在 全局区
	cout << "全局变量g_b地址为： " << (int)&g_b << endl;// 全局变量 和 静态变量 存放在 全局区

	//静态变量
	static int s_a = 10;
	static int s_b = 10;

	cout << "静态变量s_a地址为： " << (int)&s_a << endl;// 全局变量 和 静态变量 存放在 全局区
	cout << "静态变量s_b地址为： " << (int)&s_b << endl;// 全局变量 和 静态变量 存放在 全局区

	cout << "字符串常量地址为： " << (int)&"hello world" << endl;// 常量区
	cout << "字符串常量地址为： " << (int)&"hello world1" << endl;// 常量区

	cout << "全局常量c_g_a地址为： " << (int)&c_g_a << endl;// 常量区
	cout << "全局常量c_g_b地址为： " << (int)&c_g_b << endl;// 常量区

	const int c_l_a = 10;
	const int c_l_b = 10;
	cout << "局部常量c_l_a地址为： " << (int)&c_l_a << endl;// 局部常量 存放在 栈区
	cout << "局部常量c_l_b地址为： " << (int)&c_l_b << endl;// 局部常量 存放在 栈区

	// 来自弹幕：debug模式下，变量前后会有4个字节存放调试信息

	/*
		c const  常量
		g global 全局
		l local  局部
		s static 静态
	*/

	return 0;
}