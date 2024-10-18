#pragma once
#include <iostream>
#include "Message.h"

class Message
{
private:

	int _sender;//отправитель
	std::string _message;// текст сообщения

public:

	Message() = default;
	Message(int sender, std::string message);
	int getSender();
	std::string getMessage();
	~Message() = default;

};




