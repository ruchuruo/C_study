
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

				3.1.8 string�����ɾ��

				3.1.9 string�Ӵ�

					����������

						���ַ����л�ȡ��Ҫ���Ӵ�
						(�� �ַ��� �л�ȡ��Ҫ�� һС���ַ���)

					����ԭ�ͣ�

						string substr(int pos = 0, int n = npos) const; //������pos��ʼ��n���ַ���ɵ��ַ���

					�ܽ᣺�����������Ӵ����ܣ�������ʵ�ʿ����л�ȡ��Ч����Ϣ
*/

#include <iostream>

using namespace std;

//�Ӵ�
void test01()
{
	string str = "abcdefg";
	string subStr = str.substr(1, 3);
	cout << "subStr = " << subStr << endl;
}

// ʵ�ò���
void test02()
{
	string email = "hello@sina.com";
	int pos = email.find("@");
	string username = email.substr(0, pos);
	cout << "username: " << username << endl;
}

int main()
{
	test01();

	// ʵ�ò���
	test02();

	return 0;
}