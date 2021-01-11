#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int arr[10] = { 0 };
	int a = 0;
	int b = 0;

	scanf("%d %d", &a, &b);

	arr[0] = a;
	arr[1] = b;
	
	int i = 2;
	while (i < 10)
	{
		arr[i] = arr[i - 2] + arr[i - 1];
		if (arr[i] > 10)
		{
			arr[i] -= 10;
		}
		i++;
	}

	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	
	return 0;
	
}