#pragma once

#include <iostream>
#include <vector>
#include "Message.h"

class Chat
{
private:

	int _indexFirst;
	int _indexSecond;
	std::vector <Message> _connecting—hat;



public:

	Chat(int F, int S);
	Chat(const Chat&& movet);
	~Chat() = default;

	int getFirstIndex();
	int getSecondIndex();
	//void addMessage(int F, int S, std::string text);


	

};


