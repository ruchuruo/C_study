
/*
	https://blog.csdn.net/pzjdoytt/article/details/125325753

	������־

		1.������Ŀ
		2.�����ز�
		3.c++����
		4.���c++��Ŀ��ģ��
		  �����(�����ࡢ��Ϸ��)

		5.��ƽӿ�
		6.������Ϸ

��800*��600

P3
3-�����Ϸ��ѭ��
27:19
*/

#include "Tetris-��Ϸ��.h"
#include <stdlib.h>
#include <time.h>

int main(void)
{
	//srand(time(NULL));

	Tetris t(20, 10, 10, 10, 10, 10, 78, 30);

	t.play();

	return 0;
}