
/*
	232. 用栈实现队列 https://leetcode.cn/problems/implement-queue-using-stacks/

	难度：简单

	请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：


	实现 MyQueue 类：
		void push(int x) 将元素 x 推到队列的末尾
		int pop() 从队列的开头移除并返回元素
		int peek() 返回队列开头的元素
		boolean empty() 如果队列为空，返回 true ；否则，返回 false


	说明：
		你 只能 使用标准的栈操作 —— 也就是只有 push to top, peek/pop from top, size, 和 is empty 操作是合法的。
		你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。


	示例 1：
		输入：
			["MyQueue", "push", "push", "peek", "pop", "empty"]
			[[], [1], [2], [], [], []]

		输出：
			[null, null, null, 1, 1, false]


	解释：
		MyQueue myQueue = new MyQueue();
		myQueue.push(1); // queue is: [1]
		myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
		myQueue.peek(); // return 1
		myQueue.pop(); // return 1, queue is [2]
		myQueue.empty(); // return false


	提示：
		1 <= x <= 9
		最多调用 100 次 push、pop、peek 和 empty
		假设所有操作都是有效的 （例如，一个空的队列不会调用 pop 或者 peek 操作）


	进阶：
		你能否实现每个操作均摊时间复杂度为 O(1) 的队列？换句话说，执行 n 个操作的总时间复杂度为 O(n) ，即使其中一个操作可能花费较长时间。
*/

/*===================================================*/

/*===================================================*/

/*
	思路：
		两个栈实现

		  ↑        ↑
		A ↓      B ↓
		| 4 |    |   | 栈顶
		| 3 |    |   |
		| 2 |    |   |
		| 1 |    |   | 栈底

		入数据，数据放入 A栈

			  ↑        ↑
			A ↓      B ↓
			| 4 |    |   | 栈顶
			| 3 |    |   |
			| 2 |    |   |
			| 1 |    |   | 栈底

		出数据，A栈 数据 移动到 B栈，B栈 出栈

			  ↑        ↑
			A ↓      B ↓
			|   |    | 1 | 栈顶
			|   |    | 2 |
			|   |    | 3 |
			|   |    | 4 | 栈底

		再次入数据，数据放入 A栈

			  ↑        ↑
			A ↓      B ↓
			|   |    |   | 栈顶
			|   |    |   |
			| 6 |    |   |
			| 5 |    |   | 栈底

		再次出数据，A栈 数据 移动到 B栈，B栈 出栈

			  ↑        ↑
			A ↓      B ↓
			|   |    |   | 栈顶
			|   |    |   |
			|   |    | 5 |
			|   |    | 6 | 栈底

		注意：
			B栈 数据出空后再将 A栈 数据移动进来
*/

/*===================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int STDataType;

typedef struct Stack
{
	STDataType* arr;
	int top;
	int capacity;
}Stack;

// 初始化栈
void StackInit(Stack* ps);

// 入栈
void StackPush(Stack* ps, STDataType data);

// 出栈
void StackPop(Stack* ps);

// 获取栈顶元素
STDataType StackTop(Stack* ps);

// 获取栈中有效元素个数
int StackSize(Stack* ps);

// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
bool StackEmpty(Stack* ps);

// 销毁栈
void StackDestroy(Stack* ps);





// 初始化栈
void StackInit(Stack* ps)
{
	assert(ps);

	ps->arr = NULL;
	ps->top = 0;
	ps->capacity = 0;

	/*
		初始化时
			top 给0 ，意味着 top 指向 栈顶数据 的下一个。		先放数据再++
			top 给-1，意味着 top 指向 栈顶数据。				先++再放数据
	*/
}

// 销毁栈
void StackDestroy(Stack* ps)
{
	assert(ps);

	free(ps->arr);
	ps->arr = NULL;
	ps->top = 0;
	ps->capacity = 0;
}

// 入栈
void StackPush(Stack* ps, STDataType data)
{
	assert(ps);

	// 判断 栈 是否满
	if (ps->top == ps->capacity)
	{
		// 增容
		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		STDataType* tmp = (STDataType*)realloc(ps->arr, sizeof(STDataType) * newCapacity);
		if (tmp == NULL)
		{
			exit(-1);
		}

		ps->arr = tmp;
		ps->capacity = newCapacity;
	}

	ps->arr[ps->top] = data;
	ps->top++;
}

// 出栈
void StackPop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));

	ps->top--;
}

// 获取栈顶元素
STDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));

	return ps->arr[ps->top - 1];
}

// 获取栈中有效元素个数
int StackSize(Stack* ps)
{
	assert(ps);

	return ps->top;
}

// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
bool StackEmpty(Stack* ps)
{
	assert(ps);

	return ps->top == 0;
}

/*===================================================*/

typedef struct {
	Stack pushST;
	Stack popST;
} MyQueue;


MyQueue* myQueueCreate()
{
	MyQueue* q = (MyQueue*)malloc(sizeof(MyQueue));
	if (q == NULL)
	{
		exit(0);
	}

	// 初始化栈
	StackInit(&q->pushST);
	StackInit(&q->popST);

	return q;
}

void myQueuePush(MyQueue* obj, int x)
{
	// 入栈
	StackPush(&obj->pushST, x);
}

int myQueuePop(MyQueue* obj)
{
	/*
		popST 有数据直接出
		popST 没数据要导入
	*/

	// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
	if (StackEmpty(&obj->popST))
	{
		// popST 没数据要导入

		// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
		while (!StackEmpty(&obj->pushST))
		{
			// 入栈                // 获取栈顶元素
			StackPush(&obj->popST, StackTop(&obj->pushST));

			// 出栈
			StackPop(&obj->pushST);
		}
	}

	            // 获取栈顶元素
	int front = StackTop(&obj->popST);

	// 出栈
	StackPop(&obj->popST);

	return front;
}

int myQueuePeek(MyQueue* obj)
{
	/*
		popST 有数据直接出
		popST 没数据要导入
	*/

	// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
	if (StackEmpty(&obj->popST))
	{
		// popST 没数据要导入

		// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
		while (!StackEmpty(&obj->pushST))
		{
			// 入栈                // 获取栈顶元素
			StackPush(&obj->popST, StackTop(&obj->pushST));

			// 出栈
			StackPop(&obj->pushST);
		}
	}

	       // 获取栈顶元素
	return StackTop(&obj->popST);
}

bool myQueueEmpty(MyQueue* obj)
{
	// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
	return StackEmpty(&obj->pushST) && StackEmpty(&obj->popST);
}

void myQueueFree(MyQueue* obj)
{
	/*
		obj
			pushST
				[ ][ ][ ][ ]

			popST
				[ ][ ][ ][ ]
	*/

	// 销毁栈
	StackDestroy(&obj->pushST);
	StackDestroy(&obj->popST);

	free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/

int main()
{
	MyQueue* q = myQueueCreate();
	myQueuePush(q, 1);
	myQueuePush(q, 2);
	myQueuePush(q, 3);
	myQueuePush(q, 4);

	myQueuePop(q);
	myQueuePop(q);

	myQueueFree(q);

	return 0;
}