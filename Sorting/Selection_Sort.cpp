#include <stdio.h>

int main(void)
{
	/*
	10
	1 5 6 8 3 4 5 9 2 10
	-----
	1 2 3 4 5 5 6 8 9 10
	*/
	int n;
	int data[100];

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &data[i]);
	}

	for (int i = 0; i < n; i++)
	{
		// i��°�� �ּҰ��� �־��.
		// i��°���� �� �������� �� �� �ּڰ�

		int inx = i;

		for (int j = i; j < n; j++)
		{
			if (data[inx] > data[j])
			{
				// �ּڰ��� ã�´�.
				inx = j;
			}
		}

		int temp;
		temp = data[i];
		data[i] = data[inx];
		data[inx] = temp;
	}

	for (int i = 0; i < n; i++)
		printf("%d ", data[i]);

	return 0;
}