
/*
	1 C++初识

	2 数据类型

	3 运算符

	4 程序流程结构

	5 数组

	6 函数

	7 指针

		7.1 指针的基本概念

		7.2 指针变量的定义和使用

		7.3 指针所占内存空间

		7.4 空指针和野指针

		7.5 const修饰指针

			const修饰指针有三种情况

				const修饰指针 --- 常量指针
				const修饰常量 --- 指针常量
				const即修饰指针，又修饰常量

			技巧：看const右侧紧跟着的是指针还是常量, 是指针就是常量指针，是常量就是指针常量

			来自弹幕
				我自己的理解哈;const用来修饰 *p的话 *p就不能修改,
				因为*p是解引用后的值,所以值不可以修改.用const修饰 p 的话,
				p不可以修改因为p存放的是一个内存地址,所以指向的内存地址不可以修改
*/

int main()
{
	int a = 10;
	int b = 10;

	//const修饰的是指针，指针指向可以改，指针指向的值不可以更改
	const int* p1 = &a;
	p1 = &b; //正确
	//*p1 = 100;  报错


	//const修饰的是常量，指针指向不可以改，指针指向的值可以更改
	int* const p2 = &a;
	//p2 = &b; //错误
	*p2 = 100; //正确

	//const既修饰指针又修饰常量
	const int* const p3 = &a;
	//p3 = &b; //错误
	//*p3 = 100; //错误

	return 0;
}