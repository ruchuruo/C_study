/*
	strcpy()有两个参数
		1.目标空间的起始地址
		2.源空间的起始地址

	strcpy()拷贝的时候\0也会拷贝过去

	strcpy()库函数
		char * strcpy(char * 目标, const char * 源);
*/

#include <stdio.h>
#include <assert.h>

// 模拟实现库函数：strcpy
void 字符串拷贝1(char* 目标, char* 源)
{
	while (*源 != '\0')
	{
		*目标 = *源;
		目标++;
		源++;
	}
	*目标 = *源;// 循环结束后拷贝\0
}

void 字符串拷贝2(char* 目标, char* 源)
{
	while (*源 != '\0')
	{
		*目标++ = *源++;// 目标++;源++;本来就是拷贝完成后++，改成后置++，先使用再++
	}
	*目标 = *源;// 循环结束后拷贝\0
}

void 字符串拷贝3(char* 目标, char* 源)
{
	while (*目标++ = *源++)// \0的ascii码是0，0为假停止循环，表达式结果为0停止循环
	{
		;
	}
}

void 字符串拷贝4(char* 目标, char* 源)
{
	// 空指针不能进行解引用操作
	assert(源 != NULL);// 断言，条件为假 程序报错 显示错误行数
	assert(目标 != NULL);
	while (*目标++ = *源++)// \0的ascii码是0，0为假停止循环，表达式结果为0停止循环
	{
		;
	}
}

// 把 源 指向的内容拷贝放进 目标 指向的空间中
// 从本质上讲，希望 目标 指向的内容被修改，源 指向的内容不应该被修改
void 字符串拷贝5(char* 目标, const char* 源)// 加上const修饰变量，所修饰的数据类型的变量或对象的值是不能被改变的
{
	// 空指针不能进行解引用操作
	assert(源 != NULL);// 断言，条件为假报错
	assert(目标 != NULL);
	while (*目标++ = *源++)// 上面加上const后这里写反了编译器会报错
	{
		;
	}
}

// strcpy()这个库函数其实返回的是目标空间的起始地址，拷贝完成后返回
char* 字符串拷贝(char* 目标, const char* 源)
{
	assert(源 != NULL);
	assert(目标 != NULL);
	char* ret = 目标;
	while (*目标++ = *源++)
	{
		;
	}

	//return 目标;// 不能这样写，因为上面++了很多次 不是起始地址了
	return ret;
}

int main()
{
	char arr1[20] = "xxxxxxxxxx";
	char arr2[] = "hello";
	字符串拷贝(arr1, arr2);
	//printf("%s\n", arr1);
	printf("%s\n", 字符串拷贝(arr1, arr2));// 链式访问，一个函数的 返回值 作为另一个函数的 参数 

	return 0;
}