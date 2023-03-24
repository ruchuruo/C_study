#pragma once

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int LTDataType;

typedef struct ListNode
{
	LTDataType data;
	struct ListNode* next;
	struct ListNode* prev;
}ListNode;

// 双向链表初始化
ListNode* ListInit();

// 双向链创建节点
ListNode* BuyListNode(LTDataType x);

// 创建返回链表的头结点.
//ListNode* ListCreate();

// 双向链表销毁
void ListDestroy(ListNode* phead);

// 双向链表打印
void ListPrint(ListNode* phead);

// 双向链表尾插
void ListPushBack(ListNode* phead, LTDataType x);

// 双向链表尾删
void ListPopBack(ListNode* phead);

// 双向链表头插
void ListPushFront(ListNode* phead, LTDataType x);

// 双向链表头删
void ListPopFront(ListNode* phead);

// 双向链表查找
ListNode* ListFind(ListNode* phead, LTDataType x);

// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x);

// 双向链表删除pos位置的节点
void ListErase(ListNode* pos);