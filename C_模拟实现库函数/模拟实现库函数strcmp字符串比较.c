#include <stdio.h>
#include <assert.h>

int my_strcmp(const char* s1, const char* s2)
{
	/*
		s1
		↓
		abcdef\0

		abbb\0
		↑
		s2
	*/
	assert(s1 && s2);
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
		{
			return 0;
		}
		s1++;
		s2++;
	}
	if (*s1 > *s2)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

int my_strcmp_2(const char* s1, const char* s2)
{
	assert(s1 && s2);
	while (*s1 == *s2)// 比较的是ascii码值
	{
		if (*s1 == '\0')
		{
			return 0;
		}
		s1++;
		s2++;
	}
	return *s1 - *s2;
}

void 长度不受限制的字符串函数strcmp字符串比较_模拟实现()
{
	printf("长度不受限制的字符串函数strcmp字符串比较_模拟实现\n");

	char* p = "abbb";
	char* q = "abbb";
	int ret = my_strcmp_2(p, q);
	printf("%d\n", ret);

	// 这里的返回值判断 不建议写成ret == 1
	// 因为返回值是大于或小于或等于0的值
	if (ret > 0)
	{
		printf("p > q\n");
	}
	else if (ret < 0)
	{
		printf("p < q\n");
	}
	else
	{
		printf("p == q\n");
	}

}

int main()
{
	长度不受限制的字符串函数strcmp字符串比较_模拟实现();

	return 0;
}