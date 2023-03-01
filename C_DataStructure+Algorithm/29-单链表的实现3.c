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
				(顺序表就是数组，但是在数组的基础上，要求数据 从头开始 连续存储，不能跳跃间隔)

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

						// 顺序表的动态存储
						typedef struct SeqList
						{
							SLDataType* array;		// 指向动态开辟的数组
							size_t size;			// 有效数据个数
							size_t capacity;		// 容量空间的大小
						}SeqList;


						array       size    capacity
						↓             ↓     ↓
						[0][1][2][3][4][ ][ ] => 空间不够则增容


			2.2 接口实现：

				静态顺序表只适用于确定知道需要存多少数据的场景。
				静态顺序表的定长数组导致N定大了，空间开多了浪费，开少了不够用。
				所以现实中基本都是使用动态顺序表，根据需要动态的分配空间大小，
				所以下面我们实现动态顺序表。


			2.3 数组相关面试题

				1. 原地移除数组中所有的元素val，要求时间复杂度为O(N)，空间复杂度为O(1)。https://leetcode.cn/problems/remove-element/
				2. 删除排序数组中的重复项。https://leetcode.cn/problems/remove-duplicates-from-sorted-array/
				3. 合并两个有序数组。https://leetcode.cn/problems/merge-sorted-array/


			顺序表缺陷
				
				1. 空间不够需要增容。
				2. 避免频繁增容，一般扩容2倍，导致空间浪费。
				3. 要求数据从头开始连续存储，插入和删除数据，需要移动数据，效率低。

			顺序表只需要知道 第一个空间的起始地址 就能访问所有元素
				a[i] 等价于 *(a + i)


			演示&讲解
				顺序表_静态();
				顺序表_动态();
				顺序表_接口实现();
				顺序表_接口实现_使用();
				顺序表_数组相关面试题();

		-------- -------- -------- -------- -------- -------- --------

		3. 链表

			3.1 链表的概念及结构

				概念：链表是一种物理存储结构上非连续、非顺序的存储结构，数据元素的逻辑顺序是通过链表中的指针链接次序实现的 。

							数据 指针
							 ↓	  ↓
				[a1][   ] → [a2][   ] ------→ [an][NULL]
				  |									|
				   ---------------------------------
								  表

				存一个数据给一个空间，用一个指针指向第一个空间(节点)。
				有一个指针可以找到 第一个空间，第一个空间 存第二个空间的地址。
				最后一个空间存一个NULL地址。

				链表 针对 顺序表 的缺陷设计出来的

				实际中链表的结构非常多样，以下情况组合起来就有8种链表结构：
					1. 单向、双向
					2. 带头、不带头
					3. 循环、非循环

					1. 单向
						
						[d1][ ] → [d2][ ] → [d3][ ] →

					2. 双向
						
						← [ ][d1][ ] →← [ ][d2][ ] →← [ ][d3][ ] →

					3. 带头单链表
						
						[head][ ] → [d1][ ] → [d2][ ] → [d3][ ] →

					4. 不带头单链表

						[d1][ ] → [d2][ ] → [d3][ ] →

					5. 循环单链表

						→ [d1][ ] → [d2][ ] → [d3][ ]
					   |                           ↓
						---------------------------

				虽然有这么多的链表的结构，但是我们实际中最常用还是两种结构：

					不带头 单向 非循环 链表

						[d1][ ] → [d2][ ] → [d3][ ] →

					带头 双向 循环 链表

						  ----------------------------------------------
						 ↑                                              ↓
						[head][ ] →← [ ][d1][ ] →← [ ][d2][ ] →← [ ][d3][ ]
						    ↑                                             ↓
						     ---------------------------------------------

					1. 无头单向非循环链表：结构简单，一般不会单独用来存数据。
					   实际中更多是作为其他数据结构的子结构，如哈希桶、图的邻接表等等。另外这种结构在笔试面试中出现很多。

					2. 带头双向循环链表：结构最复杂，一般用在单独存储数据。
					   实际中使用的链表数据结构，都是带头双向循环链表。另外这个结构虽然结构复杂，
					   但是使用代码实现以后会发现结构会带来很多优势，实现反而简单了，后面我们代码实现了就知道了。


			3.2链表的实现


			3.3 链表面试题

				1. 删除链表中等于给定值 val 的所有节点。 https://leetcode.cn/problems/remove-linked-list-elements/description/

				2. 反转一个单链表。 https://leetcode.cn/problems/reverse-linked-list/description/
				
				3. 给定一个带有头结点 head 的非空单链表，返回链表的中间结点。
				   如果有两个中间结点，则返回第二个中间结点。 https://leetcode.cn/problems/middle-of-the-linked-list/description/
				
				4. 输入一个链表，输出该链表中倒数第k个结点。 OJ链接
				
				5. 将两个有序链表合并为一个新的有序链表并返回。
				   新链表是通过拼接给定的两个链表的所有节点组成的。 https://leetcode.cn/problems/merge-two-sorted-lists/description/
				
				6. 编写代码，以给定值x为基准将链表分割成两部分，
				   所有小于x的结点排在大于或等于x的结点之前 。OJ链接
				
				7. 链表的回文结构。OJ链接
				
				8. 输入两个链表，找出它们的第一个公共结点。OJ链接
				
				9. 给定一个链表，判断链表中是否有环。 OJ链接
				
				10. 给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 NULL OJ链接
				
				11. 给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。
				    要求返回这个链表的深度拷贝。OJ链接
				
				12. 对链表进行插入排序。OJ链表
				
				13. 在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，
				    重复的结点不保留，返回链表头指针。 OJ链接
				
				14. 其他 。ps：链表的题当前因为难度及知识面等等原因还不适合我们当前学习，
				    以后大家自己下去以后 Leetcode OJ链接 + 牛客 OJ链接


			单链表的缺陷还是很多，单纯单链表增删查改的意义不大。
			单链表更多的是去做更复杂的数据结构的子结构，如 哈希桶，邻接表。


			演示&讲解
				链表_单向不带头非循环();
				链表_链表面试题();

		-------- -------- -------- -------- -------- -------- --------
		4. 顺序表和链表的区别和联系
		-------- -------- -------- -------- -------- -------- --------
		======== ======== ======== ======== ======== ======== ========
