#include "LL.h"
#include <exception>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	LL<string> names;

	names.push_back("Alice");
	names.push_back("Bob");
	names.push_back("Jen");
	names.push_back("Sky");
	names.push_back("Ted");

	for (int i = 0; i < 3; i++)
		cout << names.pop_front() << endl;

	cout << endl;

	names.push_back("Sue");
	names.push_back("Sam");

	bool flag = false;

	try
	{
		while (!flag)
			cout << names.pop_front() << endl;
	}
	catch (exception e) { flag = true; }

	names.push_back("Eva");

	try
	{
		cout << endl;
		cout << names.peek() << endl;
	}
	catch (exception e) { cout << "This should not output\n"; }

	return 0;
}