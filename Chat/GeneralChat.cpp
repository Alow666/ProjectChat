#include "GeneralChat.h"

void GeneralChat::addMessage(std::string& text, int index) 
{
	_general_chat.push_back(text);
	_indexUser.push_back(index);
};

size_t GeneralChat::getSize()
{
	return _general_chat.size();
};

int GeneralChat::getIndex(int index)
{
	return _indexUser[index];
};

std::string GeneralChat::getText(int index)
{
	return _general_chat[index];
};