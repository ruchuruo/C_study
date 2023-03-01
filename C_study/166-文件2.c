/*
	C语言文件操作

		本章重点
			1. 为什么使用文件
			2. 什么是文件
			3. 文件的打开和关闭
			4. 文件的顺序读写
			5. 文件的随机读写
			6. 文本文件和二进制文件
			7. 文件读取结束的判定
			8. 文件缓冲区

		————————————————————————————————————————————————————————————————
		----------------------------------------------------------------

		1. 为什么使用文件
			
			我们前面学习结构体时，写了通讯录的程序，当通讯录运行起来的时候，可以给通讯录中，增删查改 数据，
			此时数据是存放在内存中，当程序退出的时候，通讯录中的数据自然就不存在了，等下次运行通讯录程序的时候，
			数据又得重新录入。

			既然是通讯录就应该把信息记录下来，只有我们自己选择删除数据的时候，数据才不复存在。
			这就涉及到了数据持久化的问题，我们一般数据持久化的方法有，把数据存放在磁盘文件，存放到数据库等方式。

			使用文件我们可以将数据直接存放在电脑的硬盘上，做到了数据的持久化。

		----------------------------------------------------------------

		2. 什么是文件

			磁盘上的文件是文件。

			但是在程序设计中，我们一般谈的文件有两种：程序文件、数据文件(从文件功能的角度来分类的)。


			程序文件
				包括源程序文件(后缀为.c)，目标文件(Windows环境 后缀为.obj)，可执行程序(Windows环境 后缀为.exe)


			数据文件
				文件的内容不一定是程序，而是程序运行时读写的数据，
				比如程序运行需要从中读取数据的文件，或者输出内容的文件


			本章讨论的是数据文件。

			在以前各章所处理数据的输入输出都是以终端为对象的，
			即从终端的键盘输入数据，运行结果显示到显示器上。

			其实有的时候我们会把信息输出到磁盘上，
			当需要的时候再从磁盘上把数据读取到内存中使用，这里处理的就是磁盘上的文件


			文件名
				一个文件要有一个唯一的文件标识，以便用户识别和引用。

				文件名包含3部分：文件路径+文件名主干+文件后缀
				例如：D:\ruchuruo\C\01\Project1\164-文件1.c

				为了方便起见，文件标识常被成为 文件名。

		----------------------------------------------------------------

		3. 文件的打开和关闭
			
			文件指针
				缓冲文件系统中，关键的概念是"文件类型指针"，简称"文件指针"。

				每个被使用的文件都在内存中开辟了一个相应的文件信息区，用来存放文件的相关信息
				(如文件名的名字，文件状态及文件当前的位置等)。这些信息是保存在一个结构体变量中的。
				该结构体类型是由系统声明的，取名：FLIE

				例如，VS2013 编译环境提供的 stdio.h 头文件中有以下的文件类型声明
					struct _iobuf {
						char *_ptr;		//文件输入的下一个位置
						int   _cnt;		//剩余多少个字符未被读取
						char *_base;	//基础位置（文件的起始位置）
						int   _flag;	//文件标志
						int   _file;	//文件的有效性验证
						int   _charbuf;	//检查缓冲区状况，如果无缓冲区则不读取
						int   _bufsiz;	//文件的大小
						char *_tmpfname;//临时文件名
						};
					typedef struct _iobuf FILE;

				不同的C编译器的FILE类型包含的内容不完全相同，但是大同小异。

				每当打开一个文件的时候，系统会根据文件的情况自动创建一个FILE结构的变量，
				并填充其中的信息，使用者不必关心细节。

				一般都是通过一个FILE的指针来维护这个FILE结构的变量，这样使用起来更加方便。

				创建一个FILE*的指针变量
					FILE* pf;// 文件指针变量

				定义pf是一个指向FILE类型数据的指针变量。可以使pf指向某个文件的文件信息区(是一个结构体变量)。
				通过该文件信息区中的信息就能够访问该文件。也就是说，通过文件指针变量能够找到与它关联的文件。

				pf1→[ ]		pf2→[ ]		pf3→[ ]
					[ ]			[ ]			[ ]
					[ ]			[ ]			[ ]
					[ ]			[ ]			[ ]
					[ ]			[ ]			[ ]
				文件f1的		文件f2的		文件f3的
				文件信息区	文件信息区	文件信息区


			文件的打开和关闭
				文件在读写之前应该先打开文件，在使用结束之后应该关闭文件。

				在编写程序的时候，在打开文件的同时，都会返回一个FILE*的指针变量指向该文件，
				也就相当于建立了指针和文件的关系。

				ANSI C 规定使用fopen函数来打开文件，fclose来关闭文件。

					// 打开文件
					FILE * fopen ( const char * filename, const char * mode );
												文件名				   打开方式

						filename
							C string containing the name of the file to be opened.
							Its value shall follow the file name specifications of the running environment and can include a path (if supported by the system).
						mode
							C string containing a file access mode. It can be:
							"r"	read: Open file for input operations. The file must exist.
							"w"	write: Create an empty file for output operations. If a file with the same name already exists, its contents are discarded and the file is treated as a new empty file.
							"a"	append: Open file for output at the end of a file. Output operations always write data at the end of the file, expanding it. Repositioning operations (fseek, fsetpos, rewind) are ignored. The file is created if it does not exist.
							"r+"	read/update: Open a file for update (both for input and output). The file must exist.
							"w+"	write/update: Create an empty file and open it for update (both for input and output). If a file with the same name already exists its contents are discarded and the file is treated as a new empty file.
							"a+"	append/update: Open a file for update (both for input and output) with all output operations writing data at the end of the file. Repositioning operations (fseek, fsetpos, rewind) affects the next input operations, but output operations move the position back to the end of file. The file is created if it does not exist.

						文件名
							包含要打开的文件的名称的 C 字符串。
							其值应遵循运行环境的文件名规范，并且可以包含路径（如果系统支持）。
						模式
							包含文件访问模式的 C 字符串。它可以是：
							“r”	读：打开用于输入操作的文件。该文件必须存在。
							“w”	写：为输出操作创建一个空文件。如果已存在同名文件，则将丢弃其内容，并将该文件视为新的空文件。
							“一”	附加：打开文件以在文件末尾输出。输出操作始终在文件末尾写入数据，并对其进行扩展。重新定位操作（重新定位操作、重新定位操作、倒带操作）将被忽略。如果该文件不存在，则创建该文件。
							“r+”	读取/更新：打开要更新的文件（输入和输出）。该文件必须存在。
							“w+”	写入/更新：创建一个空文件并打开它进行更新（用于输入和输出）。如果已存在同名文件，则将丢弃其内容，并将该文件视为新的空文件。
							“a+”	追加/更新：打开文件进行更新（输入和输出），所有输出操作都在文件末尾写入数据。重新定位操作（转口、倒带、倒带）会影响下一个输入操作，但输出操作会将位置移回文件末尾。如果该文件不存在，则创建该文件。

					// 关闭文件
					int fclose ( FILE * stream );


			演示&讲解
				文件的打开和关闭();

		----------------------------------------------------------------

		4. 文件的顺序读写
			
			功能				函数名	适用于

			字符输入函数		fgetc	所有输入流	int fgetc ( FILE * stream );
			字符输出函数		fputc	所有输出流	int fputc ( int character, FILE * stream );
			文本行输入函数	fgets	所有输入流	char * fgets ( char * str, int num, FILE * stream );
			文本行输出函数	fputs	所有输出流	int fputs ( const char * str, FILE * stream );
			格式化输入函数	fscanf	所有输入流	int fscanf ( FILE * stream, const char * format, ... );
			格式化输出函数	fprintf	所有输出流	int fprintf ( FILE * stream, const char * format, ... );
			二进制输入		fread	文件			size_t fread ( void * ptr, size_t size, size_t count, FILE * stream );
			二进制输出		fwrite	文件			size_t fwrite ( const void * ptr, size_t size, size_t count, FILE * stream );


					←输入/读取
			内存中				硬盘
					输出/写入→


			演示&讲解
				文件的顺序读写_写文件();
				文件的顺序读写_读文件();
				文件的顺序读写_读键盘();
				文件的顺序读写_写文件_一行();
				文件的顺序读写_读文件_一行();
				文件的顺序读写_格式化输出();
				文件的顺序读写_格式化输入();
				文件的顺序读写_二进制输出();
				文件的顺序读写_二进制输入();

		----------------------------------------------------------------
		5. 文件的随机读写
		----------------------------------------------------------------
		6. 文本文件和二进制文件
		----------------------------------------------------------------
		7. 文件读取结束的判定
		----------------------------------------------------------------
		8. 文件缓冲区
		----------------------------------------------------------------
		————————————————————————————————————————————————————————————————

*/
/*
		————————————————————————————————————————————————————————————————

		文件使用方式		含义											如果指定文件不存在

		r	只读			为了输入数据，打开一个已经存在的文本文件		出错
		w	只写			为了输出数据，打开一个文本文件				建立一个新的文件
		a	追加			向文本文件尾添加数据							建立一个新的文件
		rb	只读			为了输入数据，打开一个二进制文件				出错
		wb	只写			为了输出数据，打开一个二进制文件				建立一个新的文件
		ab	追加			向一个二进制文件尾添加数据					出错
		r+	读写			为了读和写，打开一个文本文件					出错
		w+	读写			为了读和写，建立一个新的文件					建立一个新的文件
		a+	读写			打开一个文件，在文件尾进行读写				建立一个新的文件
		rb+	读写			为了读和写，打开一个二进制文件				出错
		wb+	读写			为了读和写，新建一个新的二进制文件			建立一个新的文件
		ab+	读写			打开一个二进制文件，在文件尾进行读和写		建立一个新的文件

		————————————————————————————————————————————————————————————————

		流：高度抽象的概念
			
			程序可能将数据输出到

				程序	→ 屏幕
					→ 硬盘
					→ 网络
					→ ...

			不同的硬件读取方式不同，对程序员来说成本高。
			在中间抽象一个层
			程序向 流 里输入数据，流 再将数据输出到不同的硬件

				程序	→ 流	 → 屏幕
						 → 硬盘
						 → 网络
						 → ...

			C语言程序，只要运行起来，就默认打开了3个流：
				stdin  - 标准输入流 - 键盘
				stdout - 标准输出流 - 屏幕
				stderr - 标准错误流 - 屏幕

				类型都是FILE*


			向标准输出流输出 fputc('b', stdout);
			向文件流输出     fputc('t', pf);

*/

