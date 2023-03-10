/*
	动态内存管理

		本章重点
			● 为什么存在动态内存分配
			● 动态内存函数的介绍
				○ malloc
				○ free
				○ calloc
				○ realloc

			● 常见的动态内存错误
			● 几个经典的笔试题
			● 柔性数组

		————————————————————————————————————————————————————————————————

		● 为什么存在动态内存分配
			
			我们已经掌握的内存开辟方式有
				int val = 20;			// 在栈空间上开辟4个字节
				char arr[10] = { 0 };	// 在栈空间上开辟10个字节的连续空间

			但是上述的开辟空间的方式有两个特点
				1. 空间开辟大小是固定的
				2. 数组在声明的时候，必须指定数组的长度，它所需要的内存在编译时分配

			但是对于空间的需求，不仅仅是上述的情况。有时候我们需要的空间大小在程序运行的时候才能知道，
			这时候就只能试试动态内存开辟了


			栈区
				局部变量
				函数形参

			堆区
				动态内存开辟

			静态区(数据段)
				全局变量
				静态变量

		----------------------------------------------------------------

		● 动态内存函数的介绍

			○ malloc 分配内存块

				<stdlib.h>

				void* malloc (size_t size);
									 开辟的字节数

				这个函数向内存申请一块连续可用的空间，并返回指向这块空间的指针

					1. 如果开辟成功，则返回一个指向开辟好空间的指针。
					2. 如果开辟失败，则返回一个NULL指针，因此 malloc 的返回值一定要做检查。
					3. 返回值的类型是void* ，所以 malloc 函数并不知道开辟空间的类型，
					   具体在使用的时候使用者自己来决定。
					4. 如果参数size为0，malloc 的行为是 标准是 未定义的，取决于编译器。

				演示&讲解
					动态内存函数malloc分配内存块();


			○ free 动态内存释放

				<stdlib.h>

				void free (void* ptr);

				C语言提供了另外一个函数free，专门是用来做动态内存的释放和回收的
				free函数用来释放动态开辟的内存
					1. 如果参数prt指向的空间不是动态开辟的，那free函数的行为是未定义的。
					   (free 只能释放堆区上开辟的空间的起始地址)
					2. 如果参数ptr是NULL指针，则函数什么事都不做。

				演示&讲解
					动态内存函数malloc分配内存块();
					动态内存函数calloc分配内存块并初始化();
					动态内存函数realloc重新分配();


			○ calloc 分配内存块并初始化
				
				<stdlib.h>

				void* calloc (size_t num, size_t size);
							  元素个数	, 每个元素的大小(字节)

				calloc函数也用来动态内存分配
					1. 函数的功能是为num个大小为size的元素开辟一块空间，
					   并且把空间的每个字节初始化为0
					2. 与函数 malloc 的区别只在于 calloc 会在返回地址之前把
					   申请的空间的每个字节初始化为全0

				演示&讲解
					动态内存函数calloc分配内存块并初始化();


			○ realloc 动态内存调整(重新分配)

				<stdlib.h>

				void* realloc (void* ptr, size_t size);

				1. realloc 函数的出现让动态内存管理更加灵活。
				2. 有时我们会发现过去申请的空间太小了，有时我们又会觉得申请的空间太大了，
				   那为了合理的时候内存，我们一定会对内存的大小做灵活的调整。
				3. ptr 是要调整的内存地址。
				4. size 调整之后新大小
				5. 返回值为调整之后的内存起始位置
				6. 这个函数调整原内存空间大小的基础上，还会将原来内存中的数据移动到新的空间。
				7. realloc 在调整内存空间存在两种情况
					情况1：原有空间之后有足够大的空间
						增加原有空间
						[1][2][3][4][5] + [ ][ ][ ][ ][ ]...[*][*][*]

					情况2：原有空间之后没有足够大的空间
						移动到新空间
						[1][2][3][4][5][*][*][*]
						↓
						[1][2][3][4][5][ ][ ][ ][ ][ ]...[*][*][*]

				演示&讲解
					动态内存函数realloc重新分配();
					动态内存函数realloc重新分配II();

		----------------------------------------------------------------

		● 常见的动态内存错误

			○ 对NULL指针的解引用操作

				int* p = (int*)malloc(60000000000);
				// 这里少了判断，开辟失败返回空指针
				*p = 20;
				free(p);


			○ 对动态开辟空间的越界访问

				int* p = (int*)malloc(10 * sizeof(int));

				if (p == NULL)
				{
					return;
				}

				int i = 0;
				for (i = 0; i < 40; i++)
				{
					*(p + i) = i;// 越界访问
				}

				free(p);


			○ 对非动态开辟内存使用free释放

				int arr[10] = { 0 };// 栈区
				int* p = arr;
				free(p);
				p = NULL;


			○ 使用free释放一块动态开辟内存的一部分

				int* p = (int*)malloc(10 * sizeof(int));
				if (p == NULL)
				{
					return;
				}

				int i = 0;
				for (i = 0; i < 5; i++)
				{
					*p++ = i;// p指向的位置已经往后走了
				}

				free(p);// 从p当前位置往后释放
				p = NULL;


			○ 对同一块动态内存多次释放

				int* p = (int*)malloc(100);
				free(p);
				free(p);

				防止此事发生

				int* p = (int*)malloc(100);
				free(p);
				p = NULL;
				free(p);// free 接收到空指针什么事都不做


			○ 动态开辟内存忘记释放(内存泄露)

				void test()
				{
					int* p = (int*)malloc(100);
					if (p == NULL)
					{
						return;
					}
				}

				int main()
				{
					test();

					return 0;
				}

				动态开辟的空间，2种回收方式
					1. 主动free
					2. 程序结束
		
		----------------------------------------------------------------

		● 几个经典的笔试题

			讲解
				//题目1();
				题目1改正1();
				题目1改正2();
				题目2();
				//题目3();
				题目3改正1();
				//题目4();
				题目4改正1();
		
		----------------------------------------------------------------

		● 柔性数组

		----------------------------------------------------------------
		————————————————————————————————————————————————————————————————
*/
/*

	C/C++程序内存分配的几个区域

		1. 栈区（stack）：在执行函数时，函数内局部变量的存储单元都可以在栈上创建，
		   函数执行结束时这些存储单元自动被释放。
		   栈内存分配运算内置于处理器的指令集中，效率很高，但是分配的内存容量有限。
		   栈区主要存放运行函数而分配的局部变量、函数参数、返回数据、返回地址等。

		2. 堆区（heap）：一般由程序员分配释放， 若程序员不释放，程序结束时可能由OS回收。
		   分配方式类似于链表。

		3. 数据段（静态区）（static）存放全局变量、静态数据。程序结束后由系统释放。

		4. 代码段：存放函数体（类成员函数和全局函数）的二进制代码。


	有了这幅图，我们就可以更好的理解在《C语言初识》中讲的 static关键字修饰局部变量的例子

		实际上普通的局部变量是在栈区分配空间的，栈区的特点是在上面创建的变量出了作用域就销毁。
		但是被static修饰的变量存放在数据段（静态区），数据段的特点是在上面创建的变量，直到程序结束才销毁所以生命周期变长。
*/

