#pragma once
#include <iostream>
#include <vector>
#include "Message.h"
#include "Friends.h"
#include "Entrance.h"



class User
{
private:

	std::string _password;
	std::string _login;
	std::string _name;
	std::string _surname;
	std::vector <Message> messageUser;
	std::vector <Friends> friends;
	int index;

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
	bool checking_for_friends_to_add(int ñhoice);


	int number_of_messages();
	void getFriendsMesssage();
	void addMessage(std::string text, int choice);
	
	std::string receiving_a_letter(std::vector <User>& other, int indexEntrance, int indexFriend);
	

	
};

