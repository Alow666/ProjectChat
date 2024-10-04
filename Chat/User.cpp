#include "User.h"

User::User(std::string login) : _login(login)
{
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


void User::addFriends(std::string surname, std::string name, int a)
{
	friends.push_back(Friends(name, surname, a));
};
size_t User::getSizeFriends()
{
	return friends.size();
};
std::string User::getInfoFriends(int index)
{
	return friends[index].getName();
};
void User::getFriends()
{
	for (int i = 0; i < friends.size(); i++)
	{
		std::cout <<friends[i].getName() << " " << friends[i].getSurName() << std::endl;
	}
};
void User::getFriendsMesssage()
{
	for (int i = 0; i < friends.size(); i++)
	{
		std::cout << i << ") " << friends[i].getName() << " " << friends[i].getSurName() << std::endl;
	}
};
bool User::checking_for_friends(std::vector <User>& other, int �hoice)
{
	for (int i = 0; i < friends.size(); i++)
	{
		if (�hoice == friends[i].getIndex())
		{
			std::cout << �hoice << ") " << other[�hoice].getName() << " " << other[�hoice].getSurname() << " <- � ��� � �������" << std::endl;
			return false;
		};
	}
	return true;
};
bool User::checking_for_friends_to_add(int �hoice)
{
	for (int i = 0; i < friends.size(); i++)
	{
		if (�hoice == friends[i].getIndex())
		{
			return false;
		};
	}
	return true;
};


int User::number_of_messages()
{
	return messageUser.size();
};
void User::addMessage(std::string text, int choice)
{
	messageUser.push_back(Message(choice, text));
};
std::string User::receiving_a_letter(std::vector <User>& other, int indexEntrance, int indexFriend)
{
	std::cout << other[indexEntrance].getInfoFriends(indexFriend) << "������� ��� ���������" << std::endl;
	
};