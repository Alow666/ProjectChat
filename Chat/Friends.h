#pragma once
#include <iostream>

class Friends
{
private:

	std::string _name;
	std::string _surname;
	int _index;

public:

	Friends(std::string name, std::string surname, int index);
	~Friends() = default;

	std::string getName();
	std::string getSurName();
	int getIndex();

};