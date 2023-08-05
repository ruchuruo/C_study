
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

					��飺

						map������Ԫ�ض���pair
						pair�е�һ��Ԫ��Ϊkey����ֵ�������������ã��ڶ���Ԫ��Ϊvalue��ʵֵ��
						����Ԫ�ض������Ԫ�صļ�ֵ�Զ�����

					���ʣ�

						map/multimap���ڹ���ʽ�������ײ�ṹ���ö�����ʵ�֡�

					�ŵ㣺

						���Ը���keyֵ�����ҵ�valueֵ

					map��multimap����

						map���������������ظ�keyֵԪ��
						multimap�������������ظ�keyֵԪ��

				3.9.2 map����͸�ֵ

					����������

						��map�������й���͸�ֵ����

					����ԭ�ͣ�

						���죺
							map<T1, T2> mp;                //mapĬ�Ϲ��캯��
							map(const map &mp);            //�������캯��

						��ֵ��
							map& operator=(const map &mp); //���صȺŲ�����

					�ܽ᣺
						map������Ԫ�ض��ǳɶԳ��֣���������ʱ��Ҫʹ�ö���
*/

#include <iostream>
#include <map>

using namespace std;

void printMap(map<int, int> &m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << it->first << " = " << (*it).second << endl;
	}
	cout << endl;
}

void test01()
{
	//mapĬ�Ϲ��캯��
	map<int, int> m;

	// ��������
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(4, 40));

	printMap(m);


	//�������캯��
	map<int, int> m2(m);

	printMap(m2);


	//���صȺŲ�����
	map<int, int> m3;
	m3 = m2;

	printMap(m2);
}

int main()
{
	test01();

	return 0;
}