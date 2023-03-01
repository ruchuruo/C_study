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
			perror

		字符操作
			字符分类函数：
				函数			如果它的参数符合下列条件就返回真
				iscntrl		任何控制字符
				isspace		空白字符：空格‘ ’，换页‘\f’，换行'\n'，回车'\r'，制表符'\t'，或垂直制表符'\v'
				isdigit		进制数字0~9
				isxdigit	十六进制数字，包括所有十进制数字，小写字母a~f,大写字母A~F
				islower		小写字母a~z
				isupper		大写字母A~Z
				isalpha		字母a~z或A~Z
				isalnum		字母或数字a~z，A~Z或0~9
				ispunct		标点符号，任何不属于数字或字母的图像字符（可打印符号）
				isgraph		任何图像字符
				isprint		任何可打印字符，包括图像字符和空白字符

			字符转换函数：
				int tolower ( int c )
				int toupper ( int c )

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

		字符串查找

			strstr 判断字符串str2是否是str1的子串

				const char * strstr ( const char * str1, const char * str2 );
				char * strstr (       char * str1, const char * str2 );
				char * strstr ( const char *, const char * );// (比特科技)

				●  Returns a pointer to the first occurrence of str2 in str1, or a null pointer if str2 is not part of str1.

				讲解在
					字符串查找strstr判断字符串()
					字符串查找strstr判断字符串_模拟实现()


			strtok 字符串分割

				char * strtok ( char * str, const char * delimiters );
				char * strtok ( char * str, const char * sep );// (比特科技)

				●  sep参数是个字符串，定义了作用分隔符的字符集合
				●  第一个参数指定一个字符串，它包含了0个或者多个由sep字符串中一个或多个分隔符分割的标记
				●  strtok函数找到str中的下一个标记，并将其用\0结尾，返回一个指向这个标记的指针。
				   (注：strtok函数会改变被操作的字符串，所以在使用strtok函数切分的字符串一般都是临时拷贝的内容并且可修改)
				●  strtok函数的第一个参数不为NULL，函数将找到str中第一个标记，strtok函数将保存它在字符串中的位置
				●  strtok函数的第一个参数为  NULL，函数将在同一个字符串中被保存的位置开始，查找下一个标记
				●  如果字符串中不存在更多的标记，则返回NULL指针

				讲解在
					字符串查找strtok字符串分割()
					字符串查找strtok字符串分割II()

		--------------------------------------------------

		错误信息报告

			strerror 返回一个指向错误消息字符串的指针

				char * strerror ( int errnum );

				●  返回错误码，所对应的错误信息

				讲解在
					错误信息报告strerror返回一个指向错误消息字符串的指针()


			perror 将上一个函数发生错误的原因输出

				void perror ( const char * str );

				●  打印错误信息
				●  #include <stdio.h>

				讲解在
					错误信息报告perror将上一个函数发生错误的原因输出()

		--------------------------------------------------

		字符操作
			字符分类函数：
				函数			如果它的参数符合下列条件就返回真

				iscntrl		任何控制字符，																	判断一个字符是否是控制字符
				isspace		空白字符：空格‘ ’，换页‘\f’，换行'\n'，回车'\r'，制表符'\t'，或垂直制表符'\v'，	判断一个字符是否是空白字符
				isdigit		进制数字0~9，																	判断一个字符是否是数字字符
				isxdigit	十六进制数字，包括所有十进制数字，小写字母a~f,大写字母A~F，						判断一个字符是否是十六进制数字字符
				islower		小写字母a~z，																	判断一个字符是否是小写字母
				isupper		大写字母A~Z，																	判断一个字符是否是大写字母
				isalpha		字母a~z或A~Z，																	判断一个字符是否是字母
				isalnum		字母或数字a~z，A~Z或0~9，														判断一个字符是否是字母或数字
				ispunct		标点符号，任何不属于数字或字母的图像字符（可打印符号），							判断一个字符是否是标点符号
				isgraph		任何图像字符，																	判断一个字符是否是任何图像字符
				isprint		任何可打印字符，包括图像字符和空白字符，											判断一个字符是否是任何可打印字符

				讲解在
					字符操作_字符分类函数()


			字符转换函数：
				int tolower ( int c )// 转小写
				int toupper ( int c )// 转大写

				讲解在
					字符操作_字符转换函数()

		--------------------------------------------------

		内存操作函数

			memcpy 内存拷贝

				void * memcpy ( void * destination, const void * source, size_t num );

				●  函数memcpy从source的位置开始向后复制num个字节的数据到destination的内存位置
				●  这个函数在遇到'\0'的时候并不会停下来
				●  如果source和destination有任何的重叠，复制的结果都是未定义的
				●  source(来源) destination(目的地)

				讲解在
					内存操作函数memcpy内存拷贝()
					内存操作函数memcpy内存拷贝_模拟实现()
					内存操作函数memcpy内存拷贝_模拟实现II()


			memmove 内存移动

				void * memmove ( void * destination, const void * source, size_t num );

				●  和memcpy的差别就是memmove函数处理的源内存块和目标内存块是可以重叠的
				●  如果源空间和目标空间出现重叠，就得使用memmove函数处理

				讲解在
					内存操作函数memmove内存移动()
					内存操作函数memmove内存移动_模拟实现()


			memset 内存设置

				void * memset ( void * ptr, int value, size_t num );

				●  
				●  
				●  
				●  

				讲解在
					内存操作函数memset内存设置()


			memcmp 内存比较

				int memcmp ( const void * ptr1, const void * ptr2, size_t num );

				●  比较从ptr1和ptr2指针开始的num个字节
				●  返回值如下：
					○	Return Value
						—————————————————————————————————————————————————————————————————————————————————————————————————
						Returns an integral value indicating the relationship between the content of the memory blocks:
						_________________________________________________________________________________________________
						return value	indicates
						-------------------------------------------------------------------------------------------------
						<0				the first byte that does not match in both memory blocks has a lower value in ptr1 than in ptr2 
										(if evaluated as unsigned char values)
						-------------------------------------------------------------------------------------------------
						0				the contents of both memory blocks are equal
						-------------------------------------------------------------------------------------------------
						>0				the first byte that does not match in both memory blocks has a greater value in ptr1 than in ptr2 
										(if evaluated as unsigned char values)
						_________________________________________________________________________________________________

				讲解在
					内存操作函数memcmp内存比较()

		--------------------------------------------------
		——————————————————————————————————————————————————
