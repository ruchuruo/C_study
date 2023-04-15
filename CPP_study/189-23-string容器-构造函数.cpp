
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

					���ʣ�

						string��C++�����ַ�������string��������һ����

					string��char * ����

						char * ��һ��ָ��
						string��һ���࣬���ڲ���װ��char*����������ַ�������һ��char*�͵�������

					�ص㣺

						string ���ڲ���װ�˺ܶ��Ա����

						���磺����find������copy��ɾ��delete �滻replace������insert

						string����char*��������ڴ棬���õ��ĸ���Խ���ȡֵԽ��ȣ������ڲ����и���

				3.1.2 string���캯��

					���캯��ԭ�ͣ�

						string();                  //����һ���յ��ַ��� ����: string str; 
						string(const char* s);     //ʹ���ַ���s��ʼ��
						string(const string& str); //ʹ��һ��string�����ʼ����һ��string����
						string(int n, char c);     //ʹ��n���ַ�c��ʼ��

					�ܽ᣺string�Ķ��ֹ��췽ʽû�пɱ��ԣ����ʹ�ü���
*/

#include <iostream>

using namespace std;

//string����
void test01()
{
	string s1; //�������ַ����������޲ι��캯��
	cout << "str1 = " << s1 << endl;

	const char* str = "hello world";
	string s2(str); //��c_stringת������string

	cout << "str2 = " << s2 << endl;

	string s3(s2); //���ÿ������캯��
	cout << "str3 = " << s3 << endl;

	string s4(10, 'a');
	cout << "str3 = " << s3 << endl;
}

int main()
{
	test01();

	return 0;
}