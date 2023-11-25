#pragma once

// ��Ϸ��
class Tetris
{
public:
	// ��, ��, �ϱ߽����, �±߽����, ��߽����, �ұ߽����, �����С, ��Ⱦ��ʱ
	Tetris(int rows, int cols, int topMargin, int downMargin, int leftMargin, int rightMargin, int blockSize, int delay);
	~Tetris();

	// ��ʼ��
	void init();

	// ��ʼ��Ϸ
	void play();

private:
	// �����û�����
	void keyEvent();

	// ��Ⱦ��Ϸ����
	void upDateWindow();

	// ��ȡ��һ�ε��øú�������˶��ٺ���
	int getDrawDelay();

	// �½�
	void drop();

	// ����
	void clearLine();

private:
	int m_Timer;        // ÿ����Ⱦ��ʱ��
	int m_Delay;        // ��Ⱦ��ʱ
	bool m_upDateWindow;// �Ƿ���Ⱦ
};