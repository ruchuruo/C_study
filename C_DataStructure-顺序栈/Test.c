
#include "Stack.h"

void test1()
{
	Stack st;

	// 初始化栈
	StackInit(&st);

	// 入栈
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);

	// 出栈
	StackPop(&st);
	StackPop(&st);
	StackPop(&st);

	// 获取栈顶元素
	printf("%d\n", StackTop(&st));

	// 销毁栈
	StackDestroy(&st);
}

void test2()
{
	Stack st;

	// 初始化栈
	StackInit(&st);

	// 入栈
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);

	// 遍历栈 这样写才能符合栈的性质
	while (!StackEmpty(&st))
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);
	}

	// 销毁栈
	StackDestroy(&st);
}

int main()
{
	//test1();

	test2();

	return 0;
}