#include "define.h"

void n2(int 换行次数, char* 换行符号, int 符号个数)
{
	int i = 0;

	if (换行符号 != NULL && 符号个数 > 0)
	{
		printf("\n");
		for (i = 0; i < 符号个数; i++)
		{
			printf("%s", 换行符号);
		}
	}

	for (i = 0; i < 换行次数; i++)
	{
		printf("\n");
	}
}

int 判断文件是否存在(char* 文件路径)
{
	FILE* pfff = fopen(文件路径, "r");

	if (pfff == NULL)
	{
		return 0;
	}

	fclose(pfff);
	pfff = NULL;

	return 1;
}

/**************************************************************************************************************************************************/
/*================================================================================================================================================*/

void 文件的打开和关闭()
{
	printf("文件的打开和关闭\n");

	// 打开
	FILE* pf = fopen("..\\测试文件操作\\文件1.txt", "r");

	if (pf == NULL)
	{
		perror("fopen");
		return;
	}

	// 关闭
	fclose(pf);
	pf = NULL;

	n2(2, "-------- ", 4);
}

/*================================================================================================================================================*/

void 文件的顺序读写_写文件()
{
	printf("文件的顺序读写_写文件\n");

	// 判断是否存在
	FILE* pfff = fopen("..\\测试文件操作\\文件2.txt", "r");
	if (pfff == NULL)
	{
		perror("fopen");
		return;
	}
	fclose(pfff);
	pfff = NULL;

	// 操作开始
	// 判断
	FILE* pf = fopen("..\\测试文件操作\\文件2.txt", "w");
	if (pf == NULL)
	{
		perror("fopen");
		return;
	}

	// 写文件
	fputc('b', pf);
	fputc('i', pf);
	fputc('t', pf);

	// 关闭
	fclose(pf);
	pf = NULL;

	n2(2, "-------- ", 4);
}

