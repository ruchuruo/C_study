
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

				3.2.5 vector�����ɾ��

				3.2.6 vector���ݴ�ȡ

				3.2.7 vector��������

					����������

						ʵ������������Ԫ�ؽ��л���

					����ԭ�ͣ�

						swap(vec); // ��vec�뱾���Ԫ�ػ���

					�ܽ᣺swap����ʹ�����������������Դﵽʵ�õ������ڴ�Ч��
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
	vector<int> v2;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(9 - i);
	}

	cout << "����ǰ" << endl;
	printVector(v1);
	printVector(v2);

	// ��vec�뱾���Ԫ�ػ���
	v1.swap(v2);

	cout << "������" << endl;
	printVector(v1);
	printVector(v2);
}

// ʵ�õ������ڴ�
void test02()
{
	cout << endl;

	vector<int> v;

	for (int i = 0; i < 10000; i++)
	{
		v.push_back(i);
	}

	cout << "v������ " << v.capacity() << endl;
	cout << "v�Ĵ�С " << v.size() << endl;
	cout << endl;

	/*
		resize(int num);       //����ָ�������ĳ���Ϊnum���������䳤������Ĭ��ֵ�����λ�á�
						       //���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����

		resize(int num, elem); //����ָ�������ĳ���Ϊnum���������䳤������elemֵ�����λ�á�
							   //���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ��
	*/
	v.resize(3);

	cout << "v������ " << v.capacity() << endl;
	cout << "v�Ĵ�С " << v.size() << endl;
	cout << endl;

	// ����swap�����ڴ�
	/*
		��������
		vector<int>(v)

		�ö��� v ���������� ��������
		vector<int> x(v)

		��������
		.swap(v)
			
			|   ����ǰ
			|       v �� [ ][ ][ ][ ][ ][ ][ ][ ][ ]......
			|
			|       x �� [ ][ ][ ]
			|
			|   ������
			|       x �� [ ][ ][ ][ ][ ][ ][ ][ ][ ]......
			|
			|       v �� [ ][ ][ ]
			|
			|       ָ��ָ��λ�ý���
			|       ���������ص㣺��ǰ�д���ָ���������ͷ�
	*/
	vector<int>(v).swap(v);

	cout << "v������ " << v.capacity() << endl;
	cout << "v�Ĵ�С " << v.size() << endl;
}

int main()
{
	test01();

	test02();

	return 0;
}

/*
	���Ե�Ļ��жĥɱ¿?
*/