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
	int �hoice;
	bool permission_to_enter = false;
	std::string xxx;
	std:: vector <User> vectorUser; //������ � ��������������
	std::unique_ptr<Entrance> ptr_entrance = std::make_unique <Entrance>();// ���� � ������
	std::unique_ptr<GeneralChat> ptr_GChat = std::make_unique <GeneralChat>();//����� ���
	std::cout << "����� ���������� � ���!" << std::endl;

	while (true)
	{
		std::cout << "1)����� � ������� \n2)���������������� ������� \n3)�����" << std::endl;
		std::cin >> �hoice;

		switch (�hoice)
	{
		case 1:
			if (vectorUser.size() == 0)//�������� ������� �������������
			{
				std::cout << "� ���� ��� ������ ����(" << std::endl;
				continue;
			}

			permission_to_enter = ptr_entrance->entranceLogin(vectorUser);//�������� ������

			if (permission_to_enter == false)
			{
				continue;
			}

			permission_to_enter = ptr_entrance->entrancePassword(vectorUser);//�������� ������

			if (permission_to_enter == true) std::cout << "����� ���������� " << vectorUser[ptr_entrance->getIndex()].getName()<< std::endl; 

			

			while (permission_to_enter) // ���������� ������� 
			{
				std::cout << "\n1) ���" << std::endl;
				std::cout << "2) ������" << std::endl;
				std::cout << "3) ��������� ��������" << std::endl;
				std::cout << "0) ����� �� ��������" << std::endl;

				std::cin >> �hoice;

				switch (�hoice)
				{
				case 1:

					while (true) 
					{
						std::cout << "\n1) �������� ���������  " << std::endl;
						std::cout << "2) �������� ���������" << std::endl;
						std::cout << "3) ����� ���" << std::endl;
						std::cout << "0) ��������� �����" << std::endl;

						std::cin >> �hoice;

						switch (�hoice)
						{
						case 1:

							if (vectorUser[ptr_entrance->getIndex()].getSizeChat() == 0)
							{
								std::cout << "\n��������� ���!" << std::endl;
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
								std::cout << "\n���������� �������� ������!" << std::endl;
								continue;
							}

							vectorUser[ptr_entrance->getIndex()].getFriendsMesssage();

							std::cout << "\n���� �� ������ �������� ?: " << std::endl;
							
							do
							{
								std::cin >> �hoice;

								if (vectorUser[ptr_entrance->getIndex()].getSizeFriends() < �hoice || �hoice < 0)
								{
									std::cout << "\n�������� �� ������������!" << std::endl;
									continue;
								}
								
								std::cout << "\n�������� ���������:" << std::endl;
								std::cin >> xxx;

								vectorUser[ptr_entrance->getIndex()].sendMessage(vectorUser, ptr_entrance->getIndex(), vectorUser[ptr_entrance->getIndex()].getIndexFriens(�hoice), xxx);
					

								std::cout << "\n��������� ����������!" << std::endl;
								
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
								std::cout << "\n1) �������� ��������� \n0) �����" << std::endl;

								std::cin >> �hoice;

								if (1 < �hoice || �hoice < 0)
								{
									std::cout << "\n�������� �� ������������!" << std::endl;
									continue;
								};
								if (�hoice == 0) break;

								std::cout << "\n�������� ���������:" << std::endl;
								std::cin >> xxx;
								std::getline(std::cin, xxx);
								ptr_GChat->addMessage(xxx, ptr_entrance->getIndex());
								
							}
							continue;
						case 0:
							break;
						default:
							std::cout << "\n�������� ��� �� �� ������ !" << std::endl;
							continue;
						}
						break;
					}
					continue;

				case 2:

					while (true)
					{
						std::cout << "\n1) ��� ������" << std::endl;
						std::cout << "2) ������������ ���� (�������� � ������)" << std::endl;
						std::cout << "0) ��������� �����" << std::endl;

						std::cin >> �hoice;

						switch (�hoice)
						{
						case 1://+++++
							std::cout << "\n���� ������:" << std::endl;

							if (vectorUser[ptr_entrance->getIndex()].getSizeFriends() == 0)
							{
								std::cout << "\n� ��� ���� ��� ���� ������(" << std::endl;
								continue;
							}
							if (vectorUser[ptr_entrance->getIndex()].getSizeFriends() > 0)
							{
								vectorUser[ptr_entrance->getIndex()].getFriends();
								continue;
							}

						case 2:

							std::cout << "\n������������:" << std::endl;
							�hoice = 0;

							for (; �hoice < vectorUser.size(); �hoice++)
							{
							
								if (ptr_entrance->getIndex() == �hoice)
								{
									std::cout << �hoice << ") " << vectorUser[�hoice].getName() << " " << vectorUser[�hoice].getSurname() << " <- ��� ��" << std::endl;
								};
								
								if (false == vectorUser[ptr_entrance->getIndex()].checking_for_friends(vectorUser, �hoice))
								{
									continue;
								};

								if (ptr_entrance->getIndex() != �hoice)
								{
									std::cout << �hoice << ") " << vectorUser[�hoice].getName() << " " << vectorUser[�hoice].getSurname() << std::endl;
								};

							}

							std::cout << "\n�������� ���� �������� � ������: " << std::endl;

							do
							{
								std::cin >> �hoice;

								if (vectorUser.size() < �hoice || �hoice < 0)
								{
									std::cout << "\n�������� �� ������������!" << std::endl;
									continue;
								};

								if (ptr_entrance->getIndex() == �hoice)
								{
									std::cout << "\n�� �� ������ �������� ����!" << std::endl;
									break;
								}
								
								if (false == vectorUser[ptr_entrance->getIndex()].checking_for_friends(vectorUser, �hoice))
								{
									std::cout << "\n������ ������������ ��� � �������" << std::endl;
									break;
								};


								if (ptr_entrance->getIndex() != �hoice)
								{
									vectorUser[ptr_entrance->getIndex()].addFriends(vectorUser[�hoice].getName(), vectorUser[�hoice].getSurname(), �hoice);
									std::cout << "\n�� �������� " << vectorUser[�hoice].getName() << " " << vectorUser[�hoice].getSurname() << " � ������" << std::endl;
									break;
								}
								break;

							} while (true);

							continue;

						case 0:

							break;

						default:

							std::cout << "\n�������� ��� �� �� ������ !" << std::endl;
							continue;
						}
						break;
					}
					continue;

				case 3: // ��������� ��������

					while (true)
					{
						std::cout << "\n1) �������� �����" << std::endl;
						std::cout << "2) �������� ������" << std::endl;
						std::cout << "3) �������� ���" << std::endl;
						std::cout << "4) �������� �������" << std::endl;
						std::cout << "0) ��������� �����" << std::endl;
						std::cin >> �hoice;

						switch (�hoice)
						{
						case 1:


							while (true)
							{
								std::cout << "\n������� ����� �����: " << std::endl;
								std::cin >> xxx;
								int i = 0;
								do
								{
									if (xxx == vectorUser[i].getLogin())
									{
										std::cout << "\n����� ����� ���������� ������!" << std::endl;
										std::cin >> xxx;
										i = 0;
										continue;
									}
									i++;
								} while (i < vectorUser.size());

								vectorUser[ptr_entrance->getIndex()].setLogin(xxx);
								std::cout << "\n����� ������� �������!" << std::endl;
								break;
							}
							continue;

						case 2:

							std::cout << "\n������� ����� ������: " << std::endl;
							std::cin >> xxx;
							vectorUser[ptr_entrance->getIndex()].setPassword(xxx);
							std::cout << "\n������ ������� �������!" << std::endl;
							continue;

						case 3:

							std::cout << "\n������� ����� ���: " << std::endl;
							std::cin >> xxx;
							vectorUser[ptr_entrance->getIndex()].setName(xxx);
							std::cout << "\n��� ������� ��������!" << std::endl;
							continue;

						case 4:

							std::cout << "\n������� ����� �������: " << std::endl;
							std::cin >> xxx;
							vectorUser[ptr_entrance->getIndex()].setSurname(xxx);
							std::cout << "\n������� ������� ��������!" << std::endl;
							continue;

						case 0:

							break;

						default:
							std::cout << "\n�������� ��� �� �� ������ !" << std::endl;
							continue;
						}
						break;
					}
					continue;

				case 0:

					std::cout << "\n�� ������ �������!)" << std::endl;
					permission_to_enter = false;
					break;

				default:
					std::cout << "\n�������� ��� �� �� ������ !" << std::endl;
					continue;

				}
			}
			continue;
		case 2:

			while (true)
			{
				std::cout << "\n������� �����: " << std::endl;
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
							std::cout << "\n����� ����� ���������� ������" << std::endl;
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
			std::cout << "\n������ �� ������ ����� � �������." << std::endl;
			continue;

		case 3:

			std::cout << "\n�� ������ �������!" << std::endl;
			break;

		default:

			std::cout << "\n�������� ��� �� �� ������ !" << std::endl;
			continue;

		}
	}
	return 0;
}