/*================================================================================================================================================*/

void 文件的顺序读写_读文件()
{
	printf("文件的顺序读写_读文件\n");

	FILE* pf = fopen("..\\测试文件操作\\文件2.txt", "r");
	if (pf == NULL)
	{
		perror("fopen");
		return;
	}

	// 读文件
	int ret = fgetc(pf);
	printf("%c\n", ret);
	ret = fgetc(pf);
	printf("%c\n", ret);
	ret = fgetc(pf);
	printf("%c\n", ret);

	// fgetc 从文件流读取

	// 关闭
	fclose(pf);
	pf = NULL;

	n2(2, "-------- ", 4);
}

/*================================================================================================================================================*/

void 文件的顺序读写_读键盘()
{
	printf("文件的顺序读写_读键盘\n");
	printf("请输入>");

	// 读键盘输入
	int ret = fgetc(stdin);
	printf("%c\n", ret);
	ret = fgetc(stdin);
	printf("%c\n", ret);
	ret = fgetc(stdin);
	printf("%c\n", ret);

	// fgetc 从标准输入流读取

	n2(2, "-------- ", 4);
}

/*================================================================================================================================================*/

void 文件的顺序读写_写文件_一行()
{
	printf("文件的顺序读写_写文件_一行\n");

	// 判断是否存在
	FILE* pfff = fopen("..\\测试文件操作\\文件3.txt", "r");
	if (pfff == NULL)
	{
		perror("fopen");
		return;
	}
	fclose(pfff);
	pfff = NULL;

	// 操作开始
	// 判断
	FILE* pf = fopen("..\\测试文件操作\\文件3.txt", "w");
	if (pf == NULL)
	{
		perror("fopen");
		return;
	}

	// 写文件 行
	fputs("abcdef", pf);
	fputs("abcdefg\n", pf);
	fputs("abcdefgh", pf);


	// 关闭
	fclose(pf);
	pf = NULL;

	n2(2, "-------- ", 4);
}

