
/*
	��1�׶�C++ ����֮�� ��0��1����

	��2�׶�ʵս-ͨѶ¼����

	��3�׶�-C++���ı��

	��4�׶�ʵս-���ڶ�̬����ҵְ��ϵͳ

	��5�׶�-C++��߱��

		1 ģ��

			1.1 ģ��ĸ���

			1.2 ����ģ��

			1.3 ��ģ��

				1.3.1 ��ģ���﷨

				1.3.2 ��ģ���뺯��ģ������

				1.3.3 ��ģ���г�Ա��������ʱ��

				1.3.4 ��ģ���������������

				1.3.5 ��ģ����̳�

				1.3.6 ��ģ���Ա��������ʵ��

					ѧϰĿ�꣺�ܹ�������ģ���еĳ�Ա��������ʵ��

					�ܽ᣺��ģ���г�Ա��������ʵ��ʱ����Ҫ����ģ������б�
*/

#include <iostream>

using namespace std;

//��ģ���г�Ա��������ʵ��
template<class T1, class T2>
class Person
{
public:
	//��Ա������������
	Person(T1 name, T2 age);
	void showPerson();

public:
	T1 m_Name;
	T2 m_Age;
};

//���캯�� ����ʵ��
template<class T1, class T2>// ���� template �� T1 T2 �� Person(T1 name, T2 age) �����е� T1 T2
Person<T1, T2>::Person(T1 name, T2 age)// ���� Person<T1, T2> �� T1 T2 �Ǹ��߱���������ģ���г�Ա��������ʵ�֣�û�� <T1, T2> ������ͨ���г�Ա��������ʵ��
{
	this->m_Name = name;
	this->m_Age = age;
}

//��Ա���� ����ʵ��
template<class T1, class T2>// ��Ȼ��Ա������û���õ� T1 T2�������������ģ���г�Ա����
void Person<T1, T2>::showPerson()
{
	cout << "����: " << this->m_Name << " ����:" << this->m_Age << endl;
}

void test01()
{
	Person<string, int> p("Tom", 20);
	p.showPerson();
}

int main()
{
	test01();

	return 0;
}