
/*
	几种常见的程序命名规则 https://www.cnblogs.com/sonys/archive/2011/10/03/2198531.html

		正确并形象地给函数、变量命名，不仅可以增加程序的可读性，也是程序员编程风格的一种反映。
		较好的命名习惯，可以有效的提高程序的可维护性。以下介绍几种常用的变量命名规则。


		一、匈牙利命名法：广泛应用于Microsoft Windows这类环境中。

			这种命名技术是由一位能干的 Microsoft 程序员查尔斯·西蒙尼(Charles Simonyi) 提出的。匈牙利命名法通过在变量名前面加上相应的小写字母的符号标识作为前缀，标识出变量的作用域，类型等。这些符号可以多个同时使用，顺序是先m_（成员变 量），再指针，再简单数据类型，再其他。例如：m_lpszStr, 表示指向一个以0字符结尾的字符串的长指针成员变量。

			匈牙利命名法关键是：标识符的名字以一个或者多个小写字母开头作为前缀；前缀之后的是首字母大写的一个单词或多个单词组合，该单词要指明变量的用途。

			例如：bEnable, nLength, hWnd。

			| 前缀  | 类型                   | 描述 |
			| a     | Array                  | 数组
			| b     | BOOL                   | 布尔
			| by    | BYTE                   | 无符号字符
			| c     | char                   | 字符
			| cb    | Count of bytes         | 字节数
			| cr    | Color reference value  | 颜色值
			| cx,cy | Count of x,y(short)    | 长度
			| dw    | DWORD                  | 双字(无符号长整形)
			| f     | Flags                  | 标志
			| fn    | Function               | 函数
			| g_    | Global                 | 全局的
			| h     | HANDLE                 | 句柄
			| i     | Integer(int)           | 整数
			| l     | Long(long)             | 长整数
			| lp    | Long point             | 长指针
			| m_    | Data member of a class | 类的数据成员
			| n     | Short(short)           | 短整型
			| np    | Near point             | 短指针
			| p     | Point                  | 指针
			| s     | String                 | 字符串
			| sz    | Zero terminated string | 以0结尾的字符串
			| tm    | Text metric            | 文本规则
			| u     | Unsigned int           | 无符号整数
			| ul    | Unsigned long(ULONG)   | 无符号长整数
			| w     | WORD                   | 无符号短整数
			| x,y   | x,y coordinates(short) | 坐标
			| v     | Void                   | 空

			有关项目的全局变量用g_开始，类成员变量用m_。

			| 前缀 | 类型     | 例子 |
			| C    | 类       | CDocument, CPrintInfo
			| m_   | 成员变量 | m_pDoc, m_nCustomers
			| g_   | 全局变量 | g_Servers


		二、驼峰命名法：近年来越来越流行。

			驼峰命名法，正如它的名称所表示的那样，指的是混合使用大小写字母来构成标识符的名字。其中第一个单词首字母小写，余下的单词首字母大写。

			例如：
				printEmployeePaychecks();

			函数名中每一个逻辑断点都有一个大写字母来标记。


		三、帕斯卡（Pascal）命名法：与驼峰命名法类似。

			只不过驼峰命名法是第一个单词首字母小写，而帕斯卡命名法则是第一个单词首字母大写。因此这种命名法也有人称之为“大驼峰命名法”。

			例如：
				DisplayInfo();
				UserName

			都是采用了帕斯卡命名法。
			在C#中，以帕斯卡命名法和骆驼命名法居多。
			事实上，很多程序设计者在实际命名时会将驼峰命名法和帕斯卡结合使用，例如变量名采用驼峰命名法，而函数采用帕斯卡命名法。


		四、下划线命名法。

			下划线法是随着C语言的出现流行起来的，在UNIX/LIUNX这样的环境，以及GNU代码中使用非常普遍。

			4.1 函数的命名

				函数名使用下划线分割小写字母的方式命名：
					设备名_操作名();

				操作名一般采用：谓语（此时设备名作为宾语或者标明操作所属的模块）
				或者谓语+宾语/表语（此时设备名作为主语或者标明操作所属的模块） 等形式，如：
					tic_init();
					adc_is_busy();
					uart_tx_char();

				中断函数的命名直接使用 设备名_isr() 的形式命名，如：
					timer2_isr();

			4.2 变量的命名

				变量的命名也采用下划线分割小写字母的方式命名。命名应当准确，不引起歧义，且长度适中。如：
					int length;
					uint32 test_offset;

				单字符的名字也是常用的，如i, j, k等，它们通常可用作函数内的局部变量。tmp常用做临时变量名。
				局部静态变量，应加s_词冠（表示static），如：
					static int s_lastw;

				全局变量（尤其是供外部访问的全局变量），应加g_词冠（表示global），如：
					void (* g_capture_hook)(void);

			4.3 常量及宏的命名

				采用下划线分割大写字母的方式命名，一般应以设备名作为前缀，
				防止模块间命名的重复。如：
					#define TIMER0_MODE_RELOAD                2
					#define TIMER2_COUNT_RETRIEVE(val)        ((uint16)(65536 - (val)))

				当然，看作接口的宏可以按照函数的命名方法命名，例如：
					#define timer2_clear()                      (TF2 = 0)
					#define timer0_is_expired()                (TF0)


		据考察，没有一种命名规则可以让所有的程序员赞同，程序设计教科书一般都不指定命名规则。命名规则对软件产品而言并不是“成败悠关”的事，我们不要化太多精力试图发明世界上最好的命名规则，而应当制定一种令大多数项目成员满意的命名规则，并在项目中贯彻实施。
*/