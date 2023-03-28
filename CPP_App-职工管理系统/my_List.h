#pragma once

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <iostream>
#include "worker.h"

/*======== ======== ======== ========*/

class EmpListNode
{
public:
	EmpListNode();
	~EmpListNode();

	// 获取next节点
	EmpListNode* getNextNode();

	// 获取worker数据
	Worker* getData();

	// 双向链表初始化
	EmpListNode* ListInit();

	// 双向链创建节点
	EmpListNode* BuyListNode(Worker* x);

	// 双向链表销毁
	void ListDestroy(EmpListNode* phead);

	// 双向链表打印
	void ListPrint(EmpListNode* phead);

	// 双向链表尾插
	void ListPushBack(EmpListNode* phead, Worker* x);

	// 双向链表尾删
	void ListPopBack(EmpListNode* phead);

	// 双向链表头插
	void ListPushFront(EmpListNode* phead, Worker* x);

	// 双向链表头删
	void ListPopFront(EmpListNode* phead);

	// 双向链表查找 按职工编号查找
	EmpListNode* ListFind(EmpListNode* phead, int x);

	// 双向链表查找 按姓名查找
	EmpListNode* ListFind(EmpListNode* phead, string x);

	// 双向链表在pos的前面进行插入
	void ListInsert(EmpListNode* pos, Worker* x);

	// 双向链表删除pos位置的节点
	void ListErase(EmpListNode* pos);

	// 双向链表冒泡排序
	void ListBubbleSort(EmpListNode* phead, int empNum);

private:
	int h;

	Worker* worker;

	int sort;// 排序，0小→大，1大→小

	EmpListNode* next;
	EmpListNode* prev;
};

/*======== ======== ======== ========*/