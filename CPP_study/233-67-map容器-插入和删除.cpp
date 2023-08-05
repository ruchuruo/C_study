
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

					����������

						map�������в������ݺ�ɾ������

					����ԭ�ͣ�

						insert(elem);    //�������в���Ԫ�ء�
						clear();         //�������Ԫ��
						erase(pos);      //ɾ��pos��������ָ��Ԫ�أ�������һ��Ԫ�صĵ�������
						erase(beg, end); //ɾ������[beg,end)������Ԫ�� ��������һ��Ԫ�صĵ�������
						erase(key);      //ɾ��������ֵΪkey��Ԫ�ء�

					�ܽ᣺

						map���뷽ʽ�ܶ࣬��ס��һ����
						���� --- insert
						ɾ�� --- erase
						��� --- clear
*/

#include <iostream>
#include <map>

using namespace std;

void printMap(map<int, int>& m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << (*it).first << " = " << (*it).second << endl;
	}
	cout << endl;
}

//�������в���Ԫ��
void test01()
{
	map<int, int> m;

	//�������в���Ԫ�أ���ʽ1 ��������
	m.insert(pair<int, int>(1, 10));

	//�������в���Ԫ�أ���ʽ2 ����
	m.insert(make_pair(2, 10));

	//�������в���Ԫ�أ���ʽ3 ֵ����
	m.insert(map<int, int>::value_type(3, 10));



	//�������в���Ԫ�أ���ʽ4 ����[]
	// ���Ƽ�������������Ѿ�����ͬ��key���Ḳ��֮ǰkey��value
	m[3] = 11;

	// ����[]������key���ʵ�value��ǰ����ȷ�������key��������Զ�����
	cout << m[3] << endl;
	cout << m[5] << endl;

	printMap(m);
}

void test02()
{
	cout << endl;
	cout << endl;

	map<int, int> m;

	m.insert(make_pair(1, 11));
	m.insert(make_pair(2, 21));
	m.insert(make_pair(3, 31));
	m.insert(make_pair(4, 41));
	m.insert(make_pair(5, 51));
	m.insert(make_pair(6, 61));

	printMap(m);

	//ɾ��pos��������ָ��Ԫ�أ�������һ��Ԫ�صĵ�������
	m.erase(m.begin());

	printMap(m);


	//ɾ��������ֵΪkey��Ԫ�ء�
	m.erase(3);

	printMap(m);


	//ɾ������[beg,end)������Ԫ�� ��������һ��Ԫ�صĵ�������
	m.erase(++m.begin(), --m.end());

	printMap(m);


	//�������Ԫ��
	m.clear();

	printMap(m);
}

int main()
{
	//�������в���Ԫ�ء�
	test01();

	// ɾ��Ԫ��
	test02();

	return 0;
}