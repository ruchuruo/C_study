
/*
	622. 设计循环队列 https://leetcode.cn/problems/design-circular-queue/

	难度：中等

	设计你的循环队列实现。 循环队列是一种线性数据结构，其操作表现基于 FIFO（先进先出）原则并且队尾被连接在队首之后以形成一个循环。它也被称为“环形缓冲器”。

	循环队列的一个好处是我们可以利用这个队列之前用过的空间。在一个普通队列里，一旦一个队列满了，我们就不能插入下一个元素，即使在队列前面仍有空间。但是使用循环队列，我们能使用这些空间去存储新的值。


	你的实现应该支持如下操作：
		MyCircularQueue(k): 构造器，设置队列长度为 k 。
		Front: 从队首获取元素。如果队列为空，返回 -1 。
		Rear: 获取队尾元素。如果队列为空，返回 -1 。
		enQueue(value): 向循环队列插入一个元素。如果成功插入则返回真。
		deQueue(): 从循环队列中删除一个元素。如果成功删除则返回真。
		isEmpty(): 检查循环队列是否为空。
		isFull(): 检查循环队列是否已满。


	示例：
		MyCircularQueue circularQueue = new MyCircularQueue(3); // 设置长度为 3
		circularQueue.enQueue(1);  // 返回 true
		circularQueue.enQueue(2);  // 返回 true
		circularQueue.enQueue(3);  // 返回 true
		circularQueue.enQueue(4);  // 返回 false，队列已满
		circularQueue.Rear();  // 返回 3
		circularQueue.isFull();  // 返回 true
		circularQueue.deQueue();  // 返回 true
		circularQueue.enQueue(4);  // 返回 true
		circularQueue.Rear();  // 返回 4


	提示：
		所有的值都在 0 至 1000 的范围内；
		操作数将在 1 至 1000 的范围内；
		请不要使用内置的队列库。
*/
/*
	思路：数组实现
		循环队列

			另外扩展了解一下，实际中我们有时还会使用一种队列叫循环队列。
			如操作系统课程讲解生产者消费者模型时可以就会使用循环队列。
			环形队列可以使用数组实现，也可以使用循环链表实现。

						→
					[ ][ ][ ]
				 [ ]         [ ] ← 队列尾
				↑[ ]         [ ]↓
				 [ ]         [ ] ← 队列头
					[ ][ ][ ]
						←

			空的循环队列
						→
					[ ][ ][ ]
				 [ ]         [ ] ← 队列尾 ← 队列头
				↑[ ]         [ ]↓
				 [ ]         [ ]
					[ ][ ][ ]
						←

			满的循环队列
						→
					[i][j][k]
				 [h]         [ ] ← 队列尾
				↑[g]         [a] ← 队列头
				 [f]         [b]
					[e][d][c]
						←

			为了能使用 队列.头 = 队列.尾 来区别是空还是满，
			我们常常认为出现 上图 时的情况即为队满，
			此时 尾+1 = 头

			重点
				循环队列，无论使用数组实现还是链表实现，都要多开一个空间，
				要存k个数据的循环队列，要开k+1个空间，否则无法实现判空和判满。

				数组 循环队列 满：(尾+1)%(k+1) == 头
				链表 循环队列 满：尾->next == 头
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef struct
{
	int* arr;	// 
	int front;	// 头
	int tail;	// 尾
	int k;		// 循环队列大小
} MyCircularQueue;

MyCircularQueue* myCircularQueueCreate(int k);
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value);
bool myCircularQueueDeQueue(MyCircularQueue* obj);
int myCircularQueueFront(MyCircularQueue* obj);
int myCircularQueueRear(MyCircularQueue* obj);
bool myCircularQueueIsEmpty(MyCircularQueue* obj);
bool myCircularQueueIsFull(MyCircularQueue* obj);
void myCircularQueueFree(MyCircularQueue* obj);

MyCircularQueue* myCircularQueueCreate(int k)
{
	MyCircularQueue* cq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	if (cq == NULL)
	{
		exit(0);
	}

	cq->arr = (int*)malloc(sizeof(int) * (k + 1));
	cq->front = 0;
	cq->tail = 0;
	cq->k = k;

	return cq;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value)
{
	if (myCircularQueueIsFull(obj))
	{
		// 循环队列满
		return false;
	}

	obj->arr[obj->tail] = value;
	obj->tail++;

	// 如果到数组尾，就 %= 回数组头
	obj->tail %= (obj->k + 1);

	return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
	{
		// 循环队列空
		return false;
	}

	obj->front++;

	// 如果到数组尾，就 %= 回数组头
	obj->front %= (obj->k + 1);

	return true;
}

int myCircularQueueFront(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
	{
		// 循环队列空
		return -1;
	}

	return obj->arr[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
	{
		// 循环队列空
		return -1;
	}

	/*
		获取队尾元素时 会出现以下情况

			tail  front
			 ↓      ↓
			[ ]    [1]    [2]    [3]    [4]

			tail 如何找前一个？

			// 方法2
			int i = (obj->tail + obj->k) % (obj->k + 1);
			return obj->arr[i];
	*/

	// 方法1
	if (obj->tail == 0)
	{
		return obj->arr[obj->k];
	}
	else
	{
		return obj->arr[obj->tail - 1];
	}
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj)
{
	return obj->front == obj->tail;
}

bool myCircularQueueIsFull(MyCircularQueue* obj)
{
	return (obj->tail + 1) % (obj->k + 1) == obj->front;
}

void myCircularQueueFree(MyCircularQueue* obj)
{
	free(obj->arr);
	free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);

 * bool param_2 = myCircularQueueDeQueue(obj);

 * int param_3 = myCircularQueueFront(obj);

 * int param_4 = myCircularQueueRear(obj);

 * bool param_5 = myCircularQueueIsEmpty(obj);

 * bool param_6 = myCircularQueueIsFull(obj);

 * myCircularQueueFree(obj);
*/

int main()
{

	return 0;
}