
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

					����������

						ϴ�� ָ����Χ�ڵ�Ԫ�������������

					����ԭ�ͣ�

						random_shuffle(iterator beg, iterator end);
							// ָ����Χ�ڵ�Ԫ�������������
							// beg ��ʼ������
							// end ����������

					�ܽ᣺random_shuffleϴ���㷨�Ƚ�ʵ�ã�ʹ��ʱ�ǵü����������
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
	// ���������
	srand((unsigned int)time(NULL));

	vector<int> v;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	// ϴ��
	random_shuffle(v.begin(), v.end());

	// ���� ��ӡ
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;
}

int main()
{
	test01();

	return 0;
}