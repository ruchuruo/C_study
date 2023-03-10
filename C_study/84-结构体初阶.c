/*
	结构体初阶
		结构体类型的声明
		结构体初始化
		结构体成员访问
		结构体传参

		-------- -------- -------- -------- --------

		结构体的声明
			结构的基础知识
				结构是一些值的集合，这些值称为成员变量。结构的每个成员可以是不同类型的变量。

				数组：一组相同类型的元素的集合
				结构体：也是一些值的集合，但是值的类型可以不同

			结构的声明
				// 类型。然后用类型创建一个对象，就像照着图纸盖房子
				struct 学生
				{
					// 成员变量
					char 名字[20];// 字符数组
					int 年龄;
					char 学号[20];
				};

				int main()
				{
					// 用 struct 学生 创建一个对象s
					struct 学生 s;
					return 0;
				}

				画图比喻：
					struct 学生								int main()
					{										{
						char 名字[20];							struct 学生 s;
						int 年龄;								
						char 学号[20];							return 0;
					};										}
					|----------------|						|----------------|
						   类型     ---------------------------→	   对象
							↑										↑
							|										|
							|										|
						   图纸     ---------------------------→	   房子


				// 类型。然后用类型创建一个对象，就像照着图纸盖房子
				struct 学生
				{
					// 成员变量
					char 名字[20];// 字符数组
					int 年龄;
					char 学号[20];
				} s1,s2;// s1 s2也是结构体的变量，是全局变量

				int main()
				{
					// 用 struct 学生 创建一个对象s，s是局部变量
					struct 学生 s;
					return 0;
				}
			

			结构成员的类型
				结构的成员可以是标量，数组，指针，甚至是其他结构体

				结构的成员是其他结构体
					struct A
					{
						char b;
						short c;
						double d;
					};
					struct 学生
					{
						struct A sa;
						char 名字[20];
						int 年龄;
						char 学号[20];
					};

		-------- -------- -------- -------- --------

		结构体初始化

			有了结构体类型，那如何定义变量
				struct Point
				{
					int x;
					int y;
				}p1;				// 声明类型的同时定义变量p1
				struct Point p2;	// 定义结构体变量p2

			初始化
				struct A
				{
					char b;
					short c;
					double d;
				};

				struct 学生
				{
					struct A sa;
					char 名字[20];
					int 年龄;
					char 学号[20];
				};

				int main()
				{
					// {'w', 20, 3.14}这个大括号里的数据是给sa的 嵌套初始化
					struct 学生 s = { {'w', 20, 3.14}, "张三", 30, "2022" };

					return 0;
				}

		-------- -------- -------- -------- --------

		结构体成员访问
			结构体变量访问成员 结构变量的成员是通过操作符"."访问的。"."操作符接受两个操作数
			操作符
				.
				->

			struct A
			{
				char b;
				short c;
				double d;
			};

			struct 学生
			{
				struct A sa;
				char 名字[20];
				int 年龄;
				char 学号[20];
			};

			int main()
			{
				struct 学生 s = { {'w', 20, 3.14}, "张三", 30, "2022" };
				printf("%c\n", s.sa.b);
				printf("%s\n", s.学号);

				struct 学生* ps = &s;// *说明ps是指针，struct 学生 说明 ps 指向的是一个结构体类型的对象
				printf("%d\n", ps->年龄);

				return 0;
			}

		-------- -------- -------- -------- --------

		结构体传参

			struct A
			{
				char b;
				short c;
				double d;
			};

			struct 学生
			{
				struct A sa;
				char 名字[20];
				int 年龄;
				char 学号[20];
			} s1,s2;



			void 打印1(struct 学生 x)
			{
				printf("%c %d %lf %s %d %s\n", x.sa.b, x.sa.c, x.sa.d, x.名字, x.年龄, x.学号);
			}
			void 打印2(struct 学生* px)
			{
				printf("%c %d %lf %s %d %s\n", px->sa.b, px->sa.c, px->sa.d, px->名字, px->年龄, px->学号);
			}

			int main()
			{
				struct 学生 s = { {'w', 20, 3.14}, "张三", 30, "20220423" };

				// 写一个函数打印s的内容
				打印1(s); // 传值调用
				打印2(&s);// 传址调用
				// 1出错了有备份但占用内存，消耗时间。2出错了可就拉垮了但节省内存。
				// 1需要开辟新空间，占用内存，消耗时间
				return 0;
			}

			首选 打印2 函数
				函数传参的时候，参数是需要压栈的，如果传递一个结构体对象的时候
				，结构体过大，参数压栈的系统开销比较大，所以会导致性能的下降

			结论：结构体传参的时候，要传结构体的地址

		-------- -------- -------- -------- --------
		-------- -------- -------- -------- --------

		函数调用的参数压栈

			栈，是一种数据结构。先进后出，后进先出。弹夹的子弹一样，后进先出

			假设存放1 2 3 4 5 
					 ↘	从顶上往下放，叫压栈。给栈中存放数据叫压栈(压栈)
					  ↓		
					  ↓	   →  删除元素1，只能从顶上删，先删5，因为元素1拿不到，再删4......(出栈)
					 ↙	↗	
					-----
					| 5 |
					-----
					| 4 |
					-----
				栈	| 3 |
					-----
					| 2 |
					-----
					| 1 |
					-----


			代码演示
				int Add(int x, int y)
				{
					int z = 0;
					z = x + y;
					return z;
				}
				int main()
				{
					int a = 3;
					int b = 5;
					int c = 0;
					c = Add(a, b);// 大部分编译器传参是从右到左

					return 0;
				}

			每一个函数调用都会在内存的 栈区 上开辟一块空间

			代码执行过程
				进入main()函数	为Amain()函数函数开辟空间
				声明变量a赋值3
				声明变量b赋值5
				声明变量c赋值0

				传参b			栈区开辟空间	假设叫b’ = 5
				传参a			栈区开辟空间	假设叫a’ = 3

				调用Add()函数	为Add()函数开辟空间
				声明变量z赋值0
				z = x + y		访问x其实是a’ 访问y其实是b’
				return z		返回z
				c = Add(a, b)	返回值放到c里

				Add()调用完成
				Add()			开辟的空间释放了
				b’ = 5			开辟的空间释放了
				a’ = 3			开辟的空间释放了

				//				   内存
				//		|=======================|
				//		|-----------------------|
				//		|-局部变量				|
				//		|-函数的形式参数			|
				//栈区	|-(临时的变量都放在这)	|	-------- -------- →
				//		|-						|						↘
				//		|-						|						  ↘
				//		|-----------------------|						    ↘
				//		|=======================|							 |
				//		|-----------------------|							 |
				//		|-动态内存分配			|							 |
				//		|-						|							 |
				//堆区	|-						|							 |
				//		|-						|							 |
				//		|-						|							 |
				//		|-----------------------|							↙
				//		|=======================|						  ↙	
				//		|-----------------------|						↙
				//		|-全局变量				|					  ↙
				//		|-static修饰的静态变量	|					↙
				//静态区	|-						|				  ↙
				//		|-						|				↙
				//		|-						|			  ↙
				//		|-----------------------|			↙
				//		|=======================|		  ↙	
														↙
													  ↙
												    ↙
												  ↙	
											    ↙
											  ↙
								 内存栈区
						|=======================|
						|-----------------------|
						|-						|
						|-						|
						|-						|
						|=======================|
						|-						|↘
						|-						|	调用Add()函数	为Add()函数开辟空间 (z = x + y		访问x其实是a’ 访问y其实是b’)
						|-		z = 0			|↗
						|=======================|
						|-		a’ = 3			|	传参a			栈区开辟空间	假设叫a’ = 3 (a的值放到a’这个空间内)
						|-----------------------|		从上往下放，传参这个动作也叫压栈
						|-		b’ = 5			|	传参b			栈区开辟空间	假设叫b’ = 5 (b的值放到b’这个空间内)
				栈区		|=======================|
						|-						|↘
						|-						|  ↘
						|-						|    ↘
						|-----------------------|	   ↘
						|-		c = 0			|		为main()函数开辟空间，每个成员都有个空间
						|-----------------------|	   ↗
						|-		b = 5			|	 ↗
						|-----------------------|  ↗
						|-		a = 3			|↗
						|=======================|
						|-						|
						|-						|
						|-						|
						|=======================|

			感兴趣可以查 函数栈帧的创建和销毁


*/

#include "define.h"

struct A
{
	char b;
	short c;
	double d;
};

struct 学生
{
	struct A sa;
	char 名字[20];
	int 年龄;
	char 学号[20];
} s1,s2;



void 打印1(struct 学生 x)
{
	printf("%c %d %lf %s %d %s\n", x.sa.b, x.sa.c, x.sa.d, x.名字, x.年龄, x.学号);
}
void 打印2(struct 学生* px)
{
	printf("%c %d %lf %s %d %s\n", px->sa.b, px->sa.c, px->sa.d, px->名字, px->年龄, px->学号);
}

int main()
{
	struct 学生 s = { {'w', 20, 3.14}, "张三", 30, "20220423" };

	// 写一个函数打印s的内容
	打印1(s); // 传值调用
	打印2(&s);// 传址调用
	// 1出错了有备份但占用内存，消耗时间。2出错了可就拉垮了但节省内存。
	// 1需要开辟新空间，占用内存，消耗时间
	return 0;
}