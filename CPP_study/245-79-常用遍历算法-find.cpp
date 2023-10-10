
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

				ѧϰĿ�꣺

					���ճ��õĲ����㷨

				�㷨��飺

					find          //����Ԫ��
					find_if       //����������Ԫ��
					adjacent_find //���������ظ�Ԫ��
					binary_search //���ֲ��ҷ�
					count         //ͳ��Ԫ�ظ���
					count_if      //������ͳ��Ԫ�ظ���

				5.2.1 find

					����������

						����ָ��Ԫ�أ��ҵ�����ָ��Ԫ�صĵ��������Ҳ������ؽ���������end()

					����ԭ�ͣ�

						find(iterator beg, iterator end, value);
							// ��ֵ����Ԫ�أ��ҵ�����ָ��λ�õ��������Ҳ������ؽ���������λ��
							// beg   ��ʼ������
							// end   ����������
							// value ���ҵ�Ԫ��

					�ܽ᣺ ����find��������������ָ����Ԫ�أ�����ֵ�ǵ�����
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

	// ���ط���==����find֪����ζԱȣ�ʹ��const��ֹ���ݱ��޸�
	bool operator==(const Person & p)
	{
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

// ����������������
void test01()
{
	vector<int> v;
	
	// ������ݵ�����
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	// ���� 5
	vector<int>::iterator it = find(v.begin(), v.end(), 5);
	
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

// �����Զ�����������
void test02()
{
	vector<Person> v;

	// ��������
	Person p1("a", 10);
	Person p2("b", 20);
	Person p3("c", 30);
	Person p4("d", 40);

	// ��ӵ�������
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	// ��Ҫ���ҵ�����
	Person ppp("b", 20);

	// ���� �Ƿ������ݺ�ppp��ͬ��
	vector<Person>::iterator it = find(v.begin(), v.end(), ppp);

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
	// ����������������
	test01();

	// �����Զ�����������
	test02();

	return 0;
}