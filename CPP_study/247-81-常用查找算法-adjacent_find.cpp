
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

					����������

						���������ظ�Ԫ��

					����ԭ�ͣ�

						adjacent_find(iterator beg, iterator end);
							// ���������ظ�Ԫ��,�ҵ���������Ԫ�صĵ�һ��λ�õĵ��������Ҳ������ؽ���������λ��
							// beg ��ʼ������
							// end ����������

					�ܽ᣺��������������ֲ��������ظ�Ԫ�أ��ǵ���STL�е�adjacent_find�㷨
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void test01()
{
	vector<int> v;

	v.push_back(0);
	v.push_back(2);
	v.push_back(0);
	v.push_back(5);
	v.push_back(1);
	v.push_back(4);
	v.push_back(3);
	v.push_back(3);

	// ����
	vector<int>::iterator it =
		adjacent_find(v.begin(), v.end());

	// �ж��Ƿ��ҵ�
	if (it == v.end())
	{
		cout << "δ�ҵ�" << endl;
	}
	else
	{
		cout << *it << endl;
	}
}

int main()
{
	test01();

	return 0;
}