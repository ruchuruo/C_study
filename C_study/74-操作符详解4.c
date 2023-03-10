/*
	操作符详解
		操作符和表达式
			1.各种操作符的介绍
			2.表达式求值

			操作符
				分类
					算数操作符
					移位操作符
					位操作符
					赋值操作符
					单目操作符
					关系操作符
					逻辑操作符
					条件操作符
					逗号表达式
					下标引用、函数调用和结构成员

					------------------------------------------

					算数操作符
						+
						-
						*
						/
						%

						1.除了%操作符之外，其他的几个操作符可以作用于整数和浮点数
						2.对于/操作符如果两个操作数都为整数，执行整数除法。而只要有浮点数执行的就是浮点数除法。
						3.%操作符的两个操作数必须为整数。返回的是整除之后的余数

					------------------------------------------

					移位操作符
						<< 左移
						>> 右移

						移位操作不会改变本身
							int c = 2;
							c << 1;
							printf("c = %d\n", c);// 2

						左移操作符 移位规则
							左边抛弃、右边补0

								int c = 2;
								// 把c的二进制位向左移动一位
								int c2 = c << 1;
								printf("c2 = %d\n", c2);

								// 整形变量 4字节 = 32比特位
								// 十进制2 = 二进制 [00000000 00000000 00000000 00000010]
								// 左移	0[0000000 00000000 00000000 000000100]
								//	    ↑									↑
								//	 溢出丢弃							   补0
								// 现在1来到了第三位，是2的2次方 = 4
								//

						右移操作符 移位规则
							1.算术右移
								右边丢弃，左边补原符号位

							2.逻辑右移
								右边丢弃，左边补0，不管正负数


							c6验证是 算术右移 还是 逻辑右移
								int c3 = 10;
								// 把c的二进制位向右移动一位 - 当前使用的是 算数右移
								int c4 = c3 >> 1;
								printf("c4 = %d\n", c4);
								// 十进制2 = 二进制 [00000000 00000000 00000000 00000010]
								// 右移	[000000000 00000000 00000000 0000101]0
								//		 ↑									 ↑
								//	    补0							      溢出丢弃

								// 用负数测试编译器是 算术右移 还是 逻辑右移 - 当前使用的是 算数右移
								int c5 = -1;
								int c6 = c5 >> 1;
								printf("c6 = %d\n", c6);
								// 负数 -1 存放在内存中 存放的是二进制的补码
								//
								// 整数的二进制表示形式：有3种
								//	原码：直接根据数值写出的二进制序列就是原码
								//	反码：原码的符号位不变，其他位按位取反就是反码
								//	补码：反码+1，就是补码
								//
								// -1原码：	[10000000 00000000 00000000 00000001]
								//			 ↑
								//		 这个1表示负数 符号位
								//
								// -1反码：	[11111111 11111111 11111111 11111110]
								//
								// -1补码：	[11111111 11111111 11111111 11111111]
								//
								// -1右移：	[ 1111111 11111111 11111111 11111111]1
								//			 ↑
								//		 算数补1原符号位，逻辑补0。补0就变正数

								原码 反码 补码 这个算法只针对负数，正整数的原码反码补码相同

					------------------------------------------

					位操作符
						& 按位与
						| 按位或
						^ 按位异或

						注：他们的操作数必须是整数

						int d = 3;	// 00000000 00000000 00000000 00000011
						int d2 = 5;	// 00000000 00000000 00000000 00000101
						// & - 按(二进制)位与 - 计算的位置相同是1，不同是0
						int d3 = d & d2; // 00000000 00000000 00000000 00000001
						printf("d3 = %d\n", d3);
						// 00000000 00000000 00000000 00000011 d
						// 00000000 00000000 00000000 00000101 d2
						// 00000000 00000000 00000000 00000001 d3计算结果

						// 按(二进制)位或 - 有1则1，同时为0则0
						int d4 = d | d2;
						printf("d4 = %d\n", d4);
						// 00000000 00000000 00000000 00000011 d
						// 00000000 00000000 00000000 00000101 d2
						// 00000000 00000000 00000000 00000111 d4计算结果

						// 按(二进制)位异或 - 对应的二进制位异或 - 相同为0，相异为1
						int d5 = d ^ d2;
						printf("d5 = %d\n", d5);
						// 00000000 00000000 00000000 00000011 d
						// 00000000 00000000 00000000 00000101 d2
						// 00000000 00000000 00000000 00000110 d5计算结果

					------------------------------------------

					赋值操作符
						基本赋值运算符：
							=

						复合赋值运算符：
							+=（加赋值）
							-=（减赋值）
							*=（乘赋值）
							/=（除赋值）
							％=（求余赋值）
							<<=（左移赋值）
							>>=（右移赋值）
							&=（按位与赋值）
							|=（按位或赋值）
							^=（按位异或赋值）


						连续赋值
							int a = 10;
							int x - 0;
							int y = 20;
							a = x = y + 1;// y+1赋值给x，x再赋值给a。最终x和a都是y+1的值

							同样语义
								x = y + 1;
								a = x;

					------------------------------------------

					单目操作符
						只有一个操作数

						！		逻辑反操作
						-		负值
						+		正值
						&		取地址
						sizeof	计算操作数的类型长度(以字节为单位)
						~		对一个数的二进制按位取反
						--		前置、后置--
						++		前置、后置++
						*		间接访问操作符(解引用操作符)
						(类型)	强制类型转换



						！		逻辑反操作
							int flag = 0;
							// flag为真打印hehe
							if (flag)
							{
								printf("hehe\n");
							}
							// flag为假打印haha
							if (!flag)
							{
								printf("haha\n");
							}
							// !可以让假变真 真变假
							printf("%d\n", !flag);


						-		负值
							int a = 10;
							a = -a;
							printf("%d\n", a);


						sizeof	计算操作数的类型长度(以字节为单位)
							int b = 10;
							char arr[66] = { 0 };
							int arr2[66] = { 0 };
							printf("b = %d\n", sizeof(b));// 计算b所占空间的大小，单位字节
							printf("b = %d\n", sizeof b);// 计算变量时括号可以省略，说明sizeof是一个操作符 不是函数

							printf("类型int = %d\n", sizeof(int));// 计算类型所占空间大小，单位字节

							printf("数组arr = %d\n", sizeof(arr));// 一个char 1字节 66个就66字节
							printf("数组arr2 = %d\n", sizeof(arr2));// 一个int  4字节

							printf("数组类型int = %d\n", sizeof(int [10]));// int [10] 是数组类型


						~		对一个数的二进制按位取反
							int e = -1;// -1在内存中存的是补码
							// 原码 10000000 00000000 00000000 00000001
							// 反码 11111111 11111111 11111111 11111110
							// 补码 11111111 11111111 11111111 11111111
							//
							// 按(二进制)位取反 包括符号位
							int f = ~e;
							printf("f = %d\n", f);


						--		前置、后置--
						++		前置、后置++
							int g = 10;
							int h = g++;// 后置++，先使用 再++
							printf("g = %d\n", g);
							printf("h = %d\n", h);

							int g2 = 10;
							int h2 = ++g2;// 前置++，先++ 再使用
							printf("g2 = %d\n", g2);
							printf("h2 = %d\n", h2);

							int a = 1;
							在这条语句中还是用a，语句结束，a的值才变化了，加一


						&		取地址
						*		间接访问操作符(解引用操作符)

							按位与是双目操作符 取地址是单目操作符

							int a = 10;
							printf("&a = %p\n", &a);// & - 取地址操作符 - 取出a的地址

							int* pa = &a;//存放地址到变量pa，pa就是一个指针变量，a的类型是什么指针变量的类型就是什么
							*pa = 20;// * - 解引用操作符 - 间接访问操作符，通过pa找到a
							printf("a = %d\n", a);


						(类型)	强制类型转换
							int b = 3.14;// 从“double”转换到“int”，可能丢失数据
							int c = (int)3.14;// 将3.14强制转换成int类型

					------------------------------------------

					关系操作符
						>
						>=
						<
						<=
						!=
						==

					------------------------------------------

					逻辑操作符
						&&	逻辑与
						||	逻辑或

						// int c = a && b;
						// 如果a为0，b就不重要了，整个表达式就是假
						//
						// &&是遇假即停 而||是遇真即停

					------------------------------------------

					条件操作符 - 三目操作符
						exp1 ? exp2 : exp3

						int d = 3;
						int e = 0;

						if (d > 5)
						{
							e = 1;
						}
						else
						{
							b = -1;
						}

						// 三目操作符
						// d > 5 吗 真1 否则 -1 结果再赋值给e
						e = (d > 5 ? 1 : -1);
						//   -----   -   --
						//     ↑	 ↑	  ↑
						// 表达式1   ↑	  ↑
						//		  表达式2  ↑
						//				表达式是3

					------------------------------------------

					逗号表达式
						用逗号隔开的一串表达式

						exp1, exp2, exp3......, expN

						int a = 3;
						int b = 5;
						int c = 0;
						// 逗号表达式 - 从左向右依次计算，整个表达式结果是最后一个表达式的结果，不能只计算最后一个表达式
						int d = (c = 5, a = c + 3, b = a - 4, c += 5);

					------------------------------------------

					下标引用、函数调用和结构成员
						[] 下标引用
						() 函数调用操作符，接受一个或多个操作数：第一个操作数是函数名，剩余的操作数就是传递给函数的参数
						. 结构体.成员名
						->结构体指针->成员名

						int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
						printf("%d\n", arr[4]);
						// [] 的操作数是两个：arr和4



						// 创建了一个自定义的类型 - 书：书名，书号，定价
						struct 书
						{
							// 结构体的成员（成员变量）
							char 书名[20];
							char 书号[20];
							int 定价;
						};

						// 使用类型创建了一本书
						// 类型   b是一本书
						struct 书 b = {"C语言", "100", 50};
						//				书名		书号	  定价
						//
						// 结构体变量名.成员名
						printf("书名：%s\n", b.书名);
						printf("书号：%s\n", b.书号);
						printf("价格：%d\n", b.定价);

						printf("-----------------\n");

						// 指向整形的是整形指针，指向字符的叫字符指针，这个是结构体指针
						struct 书* pb = &b;

						// 结构体指针->成员名
						printf("书名：%s\n", pb->书名);
						printf("书号：%s\n", pb->书号);
						printf("价格：%d\n", pb->定价);


*/

#include "define.h"

int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	printf("%d\n", arr[4]);
	// [] 的操作数是两个：arr和4



	// 创建了一个自定义的类型 - 书：书名，书号，定价
	struct 书
	{
		// 结构体的成员（成员变量）
		char 书名[20];
		char 书号[20];
		int 定价;
	};

	// 使用类型创建了一本书
	// 类型   b是一本书
	struct 书 b = {"C语言", "100", 50};
	//				书名		书号	  定价
	// 
	// 结构体变量名.成员名
	printf("书名：%s\n", b.书名);
	printf("书号：%s\n", b.书号);
	printf("价格：%d\n", b.定价);

	printf("-----------------\n");

	// 指向整形的是整形指针，指向字符的叫字符指针，这个是结构体指针
	struct 书* pb = &b;

	// 结构体指针->成员名
	printf("书名：%s\n", pb->书名);
	printf("书号：%s\n", pb->书号);
	printf("价格：%d\n", pb->定价);










	// 表达式求值
	// 表达式求值的顺序一部分是由操作符的优先级和结合性决定。
	// 同样，有些表达式的操作数在求值的过程中可能需要转换为其他类型
	// 
	// 
	// 
	// 
	// 
	// 
	// 
	// 
	// 
	// 







	return 0;
}