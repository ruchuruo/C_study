
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

				3.3.7 deque ����

					����������

						�����㷨ʵ�ֶ�deque������������

					�㷨��

						sort(iterator beg, iterator end) //��beg��end������Ԫ�ؽ�������

					�ܽ᣺
						sort�㷨�ǳ�ʵ�ã�ʹ��ʱ����ͷ�ļ� algorithm����

						����֧��������ʵĵ�����������������������sort�㷨ֱ�ӽ�������
*/

#include <iostream>
#include <deque>
#include <algorithm>

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
	deque<int> d;

	d.push_back(10);
	d.push_back(20);
	d.push_back(30);
	d.push_front(100);
	d.push_front(200);
	d.push_front(300);

	printDeque(d);

	// sort(iterator beg, iterator end) //��beg��end������Ԫ�ؽ�������
	// Ĭ�� ��С���� ����
	sort(d.begin(), d.end());

	printDeque(d);
}

int main()
{
	test01();

	return 0;
}