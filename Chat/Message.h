#pragma once
#include <iostream>
#include "Message.h"

class Message
{
private:

	int _sender;//�����������
	std::string _message;// ����� ���������

public:

	Message() = default;
	Message(int sender, std::string message);
	int getSender();
	std::string getMessage();
	~Message() = default;

};




