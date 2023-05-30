
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

				3.7.4 list ��С����

					����������

						��list�����Ĵ�С���в���

					����ԭ�ͣ�

						size();            //����������Ԫ�صĸ���

						empty();           //�ж������Ƿ�Ϊ��

						resize(num);       //����ָ�������ĳ���Ϊnum���������䳤������Ĭ��ֵ�����λ�á�
										   //���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����

						resize(num, elem); //����ָ�������ĳ���Ϊnum���������䳤������elemֵ�����λ�á�
										   //���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����

					�ܽ᣺

						�ж��Ƿ�Ϊ�� --- empty
						����Ԫ�ظ��� --- size
						����ָ������ --- resize
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
	list<int> l1;

	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);

	printList(l1);

	//�ж������Ƿ�Ϊ��
	if (l1.empty())
	{
		cout << "l1Ϊ��" << endl;
	}
	else
	{
		cout << "l1��Ϊ��" << endl;
	}

	//����������Ԫ�صĸ���
	cout << "l1Ԫ�ظ�����" << l1.size() << endl;

	//����ָ�������ĳ���Ϊnum���������䳤������Ĭ��ֵ�����λ�á�
	l1.resize(10);
	printList(l1);

	//����ָ�������ĳ���Ϊnum���������䳤������elemֵ�����λ�á�
	l1.resize(15, 666);
	printList(l1);

	//���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
	l1.resize(3);
	printList(l1);
}

int main()
{
	test01();

	return 0;
}