*/

#include "define.h"
#include <errno.h>// 错误码
#include <ctype.h>// 字符操作_字符分类函数

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
	else if (ret < 0)
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

void 字符串查找strstr判断字符串()
{
	printf("字符串查找strstr判断字符串\n");

	char arr1[] = "abcdefabcdef";
	char arr2[] = "bcd";

	// 在arr1中查找是否包含arr2数组
	char* ret = strstr(arr1, arr2);// 如果找到返回第一次出现的首字符的地址，如果找不到返回空指针

	if (ret == NULL)
	{
		printf("没找到\n");
	}
	else
	{
		printf("找到：%s\n", ret);// 从找到的字符的地址向后打印
	}

	n(2);
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------*/

char* my_strstr(const char* str1, const char* str2)// 接收到的是字符串首字符的地址
{
	/*

		情况1
			str1
			↓
			abcdefabcdef

			cde
			↑
			str2

			第一次
				c和a比较
				不相等
				str1向后走一步

				 str1
				 ↓
				abcdefabcdef
				cde
				↑
				str2

			第二次
				b和c比较
				不相等
				str1向后走一步

				  str1
				  ↓
				abcdefabcdef
				cde
				↑
				str2

			第三次
				c和c比较
				相等
				str1向后走一步
				str2向后走一步

				   str1
				   ↓
				abcdefabcdef
				cde
				 ↑
				 str2

			第四次
				d和d比较
				相等
				str1向后走一步
				str2向后走一步

					str1
					↓
				abcdefabcdef
				cde
				  ↑
				  str2

			第五次
				e和e比较
				相等
				str1向后走一步
				str2向后走一步

					 str1
					 ↓
				abcdefabcdef
				cde[\0]
				   ↑
				   str2

			str2找到\0查找完成

		情况2
			str1
			↓
			abbbcdef

			bbc
			↑
			str2

			如果 情况2 用 情况1 的步骤来解决会找不到

			当前str2和str1匹配成功的话
				 str1
				 ↓
				abbbcdef
				bbc
				↑
				str2

			str1向后移动一步
				  str1
				  ↓
				abbbcdef
				bbc
				↑
				str2

			试试str2是否还能和str1匹配成功

			如果匹配不成功
			str1回退到上一次开始匹配的位置的下一个位置
			str2回退到上一次开始匹配的位置
				 str1
				 ↓
				abbbcdef
				bbc
				↑
				str2
	*/

	assert(str1 && str2);

	// str1和str2走着走着会回不到最初的位置，所以先保存 或 赋值给s1和s2，之后使用s1和s2
	const char* s1 = str1;
	const char* s2 = str2;

	// str1怎么回到上一次匹配的位置(不是起始位置)，再创建一个变量来保存str1
	const char* cp = str1;

	// 如果要查找的是空字符串
	if (*str2 == '\0')
	{
		return (char*)str1;// 强制类型转换，因为被const修饰，const char* 类型 → char* 类型

	}


	// 开始查找
	while (*cp)
	{
		s1 = cp;
		s2 = str2;

		while (*s1 && *s2 && (*s1 == *s2))
		{
			s1++;// s1负责往前走
			s2++;
		}
		if (*s2 == '\0')
		{
			return (char*)cp;// 强制类型转换，因为被const修饰，const char* 类型 → char* 类型
		}
		cp++;// cp负责保存上一次记录

	}
	return NULL;
	/*
		s1
		↓
		abbbcdef
		↑
		cp

		bbc
		↑
		s2

		KMP算法 比上面的代码效率更高
		(KMP算法 - 字符串查找算法)
	*/
}

void 字符串查找strstr判断字符串_模拟实现()
{
	printf("字符串查找strstr判断字符串_模拟实现\n");

	char arr1[] = "abbbcdef";
	char arr2[] = "bbc";

	char* ret = my_strstr(arr1, arr2);// 传的是字符串首字符的地址

	if (ret == NULL)
	{
		printf("没找到\n");
	}
	else
	{
		printf("找到：%s\n", ret);
	}

	n(2);
}

/*===============================================================================================================================================*/

void 字符串查找strtok字符串分割()
{
	printf("字符串查找strtok字符串分割\n");

	/*

		ruchuruo@gmail.com
		分割符的集合就是@和.

		192.168.1.100
		切割后
		将分割符改成\0，再返回 1 的地址
		↓
		192 \0

		但是strtok函数调用一次只能切割一次

		———————————————————————————————————————
		---------------------------------------

		第一个参数不为空指针
			strtok(tmp, p);

			strtok函数将找到的第一个分割符改成\0
						↓
				ruchuruo\0gmail.com

			返回 r 的地址
				↓
				ruchuruo\0gmail.com

			记录\0的地址
						↓
				ruchuruo\0gmail.com

		---------------------------------------

		第一个参数为空指针
			strtok(NULL, p);

			会从刚刚保存的位置继续往下
						↓
				ruchuruo\0gmail.com

			strtok函数将找到的第一个分割符改成\0
							   ↓
				ruchuruo\0gmail\0com

			返回 g 的地址
						  ↓
				ruchuruo\0gmail\0com

			记录\0的地址
							   ↓
				ruchuruo\0gmail\0com

		---------------------------------------

		再次调用找到\0
								↓
			ruchuruo\0gmail\0com\0

		返回 c 的地址
							 ↓
			ruchuruo\0gmail\0com\0

		记录\0的地址
								↓
			ruchuruo\0gmail\0com\0

		---------------------------------------

		如果再次调用，找不到了，返回空指针

		---------------------------------------
		———————————————————————————————————————

		只有第一次调用的时候传tmp过去，之后调用传空指针
			strtok(tmp, p);
			strtok(NULL, p);
			strtok(NULL, p);

	*/

	char arr[] = "ruchuruo@gmail.com";
	char* p = "@.";// 分割符也可也单独拿出来

	char tmp[20] = { 0 };// 备份，防止原字符串被修改
	strcpy(tmp, arr);

	//strtok(arr, "@.");
	char* ret = NULL;

	ret = strtok(tmp, p);
	printf("%s\n", ret);

	ret = strtok(NULL, p);
	printf("%s\n", ret);

	ret = strtok(NULL, p);
	printf("%s\n", ret);

	n(2);
}

void 字符串查找strtok字符串分割II()
{
	printf("字符串查找strtok字符串分割II\n");

	/*
		如果有未知个分割符，通过strtok函数的返回值 判断要不要往下找
	*/
	char arr[] = "document.getElementById(\"星空\").style.width";
	char* p = ".";

	char tmp[50] = { 0 };
	strcpy(tmp, arr);

	char* ret = NULL;

	for (ret = strtok(tmp, p); ret != NULL; ret = strtok(NULL, p))// for里的初始化(第一条代码)只执行一次
	{
		printf("%s\n", ret);
	}

	n(-2);
}

/*===============================================================================================================================================*/

void 错误信息报告strerror返回一个指向错误消息字符串的指针()
{
	printf("错误信息报告strerror返回一个指向错误消息字符串的指针\n");

	/*
		使用库函数的时候，调用库函数失败的时候，都会设置错误码

		C语言有一个全局变量，用来存放错误码的，发生错误时存放进去
		int errno;
	*/

	printf("%s\n", strerror(0));// 随便传进去一个
	//printf("%s\n", strerror(1));// 随便传进去一个
	//printf("%s\n", strerror(2));// 随便传进去一个

	// 假设打开一个文件
	FILE* pf = fopen("testttttt.txt", "r");// 以只读形式打开一个文件，没有这个文件打开失败，pf就得到一个空指针，FILE* 是指针类型
	if (pf == NULL)
	{
		printf("%s\n", strerror(errno));// 调用失败fopen函数会把错误码存放到errno变量里
		n(2);
		return 1;// 失败了以下代码就不需要执行了
	}

	// 如果成功就... ...
	fclose(pf);// 关闭文件
	pf = NULL;

	//n(-2);// 上面失败了这里就不会执行了，换行函数放到了上面
}

/*===============================================================================================================================================*/

void 错误信息报告perror将上一个函数发生错误的原因输出()
{
	printf("错误信息报告perror将上一个函数发生错误的原因输出\n");

	/*
		strerror函数只是把错误码转换成错误信息，不会打印
		perror函数直接打印错误信息
		perror函数接收的是一个const char* 的一个指针
		perror函数会自己去拿errno的值 然后把错误码转换成错误信息 再打印
	*/

	// 假设打开一个文件
	FILE* pf = fopen("testttttt.txt", "r");
	if (pf == NULL)
	{
		perror("错误信息");// 打印的时候 先打印自定义信息 再打印冒号 再打印空格 最后打印错误信息
		n(-2);
		return 1;// 失败了以下代码就不需要执行了
	}

	// 如果成功就... ...
	fclose(pf);// 关闭文件
	pf = NULL;

	//n(-2);// 上面失败了这里就不会执行了，换行函数放到了上面
}

/*===============================================================================================================================================*/

void 字符操作_字符分类函数()
{
	printf("字符操作_字符分类函数\n");

	char ch1 = '2';
	char ch2 = '#';
	int ret1 = isdigit(ch1);// int isdigit ( int c ); 传ASCII码值，
	int ret2 = isdigit(ch2);// 如果是数字字符返回非0的值，如果不是数字字符返回0
	printf("%d\n", ret1);
	printf("%d\n", ret2);

	n(1);

	char ch3 = 'a';
	char ch4 = 'A';
	int ret3 = islower(ch3);// int islower ( int c );
	int ret4 = islower(ch4);// 如果是小写字母返回非0的值，如果不是小写字母返回0
	printf("%d\n", ret3);
	printf("%d\n", ret4);
	if (ch3 >= 'A' && ch3 <= 'Z')// 这样也可也
	{
		;
	}

	n(2);
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------*/

void 字符操作_字符转换函数()
{
	printf("字符操作_字符转换函数\n");

	char arr[20] = { 0 };
	printf("请输入字母>");
	scanf("%s", arr);
	int i = 0;
	while (arr[i] != '\0')// 遍历数组
	{
		if (isupper(arr[i]))// 如果字母是大写
		{
			arr[i] = tolower(arr[i]);// 转换成小写，会返回转换后的字母
		}
		printf("%c ", arr[i]);
		i++;
	}

	n(1);
	n(-2);
}

/*===============================================================================================================================================*/

void 内存操作函数memcpy内存拷贝()
{
	printf("内存操作函数memcpy内存拷贝\n");

	/*
		拷贝arr1的前5个元素到arr2

		strcpy()函数不适用
			char * strcpy ( char * destination, const char * source );
			strcpy()是拷贝字符串，这里的arr1和arr2都是整形，传参也会出现问题

			strcpy()拷贝的时候是遇见'\0'停止，如果是小端存储，
			01 00 00 00 02 00 00 00... ...
			strcpy()一个个字节拷贝，拷贝到第二个字节就停止了
	*/

	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int arr2[10] = { 0 };

	// void * memcpy ( void * destination, const void * source, size_t num );
	// void*无具体类型的指针，任何地址都能放到void* 的指针里
	memcpy(arr2, arr1, 20);// 拷贝20字节

	n(2);
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------*/

void* my_memcpy(void* 目的地, const void* 源, size_t 字节)// size_t 无符号整形
{
	/*
		void* 的指针不能直接 解引用，++，-- 操作的
		因为void*是无具体类型的指针
	*/

	assert(目的地 && 源);

	void* ret = 目的地;// 保存目的地的地址

	while (字节--)
	{
		*(char*)目的地 = *(char*)源;// 强制类型转换 后 解引用
		目的地 = (char*)目的地 + 1;
		源 = (char*)源 + 1;

			// *(char*)目的地++ = *(char*)源++; 
			// 报错，强制类型转换之后针对的是 目的地和源，++加的时候强制类型转换的效果已经过去了，强制类型转换是一种临时的状态
			// 对于(char*)前面的*来说，这个表达式的结果是强制类型转换后的
			// 这个++加的时候 目的地和源 还是void*
			// 
			// 换成前置++有些编译器可以通过，但是在这不合适，加完后再拷贝，会提前跳过一组字符

		//*((char*)目的地)++ = *((char*)源)++;// 这样可以
	}
	return ret;// 返回 目的地 的 起始地址
}

void 内存操作函数memcpy内存拷贝_模拟实现()
{
	printf("内存操作函数memcpy内存拷贝_模拟实现\n");

	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int arr2[10] = { 0 };

	my_memcpy(arr2, arr1, 20);// 拷贝20字节

	n(2);
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------*/

void* my_memcpyII(void* 目的地, const void* 源, size_t 字节)
{
	assert(目的地 && 源);

	void* ret = 目的地;

	while (字节--)
	{
		*(char*)目的地 = *(char*)源;
		目的地 = (char*)目的地 + 1;
		源 = (char*)源 + 1;
	}
	return ret;
}

void 内存操作函数memcpy内存拷贝_模拟实现II()
{
	printf("内存操作函数memcpy内存拷贝_模拟实现II\n");

	/*
		将arr1的 12345放到 arr1的34567的空间里
		拷贝成功数据会变成：1 2 1 2 3 4 5 8 9 10

		但是这里失败了：	   1 2 1 2 1 2 1 8 9 10
		拷贝的空间有重叠，后面的345被覆盖了

		但是库里的memcpy()函数能达到效果，能拷贝成功，自己写的不行
		其实库里面 C语言标准 memcpy()，只要实现了不重叠拷贝就可以了，VS中的实现既可以拷贝 不重叠 的也可也拷贝 重叠 的
		其他平台就可能不一样

		memcpy()函数应该拷贝不重叠的内存
		memmove()函数可以处理内存重叠的情况
	*/

	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };

	my_memcpyII(arr1 + 2, arr1, 20);

	n(2);
}

/*===============================================================================================================================================*/

void 内存操作函数memmove内存移动()
{
	printf("内存操作函数memmove内存移动\n");

	/*
		将arr1的 12345放到 arr1的34567的空间里
		拷贝成功数据会变成：1 2 1 2 3 4 5 8 9 10

		memmove()函数可以处理内存重叠的情况
	*/

	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };

	memmove(arr1 + 2, arr1, 20);

	n(2);
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------*/

void* my_memmove(void* 目的地, const void* 源, size_t 字节)
{
	/*
		源  目的地
		↓   ↓
		1 2 3 4 5 6 7 8 9 10

		建立临时储存，不行，不知道给多大的空间，数组大小必须是常数

		可以把源数据，从前向后拷贝，也可也从后向前拷贝

		什么时候从前，什么时候从后？

		如果 目的地 在 源 左边，从前向后拷贝
		如果 目的地 在 源 范围内，从后向前拷贝
		如果 目的地 在 源 范围后，从前向后拷贝，也可也从后向前拷贝
		            源-------------源
		            ↓               ↓
			1   2   3   4   5   6   7   8   9   10
			←←←←←   ↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑   →→→→→→→→→→
			目的地      目的地           目的地
			前->后      后->前           任意

		这里我们选择
			1   2   3   4   5   6   7   8   9   10
			←←←←←←←←|→→→→→→→→→→→→→→→→→→→→→→→→→→→→→
			前->后	|    后->前
	*/

	assert(目的地 && 源);
	void* ret = 目的地;

	if (目的地 < 源)
	{
		// 前->后
		while (字节--)
		{
			*(char*)目的地 = *(char*)源;
			目的地 = (char*)目的地 + 1;
			源 = (char*)源 + 1;
		}
	}
	else
	{
		// 后->前
		while (字节--)
		{
			// 假设字节开始为20
			// 循环判断是后置--，在这里字节是19
			// (char*)目的地 + 字节
			// 假设来到了元素7的最后一个字节
			// 小端存储：07 00 00 00
			//                   ↑
			// 
			// 再括起来解引用*((char*)目的地 + 字节)
			*((char*)目的地 + 字节) = *((char*)源 + 字节);
		}
	}
	return ret;
}

void 内存操作函数memmove内存移动_模拟实现()
{
	printf("内存操作函数memmove内存移动_模拟实现\n");

	/*
		将arr1的 12345放到 arr1的34567的空间里
		拷贝成功数据会变成：1 2 1 2 3 4 5 8 9 10
	*/

	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int arr9[10] = { 1,2,3,4,5,6,7,8,9,10 };

	my_memmove(arr1 + 2, arr1, 20);
	my_memmove(arr9, arr9 + 2, 20);

	n(2);
}

/*===============================================================================================================================================*/

void 内存操作函数memcmp内存比较()
{
	printf("内存操作函数memcmp内存比较\n");

	/*
		memcmp和strcmp返回值思路相同，相同返回0，str1>str2返回大于0，str1<str2返回小于0
	*/

	float arr1[] = { 1.0,2.0,3.0,4.0 };
	float arr2[] = { 1.0,3.0 };

	int ret1 = memcmp(arr1, arr2, 4);// 比较前4字节
	int ret2 = memcmp(arr1, arr2, 8);// 比较前8字节

	printf("%d\n", ret1);
	printf("%d\n", ret2);

	n(2);
}

/*===============================================================================================================================================*/

void 内存操作函数memset内存设置()
{
	printf("内存操作函数memset内存设置\n");

	/*
		void * memset ( void * ptr, int value, size_t num );

						ptr		被设置
						value	设置
						num		前num个字节

		以字节为单位设置内存
	*/

	int arr[10] = { 0 };// 总共有40字节
	memset(arr, 1, 20);// 前20个字节设置成1

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

	字符串查找strstr判断字符串();
	字符串查找strstr判断字符串_模拟实现();

	字符串查找strtok字符串分割();
	字符串查找strtok字符串分割II();

	错误信息报告strerror返回一个指向错误消息字符串的指针();

	错误信息报告perror将上一个函数发生错误的原因输出();

	字符操作_字符分类函数();

	//字符操作_字符转换函数();// 需要输入字母
	n(-2);

	内存操作函数memcpy内存拷贝();			// 调试查看
	内存操作函数memcpy内存拷贝_模拟实现();	// 调试查看
	内存操作函数memcpy内存拷贝_模拟实现II();	// 调试查看

	内存操作函数memmove内存移动();			// 调试查看
	内存操作函数memmove内存移动_模拟实现();	// 调试查看

	内存操作函数memcmp内存比较();

	内存操作函数memset内存设置();			// 调试查看，内存窗口

	return 0;
}

/*************************************************************************************************************************************************/

void 文档底部()
{
	n(1);
}