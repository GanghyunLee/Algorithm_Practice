/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

const int LM = (int)1e6 + 10;
char str[LM];

// ���԰� ���� ������ �Ϲ�ȭ�� ���Ͽ� ���� NULL�� �� ���� dummy node�� ����Ѵ�. 
struct Node
{
	char data;
	Node* prev, * next;
	
	Node* alloc(char nd, Node* cur)
	{
		data = nd;
		prev = cur, next = NULL;

		if (cur) next = cur->next, cur->next = this;
		if (next) next->prev = this;

		return this;
	}

	Node* erase()
	{
		if (prev) prev->next = next;
		if (next) next->prev = prev;

		return prev;
	}
} buf[LM];
int bCnt = 0;

struct DoublyLinkedList
{
	Node* head, *cur;
	int cnt;

	DoublyLinkedList()
	{
		cnt = 0;
		head = cur = buf[bCnt++].alloc(0, NULL);
	}

	bool empty() { return cnt == 0; }
	int size() { return cnt; }

	Node* begin()
	{
		if (empty()) return NULL;
		return head->next;			// Dummy node�� ���Ƿ�.
	}

	void insert(char nd)
	{
		cur = buf[bCnt++].alloc(nd, cur);
	}

	void erase()
	{
		if (cur == head) return;
		cur = cur->erase();
	}

	void output()
	{
		Node* p = head->next;

		for (; p; p = p->next)
		{
			printf("%c", p->data);
		}
		puts("");
	}

	void leftMove()
	{
		if (cur == head) return;
		cur = cur->prev;
	}

	void rightMove()
	{
		if (cur->next == NULL) return;
		cur = cur->next;
	}
};

void init()
{
	bCnt = 0;
}

int main()
{
	int tc;
	char cmd;
	scanf("%d", &tc);

	while (tc--)
	{
		init();
		scanf("%s", str);
		DoublyLinkedList d = DoublyLinkedList(); // new�� �Ƚ����Ƿ� �������� �� ��������

		for (int i = 0; (cmd = str[i]); i++)
		{
			if (cmd == '<') d.leftMove();
			else if (cmd == '>') d.rightMove();
			else if (cmd == '-') d.erase();
			else d.insert(cmd);
		}

		d.output();
	}

	return 0;
}
*/