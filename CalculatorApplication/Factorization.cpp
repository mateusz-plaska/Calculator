#include "Factorization.h"
#include "Calculator_display.h"

#include <iostream>
#include <locale.h>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <vector>

void print_headline_5()
{
	Calculator_display sub_programme;
	sub_programme.print_headline();
	return;
}

void factorize(const unsigned long long& official_number)
{
	unsigned long long potential_prime_factor{ 2 }, number{ official_number };

	std::vector<unsigned long long> prime_factors;
	std::vector<unsigned long long>::iterator it;

	while (number > 1 && potential_prime_factor <= sqrt(official_number))
	{
		while (number % potential_prime_factor == 0)
		{
			prime_factors.push_back(potential_prime_factor);
			number /= potential_prime_factor;
		}
		++potential_prime_factor;
	}

	if (number > 1)
	{
		prime_factors.push_back(potential_prime_factor);
	}

	std::cout << std::endl << std::setw(35) << "Czynnikami pierwszymi liczby " << official_number << " s¹ :  ";

	for (it = prime_factors.begin(); it != prime_factors.end(); ++it)
	{
		std::cout << *it << ", ";
	}

	std::cout << std::endl;

	return;
}


int find_prime_factors()
{
	setlocale(LC_CTYPE, "Polish");
	
	std::ostringstream menu_info;
	unsigned long long number;
	char wilgness_to_continue;

	menu_info << std::endl << std::setw(38) << "SprawdŸ czynniki pierwsze liczby" << std::endl << std::endl
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

		factorize(number);

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
			print_headline_5();
			std::cout << std::endl << std::setw(58) << "3.3) Rozk³ad liczby na czynniki pierwsze (faktoryzacja)" << std::endl;
			std::cout << menu_info.str();
		}
	}

	return 0;
}