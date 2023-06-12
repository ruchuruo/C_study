
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

				3.7.1 list��������

				3.7.2 list���캯��

				3.7.3 list ��ֵ�ͽ���

				3.7.4 list ��С����

				3.7.5 list �����ɾ��

					����������

						��list�����������ݵĲ����ɾ��

					����ԭ�ͣ�

						push_back(elem);     //������β������һ��Ԫ��
						pop_back();          //ɾ�����������һ��Ԫ��
						push_front(elem);    //��������ͷ����һ��Ԫ��
						pop_front();         //��������ͷ�Ƴ���һ��Ԫ��
						insert(pos,elem);    //��posλ�ò�elemԪ�صĿ��������������ݵ�λ�á�
						insert(pos,n,elem);  //��posλ�ò���n��elem���ݣ��޷���ֵ��
						insert(pos,beg,end); //��posλ�ò���[beg,end)��������ݣ��޷���ֵ��
						clear();             //�Ƴ���������������
						erase(beg,end);      //ɾ��[beg,end)��������ݣ�������һ�����ݵ�λ�á�
						erase(pos);          //ɾ��posλ�õ����ݣ�������һ�����ݵ�λ�á�
						remove(elem);        //ɾ��������������elemֵƥ���Ԫ�ء�

					�ܽ᣺

						β�� --- push_back
						βɾ --- pop_back
						ͷ�� --- push_front
						ͷɾ --- pop_front
						���� --- insert
						ɾ�� --- erase
						�Ƴ� --- remove
						��� --- clear
*/

#include <iostream>
#include <list>

using namespace std;

void printList(const list<int>& l)
{
	for (list<int>::const_iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	list<int> l;

	//������β������һ��Ԫ��
	l.push_back(10);
	l.push_back(20);
	l.push_back(30);

	//��������ͷ����һ��Ԫ��
	l.push_front(100);
	l.push_front(200);
	l.push_front(300);

	printList(l);

	//ɾ�����������һ��Ԫ��
	l.pop_back();

	printList(l);

	//��������ͷ�Ƴ���һ��Ԫ��
	l.pop_front();

	printList(l);

	//��posλ�ò�elemԪ�صĿ��������������ݵ�λ�á�
	l.insert(++l.begin(), 666);

	printList(l);

	//ɾ��posλ�õ����ݣ�������һ�����ݵ�λ�á�
	l.erase(++l.begin());

	printList(l);


	//ɾ��������������elemֵƥ���Ԫ�ء�
	l.push_back(99999);
	l.push_back(99999);
	l.push_back(99999);

	printList(l);

	l.remove(99999);

	printList(l);

	//�Ƴ���������������
	l.clear();

	printList(l);
}

int main()
{
	test01();

	return 0;
}