
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

				ѧϰĿ�꣺

					���ճ��õ����������㷨

				ע�⣺

					���������㷨����С���㷨��ʹ��ʱ������ͷ�ļ�Ϊ #include <numeric>

				�㷨��飺

					accumulate // ��������Ԫ���ۼ��ܺ�
					fill       // �����������Ԫ��

				5.5.1 accumulate

					����������

						���������� ����Ԫ���ۼ��ܺ�

					����ԭ�ͣ�

						accumulate(iterator beg, iterator end, value);
							// ��������Ԫ���ۼ��ܺ�
							// beg   ��ʼ������
							// end   ����������
							// value ��ʼֵ(��ʼ�ۼ�ֵ)

					�ܽ᣺accumulateʹ��ʱͷ�ļ�ע���� numeric������㷨��ʵ��
*/

#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

void test01()
{
	vector<int> v;

	for (int i = 0; i <= 100; i++)
	{
		v.push_back(i);
	}

	// �����ܺ�

	int ret =
		accumulate(v.begin(), v.end(), 0);

	cout << ret << endl;
}

int main()
{
	test01();

	return 0;
}