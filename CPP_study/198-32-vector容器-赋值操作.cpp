
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

					����������

						��vector�������и�ֵ

					����ԭ�ͣ�

						vector& operator=(const vector &vec); //���صȺŲ�����
						assign(beg, end);                     //��[beg, end)�����е����ݿ�����ֵ������
						assign(n, elem);                      //��n��elem������ֵ������

					�ܽ᣺ vector��ֵ��ʽ�Ƚϼ򵥣�ʹ��operator=������assign������
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

//��ֵ����
void test01()
{
	vector<int> v1; //�޲ι���
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);

	vector<int>v2;
	v2 = v1;
	printVector(v2);

	vector<int>v3;
	v3.assign(v1.begin(), v1.end());
	printVector(v3);

	vector<int>v4;
	v4.assign(10, 100);
	printVector(v4);
}

int main()
{
	test01();

	return 0;
}