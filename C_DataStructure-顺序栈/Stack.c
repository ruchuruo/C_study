
#include "Stack.h"

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