#include <stdio.h>

int main(void)
{
	int n, data[100];
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &data[i]);

	for (int i = 0; i < n; i++)
	{
		// i�� ����Ű�� �ִ� ���� �������� ���� ��.
		// ��, i ������ ��� ���Ҵ� ������ �Ǿ� ����.

		// �ʱ���¿��� j�� i�� ���� ��ġ�� ���, j-1�� ��.
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