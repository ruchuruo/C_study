
#include "ͨѶ¼.h"

/**********************************************************************************************/

void ͨѶ¼����(ͨѶ¼* pc)
{
	if (pc->sz == pc->����)
	{
		// ����
		��Ϣ* ptr = (��Ϣ*)realloc(pc->����, (pc->���� + ����sz) * sizeof(��Ϣ));// �� ���� ���� (��ǰ������� �� ����sz) �� sizeof(��Ϣ)
		if (ptr != NULL)
		{
			pc->���� = ptr;
			pc->���� += ����sz;
			printf("���ݳɹ�\n");
		}
		else
		{
			perror("������ϵ��");
			printf("������ϵ��ʧ��\n");
			return;
		}
	}
}

/**********************************************************************************************/

void �����ļ�(ͨѶ¼* pc)
{
	FILE* pf = fopen("ͨѶ¼��Ϣ.txt", "r");
	if (pf == NULL)
	{
		perror("�����ļ�");
		return;
	}

	// ���ļ�
	��Ϣ ��ʱ = { 0 };
	
	while (fread(&��ʱ, sizeof(��Ϣ), 1, pf))// �����������ݾͷ��ض���
	{
		// �Ƿ���Ҫ����
		ͨѶ¼����(pc);
		pc->����[pc->sz] = ��ʱ;
		pc->sz++;
	}

	// �ر��ļ�
	fclose(pf);
	pf = NULL;
}

/**********************************************************************************************/

//void ��ʼ��ͨѶ¼(ͨѶ¼* pc)
//{
//	pc->sz = 0;
//	memset(pc->����, 0, sizeof(pc->����));// �ڴ����ã���������������Ԫ��Ϊ����0
//}

// �汾2
//void ��ʼ��ͨѶ¼(ͨѶ¼* pc)
//{
//	// �� ���� ����һ�������Ŀռ��� ���� ��
//	pc->���� = (��Ϣ*)malloc(Ĭ��sz * sizeof(��Ϣ));// Ĭ�ϴ�С �� һ���˵���Ϣ������ֵǿ������ת����(��Ϣ*)
//
//	if (pc->���� == NULL)
//	{
//		perror("��ʼ��ͨѶ¼");
//		return;
//	}
//
//	pc->sz = 0;
//	pc->���� = Ĭ��sz;
//}

// �汾3
void ��ʼ��ͨѶ¼(ͨѶ¼* pc)
{
	// �� ���� ����һ�������Ŀռ��� ���� ��
	pc->���� = (��Ϣ*)malloc(Ĭ��sz * sizeof(��Ϣ));// Ĭ�ϴ�С �� һ���˵���Ϣ������ֵǿ������ת����(��Ϣ*)

	if (pc->���� == NULL)
	{
		perror("��ʼ��ͨѶ¼");
		return;
	}

	pc->sz = 0;
	pc->���� = Ĭ��sz;

	// �����ļ�
	�����ļ�(pc);
}

/**********************************************************************************************/

void �˳�ͨѶ¼(ͨѶ¼* pc)
{
	free(pc->����);
	pc->���� = NULL;
	pc->sz = 0;
	pc->���� = 0;

	printf("�˳��ɹ�\n");
}

/**********************************************************************************************/

void ������Ϣ(ͨѶ¼* pc)
{
	FILE* pf = fopen("ͨѶ¼��Ϣ.txt", "w");
	if (pf == NULL)
	{
		perror("������Ϣ");
		return;
	}

	// д�ļ�
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		fwrite(pc->���� + i, sizeof(��Ϣ), 1, pf);// fwrite��Ҫ��ַ������ ����[i] �ĳ� ����+i
	}


	// �ر��ļ�
	fclose(pf);
	pf = NULL;
}

/**********************************************************************************************/

//void ������ϵ��(ͨѶ¼* pc)
//{
//	if (pc->sz == �����Ϣ)
//	{
//		printf("ͨѶ¼����\n");
//		return;// ��Ȼ����Ҫ���أ����ǵ�����Ҫ��������
//	}
//	
//	// ����һ���˵���Ϣ
//	printf("������+����++>");
//	scanf("%s", pc->����[pc->sz].����);// ������һ�����飬���Բ���Ҫȡ��ַ
//
//	printf("������+����++>");
//	scanf("%d", &(pc->����[pc->sz].����));// ������һ����������������Ҫ������ȡ��ַ
//
//	printf("������+�Ա�++>");
//	scanf("%s", pc->����[pc->sz].�Ա�);
//
//	printf("������+�绰++>");
//	scanf("%s", pc->����[pc->sz].�绰);
//
//	printf("������+��ַ++>");
//	scanf("%s", pc->����[pc->sz].��ַ);
//
//	pc->sz++;// ������++
//
//	printf("���ӳɹ�\n");
//
//	/*
//		pc->����[pc->sz];
//		���ӵ�pcָ���ͨѶ¼�� ���� �������棬�±�Ϊsz��λ����
//	*/
//}

