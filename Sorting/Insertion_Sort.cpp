#include <stdio.h>

int main(void)
{
	int n, data[100];
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &data[i]);

	for (int i = 0; i < n; i++)
	{
		// i가 가리키고 있는 값이 왼쪽으로 들어가야 함.
		// 단, i 왼쪽의 모든 원소는 정렬이 되어 있음.

		// 초기상태에서 j는 i와 같은 위치로 잡고, j-1과 비교.
		for (int j = i; j >= 1; j--)
		{
			if (data[j - 1] > data[j])
			{
				int temp;
				temp = data[j - 1];
				data[j - 1] = data[j];
				data[j] = temp;
			}
			else break;
		}
	}

	for (int i = 0; i < n; i++)
		printf("%d ", data[i]);

	return 0;
}