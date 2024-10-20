#include <iostream>
#include <vector>
#include <string>

#include "User.h"
#include "Entrance.h"
#include "GeneralChat.h"

//std::string& TEXT()
//{
//	std::string text;
//	std::getline(std::cin, text);
//	return text;
//};



int main()
{
	setlocale(LC_ALL, "Rus");
	int сhoice;
	bool permission_to_enter = false;
	std::string xxx;
	std:: vector <User> vectorUser; //Вектор с пользователями
	std::unique_ptr<Entrance> ptr_entrance = std::make_unique <Entrance>();// вход в учетки
	std::unique_ptr<GeneralChat> ptr_GChat = std::make_unique <GeneralChat>();//общий чат
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
						std::cout << "\n1) Входящие сообщения  " << std::endl;
						std::cout << "2) Написать сообщение" << std::endl;
						std::cout << "3) Общий чат" << std::endl;
						std::cout << "0) Вернуться назад" << std::endl;

						std::cin >> сhoice;

						switch (сhoice)
						{
						case 1:

							if (vectorUser[ptr_entrance->getIndex()].getSizeChat() == 0)
							{
								std::cout << "\nСообщений нет!" << std::endl;
								continue;
							}

							for (int i = 0; i < vectorUser[ptr_entrance->getIndex()].getSizeChat(); i++)
							{
								std::cout << vectorUser[vectorUser[ptr_entrance->getIndex()].getIndexMessage(i)].getName() << " -> " << vectorUser[ptr_entrance->getIndex()].getTextMessage(i) << std::endl;
							}

							vectorUser[ptr_entrance->getIndex()].clearMessage();

							continue;
						case 2:
							
							if (vectorUser[ptr_entrance->getIndex()].getSizeFriends() == 0)
							{
								std::cout << "\nНеобходимо добавить друзей!" << std::endl;
								continue;
							}

							vectorUser[ptr_entrance->getIndex()].getFriendsMesssage();

							std::cout << "\nКому вы хотите написать ?: " << std::endl;
							
							do
							{
								std::cin >> сhoice;

								if (vectorUser[ptr_entrance->getIndex()].getSizeFriends() < сhoice || сhoice < 0)
								{
									std::cout << "\nВыберите из существующих!" << std::endl;
									continue;
								}
								
								std::cout << "\nНапишите сообщение:" << std::endl;
								std::cin >> xxx;

								vectorUser[ptr_entrance->getIndex()].sendMessage(vectorUser, ptr_entrance->getIndex(), vectorUser[ptr_entrance->getIndex()].getIndexFriens(сhoice), xxx);
					

								std::cout << "\nСообщение отправлено!" << std::endl;
								
								break;

							} while (true);

							continue;

						case 3:

							while (true) 
							{

								std::cout << "\n";
								for (int i = 0; i < ptr_GChat->getSize(); i++)
								{
									std::cout << vectorUser[ptr_GChat->getIndex(i)].getName() << " --> " << ptr_GChat->getText(i) << std::endl;
								}
								std::cout << "\n1) Написать сообщение \n0) Выйти" << std::endl;

								std::cin >> сhoice;

								if (1 < сhoice || сhoice < 0)
								{
									std::cout << "\nВыберите из существующих!" << std::endl;
									continue;
								};
								if (сhoice == 0) break;

								std::cout << "\nНапишите сообщение:" << std::endl;
								std::cin >> xxx;
								std::getline(std::cin, xxx);
								ptr_GChat->addMessage(xxx, ptr_entrance->getIndex());
								
							}
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
							std::cout << "\nВаши друзья:" << std::endl;

							if (vectorUser[ptr_entrance->getIndex()].getSizeFriends() == 0)
							{
								std::cout << "\nУ вас пока что нету друзей(" << std::endl;
								continue;
							}
							if (vectorUser[ptr_entrance->getIndex()].getSizeFriends() > 0)
							{
								vectorUser[ptr_entrance->getIndex()].getFriends();
								continue;
							}

						case 2:

							std::cout << "\nПользователи:" << std::endl;
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

							std::cout << "\nВыберите кого добавить в друзья: " << std::endl;

							do
							{
								std::cin >> сhoice;

								if (vectorUser.size() < сhoice || сhoice < 0)
								{
									std::cout << "\nВыберите из существующих!" << std::endl;
									continue;
								};

								if (ptr_entrance->getIndex() == сhoice)
								{
									std::cout << "\nВы не можете добавить себя!" << std::endl;
									break;
								}
								
								if (false == vectorUser[ptr_entrance->getIndex()].checking_for_friends(vectorUser, сhoice))
								{
									std::cout << "\nДанный пользователь уже в друзьях" << std::endl;
									break;
								};


								if (ptr_entrance->getIndex() != сhoice)
								{
									vectorUser[ptr_entrance->getIndex()].addFriends(vectorUser[сhoice].getName(), vectorUser[сhoice].getSurname(), сhoice);
									std::cout << "\nВы добавили " << vectorUser[сhoice].getName() << " " << vectorUser[сhoice].getSurname() << " в друзья" << std::endl;
									break;
								}
								break;

							} while (true);

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
										std::cout << "\nЛогин занят попробуйте другой!" << std::endl;
										std::cin >> xxx;
										i = 0;
										continue;
									}
									i++;
								} while (i < vectorUser.size());

								vectorUser[ptr_entrance->getIndex()].setLogin(xxx);
								std::cout << "\nЛогин успешно изменен!" << std::endl;
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

					std::cout << "\nДо скорой встречи!)" << std::endl;
					permission_to_enter = false;
					break;

				default:
					std::cout << "\nВыберите что то из списка !" << std::endl;
					continue;

				}
			}
			continue;
		case 2:

			while (true)
			{
				std::cout << "\nВведите логин: " << std::endl;
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
							std::cout << "\nЛогин занят попробуйте другой" << std::endl;
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
			std::cout << "\nТеперь вы можете войти в аккаунт." << std::endl;
			continue;

		case 3:

			std::cout << "\nДо скорой встречи!" << std::endl;
			break;

		default:

			std::cout << "\nВыберите что то из списка !" << std::endl;
			continue;

		}
	}
	return 0;
}


