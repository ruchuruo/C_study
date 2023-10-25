
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

				5.3.4 reverse

					����������

						��������Ԫ�ؽ��з�ת

					����ԭ�ͣ�
						reverse(iterator beg, iterator end);
						// ��תָ����Χ��Ԫ��
						// beg ��ʼ������
						// end ����������

					�ܽ᣺reverse��ת������Ԫ�أ�����������漰��
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

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	for_each(v.begin(), v.end(), myPrint);
	cout << endl;

	// ��ת
	reverse(v.begin(), v.end());

	for_each(v.begin(), v.end(), myPrint);
	cout << endl;
}

int main()
{
	test01();

	return 0;
}