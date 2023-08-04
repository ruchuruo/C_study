
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

					����������

						��set�������в��������Լ�ͳ������

					����ԭ�ͣ�

						find(key);  //����key�Ƿ����,�����ڣ����ظü���Ԫ�صĵ��������������ڣ�����set.end();
						count(key); //ͳ��key��Ԫ�ظ���

					�ܽ᣺

						���� --- find  �����ص��ǵ�������
						ͳ�� --- count ������set�����Ϊ0����1��
*/

#include <iostream>
#include <set>

using namespace std;

void test01()
{
	set<int> s;

	s.insert(10);
	s.insert(20);
	s.insert(30);
	s.insert(30);
	s.insert(30);
	s.insert(40);
	
	//����key�Ƿ����,�����ڣ����ظü���Ԫ�صĵ��������������ڣ�����set.end();
	set<int>::iterator pos = s.find(30);
	if (pos != s.end())
	{
		cout << "�ҵ� " << *pos << endl;
	}
	else
	{
		cout << "�Ҳ���" << endl;
	}

	//ͳ��key��Ԫ�ظ���
	cout << s.count(30) << " ��" << endl;
}

int main()
{
	test01();

	return 0;
}