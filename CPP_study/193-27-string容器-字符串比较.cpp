
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

					����������

						�ַ���֮��ıȽ�

					�ȽϷ�ʽ��

						�ַ����Ƚ��ǰ��ַ���ASCII����жԱ�

						= ���� 0

						> ���� 1

						< ���� -1

					����ԭ�ͣ�

						int compare(const string &s) const; //���ַ���s�Ƚ�
						int compare(const char *s) const;   //���ַ���s�Ƚ�

					�ܽ᣺�ַ����Ա���Ҫ�����ڱȽ������ַ����Ƿ���ȣ��ж�˭��˭С�����岢���Ǻܴ�
*/

#include <iostream>

using namespace std;

//�ַ����Ƚ�
void test01()
{
	string s1 = "hello";
	string s2 = "aello";

	int ret = s1.compare(s2);

	if (ret == 0)
	{
		cout << "s1 ���� s2" << endl;
	}
	else if (ret > 0)
	{
		cout << "s1 ���� s2" << endl;
	}
	else
	{
		cout << "s1 С�� s2" << endl;
	}
}

int main()
{
	test01();

	return 0;
}