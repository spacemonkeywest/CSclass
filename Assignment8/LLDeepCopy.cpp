#include "LL.h"
#include <exception>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	LL<string> disney;
	string character;

	disney.push_back("Mickey");
	disney.push_back("Minnie");
	disney.push_back("Pluto");

	LL<string> disneyLand(disney);

	disney.push_back("Donald");

	disneyLand.push_back("Goofy");

	cout << disney.pop_front() << endl;

	for (int i = 0; i < 5; i++)
	{
		character = disney.pop_front();
		cout << character << endl;
		disney.push_back(character);

		cout << endl;

		character = disneyLand.pop_front();
		cout << character << endl;
		disneyLand.push_back(character);
	}

	disneyLand.push_back("Ariel");

	disney = disneyLand;

	cout << endl;
	cout << disneyLand.pop_front() << endl;

	disney.pop_front();

	for (int i = 0; i < 5; i++)
	{
		character = disney.pop_front();
		cout << character << endl;
		disney.push_back(character);

		cout << endl;

		character = disneyLand.pop_front();
		cout << character << endl;
		disneyLand.push_back(character);
	}

	return 0;
}