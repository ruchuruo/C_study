
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

				3.3.1 deque������������

				3.3.2 deque���캯��

				3.3.3 deque��ֵ����

				3.3.4 deque��С����

				3.3.5 deque �����ɾ��

				3.3.6 deque ���ݴ�ȡ

					����������

						��deque �е����ݵĴ�ȡ����

					����ԭ�ͣ�

						at(int idx); //��������idx��ָ������
						operator[];  //��������idx��ָ������
						front();     //���������е�һ������Ԫ��
						back();      //�������������һ������Ԫ��

					�ܽ᣺

						�����õ�������ȡdeque������Ԫ�أ�[ ]��atҲ����
						front����������һ��Ԫ��
						back�����������һ��Ԫ��
*/

#include <iostream>
#include <deque>

using namespace std;

void test01()
{
	deque<int> d;

	d.push_back(10);
	d.push_back(20);
	d.push_back(30);
	d.push_front(100);
	d.push_front(200);
	d.push_front(300);

	// at(int idx); //��������idx��ָ������
	for (int i = 0; i < d.size(); i++)
	{
		cout << d.at(i) << " ";
	}
	cout << endl;

	// operator[];  //��������idx��ָ������
	for (int i = 0; i < d.size(); i++)
	{
		cout << d[i] << " ";
	}
	cout << endl;

	// front();     //���������е�һ������Ԫ��
	cout << "��һ��Ԫ�� " << d.front() << endl;

	// back();      //�������������һ������Ԫ��
	cout << "���һ��Ԫ�� " << d.back() << endl;
}

int main()
{
	test01();

	return 0;
}