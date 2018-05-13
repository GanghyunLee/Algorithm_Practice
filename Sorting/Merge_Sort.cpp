#include <stdio.h>
#define MAX_DATA_SIZE 1000000

int data[1000000] = { 0 };
int tempData[1000000] = { 0 };

void merge(int start, int end)
{
	register int i = start;
	register int mid = (start + end) / 2;
	register int j = mid + 1;
	register int k = 0;

	while (i <= mid && j <= end)
	{
		if (data[i] <= data[j]) tempData[k++] = data[i++];
		else tempData[k++] = data[j++];
	}

	while (i <= mid) tempData[k++] = data[i++];
	while (j <= end) tempData[k++] = data[j++];

	for (register int i = start; i <= end; i++)
		data[i] = tempData[i - start];
}

void mergeSort(int start, int end)
{
	if (start == end) return;
	int mid = (start + end) / 2;
	mergeSort(start, mid);
	mergeSort(mid + 1, end);
	merge(start, end);
}

int main(void)
{
	int N;
	scanf("%d", &N);

	for (register int i = 0; i < N; i++) scanf("%d", &data[i]);
	mergeSort(0, N - 1);
	for (register int i = 0; i < N; i++) printf("%d\n", data[i]);

	return 0;
}