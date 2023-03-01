/*
	字符函数 和 字符串函数

		本章重点
			重点介绍处理字符和字符串的库函数的使用和注意事项

		——————————————————————————————————————————————————

		求字符串长度
			strlen

		长度不受限制的字符串函数
			strcpy
			strcat
			strcmp

		长度受限制的字符串函数介绍
			strncpy
			strncat
			strncmp

		字符串查找
			strstr
			strtok

		错误信息报告
			strerror

		字符操作

		内存操作函数
			memcpy
			memmove
			memset
			memcmp

		——————————————————————————————————————————————————

		前言
			C语言中对字符和字符串的处理很是频繁，但是C语言本身是没有字符串类型的，字符串通常放在 常量字符串 中
			或者 字符数组 中。字符串常量 适用于那些对它不做修改的字符串函数

		——————————————————————————————————————————————————

		求字符串长度

			strlen

				size_t strlen ( const char * str );

				●  字符串已经'\0'作为结束标志，strlen函数返回的是在字符串中'\0'前面出现的字符个数(不包括'\0')
				●  参数指向的字符串必须要以'\0'结束
				●  注意函数的返回值为size_t，是无符号的(易错)
				●  学会strlen函数的模拟实现

				strlen实现方法
					计数器
					递归
					指针减指针

				讲解在
					求字符串长度strlen()
					求字符串长度strlenII()

		--------------------------------------------------

		长度不受限制的字符串函数 - (长度不受限制：所有字符串操作完成后停止)

			strcpy 字符串拷贝

				char * strcpy ( char * destination, const char * source );
									   目的地                    来源

				●  Copies the C string pointed by source into the array pointed by destination,
				   including the terminating null character (and stopping at that point).
				●  源字符串必须以'\0'结束
				●  会将源字符串中的'\0'拷贝到目标空间
				●  目标空间必须足够大，以确保能存放源字符串
				●  目标空间必须可变
				●  学会模拟实现

				讲解在
					长度不受限制的字符串函数strcpy()


			strcat 字符串追加

				char * strcat ( char * destination, const char * source );

				●  Appends a copy of the source string to the destination string.
				   The terminating null character in destination is overwritten by the first character of source,
				   and a null-character is included at the end of the new string formed by the concatenation of both in destination.
				●  源字符串必须以'\0'结束
				●  目标空间必须有足够的大，能容纳下源字符串的内容
				●  目标空间必须可修改
				●  字符串自己给自己追加，如何？// strcat(arr, arr)，不能，\0被改变了，找不到结束的标志\0，把自己的\0覆盖了，死循环

				讲解在
					长度不受限制的字符串函数strcat字符串追加()
					长度不受限制的字符串函数strcat字符串追加_模拟实现()


			strcmp 字符串比较

				int strcmp ( const char * str1, const char * str2 );

				●  This function starts comparing the first character of each string. 
				   If they are equal to each other, 
				   it continues with the following pairs until the characters differ or until a terminating null-character is reached.
				●  标准规定
					○  第一个字符串大于第二个字符串，则返回大于0的数字
					○  第一个字符串等于第二个字符串，则返回0
					○  第一个字符串小于第二个字符串，则返回小于0的数字
				●  那么如何判断两个字符串？

				讲解在
					长度不受限制的字符串函数strcmp字符串比较()
					长度不受限制的字符串函数strcmp字符串比较_模拟实现()

		--------------------------------------------------

		长度受限制的字符串函数介绍

			strncpy 指定长度字符串拷贝
				
				char * strncpy ( char * destination, const char * source, size_t num );
																		  拷贝的字符个数

				●  Copies the first num characters of source to destination. 
				   If the end of the source C string (which is signaled by a null-character) is found before num characters have been copied, 
				   destination is padded with zeros until a total of num characters have been written to it.
				●  拷贝num个字符从源字符串到目标空间
				●  如果源字符串的长度小于num，则拷贝完源字符串之后，在目标的后面追加0，直到num个

				讲解在
					长度受限制的字符串函数介绍strncpy指定长度字符串拷贝()


			strncat 指定长度字符串追加
				
				char * strncat ( char * destination, const char * source, size_t num );

				●  Appends the first num characters of source to destination, plus a terminating null-character.
				●  If the length of the C string in source is less than num, only the content up to the terminating null-character is copied.

				讲解在
					长度受限制的字符串函数介绍strncat指定长度字符串追加()

			strncmp 指定长度字符串比较

				int strncmp ( const char * str1, const char * str2, size_t num );

				●  Compares up to num characters of the C string str1 to those of the C string str2.
				   This function starts comparing the first character of each string. 
				   If they are equal to each other, it continues with the following pairs until the characters differ, 
				   until a terminating null-character is reached, or until num characters match in both strings, whichever happens first.

				讲解在
					长度受限制的字符串函数介绍strncmp指定长度字符串比较()

		--------------------------------------------------
		——————————————————————————————————————————————————
*/

