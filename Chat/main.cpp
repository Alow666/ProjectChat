#include <iostream>
#include <vector>

#include "User.h"
#include "Entrance.h"


int main()
{
	setlocale(LC_ALL, "Rus");
	int сhoice, choice2, choice4, choice5;
	int entranceIndex;
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

			if (permission_to_enter == false)
			{
				continue;
			}

			permission_to_enter = ptr_entrance->entrancePassword(vectorUser);//проверка пароля

			if (permission_to_enter == true) std::cout << "Добро пожаловать " << vectorUser[ptr_entrance->getIndex()].getName()<< std::endl; 

			entranceIndex = ptr_entrance->getIndex();//№№№№№№№№№№№№№№№№№№№№№№№№№№№№№№№№№№№№№№№№№№№№№№№№№№№№№№№№№№№№№№№№№№№№№№

			while (permission_to_enter) // Управление учеткой 
			{
				std::cout << "\n1) Чат" << std::endl;
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

					std::cout << "\n1) Мои друзья" << std::endl;
					std::cout << "2) Пользователи чата (добавить в друзья)" << std::endl;
					std::cout << "0) Вернуться назад" << std::endl;

					std::cin >> choice4;

					switch (choice4) 
					{
					case 1:
						std::cout << "Ваши друзья:" << std::endl;

						if(vectorUser[ptr_entrance->getIndex()].getSizeFriends() == 0) //может не показывать первого друга
						{
							std::cout << "У вас пока что нету друзей(" << std::endl;
							continue;
						}
						if (vectorUser[ptr_entrance->getIndex()].getSizeFriends() > 0)
						{
							vectorUser[ptr_entrance->getIndex()].getFriends(vectorUser);
							continue;
						}
			
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
							std::cin >> choice5; // Нужен Try и ловить искл (переполнение вектора) ##############################################################################

							if (vectorUser.size() < choice5)
							{
								std::cout << "Выберите из существующих!" << std::endl;
								continue;
							};

							if (ptr_entrance->getIndex() == choice5)
							{
								std::cout << "Вы не можете добавить себя!" << std::endl;
								break;
							}

							if (ptr_entrance->getIndex() != choice5 )
							{
								vectorUser[ptr_entrance->getIndex()].addFriends(choice5);
								std::cout << "Вы добавили" << vectorUser[choice5].getName() << " " << vectorUser[choice5].getSurname()<< " в друзья" <<std::endl;
								break;
							}
							break;
						} while (true);
						break;
					case 0:
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
					permission_to_enter = false;
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
	return 0;
}


