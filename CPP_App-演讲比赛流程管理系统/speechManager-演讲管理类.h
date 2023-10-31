#pragma once

class speechManager
{
public:
	speechManager();
	~speechManager();

	// 显示菜单
	void show_Menu();

	// 开始
	void start();

	// 退出
	void exitSystem();

private:
	int NumberOfMatches;// 比赛次数
};

