
#include "Block-������.h"
#include <stdlib.h>

/*
	�ڵ��� new Block ʱ�����Զ�����Block��Ĭ�Ϲ��캯��������������Ҫ��������캯����������·���Ĵ�����
	����˹����ı�ʾ�����кܶ࣬�������ʹ��һ����ά���飬��ʾһ�ֶ���˹�����ĳ����̬��Ҳ����˵��
	һ������˹���飬��Ҫʹ��4����ά��������ʾ������̬��4�����򣩡�
	��������ʹ��һ�������ɵķ�ʽ��

	|      0  1
	|   0 [0][1]   [ ][1]   [ ][ ]   [ ][ ]   [ ][ ]   [ ][ ]   [ ][ ]   [ ][ ]
	|   1 [2][3]   [ ][3]   [2][ ]   [ ][3]   [ ][3]   [2][3]   [ ][3]   [2][3]
	|   2 [4][5]   [ ][5]   [4][5]   [4][5]   [4][5]   [ ][5]   [ ][5]   [4][5]
	|   3 [6][7]   [ ][7]   [ ][7]   [6][ ]   [ ][7]   [ ][7]   [6][7]   [ ][ ]

	int blocks[7][4] = {
		1,3,5,7, // I
		2,4,5,7, // Z 1��
		3,5,4,6, // Z 2��
		3,5,4,7, // T
		2,3,5,7, // L
		3,5,7,6, // J
		2,3,4,5, // ��
	};
*/

IMAGE* Block::m_Imgs[7] = { NULL, };// С���������ʼ��
//int Block::m_Size = 100;            // �����С��ʼ��
//int Block::m_SourceBlockSize = 100; // �����С��ʼ��

Block::Block(int sourceBlockSize):
	m_SourceBlockSize(sourceBlockSize)// �زķ����С
{
	// ֻ��Ҫ��ʼ��һ��С��������
	if (this->m_Imgs[0] == NULL)
	{
		// ����ͼƬ
		IMAGE imgTmp;
		/*
			ʹ��EasyX�⺯���е�loadimage����ʱ�����иñ���
			Visual Studio���������ԡ������������ԡ������������ԡ������߼��������߼����ԡ��ҡ��ַ��������óɡ�ʹ�ö��ֽ��ַ��������ɽ����

			��

			��ͼƬ����ǰ�Ӹ���ĸ��L����_T���������ɣ�ʾ�����£�
				loadimage(0,L"2.jpg");
				loadimage(0,_T("2.jpg"));
		*/
		//       ���ص�,     ͼƬ��ַ
		loadimage(&imgTmp, L"res/tiles.png");
		
		// ����кܶ�СͼƬ��ռ�úܶ�洢�ռ�
		// ͼƬ�и�

		// �����и����
		SetWorkingImage(&imgTmp);

		// ��7��
		for (int i = 0; i < 7; i++)
		{
			// �� m_Imgs ��������ڴ�
			m_Imgs[i] = new IMAGE;

			// �и�
			//       �ŵ�,      ��X,             ��Y, �и��,        �и��
			getimage(m_Imgs[i], i * this->m_SourceBlockSize, 0, this->m_SourceBlockSize, this->m_SourceBlockSize);
		}

		// �ָ�����ͼ��
		SetWorkingImage();
	}

	int blocks[7][4] =
	{
		1,3,5,7, // I
		2,4,5,7, // Z 1��
		3,5,4,6, // Z 2��
		3,5,4,7, // T
		2,3,5,7, // L
		3,5,7,6, // J
		2,3,4,5, // ��
	};

	// �������һ�ֶ���˹����
	this->m_BlockType =
		1 + rand() % 7;// 1 - 7

	// ��ʼ�� m_SmallBlocks
	for (int i = 0; i < 4; i++)
	{
		int val = blocks[m_BlockType - 1][i];

		// �����Ǽ���С���������
		this->m_SmallBlocks[i].row = val / 2;
		this->m_SmallBlocks[i].col = val % 2;
	}

	// ָ��ͼƬ
	this->m_Img = this->m_Imgs[this->m_BlockType - 1];
}

Block::~Block()
{
}

// �½�
void Block::drop()
{
}

// ����
void Block::moveLeft()
{
}

// ����
void Block::moveRight()
{
}

// ��ת
void Block::rotate()
{
}

// ���� �ϱ߽����, �±߽����, ��߽����, �ұ߽����, �����С
void Block::draw(int topMargin, int downMargin, int leftMargin, int rightMargin, int blockSize)
{
	// 4��С����
	for (int i = 0; i < 4; i++)
	{
		// ����С�����λ��
		//int x = leftMargin + this->m_SmallBlocks[i].col * this->m_Size;
		//int y = topMargin + this->m_SmallBlocks[i].row * this->m_Size;
		int x = leftMargin + this->m_SmallBlocks[i].col * blockSize;
		int y = topMargin + this->m_SmallBlocks[i].row * blockSize;

		// ����ͼ���С
		Resize(this->m_Img, blockSize, blockSize);

		// ����ͼ��
		putimage(x, y, this->m_Img);
	}
}
