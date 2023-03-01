/*
	深度剖析数据在内存中的存储

											// release版本没有死循环 release版本做了优化
											int i = 0;
											int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
											for (i = 0; i <= 12; i++)
											{
												arr[i] = 0;
												printf("hehe\n");
											}

											// debug版本和release版本地址对比
											int i = 0;
											int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
											//								debug		release
											printf("%p\n", &i);		//		地址大	|	地址小
											printf("%p\n", &arr[9]);//		地址小	|	地址大

											release 称为发布版本，它往往是进行了各种优化，使得程序在代码大小和运行速度上都是最优的，以便用户很好地使用

		本章重点
			1.数据类型详细介绍
			2.整形在内存中的存储：原码、反码、补码
			3.大小端字节序介绍及判断
			4.浮点型在内存中的存储解析

		-------- -------- -------- -------- --------

		1.数据类型详细介绍
			前面我们已经学习了基本的内置类型：
				char		字符数据类型
				short		短整形
				int			整形
				long		长整形
				long long	更长的整形
				float		单精度浮点数
				double		双精度浮点数
				// C语言有没有字符串类型？
			以及他们所占存储空间的大小

			类型的意义：
				1.使用这个类型开辟内存空间的大小(大小决定了使用范围)
				2.如何看待内存空间的视角

			类型的基本归类：

				整形家族
					char
						unsigned char
						signed char

					short
						unsigned short [int]
						signed short [int]

					int
						unsigned int
						signed int

					long
						unsigned long [int]
						signed long [int]

				浮点数家族
					float
					double

				构造类型(自定义类型)
					数组类型
					结构体类型 struct
					枚举类型 enum
					联合类型 union

				指针类型
					int* pi;
					char* pc;
					float* pf;
					void* pv;

				空类型
					void 表示空类型(无类型)
					通常应用于函数的返回类型、函数的参数、指针类型。

		-------- -------- -------- -------- --------

		2.整形在内存中的存储：原码、反码、补码

			数据在内存中以二进制的形式存储
			对于整数来说 整数二进制有3种表示形式：原码、反码、补码
			正整数：原码、反码、补码相同
			负整数：原码、反码、补码要进行计算
			整数在内存中存储的是补码

			为什么整数在内存中存储的是补码？

				在计算机系统中，数值(整数)一律用补码来表示和存储。原因在于，使用补码，可以将符号位和数值域统一处理；
				同时，加法和减法也可也统一处理(CPU只有加法器)此外，补码与原码相互转换，其运算过程是相同的，不需要额外的硬件电路

				因为0和-0是一样的，但是在原码中的0和-0最高位就不同，所以科学家就提出了反码，但是反码也表示不出0和-0相同，
				而反码再加1就可以表示0和-0相同，所以就产生了补码

				CPU没有减法器 计算以下
					1 + 1
					1 + (-1)
				用原码计算 结果不正确
					00000000 00000000 00000000 00000001 = 1
					+
					10000000 00000000 00000000 00000001 = -1
					=
					10000000 00000000 00000000 00000010 = -2

				用补码计算
					00000000 00000000 00000000 00000001 = 1
					+
					11111111 11111111 11111111 11111111 = -1
					=
				   100000000 00000000 00000000 00000000 = 0
				   ↑
				   多出的位 丢弃

			原码：按照数据的数值直接写出的二进制序列
			反码：原码的符号位不变 其他位按位取反
			补码：反码+1

			补码 取反 +1 就是原码

		-------- -------- -------- -------- --------

		3.大小端字节序介绍及判断
			
			大小端介绍
				大端(存储)模式，是指数据的 低位 保存在内存的 高地址 中，而数据的 高位 保存在内存的 低地址 中
				小端(存储)模式，是指数据的 低位 保存在内存的 低地址 中，而数据的 高位 保存在内存的 高地址 中


				// 大端字节序和小端字节序
				int c = 0x11223344;
						  ↑      ↑
						 高      低

				以下两种存放方式，怎么存放的就怎么拿出来
									内存
						--------------------------------
						|		11 22 33 44			   |	正着存 大端字节序
						--------------------------------
				低地址										高地址
						--------------------------------
						|		44 33 22 11			   |	倒着存 小端字节序
						--------------------------------


				关于正着存还是倒着存是根据操作系统决定的 
				在windows系统下 内存的地址都是从0开始往后排的但是数据本身就有高地址和低地址之分，
				所以数据的存储数据的 高位地址 就在内存的 高地址上面，数据的 低地址 就在 低地址

			为什么有大端和小端
				为什么有大端和小端模式之分呢？这是因为在计算机系统中，我们是以字节为单位的，
				每个地址单元对应着一个字节，一个字节8bit。但是在C语言中除了8bit的char之外，还有16bit的short型，32bit的long型
				(要看具体的编译器)，另外，对于位数大的8位的处理器，例如16位或者32位的处理器，由于寄存器宽度大于一个字节，
				那么必然存在着一个如果将多个字节安排的问题。因此就导致了大端存储模式和小端存储模式。

				例如一个16bit的short型x，在内存中的地址为0x0010，x的值为0x1122，那么0x11为高字节，0x22为低字节。
				我们常用的x86结构是小端模式，而KETL C51则为大端模式。很多的ARM，DSP都为小端模式。
				有些ARM处理器还可以由硬件来选择是大端模式还是小端模式

				因为数据存在内存中可能占的不止一个字节 也有可能是2个 8个...。这就会有存放顺序的问题



*/

#include "define.h"



int main()
{
	// 我们可以看到对于a和b分别存储的是补码，但是顺序是 倒着存储
	int a = -10;
	// 14 00 00 00

	int b = 10;
	// f6 ff ff ff


	// 大端字节序和小端字节序
	int c = 0x11223344;

	return 0;
}