/*
	Lesson2--算法的 时间复杂度 和 空间复杂度

		本节目标
			1. 算法效率
			2. 时间复杂度
			3. 空间复杂度
			4. 常见时间复杂度以及复杂度oj练习

		======== ======== ======== ======== ======== ======== ========
		-------- -------- -------- -------- -------- -------- --------

			1.算法效率

				算法效率分析分为两种：第一种是时间效率，第二种是空间效率。时间效率被称为时间复杂度，而空间效率
				被称作空间复杂度。 时间复杂度主要衡量的是一个算法的运行速度，而空间复杂度主要衡量一个算法所需要
				的额外空间，在计算机发展的早期，计算机的存储容量很小。所以对空间复杂度很是在乎。但是经过计算机
				行业的迅速发展，计算机的存储容量已经达到了很高的程度。所以我们如今已经不需要再特别关注一个算法
				的空间复杂度。

				1.1 如何衡量一个算法的好坏？

					比如以下斐波那契数列：

						long long Fib(int N)
						{
							if (N < 3)
							{
								return 1;
							}
							return Fib(N - 1) + Fib(N - 2);
						}

					斐波那契数列的递归实现方式非常简洁，但简洁一定好吗？那该如何衡量其好与坏呢？


				1.2 算法的复杂度

					算法在编写成可执行程序后，运行时需要消耗时间资源和空间(内存)资源，因此衡量一个算法的好坏，
					一般是从时间和空间两个维度来衡量的，即 时间复杂度 和 空间复杂度。

					时间复杂度主要衡量一个算法的运行快慢，而空间复杂度主要衡量一个算法运行所需要的额外空间。
					在计算机发展的早期，计算机的存储容量很小。所以对空间复杂度是很在乎。但是经过计算机行业的迅速发展。
					计算机的存储容量已经达到了很高的程度。所以我们如今已经不需要再特别关注一个算法的空间复杂度。

					摩尔定律
						归纳起来，“摩尔定律”主要有以下3种“版本”：
							1、集成电路芯片上所集成的电路的数目，每隔18个月就翻一番。
							2、微处理器的性能每隔18个月提高一倍，而价格下降一半。
							3、用一美元所能买到的计算机性能，每隔18个月翻两番。


				1.3 复杂度在校招中的考察

		-------- -------- -------- -------- -------- -------- --------

		2. 时间复杂度

			2.1 时间复杂度的概念

				时间复杂度的定义：在计算机科学中，算法的时间复杂度是一个函数(数学里面带有未知数的函数表达式)，它定量描述了该算法的运行时间。
				一个算法执行所耗费的时间，从理论上说，是不能算出来的，只有你把你的程序放在机器上跑起来，才能知道。
				但是我们需要每个算法都上机测试吗？是可以都上机测试，但是这很麻烦，所以才有了时间复杂度这个分析方式。
				一个算法所花费的时间与其中语句的执行次数成正比例，算法中的基本操作的执行次数，为算法的时间复杂度。

				即：找到某条基本语句与问题规模N之间的数学表达式，就是算出了该算法的时间复杂度。

				实际中我们计算时间复杂度时，我们其实并不一定要计算精确的执行次数，而只需要大概执行次数，
				那么这里我们使用大O的渐进表示法。

				大O的渐进表示法(估算)
					O()


			2.2 大O的渐进表示法

				大O符号（Big O notation）：是用于描述函数渐进行为的数学符号。

				推导大O阶方法：
					1、用常数1取代运行时间中的所有加法常数。
					2、在修改后的运行次数函数中，只保留最高阶项。
					3、如果最高阶项存在且不是1，则去除与这个项目相乘的常数。得到的结果就是大O阶。


				使用大O的渐进表示法以后，Func1的时间复杂度为：
					O(N^2)
					N = 10 F(N) = 100
					N = 100 F(N) = 10000
					N = 1000 F(N) = 1000000

				通过上面我们会发现大O的渐进表示法去掉了那些对结果影响不大的项，简洁明了的表示出了执行次数。
				另外有些算法的时间复杂度存在最好、平均和最坏情况：
					最坏情况：任意输入规模的最大运行次数(上界)
					平均情况：任意输入规模的期望运行次数
					最好情况：任意输入规模的最小运行次数(下界)

				例如：在一个长度为N数组中搜索一个数据x
					最好情况：1次找到
					最坏情况：N次找到
					平均情况：N/2次找到

				在实际中一般情况关注的是算法的最坏运行情况，所以数组中搜索数据时间复杂度为O(N)


			2.3常见时间复杂度计算举例

				实例1：计算Func2的时间复杂度？-双重循环时间复杂度的计算
				实例2：计算Func3的时间复杂度？-双重循环时间复杂度的计算
				实例3：计算Func4的时间复杂度？-常数循环的时间复杂度
				实例4：计算strchr的时间复杂度？
				实例5：
				实例6：
				实例7：
				实例8：


			演示&讲解
				时间复杂度_时间复杂度的概念();

		-------- -------- -------- -------- -------- -------- --------
		3. 空间复杂度
		-------- -------- -------- -------- -------- -------- --------
		4. 常见时间复杂度以及复杂度oj练习
		-------- -------- -------- -------- -------- -------- --------
		======== ======== ======== ======== ======== ======== ========

*/

