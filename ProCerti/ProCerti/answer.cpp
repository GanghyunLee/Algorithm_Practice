/*
#define MAX_N			5

#define MAX_NAME_LEN	7
#define MAX_TAG_LEN		4

const int M = 101;
const int TYPE_MAX = 5;
const int ADD_MAX = 50001;

const int HASH = 10007;

struct BOOK
{
	unsigned long long name;
	int m;
	int del;
	int cnt;
	BOOK* next;
} bbuf[ADD_MAX];
int bcnt = 0;

struct TYPE
{
	unsigned long long name;
	BOOK* b;
	TYPE* next;
} tbuf[ADD_MAX * TYPE_MAX];
int tcnt = 0;

BOOK* bhash[HASH];
TYPE* thash[HASH];

unsigned long long str2ull(char* name)
{
	unsigned long long h = 0;
	int i = 0;

	for (; name[i]; i++)
		h = (h << 6) + name[i] - 'a' + 1;

	for (; i < 6; i++)
		h = (h << 6);

	return h;
}

int bookcount = 0;
void init(int M)
{
	bookcount = 0;
	bcnt = tcnt = 0;

	for (register int i = 0; i < HASH; i++)
	{
		bhash[i] = 0;
		thash[i] = 0;
	}
}

void add(char mName[MAX_NAME_LEN], int mTypeNum, char mTypes[MAX_N][MAX_TAG_LEN], int mSection)
{
	BOOK* b = &bbuf[bcnt++];
	b->name = str2ull(mName);
	b->cnt = 0;
	b->del = 0;
	b->m = mSection;
	b->next = bhash[b->name % HASH];
	bhash[b->name % HASH] = b;

	for (int i = 0; i < mTypeNum; i++)
	{
		TYPE* t = &tbuf[tcnt++];
		t->name = str2ull(mTypes[i]);
		t->next = thash[t->name % HASH];
		thash[t->name % HASH] = t;
		t->b = b;
	}
}

int moveType(char mType[MAX_TAG_LEN], int mFrom, int mTo)
{
	unsigned long long name = str2ull(mType);
	unsigned int ret = 0;

	TYPE* t = thash[name % HASH];

	while (t)
	{
		if (t->name == name && mFrom == t->b->m && t->b->del == 0)
		{
			t->b->m = mTo;
			ret++;
		}

		t = t->next;
	}

	return ret;
}

void moveName(char mName[MAX_NAME_LEN], int mSection)
{
	unsigned long long name = str2ull(mName);
	BOOK* book = bhash[name % HASH];

	while (book)
	{
		if (book->name == name && book->del == 0)
		{
			book->m = mSection;
			break;
		}

		book = book->next;
	}
}

void deleteName(char mName[MAX_NAME_LEN])
{
	unsigned long long name = str2ull(mName);
	BOOK* book = bhash[name % HASH];

	while (book)
	{
		if (book->name == name && book->del == 0)
		{
			book->del = 1;
			break;
		}

		book = book->next;
	}
}

int countBook(int mTypeNum, char mTypes[MAX_N][MAX_TAG_LEN], int mSection)
{
	register int ret = 0;
	register TYPE* t;

	bookcount++;
	for (register int i = 0; i < mTypeNum; i++)
	{
		unsigned long long name = str2ull(mTypes[i]);
		t = thash[name % HASH];

		while (t)
		{
			if (t->name == name && t->b->m == mSection && t->b->del == 0 && t->b->cnt != bookcount)
			{
				t->b->cnt = bookcount;
				ret++;
			}

			t = t->next;
		}
	}

	return ret;
}
*/