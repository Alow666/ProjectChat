#include <iostream>
#include <vector>

#include "User.h"
#include "Entrance.h"


int main()
{
	setlocale(LC_ALL, "Rus");
	int сhoice;
	bool permission_to_enter = false;
	std::string xxx;
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

			if (permission_to_enter == false)
			{
				continue;
			}

			permission_to_enter = ptr_entrance->entrancePassword(vectorUser);//проверка пароля

			if (permission_to_enter == true) std::cout << "Добро пожаловать " << vectorUser[ptr_entrance->getIndex()].getName()<< std::endl; 

			

			while (permission_to_enter) // Управление учеткой 
			{
				std::cout << "\n1) Чат" << std::endl;
				std::cout << "2) Друзья" << std::endl;
				std::cout << "3) Настройка аккаунта" << std::endl;
				std::cout << "0) Выйти из аккаунта" << std::endl;

				std::cin >> сhoice;

				switch (сhoice)
				{
				case 1:

					while (true) 
					{
						std::cout << "1) Входящие сообщения (У вас " << vectorUser[ptr_entrance->getIndex()].number_of_messages() << " сообщений)" << std::endl;
						std::cout << "2) Написать сообщение" << std::endl;
						std::cout << "0) Вернуться назад" << std::endl;

						std::cin >> сhoice;

						switch (сhoice)
						{
						case 1:

							std::cout << "У вас "<< vectorUser[ptr_entrance->getIndex()].number_of_messages() <<  " не прочитанных cообщений:" << std::endl;

							for (int i = 0; i < vectorUser[ptr_entrance->getIndex()].number_of_messages(); i++)
							{

							}

							std::cout << "" << std::endl;
							std::cin >> сhoice;



						case 2:
							
							if (vectorUser[ptr_entrance->getIndex()].getSizeFriends() == 0)
							{
								std::cout << "Пока что писать некому, добавьте друзей!" << std::endl;
								continue;
							}

							std::cout << "Кому вы хотите написать сообщение: " << std::endl;

							vectorUser[ptr_entrance->getIndex()].getFriendsMesssage();
							
							do
							{
								std::cin >> сhoice;

								if (vectorUser[ptr_entrance->getIndex()].getSizeFriends() < сhoice || сhoice < 0)
								{
									std::cout << "Выберите из существующих!" << std::endl;
									continue;
								}
								

									


								
								break;

							} while (true);


						case 0:
							break;
						default:
							std::cout << "Выберите что то из списка !" << std::endl;
							continue;
						}
						break;
					}
					continue;

				case 2:

					while (true)
					{
						std::cout << "\n1) Мои друзья" << std::endl;
						std::cout << "2) Пользователи чата (добавить в друзья)" << std::endl;
						std::cout << "0) Вернуться назад" << std::endl;

						std::cin >> сhoice;

						switch (сhoice)
						{
						case 1://+++++
							std::cout << "Ваши друзья:" << std::endl;

							if (vectorUser[ptr_entrance->getIndex()].getSizeFriends() == 0)
							{
								std::cout << "У вас пока что нету друзей(" << std::endl;
								continue;
							}
							if (vectorUser[ptr_entrance->getIndex()].getSizeFriends() > 0)
							{
								vectorUser[ptr_entrance->getIndex()].getFriends();
								continue;
							}

						case 2:

							std::cout << "Пользователи:" << std::endl;
							сhoice = 0;

							for (; сhoice < vectorUser.size(); сhoice++)
							{
							
								if (ptr_entrance->getIndex() == сhoice)
								{
									std::cout << сhoice << ") " << vectorUser[сhoice].getName() << " " << vectorUser[сhoice].getSurname() << " <- Это вы" << std::endl;
								};
								
								if (false == vectorUser[ptr_entrance->getIndex()].checking_for_friends(vectorUser, сhoice))
								{
									continue;
								};

								if (ptr_entrance->getIndex() != сhoice)
								{
									std::cout << сhoice << ") " << vectorUser[сhoice].getName() << " " << vectorUser[сhoice].getSurname() << std::endl;
								};

							}

							std::cout << "Выберите кого добавить в друзья: " << std::endl;

							do
							{
								std::cin >> сhoice;

								if (vectorUser.size() < сhoice || сhoice < 0)
								{
									std::cout << "Выберите из существующих!" << std::endl;
									continue;
								};

								if (ptr_entrance->getIndex() == сhoice)
								{
									std::cout << "Вы не можете добавить себя!" << std::endl;
									break;
								}
								
								if (false == vectorUser[ptr_entrance->getIndex()].checking_for_friends(vectorUser, сhoice))
								{
									std::cout << "Данный пользователь уже в друзьях" << std::endl;
									break;
								};


								if (ptr_entrance->getIndex() != сhoice)
								{
									vectorUser[ptr_entrance->getIndex()].addFriends(vectorUser[сhoice].getName(), vectorUser[сhoice].getSurname(), сhoice);
									std::cout << "Вы добавили" << vectorUser[сhoice].getName() << " " << vectorUser[сhoice].getSurname() << " в друзья" << std::endl;
									break;
								}
								break;

							} while (true);

							continue;

						case 0:

							break;

						default:

							std::cout << "Выберите что то из списка !" << std::endl;
							continue;
						}
						break;
					}
					continue;

				case 3: // Настройка аккаунта

					while (true)
					{
						std::cout << "\n1) Изменить логин" << std::endl;
						std::cout << "2) Изменить пароль" << std::endl;
						std::cout << "3) Изменить имя" << std::endl;
						std::cout << "4) Изменить фамилию" << std::endl;
						std::cout << "0) Вернуться назад" << std::endl;
						std::cin >> сhoice;

						switch (сhoice)
						{
						case 1:


							while (true)
							{
								std::cout << "\nВведите новый логин: " << std::endl;
								std::cin >> xxx;
								int i = 0;
								do
								{
									if (xxx == vectorUser[i].getLogin())
									{
										std::cout << "Логин занят попробуйте другой!" << std::endl;
										std::cin >> xxx;
										i = 0;
										continue;
									}
									i++;
								} while (i < vectorUser.size());

								vectorUser[ptr_entrance->getIndex()].setLogin(xxx);
								std::cout << "Логин успешно изменен!" << std::endl;
								break;
							}
							continue;

						case 2:

							std::cout << "\nВведите новый пароль: " << std::endl;
							std::cin >> xxx;
							vectorUser[ptr_entrance->getIndex()].setPassword(xxx);
							std::cout << "\nПароль успешно изменен!" << std::endl;
							continue;

						case 3:

							std::cout << "\nВведите новое Имя: " << std::endl;
							std::cin >> xxx;
							vectorUser[ptr_entrance->getIndex()].setName(xxx);
							std::cout << "\nИмя успешно изменено!" << std::endl;
							continue;

						case 4:

							std::cout << "\nВведите новую фамилию: " << std::endl;
							std::cin >> xxx;
							vectorUser[ptr_entrance->getIndex()].setSurname(xxx);
							std::cout << "\nФамилия успешно изменена!" << std::endl;
							continue;

						case 0:

							break;

						default:
							std::cout << "\nВыберите что то из списка !" << std::endl;
							continue;
						}
						break;
					}
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

			while (true)
			{
				std::cout << "Введите логин: " << std::endl;
				std::cin >> xxx;

				if (vectorUser.size() == 0)
				{
					vectorUser.push_back(User(xxx));
					break;
				}

				if (vectorUser.size() > 0) 
				{
					int i = 0;
					do
					{
						if (xxx == vectorUser[i].getLogin())
						{
							std::cout << "Логин занят попробуйте другой" << std::endl;
							std::cin >> xxx;
							i = 0;
							continue;
						}
						i++;
					} while (i < vectorUser.size());
					
					vectorUser.push_back(User(xxx));
					break;
				}
			}
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
	return 0;
}


