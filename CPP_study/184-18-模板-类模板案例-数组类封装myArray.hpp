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
		this->m_Capacity = capacity;
		this->m_Size = 0;

		// ���ݲ�����ʼ����������
		this->pAddress = new T[this->m_Capacity];
	}

	// ��������
	MyArray(const MyArray& arr)
	{
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
	}

	// ���������=����ֹǳ��������������
	
	// ����
	~MyArray()
	{
		if (this->pAddress != NULL)
		{
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
