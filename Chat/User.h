#pragma once
#include <iostream>


class User
{
private:

	std::string _password;
	std::string _login;
	std::string _name;
	std::string _surname;

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
	
};

