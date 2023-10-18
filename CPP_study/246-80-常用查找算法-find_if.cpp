
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

					����������

						����������Ԫ��

					����ԭ�ͣ�

						find_if(iterator beg, iterator end, _Pred);
							// ��ֵ����Ԫ�أ��ҵ�����ָ��λ�õ��������Ҳ������ؽ���������λ��
							// beg   ��ʼ������
							// end   ����������
							// _Pred ��������ν�ʣ�����bool���͵ķº�����

					�ܽ᣺
						find_if����������ʹ���Ҹ������ṩ�ķº������Ըı䲻ͬ�Ĳ���

						���Ե�Ļ��
							find �Ǿ������, find_if ����������.
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

	string m_Name;
	int m_Age;
};

// ν��1
class Greater5
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};

// ν��2
class Greater20
{
public:
	bool operator()(Person& val)
	{
		return val.m_Age > 20;
	}
};

// ������������
void test01()
{
	vector<int> v;

	// ��������
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	// ���Ҵ���5����
	vector<int>::iterator it =
		find_if(v.begin(), v.end(), Greater5());

	// �ж��Ƿ��ҵ�
	if (it == v.end())
	{
		cout << "δ�ҵ�" << endl;
	}
	else
	{
		cout << *it << endl;
	}
}

// �Զ�����������
void test02()
{
	vector<Person> v;

	// ��������
	Person p1("a", 10);
	Person p2("b", 20);
	Person p3("c", 30);
	Person p4("d", 40);

	// ��������
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	// ���������20����
	vector<Person>::iterator it =
		find_if(v.begin(), v.end(), Greater20());

	// �ж��Ƿ��ҵ�
	if (it == v.end())
	{
		cout << "δ�ҵ�" << endl;
	}
	else
	{
		cout << (*it).m_Name << " " << (*it).m_Age << endl;
	}
}

int main()
{
	// ������������
	test01();

	// �Զ�����������
	test02();

	return 0;
}