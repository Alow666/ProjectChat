#include "User.h"
#include <iostream>
#include <vector>

User::User()
{
	std::cout << "������� �����: " << std::endl;
	std::cin >> _login;
	std::cout << "������� ������: " << std::endl;
	std::cin >> _password;
	std::cout << "������� ���� ���: " << std::endl;
	std::cin >> _name;
	std::cout << "������� ���� �������: " << std::endl;
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
void User::addUser(int b)
{
	friends.push_back(b);
};