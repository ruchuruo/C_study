
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

					����������

						��list���������ݽ��д�ȡ

					����ԭ�ͣ�

						front(); //���ص�һ��Ԫ�ء�
						back();  //�������һ��Ԫ�ء�

					�ܽ᣺

						list�����в�����ͨ��[]����at��ʽ��������
						���ص�һ��Ԫ��   --- front
						�������һ��Ԫ�� --- back
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
	list<int> l;

	l.push_back(10);
	l.push_back(20);
	l.push_back(30);
	l.push_back(40);

	// list�����в�����ͨ��[]����at��ʽ��������
	//l[0];
	//l.at();

	cout << "��һ��Ԫ�� " << l.front() << endl;
	cout << "���һ��Ԫ�� " << l.back() << endl;

	// ��֤�������Ƿ�֧���������
	list<int>::iterator it = l.begin();
	it++;// ֧��˫��
	it--;// ֧��˫��
	//it + 1;// ��֧���������
}

int main()
{
	test01();

	return 0;
}