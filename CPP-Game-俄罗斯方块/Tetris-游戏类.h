#pragma once

#include <vector>
#include "EasyX_2023�����/include/graphics.h"

using namespace std;

// ��Ϸ��
class Tetris
{
public:

	Tetris
	(
		int rows,       // ��
		int cols,       // ��
		int topMargin,  // �ϱ߽����
		int downMargin, // �±߽����
		int leftMargin, // ��߽����
		int rightMargin,// �ұ߽����
		int blockSize,  // �����С
		int delay       // ��Ⱦ��ʱ
	);
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
	int m_Timer;                   // ÿ����Ⱦ��ʱ��
	int m_Delay;                   // ��Ⱦ��ʱ
	bool m_upDateWindow;           // �Ƿ���Ⱦ

	vector<vector<int>> m_VGameMap;// ��ͼ����ά���飬�����Ϸ����(0��ʾû���飬������ֵ��ʾ�������࣬����5��ʾ��5�ַ���)
	int m_Rows;                    // ��
	int m_Cols;                    // ��
	int m_TopMargin;               // �ϱ߽����
	int m_LeftMargin;              // ��߽����
	int m_BlockSize;               // �����С
	IMAGE m_Bgimg;                 // ����ͼƬ
};