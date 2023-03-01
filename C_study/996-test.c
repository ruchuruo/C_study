
#include "define.h"

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

int 判断文件是否存在(char* 文件路径)
{
	FILE* pfff = fopen(文件路径, "r");

	if (pfff == NULL)
	{
		return 0;
	}

	fclose(pfff);
	pfff = NULL;

	return 1;
}

void test()
{
	if (判断文件是否存在("..\\测试文件操作\\文件99.txt") == 0)
	{
		return;
	}
	printf("文件存在");
}


int main()
{
	test();

	printf("%d", 判断文件是否存在("..\\测试文件操作\\文件99.txt"));

	n2(2, "-------- ", 4);

	return 0;
}