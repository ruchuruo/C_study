
/*
	21. 合并两个有序链表 https://leetcode.cn/problems/merge-two-sorted-lists/description/

	将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。

	示例 1：
		[1] → [2] → [4]
		[1] → [3] → [4]
		---------------
		[1] → [1] → [2] → [3] → [4] → [4]

		输入：l1 = [1,2,4], l2 = [1,3,4]
		输出：[1,1,2,3,4,4]

	示例 2：
		输入：l1 = [], l2 = []
		输出：[]

	示例 3：
		输入：l1 = [], l2 = [0]
		输出：[0]

	提示：
		两个链表的节点数目范围是 [0, 50]
		-100 <= Node.val <= 100
		l1 和 l2 均按 非递减顺序 排列
*/

#include <stdio.h>
#include <stdlib.h>

//Definition for singly-linked list.
struct ListNode
{
	int val;
	struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
	/*
		思路1：
			依次比较链表中的节点，每次取小的节点，尾插到新链表即可

			多定义一个指针 tail

				 l1
				 ↓
				[1] → [2] → [2]

				 l2
				 ↓
				[1] → [3] → [4]

				head
				tail
				 ↓
				NULL

			比较 l1 和 l2，将 l1 拿下，给 head 和 tail，l1 往后走

				       l1
				       ↓
				[1] → [2] → [2]

				 l2
				 ↓
				[1] → [3] → [4]

				head
				tail
				 ↓
				[1] → 

			比较 l1 和 l2，将 l2 拿下，给 tail 的后面，变成新的 tail ，l2 往后走

					   l1
					   ↓
				[1] → [2] → [2]

				       l2
				       ↓
				[1] → [3] → [4]

				head
				 ↓    tail
				 ↓     ↓
				[1] → [1] → 

			比较 l1 和 l2，将 l1 拿下，给 tail 的后面，变成新的 tail ，l1 往后走

					         l1
					         ↓
				[1] → [2] → [2]

					   l2
					   ↓
				[1] → [3] → [4]

				head
				 ↓          tail
				 ↓           ↓
				[1] → [1] → [2] → 

			比较 l1 和 l2，将 l1 拿下，给 tail 的后面，变成新的 tail ，l1 往后走，l1 为空

							       l1
							       ↓
				[1] → [2] → [2] → NULL

					   l2
					   ↓
				[1] → [3] → [4]

				head
				 ↓                tail
				 ↓                 ↓
				[1] → [1] → [2] → [2]

			当其中一个为空，将剩下的给 tail 的后面，结束

								   l1
								   ↓
				[1] → [2] → [2] → NULL

					   l2
					   ↓
				[1] → [3] → [4]

				head
				 ↓                tail
				 ↓                 ↓
				[1] → [1] → [2] → [2] → [3] → [4]
	*/

	// 其中一个为空，返回另外一个
	if (list1 == NULL)
	{
		return list2;
	}

	if (list2 == NULL)
	{
		return list1;
	}

	struct ListNode* head = NULL;
	struct ListNode* tail = NULL;

	while (list1 && list2)// 循环 继续的条件
	{
		if (list1->val < list2->val)
		{
			// 判断是否是第一次尾插
			if (head == NULL)
			{
				head = list1;
				tail = list1;
			}
			else
			{
				tail->next = list1;
				tail = tail->next;
			}

			// 往后走
			list1 = list1->next;
		}
		else
		{
			// 判断是否是第一次尾插
			if (head == NULL)
			{
				head = list2;
				tail = list2;
			}
			else
			{
				tail->next = list2;
				tail = tail->next;
			}

			// 往后走
			list2 = list2->next;
		}
	}

	// 将剩下的给 tail 的后面
	if (list1)
	{
		tail->next = list1;
	}

	if (list2)
	{
		tail->next = list2;
	}

	return head;
}

