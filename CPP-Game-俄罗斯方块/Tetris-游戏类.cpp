#include "Tetris-��Ϸ��.h"

// ��, ��, �ϱ߽����, �±߽����, ��߽����, �ұ߽����, �����С, ��Ⱦ��ʱ
Tetris::Tetris(int rows, int cols, int topMargin, int downMargin, int leftMargin, int rightMargin, int blockSize, int delay)
{
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
