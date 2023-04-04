
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

					1.2.1 ����ģ���﷨

					1.2.2 ����ģ��ע������

					1.2.3 ����ģ�尸��

					1.2.4 ��ͨ�����뺯��ģ�������

					1.2.5 ��ͨ�����뺯��ģ��ĵ��ù���

					1.2.6 ģ��ľ�����

						�����ԣ�

							ģ���ͨ���Բ��������ܵ�

						���磺

							template<class T>
							void f(T a, T b)
							{
								a = b;
							}

						�������������ṩ�ĸ�ֵ��������������a��b��һ�����飬���޷�ʵ����

						�����磺

							template<class T>
							void f(T a, T b)
							{
								if(a > b) { ... }
							}

						�����������У����T���������ʹ��������Person�������Զ����������ͣ�Ҳ�޷���������

						���C++Ϊ�˽���������⣬�ṩģ������أ�����Ϊ��Щ�ض��������ṩ���廯��ģ��

						�ܽ᣺

							���þ��廯��ģ�壬���Խ���Զ������͵�ͨ�û�
							ѧϰģ�岢����Ϊ��дģ�壬������STL�ܹ�����ϵͳ�ṩ��ģ��
*/

#include <iostream>

using namespace std;

class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};

//��ͨ����ģ��
template<class T>
bool myCompare(T& a, T& b)
{
	if (a == b)
	{
		return true;
	}
	else
	{
		return false;
	}
}


//���廯����ʾ���廯��ԭ�ͺͶ���˼��template<>��ͷ����ͨ��������ָ������
//���廯�����ڳ���ģ��
template<> bool myCompare(Person& p1, Person& p2)
{
	if (p1.m_Name == p2.m_Name && p1.m_Age == p2.m_Age)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void test01()
{
	int a = 10;
	int b = 20;

	//�����������Ϳ���ֱ��ʹ��ͨ�õĺ���ģ��
	bool ret = myCompare(a, b);

	if (ret)
	{
		cout << "a == b " << endl;
	}
	else
	{
		cout << "a != b " << endl;
	}
}

void test02()
{
	Person p1("Tom", 10);
	Person p2("Tom", 10);

	//�Զ����������ͣ����������ͨ�ĺ���ģ��
	//���Դ������廯��Person�������͵�ģ�壬�������⴦���������
	bool ret = myCompare(p1, p2);

	if (ret)
	{
		cout << "p1 == p2 " << endl;
	}
	else
	{
		cout << "p1 != p2 " << endl;
	}
}

int main()
{
	test01();

	test02();

	return 0;
}