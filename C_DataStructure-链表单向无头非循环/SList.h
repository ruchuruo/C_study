#pragma once

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*=====================================================*/

//typedef int 数据类型;					// (SLTDateType)
//typedef struct 链表_单向不带头非循环		// (SListNode)
//{
//	数据类型 数据;						// (data)
//	struct 链表_单向不带头非循环* 下一个;	// (next)
//}链表单向不带头非循环;					// (SLTNode)

typedef int SLTDateType;
typedef struct SListNode
{
	SLTDateType data;
	struct SListNode* next;
}SLTNode;

/*=====================================================*/

// 动态申请一个节点
SLTNode* BuySListNode(SLTDateType x);

// 单链表打印
void SListPrint(SLTNode* phead);

// 单链表尾插
void SListPushBack(SLTNode** pphead, SLTDateType x);

// 单链表的头插
void SListPushFront(SLTNode** pplist, SLTDateType x);

// 单链表的尾删
void SListPopBack(SLTNode** pphead);

// 单链表头删
void SListPopFront(SLTNode** pphead);

// 单链表查找
SLTNode* SListFind(SLTNode* phead, SLTDateType x);

// 单链表在pos位置 之前 插入x
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDateType x);

// 单链表在pos位置 之后 插入x
void SListInsertAfter(SLTNode* pos, SLTDateType x);

// 单链表删除pos位置的节点
void SListErase(SLTNode** pphead, SLTNode* pos);

// 单链表删除pos位置 之后 的节点
void SListEraseAfter(SLTNode* pos);

// 单链表销毁
void SListDestroy(SLTNode** pphead);

/*
* 需要修改 plist 指向的才需要二级指针
*/
/*=====================================================*/