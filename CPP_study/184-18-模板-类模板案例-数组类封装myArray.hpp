#pragma once

#include <iostream>

using namespace std;

// ������
template <typename T>
class MyArray
{
public:

	// �вι��� (����)
	MyArray(int capacity)
	{
		//cout << "MyArray �вι��� ����" << endl;

		this->m_Capacity = capacity;
		this->m_Size = 0;

		// ���ݲ�����ʼ����������
		this->pAddress = new T[this->m_Capacity];
	}

	// ��������
	MyArray(const MyArray& arr)
	{
		//cout << "MyArray �������� ����" << endl;

		// �������ṩ��
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		//this->pAddress = arr.pAddress;// ǳ��������Ҫ���

		this->pAddress = new T[arr.m_Capacity];// ���

		// �� arr �е����ݶ���������
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}

		/*
			�����ͷž��������⣺
				���Ե�Ļ�����˾�������Ϊ�������캯��һ���Ǵ�������ʱ�õģ��մ����϶�û�ж��������Բ���Ҫ���
		*/
	}

	// ���������=����ֹǳ��������������
	// �������ã���ʽ��̣�a = b = c
	MyArray& operator=(const MyArray& arr)
	{
		//cout << "MyArray ���������= ����" << endl;

		// �ж�ԭ�������Ƿ�������
		if (this->pAddress != NULL)
		{
			// ��������ͷ�
			delete[]pAddress;
			pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}

		// ���
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[arr.m_Capacity];// ���

		// �� arr �е����ݶ���������
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}

		return *this;
	}
	
	// ����
	~MyArray()
	{
		//cout << "MyArray ���� ����" << endl;

		if (this->pAddress != NULL)
		{
			//cout << "MyArray ���� ���� �ͷ�" << endl;

			// ���Ե�Ļ�������Ƕ�����������Ƕ���ָ�����飬���Բ���Ҫдforѭ��ȥ�ͷ�ÿһ������Ԫ��
			delete[]this->pAddress;
			this->pAddress = NULL;
		}
	}

private:
	T* pAddress;	// ����ָ��
	int m_Size;		// Ԫ�ظ���
	int m_Capacity;	// ����
};
