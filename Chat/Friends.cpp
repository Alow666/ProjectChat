#include "Friends.h"

Friends::Friends(std::string name, std::string surname, int index) :_name(name), _surname(surname), _index(index) {};

std::string Friends::getName()
{
	return _name;
};

std::string Friends::getSurName()
{
	return _surname;
};

int Friends::getIndex()
{
	return _index;
};