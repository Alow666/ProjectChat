#include <iostream>
#include <vector>

#include "User.h"
#include "Entrance.h"

int main()
{
	setlocale(LC_ALL, "Rus");
	int �hoice, choice2;
	bool permission_to_enter = false;
	std:: vector <User> vectorUser; //������ � ��������������
	std::unique_ptr<Entrance> ptr_entrance = std::make_unique <Entrance>();// ���� � ������


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

			if (permission_to_enter == false)//
			{
				continue;
			}

			permission_to_enter = ptr_entrance->entrancePassword(vectorUser);//

			while (permission_to_enter) // ���������� ������� 
			{
				std::cout << "����� ���������� " << vectorUser[ptr_entrance->getIndex()].getName()<< " " << vectorUser[ptr_entrance->getIndex()].getSurname() << std::endl;
				std::cout << "1) ���" << std::endl;
				std::cout << "2) ������" << std::endl;
				std::cout << "3) ���� ��������" << std::endl;
				std::cout << "0) ����� �� ��������" << std::endl;

				std::cin >> choice2;

				switch (choice2)
				{
				case 1:
					std::cout << "1) ���" << std::endl;
					continue;
				case 2:

					continue;
				case 3:

					continue;
				case 0:
					std::cout << "�� ������ �������!)" << std::endl;
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
			break;
		default:
			std::cout << "�������� ��� �� �� ������ !" << std::endl;
			continue;
		}
	}

}


