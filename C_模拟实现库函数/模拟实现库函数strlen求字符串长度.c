/*
	模拟实现库函数strlen求字符串长度
	strlen 求字符串长度

	__cdecl - 函数调用约定 - 函数调用时传参，参数从左传还是从右传。决定了函数调用的一些细节的规则
*/

#include <stdio.h>
#include <assert.h>

// 健壮性 鲁棒性
int 字符串长度1(const char* arr)
{
	//assert(arr != NULL);// 这里不能写成*arr，如果arr为空解引用程序崩溃，assert没机会报错
	assert(arr);// 也可也写成这样，空为0，0为假，报错
	int 计数器 = 0;
	while (*arr != '\0')// 不能写成"\0"，这样是字符串\0
	{
		计数器++;
		arr++;
	}
	return 计数器;// 循环结束返回计数器
}

// 长度不会是负数，所以用无符号整形
// size_t 是 unsigned int
size_t 字符串长度(const char* arr)
{
	//assert(arr != NULL);// 这里不能写成*arr，如果arr为空解引用程序崩溃，assert没机会报错
	assert(arr);// 也可也写成这样，空为0，0为假，报错
	size_t 计数器 = 0;
	while (*arr != '\0')// 不能写成"\0"，这样是字符串\0
	{
		计数器++;
		arr++;
	}
	return 计数器;// 循环结束返回计数器
}

int main()
{
	char arr[] = "abc";
	int len = 字符串长度(arr);
	printf("%d\n", len);

	return 0;
}
