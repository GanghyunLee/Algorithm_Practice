/*
typedef unsigned long long ull;

#define MAX_USER      1000
#define MAX_TAG       5000

const int MAX_HASH = 5387;
const int MAX_MESSAGE = 50001;

struct Msg
{
    int msgId;
    int priority;
};

struct HashTag
{
    ull value;
    Msg* msgPtr[5];
} hashTagHash[MAX_HASH];

Msg msgList[MAX_MESSAGE];
int msgCount = 0;

Msg* userMessage[MAX_MESSAGE][5];

int follow[MAX_USER][MAX_USER];
int followCnt[MAX_USER];

void insert(Msg* msgArray[], Msg* msg)
{
    register int i = 0;

    while (i < 5 && msgArray[i] != nullptr)
    {
        if (msgArray[i]->priority < msg->priority)
        {
            for (register int j = 4; j > i; j--) msgArray[j] = msgArray[j - 1];
            break;
        }
        i++;
    }

    if (i < 5)
        msgArray[i] = msg;
}

void init()
{
    msgCount = 0;

    register int i, j;

    for (i = 0; i < MAX_USER; i++)
    {
        followCnt[i] = 0;

        j = 0;

        while (userMessage[i][j] != nullptr && j < 5)
            userMessage[i][j++] = nullptr;
    }

    for (i = 0; i < MAX_HASH; i++)
    {
        hashTagHash[i].value = 0;

        for (j = 0; j < 5; j++)
        {
            hashTagHash[i].msgPtr[j] = nullptr;
        }
    }
}

void createMessage(int msgID, int userID, char msgData[])
{
    unsigned int time = (msgData[0] - '0') << 18 | (msgData[1] - '0') << 14 |
        (msgData[3] - '0') << 11 | (msgData[4] - '0') << 7 |
        (msgData[6] - '0') << 4 | (msgData[7] - '0');

    int priority = (time << 10) - userID;

    register ull hash = 0;
    register Msg* msg = &msgList[msgCount++];
    msg->msgId = msgID;
    msg->priority = priority;

    register char* str = &msgData[9];

    while (true)
    {
        if (*str == '#') hash = 0;
        else if (*str == ' ' || *str == '\0')
        {
            register int index = hash % MAX_HASH;

            while (1)
            {
                if (hashTagHash[index].msgPtr[0] == nullptr || hashTagHash[index].value == hash)
                {
                    hashTagHash[index].value = hash;
                    insert(hashTagHash[index].msgPtr, msg);
                    break;
                }
                else
                    index = (index + 1) % MAX_HASH;
            }

            if (*str == '\0') break;
        }
        else
            hash = (hash << 5) + *str;
        str++;
    }

    insert(userMessage[userID], msg);
}

void followUser(int userID1, int userID2)
{
    follow[userID1][followCnt[userID1]] = userID2;
    followCnt[userID1]++;
}

int searchByHashtag(char tagName[], int retIDs[])
{
    register int i = 0;
    register ull h = 0;

    for (i=1; tagName[i]; i++) // #는 제외이므로 i=1부터임에 유의
        h = (h << 5) + tagName[i];

    register int index = (h % MAX_HASH);

    while (true)
    {
        if (hashTagHash[index].msgPtr[0] != nullptr && hashTagHash[index].value == h)
            break;
        else if (hashTagHash[index].msgPtr[0] == nullptr)
            return 0;
        else
            index = (index + 1) % MAX_HASH;
    }

    i = 0;
    while (i < 5 && hashTagHash[index].msgPtr[i] != nullptr)
    {
        retIDs[i] = hashTagHash[index].msgPtr[i]->msgId;
        i++;
    }

    return i;
}

int getMessages(int userID, int retIDs[])
{
    register int i, k;
    ull h = 0;
    Msg* resultMsg[5] = { nullptr, };

    int retcount = 0;
    int fCount = followCnt[userID], followID = 0;


    for (i = 0; i < 5; i++) resultMsg[i] = userMessage[userID][i];
    for (i = 0; i < fCount; i++)
    {
        followID = follow[userID][i];

        k = 0;

        while (k < 5 && userMessage[followID][k] != nullptr)
        {
            insert(resultMsg, userMessage[followID][k]);
            k++;
        }
    }

    while (retcount < 5 && resultMsg[retcount] != nullptr)
    {
        retIDs[retcount] = resultMsg[retcount]->msgId;
        retcount++;
    }

    return retcount;
}
*/