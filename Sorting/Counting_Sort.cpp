#include <stdio.h>
#define MAX_DATA 10001

int main(void)
{
	int N;
	register int input;
	register int data[MAX_DATA] = { 0 };
	scanf("%d", &N);

	for (register int i = 0; i < N; i++)
	{
		scanf("%d", &input);
		(data[input])++;
	}

	for (register int i = 1; i < MAX_DATA; i++)
	{
		for (register int j = 0; j < data[i]; j++) printf("%d\n", i);
	}

	return 0;
}