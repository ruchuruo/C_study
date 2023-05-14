
/*
	202. ������ https://leetcode.cn/problems/happy-number/description/

	�Ѷȣ���

		��дһ���㷨���ж�һ���� n �ǲ��ǿ�������

		���������� ����Ϊ��

			����һ����������ÿһ�ν������滻Ϊ��ÿ��λ���ϵ����ֵ�ƽ���͡�
			Ȼ���ظ��������ֱ���������Ϊ 1��Ҳ������ ����ѭ�� ��ʼ�ձ䲻�� 1��
			���������� ���Ϊ 1����ô��������ǿ�������
		
		��� n �� ������ �ͷ��� true �����ǣ��򷵻� false ��


		ʾ�� 1��
			���룺n = 19
			�����true
			���ͣ�
			1*1 + 9*9 = 82
			8*8 + 2*2 = 68
			6*6 + 8*8 = 100
			1*1 + 0*0 + 0*0 = 1

		ʾ�� 2��
			���룺n = 2
			�����false
 

		��ʾ��
			1 <= n <= 231 - 1
*/
/*
    ��ʮ��λ�£�100���ڵĿ������У�OEIS�е�����A00770�� ��1, 7, 10, 13, 19, 23, 28, 31, 32, 44, 49, 68, 70, 79, 82, 86, 91, 94, 97, 100��

    ˼·��
        �������� v
        �������� vRecord
        ���� num �洢 ƽ�� �� ��� �Ľ��

        ����v������¼��ֳ����ĸ�λ��
        ����vRecord������¼ÿ�� ƽ�� �� ��� �Ľ��

        ÿ��ѭ������ȥ ����vRecord ���� �Ƿ��к� num ��ͬ�����֣�����У�˵������ѭ�������ǿ�����
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isHappy(int n)
    {
        vector<int> v;
        vector<int> vRecord;// ��¼ÿ�� ƽ�� �� ��� �Ľ��
        int num = 0;// �洢 ƽ�� �� ��� �Ľ��

        while (num != 1)
        {
            while (n >= 1)
            {
                v.push_back(n % 10);

                n /= 10;
            }

            for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
            {

                num += (*it) * (*it);
            }

            if (num == 1)
            {
                // �� ������
                return true;
            }

            for (vector<int>::iterator it = vRecord.begin(); it != vRecord.end(); it++)
            {
                // ����
                if ((*it) == num)
                {
                    // ���� ������
                    return false;
                }
            }

            n = num;
            vRecord.push_back(num);
            num = 0;
            v.clear();
        }

        return false;// ���õķ���
    }
};

int main()
{
    Solution s;
    s.isHappy(3);

    return 0;
}