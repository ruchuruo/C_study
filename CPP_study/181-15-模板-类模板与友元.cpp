
/*
	��1�׶�C++ ����֮�� ��0��1����

	��2�׶�ʵս-ͨѶ¼����

	��3�׶�-C++���ı��

	��4�׶�ʵս-���ڶ�̬����ҵְ��ϵͳ

	��5�׶�-C++��߱��
		
		���׶���Ҫ���C++ ���ͱ�� �� STL ��������ϸ���⣬̽��C++������ʹ��

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

				1.3.7 ��ģ����ļ���д

				1.3.8 ��ģ������Ԫ

					ѧϰĿ�꣺

						������ģ�������Ԫ���������ں�����ʵ��

					ȫ�ֺ�������ʵ�� - ֱ��������������Ԫ����

					ȫ�ֺ�������ʵ�� - ��Ҫ��ǰ�ñ�����֪��ȫ�ֺ����Ĵ���

					�ܽ᣺����ȫ�ֺ���������ʵ�֣��÷��򵥣����ұ���������ֱ��ʶ��
*/

#include <iostream>

using namespace std;

//2��ȫ�ֺ��������Ԫ  ����ʵ�� - ��������ģ���������·���������ģ�嶨�壬������Ԫ
template<class T1, class T2> class Person;

//��������˺���ģ�壬���Խ�ʵ��д�����棬������Ҫ��ʵ����д�����ǰ���ñ�������ǰ����
//template<class T1, class T2> void printPerson2(Person<T1, T2> & p); 

template<class T1, class T2>
void printPerson2(Person<T1, T2>& p)
{
	cout << "����ʵ�� ---- ������ " << p.m_Name << " ���䣺" << p.m_Age << endl;
}



template<class T1, class T2>
class Person
{
	//1��ȫ�ֺ��������Ԫ   ����ʵ��
	friend void printPerson(Person<T1, T2>& p)
	{
		cout << "������ " << p.m_Name << " ���䣺" << p.m_Age << endl;
	}


	//ȫ�ֺ��������Ԫ  ����ʵ��
	/*
		����һ����ͨ����������
			friend void printPerson2(Person<T1, T2>& p); 

		����һ������ģ���ʵ��
			template<class T1, class T2>
			void printPerson2(Person<T1, T2>& p){}

		���Ե�������������һ�׶���
		����Ҫ���� ��ģ������б�<>�����߱���������һ�� ����ģ��ĺ�������
			friend void printPerson2<>(Person<T1, T2>& p);

		ȫ�ֺ�������ʵ�� - ��Ҫ��ǰ�ñ�����֪��ȫ�ֺ����Ĵ���
		(ʵ�����Ϸ�)
	*/
	friend void printPerson2<>(Person<T1, T2>& p);

public:

	Person(T1 name, T2 age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}


private:
	T1 m_Name;
	T2 m_Age;

};



//1��ȫ�ֺ���������ʵ��
void test01()
{
	Person <string, int >p("Tom", 20);
	printPerson(p);
}

//2��ȫ�ֺ���������ʵ��
void test02()
{
	Person <string, int >p("Jerry", 30);
	printPerson2(p);
}

int main()
{
	test01();

	test02();

	return 0;
}

/*
	���Ե�Ļ����������������Ų��ҽţ��ҽŲ��������
*/