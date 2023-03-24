
#include "my_List.h"

// 双向链表初始化
ListNode* ListInit()
{
	// 哨兵位的头节点
	ListNode* phead = (ListNode*)malloc(sizeof(ListNode));

	// 循环链表，next 指向自己
	phead->next = phead;
	phead->prev = phead;

	return phead;
}

// 双向链创建节点
ListNode* BuyListNode(LTDataType x)
{
	// 创建节点
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));

	newNode->data = x;

	// 好习惯
	newNode->next = NULL;
	newNode->prev = NULL;

	return newNode;
}

// 双向链表尾插
void ListPushBack(ListNode* phead, LTDataType x)
{
	assert(phead);

	// 找尾
	ListNode* tail = phead->prev;

	// 创建节点
	ListNode* newNode = BuyListNode(x);

	// 链接
	tail->next = newNode;
	newNode->prev = tail;
	newNode->next = phead;
	phead->prev = newNode;

	/*
		复用

			assert(phead);

			// 双向链表在pos的前面进行插入
			ListInsert(phead, x);
	*/
}

// 双向链表尾删
void ListPopBack(ListNode* phead)
{
	assert(phead);

	// 防止删除 哨兵位
	assert(phead->next != phead);

	// 找尾
	ListNode* tail = phead->prev;

	// 记录 tail 的 prev
	ListNode* tailPrev = tail->prev;

	free(tail);

	tailPrev->next = phead;
	phead->prev = tailPrev;

	/*
		另一种写法：不记录 tail 的 prev

			assert(phead);

			// 防止删除 哨兵位
			assert(phead->next != phead);

			// 找尾
			ListNode* tail = phead->prev;

			phead->prev = tail->prev;
			tail->prev->next = phead;

			free(tail);
	*/

	/*
		复用

			assert(phead);

			// 防止删除 哨兵位
			assert(phead->next != phead);

			ListErase(phead->prev);
	*/
}

// 双向链表头插
void ListPushFront(ListNode* phead, LTDataType x)
{
	assert(phead);

	// 创建节点
	ListNode* newNode = BuyListNode(x);

	// 建议多定义一个指针
	ListNode* pheadNext = phead->next;

	phead->next = newNode;
	newNode->prev = phead;

	newNode->next = pheadNext;
	pheadNext->prev = newNode;

	/*
		复用

			assert(phead);

			// 双向链表在pos的前面进行插入
			ListInsert(phead->next, x);
	*/
}

// 双向链表头删
void ListPopFront(ListNode* phead)
{
	assert(phead);

	// 防止删除 哨兵位
	assert(phead->next != phead);

	// 建议多定义一个指针
	ListNode* pheadNext = phead->next;
	ListNode* pheadNextNext = phead->next->next;

	phead->next = pheadNextNext;
	pheadNextNext->prev = phead;

	free(pheadNext);

	/*
		复用

			assert(phead);

			// 防止删除 哨兵位
			assert(phead->next != phead);

			ListErase(phead->next);
	*/
}

// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);

	// 记录前一个节点
	ListNode* posPrev = pos->prev;

	ListNode* newNode = BuyListNode(x);

	posPrev->next = newNode;
	newNode->prev = posPrev;
	newNode->next = pos;
	pos->prev = newNode;
}

// 双向链表删除pos位置的节点
void ListErase(ListNode* pos)
{
	assert(pos);

	ListNode* posPrev = pos->prev;
	ListNode* posNext = pos->next;

	posPrev->next = posNext;
	posNext->prev = posPrev;

	free(pos);
	pos = NULL;
}

// 双向链表查找
ListNode* ListFind(ListNode* phead, LTDataType x)
{
	assert(phead);

	// cur 从 phead->next 开始遍历
	// cur 等于 phead 时停止

	ListNode* cur = phead->next;

	while (cur != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}

		cur = cur->next;
	}

	return NULL;
}

// 双向链表打印
void ListPrint(ListNode* phead)
{
	assert(phead);

	// cur 从 phead->next 开始遍历
	// cur 等于 phead 时停止

	ListNode* cur = phead->next;

	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}

	printf("\n");
}

// 双向链表销毁
void ListDestroy(ListNode* phead)
{
	assert(phead);

	ListNode* cur = phead->next;

	while (cur != phead)
	{
		ListNode* curNext = cur->next;
		free(cur);
		cur = curNext;
	}

	free(phead);
	phead = NULL;
}