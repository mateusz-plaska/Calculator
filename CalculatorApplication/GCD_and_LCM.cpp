#include "GCD_and_LCM.h"
#include "Calculator_display.h"

#include <iostream>
#include <locale.h>
#include <sstream>
#include <iomanip>

void print_headline_7()
{
	Calculator_display sub_programme;
	sub_programme.print_headline();
	return;
}

unsigned long long calculate_Greatest_Common_Divisor(unsigned long long numb_1, unsigned long long numb_2)
{
	unsigned long long modulo;

	while (numb_2)
	{
		modulo = numb_1 % numb_2;
		numb_1 = numb_2;
		numb_2 = modulo;
	}
	return numb_1;
}

unsigned long long calculate_Least_Common_Multiple(unsigned long long numb_1, unsigned long long numb_2, unsigned long long GCD)
{
	return (numb_1 * numb_2) / GCD;
}

int gcd_and_lcm()
{
	setlocale(LC_CTYPE, "Polish");

	std::ostringstream menu_info_text;
	char wilgness_to_continue;
	unsigned long long number_1,number_2;

	menu_info_text << std::endl << std::setw(49) << "SprawdŸ NWD (Najwiêkszy Wspólny Dzielnik) i" << std::endl
								<< std::setw(57) << "NWW (Najmniejsza Wspólna Wielokrotnoœæ) dwóch liczb" << std::endl << std::endl
								<< std::setw(65) << "Podaj¹c liczbê nieca³kowit¹ czêœæ u³amkowa zostanie uciêta!" << std::endl
								<< std::setw(56) << "Nie podawaj ujemnych liczb!!! Wynik bêdzie b³êdny!" << std::endl;
	
	std::cout << menu_info_text.str();

	while (1)
	{
		std::cout << std::endl << std::setw(17) << "Liczba 1 : ";
		std::cin >> number_1;

		if (!std::cin.good())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << std::endl << std::setw(72) << "Error! [Podana liczba nie jest poprawna! Podaj liczbê jeszcze raz.]" << std::endl;
			continue;
		}

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


		std::cout << std::endl << std::setw(17) << "Liczba 2 : ";
		std::cin >> number_2;

		if (!std::cin.good())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << std::endl << std::setw(72) << "Error! [Podana liczba nie jest poprawna! Podaj liczbê jeszcze raz.]" << std::endl;
			continue;
		}

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		unsigned long long gcd = calculate_Greatest_Common_Divisor(number_1, number_2);

		std::cout << std::endl << std::setw(46) << "Najwiêkszy Wspólny Dzielnik (NWD) liczb " << number_1 << " i " << number_2 << " to :  " << gcd << std::endl;
		std::cout << std::setw(52) << "Najmniejsza Wspólna Wielokrotnoœæ (NWW) liczb " << number_1 << " i " << number_2 << " to :  "
				  << calculate_Least_Common_Multiple(number_1, number_2, gcd) << std::endl;

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
			print_headline_7();
			std::cout << std::endl << std::setw(16) << "4.1) NWD, NWW" << std::endl;
			std::cout << menu_info_text.str();
		}
	}

	return 0;
}