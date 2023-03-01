
/*
	138. 复制带随机指针的链表 https://leetcode.cn/problems/copy-list-with-random-pointer/description/

	难度：中等

	给你一个长度为 n 的链表，每个节点包含一个额外增加的随机指针 random ，该指针可以指向链表中的任何节点或空节点。

	构造这个链表的 深拷贝。 深拷贝应该正好由 n 个 全新 节点组成，其中每个新节点的值都设为其对应的原节点的值。
	新节点的 next 指针和 random 指针也都应指向复制链表中的新节点，并使原链表和复制链表中的这些指针能够表示相同的链表状态。
	复制链表中的指针都不应指向原链表中的节点 。

	例如，如果原链表中有 X 和 Y 两个节点，其中 X.random --> Y 。那么在复制链表中对应的两个节点 x 和 y ，同样有 x.random --> y 。

	返回复制链表的头节点。

	用一个由 n 个节点组成的链表来表示输入/输出中的链表。每个节点用一个 [val, random_index] 表示：

	● val：一个表示 Node.val 的整数。
	● random_index：随机指针指向的节点索引（范围从 0 到 n-1）；如果不指向任何节点，则为  null 。

	你的代码 只 接受原链表的头节点 head 作为传入参数。



	示例 1：

		输入：head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
		输出：[[7,null],[13,0],[11,4],[10,2],[1,0]]

	示例 2：

		输入：head = [[1,1],[2,1]]
		输出：[[1,1],[2,1]]

	示例 3：

		输入：head = [[3,null],[3,0],[3,null]]
		输出：[[3,null],[3,0],[3,null]]


	提示：
		● 0 <= n <= 1000
		● -104 <= Node.val <= 104
		● Node.random 为 null 或指向链表中的节点。
*/

#include <stdlib.h>

// Definition for a Node.
struct Node
{
	int val;
	struct Node *next;
	struct Node *random;
};


struct Node* copyRandomList(struct Node* head)
{
	/*
		思路1：
			计算 原链表 节点 的 random 和当前 节点 的相对距离，
			在 新链表 中用相对距离找 random。

			时间复杂度 O(N ^ 2)

		思路2：
			复制节点，插入到 原节点 和 下一个节点 之间

				[[7,null],          [13,0],       [11,4],       [10,2],       [1,0]],       NULL
				↓
				[[7,null],[[7,    ],[13,0],[13, ],[11,4],[11, ],[10,2],[10, ],[1,0] ,[1, ]],NULL

			根据原节点的random，处理复制节点的random，
			原节点的random是空，复制节点的random是空，

				[[7,null],          [13,0],       [11,4],       [10,2],       [1,0]],       NULL
				↓
				[[7,null],[[7,null],[13,0],[13, ],[11,4],[11, ],[10,2],[10, ],[1,0] ,[1, ]],NULL
				  ↑                  ↑      ↑
				cur.random          cur    cur.next

				cur.next.random = cur.random.next

			最后，将 复制节点 拼接成 新链表，恢复原链表

			时间复杂度 O(3N)
	*/

	// 思路2
	
	// 复制节点，插入到 原节点 和 下一个节点 之间
	struct Node* cur = head;

	while (cur)
	{
		struct Node* copyNode = (struct Node*)malloc(sizeof(struct Node));

		// 复制
		copyNode->val = cur->val;

		// 插入
		copyNode->next = cur->next;
		cur->next = copyNode;

		// cur 往后走
		cur = copyNode->next;
	}


	// 根据原节点的random，处理复制节点的random
	cur = head;

	while (cur)
	{
		struct Node* copyNode = cur->next;

		if (cur->random == NULL)
		{
			copyNode->random = NULL;
		}
		else
		{
			copyNode->random = cur->random->next;
		}

		cur = copyNode->next;
	}


	// 最后，将 复制节点 拼接成 新链表，恢复原链表
	struct Node* copyHead = NULL;
	struct Node* copyTail = NULL;
	cur = head;

	while (cur)
	{
		struct Node* copyNode = cur->next;
		struct Node* next = copyNode->next;

		if (copyTail == NULL)
		{
			copyHead = copyNode;
			copyTail = copyNode;
		}
		else
		{
			// 尾插
			copyTail->next = copyNode;
			copyTail = copyTail->next;
		}

		// 恢复原链表
		cur->next = next;
		cur = cur->next;
	}

	return copyHead;

}

int main()
{
	struct Node* n1 = (struct Node*)malloc(sizeof(struct Node));
	struct Node* n2 = (struct Node*)malloc(sizeof(struct Node));
	struct Node* n3 = (struct Node*)malloc(sizeof(struct Node));
	struct Node* n4 = (struct Node*)malloc(sizeof(struct Node));
	struct Node* n5 = (struct Node*)malloc(sizeof(struct Node));

	n1->val = 7;
	n2->val = 13;
	n3->val = 11;
	n4->val = 10;
	n5->val = 1;

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = NULL;

	n1->random = NULL;
	n2->random = n1;
	n3->random = n5;
	n4->random = n3;
	n5->random = n1;

	struct Node* head = copyRandomList(n1);

	return 0;
}