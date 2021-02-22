/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 최대힙
// 1) 완전이진트리
// - 이진트리의 원소가 왼쪽부터 채워진다.
// - 왼쪽부터 채우는데 더 이상 채울 수 없는 경우 새로운 레벨의 왼쪽부터 채운다.
// 2) 부모 노드의 값 >= 자식 노드의 값

// k의 왼쪽 자식 = k * 2 + 1
// k의 오른쪽 자식 = k * 2 + 2
// k의 부모 번호 = (k-1)/2

int N;
const int MAX_SIZE = 500001;

struct PriorityQueue
{
	int _heap[MAX_SIZE];
	int cnt = 0;

	void Push(int item)
	{
		_heap[cnt++] = item;

		// 도장깨기
		int now = cnt-1;
		while (now > 0)
		{
			int next = (now - 1) / 2;

			if (_heap[now] < _heap[next])
				break;

			int temp = _heap[now];
			_heap[now] = _heap[next];
			_heap[next] = temp;

			now = next;
		}
	}

	int Pop()
	{
		int ret = _heap[0];
		cnt--;

		int temp = _heap[cnt];
		_heap[cnt] = _heap[0];
		_heap[0] = temp;

		int lastIndex = cnt - 1;

		// 역도장깨기
		int now = 0;
		while (true)
		{
			int left = (now * 2) + 1;
			int right = (now * 2) + 2;

			int next = now;
			if (left <= lastIndex && _heap[next] < _heap[left])
				next = left;

			if (right <= lastIndex && _heap[next] < _heap[right])
				next = right;

			if (now == next)
				break;

			int temp = _heap[now];
			_heap[now] = _heap[next];
			_heap[next] = temp;

			now = next;
		}

		return ret;
	}

} pq;

int main(void)
{
	scanf("%d", &N);

	int _input = 0;
	for (register int i = 0; i < N; i++)
	{
		scanf("%d", &_input);
		pq.Push(_input);
	}

	for (register int i = 0; i < N; i++)
		printf("%d ", pq._heap[i]);
	printf("\n");

	for (register int i = 0; i < N; i++)
		pq.Pop();

	for (register int i = 0; i < N; i++)
		printf("%d ", pq._heap[i]);
	printf("\n");

	return 0;
}
*/