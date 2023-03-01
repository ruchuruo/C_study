
/*
	剑指offer_链表中倒数第k个结点
	https://www.nowcoder.com/practice/529d3ae5a407492994ad2a246518148a?tpId=13&&tqId=11167&rp=2&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking

	https://leetcode.cn/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/

	时间限制：C/C++ 1秒，其他语言 2秒
	空间限制：C/C++ 64M，其他语言 128M

	知识点：链表，双指针

	描述
		输入一个链表，输出该链表中倒数第k个结点。

		示例1
			输入：1,{1,2,3,4,5}
			返回值：{5}
*/

#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
	int val;
	struct ListNode *next;
};


/**
*
* @param pListHead ListNode类
* @param k int整型
* @return ListNode类
*/
struct ListNode* FindKthToTail(struct ListNode* pListHead, int k)
{
	// write code here

	/*
		思路1：
			快慢指针
			快指针先走k步
			慢指针 和 快指针 再一起走，快指针 == NULL 时，慢指针 就是倒数第k个

				fast
				 ↓
				[1] → [2] → [3] → [4] → [5]
				 ↑
				slow
	*/

	struct ListNode* fast = pListHead;// 快指针
	struct ListNode* slow = pListHead;// 慢指针
	int counter = 0;// 计数器

	while (fast)
	{
		if (counter >= k)
		{
			slow = slow->next;
		}

		fast = fast->next;
		counter++;
	}

	// k 大于 链表长度应该返回 空
	if (k > counter)
	{
		return NULL;
	}

	return slow;
}

int main()
{
	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n5 = (struct ListNode*)malloc(sizeof(struct ListNode));

	n1->val = 1;
	n2->val = 2;
	n3->val = 3;
	n4->val = 4;
	n5->val = 5;

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = NULL;

	struct ListNode* head = FindKthToTail(n1, 6);

	return 0;
}