#include <stdio.h>
#define MAX_GRAPH_SIZE 20001
#define MAX_DATA_SIZE 1001
#define MAX_QUEUE_SIZE 1000000

class Queue
{
public:
	int data[MAX_QUEUE_SIZE];
	int front;
	int rear;
	int size;

	Queue()
	{
		front = rear = size = 0;
	}

	void push(int _data)
	{
		data[rear] = _data;
		rear = (rear + 1) % MAX_QUEUE_SIZE;
		size++;
	}

	int pop()
	{
		int result = data[front];
		size--;
		front = (front + 1) % MAX_QUEUE_SIZE;

		return result;
	}

	bool isEmpty()
	{
		return (front == rear);
	}
};

class Edge
{
public:
	int from, to;

	bool operator<=(Edge other)
	{
		if (this->from == other.from)
			return this->to <= other.to;
		else
			return this->from <= other.from;
	}
};
Edge edge[MAX_GRAPH_SIZE];
int cnt[MAX_DATA_SIZE];
bool check[MAX_DATA_SIZE];

void swap(Edge(&data)[MAX_GRAPH_SIZE], int a, int b)
{
	Edge temp = data[a];
	data[a] = data[b];
	data[b] = temp;
}

int partition(Edge(&data)[MAX_GRAPH_SIZE], int low, int high)
{
	int index = low;
	Edge pivotData = data[high];

	for (int i = low; i < high; i++)
	{
		if (data[i] <= pivotData)
		{
			swap(data, i, index);
			index++;
		}
	}
	swap(data, high, index);

	return index;
}

void qsort(Edge(&data)[MAX_GRAPH_SIZE], int low, int high)
{
	if (low >= high) return;

	int pivot = partition(data, low, high);
	qsort(data, low, pivot - 1);
	qsort(data, pivot + 1, high);
}

void DFS(int start)
{
	check[start] = true;
	printf("%d ", start);

	for (register int i = cnt[start - 1]; i < cnt[start]; i++)
	{
		int next = edge[i].to;
		if (check[next] == false)
		{
			DFS(next);
		}
	}
}

void BFS(int start)
{
	Queue q;
	check[start] = true;
	q.push(start);

	while (!q.isEmpty())
	{
		int node = q.pop();
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
	int N, M, V;
	scanf("%d %d %d", &N, &M, &V);

	for (register int i = 0; i < M; i++)
	{
		scanf("%d %d", &edge[i].from, &edge[i].to);
		edge[i + M].from = edge[i].to;
		edge[i + M].to = edge[i].from;
	}
	M *= 2;
	qsort(edge, 0, M - 1);

	for (register int i = 0; i < M; i++)
		cnt[edge[i].from] += 1;
	for (register int i = 1; i <= N; i++)
		cnt[i] += cnt[i - 1];

	DFS(V);
	printf("\n");
	for (register int i = 1; i <= N; i++) check[i] = false;
	BFS(V);
	printf("\n");

	return 0;
}