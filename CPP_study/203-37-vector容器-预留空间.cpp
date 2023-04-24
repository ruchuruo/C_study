
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

				3.2.7 vector��������

				3.2.8 vectorԤ���ռ�

					����������

						����vector�ڶ�̬��չ����ʱ����չ����

					����ԭ�ͣ�

						reserve(int len);//����Ԥ��len��Ԫ�س��ȣ�Ԥ��λ�ò���ʼ����Ԫ�ز��ɷ��ʡ�

					�ܽ᣺����������ϴ󣬿���һ��ʼ����reserveԤ���ռ�
*/

#include <iostream>
#include <vector>

using namespace std;

void test01()
{
	vector<int> v;

	// ͳ�ƶ�̬��չ����
	int num = 0;
	int* p = NULL;

	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);

		// ͨ�� ���� �Ա� ��С ��ͳ����չ����
		//if (v.size() == v.capacity())
		//{
		//	num++;
		//}


		// ͨ��������ݵ� �׵�ַ ��ͳ����չ����
		if (p != &v[0])
		{
			p = &v[0];
			num++;
		}
	}

	cout << "v������ " << v.capacity() << endl;
	cout << "v�Ĵ�С " << v.size() << endl;
	cout << "��չ��" << num << endl;
}

// ���� reserve() Ԥ���ռ�
void test02()
{
	vector<int> v;

	v.reserve(100000);

	// ͳ�ƶ�̬��չ����
	int num = 0;
	int* p = NULL;

	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);

		// ͨ�� ���� �Ա� ��С ��ͳ����չ����
		//if (v.size() == v.capacity())
		//{
		//	num++;
		//}


		// ͨ��������ݵ� �׵�ַ ��ͳ����չ����
		if (p != &v[0])
		{
			p = &v[0];
			num++;
		}
	}

	cout << "v������ " << v.capacity() << endl;
	cout << "v�Ĵ�С " << v.size() << endl;
	cout << "��չ��" << num << endl;
}

int main()
{
	test01();

	// ���� reserve() Ԥ���ռ�
	test02();

	return 0;
}