#include <stdio.h>
#define WORD_COUNTER (26)

char word[WORD_COUNTER];
bool visited[WORD_COUNTER];
char output[WORD_COUNTER];
int n, r;

void DFS(int n, int nowR)
{
	if (nowR == r)
	{
		for (int i = 0; i < r; i++)
			printf("%c", output[i]);

		printf("\n");

		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			output[nowR] = i + 'a';
			DFS(n, nowR+1);
			visited[i] = false; // 여기 써줘야함에 유의
		}
	}
}

int main(void)
{
	scanf("%d %d", &n, &r);

	DFS(n, 0);

	return 0;
}