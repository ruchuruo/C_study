
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

				3.7.5 list �����ɾ��

				3.7.6 list ���ݴ�ȡ

				3.7.7 list ��ת������

					����������

						�������е�Ԫ�ط�ת���Լ��������е����ݽ�������

					����ԭ�ͣ�

						reverse(); //��ת����
						sort();    //��������

					�ܽ᣺

						��ת --- reverse
						���� --- sort ����Ա������
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

bool myCompare(int v1, int v2)
{
	// ���� v1 > v2
	return v1 > v2;
}

void test01()
{
	list<int> l;

	l.push_back(20);
	l.push_back(10);
	l.push_back(50);
	l.push_back(40);
	l.push_back(30);

	printList(l);

	//��ת����
	l.reverse();

	printList(l);

	//��������
	// ��֧��������ʵ����������� �����ñ�׼�㷨
	//sort(l.begin(), l.end());
	// ��֧��������ʵ����������� �ڲ����ṩ��Ӧ��һЩ�㷨
	l.sort();// Ĭ�ϴ�С���� ����

	printList(l);

	//�������� �Ӵ�С ����
	l.sort(myCompare);

	printList(l);
}

int main()
{
	test01();

	return 0;
}










/*
	�ײ����
		����ʦ����Ҳ���Ժ���
*/