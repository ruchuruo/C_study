
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

				3.6.1 queue ��������

				3.6.2 queue ���ýӿ�

					����������ջ�������õĶ���ӿ�

					���캯����

						queue<T> que;                       //queue����ģ����ʵ�֣�queue�����Ĭ�Ϲ�����ʽ
						queue(const queue &que);            //�������캯��

					��ֵ������

						queue& operator=(const queue &que); //���صȺŲ�����

					���ݴ�ȡ��

						push(elem);                         //����β���Ԫ��
						pop();                              //�Ӷ�ͷ�Ƴ���һ��Ԫ��
						back();                             //�������һ��Ԫ��
						front();                            //���ص�һ��Ԫ��

					��С������

						empty();                            //�ж϶�ջ�Ƿ�Ϊ��
						size();                             //����ջ�Ĵ�С

					�ܽ᣺

						���          --- push
						����          --- pop
						���ض�ͷԪ��   --- front
						���ض�βԪ��   --- back
						�ж϶��Ƿ�Ϊ�� --- empty
						���ض��д�С   --- size
*/

#include <iostream>
#include <queue>

using namespace std;


class Person
{
public:
	Person(string name, int age):m_Name(name), m_Age(age) {}
public:
	string m_Name;
	int m_Age;
};


void test01()
{
	queue<Person> q;

	// ׼������
	Person p1("��һ", 20);
	Person p2("�¶�", 30);
	Person p3("����", 40);
	Person p4("����", 50);

	// ���
	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);

	cout << "���д�С " << q.size() << endl;

	// �ж϶��в�Ϊ�գ��鿴��ͷ �� ��β��Ȼ�����
	while (!q.empty())
	{
		cout << "��ͷ��" << q.front().m_Name << " " << q.front().m_Age << endl;

		cout << "��β��" << q.back().m_Name << " " << q.back().m_Age << endl;

		q.pop();
	}

	cout << "���д�С " << q.size() << endl;
}

int main()
{
	test01();

	return 0;
}