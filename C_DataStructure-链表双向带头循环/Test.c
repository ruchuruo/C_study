
#include "List.h"

void test1()
{
	//ListNode* plist = NULL;

	// 双向链表初始化
	ListNode* plist = ListInit();

	// 双向链表尾插
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);

	// 双向链表打印
	ListPrint(plist);
	 
	// 双向链表尾删
	ListPopBack(plist);
	ListPopBack(plist);

	// 双向链表打印
	ListPrint(plist);
}

void test2()
{
	// 双向链表初始化
	ListNode* plist = ListInit();

	// 双向链表头插
	ListPushFront(plist, 1);
	ListPushFront(plist, 2);
	ListPushFront(plist, 3);
	ListPushFront(plist, 4);

	// 双向链表打印
	ListPrint(plist);

	// 双向链表头删
	ListPopFront(plist);
	ListPopFront(plist);
	ListPopFront(plist);

	// 双向链表打印
	ListPrint(plist);
}

void test3()
{
	// 双向链表初始化
	ListNode* plist = ListInit();

	// 双向链表头插
	ListPushFront(plist, 1);
	ListPushFront(plist, 2);
	ListPushFront(plist, 3);
	ListPushFront(plist, 4);

	// 双向链表打印
	ListPrint(plist);

	// 双向链表查找
	if (ListFind(plist, 2))
	{
		printf("找到\n");
	}
	else
	{
		printf("找不到\n");
	}

	// 双向链表删除pos位置的节点
	ListErase(ListFind(plist, 2));

	// 双向链表打印
	ListPrint(plist);
}

void test4()
{
	// 双向链表初始化
	ListNode* plist = ListInit();

	// 双向链表头插
	ListPushFront(plist, 1);
	ListPushFront(plist, 2);
	ListPushFront(plist, 3);
	ListPushFront(plist, 4);

	// 双向链表打印
	ListPrint(plist);

	// 双向链表销毁
	void ListDestroy(plist);

	// 保持接口一致性
	// 需要自己置空
	plist = NULL;
}

int main()
{
	//test1();

	//test2();

	//test3();

	test4();

	return 0;
}