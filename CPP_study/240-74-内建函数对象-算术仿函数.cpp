
/*
	��1�׶�C++ ����֮�� ��0��1����

	��2�׶�ʵս-ͨѶ¼����

	��3�׶�-C++���ı��

	��4�׶�ʵս-���ڶ�̬����ҵְ��ϵͳ

	��5�׶�-C++��߱��

		1 ģ��

		2 STL��ʶ

		3 STL- ��������

		4 STL- ��������

			4.1 ��������

			4.2 ν��

			4.3 �ڽ���������

				4.3.1 �ڽ�������������

					���

						STL�ڽ���һЩ��������
						(�Ѿ������˺ܶ�С�����ˣ�ֱ�������þ�����)

					����:

						�����º���
						��ϵ�º���
						�߼��º���

					�÷���

						��Щ�º����������Ķ����÷���һ�㺯����ȫ��ͬ
						ʹ���ڽ�����������Ҫ����ͷ�ļ� #include<functional>

				4.3.2 �����º���

					����������

						ʵ����������
						����negate��һԪ���㣬�������Ƕ�Ԫ����

					�º���ԭ�ͣ�

						template<class T> T plus<T>       //�ӷ��º���
						template<class T> T minus<T>      //�����º���
						template<class T> T multiplies<T> //�˷��º���
						template<class T> T divides<T>    //�����º���
						template<class T> T modulus<T>    //ȡģ�º���
						template<class T> T negate<T>     //ȡ���º���

					�ܽ᣺ʹ���ڽ���������ʱ����Ҫ����ͷ�ļ� #include <functional>
*/

#include <iostream>
#include <functional>

using namespace std;

// ȡ���º���
void test01()
{
	negate<int> n;

	cout << n(50) << endl;
}

// �ӷ��º���
void test02()
{
	// ֻ�����ͬ��������
	plus<int> p;

	cout << p(10, 20) << endl;
}

int main()
{
	// ȡ���º���
	test01();

	// �ӷ��º���
	test02();

	return 0;
}