/*================================================================================================================================================*/

void 文件的顺序读写_读文件_一行()
{
	printf("文件的顺序读写_读文件_一行\n");

	FILE* pf = fopen("..\\测试文件操作\\文件3.txt", "r");
	if (pf == NULL)
	{
		perror("fopen");
		return;
	}

	// 读文件 行
	char arr[10] = { 0 };
	fgets(arr, 4, pf);// 读4个字符，其中放入1个\0
	printf("%s\n", arr);
	fgets(arr, 4, pf);// 读4个字符，其中放入1个\0
	printf("%s\n", arr);


	// 关闭
	fclose(pf);
	pf = NULL;

	n2(2, "-------- ", 4);
}

/*================================================================================================================================================*/

void 文件的顺序读写_格式化输出()
{
	printf("文件的顺序读写_格式化输出\n");

	if ((判断文件是否存在("..\\测试文件操作\\文件4.txt")) == 0)
	{
		printf("文件可能不存在\n");
		return;
	}

	struct S
	{
		char arr[10];
		int num;
		float sc;
	};

	struct S s = { "abcdef", 10, 5.5f };

	// 对格式化的数据进行写文件

	FILE* pf = fopen("..\\测试文件操作\\文件4.txt", "w");
	if (pf == NULL)
	{
		perror("fopen");
		return;
	}

	// int fprintf ( FILE * stream, const char * format, ... );
	//											 格式	 可变参数
	fprintf(pf, "%s %d %f", s.arr, s.num, s.sc);

	fclose(pf);
	pf = NULL;

	n2(2, "-------- ", 4);
}

