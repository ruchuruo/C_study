/*
	指针进阶
		9.指针和数组面试题的解析

			笔试题7()
			笔试题8()
*/

#include "define.h"

void 笔试题7()
{
	char* a[] = { "work","at","alibaba" };
	char** pa = a;
	pa++;
	printf("%s\n", *pa);
}

/**************************************************************************************************************************************************/

void 笔试题8()
{
	char* c[] = { "ENTER","NEW","POINT","FIRST" };
	char** cp[] = { c + 3,c + 2,c + 1,c };
	char*** cpp = cp;
	printf("%s\n", **++cpp);
	printf("%s\n", *-- * ++cpp + 3);
	printf("%s\n", *cpp[-2] + 3);
	printf("%s\n", cpp[-1][-1] + 1);
}

int main()
{
	笔试题7();

	笔试题8();

	return 0;
}