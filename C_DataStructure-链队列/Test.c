
/*
	单个值就定义单个值
	多个值就定义结构

	要改变什么 就传它的地址
*/

#include "Queue.h"


void test1()
{
	Queue q;

	// 初始化队列
	QueueInit(&q);

	// 队尾入队列
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);

	// 队头出队列
	QueuePop(&q);
	QueuePop(&q);

	// 获取队列头部元素
	printf("%d\n", QueueFront(&q));

	// 获取队列队尾元素
	printf("%d\n", QueueBack(&q));

	// 获取队列中有效元素个数
	printf("%d\n", QueueSize(&q));

	// 销毁队列
	QueueDestroy(&q);
}

void test2()
{
	Queue q;

	// 初始化队列
	QueueInit(&q);

	// 队尾入队列
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);

	// 出队列
	while (!QueueEmpty(&q))
	{
		QDataType front = QueueFront(&q);

		printf("%d ", front);

		QueuePop(&q);
	}
}

int main()
{
	//test1();

	test2();

	return 0;
}