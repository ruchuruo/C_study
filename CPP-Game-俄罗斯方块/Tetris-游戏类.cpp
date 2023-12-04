
#include "Tetris-��Ϸ��.h"

const int SPEED_NORMAL = 500;// �ٶ����� ����
const int SPEED_QUICK = 50;  // �ٶȿ��� ����

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
	m_Delay(delay),
	m_BakBlock(this->m_BlockSize)// ���÷��飬�����ഴ����Ҫ����
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
	// ������Ϸ����
	initgraph(800, 600);

	// ���ر���ͼƬ
	loadimage(&this->m_Bgimg, L"res/bg1.png");

	// ��ʼ����Ϸ����

	// �� ��ͼ ��ʼ��
	for (int i = 0; i < this->m_Rows; i++)
	{
		for (int j = 0; j < this->m_Cols; j++)
		{
			this->m_VGameMap[i][j] = 0;
		}
	}
}

// ��ʼ��Ϸ
void Tetris::play()
{
	// ��ʼ��
	this->init();

	// ��ʼ��Ϸǰ��Ҫ�ȴ�������
	// ����Ԥ�淽��
	this->m_NextBlock = new Block(100);

	// ��ǰ���� ���� Ԥ�淽��
	this->m_CurBlock = this->m_NextBlock;

	// ֮�����Ԥ�淽��
	this->m_NextBlock = new Block(100);


	while (true)
	{
		// �����û�����
		this->keyEvent();

		// ��ȡ��һ�ε��øú�������˶��ٺ���
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
	//// �����������Ⱦ
	//this->m_upDateWindow = true;

	//// ������Ⱦ��ʱ��
	//this->m_Timer = 0;
}

// ��Ⱦ��Ϸ����
void Tetris::upDateWindow()
{
	// ���ͼ����˸����ͳһ��Ⱦ
	// ��ʼ��������
	BeginBatchDraw();


	// ���ñ���ͼƬ
	putimage(0, 0, &this->m_Bgimg);

	// ���Է�����ʾ
	//Block b(100);
	//b.draw(10, 10, 10, 10, 30);

	// ��ȡ С����ͼ��ָ������
	IMAGE** retImgs = Block::getImgs();

	// �Ѿ����䵽�ײ��ķ���
	for (int i = 0; i < this->m_Rows; i++)
	{
		for (int j = 0; j < this->m_Cols; j++)
		{
			// �з���
			if (this->m_VGameMap[i][j] != 0)
			{
				// ����̻��ķ�������
				int x = j * this->m_BlockSize + this->m_LeftMargin;
				int y = i * this->m_BlockSize + this->m_TopMargin;

				// ��Ⱦ�̻��ķ���
				// �����е�Ԫ���Ƕ��پ���Ⱦʲô���͵ķ���
				putimage(x, y, retImgs[this->m_VGameMap[i][j] - 1]);
			}
		}
	}

	// ��ǰ������Ⱦ
	this->m_CurBlock->draw(this->m_TopMargin, NULL, this->m_LeftMargin, NULL, 30);

	// Ԥ�淽����Ⱦ
	this->m_NextBlock->draw(this->m_TopMargin, NULL, this->m_LeftMargin + 700, NULL, 30);


	// �����������ƣ���ִ��ָ��������δ��ɵĻ�������
	EndBatchDraw();
}

// ��ȡ��һ�ε��øú�������˶��ٺ���
int Tetris::getDrawDelay()
{
	// �ϴ�ʱ�䣬�ֲ���̬������ֻ��ʼ��һ��
	static unsigned long long lastCurrentTime = 0;

	// ������ϵͳ�������������ĺ��������Ϊ 49.7 �졣
	unsigned long long currentTime =
		GetTickCount();

	if (lastCurrentTime == 0)
	{
		// ֮�󽫲��ǵ�һ�ε���
		lastCurrentTime = currentTime;

		// ��һ�ε��÷���0
		return 0;
	}

	// ���ǵ�һ�ε���
	int ret = currentTime - lastCurrentTime;
	lastCurrentTime = currentTime;
	return ret;
}

// �½�
void Tetris::drop()
{
	// �½�ǰ���浱ǰλ��
	this->m_BakBlock = *this->m_CurBlock;

	// �½�
	this->m_CurBlock->drop();

	// ��鷽��λ���Ƿ�Ϸ�
	//if (!this->m_CurBlock->blockInMap(this->m_VGameMap))
	if (this->m_CurBlock->blockInMap(this->m_VGameMap) == false)
	{
		// �Ƿ�
		// �̻����飬�ñ��÷������̻�
		this->m_BakBlock.solidify(this->m_VGameMap);

		// ��ǰ����û����
		delete this->m_CurBlock;

		// ��Ҫ��һ������
		this->m_CurBlock = this->m_NextBlock;

		// �����·���
		this->m_NextBlock = new Block(100);
	}

}

// ����
void Tetris::clearLine()
{
}
