
/*
	��1�׶�C++ ����֮�� ��0��1����

	��2�׶�ʵս-ͨѶ¼����

	��3�׶�-C++���ı��

	��4�׶�ʵս-���ڶ�̬����ҵְ��ϵͳ

	��5�׶�-C++��߱��

		1 ģ��

		2 STL��ʶ

			2.1 STL�ĵ���

			2.2 STL��������

			2.3 STL�������

			2.4 STL���������㷨��������

			2.5 �����㷨��������ʶ

				2.5.1 vector���������������

				2.5.2 Vector����Զ�����������

					ѧϰĿ�꣺vector�д���Զ����������ͣ�����ӡ���
*/

#include <iostream>
#include <vector>   // ���� vector ��ͷ�ļ�

using namespace std;

class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

public:
	string m_Name;
	int m_Age;
};



// ����Զ�����������
void test01()
{
	vector<Person> v;

	Person p1("����", 10);
	Person p2("����", 20);
	Person p3("����", 30);
	Person p4("����", 40);
	Person p5("����", 50);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	// ����
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout
			<< "���� " << (*it).m_Name << " "
			<< "���� " << it->m_Age
			<< 
		endl;

		/*
			it ��ָ�룬�����ú���<>������� Person
		*/
	}

	cout << endl;
}



// ����Զ����������� �� ָ��
void test02()
{
	vector<Person*> v;

	Person p1("����", 10);
	Person p2("����", 20);
	Person p3("����", 30);
	Person p4("����", 40);
	Person p5("����", 50);

	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);

	// ����
	for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout
			<< "���� " << (*(*it)).m_Name << " "
			<< "���� " << (*it)->m_Age
			<<
		endl;

		/*
			it ��ָ�룬�����ú���<>������� Person*
		*/
	}
}



int main()
{
	// ����Զ�����������
	test01();

	// ����Զ����������� �� ָ��
	test02();

	return 0;
}