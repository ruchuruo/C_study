
#include "my_h.h"
#include easyx_h

// ���ڴ���
void test1()
{
	// ��������
	//        �� , ��
	//initgraph(800, 600);

	// ����ͼ�δ���ʱ��������̨����
	initgraph(800, 600, EX_SHOWCONSOLE);

	// ���ùرհ�ť
	//initgraph(800, 600, EX_NOCLOSE);

	// ������С����ť
	//initgraph(800, 600, EX_NOMINIMIZE);

	// �����Ҫʹ��
	//initgraph(800, 600, EX_SHOWCONSOLE | EX_NOCLOSE | EX_NOMINIMIZE);

	/*
		// EasyX Window Properties // EasyX��������
		#define EX_SHOWCONSOLE		1		// Maintain the console window when creating a graphics window // ����ͼ�δ���ʱ��������̨����
		#define EX_NOCLOSE			2		// Disable the close button                                    // ���ùرհ�ť
		#define EX_NOMINIMIZE		4		// Disable the minimize button                                 // ������С����ť
		#define EX_DBLCLKS			8		// Support double-click events                                 // ֧��˫���¼�
	*/
}

// ���ڱ�����ɫ
void test2()
{
	// ����ͼ�δ���ʱ��������̨����
	initgraph(800, 600, EX_SHOWCONSOLE);

	// ��������������õ�ǰ�豸��ͼ����ɫ��
	// ��ɫ
	//setbkcolor(WHITE);

	// �Զ�����ɫ
	// ��FFC0CB	rgb��255,192,203��
	//setbkcolor(0XFFC0CB);
	setbkcolor(RGB(255, 192, 203));

	// ��ʱ��������ʾ��ɫ
	// ��Ҫ
	// �������ʹ�õ�ǰ����ɫ��ջ�ͼ�豸��
	cleardevice();

	/*
		// Color constant // ��ɫ����
		#define	BLACK			0
		#define	BLUE			0xAA0000
		#define	GREEN			0x00AA00
		#define	CYAN			0xAAAA00
		#define	RED				0x0000AA
		#define	MAGENTA			0xAA00AA
		#define	BROWN			0x0055AA
		#define	LIGHTGRAY		0xAAAAAA
		#define	DARKGRAY		0x555555
		#define	LIGHTBLUE		0xFF5555
		#define	LIGHTGREEN		0x55FF55
		#define	LIGHTCYAN		0xFFFF55
		#define	LIGHTRED		0x5555FF
		#define	LIGHTMAGENTA	0xFF55FF
		#define	YELLOW			0x55FFFF
		#define	WHITE			0xFFFFFF
	*/
}

// ����������ϵ
void test3()
{
	/*
		�������Ͻ�������ԭ��
		������������������

		|   +-------------+
		|   |window    -���|
		|   +-------------+--�� X
		|   |             |
		|   |             |
		|   |             |
		|   |             |
		|   |             |
		|   +-------------+
		|   |
		|   ��
		|   Y
	*/
}

int main()
{
	// ���ڴ���
	//test1();

	// ���ڱ�����ɫ
	test2();

	// ����������ϵ
	//test3();

	// �����������
	system("pause");

	return 0;
}