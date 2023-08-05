
/*
	��1�׶�C++ ����֮�� ��0��1����

	��2�׶�ʵս-ͨѶ¼����

	��3�׶�-C++���ı��

	��4�׶�ʵս-���ڶ�̬����ҵְ��ϵͳ

	��5�׶�-C++��߱��

		1 ģ��

		2 STL��ʶ

		3 STL- ��������

			3.1 string����

			3.2 vector����

			3.3 deque����

			3.4 ����-��ί���

			3.5 stack����

			3.6 queue ����

			3.7 list����

			3.8 set/ multiset ����

			3.9 map/ multimap����

				3.9.1 map��������

				3.9.2 map����͸�ֵ

				3.9.3 map��С�ͽ���

				3.9.4 map�����ɾ��

				3.9.5 map���Һ�ͳ��

				3.9.6 map��������

					ѧϰĿ�꣺

						map����Ĭ���������Ϊ ����keyֵ���� ��С��������������θı��������

					��Ҫ������:

						���÷º��������Ըı��������

					�ܽ᣺

						���÷º�������ָ��map�������������
						�����Զ����������ͣ�map����Ҫָ���������,ͬset����
*/

#include <iostream>
#include <map>

using namespace std;

class MyCompare
{
public:
	// ���Ե�Ļ��vs2019Ҫ�ڳ�Ա���������߼�һ��const��ɳ�����
	bool operator()(int v1, int v2) const
	{
		// ����
		return v1 > v2;
	}
};

void printMap(map<int, int, MyCompare>& m)
{
	for (map<int, int, MyCompare>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << (*it).first << " = " << (*it).second << endl;
	}
	cout << endl;
}

void test01()
{
	map<int, int, MyCompare> m;

	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(4, 40));

	printMap(m);
}

int main()
{
	test01();

	return 0;
}