#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//strcmp
//
int strcmp(const char *source, const char *dest)
{
	char c1, c2;
	if (source == NULL || dest == NULL)
		return -1;
	while(1) {
		c1 = *source++;
		c2 = *dest++;
		if (c1 != c2)
			return -1;
		if (!c1)
			break;
	}
	return 0;
}


//回文判断
//123321
//
int func(char *p)
{
	int len;
	char *start, *end;

	if (p == NULL)
		return 0;
	len = strlen(p);
	end = p + len - 1;
	start = p;

	while(1) {
		if (*start != *end)
			return 0;
		if (start == end)
			break;
		else if (start + 1 == end)
			break;
		start++;
		end--;

	}
	return 1;
}


int main(void)
{
	char *str1 = "12344321";
	char *str2 = "1234321";
	char *str3 = "12354321";

	printf("str1 is cycle number:%d\n", func(str1));
	printf("str2 is cycle number:%d\n", func(str2));
	printf("str3 is cycle number:%d\n", func(str3));
	return 0;
}
