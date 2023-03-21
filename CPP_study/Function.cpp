
#include "Function.h"

void n2(int 换行次数, char* 换行符号, int 符号个数)
{
	int i = 0;

	if (换行符号 != NULL && 符号个数 > 0)
	{
		printf("\n");
		for (i = 0; i < 符号个数; i++)
		{
			printf("%s", 换行符号);
		}
	}

	for (i = 0; i < 换行次数; i++)
	{
		printf("\n");
	}
}

// 计算整数位数
int digit(int num)
{
	int counter = 1;

	while (num >= 10)
	{
		num = num / 10;
		counter++;
	}

	return counter;
}


// 判断文件是否存在，判断文件权限
int fileAccess(const char* FileName, int mode)
{
	// fopen("..\\测试文件操作\\文件2.txt", "r");

	/*
		int _access(const char* path,int mode);
		int _waccess(const char* path,int mode);

		在windows平台，直接调用c函数库中的_access函数。

		就是函数 int _access(const char* path,int mode);

		或者  int _waccess(const char* path,int mode);
		_waccess是_access的宽字符版本，_waccess的参数path为宽字符的字符串，其他与_access相同。

		这个函数的功能十分强大，其头文件为#include  <io.h>。

		参数含义： path表示文件或目录的路径；mode表示访问权限。
		返回值：如果文件具有指定的访问权限，则函数返回0；如果文件不存在，或者没有访问指定的权限，则返回-1。

		备注：当path为文件时，_access函数判断文件是否存在，并判断文件是否可以用 mode值指定的模式进行访问。当path为目录时，_access只判断指定的目录是否存在，在WindowsNT和Windows2000中，所有的目录都有读写权限。

		mode的值和含义如下表所示：

			mode值  检查文件
			00      只检查文件是否存在
			02      写权限
			04      读权限
			06      读写权限
		————————————————
		版权声明：本文为CSDN博主「爱思考的实践者」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
		原文链接：https://blog.csdn.net/chinawangfei/article/details/42487839
	*/

	// https://learn.microsoft.com/zh-cn/cpp/c-runtime-library/reference/access-waccess?view=msvc-170
	
	switch (mode)
	{
	case 0:
		if (_access(FileName, mode) == 0)
		{
			// 文件存在
			return 1;
		}
		else
		{
			printf("文件 不 存在\n");
			return 0;
		}

		break;

	case 2:
		if (_access(FileName, mode) == 0)
		{
			// 文件可写
			return 1;
		}
		else
		{
			printf("文件 不可 写\n");
			return 0;
		}

		break;

	case 4:
		if (_access(FileName, mode) == 0)
		{
			// 文件可读
			return 1;
		}
		else
		{
			printf("文件 不可 读\n");
			return 0;
		}

		break;

	case 6:
		if (_access(FileName, mode) == 0)
		{
			// 文件可读写
			return 1;
		}
		else
		{
			printf("文件 不可 读写\n");
			return 0;
		}

		break;

	default:
		printf("模式错误\n");
		return 0;
		break;
	}
}

