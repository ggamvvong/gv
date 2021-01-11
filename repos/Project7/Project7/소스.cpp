#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char a[100];

	scanf("%s", &a);

	printf("%-5s\n", a);

	return 0;
}