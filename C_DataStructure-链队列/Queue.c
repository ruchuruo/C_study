
#include "Queue.h"

// 初始化队列
void QueueInit(Queue* q)
{
	assert(q);

	q->head = NULL;
	q->tail = NULL;
}

// 销毁队列
void QueueDestroy(Queue* q)
{
	assert(q);

	QueueNode* cur = q->head;

	while (cur != NULL)
	{
		QueueNode* curNext = cur->next;

		free(cur);

		cur = curNext;
	}

	q->head = NULL;
	q->tail = NULL;
}

// 队尾入队列
void QueuePush(Queue* q, QDataType data)
{
	assert(q);

	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newNode == NULL)
	{
		exit(0);
	}

	newNode->data = data;
	newNode->next = NULL;

	if (q->head == NULL)// 头尾同时为空 或 都不为空，所以只用判断一个
	{
		// 空队列

		q->head = newNode;
		q->tail = newNode;
	}
	else
	{
		// 不为空

		q->tail->next = newNode;
		q->tail = newNode;
	}
}

// 队头出队列
void QueuePop(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));

	QueueNode* headNext = q->head->next;

	free(q->head);

	q->head = headNext;

	if (q->head == NULL)
	{
		// 队列中节点被删除完后
		
		q->tail = NULL;
	}
}

// 获取队列头部元素
QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));

	return q->head->data;
}

// 获取队列队尾元素
QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));

	return q->tail->data;
}

// 获取队列中有效元素个数
int QueueSize(Queue* q)
{
	assert(q);

	QueueNode* cur = q->head;

	int n = 0;
	while (cur)
	{
		n++;

		cur = cur->next;
	}

	return n;
}

// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
bool QueueEmpty(Queue* q)
{
	assert(q);

	return q->head == NULL;
}