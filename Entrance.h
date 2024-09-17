#pragma once
#include <iostream>
#include "User.h"

class Entrance
{
private:

	std::string _loginScan;
	std::string _passwordScan;
	bool _access = false;
	int _index{};

public:

	Entrance() = default;
	 ~Entrance() = default;

	 void setSLogin(std::string a);
	 void setSPassword(std::string a);
	 void setAccess(bool a);
	 void setIndex(int a);
	 std::string getSLogin();
	 std::string getSPassword();
	 bool getAccess();
	 int getIndex();
	 bool entranceLogin(std::vector<User>& other);
	 bool entrancePassword(std::vector<User>& other);
};