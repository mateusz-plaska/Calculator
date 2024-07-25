#include "Radical.h"
#include "Calculator_display.h"

#include <iostream>
#include <locale.h>
#include <sstream>
#include <iomanip>
#include <cmath>

void print_headline_9()
{
	Calculator_display sub_programme;
	sub_programme.print_headline();
	return;
}

int radical()
{
	setlocale(LC_CTYPE, "Polish");

	std::ostringstream menu_info_text;
	unsigned long long number;
	double grade_of_radical;
	char wilgness_to_continue;

	menu_info_text << std::endl << std::setw(52) << "SprawdŸ pierwiastek dowolnego stopnia z liczby" << std::endl << std::endl
								<< std::setw(65) << "Podaj¹c liczbê nieca³kowit¹ czêœæ u³amkowa zostanie uciêta!" << std::endl
								<< std::setw(56) << "Nie podawaj ujemnych liczb!!! Wynik bêdzie b³êdny!" << std::endl;

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

		std::cout << std::endl << std::setw(28) << "Stopieñ pierwiastka : ";
		std::cin >> grade_of_radical;
		
		if (!std::cin.good())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << std::endl << std::setw(72) << "Error! [Podana liczba nie jest poprawna! Podaj liczbê jeszcze raz.]" << std::endl;
			continue;
		}

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		
		if (grade_of_radical < 0.0)
		{
			std::cout << std::endl << std::setw(80) << "Error! [Stopieñ pierwiastka nie mo¿e byæ ujemny! Podaj liczbê jeszcze raz.]" << std::endl;
			continue;
		}

		std::cout << std::endl << std::setw(9) << "|  " << "Pierwiastek " << grade_of_radical << " stopnia z liczby " << number
											   << "  :  " << std::pow(number, 1 / grade_of_radical) << std::endl;

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
			print_headline_9();
			std::cout << std::endl << std::setw(19) << "4.3) Pierwiastek" << std::endl;
			std::cout << menu_info_text.str();
		}
	}

	return 0;
}