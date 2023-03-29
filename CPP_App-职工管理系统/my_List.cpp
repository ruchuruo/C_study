
#include "my_List.h"

/*======== ======== ======== ========*/

EmpListNode::EmpListNode():next(NULL), prev(NULL), worker(NULL), sort(0)
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

// 获取worker数据
Worker* EmpListNode::getData()
{
	return worker;
}

// 双向链表初始化
EmpListNode* EmpListNode::ListInit()
{
	// 哨兵位的头节点
	EmpListNode* phead = new(EmpListNode);

	phead->next = phead;
	phead->prev = phead;

	phead->h = 666;
	phead->worker = NULL;

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

// 双向链表销毁
void EmpListNode::ListDestroy(EmpListNode* phead)
{
	assert(phead);

	EmpListNode* cur = phead->next;

	while (cur != phead)
	{
		EmpListNode* curNext = cur->next;
		
		delete cur->getData();
		delete cur;

		cur = curNext;
	}

	delete phead->getData();
	delete phead;
	phead = NULL;
}

// 双向链表清空(保留头)
void EmpListNode::ListClear(EmpListNode* phead)
{
	assert(phead);

	EmpListNode* cur = phead->next;

	while (cur != phead)
	{
		EmpListNode* curNext = cur->next;

		delete cur->getData();
		delete cur;

		cur = curNext;
	}

	//delete phead->getData();
	//delete phead;
	//phead = NULL;

	phead->next = phead;
	phead->prev = phead;
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

// 双向链表删除pos位置的节点
void EmpListNode::ListErase(EmpListNode* pos)
{
	assert(pos);

	EmpListNode* posPrev = pos->prev;
	EmpListNode* posNext = pos->next;

	posPrev->next = posNext;
	posNext->prev = posPrev;

	delete pos->getData();
	delete pos;
	pos = NULL;
}

// 双向链表查找 按职工编号查找
EmpListNode* EmpListNode::ListFind(EmpListNode* phead, int x)
{
	assert(phead);

	EmpListNode* cur = phead->next;

	while (cur != phead)
	{
		if (cur->worker->m_Id == x)
		{
			return cur;
		}

		cur = cur->next;
	}

	return NULL;
}

// 双向链表查找 按姓名查找
EmpListNode* EmpListNode::ListFind(EmpListNode* phead, string x)
{
	assert(phead);

	EmpListNode* cur = phead->next;

	while (cur != phead)
	{
		if (cur->worker->m_Name == x)
		{
			return cur;
		}

		cur = cur->next;
	}

	return NULL;
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

// 双向链表冒泡排序
void EmpListNode::ListBubbleSort(EmpListNode* phead, int empNum)
{
	EmpListNode* cur = phead->next;

	if (sort == 0)
	{
		// 0小→大
		
		// 开始排序
		// 排序总轮数 = 元素个数 - 1
		for (int i = 0; i < empNum - 1; i++)
		{
			// 每轮对比次数 = 元素个数 - 排序轮数 - 1
			for (int j = 0; j < empNum - 1 - i; j++)
			{
				if (cur != phead && cur->next != phead)
				{
					if (cur->worker->m_Id > cur->next->worker->m_Id)
					{
						Worker* tmpWorker = cur->worker;
						cur->worker = cur->next->worker;
						cur->next->worker = tmpWorker;
					}
				}
				else
				{
					// 跳过头后需要补次数
					j--;
					j--;
				}

				cur = cur->next;
			}
		}

		sort = 1;
	}
	else
	{
		// 1大→小

		// 开始排序
		// 排序总轮数 = 元素个数 - 1
		for (int i = 0; i < empNum - 1; i++)
		{
			// 每轮对比次数 = 元素个数 - 排序轮数 - 1
			for (int j = 0; j < empNum - 1 - i; j++)
			{
				if (cur != phead && cur->next != phead)
				{
					if (cur->worker->m_Id < cur->next->worker->m_Id)
					{
						Worker* tmpWorker = cur->worker;
						cur->worker = cur->next->worker;
						cur->next->worker = tmpWorker;
					}
				}
				else
				{
					// 跳过头后需要补次数
					j--;
					j--;
				}

				cur = cur->next;
			}
		}

		sort = 0;
	}
}

/*======== ======== ======== ========*/