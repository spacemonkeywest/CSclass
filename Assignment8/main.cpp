#include <iostream>
#include <fstream>
#include <string>
#include "emptyList.h"
#include "LL.h"

using namespace std;

class cardType
{
public:
	cardType() : face('\0'), suit('\0') {}

	cardType(char f, char s) : face(f), suit(s) {}

	bool operator==(const cardType& rhs) const
	{
		return this->face == rhs.face;
	}

	bool operator<(const cardType& rhs) const
	{
		return getValueFromFace(this->face) < 
				getValueFromFace(rhs.face);
	}

	char getFace() const { return face; }
	char getSuit() const { return suit; }

private:

int getValueFromFace(char f) const
{
	if (f >= '2' && f <= '9')
		return f - '0';

	if (f == 'T')
		return 10;

	if (f == 'J')
		return 11;

	if (f == 'Q')
		return 12;

	if (f == 'K')
		return 13;

	if (f == 'A')
		return 14;
}

	char face;
	char suit;
};



int main()
{
	
	return 0;
}


