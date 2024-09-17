#include <iostream>
#include <vector>

#include "User.h"
#include "Entrance.h"


int main()
{
	setlocale(LC_ALL, "Rus");
	int �hoice, choice2, choice4, choice5;
	int entranceIndex;
	bool permission_to_enter = false;
	bool friend1 = false;
	bool exit = true;
	std:: vector <User> vectorUser; //������ � ��������������
	std::unique_ptr<Entrance> ptr_entrance = std::make_unique <Entrance>();// ���� � ������


	std::cout << "����� ���������� � ���!" << std::endl;

	while (exit)
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

			entranceIndex = ptr_entrance->getIndex();//����������������������������������������������������������������������

			while (permission_to_enter) // ���������� ������� 
			{
				std::cout << "\n1) ���" << std::endl;
				std::cout << "2) �����" << std::endl;
				std::cout << "3) ��������� ��������" << std::endl;
				std::cout << "0) ����� �� ��������" << std::endl;

				std::cin >> choice2;

				switch (choice2)
				{
				case 1:

					/*std::cout << "1) ��� ������" << std::endl;
					std::cout << "2) ����� �����" << std::endl;
					std::cout << "0) ��������� �����" << std::endl;

					std::cin >> choice3;

					switch (choice3)
					{
					case 1:

					case 2:

					case 0:
						break;
					default:
						std::cout << "�������� ��� �� �� ������ !" << std::endl;
						continue;
					}*/
					
					continue;

				case 2:

					std::cout << "\n1) ��� ������" << std::endl;
					std::cout << "2) ������������ ���� (�������� � ������)" << std::endl;
					std::cout << "0) ��������� �����" << std::endl;

					std::cin >> choice4;

					switch (choice4) 
					{
					case 1:
						std::cout << "���� ������:" << std::endl;

						if(vectorUser[ptr_entrance->getIndex()].getSizeFriends() == 0) //����� �� ���������� ������� �����
						{
							std::cout << "� ��� ���� ��� ���� ������(" << std::endl;
							continue;
						}
						if (vectorUser[ptr_entrance->getIndex()].getSizeFriends() > 0)
						{
							vectorUser[ptr_entrance->getIndex()].getFriends(vectorUser);
							continue;
						}
			
					case 2:

						std::cout << "������������:" << std::endl;
						choice5 = 0;

						for (; choice5 < vectorUser.size(); choice5++)
						{

							if (ptr_entrance->getIndex() == choice5)
							{
								std::cout << choice5 << ") " << vectorUser[choice5].getName() << " " << vectorUser[choice5].getSurname() << " <- ��� ��" << std::endl;
							};

							if (ptr_entrance->getIndex() != choice5)
							{
								std::cout << choice5 << ") " << vectorUser[choice5].getName() << " " << vectorUser[choice5].getSurname() << std::endl;
							};
							
						}

						std::cout << "�������� ���� �������� � ������" << std::endl;

						do
						{
							std::cin >> choice5; // ����� Try � ������ ���� (������������ �������) ##############################################################################

							if (vectorUser.size() < choice5)
							{
								std::cout << "�������� �� ������������!" << std::endl;
								continue;
							};

							if (ptr_entrance->getIndex() == choice5)
							{
								std::cout << "�� �� ������ �������� ����!" << std::endl;
								break;
							}

							if (ptr_entrance->getIndex() != choice5 )
							{
								vectorUser[ptr_entrance->getIndex()].addFriends(choice5);
								std::cout << "�� ��������" << vectorUser[choice5].getName() << " " << vectorUser[choice5].getSurname()<< " � ������" <<std::endl;
								break;
							}
							break;
						} while (true);
						break;
					case 0:
						break;
					default:
						std::cout << "�������� ��� �� �� ������ !" << std::endl;
						continue;
					}
					continue;
				case 3:


					continue;
				case 0:
					std::cout << "�� ������ �������!)" << std::endl;
					permission_to_enter = false;
					break;
				default:
					std::cout << "�������� ��� �� �� ������ !" << std::endl;
					continue;
				}
			}
			continue;
		case 2:
			vectorUser.push_back(User());
			std::cout << "������ �� ������ ����� � �������." << std::endl;
			continue;
		case 3:
			std::cout << "�� ������ �������!" << std::endl;
			exit = false;
			break;
		default:
			std::cout << "�������� ��� �� �� ������ !" << std::endl;
			continue;
		}
	}
	return 0;
}


