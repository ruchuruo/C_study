
/*
	169. ����Ԫ�� https://leetcode.cn/problems/majority-element/

	�Ѷȣ���

		����һ����СΪ n ������ nums ���������еĶ���Ԫ�ء�����Ԫ����ָ�������г��ִ��� ���� ( n/2 ) ��Ԫ�ء�

		����Լ��������Ƿǿյģ����Ҹ������������Ǵ��ڶ���Ԫ�ء�


		ʾ�� 1��
			���룺nums = [3,2,3]
			�����3

		ʾ�� 2��
			���룺nums = [2,2,1,1,1,2,2]
			�����2


		��ʾ��
			n == nums.length
			1 <= n <= 5 * 104
			-109 <= nums[i] <= 109


		���ף��������ʱ�临�Ӷ�Ϊ O(n)���ռ临�Ӷ�Ϊ O(1) ���㷨��������⡣
*/
/*
	˼·��
		�� nums ��Ԫ�طŵ� ˳��� �в���
		�Ҳ��� ����ӵ� ˳���
		�ҵ� �ͽ���� nums ��Ԫ���� ˳��� �ڳ��ֵĴ���++

		��� ����̨ �ҳ����ִ�������Ԫ��
*/

#include <stdio.h>
#include <stdlib.h>

struct element
{
	int m_Val;// ֵ
	int m_Num;// ����
};

struct SeqList
{
	struct element* m_ElmArr;
	int m_Size;
	int m_Capacity;
};



void SeqListInit(struct SeqList* psl);                  // ˳����ʼ��
void SeqListPushBack(struct SeqList* psl, int x);       // ˳���β��
struct element* SeqListFind(struct SeqList* psl, int x);// ˳������

// ˳����ʼ��
void SeqListInit(struct SeqList* psl)
{
	psl->m_ElmArr = (struct element*)malloc(sizeof(struct element) * 50000);
	psl->m_Size = 0;
	psl->m_Capacity = 50000;
}

// ˳���β��
void SeqListPushBack(struct SeqList* psl, int val)
{
	psl->m_ElmArr[psl->m_Size].m_Val = val;
	psl->m_ElmArr[psl->m_Size].m_Num = 1;
	psl->m_Size++;
}

// ˳������ ֵ
struct element* SeqListFind(struct SeqList* psl, int val)
{
	for (int i = 0; i < psl->m_Size; i++)
	{
		if (psl->m_ElmArr[i].m_Val == val)
		{
			return &psl->m_ElmArr[i];
		}
	}

	return NULL;
}



int majorityElement(int* nums, int numsSize)
{
	struct SeqList sl;

	SeqListInit(&sl);// ˳����ʼ��

	for (int i = 0; i < numsSize; i++)
	{
		struct element* ret = SeqListFind(&sl, nums[i]);// ˳������

		// û�������
		if (ret == NULL)
		{
			SeqListPushBack(&sl, nums[i]);// ˳���β��
		}
		else
		{
			// �������++
			ret->m_Num++;
		}
	}

	// �ҵ�������������
	int numMax = 0;
	struct element* elmMax = NULL;

	for (int i = 0; i < sl.m_Size; i++)
	{
		if (sl.m_ElmArr[i].m_Num > numMax)
		{
			numMax = sl.m_ElmArr[i].m_Num;
			elmMax = &sl.m_ElmArr[i];
		}
	}

	return elmMax->m_Val;
}

int main()
{

	return 0;
}