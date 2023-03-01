
#include "SList.h"

// 动态申请一个节点
SLTNode* BuySListNode(SLTDateType x)
{
	// 创建新节点
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));

	// 检查
	if (newnode == NULL)
	{
		exit(-1);
	}

	// 新节点插入值
	newnode->data = x;
	newnode->next = NULL;

	return newnode;
}

// 单链表打印
void SListPrint(SLTNode* phead)
{
	/*
		phead → [d1][  ] → [d2][  ] → [d3][  ] → 

		        cur
		         ↓
		phead → [d1][  ] → [d2][  ] → [d3][  ] →
	*/

	SLTNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

// 单链表尾插
void SListPushBack(SLTNode** pphead, SLTDateType x)
{
	/*
		tail	尾
		newnode	新节点

		形参phead 的改变不会影响 实参plist

		plist 的值 拷贝给 phead
		因为plist是一个一级指针，phead也一个一级指针，实际意义上还是传值，所以phead应该为二级指针才是传地址
			
			int a;
			f(&a);

			void f(int* px)
			{
				*px = 0;
			}

			--------------------------------

			int* p;
			f(&p);

			void f(int** px)
			{
				*px = 0x00;
			}

	*/

	// 动态申请一个节点
	SLTNode* newnode = BuySListNode(x);

	// 没有节点就用新节点
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		// 找到尾节点
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}

		// 新节点 地址给 上一个节点
		tail->next = newnode;
	}
}

// 单链表的头插
void SListPushFront(SLTNode** pphead, SLTDateType x)
{
	// 动态申请一个节点
	SLTNode* newnode = BuySListNode(x);

	// 头插
	newnode->next = *pphead;
	*pphead = newnode;
}

// 单链表的尾删
void SListPopBack(SLTNode** pphead)
{
	// 无节点的情况
	if (*pphead == NULL)
	{
		return;
	}

	// 只有一个节点的情况
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		// 找到尾之前记录上一个节点地址
		SLTNode* prev = NULL;

		// 找到尾节点
		SLTNode* tail = *pphead;
		while (tail->next)// tail->next != NULL
		{
			// 记录后再继续找
			prev = tail;

			tail = tail->next;
		}

		// 尾删
		// 注意：tail 是局部变量，是 pphead 的拷贝，置空只是让 tail 指向空
		// 注意：上一个节点的 next 要置空，避免野指针
		free(tail);
		tail = NULL;

		prev->next = NULL;



		//// 当前 else 下的方法2
		//SLTNode* tail = *pphead;
		//while (tail->next->next)
		//{
		//	tail = tail->next;
		//}
		//free(tail->next);
		//tail->next = NULL;
	}
}

// 单链表头删
void SListPopFront(SLTNode** pphead)
{
	// 无节点的情况
	if (*pphead == NULL)
	{
		return;
	}

	// 保存下一个节点的地址
	SLTNode* next = (*pphead)->next;

	// 释放当前节点
	free(*pphead);

	// 指向下一个节点
	*pphead = next;
}

// 单链表查找
SLTNode* SListFind(SLTNode* phead, SLTDateType x)
{
	SLTNode* cur = phead;

	// 遍历链表
	while (cur)
	{
		// 找到返回
		if (cur->data == x)
		{
			return cur;
		}
		else// 没找到继续
		{
			cur = cur->next;
		}
	}

	// 没找到
	return NULL;
}

// 单链表在pos位置 之前 插入x
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDateType x)
{
	/*
						  pos
						   ↓
		[1][ ] → [2][ ] → [3][ ] → [4][ ] → 
						↑
						x

		找不到前一个节点
	*/

	// 动态申请一个节点
	SLTNode* newnode = BuySListNode(x);

	// 头插 需要单独处理
	if (*pphead == pos)
	{
		// 头插
		newnode->next = *pphead;
		*pphead = newnode;
	}
	else
	{
		// 找到pos的前一个位置
		SLTNode* posPrev = *pphead;
		while (posPrev->next != pos)
		{
			posPrev = posPrev->next;
		}

		// 插入x
		posPrev->next = newnode;
		newnode->next = pos;
	}
}

// 单链表在pos位置 之后 插入x
void SListInsertAfter(SLTNode* pos, SLTDateType x)
{
	/*
		pos
		 ↓
		[1][ ] → [2][ ] → [3][ ] → [4][ ] → 

		必须先让 newnode 指向下一个
	*/

	// 动态申请一个节点
	SLTNode* newnode = BuySListNode(x);

	newnode->next = pos->next;
	pos->next = newnode;
}

// 单链表删除pos位置的节点
void SListErase(SLTNode** pphead, SLTNode* pos)
{
	/*
		pos
		 ↓
		[1][ ] → [2][ ] → [3][ ] → [4][ ] →

		无头链表 删除pos位置 的 头删 和 尾删 逻辑不一样
	*/

	assert(pphead);
	assert(pos);

	// 判断头删
	if (*pphead == pos)
	{
		// 头删
		// 让 plist 指向下一个
		*pphead = pos->next;

		// 释放节点
		free(pos);
	}
	else
	{
		// 找到 pos 节点的前一个节点
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}

		// 
		prev->next = pos->next;

		// 
		free(pos);
	}
}

// 单链表删除pos位置 之后 的节点
void SListEraseAfter(SLTNode* pos)
{
	/*
		pos     next  next->next
		 ↓        ↓        ↓
		[1][ ] → [2][ ] → [3][ ] → [4][ ] →

	*/

	assert(pos);
	assert(pos->next);

	// 
	SLTNode* next = pos->next;
	pos->next = next->next;

	// 
	free(next);
}

// 单链表销毁
void SListDestroy(SLTNode** pphead)
{
	/*
		        cur
		         ↓
		plist → [1][ ] → [2][ ] → [3][ ] → [4][ ] →

	*/

	assert(pphead);

	SLTNode* cur = *pphead;

	while (cur)
	{
		SLTNode* next = cur->next;
		free(cur);
		cur = next;
	}

	*pphead = NULL;
}