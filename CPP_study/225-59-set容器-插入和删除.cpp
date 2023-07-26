
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

					����������

						set�������в������ݺ�ɾ������

					����ԭ�ͣ�

						insert(elem);    //�������в���Ԫ�ء�
						clear();         //�������Ԫ��
						erase(pos);      //ɾ��pos��������ָ��Ԫ�أ�������һ��Ԫ�صĵ�������
						erase(beg, end); //ɾ������[beg,end)������Ԫ�� ��������һ��Ԫ�صĵ�������
						erase(elem);     //ɾ��������ֵΪelem��Ԫ�ء�

					�ܽ᣺

						���� --- insert
						ɾ�� --- erase
						��� --- clear
*/

#include <iostream>
#include <set>

using namespace std;

void printSet(set<int>& s)
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

	s.insert(10);
	s.insert(20);
	s.insert(30);
	s.insert(40);
	s.insert(50);
	s.insert(60);

	printSet(s);

	//ɾ��pos��������ָ��Ԫ�أ�������һ��Ԫ�صĵ�������
	s.erase(++s.begin());

	printSet(s);

	//ɾ��������ֵΪelem��Ԫ�ء�
	s.erase(30);

	printSet(s);

	//ɾ������[beg,end)������Ԫ�� ��������һ��Ԫ�صĵ�������
	s.erase(++s.begin(), --s.end());

	printSet(s);

	//�������Ԫ��
	s.clear();

	printSet(s);
}

int main()
{
	test01();

	return 0;
}