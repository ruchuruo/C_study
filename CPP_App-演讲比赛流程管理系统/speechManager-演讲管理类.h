#pragma once

class speechManager
{
public:
	speechManager();
	~speechManager();

	// ��ʾ�˵�
	void show_Menu();

	// ��ʼ
	void start();

	// �˳�
	void exitSystem();

private:
	int NumberOfMatches;// ��������
};

