
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

				5.2.1 find

				5.2.2 find_if

				5.2.3 adjacent_find

				5.2.4 binary_search

					����������

						����ָ��Ԫ���Ƿ����

					����ԭ�ͣ�

						bool binary_search(iterator beg, iterator end, value);
							// ����ָ����Ԫ�أ��鵽 ����true ����false
							// ע��: �����������в�����
							// beg   ��ʼ������
							// end   ����������
							// value ���ҵ�Ԫ��

					�ܽ᣺���ֲ��ҷ�����Ч�ʺܸߣ�ֵ��ע����ǲ��ҵ�������Ԫ�ر������������
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void test01()
{
	vector<int> v;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	// ����9
	bool ret =
		binary_search(v.begin(), v.end(), 9);

	// �ж��Ƿ��ҵ�
	if (ret == false)
	{
		cout << "δ�ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ�" << endl;
	}
}

int main()
{
	test01();

	return 0;
}