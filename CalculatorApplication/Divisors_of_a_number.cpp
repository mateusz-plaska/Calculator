#include "Divisors_of_a_number.h"
#include "Calculator_display.h"

#include <iostream>
#include <locale.h>
#include <sstream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>

void print_headline_4()
{
	Calculator_display sub_programme;
	sub_programme.print_headline();
	return;
}

void find_divisors(unsigned long long& number)
{
	std::vector<unsigned long long> divisors;
	std::vector<unsigned long long>::iterator it;

	divisors.push_back(1);
	divisors.push_back(number);

	for (unsigned long long i = 2; i <= sqrt(number); ++i)
	{
		if (number % i == 0)
		{
			divisors.push_back(i);
			divisors.push_back(number / i);
		}
	}
	
	std::sort(divisors.begin(), divisors.end());

	std::cout << std::endl << std::setw(23) << "Dzielniki liczby " << number << " :  ";

	for (it = divisors.begin(); it != divisors.end(); ++it)
	{
		std::cout << *it << ", ";
	}

	std::cout<<std::endl;

	return;
}

int find_divisors()
{
	setlocale(LC_CTYPE, "Polish");

	std::ostringstream menu_info;
	unsigned long long number;
	char wilgness_to_continue;

	menu_info << std::endl << std::setw(30) << "SprawdŸ dzielniki liczby" << std::endl << std::endl
						   << std::setw(65) << "Podaj¹c liczbê nieca³kowit¹ czêœæ u³amkowa zostanie uciêta!" << std::endl
						   << std::setw(56) << "Nie podawaj ujemnych liczb!!! Wynik bêdzie b³êdny!" << std::endl;

	std::cout << menu_info.str();

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

		find_divisors(number);

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
			print_headline_4();
			std::cout << std::endl << std::setw(22) << "3.2) Dzielniki liczby" << std::endl;
			std::cout << menu_info.str();
		}
	}

	return 0;
}

