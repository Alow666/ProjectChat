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
bool User::checking_for_friends(std::vector <User>& other, int ñhoice)
{
	for (int i = 0; i < friends.size(); i++)
	{
		if (ñhoice == friends[i].getIndex())
		{
			std::cout << ñhoice << ") " << other[ñhoice].getName() << " " << other[ñhoice].getSurname() << " <- Ó âàñ â äðóçüÿõ" << std::endl;
			return false;
		};
	}
	return true;
};
bool User::checking_for_friends_to_add(int ñhoice)
{
	for (int i = 0; i < friends.size(); i++)
	{
		if (ñhoice == friends[i].getIndex())
		{
			return false;
		};
	}
	return true;
};


size_t User::number_of_messages()
{
	return messageUser.size();
};
void User::addFirstMessage(std::vector <User>& other, std::string text, int choice, int a)
{
	other[friends[choice].getIndex()].messageUser.push_back(Message(a, text, choice));
};
int User::message_counter(int b)
{
	int a = 0;

	for (int i = 0; i < messageUser.size(); i++)
	{
		if(messageUser[b].fromWhom() == messageUser[i].fromWhom())
		{
			++a;
		}
	}

	return a;
};
void User::receiving_a_letter(std::vector <User>& other, int indexEntrance)
{
	for (int i = 0; i < friends.size(); i++)
	{
		std::cout << i << ") " << other[friends[i].getIndex()].getName() << " " << other[friends[i].getIndex()].getSurname() << " " << other[indexEntrance].message_counter(i) << " ñîîáùåíèÿ." << std::endl;
	}
};



void User::chat(std::vector <User>& other, int choice, int indexEntrance)
{
	for (int i = 0; i < messageUser.size(); i++)
	{
		if (messageUser[i].toWhom() == choice && messageUser[i].fromWhom() == indexEntrance)
		{
			std::cout << "Âû: " << messageUser[i].getMessage() << std::endl;
		}
		if (other[friends[choice].getIndex()].messageUser[i].fromWhom() == choice && other[friends[choice].getIndex()].messageUser[i].toWhom() == indexEntrance)
		{
			std::cout << other[messageUser[i].fromWhom()].getName() << ": " << messageUser[i].getMessage() << std::endl;
		}
	}
};