/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// �ִ���
// 1) ��������Ʈ��
// - ����Ʈ���� ���Ұ� ���ʺ��� ä������.
// - ���ʺ��� ä��µ� �� �̻� ä�� �� ���� ��� ���ο� ������ ���ʺ��� ä���.
// 2) �θ� ����� �� >= �ڽ� ����� ��

// k�� ���� �ڽ� = k * 2 + 1
// k�� ������ �ڽ� = k * 2 + 2
// k�� �θ� ��ȣ = (k-1)/2

int N;
const int MAX_SIZE = 500001;

struct PriorityQueue
{
	int _heap[MAX_SIZE];
	int cnt = 0;

	void Push(int item)
	{
		_heap[cnt++] = item;

		// �������
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

		// ���������
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