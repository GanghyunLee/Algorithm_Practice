typedef unsigned long long ull;

#define MAX_N			5

#define MAX_NAME_LEN	7
#define MAX_TAG_LEN		4

const int M = 101;
const int TMAX = 5;
const int ADD_MAX = 50001;

const int HASH = 10007;

struct BOOK
{
	unsigned long long name;
	int del;
	int m;
	int cnt;
	BOOK* next;
} bbuf[ADD_MAX];
int bcnt = 0;

struct TYPE
{
	unsigned long long name;
	BOOK* b;
	TYPE* next;
} tbuf[ADD_MAX*TMAX];
int tcnt = 0;

ull str2ull(char* name)
{
	ull h = 0;
	register int i = 0;

	for (; name[i]; i++)
		h = (h << 6) + name[i] - 'a' + 1;

	for (; i < 10; i++)
		h = (h << 6);

	return h;
}

BOOK* bhash[HASH];
TYPE* thash[HASH];

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
		t->b = b;
		t->name = str2ull(mTypes[i]);
		t->next = thash[t->name % HASH];
		thash[t->name % HASH] = t;
	}
}

int moveType(char mType[MAX_TAG_LEN], int mFrom, int mTo)
{
	unsigned long long name = str2ull(mType);
	unsigned int ret = 0;

	TYPE* t = thash[name % HASH];
	
	while (t)
	{
		if (t->name == name && t->b->m == mFrom && t->b->del == 0)
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
	BOOK* b = bhash[name % HASH];

	while (b)
	{
		if (b->name == name && b->del == 0)
		{
			b->m = mSection;
			break;
		}

		b = b->next;
	}
}

void deleteName(char mName[MAX_NAME_LEN])
{
	unsigned long long name = str2ull(mName);
	BOOK* b = bhash[name % HASH];
	
	while (b)
	{
		if (b->name == name && b->del == 0)
		{
			b->del = 1;
			break;
		}

		b = b->next;
	}
}

int countBook(int mTypeNum, char mTypes[MAX_N][MAX_TAG_LEN], int mSection)
{
	unsigned int ret = 0;
	bookcount++;
	TYPE* t;

	for (int i = 0; i < mTypeNum; i++)
	{
		unsigned long long name = str2ull(mTypes[i]);
		t = thash[name % HASH];

		while (t)
		{
			if (t->name == name && t->b->del == 0 && t->b->m == mSection && t->b->cnt != bookcount)
			{
				t->b->cnt = bookcount;
				ret++;
			}
			t = t->next;
		}
	}

	return ret;
}