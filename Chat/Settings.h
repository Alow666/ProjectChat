#pragma once
#include <iostream>
#include "User.h"


class Setting: protected User
{
private:

	int _index;

public:

	Setting() = default;

	virtual ~Setting() = default;

};

