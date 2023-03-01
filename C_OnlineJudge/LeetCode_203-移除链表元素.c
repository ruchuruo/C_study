
/*
	给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。

	示例 1：
		(1) → (2) → (6) → (3) → (4) → (5) → (6)
				↓
		(1) → (2) → (3) → (4) → (5)

		输入：head = [1,2,6,3,4,5,6], val = 6
		输出：[1,2,3,4,5]

	示例 2：
		输入：head = [], val = 1
		输出：[]

	示例 3：
		输入：head = [7,7,7,7], val = 7
		输出：[]

	提示：
		列表中的节点数目在范围 [0, 104] 内
		1 <= Node.val <= 50
		0 <= val <= 50
*/

#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode
{
	int val;
	struct ListNode *next;
};

struct ListNode* removeElements(struct ListNode* head, int val)
{
	/*
		思路

			需要找到 被删除节点 的 前一个节点
					 prev   cur
					   ↓     ↓
				(1) → (2) → (6) → (3) → (4) → (5) → (6)

			找不到，往后走

			找到，将cur->next给prev->next，再释放空间，cur 继续往后走

			如果是头删，head指向下一个节点，再释放空间，再 cur = head，再继续往后走
	*/

	struct ListNode* prev = NULL;
	struct ListNode* cur = head;

	while (cur)
	{
		if (cur->val == val)
		{
			// 判断是否头删
			if (cur == head)
			{
				head = cur->next;
				free(cur);
				cur = head;
			}
			else// 不是头删
			{
				// 先让 prev->next 指向 cur->next
				prev->next = cur->next;

				// 删除
				free(cur);

				// 继续往后走
				cur = prev->next;
			}
		}
		else
		{
			// 继续往后走
			prev = cur;
			cur = cur->next;
		}
	}

	return head;
}

int main()
{
	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));

	n1->val = 7;
	n2->val = 7;
	n3->val = 7;
	n4->val = 7;

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = NULL;

	struct ListNode* head = removeElements(n1, 7);

	return 0;
}