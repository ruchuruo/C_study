
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

			3.3 deque����

			3.4 ����-��ί���

			3.5 stack����

			3.6 queue ����

			3.7 list����

			3.8 set/ multiset ����

				3.8.1 set��������

				3.8.2 set����͸�ֵ

				3.8.3 set��С�ͽ���

				3.8.4 set�����ɾ��

				3.8.5 set���Һ�ͳ��

				3.8.6 set��multiset����

					ѧϰĿ�꣺

						����set��multiset������

					����

						set�����Բ����ظ����ݣ���multiset����
						set�������ݵ�ͬʱ�᷵�ز���������ʾ�����Ƿ�ɹ�
						multiset���������ݣ���˿��Բ����ظ�����

					�ܽ᣺

						�������������ظ����ݿ�������set
						�����Ҫ�����ظ���������multiset

					pair�ǽ�2��������ϳ�һ�����ݣ�����Ҫ����������ʱ�Ϳ���ʹ��pair��
					��stl�е�map���ǽ�key��value����һ�������档
					��һ��Ӧ���ǣ���һ��������Ҫ����2�����ݵ�ʱ�򣬿���ѡ��pair��
					pair��ʵ����һ���ṹ�壬��Ҫ��������Ա������first second ��Ϊ��ʹ��struct����class��
					���Կ���ֱ��ʹ��pair�ĳ�Ա������
*/

#include <iostream>
#include <set>

using namespace std;

void test01()
{
	// set
	set<int> s;

	pair<set<int>::iterator, bool> ret = s.insert(10);

	if (ret.second)
	{
		cout << "����ɹ�" << endl;
	}
	else
	{
		cout << "����ʧ��" << endl;
	}

	ret = s.insert(10);

	if (ret.second)
	{
		cout << "����ɹ�" << endl;
	}
	else
	{
		cout << "����ʧ��" << endl;
	}



	// multiset
	multiset<int> ms;

	ms.insert(10);
	ms.insert(10);

	for (multiset<int>::iterator it = ms.begin(); it != ms.end(); it++)
	{
		cout << *it << endl;

	}
	cout << endl;
}

int main()
{
	test01();

	return 0;
}