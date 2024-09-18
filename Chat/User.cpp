#include "User.h"
#include <iostream>
#include <vector>



User::User(std::string login) : _login(login)
{
	std::cout << "¬ведите пароль: " << std::endl;
	std::cin >> _password;
	std::cout << "¬ведите ваше им€: " << std::endl;
	std::cin >> _name;
	std::cout << "¬ведите вашу ‘амилию: " << std::endl;
	std::cin >> _surname;
};

std::string User::getLogin() 
{
	return _login;
}

std::string User::getPassword()
{
	return _password;
}
std::string User::getName()
{
	return _name;
}
std::string User::getSurname()
{
	return _surname;
}
void User::setLogin(std::string login)
{
	_login = login ;
}
void User::setPassword(std::string password)
{
	_password = password;
}
void User::setName(std::string name)
{
	_name = name;
}
void User::setSurname(std::string surname)
{
	_surname = surname;
}
void User::addFriends(int b)
{
	friends.push_back(b);
};

size_t User::getSizeFriends()
{
	return friends.size();
};

void User::getFriends(std::vector<User>& other)
{
	for (int i = 0; i < friends.size(); i++)
	{
		std::cout << other[friends[i]].getName() << " " << other[friends[i]].getSurname() << std::endl;
	}
};