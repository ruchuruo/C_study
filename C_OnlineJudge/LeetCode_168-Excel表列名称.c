
/*
	168. Excel�������� https://leetcode.cn/problems/excel-sheet-column-title/

	�Ѷȣ���

		����һ������ columnNumber ���������� Excel �������Ӧ�������ơ�

		���磺
			A -> 1
			B -> 2
			C -> 3
			...
			Z -> 26
			AA -> 27
			AB -> 28 
			...
 

		ʾ�� 1��
			���룺columnNumber = 1
			�����"A"

		ʾ�� 2��
			���룺columnNumber = 28
			�����"AB"

		ʾ�� 3��
			���룺columnNumber = 701
			�����"ZY"

		ʾ�� 4��
			���룺columnNumber = 2147483647
			�����"FXSHRXW"
 

		��ʾ��
			1 <= columnNumber <= 231 - 1
*/
/*
	ģ��
		����һ���� 1 ��ʼ�ĵ� 26 ����ת���⡣

		����һ���ԵĽ���ת����Ŀ��ֻ��Ҫ���ϵض� columnNumbercolumnNumbercolumnNumber ���� % ����ȡ�����һλ��Ȼ��� columnNumbercolumnNumbercolumnNumber ���� / ���㣬���Ѿ�ȡ�õ�λ��ȥ����ֱ�� columnNumbercolumnNumbercolumnNumber Ϊ 000 ���ɡ�

		һ���ԵĽ���ת����Ŀ������ж������������Ϊ�������ڡ�ÿһλ��ֵ��Χ�� [0,x)[0,x)[0,x)����ǰ���½��С��� xxx ��һ����

		��������Ҫ���ǽ��� 111 ��ʼ�������ִ�С�����ת��������ǰ��������Ҫ�ȶ� columnNumbercolumnNumbercolumnNumber ִ�м�һ�������Ӷ�ʵ������ƫ�ơ�

		���ߣ���ˮ��Ҷ
		���ӣ�https://leetcode.cn/problems/excel-sheet-column-title/solutions/849680/gong-shui-san-xie-cong-1-kai-shi-de-26-j-g2ur/
		��Դ�����ۣ�LeetCode��
		����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/

void reverse(char* ch, int size)
{
	int left = 0;
	int right = size - 1;

	while (left < right)
	{
		char tmp = ch[left];
		ch[left] = ch[right];
		ch[right] = tmp;

		left++;
		right--;
	}

	return ch;
}

char* convertToTitle(int columnNumber)
{
	char* pc = (char*)malloc(sizeof(char) * 100);
	int pcSize = 0;

	while (columnNumber > 0)
	{
		columnNumber--;

		pc[pcSize++] = columnNumber % 26 + 'A';

		columnNumber /= 26;
	}

	pc[pcSize] = 0;
	reverse(pc, pcSize);

	return pc;
}

int main()
{

	return 0;
}