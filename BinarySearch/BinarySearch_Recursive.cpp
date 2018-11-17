// binarySearch 구현(재귀)

#include <stdio.h>
#define MAX_DATA_SIZE (100000)

// data 배열의 start부터 end까지에서 value를 찾는다.
// 없으면 -1을, 있으면 Index를 반환한다.
int binarySearch(int data[], int start, int end, int value)
{
	if (start > end) return -1;
	if (start == end)
	{
		if (data[start] == value) return start;
		else return -1;
	}

	int mid = (start + end) / 2;

	if (data[mid] == value) return mid;
	else if (data[mid] > value) return binarySearch(data, start, mid - 1, value);
	else return binarySearch(data, mid + 1, end, value);
}

int main(void)
{
	int data[MAX_DATA_SIZE] = { 0, };
	int n, m;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) scanf("%d", &data[i]);
	
	scanf("%d", &m);

	// m을 찾아서 Index 반환(없으면 -1)
	printf("%d\n", binarySearch(data, 0, n - 1, m));
	
	return 0;
}