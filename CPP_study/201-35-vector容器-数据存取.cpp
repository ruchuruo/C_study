
/*
	��1�׶�C++ ����֮�� ��0��1����

	��2�׶�ʵս-ͨѶ¼����

	��3�׶�-C++���ı��

	��4�׶�ʵս-���ڶ�̬����ҵְ��ϵͳ

	��5�׶�-C++��߱��

		1 ģ��

		2 STL��ʶ

		3 STL- ��������

			3.1 string����

			3.2 vector����

				3.2.1 vector��������

				3.2.2 vector���캯��

				3.2.3 vector��ֵ����

				3.2.4 vector�����ʹ�С

				3.2.5 vector�����ɾ��

				3.2.6 vector���ݴ�ȡ

					����������

						��vector�е����ݵĴ�ȡ����

					����ԭ�ͣ�

						at(int idx); //��������idx��ָ������
						operator[];  //��������idx��ָ������
						front();     //���������е�һ������Ԫ��
						back();      //�������������һ������Ԫ��

					�ܽ᣺

						�����õ�������ȡvector������Ԫ�أ�[ ]��atҲ����
						front����������һ��Ԫ��
						back�����������һ��Ԫ��
*/

#include <iostream>
#include <vector>

using namespace std;

void test01()
{
	vector<int> v1;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}

	// at(int idx); //��������idx��ָ������
	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1.at(i) << " ";
	}
	cout << endl;

	// operator[];  //��������idx��ָ������
	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;

	// front();     //���������е�һ������Ԫ��
	cout << v1.front() << endl;

	// back();      //�������������һ������Ԫ��
	cout << v1.back() << endl;
}

int main()
{
	test01();

	return 0;
}