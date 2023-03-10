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

			整形表示的范围：limits.h中定义

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

		-------- -------- -------- -------- --------

		4.浮点型在内存中的存储解析
			常见的浮点数
				3.14159
				1E10(1.0 * 10 的 10 次方)
				1E5 (1.0 * 10 的 5 次方)

			浮点数表示的范围：float.h中定义

			浮点型和整型在内存中存储和解读的方式有区别

			根据国际标准IEEE(电气和电子工程协会)754，任意一个二进制浮点数V可以表示成下面的形式
				(-1)^S * M * 2^E
					(-1)^S表示符号位，当S=0，V为正数；当S=1，V为负数
					M表示有效数字，大于等于1，小于2
					2^E表示指数位

				浮点数
					十进制：5.5
					二进制：101.1
					科学计数法：1.011小数点向左移动了两位，相当于1.011*2^2

					101.1 = 1.011*2^2 = (-1)^0 * 1.011*2^2
											 ↑	   ↑	 ↑
											 S	   M	 E
											 0	 1.011	 2

					1.011是M，M表示有效数字，大于等于1，小于2
					2^2后面的2是E

				IEEE 754规定：对于32位的浮点数(float)，最高的1位是符号位S，接着的8位的指数E，剩下的23位是有效数字M
					[] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] 
					↑   ↖_________________↗	↖______________________________________________________________↗
					S			  E												M
				   1bit			 8bit										  23bit

				IEEE 754规定：对于64位的浮点数(double)，最高的1位是符号位S，接着的11位的指数E，剩下的52位是有效数字M
					[] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] 
					↑   ↖__________________________↗	 ↖_____________________________________________________________________________________________________________________________________________________↗
					S			      E												M
				   1bit			    11bit										  52bit

				IEEE 754对有效数字的M和指数E，还有一些特别的规定。前面说过，1<M<2，也就是说，M可以写成1.xxxxxx的形式，其中xxxxxx表示小数部分。

				IEEE 754规定：在计算机内部保存M时，默认这个数的第一位总是1，因此可以被舍去，只保存后面的xxxxxx部分。
							  比如保存1.01的时候，只保存01，等到读取的时候，再把第一位的1加上去。这样做的目的是节省1位有效数字。
							  以32位浮点数为例，留给M只有23位，将第一位的1舍去以后，等于可以保存24位有效数字。

							  至于指数E，情况就比较复杂。
							  首先，E作为一个无符号整数(unsigned int)这意味着，如果E为8位，它的取值范围为0~255；如果E为11位，它的取值范围为0~2047。
							  但是，科学计数法中E是可以出现负数的，所以IEEE 754规定，存入内存时E的真实值必须再加上一个中间数，
							  对于8位的E，这个中间数是127；对于11位的E，这个中间数是1023。
							  比如2^10的E是10，所以保存成32位浮点数时，必须保存成10+127=137，即10001001

							  举例
								十进制：0.5
								二进制：0.1 = 1.0 * 2^-1 ——> S=0，M=1.0，E=-1
																		 ↑
																		float：-1+127 = 126 得到126再把126存入E的8个比特位中
																		double:-1+1023=1022 得到1022再把1022存入E的11个比特位中

				然后，指数E从内存中取出还可以再分成三种情况

					E不全为0 或 不全为1
						这时，浮点数就采用下面的规则表示，即指数E的计算值减去127(或1023)，得到真实值，再将有效数字M前加上第一位的1。
						比如：0.5(1/2)的二进制形式为0.1，由于规定正数部分必须为1，即将小数点右移1位，则为1.0*2^(-1)，
						其阶码为-1+127=126，表示为01111110，而尾数1.0去掉整数部分为0，补齐0到23位 0000000 00000000 00000000
						则其二进制表示形式为
						0 01111110 0000000 00000000 00000000

					E为全0
						这时，浮点数的指数E等于1减127(或者1减1023)即为真实值，有效数字M不再加上第一位的1，
						而是还原为0.xxxxxx的小数。这样做是为了表示±0，以及接近于0的很小的数字。
						(非常小的数字 2^-127)

					E为全1
						这时，如果有效数字M全为0，表示±无穷大(正负取决于符号位S)
						(非常大的数字 2^128)

				是啊，你记住这个公式就行了float的存进去+127 取的时候减掉 记得把1补回来，


		-------- -------- -------- -------- --------
		补充
			char C语言标准没有规定是signed char还是unsigned char，取决于编译器。大部分编译器都是signed char
			int 是signed int
			short 是signed short

			char类型变量的取值范围
				char占1字节 = 8bit

						  内存
				char	00000000	8个比特位里面要存放数据的话 可能存放的是8个0 到 8个1 的可能性
						00000001
						01111111	= 127
						...
						10000000	= -128
						11111110
						11111111	反码11111110 原码10000001 = -1

				有符号char的取值范围-128~127
		-------- -------- -------- -------- --------



*/

#include "define.h"


void 浮点数存储的例子()
{
	int n = 9;// 4字节
	float* pFloat = (float*)&n;// 强制类型转换
	printf("n的值为：%d\n", n);// 9
	printf("*pFloat的值为：%f\n", *pFloat);// *pFloat是以浮点数的视角去看的

	*pFloat = 9.0;// 以浮点数的视角存储9.0
	printf("n的值为：%d\n", n);
	printf("*pFloat的值为：%f\n", *pFloat);// 9.0
}

void 浮点数存储的例子讲解()
{
	int n = 9;
	float* pFloat = (float*)&n;
	printf("n的值为：%d\n", n);
	printf("*pFloat的值为：%f\n", *pFloat);

	*pFloat = 9.0;
	printf("n的值为：%d\n", n);
	printf("*pFloat的值为：%f\n", *pFloat);

	/*
		n 二进制 
			0 00000000 00000000000000000001001
			S	  E				M

		浮点数取出 
				0. 00000000000000000001001 * 2^-126
			E全0不补1			M

		*pFloat = 9.0;存储 小数点向左移动了3位
			1001.0 = 1.001 * 2^3
			E = 3，应该加上127再存进去 = 130
			0 10000010 00100000000000000000000

		整数形式打印9.0，前面0 正数 原反补相同
			0 10000010 00100000000000000000000
	*/

}

void 练习1()
{
	//101.1
	//1.011 * 2^2
	//S=0 M=1.011 E=2
	//S=0 M=1.011 E=2+127
	//
	// S	E	  M是011 不够后面补0
	// 0 10000001 011 00000000000000000000
	// 
	// 4个二进制位就是一个十六进制位
	// 40 B0 00 00
	float f = 5.5f;
}

int main()
{
	浮点数存储的例子();

	//浮点数存储的例子讲解();

	练习1();



	return 0;
}