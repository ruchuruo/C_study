
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

					����������

						��deque�����в����ɾ������

					����ԭ�ͣ�

						���˲���ɾ��������

							push_back(elem);  //������β�����һ������
							push_front(elem); //������ͷ������һ������
							pop_back();       //ɾ���������һ������
							pop_front();      //ɾ��������һ������

						ָ��λ�ò�����

							insert(pos,elem);    //��posλ�ò���һ��elemԪ�صĿ��������������ݵ�λ�á�

							insert(pos,n,elem);  //��posλ�ò���n��elem���ݣ��޷���ֵ��

							insert(pos,beg,end); //��posλ�ò���[beg,end)��������ݣ��޷���ֵ��

							clear();             //�����������������

							erase(beg,end);      //ɾ��[beg,end)��������ݣ�������һ�����ݵ�λ�á�

							erase(pos);          //ɾ��posλ�õ����ݣ�������һ�����ݵ�λ�á�

						�ܽ᣺

							�����ɾ���ṩ��λ���ǵ�������
							β�� --- push_back
							βɾ --- pop_back
							ͷ�� --- push_front
							ͷɾ --- pop_front
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

// ���˲������
void test01()
{
	deque<int> d1;

	// β��
	d1.push_back(10);
	d1.push_back(20);

	// ͷ��
	d1.push_front(100);
	d1.push_front(200);

	printDeque(d1);

	// βɾ
	d1.pop_back();
	printDeque(d1);

	// ͷɾ
	d1.pop_front();
	printDeque(d1);

	cout << endl;
}

// ָ��λ�ò���
void test02()
{
	deque<int> d1;
	deque<int> d2;

	d1.push_back(10);
	d1.push_back(20);
	d1.push_front(100);
	d1.push_front(200);

	d2.push_back(1);
	d2.push_back(2);
	d2.push_back(3);

	printDeque(d1);



	//��posλ�ò���һ��elemԪ�صĿ��������������ݵ�λ�á�
	d1.insert(d1.begin() + 2, 666);

	printDeque(d1);

	//��posλ�ò���n��elem���ݣ��޷���ֵ��
	d1.insert(d1.begin() + 3, 2, 999);
	printDeque(d1);

	//��posλ�ò���[beg,end)��������ݣ��޷���ֵ��
	d1.insert(d1.begin(), d2.begin(), d2.end());
	printDeque(d1);

	cout << endl;
}

// ָ��λ��ɾ������
void test03()
{
	deque<int> d1;

	d1.push_back(10);
	d1.push_back(20);
	d1.push_front(100);
	d1.push_front(200);

	printDeque(d1);

	//ɾ��posλ�õ����ݣ�������һ�����ݵ�λ�á�
	d1.erase(d1.begin());
	printDeque(d1);

	//ɾ��[beg,end)��������ݣ�������һ�����ݵ�λ�á�
	d1.erase(d1.begin() + 1, d1.begin() + 3);
	printDeque(d1);

	//�����������������
	d1.clear();
	printDeque(d1);
}

int main()
{
	// ���˲���ɾ������
	test01();

	// ָ��λ�ò������
	test02();

	// ָ��λ��ɾ������
	test03();

	return 0;
}