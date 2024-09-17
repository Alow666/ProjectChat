#include <iostream>
#include <vector>

#include "User.h"
#include "Entrance.h"

int main()
{
	setlocale(LC_ALL, "Rus");
	int сhoice, choice2;
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
				std::cout << "Добро пожаловать " << vectorUser[ptr_entrance->getIndex()].getName()<< " " << vectorUser[ptr_entrance->getIndex()].getSurname() << std::endl;
				std::cout << "1) Чат" << std::endl;
				std::cout << "2) Друзья" << std::endl;
				std::cout << "3) Меню настроек" << std::endl;
				std::cout << "0) Выйти из аккаунта" << std::endl;

				std::cin >> choice2;

				switch (choice2)
				{
				case 1:
					std::cout << "1) Чат" << std::endl;
					continue;
				case 2:

					continue;
				case 3:

					continue;
				case 0:
					std::cout << "До скорой встречи!)" << std::endl;
					break;
				default:
					std::cout << "Выберите что то из списка !" << std::endl;
					continue;
				}



			
				
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


