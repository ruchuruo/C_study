
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

					����������

						ʵ�����ַ���ĩβƴ���ַ���

					����ԭ�ͣ�

						string& operator+=(const char* str);             //����+=������
						string& operator+=(const char c);                //����+=������
						string& operator+=(const string& str);           //����+=������
						string& append(const char *s);                   //���ַ���s���ӵ���ǰ�ַ�����β
						string& append(const char *s, int n);            //���ַ���s��ǰn���ַ����ӵ���ǰ�ַ�����β
						string& append(const string &s);                 //ͬoperator+=(const string& str)
						string& append(const string &s, int pos, int n); //�ַ���s�д�pos��ʼ��n���ַ����ӵ��ַ�����β

					�ܽ᣺�ַ���ƴ�ӵ����ذ汾�ܶ࣬��ѧ�׶μ�ס���ּ���
*/

#include <iostream>

using namespace std;

//�ַ���ƴ��
void test01()
{
	string str1 = "��";

	str1 += "������Ϸ";

	cout << "str1 = " << str1 << endl;

	str1 += ':';

	cout << "str1 = " << str1 << endl;

	string str2 = "LOL DNF";

	str1 += str2;

	cout << "str1 = " << str1 << endl;

	string str3 = "I";
	str3.append(" love ");
	str3.append("game abcde", 4);
	//str3.append(str2);
	str3.append(str2, 4, 3); // ���±�4λ�ÿ�ʼ ����ȡ3���ַ���ƴ�ӵ��ַ���ĩβ
	cout << "str3 = " << str3 << endl;
}
int main()
{
	test01();

	return 0;
}