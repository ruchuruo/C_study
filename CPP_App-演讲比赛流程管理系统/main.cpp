
#include "main.h"
#include "speechManager-�ݽ�������.h"

void test1()
{
	speechManager sm;

	// ��ʾ�˵�
	sm.show_Menu();

	// �û�ѡ��
	int choice = 0;

	do
	{
		cout << "�� ѡ��" << endl;
		cout << "�� ";

		// ����
		cin >> choice;

		switch (choice)
		{
		case 1:// ��ʼ�ݽ�����
			sm.start();
			break;
		case 2:// �鿴�����¼
			break;
		case 3:// ��ձ�����¼
			break;

		case 0:// �˳���������
			sm.exitSystem();
			break;

		default:
			cout << "�������" << endl;
			break;
		}

	} while (choice);
}

int main()
{
	srand((unsigned int)time(NULL));

	test1();
	
	return 0;
}

// system("cls");
// system("pause");