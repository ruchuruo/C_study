
/*
	225. 用队列实现栈 https://leetcode.cn/problems/implement-stack-using-queues/
	
	难度：简单

	请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（push、top、pop 和 empty）。


	实现 MyStack 类：
		void push(int x) 将元素 x 压入栈顶。
		int pop() 移除并返回栈顶元素。
		int top() 返回栈顶元素。
		boolean empty() 如果栈是空的，返回 true ；否则，返回 false 。


	注意：
		你只能使用队列的基本操作 —— 也就是 push to back、peek/pop from front、size 和 is empty 这些操作。
		你所使用的语言也许不支持队列。 你可以使用 list （列表）或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。


	示例：
		输入：
			["MyStack", "push", "push", "top", "pop", "empty"]
			[[], [1], [2], [], [], []]

		输出：
			[null, null, null, 2, 2, false]

		解释：
			MyStack myStack = new MyStack();
			myStack.push(1);
			myStack.push(2);
			myStack.top(); // 返回 2
			myStack.pop(); // 返回 2
			myStack.empty(); // 返回 False


	提示：
		1 <= x <= 9
		最多调用100 次 push、pop、top 和 empty
		每次调用 pop 和 top 都保证栈不为空


	进阶：你能否仅用一个队列来实现栈。
*/

/*===================================================*/

/*
	链接 队列 无头
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int QDataType;

// 队列 节点
typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QueueNode;

// 队列 头尾指针
typedef struct Queue
{
	QueueNode* head;
	QueueNode* tail;
	//int size;
}Queue;


// 初始化队列
void QueueInit(Queue* q);

// 队尾入队列
void QueuePush(Queue* q, QDataType data);

// 队头出队列
void QueuePop(Queue* q);

// 获取队列头部元素
QDataType QueueFront(Queue* q);

// 获取队列队尾元素
QDataType QueueBack(Queue* q);

// 获取队列中有效元素个数
int QueueSize(Queue* q);

// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
bool QueueEmpty(Queue* q);

// 销毁队列
void QueueDestroy(Queue* q);






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

/*===================================================*/

/*
	思路：
		两个队列实现

		不能去改变队列的结构，比如翻转，只能去调用队列提供的接口函数

			  队头                         队尾
			  ↓                              ↓

			A ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		出队 ←                                ← 入队
			  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

			B ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		出队 ←                                ← 入队
			  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


		入数据

				A ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
			出队 ← 1 2 3 4                        ← 入队
				  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

				B ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
			出队 ←                                ← 入队
				  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		出数据 A队列 转移数据到 B队列，留一个

				A ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
			出队 ← 4                              ← 入队
				  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

				B ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
			出队 ← 1 2 3                          ← 入队
				  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		再将 A队列 最后一个数据 出队

				A ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
			出队 ←                                ← 入队
				  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

				B ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
			出队 ← 1 2 3                          ← 入队
				  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		当再次 入数据，往不为空的队列入

				A ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
			出队 ←                                ← 入队
				  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

				B ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
			出队 ← 1 2 3 5 6                      ← 入队
				  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		出数据 

				A ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
			出队 ← 1 2 3 5                        ← 入队
				  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

				B ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
			出队 ← 6                              ← 入队
				  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		核心思路
			1. 入数据，往不为空的队列入，保持另一个队列为空。
			2. 出数据，依次出队头的数据，转移到另一个队列保存，留最后一个数据，Pop掉最后一个数据。
*/

typedef struct
{
	Queue q1;
	Queue q2;
} MyStack;


MyStack* myStackCreate()
{
	/*
		这样写会出现野指针
		变量出作用域就销毁了

		MyStack st;
		return &st;
	*/

	// 不推荐使用全局变量
	MyStack* st = (MyStack*)malloc(sizeof(MyStack));
	if (st == NULL)
	{
		exit(0);
	}

	// 初始化队列
	QueueInit(&st->q1);
	QueueInit(&st->q2);

	return st;
}

void myStackPush(MyStack* obj, int x)
{
	// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
	if (!QueueEmpty(&obj->q1))
	{
		// q1 不为空就往里面入队
		// 队尾入队列
		QueuePush(&obj->q1, x);
	}
	else
	{
		// 队尾入队列
		QueuePush(&obj->q2, x);
	}
}

int myStackPop(MyStack* obj)
{
	// 假设 q1 为空，q2 不为空
	Queue* emptyQ = &obj->q1;
	Queue* nonemptyQ = &obj->q2;

	// 假设错了，就改正
	// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
	if (!QueueEmpty(&obj->q1))
	{
		// q1 不为空
		emptyQ = &obj->q2;
		nonemptyQ = &obj->q1;
	}

	// 转移数据，留一个数据
	while (QueueSize(nonemptyQ) > 1)
	{
		// 队尾入队列     // 获取队列头部元素
		QueuePush(emptyQ, QueueFront(nonemptyQ));

		// 队头出队列
		QueuePop(nonemptyQ);
	}

	// 获取队列头部元素
	int top = QueueFront(nonemptyQ);

	// 队头出队列
	QueuePop(nonemptyQ);

	return top;
}

int myStackTop(MyStack* obj)
{
	// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
	if (!QueueEmpty(&obj->q1))
	{
		// q1 不为空
		
		// 获取队列队尾元素
		return QueueBack(&obj->q1);
	}
	else
	{
		// 获取队列队尾元素
		return QueueBack(&obj->q2);
	}
}

bool myStackEmpty(MyStack* obj)
{
	// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
	return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}

void myStackFree(MyStack* obj)
{
	/*
		MyStack* obj
			q1
				head
				tail
			q2
				head
				tail
	*/
	
	QueueDestroy(&obj->q1);
	QueueDestroy(&obj->q2);
	free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);

 * int param_2 = myStackPop(obj);

 * int param_3 = myStackTop(obj);

 * bool param_4 = myStackEmpty(obj);

 * myStackFree(obj);
*/

int main()
{
	MyStack* st = myStackCreate();
	myStackPush(st, 1);
	myStackPush(st, 2);
	myStackPush(st, 3);
	myStackPush(st, 4);

	myStackPop(st);
	myStackPop(st);

	myStackFree(st);

	return 0;
}