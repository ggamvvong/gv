#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int student(int arr[3][3])
{
	int sum[3] = { 0 };
	int vum[3] = { 0 };
	int vsum = 0;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			sum[i] += arr[i][j];
			if (j == 0)
			{
				vum[0] += arr[i][j];
			}
			else if (j == 1)
			{
				vum[1] += arr[i][j];
			}
			else if (j == 2)
			{
				vum[2] += arr[i][j];
			}
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("%d\n", sum[i]);
	}
	for (int i = 0; i < 3; i++)
	{
		vsum += vum[i];
		printf("%d ", vum[i]);
	}
	printf("%d\n", vsum);

	return 0;
}

int main()
{
	int arr[3][3];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	student(arr);
	return 0;
}