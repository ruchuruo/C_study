
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

					����������

						��map�������в��������Լ�ͳ������

					����ԭ�ͣ�

						find(key);  //����key�Ƿ����,�����ڣ����ظü���Ԫ�صĵ��������������ڣ�����map.end();
						count(key); //ͳ��key��Ԫ�ظ���

					�ܽ᣺

						���� --- find  �����ص��ǵ�������
						ͳ�� --- count ������map�����Ϊ0����1��
*/

#include <iostream>
#include <map>

using namespace std;

void test01()
{
	map<int, int> m;

	m.insert(make_pair(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(3, 30));
	m.insert(make_pair(3, 31));
	m.insert(make_pair(4, 40));

	//����key�Ƿ����,�����ڣ����ظü���Ԫ�صĵ��������������ڣ�����map.end();
	map<int, int>::iterator pos = m.find(3);

	if (pos == m.end())
	{
		cout << "û�ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ� " << pos->first << " = " << pos->second << endl;
	}


	//ͳ��key��Ԫ�ظ���
	cout << m.count(3) << endl;
}

int main()
{
	test01();

	return 0;
}