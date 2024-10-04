#pragma once
#include <iostream>
#include "User.h"


class Message
{
private:

	int _index;
	std::string _message;

public:

	Message(int index, std::string message);
	~Message() = default;

	int getIndex();
	std::string getMessage();
	void creatMessage(std::vector <User>& other);

	/*void openMessage();*/

};




