
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

					��ģ���г�Ա��������ͨ���г�Ա��������ʱ����������ģ�

						��ͨ���еĳ�Ա����һ��ʼ�Ϳ��Դ���
						��ģ���еĳ�Ա�����ڵ���ʱ�Ŵ���

					�ܽ᣺��ģ���еĳ�Ա����������һ��ʼ�ʹ����ģ��ڵ���ʱ��ȥ����
*/

#include <iostream>

using namespace std;

class Person1
{
public:
	void showPerson1()
	{
		cout << "Person1 show" << endl;
	}
};

class Person2
{
public:
	void showPerson2()
	{
		cout << "Person2 show" << endl;
	}
};

template<class T>
class MyClass
{
public:
	T obj;

	//��ģ���еĳ�Ա������������һ��ʼ�ʹ����ģ�������ģ�����ʱ������
	// ��ȷ���������������ͣ����Բ��ᴴ��

	void fun1() { obj.showPerson1(); }
	void fun2() { obj.showPerson2(); }
};

void test01()
{
	MyClass<Person1> m;

	m.fun1();

	// Person1 ����û�� showPerson2() ����
	//m.fun2();//��������˵���������òŻ�ȥ������Ա����
}

int main()
{
	test01();

	return 0;
}