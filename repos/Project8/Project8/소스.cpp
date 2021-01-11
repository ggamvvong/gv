#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct people
{
	char name[20];
	char tel[100];
	char addr[100];
};
int main()
{
	struct people p[3];

	for (int i = 0; i < 3; i++)
	{
		scanf("%s %s %s", &p[i].name, &p[i].tel, &p[i].addr);
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = i+1; j < 3; j++)
		{
			if (p[i].name < p[j].name)
			{
				people tmp = p[i];
				p[i] = p[j];
				p[j] = tmp;
			}
		}
	}
	
	for (int i = 0; i < 3; i++)
	{
		printf("name : %s\n", p[i].name);
		printf("tel : %s\n", p[i].tel);
		printf("addr : %s\n", p[i].addr);
	}
	
	return 0;
}