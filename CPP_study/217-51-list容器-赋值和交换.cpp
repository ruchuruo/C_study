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

				3.7.3 list ��ֵ�ͽ���

					����������

						��list�������и�ֵ���Լ�����list����

					����ԭ�ͣ�

						assign(beg, end);                 //��[beg, end)�����е����ݿ�����ֵ������
						assign(n, elem);                  //��n��elem������ֵ������
						list& operator=(const list &lst); //���صȺŲ�����
						swap(lst);                        //��lst�뱾���Ԫ�ػ�����

					�ܽ᣺list��ֵ�ͽ��������ܹ�������ü���
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

// ��ֵ
void test01()
{
	list<int> l1;

	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);

	printList(l1);


	
	list<int> l2;
	list<int> l3;
	list<int> l4;

	// ��ֵ ���صȺŲ�����
	l2 = l1;

	//��[beg, end)�����е����ݿ�����ֵ������
	l3.assign(l1.begin(), l1.end());

	//��n��elem������ֵ������
	l4.assign(10, 666);

	printList(l2);
	printList(l3);
	printList(l4);
}

void test02()
{
	cout << endl;

	list<int> l1;
	list<int> l2;

	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);

	l2.assign(10, 999);

	cout << "����ǰ" << endl;
	printList(l1);
	printList(l2);

	cout << endl;

	//��lst�뱾���Ԫ�ػ�����
	l1.swap(l2);

	cout << "������" << endl;
	printList(l1);
	printList(l2);
}

int main()
{
	// ��ֵ
	test01();

	// ����
	test02();

	return 0;
}