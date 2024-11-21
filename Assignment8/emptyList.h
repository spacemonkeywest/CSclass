#include <string>

#ifndef EMPTYLIST_H
#define EMPTYLIST_H

class emptyList : public std::exception
{
private:
	std::string message;

public:
	emptyList() : message("Empty Linked List") {}
	emptyList(std::string m) : message(m) {}
	std::string what() { return message; }
};
#endif