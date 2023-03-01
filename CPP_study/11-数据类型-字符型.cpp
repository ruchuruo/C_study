
/*
	1 C++初识

	2 数据类型

		2.4 字符型

			作用：字符型变量用于显示单个字符

			语法：char ch = 'a';

			注意1：在显示字符型变量时，用单引号将字符括起来，不要用双引号

			注意2：单引号内只能有一个字符，不可以是字符串

			C和C++中字符型变量只占用 1个字节。
			字符型变量并不是把字符本身放到内存中存储，而是将对应的ASCII编码放入到存储单元

			ASCII码表格：

				|    ASCII值  |   控制字符   |    ASCII值  |   字符    |    ASCII值  |   字符   |    ASCII值  |   字符   |
				| ----------- | ------------ | ----------- | -------- | ----------- | -------- | ----------- | -------- |
				| 0           | NUT          | 32          | (space)  | 64          | @        | 96          | 、       |
				| 1           | SOH          | 33          | !        | 65          | A        | 97          | a        |
				| 2           | STX          | 34          | "        | 66          | B        | 98          | b        |
				| 3           | ETX          | 35          | #        | 67          | C        | 99          | c        |
				| 4           | EOT          | 36          | $        | 68          | D        | 100         | d        |
				| 5           | ENQ          | 37          | %        | 69          | E        | 101         | e        |
				| 6           | ACK          | 38          | &        | 70          | F        | 102         | f        |
				| 7           | BEL          | 39          | ,        | 71          | G        | 103         | g        |
				| 8           | BS           | 40          | (        | 72          | H        | 104         | h        |
				| 9           | HT           | 41          | )        | 73          | I        | 105         | i        |
				| 10          | LF           | 42          | *        | 74          | J        | 106         | j        |
				| 11          | VT           | 43          | +        | 75          | K        | 107         | k        |
				| 12          | FF           | 44          | ,        | 76          | L        | 108         | l        |
				| 13          | CR           | 45          | -        | 77          | M        | 109         | m        |
				| 14          | SO           | 46          | .        | 78          | N        | 110         | n        |
				| 15          | SI           | 47          | /        | 79          | O        | 111         | o        |
				| 16          | DLE          | 48          | 0        | 80          | P        | 112         | p        |
				| 17          | DCI          | 49          | 1        | 81          | Q        | 113         | q        |
				| 18          | DC2          | 50          | 2        | 82          | R        | 114         | r        |
				| 19          | DC3          | 51          | 3        | 83          | S        | 115         | s        |
				| 20          | DC4          | 52          | 4        | 84          | T        | 116         | t        |
				| 21          | NAK          | 53          | 5        | 85          | U        | 117         | u        |
				| 22          | SYN          | 54          | 6        | 86          | V        | 118         | v        |
				| 23          | TB           | 55          | 7        | 87          | W        | 119         | w        |
				| 24          | CAN          | 56          | 8        | 88          | X        | 120         | x        |
				| 25          | EM           | 57          | 9        | 89          | Y        | 121         | y        |
				| 26          | SUB          | 58          | :        | 90          | Z        | 122         | z        |
				| 27          | ESC          | 59          | ;        | 91          | [        | 123         | {        |
				| 28          | FS           | 60          | <        | 92          | /        | 124         | |        |
				| 29          | GS           | 61          | =        | 93          | ]        | 125         | }        |
				| 30          | RS           | 62          | >        | 94          | ^        | 126         | `        |
				| 31          | US           | 63          | ?        | 95          | _        | 127         | DEL      |

			ASCII 码大致由以下 两部分组 成：
				* ASCII 非打印控制字符： ASCII 表上的数字 **0-31** 分配给了控制字符，用于控制像打印机等一些外围设备。
				* ASCII 打印字符：数字 **32-126** 分配给了能在键盘上找到的字符，当查看或打印文档时就会出现。

*/

#include <iostream>

using namespace std;

int main() {

	char ch = 'a';
	cout << ch << endl;
	cout << sizeof(char) << endl;

	//ch = "a";     //错误，不可以用双引号，创建 字符型 变量的时候要用单引号
	//ch = "abcde"; //错误，不可以用双引号
	//ch = 'abcde'; //错误，单引号内只能引用一个字符

	cout << (int)ch << endl; //查看字符a对应的ASCII码
	ch = 98; //可以直接用ASCII给字符型变量赋值
	cout << ch << endl;

	return 0;
}