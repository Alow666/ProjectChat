#include "User.h"

User::User(std::string login) : _login(login)
{
	std::cout << "Ââåäèòå ïàðîëü: " << std::endl;
	std::cin >> _password;
	std::cout << "Ââåäèòå âàøå èìÿ: " << std::endl;
	std::cin >> _name;
	std::cout << "Ââåäèòå âàøó Ôàìèëèþ: " << std::endl;
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
	_friends.push_back(Friends(name, surname, a));
};
size_t User::getSizeFriends()
{
	return _friends.size();
};
std::string User::getInfoFriends(int index)
{
	return _friends[index].getName();
};
void User::getFriends()
{
	for (int i = 0; i < _friends.size(); i++)
	{
		std::cout <<_friends[i].getName() << " " <<_friends[i].getSurName() << std::endl;
	}
};
bool User::checking_for_friends(std::vector <User>& other, int ñhoice)
{
	for (int i = 0; i < _friends.size(); i++)
	{
		if (ñhoice == _friends[i].getIndex())
		{
			std::cout << ñhoice << ") " << other[ñhoice].getName() << " " << other[ñhoice].getSurname() << " <- Ó âàñ â äðóçüÿõ" << std::endl;
			return false;
		};
	}
	return true;
};
bool User::checking_for_friends_to_add(int ñhoice)
{
	for (int i = 0; i < _friends.size(); i++)
	{
		if (ñhoice == _friends[i].getIndex())
		{
			return false;
		};
	}
	return true;
};
int User::getIndexFriens(int a)
{
	return _friends[a].getIndex();
};

void User::createMessage(int sender, std::string& text)
{
	_chat.push_back(Message(sender, text));
};

void User::sendMessage(std::vector <User>& other, int sender, int index, std::string& text)
{
	other[index].createMessage(sender, text);
};

size_t User::getSizeChat()
{
	return _chat.size();
};

int User::getIndexMessage(int a)
{
	return _chat[a].getSender();
};

std::string User::getTextMessage(int a)
{
	return _chat[a].getMessage();
};

void User::getFriendsMesssage()
{
	for (int i = 0; i < _friends.size(); i++)
	{
		std::cout << i << ") " << _friends[i].getName() << " " << _friends[i].getSurName() << std::endl;
	}
};

void User::clearMessage()
{
	_chat.clear();
};