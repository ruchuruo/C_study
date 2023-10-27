
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

				5.5.1 accumulate

				5.5.2 fill

					����������

						�����������ָ����Ԫ��

					����ԭ�ͣ�

						fill(iterator beg, iterator end, value);
							// �����������Ԫ��
							// beg   ��ʼ������
							// end   ����������
							// value ����ֵ

					�ܽ᣺����fill���Խ�����������Ԫ�����Ϊ ָ����ֵ
*/

#include <iostream>
#include <numeric>
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

	// ����
	v.resize(10);

	// ���� ��ӡ
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;

	// ���999
	fill(v.begin(), v.end(), 999);

	// ���� ��ӡ
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;
}

int main()
{
	test01();

	return 0;
}