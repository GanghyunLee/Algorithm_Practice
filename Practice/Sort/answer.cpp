/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

const int N = 7;

int arr[N];

void Init()
{
	arr[0] = 80;
	arr[1] = 96;
	arr[2] = 75;
	arr[3] = 82;
	arr[4] = 95;
	arr[5] = 92;
	arr[6] = 100;
}

void SelectionSort()
{
	for (int i = 0; i < N - 1; i++)
	{
		int idx = i;

		for (int j = i + 1; j < N; j++)
		{
			if (arr[idx] > arr[j])
				idx = j;
		}

		int tmp = arr[idx];
		arr[idx] = arr[i];
		arr[i] = tmp;
	}
}

void Print()
{
	for (int i = 0; i < N; i++)
		printf("%d ", arr[i]);

	puts("");
}

int main(void)
{
	Init();
	SelectionSort();
	Print();

	return 0;
}
*/