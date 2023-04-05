
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

					��ģ���뺯��ģ��������Ҫ�����㣺

						��ģ��û���Զ������Ƶ���ʹ�÷�ʽ
						��ģ����ģ������б��п�����Ĭ�ϲ���

					�ܽ᣺

						��ģ��ʹ��ֻ������ʾָ�����ͷ�ʽ
						��ģ���е�ģ������б������Ĭ�ϲ���
*/

#include <iostream>

using namespace std;

//��ģ��
template<class NameType, class AgeType = int>
class Person
{
public:
	Person(NameType name, AgeType age)
	{
		this->mName = name;
		this->mAge = age;
	}
	void showPerson()
	{
		cout << "name: " << this->mName << " age: " << this->mAge << endl;
	}
public:
	NameType mName;
	AgeType mAge;
};

//1����ģ��û���Զ������Ƶ���ʹ�÷�ʽ
void test01()
{
	// Person p("�����", 1000); // ���� ��ģ��ʹ��ʱ�򣬲��������Զ������Ƶ�
	Person <string, int>p("�����", 1000); //����ʹ����ʾָ�����͵ķ�ʽ��ʹ����ģ��
	p.showPerson();
}

//2����ģ����ģ������б��п�����Ĭ�ϲ���
void test02()
{
	Person <string> p("��˽�", 999); //��ģ���е�ģ������б� ����ָ��Ĭ�ϲ���
	p.showPerson();
}

// ûָ�����;���Ĭ������
void test3()
{
	Person <string, string>p("����", "abcd");
	p.showPerson();
}

int main()
{
	test01();

	test02();

	test3();

	return 0;
}