
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

					��飺

						����Ԫ�ض����ڲ���ʱ�Զ�������
						(�������Ҳ�м�������)

					���ʣ�

						set/multiset���ڹ���ʽ�������ײ�ṹ���ö�����ʵ�֡�

					set��multiset����

						set���������������ظ���Ԫ��
						multiset�������������ظ���Ԫ��

				3.8.2 set����͸�ֵ

					��������������set�����Լ���ֵ

					���죺

						set<T> st;          //Ĭ�Ϲ��캯����
						set(const set &st); //�������캯��

					��ֵ��

						set& operator=(const set &st); //���صȺŲ�����

					�ܽ᣺

						set������������ʱ��insert
						set�����������ݵ����ݻ��Զ�����
						set�������������������ظ���Ԫ��
*/

#include <iostream>
#include <set>

using namespace std;

void printSet(set<int> &s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	set<int> s;

	// ��������ֻ�� insert ��ʽ
	s.insert(10);
	s.insert(40);
	s.insert(30);
	s.insert(20);
	s.insert(30);

	// ��������
	printSet(s);


	// ��������
	set<int> s2(s);

	printSet(s);


	// ��ֵ
	set<int> s3;
	s3 = s2;

	printSet(s);
}


int main()
{
	test01();

	return 0;
}