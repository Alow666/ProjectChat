#pragma once
#include <iostream>
#include <vector>
#include "Entrance.h"
#include "User.h"

void Entrance::setSLogin(std::string a)
{
	_loginScan = a;
}

void Entrance::setSPassword(std::string a)
{
	_passwordScan = a;
}

void Entrance::setAccess(bool a)
{
	_access = a;
}

void Entrance::setIndex(int a)
{
	_index = a;
}

std::string Entrance::getSLogin()
{
	return _loginScan;
}

std::string Entrance::getSPassword()
{
	return _passwordScan;
}

bool Entrance::getAccess()
{
	return _access;
}

int Entrance::getIndex()
{
	return _index;
}

bool Entrance::entranceLogin(std::vector<User>& other)
{
	while (true)
	{
		std::cout << "Введите логин: " << std::endl;
		std::cin >> _loginScan;
			
		for (int i = 0; i < other.size(); i++)
		{
			if (other[i].getLogin() == _loginScan)
			{
				_index = i;
				return true;
			}
		}
		std::cout << "Такого пользователя не существует!" << std::endl;
		return false;
	}
}

bool Entrance::entrancePassword(std::vector<User>& other)
{
	int attempts = 6;
	for (int i = 0; i < 6; i++)
	{
		std::cout << "Введите пароль: " << std::endl;
		std::cin >> _passwordScan;

		if (other[_index].getPassword() == _passwordScan)
		{
			return true;
		}

		std::cout << "Неверный пароль! Попыток оталось:" << --attempts << std::endl;
	}
	std::cout << "Попытки закончились!" << std::endl;
	return false;
};