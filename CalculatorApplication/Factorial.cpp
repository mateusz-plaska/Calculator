#include "Factorial.h"
#include "Calculator_display.h"

#include <iostream>
#include <locale.h>
#include <sstream>
#include <iomanip>

void print_headline_8()
{
	Calculator_display sub_programme;
	sub_programme.print_headline();
	return;
}

long double find_factorial(int number)
{
	if (number == 0)
		return 1;
	else
		return number * find_factorial(number - 1);
}

long double find_double_factorial(int number)
{
	if (number == 0 || number == 1)
		return 1;
	else
		return number * find_double_factorial(number - 2);
}

int factorial()
{
	setlocale(LC_CTYPE, "Polish");

	std::ostringstream menu_info_text;
	char wilgness_to_continue;
	int number;

	menu_info_text << std::endl << std::setw(48) << "SprawdŸ silniê liczby oraz silniê podwójn¹" << std::endl << std::endl
								<< std::setw(61) << "Silnia podwójna : 4!! = 4 * 2 = 8, 5!! = 5 * 3 * 1 = 15" << std::endl << std::endl
								<< std::setw(65) << "Podaj¹c liczbê nieca³kowit¹ czêœæ u³amkowa zostanie uciêta!" << std::endl
								<< std::setw(33) << "Nie podawaj ujemnych liczb!" << std::endl;

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

		if (number < 0)
		{
			std::cout << std::endl << std::setw(66) << "Error! [Podana liczba jest ujemna! Podaj liczbê jeszcze raz.]" << std::endl;
			continue;
		}

		std::cout << std::endl << std::setw(9) << "|  " << number << "!  =  " << find_factorial(number) << std::endl << std::endl;
		std::cout << std::endl << std::setw(9) << "|  " << number << "!!  =  " << find_double_factorial(number) << std::endl << std::endl;

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
			print_headline_8();
			std::cout << std::endl << std::setw(16) << "4.1) NWD, NWW" << std::endl;
			std::cout << menu_info_text.str();
		}
	}

	return 0;
}