struct ListNode* mergeTwoLists2(struct ListNode* list1, struct ListNode* list2)
{
	/*
		思路1 优化：
			依次比较链表中的节点，每次取小的节点，尾插到新链表即可

			多定义一个指针 tail

				 l1
				 ↓
				[1] → [2] → [2]

				 l2
				 ↓
				[1] → [3] → [4]

				head
				tail
				 ↓
				NULL

			比较 l1 和 l2，将 l1 拿下，给 head 和 tail，l1 往后走

					   l1
					   ↓
				[1] → [2] → [2]

				 l2
				 ↓
				[1] → [3] → [4]

				head
				tail
				 ↓
				[1] →

			比较 l1 和 l2，将 l2 拿下，给 tail 的后面，变成新的 tail ，l2 往后走

					   l1
					   ↓
				[1] → [2] → [2]

					   l2
					   ↓
				[1] → [3] → [4]

				head
				 ↓    tail
				 ↓     ↓
				[1] → [1] →

			比较 l1 和 l2，将 l1 拿下，给 tail 的后面，变成新的 tail ，l1 往后走

							 l1
							 ↓
				[1] → [2] → [2]

					   l2
					   ↓
				[1] → [3] → [4]

				head
				 ↓          tail
				 ↓           ↓
				[1] → [1] → [2] →

			比较 l1 和 l2，将 l1 拿下，给 tail 的后面，变成新的 tail ，l1 往后走，l1 为空

								   l1
								   ↓
				[1] → [2] → [2] → NULL

					   l2
					   ↓
				[1] → [3] → [4]

				head
				 ↓                tail
				 ↓                 ↓
				[1] → [1] → [2] → [2]

			当其中一个为空，将剩下的给 tail 的后面，结束

								   l1
								   ↓
				[1] → [2] → [2] → NULL

					   l2
					   ↓
				[1] → [3] → [4]

				head
				 ↓                tail
				 ↓                 ↓
				[1] → [1] → [2] → [2] → [3] → [4]
	*/

	// 其中一个为空，返回另外一个
	if (list1 == NULL)
	{
		return list2;
	}

	if (list2 == NULL)
	{
		return list1;
	}

	// 
	struct ListNode* head = NULL;
	struct ListNode* tail = NULL;

	// 先取一个小的做第一个节点
	if (list1->val < list2->val)
	{
		head = list1;
		tail = list1;
		list1 = list1->next;
	}
	else
	{
		head = list2;
		tail = list2;
		list2 = list2->next;
	}

	// 
	while (list1 && list2)// 循环 继续的条件
	{
		if (list1->val < list2->val)
		{
			tail->next = list1;
			tail = tail->next;

			// 往后走
			list1 = list1->next;
		}
		else
		{
			tail->next = list2;
			tail = tail->next;

			// 往后走
			list2 = list2->next;
		}
	}

	// 将剩下的给 tail 的后面
	if (list1)
	{
		tail->next = list1;
	}

	if (list2)
	{
		tail->next = list2;
	}

	return head;
}

struct ListNode* mergeTwoLists3(struct ListNode* list1, struct ListNode* list2)
{
	/*
		思路1 哨兵位的头节点：

				 l1
				 ↓
				[1] → [2] → [2]

				 l2
				 ↓
				[1] → [3] → [4]

				head
				tail
				 ↓
				[ ]
	*/

	// 其中一个为空，返回另外一个
	if (list1 == NULL)
	{
		return list2;
	}

	if (list2 == NULL)
	{
		return list1;
	}

	// 
	struct ListNode* head = NULL;
	struct ListNode* tail = NULL;

	// 哨兵位的头节点
	head = tail = (struct ListNode*)malloc(sizeof(struct ListNode));

	// 
	while (list1 && list2)// 循环 继续的条件
	{
		if (list1->val < list2->val)
		{
			tail->next = list1;
			tail = tail->next;

			// 往后走
			list1 = list1->next;
		}
		else
		{
			tail->next = list2;
			tail = tail->next;

			// 往后走
			list2 = list2->next;
		}
	}

	// 将剩下的给 tail 的后面
	if (list1)
	{
		tail->next = list1;
	}

	if (list2)
	{
		tail->next = list2;
	}

	// 先保存头
	struct ListNode* list = head->next;

	// 释放
	free(head);

	return list;
}

int main()
{
	struct ListNode* l1n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* l1n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* l1n3 = (struct ListNode*)malloc(sizeof(struct ListNode));

	struct ListNode* l2n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* l2n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* l2n3 = (struct ListNode*)malloc(sizeof(struct ListNode));

	l1n1->val = 1;
	l1n2->val = 2;
	l1n3->val = 4;

	l2n1->val = 1;
	l2n2->val = 3;
	l2n3->val = 4;

	l1n1->next = l1n2;
	l1n2->next = l1n3;
	l1n3->next = NULL;

	l2n1->next = l2n2;
	l2n2->next = l2n3;
	l2n3->next = NULL;

	struct ListNode* ret = mergeTwoLists(l1n1, l2n1);	// 思路1：依次比较链表中的节点，每次取小的节点，尾插到新链表即可

	struct ListNode* ret2 = mergeTwoLists2(l1n1, l2n1);	// 思路1：优化

	struct ListNode* ret3 = mergeTwoLists3(l1n1, l2n1);	// 思路1：哨兵位的头节点

	return 0;
}