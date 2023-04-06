
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

					ѧϰĿ�꣺

						��ģ��ʵ�������Ķ����������εķ�ʽ

					һ�������ִ��뷽ʽ��

						ָ����������� --- ֱ����ʾ�������������
						����ģ�廯     --- �������еĲ�����Ϊģ����д���
						������ģ�廯   --- ������������� ģ�廯���д���

					�ܽ᣺

						ͨ����ģ�崴���Ķ��󣬿��������ַ�ʽ�����н��д���
						ʹ�ñȽϹ㷺�ǵ�һ�֣�ָ�����������
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

//1��ָ����������� (���ͣ�Person<string, int>�����ã���������p)
void printPerson1(Person<string, int>& p)
{
    p.showPerson();
}
void test01()
{
    Person<string, int> p("�����", 100);
    printPerson1(p);
}

//2������ģ�廯 (<string, int > ���ģ�� <T1, T2>)
template <class T1, class T2>
void printPerson2(Person<T1, T2>& p)
{
    p.showPerson();
    cout << "T1������Ϊ�� " << typeid(T1).name() << endl;// string
    cout << "T2������Ϊ�� " << typeid(T2).name() << endl;// int
}
void test02()
{
    Person <string, int >p("��˽�", 90);
    printPerson2(p);
}

//3��������ģ�廯 (������ Person <string, int > ���ģ�� T)
template<class T>
void printPerson3(T& p)
{
    cout << "T������Ϊ�� " << typeid(T).name() << endl;// class Person
    p.showPerson();
}
void test03()
{
    Person <string, int >p("��ɮ", 30);
    printPerson3(p);
}

int main()
{
    //1��ָ�����������
    test01();

    //2������ģ�廯
    test02();

    //3��������ģ�廯
    test03();

    return 0;
}