
/*
	136. ֻ����һ�ε����� https://leetcode.cn/problems/single-number/

	�Ѷȣ���

		����һ�� �ǿ� �������� nums ������ĳ��Ԫ��ֻ����һ�����⣬����ÿ��Ԫ�ؾ��������Ρ��ҳ��Ǹ�ֻ������һ�ε�Ԫ�ء�

		�������Ʋ�ʵ������ʱ�临�Ӷȵ��㷨����������⣬�Ҹ��㷨ֻʹ�ó�������ռ䡣

 
		ʾ�� 1 ��
			���룺nums = [2,2,1]
			�����1

		ʾ�� 2 ��
			���룺nums = [4,1,2,1,2]
			�����4

		ʾ�� 3 ��
			���룺nums = [1]
			�����1


		��ʾ��
			1 <= nums.length <= 3 * 104
			-3 * 104 <= nums[i] <= 3 * 104
			����ĳ��Ԫ��ֻ����һ�����⣬����ÿ��Ԫ�ؾ��������Ρ�
*/
/*
    ˼·��
        �������� ����ѭ��

        ��ѭ������ҵ���ͬ������ count++

        ��ѭ��������鿴�Ƿ��� count Ϊ 1 ������
*/

#include <stdio.h>

int singleNumber(int* nums, int numsSize)
{
    if (nums == NULL)
    {
        return;
    }

    // �������� ����ѭ��
    int i = 0;
    int j = 0;
    int count = 0;// ������

    for (i = 0; i < numsSize; i++)
    {
        count = 0;

        for (j = 0; j < numsSize; j++)
        {
            if (nums[i] == nums[j])
            {
                count++;
            }
        }

        printf("%d\n", count);

        if (count == 1)
        {
            printf("�ҵ� %d\n", nums[i]);

            return nums[i];
        }
    }

    return 666;
}

int main()
{

    return 0;
}