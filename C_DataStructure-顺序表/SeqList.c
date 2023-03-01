
#include "SeqList.h"

// 基本增删查改接口
// 顺序表初始化
void SeqListInit(SL* psl)
{
	psl->arr = NULL;
	psl->size = 0;
	psl->capacity = 0;
}

// 顺序表销毁
void SeqListDestory(SL* psl)
{
	free(psl->arr);
	psl->arr = NULL;
	psl->size = 0;
	psl->capacity = 0;
}

// 顺序表打印
void SeqListPrint(SL* psl)
{
	int i = 0;
	for (i = 0; i < psl->size; i++)
	{
		printf("%d ", psl->arr[i]);
	}
	printf("\n");
}

// 检查空间，如果满了，进行增容
void SeqListCheckCapacity(SL* psl)
{
	// 判断空间是否充足
	if (psl->size == psl->capacity)
	{
		// 空间不足 扩容
		// 扩容2倍适中，但是0*2还是0
		// int 新capacity = psl->capacity == 0 ? 4 : psl->capacity * 2;
		// 
		// void* realloc (void* ptr, size_t size);
		// 库函数realloc，如果ptr是NULL，就和 库函数malloc 功能一样。
		if (psl->capacity == 0)
		{
			int 新capacity = 4;

			//SLDataType* tmp = (SLDataType*)realloc(psl->arr, 新capacity);
			// 参数 size_t size 是字节，所以要乘一个类型
			SLDataType* tmp = (SLDataType*)realloc(psl->arr, 新capacity * sizeof(SLDataType));
			if (tmp == NULL)
			{
				printf("无法扩容\n");
				exit(-1);
			}

			// 扩容成功
			psl->arr = tmp;
			psl->capacity = 新capacity;

		}
		else
		{
			int 新capacity = psl->capacity * 2;

			//SLDataType* tmp = (SLDataType*)realloc(psl->arr, 新capacity);
			// 参数 size_t size 是字节，所以要乘一个类型
			SLDataType* tmp = (SLDataType*)realloc(psl->arr, 新capacity * sizeof(SLDataType));
			if (tmp == NULL)
			{
				printf("无法扩容\n");
				exit(-1);
			}

			// 扩容成功
			psl->arr = tmp;
			psl->capacity = 新capacity;
		}
	}
}

// 顺序表尾插
void SeqListPushBack(SL* psl, SLDataType x)
{
	SeqListCheckCapacity(psl);

	// 插入数据
	psl->arr[psl->size] = x;
	psl->size++;
}

// 顺序表尾删
void SeqListPopBack(SL* psl)
{
	if (psl->size > 0)
	{
		// 减减后 就访问不到后面的数据
		psl->size--;
	}
}

// 顺序表头插
void SeqListPushFront(SL* psl, SLDataType x)
{
	/*
		把数据从后往前 逐个 向后移动一位
			[1][2][3][4][5]
						end
						 →
			[1][2][3][4][ ][5]
			 →
			[ ][1][2][3][4][5]
	*/

	SeqListCheckCapacity(psl);

	// 移动前 最后一个数据的下标
	int end = psl->size - 1;

	// 移动数据
	while (end >= 0)
	{
		psl->arr[end + 1] = psl->arr[end];
		end--;
	}

	// 插入数据
	psl->arr[0] = x;
	psl->size++;
}

// 顺序表头删
void SeqListPopFront(SL* psl)
{
	/*
		把第二个数据开始 逐个 向前移动一位
		[1][2][3][4][5]
		   begin
		    ←
		[2][ ][3][4][5]
		             ←
		[2][3][4][5][ ]
	*/

	if (psl->size > 0)
	{
		// 移动前 第二个数据的下标
		int begin = 1;

		// 移动数据
		while (begin < psl->size)
		{
			psl->arr[begin - 1] = psl->arr[begin];
			begin++;
		}

		// 减减后 就访问不到后面的数据
		psl->size--;
	}
}

// 顺序表查找
int SeqListFind(SL* psl, SLDataType x)
{
	// 遍历一遍查找
	int i = 0;
	for (i = 0; i < psl->size; i++)
	{
		if (psl->arr[i] == x)
		{
			return i;
		}
	}

	return -1;
}

// 顺序表在pos位置插入x
void SeqListInsert(SL* psl, int pos, SLDataType x)
{
	/*
		      pos   end
		       ↓     ↓
		[0][1][2][3][4]
	*/

	// 判断是否越界
	if (pos > psl->size || pos < 0)
	{
		return;
	}

	SeqListCheckCapacity(psl);

	int end = psl->size - 1;

	// 移动数据
	while (end >= pos)
	{
		psl->arr[end + 1] = psl->arr[end];
		end--;
	}

	// 插入数据
	psl->arr[pos] = x;
	psl->size++;
}

// 顺序表删除pos位置的值
void SeqListErase(SL* psl, size_t pos)
{
	/*
		      pos
		       ↓
		[0][1][2][3][4]
		          ↑
		        begin
	*/

	// 判断是否越界
	if (pos >= psl->size || pos < 0)
	{
		return;
	}

	int begin = pos + 1;
	while (begin < psl->size)
	{
		psl->arr[begin - 1] = psl->arr[begin];
		begin++;
	}

	psl->size--;
}