
/*
	��1�׶�C++ ����֮�� ��0��1����

	��2�׶�ʵս-ͨѶ¼����

	��3�׶�-C++���ı��

	��4�׶�ʵս-���ڶ�̬����ҵְ��ϵͳ

	��5�׶�-C++��߱��

		1 ģ��

		2 STL��ʶ

			2.1 STL�ĵ���

			2.2 STL��������

			2.3 STL�������

			2.4 STL���������㷨��������

			2.5 �����㷨��������ʶ

				2.5.1 vector���������������

				2.5.2 Vector����Զ�����������

				2.5.3 Vector����Ƕ������

					ѧϰĿ�꣺������Ƕ�����������ǽ��������ݽ��б������

					�����ƶ�ά����
						[1][2][3][4][5]
						[1][2][3][4][5]
						[1][2][3][4][5]
						[1][2][3][4][5]
*/

#include <iostream>
#include <vector>   // ���� vector ��ͷ�ļ�

using namespace std;

void test01()
{
	// ������
	vector<vector<int>> V;

	// С����
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<int> v4;

	// �� С���� ����� ����
	for (int i = 0; i < 5; i++)
	{
		v1.push_back(i + 1);
		v2.push_back(i + 2);
		v3.push_back(i + 3);
		v4.push_back(i + 4);
	}

	// �� ������ ����� С����
	V.push_back(v1);
	V.push_back(v2);
	V.push_back(v3);
	V.push_back(v4);

	// ������������
	for (vector<vector<int>>::iterator it = V.begin(); it != V.end(); it++)
	{
		// (*it) == vector<int>
		for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++)
		{
			cout << (*vit) << " ";
		}

		cout << endl;
	}
}

int main()
{
	test01();

	return 0;
}