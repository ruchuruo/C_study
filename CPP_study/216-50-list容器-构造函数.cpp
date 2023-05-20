
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

				3.7.1 list��������

				3.7.2 list���캯��

					����������

						����list����

					����ԭ�ͣ�

						list<T> lst;           //list���ò���ģ����ʵ��,�����Ĭ�Ϲ�����ʽ��
						list(beg,end);         //���캯����[beg, end)�����е�Ԫ�ؿ���������
						list(n,elem);          //���캯����n��elem����������
						list(const list &lst); //�������캯����

					�ܽ᣺list���췽ʽͬ��������STL�����������������ռ���
*/

#include <iostream>
#include <list>

using namespace std;

void printList(const list<int>& l)
{
	for (list<int>::const_iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	// �����Ĭ�Ϲ�����ʽ
	list<int> l1;

	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);

	// ����
	printList(l1);

	//���캯����[beg, end)�����е�Ԫ�ؿ���������
	list<int> l2(l1.begin(), l1.end());
	printList(l2);

	//�������캯����
	list<int> l3(l2);
	printList(l3);

	//���캯����n��elem����������
	list<int> l4(10, 666);
	printList(l4);
}

int main()
{
	test01();

	return 0;
}