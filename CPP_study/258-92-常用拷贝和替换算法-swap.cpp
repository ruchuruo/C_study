
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

				5.4.1 copy

				5.4.2 replace

				5.4.3 replace_if

				5.4.4 swap

					����������

						��������������Ԫ��

					����ԭ�ͣ�

						swap(container c1, container c2);
							// ��������������Ԫ��
							// c1����1
							// c2����2

					�ܽ᣺swap��������ʱ��ע�⽻��������Ҫͬ������
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

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 10);
	}

	// ���� ��ӡ
	for_each(v1.begin(), v1.end(), myPrint);
	cout << endl;

	// ����
	swap(v1, v2);

	// ���� ��ӡ
	for_each(v1.begin(), v1.end(), myPrint);
	cout << endl;
}

int main()
{
	test01();

	return 0;
}