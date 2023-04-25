
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

					����������

						��deque�����Ĵ�С���в���

					����ԭ�ͣ�

						deque.empty();           //�ж������Ƿ�Ϊ��

						deque.size();            //����������Ԫ�صĸ���

						deque.resize(num);       //����ָ�������ĳ���Ϊnum,�������䳤������Ĭ��ֵ�����λ�á�
						                         //���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����

						deque.resize(num, elem); //����ָ�������ĳ���Ϊnum,�������䳤������elemֵ�����λ�á�
						                         //���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����

					�ܽ᣺

						dequeû�������ĸ���
						�ж��Ƿ�Ϊ�� --- empty
						����Ԫ�ظ��� --- size
						����ָ������ --- resize
*/

#include <iostream>
#include <deque>

using namespace std;

void printDeque(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	deque<int> d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);

	//�ж������Ƿ�Ϊ��
	if (d1.empty())
	{
		cout << "d1Ϊ��" << endl;
	}
	else
	{
		cout << "d1��Ϊ��" << endl;
	}

	//����������Ԫ�صĸ���
	// deque ����û����������
	cout << "d1�Ĵ�С " << d1.size() << endl;

	//����ָ�������ĳ���Ϊnum,�������䳤������Ĭ��ֵ�����λ�á�
	d1.resize(15);
	printDeque(d1);

	//����ָ�������ĳ���Ϊnum,�������䳤������elemֵ�����λ�á�
	d1.resize(20, 666);
	printDeque(d1);

	//���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
	d1.resize(5);
	printDeque(d1);
}

int main()
{
	test01();

	return 0;
}