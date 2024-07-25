#include "Power.h"
#include "Calculator_display.h"

#include <iostream>
#include <locale.h>
#include <sstream>
#include <iomanip>
#include <cmath>

void print_headline_10()
{
	Calculator_display sub_programme;
	sub_programme.print_headline();
	return;
}

int power()
{
	setlocale(LC_CTYPE, "Polish");

	std::ostringstream menu_info_text;
	long double number;
	double grade_of_power;
	char wilgness_to_continue;

	menu_info_text << std::endl << std::setw(35) << "Sprawd� dowoln� pot�g� liczby" << std::endl << std::endl
								<< std::setw(69) << "Podaj�c liczb� nieca�kowit� stosuj zapis dziesi�tny (z kropk�)!" << std::endl
								<< std::setw(55) << "Zar�wno podstawa jak i wyk�adnik mo�e by� ujemny." << std::endl
								<< std::setw(50) << "Niekt�re wyniki z danymi ujemnymi s� b��dne!" << std::endl;

	std::cout << menu_info_text.str();

	while (1)
	{
		std::cout << std::endl << std::setw(15) << "Liczba : ";
		std::cin >> number;

		if (!std::cin.good())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << std::endl << std::setw(72) << "Error! [Podana liczba nie jest poprawna! Podaj liczb� jeszcze raz.]" << std::endl;
			continue;
		}

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << std::endl << std::setw(15) << "Pot�ga : ";
		std::cin >> grade_of_power;

		if (!std::cin.good())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << std::endl << std::setw(72) << "Error! [Podana liczba nie jest poprawna! Podaj liczb� jeszcze raz.]" << std::endl;
			continue;
		}

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << std::endl << std::setw(9) << "|  " << number << " ^ " << grade_of_power << "  =  "
							   << std::pow(number, grade_of_power) << std::endl;

		while (1)
		{
			std::cout << std::endl << std::setw(69) << "Wprowad�: 0 (czyszczenie ekranu), 1 (kontynuuj), 2 (wyj�cie)  : ";
			std::cin >> wilgness_to_continue;

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			if (wilgness_to_continue != '0' && wilgness_to_continue != '1' && wilgness_to_continue != '2')
			{
				std::cout << std::endl << std::setw(59) << "Z�e dane! Nie ma takiej opcji. Podaj dane jeszcze raz." << std::endl;
				continue;
			}
			break;
		}

		if (wilgness_to_continue == '2')
			break;
		if (wilgness_to_continue == '0')
		{
			system("cls");
			print_headline_10();
			std::cout << std::endl << std::setw(14) << "4.4) Pot�ga" << std::endl;
			std::cout << menu_info_text.str();
		}
	}

	return 0;
}