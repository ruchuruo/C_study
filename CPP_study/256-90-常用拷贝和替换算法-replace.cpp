
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

					����������

						��������ָ����Χ�ľ�Ԫ���޸�Ϊ��Ԫ��

					����ԭ�ͣ�

						replace(iterator beg, iterator end, oldvalue, newvalue);
							// �������ھ�Ԫ�� �滻�� ��Ԫ��
							// beg      ��ʼ������
							// end      ����������
							// oldvalue ��Ԫ��
							// newvalue ��Ԫ��

					�ܽ᣺replace���滻����������������Ԫ��
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// �º���
struct MyPrint
{
	void operator()(int val)
	{
		cout << val << " ";
	}
};

void test01()
{
	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(10);
	v.push_back(40);
	v.push_back(10);
	v.push_back(60);
	v.push_back(10);
	v.push_back(80);

	// ���� ��ӡ
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;

	// ��10�滻��999
	replace(v.begin(), v.end(), 10, 999);

	// ���� ��ӡ
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;
}

int main()
{
	test01();

	return 0;
}