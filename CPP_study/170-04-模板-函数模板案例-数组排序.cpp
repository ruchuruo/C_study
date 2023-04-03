
/*
	��1�׶�C++ ����֮�� ��0��1����

	��2�׶�ʵս-ͨѶ¼����

	��3�׶�-C++���ı��

	��4�׶�ʵս-���ڶ�̬����ҵְ��ϵͳ

	��5�׶�-C++��߱��
		
		���׶���Ҫ���C++ ���ͱ�� �� STL ��������ϸ���⣬̽��C++������ʹ��

		1 ģ��

			1.1 ģ��ĸ���

			1.2 ����ģ��

					1.2.1 ����ģ���﷨

					1.2.2 ����ģ��ע������

					1.2.3 ����ģ�尸��

						����������

							���ú���ģ���װһ������ĺ��������ԶԲ�ͬ�������������������
							�������Ӵ�С�������㷨Ϊѡ������
							�ֱ�����char�����int������в���

						�ܽ᣺ģ�������ߴ��븴�ã���Ҫ��������
*/

#include <iostream>

using namespace std;

//�����ĺ���ģ��
template<typename T>
void mySwap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}


template<class T> // Ҳ�����滻��typename
//����ѡ�����򣬽��ж�����Ӵ�С������
void mySort(T arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        int max = i; //��������±�

        for (int j = i + 1; j < len; j++)
        {
            if (arr[max] < arr[j])// �϶������ֵ �� ����������ֵ ҪС��˵�� j �±��Ԫ�ز������������ֵ
            {
                max = j;// �������ֵ�±�
            }
        }

        if (max != i) //�����������±겻��i����������
        {
            mySwap(arr[max], arr[i]);
        }
    }
}


template<typename T>
void printArray(T arr[], int len)
{

    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}


void test01()
{
    //����char����
    char charArr[] = "bdcfeagh";
    int num = sizeof(charArr) / sizeof(char);
    mySort(charArr, num);
    printArray(charArr, num);
}

void test02()
{
    //����int����
    int intArr[] = { 7, 5, 8, 1, 3, 9, 2, 4, 6 };
    int num = sizeof(intArr) / sizeof(int);
    mySort(intArr, num);
    printArray(intArr, num);
}

int main()
{
    test01();
    test02();

    return 0;
}