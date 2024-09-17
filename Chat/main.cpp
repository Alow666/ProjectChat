#include <iostream>
#include <vector>

#include "User.h"
#include "Entrance.h"

int main()
{
	setlocale(LC_ALL, "Rus");
	int сhoice;
	bool permission_to_enter = false;
	std:: vector <User> vectorUser; //Вектор с пользователями
	std::unique_ptr<Entrance> ptr_entrance = std::make_unique <Entrance>();// вход в учетки


	std::cout << "Добро пожаловать в чат!" << std::endl;

	while (true)
	{
		std::cout << "1)Войти в аккаунт \n2)Зарегистрировать аккаунт \n3)Выйти" << std::endl;
		std::cin >> сhoice;

		switch (сhoice)
	{
		case 1:
			if (vectorUser.size() == 0)//Проверка наличия пользователей
			{
				std::cout << "В чате еще никого нету(" << std::endl;
				continue;
			}

			permission_to_enter = ptr_entrance->entranceLogin(vectorUser);//проверка логина

			if (permission_to_enter == false)//
			{
				continue;
			}

			permission_to_enter = ptr_entrance->entrancePassword(vectorUser);//

			while (permission_to_enter) // Управление учеткой 
			{
				



			
				
			}
			continue;
		case 2:
			vectorUser.push_back(User());
			std::cout << "Теперь вы можете войти в аккаунт." << std::endl;
			continue;
		case 3:
			std::cout << "До скорой встречи!" << std::endl;
			break;
		default:
			std::cout << "Выберите что то из списка !" << std::endl;
			continue;
		}
	}

}


