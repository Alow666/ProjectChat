#pragma once
#include <iostream>
#include <vector>

class Message
{
private:

	int _from_whom;// �� ����
	std::vector <std::string> _message;
	int _to_whom; // ����

public:

	Message(int from_whom, int to_whom);
	~Message() = default;

	void addMessageClass();

	int fromWhom();
	int toWhom();
	
	

	

};




