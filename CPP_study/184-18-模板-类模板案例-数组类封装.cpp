
#include "184-18-ģ��-��ģ�尸��-�������װmyArray.hpp"

void test01()
{
	MyArray<int> arr1(5);
	MyArray<int> arr2(arr1);

	MyArray<int> arr3(100);
	arr3 = arr1;
}

int main()
{
	test01();

	return 0;
}