/*
	指针初阶
		1.指针是什么
		2.指针和指针类型
		3.野指针
		4.指针运算
		5.指针和数组
		6.二级指针
		7.指针数组

		======== ======== ======== ======== ========
		-------- -------- -------- -------- --------
		1.指针是什么
			在计算机科学中，指针（Pointer）是编程语言中的一个对象，利用地址，它的值直接指向（points to）存在电脑存储器中另一个地方的值。
			由于通过地址能找到所需的变量单元，可以说，地址指向该变量单元。因此，将地址形象化的称为"指针"。意思就是通过它能找到
			以它为地址的内存单元。

			那我们就可以这样理解
				内存

					  内存		   编号
					-------- |  ----------
					一个字节	 |  0xFFFFFFFF
					-------- |  ----------
					一个字节	 |  0xFFFFFFFE
					-------- |  ----------
					一个字节	 |
					-------- |  ----------
							 |  ...
					-------- |  ----------
							 |  ...
					-------- |  ----------
							 |  ...
					-------- |  ----------
					一个字节	 |  0x00000002
					-------- |  ----------
					一个字节	 |  0x00000001
					-------- |  ----------
					一个字节	 |  0x00000000
					-------- |  ----------

					内存是一块大的空间，如何去管理，把内存划分为一个一个的内存单元，一个格子就是一个内存单元，一个内存单元1字节
					为了很好的管理内存单元，给每一个内存单元进行编号，内存单元编号也可也叫做地址，通过编号可以找到内存单元，地址指向内存单元

					内存单元编号如何产生？
						32位机器通电之后产生电信号，电信号有正电和负电，电信号转换成数字信号之后，就是32个0，1组成的二进制序列。
						32个0，1组成的二进制序列有多少种可能性？
							00000000 00000000 00000000 00000000
							到
							11111111 11111111 11111111 11111111
						这中间产生的所有编号就可以被当成内存单元的编号

			总结：
				指针是用来存放地址的，地址是唯一标示一块地址空间的。
				指针的大小在32位平台是4字节，64位平台是8字节。

		-------- -------- -------- -------- --------
		2.指针和指针类型
			变量有不同的类型，指针也有不同的类型

			指针类型的意义
				1.指针类型决定访问权限
				2.指针类型决定了指针走一步能走多远(步长)，整形指针+1步长4，字符指针+1步长1


			总结
				指针的类型决定了，对指针解引用的时候有多大的权限(能操作几个字节)。
				比如：char*的指针解引用只能访问一个字节，而int*的指针的解引用就能访问四个字节
		-------- -------- -------- -------- --------

		3.野指针
			概念：野指针就是指针指向的位置是不可知的（随机的、不正确的、没有明确限制的）

			1.指针未初始化
				int* p;// p是一个局部的指针变量，局部变量不初始化默认随机值
				*p = 20;// 非法访问内存
				 
			2.指针越界访问
				int arr[10] = { 0 };
				int* parr = arr;
				int i = 0;
				for (i = 0; i <= 10; i++)
				{
					*parr = i;
					// 当指针指向的范围超出数组arr的范围时，p就是野指针
					parr++;
				}

			3.指针指向的空间释放
				这里放在动态内存开辟的时候讲解，

				int* test()
				{
					int a = 10;
					return &a;
				}
				int main()
				{
					int* p = test();
					*p = 20;
				}

			如何规避野指针
				1.指针初始化
					当不知道指针变量应该初始化为 什么地址的时候，直接初始化为NULL
					int* p = NULL;

				2.小心指针越界
					C语言本身是不会检查数组的越界行为的

				3.指针指向空间释放及时置NULL
					int* p = NULL;
					
				4.指针使用之前检查有效性
					int* p = NULL;
					if(p != NULL)
					{
						*p = 10;
					}


			p是指针 *p是解引用代表p指向的内存空间
		-------- -------- -------- -------- --------

		4.指针运算
			指针 + - 整数
			指针 - 指针
			指针的关系运算

			float arr[5];
			float* vp;
			// 指针+-整数，指针的关系运算
			for(vp = &arr[0]; vp < &arr[5];)
			{
				*vp++ = 0;
			}

			指针 - 指针
				int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
				printf("%d\n", &arr[9] - &arr[0]);

				指针-指针得到的两个指针之间的元素个数
				指针-指针的前提：两个指针指向同一块空间
			
		-------- -------- -------- -------- --------
*/

#include "define.h"

int main()
{
	//int* p;// p是一个局部的指针变量，局部变量不初始化默认随机值
	//*p = 20;// 非法访问内存


	//int arr[10] = { 0 };
	//int* parr = arr;
	//int i = 0;
	//for (i = 0; i <= 10; i++)
	//{
	//	*parr = i;
	//	// 当指针指向的范围超出数组arr的范围时，p就是野指针
	//	parr++;
	//}
	
	

	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	printf("%d\n", &arr[9] - &arr[0]);

	return 0;
}