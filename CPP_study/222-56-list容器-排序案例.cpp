
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

				3.7.8 ������

					������������Person�Զ����������ͽ�������Person�����������������䡢���

					������򣺰�����������������������ͬ������߽��н���

					�ܽ᣺

						�����Զ����������ͣ�����Ҫָ��������򣬷����������֪����ν�������

						�߼�����ֻ��������������ٽ���һ���߼������ƶ�����������
*/

#include <iostream>
#include <list>

using namespace std;

class Person
{
public:
	Person(string name, int age, int height)
	{
		m_Name = name;
		m_Age = age;
		m_Height = height;
	}

public:
	string m_Name;  //����
	int m_Age;      //����
	int m_Height;   //���
};

void printList(const list<Person>& l)
{
	for (list<Person>::const_iterator it = l.begin(); it != l.end(); it++)
	{
		cout << (*it).m_Name << " "
			<< (*it).m_Age << " "
			<< (*it).m_Height << " "
			<< endl;
	}
	cout << endl;
}


// ָ���������
bool ComparePerson(Person& p1, Person& p2)
{
	if (p1.m_Age == p2.m_Age)
	{
		return p1.m_Height > p2.m_Height;
	}
	else
	{
		return  p1.m_Age < p2.m_Age;
	}
}

void test01()
{
	list<Person> l;

	Person p1("����", 20, 100);
	Person p2("����", 30, 200);
	Person p3("����", 30, 300);
	Person p4("����", 50, 400);
	Person p5("����", 60, 500);

	l.push_back(p2);
	l.push_back(p1);
	l.push_back(p3);
	l.push_back(p5);
	l.push_back(p4);

	printList(l);

	// ����
	// �Զ����������� ��Ҫָ��������Ҫ�ص����� ���� �º���
	cout << "�����" << endl;

	l.sort(ComparePerson);

	printList(l);

}

int main()
{
	test01();

	return 0;
}