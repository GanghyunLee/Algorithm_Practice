// binarySearch ����(���)

#include <stdio.h>
#define MAX_DATA_SIZE (100000)

// data �迭�� start���� end�������� value�� ã�´�.
// ������ -1��, ������ Index�� ��ȯ�Ѵ�.
int binarySearch(int data[], int start, int end, int value)
{
	if (start > end) return -1;
	if (start == end)
	{
		if (data[start] == value) return start;
		else return -1;
	}

	int mid = (start + end) / 2;

	if (data[mid] == value) return mid;
	else if (data[mid] > value) return binarySearch(data, start, mid - 1, value);
	else return binarySearch(data, mid + 1, end, value);
}

int main(void)
{
	int data[MAX_DATA_SIZE] = { 0, };
	int n, m;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) scanf("%d", &data[i]);
	
	scanf("%d", &m);

	// m�� ã�Ƽ� Index ��ȯ(������ -1)
	printf("%d\n", binarySearch(data, 0, n - 1, m));
	
	return 0;
}