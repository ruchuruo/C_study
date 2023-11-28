
#include "Tetris-��Ϸ��.h"

Tetris::Tetris
(
	int rows,       // ��
	int cols,       // ��
	int topMargin,  // �ϱ߽����
	int downMargin, // �±߽����
	int leftMargin, // ��߽����
	int rightMargin,// �ұ߽����
	int blockSize,  // �����С
	int delay       // ��Ⱦ��ʱ
):
	m_Rows(rows),
	m_Cols(cols),
	m_TopMargin(topMargin),
	m_LeftMargin(leftMargin),
	m_BlockSize(blockSize),
	m_Delay(delay)
{
	// �� ��ͼ ��ʼ��
	for (int i = 0; i < this->m_Rows; i++)
	{
		// ���� ��
		vector<int> mapRow;

		for (int j = 0; j < this->m_Cols; j++)
		{
			// ���� �� ��ʼ��
			mapRow.push_back(0);
		}

		// �� ��ͼ �������� ��
		this->m_VGameMap.push_back(mapRow);
	}
}

Tetris::~Tetris()
{
}

// ��ʼ��
void Tetris::init()
{
}

// ��ʼ��Ϸ
void Tetris::play()
{
	// ��ʼ��
	this->init();

	while (true)
	{
		// �����û�����
		this->keyEvent();

		this->m_Timer += this->getDrawDelay();

		if (this->m_Timer > this->m_Delay)
		{
			// �½�
			this->drop();

			// ʱ�䵽ʱȷ����Ⱦ
			this->m_upDateWindow = true;

			// ������Ⱦ��ʱ��
			this->m_Timer = 0;
		}

		// ȷ����Ⱦ
		if (this->m_upDateWindow == true)
		{
			// ��Ⱦ��Ϸ����(������Ϸ����)
			this->upDateWindow();

			// ��Ⱦ��ֹͣ��Ⱦ
			this->m_upDateWindow = false;

			// ������Ϸ�������(����)
			this->clearLine();
		}
		
	}
}

// �����û�����
void Tetris::keyEvent()
{
	// �����������Ⱦ
	this->m_upDateWindow = true;

	// ������Ⱦ��ʱ��
	this->m_Timer = 0;
}

// ��Ⱦ��Ϸ����
void Tetris::upDateWindow()
{
}

// ��ȡ��һ�ε��øú�������˶��ٺ���
int Tetris::getDrawDelay()
{
	// ��һ�ε��÷���0

	return 0;
}

// �½�
void Tetris::drop()
{
}

// ����
void Tetris::clearLine()
{
}
