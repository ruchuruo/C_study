
/*
	printf("文字\n");
	n2(2, "-------- ", 4);
*/

#include "My_function.h"

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

struct 单链表* 初始化单链表()
{
	struct 单链表* n1 = (struct 单链表*)malloc(sizeof(struct 单链表));
	struct 单链表* n2 = (struct 单链表*)malloc(sizeof(struct 单链表));
	struct 单链表* n3 = (struct 单链表*)malloc(sizeof(struct 单链表));
	struct 单链表* n4 = (struct 单链表*)malloc(sizeof(struct 单链表));

	n1->val = 7;
	n2->val = 7;
	n3->val = 7;
	n4->val = 7;

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = NULL;

	return n1;
}