
/*
	20. 有效的括号

	难度：简单

	给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

	有效字符串需满足：
		左括号必须用相同类型的右括号闭合。
		左括号必须以正确的顺序闭合。
		每个右括号都有一个对应的相同类型的左括号。


	示例 1：
		输入：s = "()"
		输出：true

	示例 2：
		输入：s = "()[]{}"
		输出：true

	示例 3：
		输入：s = "(]"
		输出：false

	提示：
		1 <= s.length <= 104
		s 仅由括号 '()[]{}' 组成
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef char STDataType;

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











bool isValid(char* s)
{
	/*
		思路1：栈
			左括号 入栈
			右括号 出栈 匹配数据
	*/

	Stack st;

	// 初始化栈
	StackInit(&st);

	while (*s)
	{
		if (*s == '(' || *s == '[' || *s == '{')
		{
			// 入栈
			StackPush(&st, *s);
			
			s++;
		}
		else
		{
			// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
			if (StackEmpty(&st))
			{
				// 销毁栈
				StackDestroy(&st);

				// 遇到右括号，但是栈空，说明前面没有左括号，没有匹配 返回false
				return false;
			}

			// 获取栈顶元素
			STDataType top = StackTop(&st);

			// 出栈
			StackPop(&st);

			if (
					(*s == ')' && top != '(') ||
					(*s == ']' && top != '[') ||
					(*s == '}' && top != '{')
				)
			{
				// 销毁栈
				StackDestroy(&st);

				return false;
			}
			else
			{
				s++;
			}
		}
	}

	// 如果栈不是空，说明栈中还有左括号未出 没有匹配 返回false
	// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
	bool ret = StackEmpty(&st);

	// 销毁栈
	StackDestroy(&st);

	return ret;
}

int main()
{
	bool ret = isValid("()[]{}");

	return 0;
}