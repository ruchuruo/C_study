
/*
	��1�׶�C++ ����֮�� ��0��1����

	��2�׶�ʵս-ͨѶ¼����

	��3�׶�-C++���ı��

	��4�׶�ʵս-���ڶ�̬����ҵְ��ϵͳ

	��5�׶�-C++��߱��

		1 ģ��

		2 STL��ʶ

		3 STL- ��������

		4 STL- ��������

		5 STL- �����㷨

			5.1 ���ñ����㷨

			5.2 ���ò����㷨

			5.3 ���������㷨

			5.4 ���ÿ������滻�㷨

				ѧϰĿ�꣺

					���ճ��õĿ������滻�㷨

				�㷨��飺

					copy       // ������ָ����Χ��Ԫ�ؿ�������һ������
					replace    // ��������ָ����Χ�ľ�Ԫ���޸�Ϊ��Ԫ��
					replace_if // ������ָ����Χ����������Ԫ���滻Ϊ��Ԫ��
					swap       // ��������������Ԫ��

				5.4.1 copy

					����������
					
						������ָ����Χ��Ԫ�ؿ�������һ������

					����ԭ�ͣ�

						copy(iterator beg, iterator end, iterator dest);
						// ��ֵ����Ԫ�أ��ҵ�����ָ��λ�õ��������Ҳ������ؽ���������λ��
						// beg  ��ʼ������
						// end  ����������
						// dest Ŀ����ʼ������

					�ܽ᣺����copy�㷨�ڿ���ʱ��Ŀ�������ǵ���ǰ���ٿռ�
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void myPrint(int val)
{
	cout << val << " ";
}

void test01()
{
	vector<int> v;
	vector<int> vTarget;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	// ����
	vTarget.resize(v.size());

	// ����
	copy(v.begin(), v.end(), vTarget.begin());

	// ���� ��ӡ
	for_each(vTarget.begin(), vTarget.end(), myPrint);
	cout << endl;
}

int main()
{
	test01();

	return 0;
}