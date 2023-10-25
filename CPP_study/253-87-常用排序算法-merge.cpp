
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

				5.3.1 sort

				5.3.2 random_shuffle

				5.3.3 merge

					����������

						��������Ԫ�غϲ������洢����һ������

					����ԭ�ͣ�

						merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
						// ����Ԫ�غϲ������洢����һ������
						// ע��: �������������������
						// beg1 ����1��ʼ������
						// end1 ����1����������
						// beg2 ����2��ʼ������
						// end2 ����2����������
						// dest Ŀ��������ʼ������

					�ܽ᣺merge�ϲ�����������������������У��ϲ���ɺ�������
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
		v1.push_back(i);
		v2.push_back(i + 10);
	}

	// ����
	vTarget.resize(v1.size() + v2.size());

	// �ϲ�
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

	// ���� ��ӡ
	for_each(vTarget.begin(), vTarget.end(), myPrint);
	cout << endl;
}

int main()
{
	test01();

	return 0;
}