/*================================================================================================================================================*/

void 文件的顺序读写_格式化输入()
{
	printf("文件的顺序读写_格式化输入\n");

	if ((判断文件是否存在("..\\测试文件操作\\文件4.txt")) == 0)
	{
		printf("文件可能不存在\n");
		return;
	}

	struct S
	{
		char arr[10];
		int num;
		float sc;
	};

	struct S s = { 0 };

	// 对格式化的数据进行读文件

	FILE* pf = fopen("..\\测试文件操作\\文件4.txt", "r");

	// int fscanf ( FILE * stream, const char * format, ... );
	fscanf(pf, "%s %d %f", s.arr, &(s.num), &(s.sc));// 有些需要取地址

	// 打印
	printf("%s %d %f\n", s.arr, s.num, s.sc);
	fprintf(stdout, "%s %d %f\n", s.arr, s.num, s.sc);// 也可以这样

	fclose(pf);
	pf = NULL;

	n2(2, "-------- ", 4);
}

/*================================================================================================================================================*/

void 文件的顺序读写_二进制输出()
{
	printf("文件的顺序读写_二进制输出\n");

	if ((判断文件是否存在("..\\测试文件操作\\文件5.txt")) == 0)
	{
		printf("文件可能不存在\n");
		return;
	}

	struct S
	{
		char arr[10];
		int num;
		float sc;
	};

	struct S s = { "abcdef", 10, 5.5f };

	// 二进制输出

	FILE* pf = fopen("..\\测试文件操作\\文件5.txt", "w");
	if (pf == NULL)
	{
		perror("fopen");
		return;
	}

	// size_t fwrite ( const void * ptr, size_t size, size_t count, FILE * stream );
	//						 指向的数据,		元素大小,	  元素个数,			流
	fwrite(&s, sizeof(struct S), 1, pf);// 当前只有1个数据

	fclose(pf);
	pf = NULL;

	n2(2, "-------- ", 4);
}

/*================================================================================================================================================*/

void 文件的顺序读写_二进制输入()
{
	printf("文件的顺序读写_二进制输入\n");

	if ((判断文件是否存在("..\\测试文件操作\\文件5.txt")) == 0)
	{
		printf("文件可能不存在\n");
		return;
	}

	struct S
	{
		char arr[10];
		int num;
		float sc;
	};

	struct S s = { 0 };

	// 二进制输入

	FILE* pf = fopen("..\\测试文件操作\\文件5.txt", "r");
	
	// size_t fread ( void * ptr, size_t size, size_t count, FILE * stream );
	fread(&s, sizeof(struct S), 1, pf);

	// 打印
	printf("%s %d %f\n", s.arr, s.num, s.sc);
	
	fclose(pf);
	pf = NULL;

	n2(2, "-------- ", 4);
}

/*================================================================================================================================================*/

int main()
{
	文件的打开和关闭();

	文件的顺序读写_写文件();
	文件的顺序读写_读文件();
	//文件的顺序读写_读键盘();// 需要输入
	文件的顺序读写_写文件_一行();
	文件的顺序读写_读文件_一行();
	文件的顺序读写_格式化输出();
	文件的顺序读写_格式化输入();
	文件的顺序读写_二进制输出();
	文件的顺序读写_二进制输入();

	return 0;
}

/*================================================================================================================================================*/
/**************************************************************************************************************************************************/