
/*
	��1�׶�C++ ����֮�� ��0��1����

	��2�׶�ʵս-ͨѶ¼����

	��3�׶�-C++���ı��

	��4�׶�ʵս-���ڶ�̬����ҵְ��ϵͳ

	��5�׶�-C++��߱��

		1 ģ��

		2 STL��ʶ

			2.1 STL�ĵ���

			2.2 STL��������

			2.3 STL�������

			2.4 STL���������㷨��������

			2.5 �����㷨��������ʶ

				�˽�STL���������㷨������������֮���������ô������STL������

				STL����õ�����ΪVector���������Ϊ���飬�������ǽ�ѧϰ�������������в������ݡ��������������

				2.5.1 vector���������������

					������ vector

					�㷨�� for_each

					�������� vector<int>::iterator
*/

#include <iostream>
#include <vector>   // ���� vector ��ͷ�ļ�
#include <algorithm>// ��׼�㷨ͷ�ļ�

using namespace std;

void myPrint(int val)
{
	cout << val << " ";
}

void test01()
{
	// ��Ҫͷ�ļ� <vector>
	vector<int> v;

	// β��
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);



	// ͨ�� ������ ���������е�����
	// begin() ��ʼ��������ָ�������е�һ��Ԫ��
	//  ��
	// [10][20][30][40]
	vector<int>::iterator itBegin = v.begin();

	// end() ������������ָ�����������һ��Ԫ�ص���һ��λ��
	//                  ��
	// [10][20][30][40][??]
	vector<int>::iterator itEnd = v.end();



	// ����
	// ��ʽ1
	while (itBegin != itEnd)
	{
		// ������ itBegin
		cout << *itBegin << " ";
		itBegin++;
	}
	cout << endl;

	// ��ʽ2
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	// ��ʽ3 ����STL�ṩ�ı����㷨����Ҫͷ�ļ� <algorithm>
	/*
		template <class InputIterator, class Function>
		Function for_each(InputIterator first, InputIterator last, Function fn);
		                                ��ʼ                 ����           ����
			
		����
			first, last
				Input iterators to the initial and final positions in a sequence. The range used is [first,last), which contains all the elements between first and last, including the element pointed by first but not the element pointed by last.
				�����������뵽�����еĳ�ʼλ�ú�����λ�á�ʹ�õķ�Χ�� �������� �� ֮�������Ԫ�أ����� ָ���Ԫ�أ���������ָ���Ԫ�ء�

			fn
				Unary function that accepts an element in the range as argument.
				This can either be a function pointer or a move constructible function object.
				Its return value, if any, is ignored.
				���ܷ�Χ�ڵ�Ԫ����Ϊ������һԪ������
				������Ǻ���ָ����ƶ��ɹ��캯������
				���ķ���ֵ������У��������ԡ�

		����ֵ
			C++98
				Returns fn.

			C++11
				Returns fn, as if calling std::move(fn).
	*/
	for_each(v.begin(), v.end(), myPrint);
}

int main()
{
	test01();

	return 0;
}

/*
	���Ե�Ļ������STL���Կ���STLԴ��������
*/