
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

					����������

						��deque�������и�ֵ

					����ԭ�ͣ�

						deque& operator=(const deque &deq); //���صȺŲ�����

						assign(beg, end);                   //��[beg, end)�����е����ݿ�����ֵ������

						assign(n, elem);                    //��n��elem������ֵ������

					�ܽ᣺deque��ֵ����Ҳ��vector��ͬ������������
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

	//���صȺŲ�����
	deque<int> d2;
	d2 = d1;
	printDeque(d2);

	//��[beg, end)�����е����ݿ�����ֵ������
	deque<int> d3;
	d3.assign(d1.begin(), d1.end());
	printDeque(d3);

	//��n��elem������ֵ������
	deque<int> d4;
	d4.assign(10, 666);
	printDeque(d4);
}

int main()
{
	test01();

	return 0;
}