#pragma once
#include <iostream>
#include <vector>


class User
{
private:

	std::string _password;
	std::string _login;
	std::string _name;
	std::string _surname;
	std::vector <std::string> message;
	std::vector <int> friends;

public:

	User();
	~User() = default;
	std::string getLogin();
	std::string getPassword();
	std::string getName();
	std::string getSurname();
	void setLogin(std::string login);
	void setPassword(std::string password);
	void setName(std::string name);
	void setSurname(std::string surname);

	void addUser(int b);


};