#include "define.h"
#include <stdlib.h>

void n2(int 换行次数, char* 换行符号, int 符号个数)
{
	int i = 0;

	if (换行符号 != NULL && 符号个数 > 0)
	{
		printf("\n");
		for (i = 0; i < 符号个数; i++)
		{
			printf("%s", 换行符号);
		}
	}

	for (i = 0; i < 换行次数; i++)
	{
		printf("\n");
	}
}

/**************************************************************************************************************************************************/
/*================================================================================================================================================*/

void 动态内存函数malloc分配内存块()
{
	printf("动态内存函数malloc分配内存块\n");

	// 开辟10个整形的空间
	// 10 * sizeof(int)
	// int* p = malloc(10 * sizeof(int));// 建议强制类型转换
	int* p = (int*)malloc(10 * sizeof(int));

	// 使用前
	if (p == NULL)
	{
		perror("动态内存函数malloc分配内存块");
		return;
	}

	// 使用
	// [1][2][3][4][5][6][7][8][9][10]
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		*(p + i) = i;// 解引用找到元素，赋值
	}

	// 查看
	for (i = 0; i < 10; i++)
	{
		printf("%d ", p[i]);// p[i] 等价于 *(p + i)
	}

	// 释放
	free(p);// p指向那块空间的起始位置，释放那块空间

	// 置空
	// free 并不会把p置空
	p = NULL;

	n2(2, "-------- ", 0);
}

/*================================================================================================================================================*/

void 动态内存函数calloc分配内存块并初始化()
{
	printf("动态内存函数calloc分配内存块并初始化\n");

	// malloc
	int* p = (int*)malloc(40);

	if (p == NULL)
	{
		return;
	}

	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d\n", *(p + i));
	}

	free(p);

	/*----------------------------------- -----------------------------------*/

	// calloc
	p = (int*)calloc(10, sizeof(int));

	if (p == NULL)
	{
		return;
	}

	for (i = 0; i < 10; i++)
	{
		printf("%d\n", *(p + i));
	}

	free(p);
	p = NULL;

	n2(1, "-------- ", 0);
}

/*================================================================================================================================================*/

