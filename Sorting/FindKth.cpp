#include <stdio.h>
#define MAX_DATA_SIZE 5000001

// K번째 수를 출력해야 함.
// Data개수가 많아서, Quicksort를 응용하는 방식으로 풀어야 함.

void swap(long long data[], int a, int b)
{
	long long tmp = data[a];
	data[a] = data[b];
	data[b] = tmp;
}

int partition(long long data[], int low, int high)
{
	long long last = data[high];
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

long long findKth(long long data[], int k, int low, int high)
{
	int pivot = partition(data, low, high);
	int ret;

	if (pivot == k) {
		ret = data[pivot];
	}
	else if (pivot < k) {
		ret = findKth(data, k, pivot + 1, high);
	}
	else {
		ret = findKth(data, k, low, pivot - 1);
	}

	return ret;
}

int main(void)
{
	int N, K;
	scanf("%d %d", &N, &K);

	long long data[MAX_DATA_SIZE] = { 0 };

	for (register int i = 0; i < N; i++) scanf("%lld", &data[i]);
	printf("%lld\n", findKth(data, K - 1, 0, N - 1));

	return 0;
}