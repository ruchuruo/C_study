
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

				3.8.1 set��������

				3.8.2 set����͸�ֵ

				3.8.3 set��С�ͽ���

				3.8.4 set�����ɾ��

				3.8.5 set���Һ�ͳ��

				3.8.6 set��multiset����

				3.8.7 pair���鴴��

					����������

						�ɶԳ��ֵ����ݣ����ö�����Է�����������

					���ִ�����ʽ��

						pair<type, type> p ( value1, value2 );
						pair<type, type> p = make_pair( value1, value2 );

					�ܽ᣺

						���ַ�ʽ�����Դ������飬��סһ�ּ���
*/

#include <iostream>

using namespace std;

void test01()
{
	// pair<type, type> p ( value1, value2 );
	pair<string, int> p("Tom", 20);

	cout << p.first << " " << p.second << endl;


	// pair<type, type> p = make_pair( value1, value2 );
	pair<string, int> p2 = make_pair("����", 30);
	cout << p2.first << " " << p2.second << endl;
}

int main()
{
	test01();

	return 0;
}