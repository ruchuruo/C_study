#include <stdio.h>
#include <assert.h>

char* my_strstr(const char* str1, const char* str2)// 接收到的是字符串首字符的地址
{
	/*

		情况1
			str1
			↓
			abcdefabcdef

			cde
			↑
			str2

			第一次
				c和a比较
				不相等
				str1向后走一步

				 str1
				 ↓
				abcdefabcdef
				cde
				↑
				str2

			第二次
				b和c比较
				不相等
				str1向后走一步

				  str1
				  ↓
				abcdefabcdef
				cde
				↑
				str2

			第三次
				c和c比较
				相等
				str1向后走一步
				str2向后走一步

				   str1
				   ↓
				abcdefabcdef
				cde
				 ↑
				 str2

			第四次
				d和d比较
				相等
				str1向后走一步
				str2向后走一步

					str1
					↓
				abcdefabcdef
				cde
				  ↑
				  str2

			第五次
				e和e比较
				相等
				str1向后走一步
				str2向后走一步

					 str1
					 ↓
				abcdefabcdef
				cde[\0]
				   ↑
				   str2

			str2找到\0查找完成

		情况2
			str1
			↓
			abbbcdef

			bbc
			↑
			str2

			如果 情况2 用 情况1 的步骤来解决会找不到

			当前str2和str1匹配成功的话
				 str1
				 ↓
				abbbcdef
				bbc
				↑
				str2

			str1向后移动一步
				  str1
				  ↓
				abbbcdef
				bbc
				↑
				str2

			试试str2是否还能和str1匹配成功

			如果匹配不成功
			str1回退到上一次开始匹配的位置的下一个位置
			str2回退到上一次开始匹配的位置
				 str1
				 ↓
				abbbcdef
				bbc
				↑
				str2
	*/

	assert(str1 && str2);

	// str1和str2走着走着会回不到最初的位置，所以先保存 或 赋值给s1和s2，之后使用s1和s2
	const char* s1 = str1;
	const char* s2 = str2;

	// str1怎么回到上一次匹配的位置(不是起始位置)，再创建一个变量来保存str1
	const char* cp = str1;

	// 如果要查找的是空字符串
	if (*str2 == '\0')
	{
		return (char*)str1;// 强制类型转换，因为被const修饰，const char* 类型 → char* 类型

	}


	// 开始查找
	while (*cp)
	{
		s1 = cp;
		s2 = str2;

		while (*s1 && *s2 && (*s1 == *s2))
		{
			s1++;// s1负责往前走
			s2++;
		}
		if (*s2 == '\0')
		{
			return (char*)cp;// 强制类型转换，因为被const修饰，const char* 类型 → char* 类型
		}
		cp++;// cp负责保存上一次记录

	}
	return NULL;
	/*
		s1
		↓
		abbbcdef
		↑
		cp

		bbc
		↑
		s2

		KMP算法 比上面的代码效率更高
		(KMP算法 - 字符串查找算法)
	*/
}

void 字符串查找strstr判断字符串_模拟实现()
{
	printf("字符串查找strstr判断字符串_模拟实现\n");

	char arr1[] = "abbbcdef";
	char arr2[] = "bbc";

	char* ret = my_strstr(arr1, arr2);// 传的是字符串首字符的地址

	if (ret == NULL)
	{
		printf("没找到\n");
	}
	else
	{
		printf("找到：%s\n", ret);
	}

}

int main()
{
	字符串查找strstr判断字符串_模拟实现();

	return 0;
}