
#include "my_List.h"

/*======== ======== ======== ========*/

EmpListNode::EmpListNode():next(NULL), prev(NULL), worker(NULL)
{
}

EmpListNode::~EmpListNode()
{
}

// 获取next节点
EmpListNode* EmpListNode::getNextNode()
{
	return next;
}

// 双向链表初始化
EmpListNode* EmpListNode::ListInit()
{
	// 哨兵位的头节点
	EmpListNode* phead = new(EmpListNode);

	phead->next = phead;
	phead->prev = phead;

	phead->h = 666;

	return phead;
}

// 双向链创建节点
EmpListNode* EmpListNode::BuyListNode(Worker* x)
{
	EmpListNode* newNode = new(EmpListNode);

	newNode->worker = x;
	newNode->next = NULL;
	newNode->prev = NULL;

	return newNode;
}

// 双向链表在pos的前面进行插入
void EmpListNode::ListInsert(EmpListNode* pos, Worker* x)
{
	assert(pos);

	// 记录前一个节点
	EmpListNode* posPrev = pos->prev;

	EmpListNode* newNode = BuyListNode(x);

	posPrev->next = newNode;
	newNode->prev = posPrev;
	newNode->next = pos;
	pos->prev = newNode;
}

// 双向链表打印
void EmpListNode::ListPrint(EmpListNode* phead)
{
	assert(phead);

	EmpListNode* cur = phead->next;

	while (cur != phead)
	{
		cur->worker->showInfo();
		cur = cur->next;
	}

	cout << endl;
}

/*======== ======== ======== ========*/