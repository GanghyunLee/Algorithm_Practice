
#define MAX_USER      1000
#define MAX_TAG       5000

// The below commented functions are for your reference. If you want 
// to use it, uncomment these functions.
/*
int mstrcmp(const char *a, const char *b)
{
int i;
for (i = 0; a[i] != '\0'; ++i) if (a[i] != b[i]) return a[i] - b[i];
return a[i] - b[i];
}

void mstrcpy(char *dest, const char *src)
{
int i = 0;
while (src[i] != '\0') { dest[i] = src[i]; i++; }
dest[i] = src[i];
}
*/

void init()
{
}

void createMessage(int msgID, int userID, char msgData[])
{
}

void followUser(int userID1, int userID2)
{
}

int searchByHashtag(char tagName[], int retIDs[])
{
	return 0;
}

int getMessages(int userID, int retIDs[])
{
	return 0;
}