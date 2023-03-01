#pragma once

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>


/*
	头尾 删除 插入 可以复用 SeqListInsert() 和 SeqListErase()
*/

typedef int SLDataType;

// 顺序表的动态存储
typedef struct SeqList
{
	SLDataType* arr;// 指向动态开辟的数组
	int size;		// 有效数据个数
	int capacity;	// 容量空间的大小
}SL;


// 顺序表初始化
void SeqListInit(SL* psl);

// 顺序表销毁
void SeqListDestory(SL* psl);

// 顺序表打印
void SeqListPrint(SL* psl);

// 检查空间，如果满了，进行增容
void SeqListCheckCapacity(SL* psl);

// 顺序表尾插
void SeqListPushBack(SL* psl, SLDataType x);

// 顺序表尾删
void SeqListPopBack(SL* psl);

// 顺序表头插
void SeqListPushFront(SL* psl, SLDataType x);

// 顺序表头删
void SeqListPopFront(SL* psl);

// 顺序表查找
int SeqListFind(SL* psl, SLDataType x);

// 顺序表在pos位置插入x
void SeqListInsert(SL* psl, int pos, SLDataType x);

// 顺序表删除pos位置的值
void SeqListErase(SL* psl, size_t pos);