#include "define.h"

void 文档底部();

void n(int y)
{
	if (y < 0)
	{
		y = y * (-1);
		printf("\n-------- -------- -------- --------");
		int i = 0;
		for (i = 0; i < y; i++)
		{
			printf("\n");
		}
	}
	else
	{
		int i = 0;
		for (i = 0; i < y; i++)
		{
			printf("\n");
		}
	}
}

/*************************************************************************************************************************************************/
/*===============================================================================================================================================*/

void 求字符串长度strlen()
{
	printf("求字符串长度strlen\n");

	char arr[] = "abc";
	char arr2[] = { 'a', 'b', 'c' };// 没有\0

	int len = strlen(arr);
	int len2 = strlen(arr2);// 没有\0，随机值

	printf("%d\n", len);
	printf("%d\n", len2);

	n(2);
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------*/

void 求字符串长度strlenII()
{
	printf("求字符串长度strlenII\n");

	// 注意函数的返回值为size_t，是无符号的(易错)
	if (strlen("abc") - strlen("abcdef") > 0)// 这里-3被当成无符号数，非常大的正数
	{
		printf(">\n");
	}
	else
	{
		printf("<=\n");
	}

	n(-2);
}

/*===============================================================================================================================================*/

void 长度不受限制的字符串函数strcpy字符串拷贝()
{
	printf("长度不受限制的字符串函数strcpy字符串拷贝\n");

	char arr[6] = { 0 };
	char arr2[] = { 'a', 'b', 'c' };
	char* arr3 = "hello world";
	char* arr4 = "hello *****";

	// 将hello放到数组arr里
	//arr = "hello";// 错误写法，arr是数组名，数组名是首元素地址，地址是个编号，编号是常量，把hello放到编号上？应该把hello放到编号所指向的空间内

	strcpy(arr, "hello");
	//strcpy(arr, arr2);// err，arr2内没有\0，拷贝不知道什么时候停止
	//strcpy(arr, arr3);// err，放不下
	//strcpy(arr3, arr4);// err，目标空间是常量，不能改变

	printf("%s\n", arr);

	n(2);
}

/*===============================================================================================================================================*/

void 长度不受限制的字符串函数strcat字符串追加()
{
	printf("长度不受限制的字符串函数strcat字符串追加\n");

	char arr1[20] = "hello \0########";
	char arr2[] = "world";

	strcat(arr1, arr2);// 字符串追加(连接)，覆盖掉arr1的\0，会将arr2的\0带过去
	/*
		arr1 [h][e][l][l][0][ ][\0][#][#][#][#][# ][#][#][#][\0][\0][\0][\0][\0]
								↑   ↑  ↑  ↑  ↑  ↑
		arr2                   [w ][o][r][l][d][\0]
	*/

	printf("%s\n", arr1);

	n(2);
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------*/

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

void 长度不受限制的字符串函数strcat字符串追加_模拟实现()
{
	printf("长度不受限制的字符串函数strcat字符串追加_模拟实现\n");

	char arr1[20] = "hello ";
	char arr2[] = "world";

	//my_strcat(arr1, arr2);

	//printf("%s\n", arr1);
	printf("%s\n", my_strcat(arr1, arr2));// 这个函数有返回值，所以可以这样写

	n(2);
}

/*===============================================================================================================================================*/

void 长度不受限制的字符串函数strcmp字符串比较()
{
	printf("长度不受限制的字符串函数strcmp字符串比较\n");

	char* p = "obc";
	char* q = "abcdef";

	//if(p > q)				比较的是存放的地址
	//if("obc" > "abcdef")	比较的是首字符的地址

	// strcmp字符串比较方式
	// a b b b
	// | | <
	// a b c
	// "abbb" < "abc"
	
	int ret = strcmp("abbb", "abc");
	printf("%d\n", ret);

	n(2);
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------*/

int my_strcmp(const char* s1, const char* s2)
{
	/*
		s1
		↓
		abcdef\0

		abbb\0
		↑
		s2
	*/
	assert(s1 && s2);
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
		{
			return 0;
		}
		s1++;
		s2++;
	}
	if (*s1 > *s2)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

int my_strcmp_2(const char* s1, const char* s2)
{
	assert(s1 && s2);
	while (*s1 == *s2)// 比较的是ascii码值
	{
		if (*s1 == '\0')
		{
			return 0;
		}
		s1++;
		s2++;
	}
	return *s1 - *s2;
}

void 长度不受限制的字符串函数strcmp字符串比较_模拟实现()
{
	printf("长度不受限制的字符串函数strcmp字符串比较_模拟实现\n");

	char* p = "abbb";
	char* q = "abbb";
	int ret = my_strcmp_2(p, q);
	printf("%d\n", ret);

	// 这里的返回值判断 不建议写成ret == 1
	// 因为返回值是大于或小于或等于0的值
	if (ret > 0)
	{
		printf("p > q\n");
	}
	else if(ret < 0)
	{
		printf("p < q\n");
	}
	else
	{
		printf("p == q\n");
	}

	n(-2);
}

/*===============================================================================================================================================*/

void 长度受限制的字符串函数介绍strncpy指定长度字符串拷贝()
{
	printf("长度受限制的字符串函数介绍strncpy指定长度字符串拷贝\n");

	char arr1[20] = "abcdef";
	char arr2[] = "qwer";
	strncpy(arr1, arr2, 2);// 如果拷贝6个，qwer后面继续拷贝\0
	printf("%s\n", arr1);

	n(2);
}

/*===============================================================================================================================================*/

void 长度受限制的字符串函数介绍strncat指定长度字符串追加()
{
	printf("长度受限制的字符串函数介绍strncat指定长度字符串追加\n");

	char arr1[20] = "hello ";
	char arr2[] = "world";
	strncat(arr1, arr2, 3);// 如果追加10个，\0追加完成后停止
	printf("%s\n", arr1);

	n(2);
}

/*===============================================================================================================================================*/

void 长度受限制的字符串函数介绍strncmp指定长度字符串比较()
{
	printf("长度受限制的字符串函数介绍strncmp指定长度字符串比较\n");

	char* p = "abcdef";
	char* q = "abcddddd";
	int ret = strncmp(p, q, 3);
	printf("%d\n", ret);

	n(-2);
}

/*===============================================================================================================================================*/

int main()
{
	求字符串长度strlen();
	求字符串长度strlenII();

	长度不受限制的字符串函数strcpy字符串拷贝();

	长度不受限制的字符串函数strcat字符串追加();
	长度不受限制的字符串函数strcat字符串追加_模拟实现();
	
	长度不受限制的字符串函数strcmp字符串比较();
	长度不受限制的字符串函数strcmp字符串比较_模拟实现();

	长度受限制的字符串函数介绍strncpy指定长度字符串拷贝();

	长度受限制的字符串函数介绍strncat指定长度字符串追加();

	长度受限制的字符串函数介绍strncmp指定长度字符串比较();

	return 0;
}

/*************************************************************************************************************************************************/

void 文档底部()
{
	;
}