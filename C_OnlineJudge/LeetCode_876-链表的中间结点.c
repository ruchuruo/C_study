
/*
	876. 链表的中间结点
	https://leetcode.cn/problems/middle-of-the-linked-list/description/

	给定一个头结点为 head 的非空单链表，返回链表的中间结点。
	如果有两个中间结点，则返回第二个中间结点。

	示例 1：
		输入：[1,2,3,4,5]
		输出：此列表中的结点 3 (序列化形式：[3,4,5])
		返回的结点值为 3 。 (测评系统对该结点序列化表述是 [3,4,5])。
		注意，我们返回了一个 ListNode 类型的对象 ans，这样：
		ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, 以及 ans.next.next.next = NULL.

	示例 2：
		输入：[1,2,3,4,5,6]
		输出：此列表中的结点 4 (序列化形式：[4,5,6])
		由于该列表有两个中间结点，值分别为 3 和 4，我们返回第二个结点。

	提示：
		给定链表的结点数介于 1 和 100 之间。
*/

#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode
{
	int val;
	struct ListNode *next;
};

struct ListNode* middleNode(struct ListNode* head)
{
	/*
		思路1：
			遍历一遍计算长度，长度除2

			再遍历一遍找到中间节点

			时间复杂度O(N)

		思路2：
			要求：只能遍历链表一次

			用双指针，快慢指针

				fast
				 ↓
				[1] → [2] → [3] → [4] → [5]
				 ↑
				slow

			快指针一次走2步，慢指针一次走1步

					        fast
				             ↓
				[1] → [2] → [3] → [4] → [5]
				       ↑
				      slow

			停止条件，fast 为 空 并且 fast->next 为 空
	*/

	// 思路2 快慢指针
	struct ListNode* fast = head;
	struct ListNode* slow = head;

	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
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

	struct ListNode* head = middleNode(n1);

	return 0;
}