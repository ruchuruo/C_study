
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

					����������

						��string�ַ������в����ɾ���ַ�����

					����ԭ�ͣ�

						string& insert(int pos, const char* s);   //�����ַ���
						string& insert(int pos, const string& str);  //�����ַ���
						string& insert(int pos, int n, char c); //��ָ��λ�ò���n���ַ�c
						string& erase(int pos, int n = npos); //ɾ����Pos��ʼ��n���ַ�

					�ܽ᣺�����ɾ������ʼ�±궼�Ǵ�0��ʼ
*/

#include <iostream>

using namespace std;

//�ַ��������ɾ��
void test01()
{
	string str = "hello";
	str.insert(1, "111");
	cout << str << endl;

	str.erase(1, 3);  //��1��λ�ÿ�ʼ3���ַ�
	cout << str << endl;
}

int main()
{
	test01();

	return 0;
}