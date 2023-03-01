
/*
	160. 相交链表 https://leetcode.cn/problems/intersection-of-two-linked-lists/description/

	难度：简单

	给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表不存在相交节点，返回 null 。

	图示两个链表在节点 c1 开始相交：

	A:        [a1] → [a2] ↘
							→ [c1] → [c2] → [c3]
	B: [b1] → [b2] → [b3] ↗

	题目数据 保证 整个链式结构中不存在环。

	注意，函数返回结果后，链表必须 保持其原始结构 。

	自定义评测：

		评测系统 的输入如下（你设计的程序 不适用 此输入）：

			● intersectVal - 相交的起始节点的值。如果不存在相交节点，这一值为 0
			● listA - 第一个链表
			● listB - 第二个链表
			● skipA - 在 listA 中（从头节点开始）跳到交叉节点的节点数
			● skipB - 在 listB 中（从头节点开始）跳到交叉节点的节点数

		评测系统将根据这些输入创建链式数据结构，并将两个头节点 headA 和 headB 传递给你的程序。如果程序能够正确返回相交节点，那么你的解决方案将被 视作正确答案 。


	示例 1：

		A:       [4] → [1] ↘
							 → [8] → [4] → [5]
		B: [5] → [6] → [1] ↗

		输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
		输出：Intersected at '8'
		解释：相交节点的值为 8 （注意，如果两个链表相交则不能为 0）。
		从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，链表 B 为 [5,6,1,8,4,5]。
		在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。
		— 请注意相交节点的值不为 1，因为在链表 A 和链表 B 之中值为 1 的节点 (A 中第二个节点和 B 中第三个节点) 是不同的节点。换句话说，它们在内存中指向两个不同的位置，而链表 A 和链表 B 中值为 8 的节点 (A 中第三个节点，B 中第四个节点) 在内存中指向相同的位置。
 

	示例 2：

		A: [1] → [9] → [1] ↘
							 → [2] → [4]
		B:             [3] ↗

		输入：intersectVal = 2, listA = [1,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
		输出：Intersected at '2'
		解释：相交节点的值为 2 （注意，如果两个链表相交则不能为 0）。
		从各自的表头开始算起，链表 A 为 [1,9,1,2,4]，链表 B 为 [3,2,4]。
		在 A 中，相交节点前有 3 个节点；在 B 中，相交节点前有 1 个节点。


	示例 3：

		A: [2] → [6] → [4]
							
		B:       [1] → [5]

		输入：intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
		输出：null
		解释：从各自的表头开始算起，链表 A 为 [2,6,4]，链表 B 为 [1,5]。
		由于这两个链表不相交，所以 intersectVal 必须为 0，而 skipA 和 skipB 可以是任意值。
		这两个链表不相交，因此返回 null 。
 

	提示：
		listA 中节点数目为 m
		listB 中节点数目为 n
		1 <= m, n <= 3 * 104
		1 <= Node.val <= 105
		0 <= skipA <= m
		0 <= skipB <= n
		如果 listA 和 listB 没有交点，intersectVal 为 0
		如果 listA 和 listB 有交点，intersectVal == listA[skipA] == listB[skipB]
 

	进阶：你能否设计一个时间复杂度 O(m + n) 、仅用 O(1) 内存的解决方案？
*/
/*
	简单来说：
		1. 判断两个链表是否相交。
		2. 相交返回交点。
*/

#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode
{
	int val;
	struct ListNode *next;
};

struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
{
	/*
		思路1：穷举
			依次取 A链表 中的每个节点和 B链表 中的所有节点比较，
			如果有地址相同的节点，就是相交，第一个相同的交点。

			时间复杂度：O(N^2)

		思路2：
			1. 尾节点相同就是相交，否则不相交。
			2. 求交点：长的链表先走 长度差 步，再同时走，第一个相同就是交点。
	*/

	// 思路2

	struct ListNode* tailA = headA;
	struct ListNode* tailB = headB;
	int lenA = 1;
	int lenB = 1;

	// 找尾 并记录 长度
	while (tailA->next)
	{
		tailA = tailA->next;
		lenA++;
	}

	while (tailB->next)
	{
		tailB = tailB->next;
		lenB++;
	}

	// 不相交
	if (tailA != tailB)
	{
		return NULL;
	}

	// 求差 绝对值，库函数int abs (int n);
	int gap = abs(lenA - lenB);

	// 长的先走差距步，再同时走找交点
	// 默认认为 A 长 B 短
	struct ListNode* longList = headA;
	struct ListNode* shortList = headB;

	// 判断谁长
	if (lenA < lenB)
	{
		shortList = headA;
		longList = headB;
	}

	// 长的先走差距步
	while (gap--)
	{
		longList = longList->next;
	}

	// 再同时走找交点
	while (longList != shortList)
	{
		longList = longList->next;
		shortList = shortList->next;
	}

	return longList;
}

int main()
{
	/*	======== ======== ======== C ======== ======== ========	*/
	struct ListNode* Cn1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* Cn2 = (struct ListNode*)malloc(sizeof(struct ListNode));

	Cn1->val = 7;
	Cn2->val = 7;

	Cn1->next = Cn2;
	Cn2->next = NULL;

	/*	======== ======== ======== A ======== ======== ========	*/
	struct ListNode* An1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* An2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* An3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* An4 = (struct ListNode*)malloc(sizeof(struct ListNode));

	An1->val = 7;
	An2->val = 7;
	An3->val = 7;
	An4->val = 7;

	An1->next = An2;
	An2->next = An3;
	An3->next = An4;
	An4->next = Cn1;

	/*	======== ======== ======== B ======== ======== ========	*/
	struct ListNode* Bn1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* Bn2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* Bn3 = (struct ListNode*)malloc(sizeof(struct ListNode));

	Bn1->val = 7;
	Bn2->val = 7;
	Bn3->val = 7;

	Bn1->next = Bn2;
	Bn2->next = Bn3;
	Bn3->next = Cn1;

	/*	****************************************************	*/

	struct ListNode* ret = getIntersectionNode(An1, Bn1);

	return 0;
}