/*
	Lesson3--顺序表和链表

		本节目标
			1. 线性表
			2. 顺序表
			3. 链表
			4. 顺序表和链表的区别和联系

		======== ======== ======== ======== ======== ======== ========
		-------- -------- -------- -------- -------- -------- --------

		1. 线性表

			线性表（linear list）是n个具有相同特性的数据元素的有限序列。
			线性表是一种在实际中广泛使用的数据结构，常见的线性表：顺序表、链表、栈、队列、字符串...

			线性表在逻辑上是线性结构，也就说是连续的一条直线。但是在物理结构上并不一定是连续的，
			线性表在物理上存储时，通常以数组和链式结构的形式存储。

			顺序表
				[1][2][3][4][5][6][7]
					

			链表
				|data|   →|data|   →|data|   →|data|
				|----| ↗ |----| ↗ |----| ↗ |----|
				|next|→   |next|→   |next|→   |next|

				[data]
				[next] → [data]
						 [next] → [data]
								  [next] → [data]
										   [next]

		-------- -------- -------- -------- -------- -------- --------

		2. 顺序表

			2.1概念及结构

				顺序表是用一段物理地址连续的存储单元依次存储数据元素的线性结构，一般情况下采用数组存储。
				在数组上完成数据的增删查改。
				(顺序表就是数组，但是在数组的基础上，要求数据连续存储，不能跳跃间隔)

				顺序表一般可以分为：
					1. 静态顺序表：使用定长数组存储。

						// 顺序表的静态存储
						#define N 7
						typedef int SLDataType;

						typedef struct SeqList
						{
							SLDataType array[N];	// 定长数组
							size_t size;			// 有效数据的个数
						}SeqList;


						array       size    N
						↓             ↓     ↓
						[0][1][2][3][4][ ][ ]


					2. 动态顺序表：使用动态开辟的数组存储。

		-------- -------- -------- -------- -------- -------- --------
		3. 链表
		-------- -------- -------- -------- -------- -------- --------
		4. 顺序表和链表的区别和联系
		-------- -------- -------- -------- -------- -------- --------
		======== ======== ======== ======== ======== ======== ========
*/