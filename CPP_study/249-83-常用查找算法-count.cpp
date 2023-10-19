
/*
	��1�׶�C++ ����֮�� ��0��1����

	��2�׶�ʵս-ͨѶ¼����

	��3�׶�-C++���ı��

	��4�׶�ʵս-���ڶ�̬����ҵְ��ϵͳ

	��5�׶�-C++��߱��

		1 ģ��

		2 STL��ʶ

		3 STL- ��������

		4 STL- ��������

		5 STL- �����㷨

			5.1 ���ñ����㷨

			5.2 ���ò����㷨

				5.2.1 find

				5.2.2 find_if

				5.2.3 adjacent_find

				5.2.4 binary_search

				5.2.5 count

					����������

						ͳ��Ԫ�ظ���

					����ԭ�ͣ�

						count(iterator beg, iterator end, value);
							// ͳ��Ԫ�س��ִ���
							// beg   ��ʼ������
							// end   ����������
							// value ͳ�Ƶ�Ԫ��

					�ܽ᣺ ͳ���Զ�����������ʱ����Ҫ������� operator==
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// �Զ�����������
class Person
{
public:
	Person(string name, int age) :m_Name(name), m_Age(age) {}

	// ���ط���==����count֪����ζԱȣ�ʹ��const��ֹ���ݱ��޸ģ�����const���벻ͨ��
	bool operator==(const Person& p)
	{
		if (this->m_Age == p.m_Age)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	string m_Name;
	int m_Age;
};

// ������������
void test01()
{
	vector<int> v;

	v.push_back(10);
	v.push_back(40);
	v.push_back(30);
	v.push_back(40);
	v.push_back(20);
	v.push_back(40);

	// ͳ��40�ĸ���
	int num =
		count(v.begin(), v.end(), 40);

	cout << num << endl;
}

// �Զ�����������
void test02()
{
	vector<Person> v;

	// ��������
	Person p1("����", 10);
	Person p2("����", 10);
	Person p3("�ŷ�", 10);
	Person p4("����", 20);
	Person p5("�ܲ�", 30);

	// �������
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	// ���������p6��ͬ������
	Person p6("�����", 30);

	int num =
		count(v.begin(), v.end(), p6);

	cout << num << endl;
}

int main()
{
	// ������������
	test01();

	// �Զ�����������
	test02();

	return 0;
}