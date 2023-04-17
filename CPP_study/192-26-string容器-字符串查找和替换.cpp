
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

					����������

						���ң�����ָ���ַ����Ƿ����
						�滻����ָ����λ���滻�ַ���

					����ԭ�ͣ�

						int find(const string& str, int pos = 0) const;     //����str��һ�γ���λ��,��pos��ʼ����
						int find(const char* s, int pos = 0) const;         //����s��һ�γ���λ��,��pos��ʼ����
						int find(const char* s, int pos, int n) const;      //��posλ�ò���s��ǰn���ַ���һ��λ��
						int find(const char c, int pos = 0) const;          //�����ַ�c��һ�γ���λ��
						int rfind(const string& str, int pos = npos) const; //����str���һ��λ��,��pos��ʼ����
						int rfind(const char* s, int pos = npos) const;     //����s���һ�γ���λ��,��pos��ʼ����
						int rfind(const char* s, int pos, int n) const;     //��pos����s��ǰn���ַ����һ��λ��
						int rfind(const char c, int pos = 0) const;         //�����ַ�c���һ�γ���λ��
						string& replace(int pos, int n, const string& str); //�滻��pos��ʼn���ַ�Ϊ�ַ���str
						string& replace(int pos, int n,const char* s);      //�滻��pos��ʼ��n���ַ�Ϊ�ַ���s

					�ܽ᣺

						find�����Ǵ�������rfind��������
						find�ҵ��ַ����󷵻ز��ҵĵ�һ���ַ�λ�ã��Ҳ�������-1
						replace���滻ʱ��Ҫָ�����ĸ�λ���𣬶��ٸ��ַ����滻��ʲô�����ַ���
*/

#include <iostream>

using namespace std;

//����
void test01()
{
	//����
	string str1 = "abcdefgde";

	int pos = str1.find("de");

	if (pos == -1)
	{
		cout << "δ�ҵ�" << endl;
	}
	else
	{
		cout << "pos = " << pos << endl;
	}


	pos = str1.rfind("de");

	cout << "pos = " << pos << endl;

}

//�滻
void test02()
{
	//�滻
	string str1 = "abcdefgde";
	str1.replace(1, 3, "1111");

	/*
		������滻�ǽ� str1 �е�3���ַ��滻��4�� 1
		�� 1��λ�� �� 3���ַ� �滻�� 1111

		"abcd efgde"
		"a    efgde"
		"a1111efgde"
	*/

	cout << "str1 = " << str1 << endl;
}

int main()
{
	//����
	test01();

	//�滻
	test02();

	return 0;
}