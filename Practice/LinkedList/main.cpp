// dsexpert 3123 : Ű�ΰ�(Keylogger)
/*
[input]
2
<<BP<A>>Cd-
ThIsIsS3Cr3t

[answer]
BAPC
ThIsIsS3Cr3t
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

const int LM = (int)1e6 + 10;
char str[LM];

int main()
{
	int tc;
	char cmd;
	scanf("%d", &tc);

	while (tc--)
	{
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