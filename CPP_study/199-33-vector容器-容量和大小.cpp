
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

					����������

						��vector�����������ʹ�С����

					����ԭ�ͣ�

						empty();               //�ж������Ƿ�Ϊ��

						capacity();            //����������

						size();                //����������Ԫ�صĸ���

						resize(int num);       //����ָ�������ĳ���Ϊnum���������䳤������Ĭ��ֵ�����λ�á�
										       //���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����

						resize(int num, elem); //����ָ�������ĳ���Ϊnum���������䳤������elemֵ�����λ�á�
											   //���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ��

					�ܽ᣺

						�ж��Ƿ�Ϊ�� --- empty
						����Ԫ�ظ��� --- size
						������������ --- capacity
						����ָ����С --- resize
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
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);

	if (v1.empty())
	{
		cout << "v1Ϊ��" << endl;
	}
	else
	{
		cout << "v1��Ϊ��" << endl;
		cout << "v1������ = " << v1.capacity() << endl;
		cout << "v1�Ĵ�С = " << v1.size() << endl;
	}

	//resize ����ָ����С ����ָ���ĸ���Ĭ����0�����λ�ã������������ذ汾�滻Ĭ�����
	v1.resize(15, 666);
	printVector(v1);

	//resize ����ָ����С ����ָ���ĸ�С����������Ԫ�ر�ɾ��
	v1.resize(5);
	printVector(v1);
}

int main()
{
	test01();

	return 0;
}