*/
/*
		======== ======== ======== ======== ======== ======== ========
		-------- -------- -------- -------- -------- -------- --------

		OJ分类和原理
			Online Judge

			1. IO型
				需要直接写头文件，函数......
				测试用例：要用 scanf 获取
				结果：printf输出

			2. 接口型
				只给了函数，需要实现函数
				测试用例：通过参数传过来
				结果：一般通过返回值拿，或是输出型参数

				int* singleNumbers(int* nums, int numsSize, int* returnSize);
																 输出型参数

		-------- -------- -------- -------- -------- -------- --------
		======== ======== ======== ======== ======== ======== ========
*/

#include "My_function.h"
#include <stdlib.h>

/**************************************************************************************************************************************************/
/*================================================================================================================================================*/

void 顺序表_静态()
{
	printf("顺序表_静态\n");

	/*--------------------------------*/

	// 顺序表的静态存储
#define N 100
	struct SeqList
	{
		int a[N];// 定长数组
		int size;// 有效数据的个数(表示数组中存储了多少个数据)
	};

	/*--------------------------------*/

	// 完善 ，SL 是 SeqList 的缩写
	// 这样顺序表想存什么类型就从这里改 typedef double SLDataType;
	typedef int SLDataType;
	struct SeqList2
	{
		SLDataType a[N];// 定长数组
		int size;// 有效数据的个数(表示数组中存储了多少个数据)
	};

	// 接口函数
	//void 顺序表末尾插入数据(struct SeqList2* ps, int x);
	// ......

	/*--------------------------------*/

	// 修改
	typedef struct SeqList3
	{
		SLDataType a[N];// 定长数组
		int size;// 有效数据的个数(表示数组中存储了多少个数据)
	}SL3;

	// 接口函数
	//void 顺序表末尾插入数据(SL3* ps, int x);
	// ......

	/*--------------------------------*/

	/*
		接口函数 命名风格跟着STL走的
		SeqListPushBack
	*/

#undef N

	n2(2, "-------- ", 4);
}

/*================================================================================================================================================*/

void 顺序表_动态()
{
	printf("顺序表_动态\n");

	// 顺序表的动态存储
	typedef int SLDataType;
	typedef struct SeqList
	{
		SLDataType* arr;// 指向动态开辟的数组
		int size;		// 有效数据个数(表示数组中存储了多少个数据)
		int capacity;	// 容量空间的大小
	}SL;

	n2(2, "-------- ", 4);
}

/*================================================================================================================================================*/

void 顺序表_接口实现()
{
	printf("顺序表_接口实现\n");

	// 顺序表初始化

	// 顺序表尾插

	// 顺序表打印

	// 顺序表尾删

	// 顺序表头插

	// 顺序表头删

	// 顺序表查找

	// 顺序表在pos位置插入x

	// 顺序表删除pos位置的值

	// 顺序表销毁

	/*
		头尾 删除 插入 可以复用 SeqListInsert() 和 SeqListErase()
	*/

	n2(2, "-------- ", 4);
}

void 顺序表_接口实现_菜单()
{
	printf("******** ******** ******** ******** ********\n");
	printf("******** 1.头插              2.头删 ********\n");
	printf("******** 3.尾插              4.尾删 ********\n");
	printf("******** 5.查找              6.打印 ********\n");
	printf("******** 7.pos位置插入 8.pos位置删除 ********\n");
	printf("********           0.退出           ********\n");
	printf("******** ******** ******** ******** ********\n");
}

void 顺序表_接口实现_使用()
{
	
}

/*================================================================================================================================================*/

void 顺序表_数组相关面试题()
{
	n2(2, "-------- ", 4);
	printf("顺序表_数组相关面试题\n");

	// LeetCode_27-移除元素

	// LeetCode_26-删除有序数组中的重复项

	// LeetCode_88-合并两个有序数组
	

	n2(2, "-------- ", 4);
}

/*================================================================================================================================================*/

void 链表_单向不带头非循环()
{
	printf("链表_单向不带头非循环\n");

	n2(2, "-------- ", 4);
}

/*================================================================================================================================================*/

void 链表_链表面试题()
{
	printf("链表_链表面试题\n");

	// LeetCode_203-移除链表元素

	n2(2, "-------- ", 4);

}

/*================================================================================================================================================*/

int main()
{
	顺序表_静态();
	顺序表_动态();
	顺序表_接口实现();		// 被 顺序表_接口实现_使用(); 替代
	顺序表_接口实现_使用();	// 项目 C_DataStructure-顺序表
	顺序表_数组相关面试题();	// 项目 C_OnlineJudge

	链表_单向不带头非循环();	// 项目 C_DataStructure-链表单向无头非循环
	链表_链表面试题();		// 项目 C_OnlineJudge

	return 0;
}

/*================================================================================================================================================*/
/**************************************************************************************************************************************************/