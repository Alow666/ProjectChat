#include "Chat.h"


Chat::Chat(int F, int S) : _indexFirst(F), _indexSecond(S){};

Chat::Chat(const Chat&& movet)
{
	_connecting—hat = movet._connecting—hat;
};

int Chat::getFirstIndex() 
{
	return _indexFirst;
};


int Chat::getSecondIndex()
{
	return _indexSecond;
};

//void Chat::addMessage(int F, int S) 
//{
//
//};