// �汾2
void ������ϵ��(ͨѶ¼* pc)
{

	// ͨѶ¼����
	ͨѶ¼����(pc);

	// ����һ���˵���Ϣ
	printf("������+����++>");
	scanf("%s", pc->����[pc->sz].����);// ������һ�����飬���Բ���Ҫȡ��ַ

	printf("������+����++>");
	scanf("%d", &(pc->����[pc->sz].����));// ������һ����������������Ҫ������ȡ��ַ

	printf("������+�Ա�++>");
	scanf("%s", pc->����[pc->sz].�Ա�);

	printf("������+�绰++>");
	scanf("%s", pc->����[pc->sz].�绰);

	printf("������+��ַ++>");
	scanf("%s", pc->����[pc->sz].��ַ);

	pc->sz++;// ������++

	printf("���ӳɹ�\n");

	/*
		pc->����[pc->sz];
		���ӵ�pcָ���ͨѶ¼�� ���� �������棬�±�Ϊsz��λ����
	*/
}

/**********************************************************************************************/

void ��ʾ��ϵ��(const ͨѶ¼* pc)
{
	// ��ӡ����
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n", "����", "�Ա�", "����", "�绰", "��ַ");

	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		printf("%-20s\t%-5s\t%-5d\t%-12s\t%-20s\n", 
			pc->����[i].����, 
			pc->����[i].�Ա�, 
			pc->����[i].����, 
			pc->����[i].�绰, 
			pc->����[i].��ַ
		);
	}
}

/**********************************************************************************************/

static int ���Ұ�����(ͨѶ¼* pc, char ����[])// �����������Դ�ļ�����Ҫ�����Լ���static
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->����[i].����, ����) == 0)
		{
			return i;
		}
	}

	return -1;
}

void ɾ����ϵ��(ͨѶ¼* pc)
{
	if (pc->sz == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
		return;// ��Ȼ����Ҫ���أ����ǵ�����Ҫ��������
	}

	char ����[�������] = { 0 };

	printf("������-����-->");

	scanf("%s", ����);

	// ����Ҫɾ������
	int �±� = ���Ұ�����(pc, ����);

	if (�±� == -1)
	{
		printf("���޴���\n");
		return;
	}

	// ɾ��
	// ��Ҫɾ���� λ�� ֮�� ��������ǰ�ƶ�
	// 1 2 3 4 5 6 7
	//     3 ������
	// 1 2 4 5 6 7
	// 
	// ���һ��Ԫ�ز���Ҫ����
	// sz-- ֮��ͷ��ʲ�����
	//             ��
	// 1 2 4 5 6 7 7
	// 
	// ɾ�����һ��Ԫ��
	// ��Ȼ����ȥѭ��������sz-- ֮��ͷ��ʲ�����
	int i = 0;
	for (i = �±�; i < pc->sz - 1; i++)
	{
		pc->����[i] = pc->����[i + 1];
	}

	pc->sz--;

	printf("ɾ���ɹ�\n");
}

/**********************************************************************************************/

void ������ϵ��(const ͨѶ¼* pc)
{
	char ����[�������] = { 0 };

	printf("������@����@@>");

	scanf("%s", ����);

	int �±� = ���Ұ�����(pc, ����);

	if (�±� == -1)
	{
		printf("���޴���\n");
		return;
	}
	else
	{
		printf("%-20s\t%-5s\t%-5d\t%-12s\t%-20s\n",
			pc->����[�±�].����,
			pc->����[�±�].�Ա�,
			pc->����[�±�].����,
			pc->����[�±�].�绰,
			pc->����[�±�].��ַ
		);
	}
}

/**********************************************************************************************/

void �޸���ϵ��(ͨѶ¼* pc)
{
	// ����
	char ����[�������] = { 0 };

	printf("������/����//>");

	scanf("%s", ����);

	int �±� = ���Ұ�����(pc, ����);

	if (�±� == -1)
	{
		printf("���޴���\n");
		return;
	}
	else
	{
		// ����
		// ����һ���˵���Ϣ
		printf("������+����++>");
		scanf("%s", pc->����[�±�].����);// ������һ�����飬���Բ���Ҫȡ��ַ

		printf("������+����++>");
		scanf("%d", &(pc->����[�±�].����));// ������һ����������������Ҫ������ȡ��ַ

		printf("������+�Ա�++>");
		scanf("%s", pc->����[�±�].�Ա�);

		printf("������+�绰++>");
		scanf("%s", pc->����[�±�].�绰);

		printf("������+��ַ++>");
		scanf("%s", pc->����[�±�].��ַ);

		printf("�޸ĳɹ�\n");
	}

	
}