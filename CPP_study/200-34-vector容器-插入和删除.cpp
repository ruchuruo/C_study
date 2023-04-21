
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

				3.2.1 vector��������

				3.2.2 vector���캯��

				3.2.3 vector��ֵ����

				3.2.4 vector�����ʹ�С

				3.2.5 vector�����ɾ��

					����������

						��vector�������в��롢ɾ������

					����ԭ�ͣ�

						push_back(ele);                                  //β������Ԫ��ele
						pop_back();                                      //ɾ�����һ��Ԫ��
						insert(const_iterator pos, ele);                 //������ָ��λ��pos����Ԫ��ele
						insert(const_iterator pos, int count,ele);       //������ָ��λ��pos����count��Ԫ��ele
						erase(const_iterator pos);                       //ɾ��������ָ���Ԫ��
						erase(const_iterator start, const_iterator end); //ɾ����������start��end֮���Ԫ��
						clear();                                         //ɾ������������Ԫ��

					�ܽ᣺

						β�� --- push_back
						βɾ --- pop_back
						���� --- insert (λ�õ�����)
						ɾ�� --- erase ��λ�õ�������
						��� --- clear
*/

#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	vector<int> v1;

	// β��
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);
	printVector(v1);

	// βɾ
	v1.pop_back();
	printVector(v1);

	// pos����
	v1.insert(v1.begin(), 166);
	printVector(v1);

	// pos���� �����ͬ����
	v1.insert(v1.begin(), 2, 266);
	printVector(v1);

	// posɾ��
	v1.erase(v1.begin());
	printVector(v1);

	// posɾ�� �������
	//vector<int>::iterator itBegin = v1.begin();
	//v1.erase(v1.begin(), itBegin + 5);
	v1.erase(v1.begin(), v1.begin() + 5);
	printVector(v1);

	// ���
	v1.clear();
	printVector(v1);
}

int main()
{
	test01();

	return 0;
}