#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int print(int x)
{
	int dice = 1;
	int num1 = 1;
	int num2 = 1;
	int num3 = 1;
	for (int i = 0; i < x; i++)
	{
		dice *= 6;
	}
	for (int j = 0; j < dice; j++)
	{
		printf("%d %d %d\n", num1, num2, num3);
		num3++;
		if (num3 == 7)
		{
			num2++;
			num3 = 1;
		}
		if (num2 == 7)
		{
			num1++;
			num2 = 1;
		}
		if (num1 == 6 && num2 == 6 && num3 == 7)
		{
			break;
		}
	}
	return 0;
}

int main()
{
	int x = 0;

	scanf("%d", &x);

	print(x);

	return 0;
}