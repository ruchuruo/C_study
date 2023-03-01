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

		--------------------------------------------------
		——————————————————————————————————————————————————
*/

#include "define.h"
#include <errno.h>// 错误码

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

	assert(str1&& str2);

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
		return 1;// 失败了以下代码就不需要执行了
	}

	// 如果成功就... ...
	fclose(pf);// 关闭文件
	pf = NULL;

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

	return 0;
}

/*************************************************************************************************************************************************/

void 文档底部()
{
	;
}