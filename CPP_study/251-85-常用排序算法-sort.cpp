
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

				ѧϰĿ�꣺

					���ճ��õ������㷨

				�㷨��飺

					sort           // ��������Ԫ�ؽ�������
					random_shuffle // ϴ�� ָ����Χ�ڵ�Ԫ�������������
					merge          // ����Ԫ�غϲ������洢����һ������
					reverse        // ��תָ����Χ��Ԫ��

				5.3.1 sort

					����������

						��������Ԫ�ؽ�������

					����ԭ�ͣ�

						sort(iterator beg, iterator end, _Pred);
						// ��ֵ����Ԫ�أ��ҵ�����ָ��λ�õ��������Ҳ������ؽ���������λ��
						// beg   ��ʼ������
						// end   ����������
						// _Pred ν��

					�ܽ᣺sort���ڿ�������õ��㷨֮һ������������
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

	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(20);
	v.push_back(40);

	// ���� ����
	sort(v.begin(), v.end());

	// ���� ��ӡ
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;


	// ���� ���� ��ϵ�º���greater<T>
	sort(v.begin(), v.end(), greater<int>());

	// ���� ��ӡ
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;
}

int main()
{
	test01();

	return 0;
}