void 动态内存函数realloc重新分配()
{
	printf("动态内存函数realloc重新分配\n");

	int* p = (int*)calloc(10, sizeof(int));

	if (p == NULL)
	{
		return;
	}

	int i = 0;
	for (i = 0; i < 10; i++)
	{
		*(p + i) = 5;
	}

	// 这里需要p指向的空间更大，需要20个int的空间
	// 
	// p = realloc(p, 20 * sizeof(int));
	// 不能直接用之前的p来接收，因为realloc找不到合适的空间会返回空指针
	int* ptr = (int*)realloc(p, 20 * sizeof(int));// 不是增加的大小，是新的大小

	// 判断临时指针是否为空
	if (ptr != NULL)
	{
		p = ptr;
	}

	free(p);
	p = NULL;
	ptr = NULL;

	n2(1, "-------- ", 0);
}

/*================================================================================================================================================*/

void 动态内存函数realloc重新分配II()
{
	printf("动态内存函数realloc重新分配II\n");

	int* p = (int*)realloc(NULL, 40);// 这里功能类似于malloc，就是直接在堆区开辟40个字节

	n2(1, "-------- ", 4);
}

/*================================================================================================================================================*/
/*================================================================================================================================================*/

// 题目1() 函数会有什么样的结果？

void 题目1GetMemory(char* p)
{
	p = (char*)malloc(100);
}

void 题目1(void)
{
	char* str = NULL;
	题目1GetMemory(str);
	strcpy(str, "hello world");
	printf(str);
}

/*
	str 传给 GetMemory 函数的时候是值传递，所以 GetMemory 函数的形参 p 是 str 的一份临时拷贝。
	在 GetMemory 函数内部动态申请空间的地址，存放在 p 中，不会影响外面的 str ，
	所以 GetMemory 函数返回之后，str 依然是 NULL，所以 strcpy 会失败。

	当 GetMemory 函数返回之后，形参p销毁，使得动态开辟的100个字节存在内存泄露，无法释放。
*/

char* 题目1GetMemory改正1(char* p)
{
	p = (char*)malloc(100);
	return p;
}

void 题目1改正1(void)
{
	n2(1, "-------- ", 0);
	printf("题目1改正1\n");

	char* str = NULL;
	str = 题目1GetMemory改正1(str);
	strcpy(str, "hello world");
	printf(str);

	free(str);
	str = NULL;

	n2(1, "-------- ", 0);
}

/*----------------------------------- -----------------------------------*/

void 题目1GetMemory改正2(char** p)
{
	*p = (char*)malloc(100);
}

void 题目1改正2(void)
{
	n2(1, "-------- ", 0);
	printf("题目1改正2\n");

	char* str = NULL;
	题目1GetMemory改正2(&str);
	strcpy(str, "hello world");
	printf(str);

	free(str);
	str = NULL;

	n2(1, "-------- ", 0);
}

/*================================================================================================================================================*/

char* 题目2GetMemory()
{
	char p[] = "hello world";
	return p;
}

void 题目2(void)
{
	n2(1, "-------- ", 0);
	printf("题目2\n");

	char* str = NULL;
	str = 题目2GetMemory();
	printf(str);

	n2(1, "-------- ", 0);
}

/*
	GetMemory 函数内部创建的数组是在栈区上创建的
	出了函数，p数组的空间就还给了操作系统
	返回的地址是没有实际的意义，如果通过返回的地址，去访问内存就是非法访问内存
*/

/*================================================================================================================================================*/

void 题目3GetMemory(char** p, int num)
{
	*p = (char*)malloc(num);
}

void 题目3(void)
{
	char* str = NULL;
	题目3GetMemory(&str, 100);
	strcpy(str, "hello");
	printf(str);
}

/*
	没有 free
*/

void 题目3GetMemory改正1(char** p, int num)
{
	*p = (char*)malloc(num);
}

void 题目3改正1(void)
{
	n2(1, "-------- ", 0);
	printf("题目3改正1\n");

	char* str = NULL;
	题目3GetMemory改正1(&str, 100);
	strcpy(str, "hello");
	printf(str);

	free(str);
	str = NULL;

	n2(1, "-------- ", 0);
}

/*================================================================================================================================================*/

void 题目4(void)
{
	char* str = (char*)malloc(100);
	strcpy(str, "hello");
	free(str);

	if (str != NULL);
	{
		strcpy(str, "world");
		printf(str);
	}
}

/*
	free 后没有 置空
*/

void 题目4改正1(void)
{
	n2(1, "-------- ", 0);
	printf("题目4改正1\n");

	char* str = (char*)malloc(100);
	strcpy(str, "hello");

	free(str);
	str = NULL;

	if (str != NULL)
	{
		strcpy(str, "world");
		printf(str);
	}

	n2(1, "-------- ", 4);
}

/*================================================================================================================================================*/

int main()
{
	动态内存函数malloc分配内存块();

	动态内存函数calloc分配内存块并初始化();

	动态内存函数realloc重新分配();
	动态内存函数realloc重新分配II();


	//题目1();
	题目1改正1();
	题目1改正2();

	题目2();

	//题目3();
	题目3改正1();

	//题目4();
	题目4改正1();

	return 0;
}

/**************************************************************************************************************************************************/
