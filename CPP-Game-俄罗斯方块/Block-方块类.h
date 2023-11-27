#pragma once

#include "EasyX_2023�����/include/easyx.h"
#include "EasyX_2023�����/include/graphics.h"

struct Point
{
	int row;// ��
	int col;// ��
};

// ������
class Block
{
public:
	Block();
	~Block();

	// �½�
	void drop();

	// ����
	void moveLeft();
	
	// ����
	void moveRight();

	// ��ת
	void rotate();

	// ���� �ϱ߽����, �±߽����, ��߽����, �ұ߽����, �����С
	void draw(int topMargin, int downMargin, int leftMargin, int rightMargin, int blockSize);

private:
	int m_blockType;              // ��������
	struct Point m_smallBlocks[4];// С�������λ��

	IMAGE *m_Img;                 // ͼ��ָ�룬����ָ��m_Imgs����ΪͼƬһ�������Բ���Ҫ�ܶ��
	static IMAGE *m_Imgs[7];      // С����ͼ��ָ�����飬��̬�������๲��
	static int m_Size;            // �����С
};