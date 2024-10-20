#pragma once
#include <iostream>
#include <vector>

class GeneralChat
{
private:

	std::vector <std::string> _general_chat;
	std::vector <int> _indexUser;

public:

	GeneralChat() = default;
	~GeneralChat() = default;

	void addMessage(std::string& text, int index);
	size_t getSize();
	int getIndex(int index);
	std::string getText(int index);


};


