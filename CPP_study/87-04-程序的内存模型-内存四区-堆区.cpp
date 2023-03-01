
/*
	第1阶段C++ 匠心之作 从0到1入门

	第2阶段实战-通讯录管理

	第3阶段-C++核心编程

		1 内存分区模型

			1.1 程序运行前

			1.2 程序运行后

				栈区：

					由编译器自动分配释放, 存放函数的参数值,局部变量等

					注意事项：不要返回局部变量的地址，栈区开辟的数据由编译器自动释放

				堆区：

					由程序员分配释放,若程序员不释放,程序结束时由操作系统回收

					在C++中主要利用new在堆区开辟内存

				总结：

					堆区数据由程序员管理开辟和释放

					堆区数据利用new关键字进行开辟内存
*/

#include <iostream>

using namespace std;



// 栈区
int* test1_func()
{
	int a = 10;
	return &a;
}
void test1()
{
	int* p = test1_func();

	cout << *p << endl;// 第一次可以打印正确的数字，因为编译器做了保留
	cout << *p << endl;
}



// 堆区
int* test2_func()
{
	// int* a = (int*)malloc(sizeof(int));
	int* a = new int(10);
	return a;
}
void test2()
{
	int* p = test2_func();

	cout << *p << endl;
	cout << *p << endl;
}



int main()
{
	// 栈区
	test1();

	// 堆区
	test2();

	/*
		来自弹幕：

			第一次输出还是10是因为a原来在的内存还没有被覆盖，所以可以输出

			这里讲的不太好，函数调用返回后栈上的数据并没有被清空，而是程序失去了对栈所在内存的控制权

			第二次输出的时候已经被别的数据覆盖了，所以输出的内容是不可控的

			一定要调成x86，要不然会一直输出10
	*/

	return 0;
}