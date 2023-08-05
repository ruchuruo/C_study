
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

				3.8.8 set��������

					ѧϰĿ�꣺

						set����Ĭ���������Ϊ��С����������θı��������

					��Ҫ�����㣺

						���÷º��������Ըı��������
*/

#include <iostream>
#include <set>

using namespace std;

class MyCompar
{
public:
	// ����()
	// const��Ա����
	bool operator()(int v1, int v2) const
	{
		return v1 > v2;
	}

	/*
		���Ե�Ļ��
			Ψһ�������Ƕ���mutable���εĳ�Ա������const�ĳ�Ա�������Ա���const�����const������ã�
			�Ǿ�̬��Ա���������const���ӵ��ǳ�Ա������̬��Ա��������������󣩣�
			��ʾ��Ա�������������thisָ��Ϊconstָ�룬�������ڸó�Ա�����У�
			�����޸������ڵ���ĳ�Ա�Ĳ������ǲ�����ģ���Ϊ�����˶�thisָ���const���ã���
			������const�ĳ�Ա����ֻ�ܱ���const������á�

		���Ե�Ļ��
			�ڷº����У����ڴ���Ĳ������в���ʱ�����û�м���const����ôĬ����������ǿ��Ա��޸ĵġ�
			����set�����У�Ԫ���ǲ������޸ĵģ���������º�����û�м���const������set������ʵ��ì�ܣ����±������
			������const���ʾ���������ֻ���ģ������������޸ģ����ܱ����������
	*/
};



// set���������������
void test01()
{
	set<int> s;

	s.insert(10);
	s.insert(20);
	s.insert(30);
	s.insert(40);
	s.insert(50);

	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	cout << endl;



	// ָ��������� �Ӵ�С��������ǰָ��������
	set<int, MyCompar> s2;

	// ���Ե�Ļ������������������Ϊset<int,MyCompare>�е������βζ����������ͣ�MyCompare��һ��class���͡��ú����Ļ��������������ͣ��ײ�Ӧ�ûᱨ��

	s2.insert(10);
	s2.insert(20);
	s2.insert(30);
	s2.insert(40);
	s2.insert(50);

	for (set<int, MyCompar>::iterator it = s2.begin(); it != s2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	// set���������������
	test01();

	return 0;
}