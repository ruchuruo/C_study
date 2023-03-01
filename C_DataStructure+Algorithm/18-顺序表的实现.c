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
							size_t capicity;		// 容量空间的大小
						}SeqList;


						array       size    capicity
						↓             ↓     ↓
						[0][1][2][3][4][ ][ ] => 空间不够则增容


			2.2 接口实现：

				静态顺序表只适用于确定知道需要存多少数据的场景。
				静态顺序表的定长数组导致N定大了，空间开多了浪费，开少了不够用。
				所以现实中基本都是使用动态顺序表，根据需要动态的分配空间大小，
				所以下面我们实现动态顺序表。


			演示&讲解
				顺序表_静态();
				顺序表_动态();
				顺序表_接口实现();

		-------- -------- -------- -------- -------- -------- --------
		3. 链表
		-------- -------- -------- -------- -------- -------- --------
		4. 顺序表和链表的区别和联系
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
		int capicity;	// 容量空间的大小
	}SL;

	n2(2, "-------- ", 4);
}

/*================================================================================================================================================*/

typedef int SLDataType;

// 顺序表的动态存储
typedef struct SeqList
{
	SLDataType* arr;// 指向动态开辟的数组
	int size;		// 有效数据个数
	int capicity;	// 容量空间的大小
}SL;

// 基本增删查改接口
// 顺序表初始化
void SeqListInit(SL* psl)
{
	psl->arr = NULL;
	psl->size = 0;
	psl->capicity = 0;
}

// 顺序表销毁
void SeqListDestory(SL* psl)
{
	free(psl->arr);
	psl->arr = NULL;
	psl->size = 0;
	psl->capicity = 0;
}

// 顺序表打印
void SeqListPrint(SL* psl)
{
	int i = 0;
	for (i = 0; i < psl->size; i++)
	{
		printf("%d ", psl->arr[i]);
	}
	printf("\n");
}

// 检查空间，如果满了，进行增容
void SeqListCheckCapacity(SL* psl)
{
	// 判断空间是否充足
	if (psl->size == psl->capicity)
	{
		// 空间不足 扩容
		// 扩容2倍适中，但是0*2还是0
		// int 新capicity = psl->capicity == 0 ? 4 : psl->capicity * 2;
		// 
		// void* realloc (void* ptr, size_t size);
		// 库函数realloc，如果ptr是NULL，就和 库函数malloc 功能一样。
		if (psl->capicity == 0)
		{
			int 新capicity = 4;

			//SLDataType* tmp = (SLDataType*)realloc(psl->arr, 新capicity);
			// 参数 size_t size 是字节，所以要乘一个类型
			SLDataType* tmp = (SLDataType*)realloc(psl->arr, 新capicity * sizeof(SLDataType));
			if (tmp == NULL)
			{
				printf("无法扩容\n");
				exit(-1);
			}

			// 扩容成功
			psl->arr = tmp;
			psl->capicity = 新capicity;

		}
		else
		{
			int 新capicity = psl->capicity * 2;

			//SLDataType* tmp = (SLDataType*)realloc(psl->arr, 新capicity);
			// 参数 size_t size 是字节，所以要乘一个类型
			SLDataType* tmp = (SLDataType*)realloc(psl->arr, 新capicity * sizeof(SLDataType));
			if (tmp == NULL)
			{
				printf("无法扩容\n");
				exit(-1);
			}

			// 扩容成功
			psl->arr = tmp;
			psl->capicity = 新capicity;
		}
	}
}

// 顺序表尾插
void SeqListPushBack(SL* psl, SLDataType x)
{
	SeqListCheckCapacity(psl);

	// 插入数据
	psl->arr[psl->size] = x;
	psl->size++;
}

// 顺序表尾删
void SeqListPopBack(SL* psl)
{
	if (psl->size > 0)
	{
		// 减减后 就访问不到后面的数据
		psl->size--;
	}
}

// 顺序表头插
void SeqListPushFront(SL* psl, SLDataType x)
{
	/*
		把数据从后往前 逐个 向后移动一位
			[1][2][3][4][5]
			            end
			             →
			[1][2][3][4][ ][5]
			 →
			[ ][1][2][3][4][5]
	*/

	SeqListCheckCapacity(psl);

	// 移动前 最后一个数据的下标
	int end = psl->size - 1;

	// 移动数据
	while (end >= 0)
	{
		psl->arr[end + 1] = psl->arr[end];
		end--;
	}

	// 插入数据
	psl->arr[0] = x;
	psl->size++;
}

// 顺序表头删
void SeqListPopFront(SL* psl)
{
	/*
		把第二个数据开始 逐个 向前移动一位
		[1][2][3][4][5]
		   begin
		    ←
		[2][ ][3][4][5]
		             ←
		[2][3][4][5][ ]
	*/

	if (psl->size > 0)
	{
		// 移动前 第二个数据的下标
		int begin = 1;

		// 移动数据
		while (begin < psl->size)
		{
			psl->arr[begin - 1] = psl->arr[begin];
			begin++;
		}

		// 减减后 就访问不到后面的数据
		psl->size--;
	}
}

//// 顺序表查找
//int SeqListFind(SeqList* psl, SLDataType x);

//// 顺序表在pos位置插入x
//void SeqListInsert(SeqList* psl, size_t pos, SLDataType x);

//// 顺序表删除pos位置的值
//void SeqListErase(SeqList* psl, size_t pos);

void 顺序表_接口实现()
{
	printf("顺序表_接口实现\n");

	SL sl;

	// 顺序表初始化
	SeqListInit(&sl);

	// 顺序表尾插
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);

	// 顺序表打印
	SeqListPrint(&sl);

	// 顺序表尾删
	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	//SeqListPopBack(&sl);
	//SeqListPopBack(&sl);
	//SeqListPopBack(&sl);

	SeqListPrint(&sl);

	// 顺序表头插
	SeqListPushFront(&sl, 10);
	SeqListPushFront(&sl, 20);
	SeqListPushFront(&sl, 30);
	SeqListPushFront(&sl, 40);
	SeqListPushFront(&sl, 50);
	SeqListPushFront(&sl, 60);
	SeqListPushFront(&sl, 70);
	SeqListPushFront(&sl, 80);
	SeqListPushFront(&sl, 90);

	SeqListPrint(&sl);

	// 顺序表头删
	SeqListPopFront(&sl);
	SeqListPopFront(&sl);

	SeqListPrint(&sl);


	// 顺序表销毁
	SeqListDestory(&sl);

	n2(2, "-------- ", 4);
}

/*================================================================================================================================================*/

int main()
{
	顺序表_静态();
	顺序表_动态();
	顺序表_接口实现();

	return 0;
}

/*================================================================================================================================================*/
/**************************************************************************************************************************************************/