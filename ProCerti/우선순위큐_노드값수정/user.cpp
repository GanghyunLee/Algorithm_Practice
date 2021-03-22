typedef unsigned long long ull;

const int MAX_SIZE = 100001;

struct Data
{
	ull name;
	int idx;
	int pos;

	bool operator<(Data other)
	{
		if (name == other.name)
			return idx > other.idx;

		return name < other.name;
	}

} data[MAX_SIZE];
Data* heap[MAX_SIZE];
int hCnt = 0;

ull str2ull(char* name)
{
	register ull h = 0;
	register int i = 0;

	for (; name[i]; i++)
		h = (h << 5) + name[i] - 'a' + 1;

	for (; i < 10; i++)
		h = (h << 5);

	return h;
}

void init() {
	hCnt = 0;
}

void clear() {
	hCnt = 0;
}

void Up(int now)
{
	while (now > 0)
	{
		int parent = (now - 1) / 2;

		if (*heap[parent] < *heap[now])
		{
			heap[parent]->pos = now;
			heap[now]->pos = parent;

			Data* tmp = heap[parent];
			heap[parent] = heap[now];
			heap[now] = tmp;
		}
		else
			break;

		now = parent;
	}
}

void push(int idx, char name[]) {
	Data* tmp = &data[idx];
	tmp->name = str2ull(name);
	tmp->idx = idx;
	tmp->pos = hCnt;
	heap[hCnt] = tmp;

	Up(hCnt);
	hCnt++;
}

void Down(int now)
{
	int lastIdx = hCnt - 1;

	while (true)
	{
		int next = now;
		int left = (now * 2) + 1;
		int right = (now * 2) + 2;

		if (left <= lastIdx && *heap[next] < *heap[left])
			next = left;

		if (right <= lastIdx && *heap[next] < *heap[right])
			next = right;

		if (next == now)
			break;

		heap[next]->pos = now;
		heap[now]->pos = next;

		Data* tmp = heap[next];
		heap[next] = heap[now];
		heap[now] = tmp;

		now = next;
	}
}

int pop() {
	int ret = heap[0]->idx;
	hCnt--;

	heap[0]->pos = hCnt;
	heap[hCnt]->pos = 0;

	Data* tmp = heap[0];
	heap[0] = heap[hCnt];
	heap[hCnt] = tmp;

	Down(0);

	return ret;
}

void mod(int idx, char name[]) {
	int pos = data[idx].pos;
	heap[pos]->name = str2ull(name);
	
	Up(pos);
	Down(pos);
}
