#include <stdio.h>
#define MAX_NUMBER_SIZE (103)

class BigInteger
{
public:
	char num[MAX_NUMBER_SIZE];

	BigInteger operator+(BigInteger other)
	{
		BigInteger result;
		int resultIdx = 0;

		int mySize = this->getSize() - 1;
		int otherSize = other.getSize() - 1;

		int carry = 0;
		
		while (mySize >= 0 && otherSize >= 0)
		{
			int n1 = num[mySize] - '0';
			int n2 = other.num[otherSize] - '0';

			int sum = (n1 + n2 + carry) % 10;
			
			result.num[resultIdx++] = sum + '0';

			carry = (n1 + n2 + carry) / 10;
			mySize--; otherSize--;
		}

		// for remain numbers
		while (mySize >= 0)
		{
			int sum = (num[mySize] - '0' + carry) % 10;
			carry = (num[mySize] - '0' + carry) / 10;

			result.num[resultIdx++] = sum + '0';

			mySize--;
		}

		while (otherSize >= 0)
		{
			int sum = (other.num[otherSize] - '0' + carry) % 10;
			carry = (other.num[otherSize] - '0' + carry) / 10;

			result.num[resultIdx++] = sum + '0';

			otherSize--;
		}

		if(carry > 0) result.num[resultIdx++] = carry + '0';

		int firstIdx = 0;
		int lastIdx = resultIdx - 1;

		// reverse
		while (firstIdx < lastIdx)
		{
			char temp = result.num[firstIdx];
			result.num[firstIdx] = result.num[lastIdx];
			result.num[lastIdx] = temp;

			firstIdx++; lastIdx--;
		}

		result.num[resultIdx] = '\0';

		return result;
	}

	int getSize()
	{
		int result = 0;

		while (num[result] != '\0') result++;

		return result;
	}
};

int main(void)
{
	BigInteger n1, n2;
	BigInteger result;

	scanf("%s", n1.num);
	scanf("\n%s", n2.num);

	result = n1 + n2;

	printf("%s\n", result.num);
	

	return 0;
}