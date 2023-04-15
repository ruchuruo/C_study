
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

					����������

						��string�ַ������и�ֵ

					��ֵ�ĺ���ԭ�ͣ�

						string& operator=(const char* s);     //char*�����ַ��� ��ֵ����ǰ���ַ���
						string& operator=(const string &s);   //���ַ���s������ǰ���ַ���
						string& operator=(char c);            //�ַ���ֵ����ǰ���ַ���
						string& assign(const char *s);        //���ַ���s������ǰ���ַ���
						string& assign(const char *s, int n); //���ַ���s��ǰn���ַ�������ǰ���ַ���
						string& assign(const string &s);      //���ַ���s������ǰ�ַ���
						string& assign(int n, char c);        //��n���ַ�c������ǰ�ַ���

					�ܽ᣺

						string�ĸ�ֵ��ʽ�ܶ࣬operator= ���ַ�ʽ�ǱȽ�ʵ�õ�
*/

#include <iostream>

using namespace std;

//��ֵ
void test01()
{
	string str1;
	str1 = "hello world";
	cout << "str1 = " << str1 << endl;

	string str2;
	str2 = str1;
	cout << "str2 = " << str2 << endl;

	string str3;
	str3 = 'a';
	cout << "str3 = " << str3 << endl;

	string str4;
	str4.assign("hello c++");
	cout << "str4 = " << str4 << endl;

	string str5;
	str5.assign("hello c++", 5);
	cout << "str5 = " << str5 << endl;


	string str6;
	str6.assign(str5);
	cout << "str6 = " << str6 << endl;

	string str7;
	str7.assign(5, 'x');
	cout << "str7 = " << str7 << endl;
}

int main()
{
	test01();

	return 0;
}