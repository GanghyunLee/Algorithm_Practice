#include <stdio.h>
#include <cstring>
#include <queue>
#include <algorithm>

// https://www.acmicpc.net/problem/1260

using namespace std;

struct Edge {
	int from, to;
};

Edge edge[20001];
int cnt[1001];
bool check[1001];

bool cmp(const Edge &u, const Edge &v)
{
	if (u.from == v.from) {
		return u.to < v.to;
	}
	else {
		return u.from < v.from;
	}
}

void dfs(int node)
{
	check[node] = true;
	printf("%d ", node);

	for (register int i = cnt[node - 1]; i < cnt[node]; i++)
	{
		int next = edge[i].to;

		if (check[next] == false)
			dfs(next);
	}
}

void bfs(int start)
{
	queue<int> q;
	q.push(start);
	check[start] = true;

	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		printf("%d ", node);

		for (register int i = cnt[node - 1]; i < cnt[node]; i++)
		{
			int next = edge[i].to;

			if (check[next] == false)
			{
				check[next] = true;
				q.push(next);
			}
		}
	}
}

int main(void)
{
	int n, m, start;
	// N : 정점의 개수, M : 간선의 개수, START : 탐색을 시작할 정점의 번호
	scanf("%d %d %d", &n, &m, &start);

	for (register int i = 0; i < m; i++)
	{
		scanf("%d %d", &edge[i].from, &edge[i].to);
		edge[i + m].from = edge[i].to;
		edge[i + m].to = edge[i].from;
	}
	m *= 2;
	sort(edge, edge + m, cmp);

	for (register int i = 0; i < m; i++) {
		cnt[edge[i].from] += 1;
	}
	for (register int i = 1; i <= n; i++) {
		cnt[i] += cnt[i - 1];
	}

	dfs(start);
	printf("\n");
	memset(check, false, sizeof(check));
	bfs(start);
	printf("\n");

	return 0;
}