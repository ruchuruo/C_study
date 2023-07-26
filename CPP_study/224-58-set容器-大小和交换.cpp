
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

					����������

						ͳ��set������С�Լ�����set����

					����ԭ�ͣ�

						size();   //����������Ԫ�ص���Ŀ
						empty();  //�ж������Ƿ�Ϊ��
						swap(st); //����������������

					�ܽ᣺

						ͳ�ƴ�С     --- size
						�ж��Ƿ�Ϊ�� --- empty
						��������     --- swap
*/

#include <iostream>
#include <set>

using namespace std;

void printSet(set<int>& s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

// ͳ�ƴ�С
// �ж��Ƿ�Ϊ��
void test01()
{
	set<int> s;

	s.insert(10);
	s.insert(20);
	s.insert(30);
	s.insert(40);

	printSet(s);

	// �ж��Ƿ�Ϊ��
	if (s.empty())
	{
		cout << "��" << endl;
	}
	else
	{
		cout << "����" << endl;

		// ͳ�ƴ�С
		cout << "��С " << s.size() << endl;
	}
}

// ��������
void test02()
{
	cout << endl;

	set<int> s1;
	set<int> s2;

	s1.insert(1);
	s1.insert(2);
	s1.insert(3);
	s1.insert(4);
	s2.insert(10);
	s2.insert(20);
	s2.insert(30);
	s2.insert(40);

	cout << "����ǰ" << endl;
	printSet(s1);
	printSet(s2);

	// ��������
	s1.swap(s2);

	cout << "������" << endl;
	printSet(s1);
	printSet(s2);
}



int main()
{
	// ͳ�ƴ�С
	// �ж��Ƿ�Ϊ��
	test01();

	// ��������
	test02();

	return 0;
}