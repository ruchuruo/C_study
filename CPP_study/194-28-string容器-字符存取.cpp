
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

				3.1.1 string��������

				3.1.2 string���캯��

				3.1.3 string��ֵ����

				3.1.4 string�ַ���ƴ��

				3.1.5 string���Һ��滻

				3.1.6 string�ַ����Ƚ�

				3.1.7 string�ַ���ȡ

					string�е����ַ���ȡ��ʽ������

						char& operator[](int n); //ͨ��[]��ʽȡ�ַ�
						char& at(int n);         //ͨ��at������ȡ�ַ�

					�ܽ᣺string�ַ����е����ַ���ȡ�����ַ�ʽ������ [ ] �� at
*/

#include <iostream>

using namespace std;

void test01()
{
	string str = "hello world";

	for (int i = 0; i < str.size(); i++)
	{
		cout << str[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < str.size(); i++)
	{
		cout << str.at(i) << " ";
	}
	cout << endl;


	//�ַ��޸�
	str[0] = 'x';
	str.at(1) = 'x';
	cout << str << endl;
}

int main()
{
	test01();

	return 0;
}