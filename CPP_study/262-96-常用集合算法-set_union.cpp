
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

			5.5 �������������㷨

			5.6 ���ü����㷨

				5.6.1 set_intersection

				5.6.2 set_union

					����������

						���������ϵĲ���

						|   v1 [0][1][2][3][4][5 ][6 ][7 ][8 ][9 ]
						|   v2 [5][6][7][8][9][10][11][12][13][14]
						|
						|   v1��v2�Ľ���(�ظ�Ԫ��      ) [5][6][7][8][9]
						|   v1��v2�Ĳ���(���ظ�Ԫ�غϲ�) [0][1][2][3][4][5 ][6 ][7 ][8 ][9 ][10][11][12][13][14]

					����ԭ�ͣ�

						set_union(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
							// ���������ϵĲ���
							// ע��:�������ϱ�������������
							// beg1 ����1��ʼ������
							// end1 ����1����������
							// beg2 ����2��ʼ������
							// end2 ����2����������
							// dest Ŀ��������ʼ������

					�ܽ᣺

						�󲢼����������ϱ������������
						Ŀ���������ٿռ���Ҫ�����������
						set_union����ֵ���ǲ��������һ��Ԫ�ص�λ��
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
	vector<int> v1;
	vector<int> v2;
	vector<int> vTarget;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);     // 0 ~ 9
		v2.push_back(i + 5); // 5 ~ 14
	}

	// Ŀ����������
	// �����������������û����ͬ����
	// ���ݵ�����������Ӵ�С
	vTarget.resize(v1.size() + v2.size());

	// �󲢼�
	vector<int>::iterator itEnd =
		set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

	// ���� ��ӡ
	for_each(vTarget.begin(), itEnd, myPrint);
	cout << endl;
}

int main()
{
	test01();

	return 0;
}