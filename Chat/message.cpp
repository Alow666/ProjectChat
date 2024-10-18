#include "Message.h"

Message::Message(int sender, std::string message) : _sender(sender), _message(message){};

int Message::getSender() 
{
	return _sender;
};

std::string Message::getMessage() 
{
	return _message;
};