#include "My_function.h"

/**************************************************************************************************************************************************/
/*================================================================================================================================================*/

// -嵌套循环时间复杂度的计算
// 计算Func1中++count语句总共执行了多少次？
void Func1(int N)
{
	int count = 0;

	int i = 0;
	int j = 0;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			++count;
		}
	}

	for (int k = 0; k < 2 * N; k++)
	{
		++count;
	}

	int M = 10;
	while (N--)
	{
		++count;
	}

	printf("%d\n", count);

	// 计算Func1中++count语句总共执行了多少次？
	// 
	// 未知数
	//   ↓
	// F(N) = N * N + 2 * N + 10
	// 时间复杂度的函数式

	/*
		F(N) = N * N + 2 * N + 10

		Func1 执行的基本操作次数 ：
			N = 10 F(N) = 130
			N = 100 F(N) = 10210
			N = 1000 F(N) = 1002010


		只关注影响最大的项
		F(N) = N ^ 2
		N = 100 F(N) = 10000
		N = 1000 F(N) = 1000000

		F(N) = N * N + 2 * N + 10
					   __________
		N越大，后两项对结果的影响是越小的


		保留N * N这一项，因为这一项影响结果最大
		时间复杂度：O(N ^ 2)
	*/
}

// 实例1：
// 计算Func2的时间复杂度？
void Func2(int N)
{
	int count = 0;
	for (int k = 0; k < 2 * N; ++k)
	{
		++count;
	}
	int M = 10;
	while (M--)
	{
		++count;
	}
	printf("%d\n", count);

	/*
		F(N) = 2 * N + 10

		3、如果最高阶项存在且不是1，则去除与这个项目相乘的常数(系数)。得到的结果就是大O阶。

		O(N)
	*/
}

// 实例2：
// 计算Func3的时间复杂度？
void Func3(int N, int M)
{
	int count = 0;
	for (int k = 0; k < M; ++k)
	{
		++count;
	}
	for (int k = 0; k < N; ++k)
	{
		++count;
	}
	printf("%d\n", count);

	/*
		无 说明M和N的大小关系
			O(M+N)

		有 说明M和N的大小关系
			M远大于N -> O(M)
			N远大于M -> O(N)
			M和N差不多大 -> O(M) 或是 O(N)

		一般情况下 时间复杂度计算时未知数都是用 N，
		但是也是可以是 M，K 等等其他的。
	*/
}

// 实例3：
// 计算Func4的时间复杂度？
void Func4(int N)
{
	int count = 0;
	for (int k = 0; k < 100; ++k)
	{
		++count;
	}
	printf("%d\n", count);

	/*
		1、用常数1取代运行时间中的所有加法常数。

		O(1)

		O(1)不是代表算法运行一次，是常数次
	*/
}

void 函数1()
{
	// 实例4:
	// 计算strchr的时间复杂度？
	const char* strchr(const char* str, int character);
	/*
		const char * strchr ( const char * str, int character );
		char * strchr (       char * str, int character );
		在字符串中查找首次出现的字符

		相当于
			while (*str)
			{
				if (*str == character)
				{
					return str;
				}
				else
				{
					++str;
				}
			}

	*/
}


void 时间复杂度_时间复杂度的概念()
{
	printf("文字\n");

	Func1(1);
	Func2(1);
	Func3(1, 1);
	Func4(1);
	函数1();

	n2(2, "-------- ", 4);
}

/*================================================================================================================================================*/

int main()
{
	时间复杂度_时间复杂度的概念();

	return 0;
}

/*================================================================================================================================================*/
/**************************************************************************************************************************************************/