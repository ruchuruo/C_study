
/*
	168. Excel表列名称 https://leetcode.cn/problems/excel-sheet-column-title/

	难度：简单

		给你一个整数 columnNumber ，返回它在 Excel 表中相对应的列名称。

		例如：
			A -> 1
			B -> 2
			C -> 3
			...
			Z -> 26
			AA -> 27
			AB -> 28 
			...
 

		示例 1：
			输入：columnNumber = 1
			输出："A"

		示例 2：
			输入：columnNumber = 28
			输出："AB"

		示例 3：
			输入：columnNumber = 701
			输出："ZY"

		示例 4：
			输入：columnNumber = 2147483647
			输出："FXSHRXW"
 

		提示：
			1 <= columnNumber <= 231 - 1
*/
/*
	模拟
		这是一道从 1 开始的的 26 进制转换题。

		对于一般性的进制转换题目，只需要不断地对 columnNumbercolumnNumbercolumnNumber 进行 % 运算取得最后一位，然后对 columnNumbercolumnNumbercolumnNumber 进行 / 运算，将已经取得的位数去掉，直到 columnNumbercolumnNumbercolumnNumber 为 000 即可。

		一般性的进制转换题目无须进行额外操作，是因为我们是在「每一位数值范围在 [0,x)[0,x)[0,x)」的前提下进行「逢 xxx 进一」。

		但本题需要我们将从 111 开始，因此在执行「进制转换」操作前，我们需要先对 columnNumbercolumnNumbercolumnNumber 执行减一操作，从而实现整体偏移。

		作者：宫水三叶
		链接：https://leetcode.cn/problems/excel-sheet-column-title/solutions/849680/gong-shui-san-xie-cong-1-kai-shi-de-26-j-g2ur/
		来源：力扣（LeetCode）
		著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
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