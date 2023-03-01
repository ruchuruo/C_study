/*
	
*/

#include "SeqList.h"

void 顺序表_接口实现_菜单()
{
	printf("******** ******** ******** ******** ********\n");
	printf("******** 1.头插              2.头删 ********\n");
	printf("******** 3.尾插              4.尾删 ********\n");
	printf("******** 5.查找              6.打印 ********\n");
	printf("******** 7.pos位置插入 8.pos位置删除 ********\n");
	printf("********           0.退出           ********\n");
	printf("******** ******** ******** ******** ********\n");
}

int main()
{
	SL sl;

	// 顺序表初始化
	SeqListInit(&sl);

	int 输入 = 1;
	int x;
	int pos;

	while (输入)
	{
		顺序表_接口实现_菜单();

		printf("选项>");
		scanf("%d", &输入);

		switch (输入)
		{
		case 1:
			printf("头插+L>");
			scanf("%d", &x);
			SeqListPushFront(&sl, x);
			break;
		case 2:
			printf("头删-L<\n");
			SeqListPopFront(&sl);
			break;
		case 3:
			printf("尾插L+>");
			scanf("%d", &x);
			SeqListPushBack(&sl, x);
			break;
		case 4:
			printf("尾删L-<\n");
			SeqListPopBack(&sl);
			break;
		case 5:
			printf("查找L?>");
			scanf("%d", &x);
			printf("下标为 %d\n", SeqListFind(&sl, x));
			break;
		case 6:
			SeqListPrint(&sl);
			break;
		case 7:
			printf("位置+L+>");
			scanf("%d", &pos);

			printf("值+L+>");
			scanf("%d", &x);

			SeqListInsert(&sl, pos, x);
			break;
		case 8:
			printf("位置-L->");
			scanf("%d", &pos);
			SeqListErase(&sl, pos);
			break;
		case 0:
			printf("退出\n");
			break;
		default:
			printf("输入错误\n");
			break;
		}
	}

	SeqListDestory(&sl);

	return 0;
}