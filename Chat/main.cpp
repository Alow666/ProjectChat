#include <iostream>
#include <vector>

#include "User.h"
#include "Entrance.h"

int main()
{
	setlocale(LC_ALL, "Rus");
	int сhoice, choice2, choice3, choice4, choice5;
	bool permission_to_enter = false;
	bool friend1 = false;
	bool exit = true;
	std:: vector <User> vectorUser; //Вектор с пользователями
	std::unique_ptr<Entrance> ptr_entrance = std::make_unique <Entrance>();// вход в учетки


	std::cout << "Добро пожаловать в чат!" << std::endl;

	while (exit)
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
				std::cout << "Добро пожаловать " << vectorUser[ptr_entrance->getIndex()].getName()<< std::endl;
				std::cout << "1) Чат" << std::endl;
				std::cout << "2) Дузья" << std::endl;
				std::cout << "3) Настройка аккаунта" << std::endl;
				std::cout << "0) Выйти из аккаунта" << std::endl;

				std::cin >> choice2;

				switch (choice2)
				{
				case 1:

					/*std::cout << "1) Мои друзья" << std::endl;
					std::cout << "2) Поиск людей" << std::endl;
					std::cout << "0) Вернуться назад" << std::endl;

					std::cin >> choice3;

					switch (choice3)
					{
					case 1:

					case 2:

					case 0:
						break;
					default:
						std::cout << "Выберите что то из списка !" << std::endl;
						continue;
					}*/
					
					continue;
				case 2:
					std::cout << "1) Мои друзья" << std::endl;
					std::cout << "2) Пользователи чата (добавить в друзья)" << std::endl;
					std::cout << "0) Вернуться назад" << std::endl;

					std::cin >> choice4;

					switch (choice4)
					{
					case 1:

					case 2:

						std::cout << "Пользователи:" << std::endl;
						choice5 = 0;

						for (; choice5 < vectorUser.size(); choice5++)
						{

							if (ptr_entrance->getIndex() == choice5)
							{
								std::cout << choice5 << ") " << vectorUser[choice5].getName() << " " << vectorUser[choice5].getSurname() << " <- Это вы" << std::endl;
							};

							if (ptr_entrance->getIndex() != choice5)
							{
								std::cout << choice5 << ") " << vectorUser[choice5].getName() << " " << vectorUser[choice5].getSurname() << std::endl;
							};
							
						}

						std::cout << "Выберите кого добавить в друзья" << std::endl;

						do
						{
							std::cin >> choice5;

							if (ptr_entrance->getIndex() == choice5)
							{
								std::cout << "Вы не можете добавить себя!" << std::endl;
							}

							if (ptr_entrance->getIndex() != choice5)
							{
								vectorUser[ptr_entrance->getIndex()].addUser(choice5);
								std::cout << "Вы добавили" << vectorUser[choice5].getName() << " " << vectorUser[choice5].getSurname()<< " в друзья" <<std::endl;
								friend1 = true;
							}

						} while (friend1);

					case 0:// баг не выходит из учетки
						permission_to_enter = true;
						break;
					default:
						std::cout << "Выберите что то из списка !" << std::endl;
						continue;
					}
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
			exit = false;
			break;
		default:
			std::cout << "Выберите что то из списка !" << std::endl;
			continue;
		}
	}

}


