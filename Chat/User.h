#pragma once
#include <iostream>
#include <vector>
#include "Friends.h"
#include "Message.h"

class User
{
private:

	std::string _password;
	std::string _login;
	std::string _name;
	std::string _surname;
	std::vector <Friends> _friends;
	std::vector <Message> _chat;

public:

	User() = default;
	User(std::string login);
	~User() = default;

	std::string getLogin();
	std::string getPassword();
	std::string getName();
	std::string getSurname();

	void setLogin(std::string login);
	void setPassword(std::string password);
	void setName(std::string name);
	void setSurname(std::string surname);

	void addFriends(std::string surname, std::string name, int a);
	size_t getSizeFriends();
	void getFriends();
	std::string getInfoFriends(int index);
	bool checking_for_friends(std::vector <User>& other, int ñhoice);
	int getIndexFriens(int a);
	void createMessage(int sender, std::string& text);
	void sendMessage(std::vector <User>& other, int sender, int index, std::string& text);
	size_t getSizeChat();
	int getIndexMessage(int a);
	std::string getTextMessage(int a);
	void getFriendsMesssage();
	void clearMessage();
};

