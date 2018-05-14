#include <stdio.h>
#define MAX_DATA_SIZE 1000

// reference : 
// https://www.youtube.com/watch?v=MZaf_9IZCrc

void swap(int data[], int a, int b)
{
	int tmp = data[a];
	data[a] = data[b];
	data[b] = tmp;
}

int partition(int data[], int low, int high)
{
	int last = data[high];
	int index = low;

	for (register int i = low; i < high; i++)
	{
		if (data[i] <= last)
		{
			swap(data, i, index);
			index++;
		}
	}

	swap(data, index, high);
	return index;
}

void qsort(int data[], int low, int high)
{
	if (high <= low) return;

	int pivot = partition(data, low, high);
	qsort(data, low, pivot - 1);
	qsort(data, pivot + 1, high);
}

int main(void)
{
	int N;
	scanf("%d", &N);

	int data[MAX_DATA_SIZE] = { 0 };

	for (register int i = 0; i < N; i++) scanf("%d", &data[i]);
	qsort(data, 0, N - 1);
	for (register int i = 0; i < N; i++) printf("%d\n", data[i]);

	return 0;
}
