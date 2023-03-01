
/*
	面试题 02.04. 分割链表 https://leetcode.cn/problems/partition-list-lcci/

	难度：中等

	给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。

	你不需要 保留 每个分区中各节点的初始相对位置。

	示例 1：
		
		[1] → [4] → [3] → [2] → [5] → [2]
						↓
		[1] → [2] → [2] → [4] → [3] → [5]

		输入：head = [1,4,3,2,5,2], x = 3
		输出：[1,2,2,4,3,5]

	示例 2：
		输入：head = [2,1], x = 2
		输出：[1,2]

	提示：
		链表中节点的数目在范围 [0, 200] 内
		-100 <= Node.val <= 100
		-200 <= x <= 200
*/

#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode
{
	int val;
	struct ListNode *next;
};

struct ListNode* partition(struct ListNode* head, int x)
{
	/*
		思路1：
			输入：head = [2,3,5,1,7,2], x = 4
			输出：       [2,1,3,2,5,7]

			创建新链表
				头 newhead
				尾 newtail

			小于 4 的值 头插到 新链表
			大于等于 4 的值 尾插到 新链表

		思路2：
			要求：相对顺序不变
			输入：head = [2,3,5,1,7,2], x = 4
			输出：       [2,3,1,2,5,7]

			创建新链表
				较小的 less
				头 lessHead
				尾 lessTail
			
			创建新链表
				更大的 greater
				头 greaterHead
				尾 greaterTail

			遍历 原链表

			小于 4 的尾插到 less
				2,3,1,2

			大于等于 4 的 尾插到 greater
				5,7

			最后合并链表
				less      greater
				[2,3,1,2]→[5,7]


			详细过程

			初始状态

				x = 4

				cur
				 ↓
				[2] → [3] → [5] → [1] → [7] → [2]

				lessHead
				lessTail
				↓
				[哨兵位]

				greaterHead
				greaterTail
				↓
				[哨兵位]
			
			原链表 cur 小于 x，lessTail->next 指向 cur，cur 往后走，lessTail = lessTail->next

				x = 4

				      cur
				       ↓
				[2] → [3] → [5] → [1] → [7] → [2]

				lessHead
				↓           lessTail
				↓           ↓
				[哨兵位] → [2]

				greaterHead
				greaterTail
				↓
				[哨兵位]

			原链表 cur 大于 x，greaterTail->next 指向 cur，cur 往后走，greaterTail = greaterTail->next

				x = 4

					              cur
					               ↓
				[2] → [3] → [5] → [1] → [7] → [2]

				lessHead
				↓                lessTail
				↓                 ↓
				[哨兵位] → [2] → [3]

				greaterHead
				↓          greaterTail
				↓           ↓
				[哨兵位] → [5]
	*/

	// 思路2

	struct ListNode* lessHead;
	struct ListNode* lessTail;
	struct ListNode* greaterHead;
	struct ListNode* greaterTail;
	struct ListNode* cur = head;
	
	// 开一个哨兵位头节点，方便尾插
	lessHead = lessTail = (struct ListNode*)malloc(sizeof(struct ListNode));
	greaterHead = greaterTail = (struct ListNode*)malloc(sizeof(struct ListNode));

	lessTail->next = NULL;
	greaterTail->next = NULL;

	// 遍历 原链表
	while (cur)
	{
		// 原链表 cur 小于 x，lessTail->next 指向 cur，cur 往后走，lessTail = lessTail->next
		if (cur->val < x)
		{
			lessTail->next = cur;
			lessTail = lessTail->next;
		}
		else
		{
			greaterTail->next = cur;
			greaterTail = greaterTail->next;
		}

		cur = cur->next;
	}

	// 合并链表
	lessTail->next = greaterHead->next;

	// 必须置空，不然链表死循环
	greaterTail->next = NULL;

	// 释放 哨兵位 之前，newHead 记录 lessTail->next
	struct ListNode* newHead = lessHead->next;

	// 释放 哨兵位
	free(lessHead);
	free(greaterHead);

	// 
	return newHead;
}

int main()
{
	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n5 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n6 = (struct ListNode*)malloc(sizeof(struct ListNode));

	n1->val = 1;
	n2->val = 4;
	n3->val = 3;
	n4->val = 2;
	n5->val = 5;
	n6->val = 2;

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = NULL;

	struct ListNode* head = partition(n1, 3);

	return 0;
}