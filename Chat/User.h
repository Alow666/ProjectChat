#pragma once
#include <iostream>
#include <vector>
#include "Message.h"



class User
{
private:

	std::string _password;
	std::string _login;
	std::string _name;
	std::string _surname;
	std::vector <Message> messageUser;
	std::vector <int> friends;

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

	void addFriends(int b);
	size_t getSizeFriends();
	void getFriends(std::vector<User>& other);

	void number_of_messages();
	void addMessage(std::string text);



	void viewing_messages();
	/*std::string creatMassage();*/

	//std::string friends_for_correspondence();
};

