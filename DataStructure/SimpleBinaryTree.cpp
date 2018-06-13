#include <stdio.h>
int Tree[27][2] = { {0} };

void preorder(int node)
{
	if (node == -1) return;
	printf("%c", node + 'A');
	preorder(Tree[node][0]);
	preorder(Tree[node][1]);
}

void inorder(int node)
{
	if (node == -1) return;

	inorder(Tree[node][0]);
	printf("%c", node + 'A');
	inorder(Tree[node][1]);
}

void postorder(int node)
{
	if (node == -1) return;

	postorder(Tree[node][0]);
	postorder(Tree[node][1]);
	printf("%c", node + 'A');
}

int main(void)
{
	int N;
	scanf("%d", &N);

	for (register int i = 0; i < N; i++)
	{
		char node, left, right;
		scanf("\n%c %c %c", &node, &left, &right);

		node -= 'A';

		if (left == '.') Tree[node][0] = -1;
		else Tree[node][0] = left - 'A';

		if (right == '.') Tree[node][1] = -1;
		else Tree[node][1] = right - 'A';
	}

	preorder(0);
	printf("\n");
	inorder(0);
	printf("\n");
	postorder(0);
	printf("\n");

	return 0;
}

/*
Input
7
A B C
B D .
C E F
E . .
F . G
D . .
G . .

Output
ABDCEFG
DBAECFG
DBEGFCA
*/