#include <stdio.h>

int main() {

	int n, arr[100];

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	for (int i = 0; i < n; i++)
	{
		// n번 훑겠다!

		// i = 0 --> j = 0 ~ 9
		// i = 1 --> j = 0 ~ 8
		// i = 2 --> j = 0 ~ 7
		// 따라서, j = 0 ~ n-i-2

		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp;
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);

	printf("\n");

	return 0;
}