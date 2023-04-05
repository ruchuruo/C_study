
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

					��ģ�����ã�

						����һ��ͨ���࣬���еĳ�Ա �������Ϳ��Բ������ƶ�����һ�����������������

					�﷨��

						template<typename T>
						��

					���ͣ�

						template --- ��������ģ��

						typename --- ���������ķ�����һ���������ͣ�������class����

						T --- ͨ�õ��������ͣ����ƿ����滻��ͨ��Ϊ��д��ĸ

					�ܽ᣺��ģ��ͺ���ģ���﷨���ƣ�������ģ��template������࣬�����Ϊ��ģ��
*/

#include <iostream>

using namespace std;

//��ģ��
template<class NameType, class AgeType>
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

void test01()
{
	// ָ��NameType Ϊstring���ͣ�AgeType Ϊ int����
	Person<string, int> P1("�����", 999);

	P1.showPerson();
}

int main()
{
	test01();

	return 0;
}