#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int num;
	printf("정수 입력 : ");
	scanf("%d", &num);
	int start = 0;
	int end = 0;
	for (int i = 0; i < num+2; i++)
	{
		for (int j = 0; j < num; j++)
		{
			if (j>start&&j<=end)
			{
				printf("#");
			}
			else if (j >= start&&j <= end)
			{
				printf("#");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
		if (i == num - 1)
		{
			start++;
		}
		else
		{
			end++;
		}
	}
	return 0;
}