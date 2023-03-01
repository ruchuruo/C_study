
#include "SList.h"

void test1()
{
	SLTNode* plist = NULL;

	// 单链表尾插
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);

	SListPrint(plist);

	// 单链表的头插
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);
	
	SListPrint(plist);

	// 单链表的尾删
	SListPopBack(&plist);

	SListPrint(plist);
}

void test2()
{
	SLTNode* plist = NULL;

	// 单链表的头插
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);

	SListPrint(plist);

	// 单链表的尾删
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);

	SListPrint(plist);
}

void test3()
{
	SLTNode* plist = NULL;

	// 单链表的头插
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);

	SListPrint(plist);

	// 单链表头删
	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPopFront(&plist);

	SListPrint(plist);
}

void test4()
{
	SLTNode* plist = NULL;

	// 单链表的头插
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);// 2
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 2);// 2
	SListPushFront(&plist, 4);
	SListPushFront(&plist, 2);// 2

	SListPrint(plist);

	// 单链表查找 找多个相同的
	SLTNode* pos = SListFind(plist, 2);
	int i = 1;
	while (pos)
	{
		printf("第%d个pos节点:%p->%d\n", i++, pos, pos->data);

		// 从pos的下一个位置找
		pos = SListFind(pos->next, 2);
	}

	// 单链表查找 修改
	pos = SListFind(plist, 3);
	if (pos)
	{
		pos->data = 333;
	}

	SListPrint(plist);
}

void test5()
{
	SLTNode* plist = NULL;

	// 单链表的头插
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);

	SListPrint(plist);

	// 先查找
	SLTNode* pos = SListFind(plist, 3);
	if (pos)
	{
		// 单链表在pos位置 之前 插入x
		SListInsert(&plist, pos, 666);
	}

	SListPrint(plist);

	// 再插入
	// 先查找
	pos = SListFind(plist, 4);
	if (pos)
	{
		// 单链表在pos位置 之前 插入x
		SListInsert(&plist, pos, 888);
	}

	SListPrint(plist);

	SListDestroy(&plist);
}

int main()
{
	//test1();

	//test2();

	//test3();

	//test4();

	test5();

	return 0;
}