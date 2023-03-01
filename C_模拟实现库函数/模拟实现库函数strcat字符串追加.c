/*
	132. 字符串函数及模拟实现strlen&&strcpy&&strcat
*/

#include <stdio.h>
#include <assert.h>

char* my_strcat(char* 目的地, const char* 源)
{
	/*
			 目的地
			 ↓
		arr1 [h][e][l][l][o][ ][\0][\0][\0][\0][\0][\0][\0][\0][\0][\0][\0][\0][\0][\0]
		arr2 [w][o][r][l][d][\0]
			 ↑
			 源

		1. 找到目标字符串中的\0
		2. 源数据追加过去，包含\0

		目的地最后指向的不再是arr1的起始位置
		先保存目的地
		最后再返回
	*/

	assert(目的地 && 源);

	char* ret = 目的地;

	//1. 找到目标字符串中的\0
	while (*目的地)
	{
		目的地++;
	}
	// 循环结束后 目的地 指向的是\0

	//2. 源数据追加过去，包含\0
	while (*目的地++ = *源++)// 赋值后++
	{
		;
	}

	return ret;// 返回的是目标空间的起始地址
}

void 长度不受限制的字符串函数strcat模拟实现()
{
	printf("长度不受限制的字符串函数strcat模拟实现\n");

	char arr1[20] = "hello ";
	char arr2[] = "world";

	//my_strcat(arr1, arr2);

	//printf("%s\n", arr1);
	printf("%s\n", my_strcat(arr1, arr2));// 这个函数有返回值，所以可以这样写
}

int main()
{
	长度不受限制的字符串函数strcat模拟实现();

	return 0;
}