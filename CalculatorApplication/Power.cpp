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

	menu_info_text << std::endl << std::setw(35) << "SprawdŸ dowoln¹ potêgê liczby" << std::endl << std::endl
								<< std::setw(69) << "Podaj¹c liczbê nieca³kowit¹ stosuj zapis dziesiêtny (z kropk¹)!" << std::endl
								<< std::setw(55) << "Zarówno podstawa jak i wyk³adnik mo¿e byæ ujemny." << std::endl
								<< std::setw(50) << "Niektóre wyniki z danymi ujemnymi s¹ b³êdne!" << std::endl;

	std::cout << menu_info_text.str();

	while (1)
	{
		std::cout << std::endl << std::setw(15) << "Liczba : ";
		std::cin >> number;

		if (!std::cin.good())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << std::endl << std::setw(72) << "Error! [Podana liczba nie jest poprawna! Podaj liczbê jeszcze raz.]" << std::endl;
			continue;
		}

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << std::endl << std::setw(15) << "Potêga : ";
		std::cin >> grade_of_power;

		if (!std::cin.good())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << std::endl << std::setw(72) << "Error! [Podana liczba nie jest poprawna! Podaj liczbê jeszcze raz.]" << std::endl;
			continue;
		}

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << std::endl << std::setw(9) << "|  " << number << " ^ " << grade_of_power << "  =  "
							   << std::pow(number, grade_of_power) << std::endl;

		while (1)
		{
			std::cout << std::endl << std::setw(69) << "WprowadŸ: 0 (czyszczenie ekranu), 1 (kontynuuj), 2 (wyjœcie)  : ";
			std::cin >> wilgness_to_continue;

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			if (wilgness_to_continue != '0' && wilgness_to_continue != '1' && wilgness_to_continue != '2')
			{
				std::cout << std::endl << std::setw(59) << "Z³e dane! Nie ma takiej opcji. Podaj dane jeszcze raz." << std::endl;
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
			std::cout << std::endl << std::setw(14) << "4.4) Potêga" << std::endl;
			std::cout << menu_info_text.str();
		}
	}

	return 0;
}