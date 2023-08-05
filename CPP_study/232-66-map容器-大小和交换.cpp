
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

					����������

						ͳ��map������С�Լ�����map����

					����ԭ�ͣ�

						size();   //����������Ԫ�ص���Ŀ
						empty();  //�ж������Ƿ�Ϊ��
						swap(st); //����������������

					�ܽ᣺

						ͳ�ƴ�С     --- size
						�ж��Ƿ�Ϊ�� --- empty
						��������     --- swap
*/

#include <iostream>
#include <map>

using namespace std;

void printMap(map<int, int>& m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << it->first << " = " << (*it).second << endl;
	}
	cout << endl;
}

// ��С
void test01()
{
	map<int, int> m;

	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 10));
	m.insert(pair<int, int>(3, 10));
	m.insert(pair<int, int>(4, 10));

	//�ж������Ƿ�Ϊ��
	if (m.empty())
	{
		cout << "mΪ��" << endl;
	}
	else
	{
		cout << "m��Ϊ��" << " ��С ";

		//����������Ԫ�ص���Ŀ
		cout << m.size() << endl;
	}
}

// ����
void test02()
{
	map<int, int> m1;
	map<int, int> m2;

	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(2, 10));
	m1.insert(pair<int, int>(3, 10));

	m2.insert(pair<int, int>(10, 100));
	m2.insert(pair<int, int>(20, 100));
	m2.insert(pair<int, int>(30, 100));

	cout << "����ǰ" << endl;
	printMap(m1);
	printMap(m2);

	m1.swap(m2);
	cout << "������" << endl;
	printMap(m1);
	printMap(m2);
}

int main()
{
	// ��С
	test01();

	// ����
	test02();

	return 0;
}