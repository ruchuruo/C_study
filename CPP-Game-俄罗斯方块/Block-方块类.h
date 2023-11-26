#pragma once

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
};