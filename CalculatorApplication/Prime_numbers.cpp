#include "Prime_numbers.h"
#include "Calculator_display.h"

#include <iostream>
#include <locale.h>
#include <sstream>
#include <iomanip>
#include <cmath>

void print_headline_3()
{
	Calculator_display sub_programme;
	sub_programme.print_headline();
	return;
}

void check_if_prime(unsigned long long& number)
{
	std::string number_as_text{ std::to_string(number) };

	unsigned int width{ number_as_text.length() + 5 };


	if (number == 0 || number == 1)
	{
		std::cout << std::endl << std::setw(width) << number << " nie jest ani liczb� pierwsz�, ani z�o�on�" << std::endl;
		return;
	}

	bool if_prime{ true };

	for (unsigned long long i = 2; i <= sqrt(number); ++i)
	{
		if (number % i == 0)
		{
			if_prime = false;
			break;
		}
	}

	if (if_prime)
		std::cout << std::endl << std::setw(width) << number << " jest liczb� pierwsz�" << std::endl;
	else
		std::cout << std::endl << std::setw(width) << number << " jest liczb� z�o�on�" << std::endl;

	return;
}

int check_if_prime()
{
	setlocale(LC_CTYPE, "Polish");

	std::ostringstream menu_info;
	unsigned long long number;
	char wilgness_to_continue;

	menu_info << std::endl << std::setw(50) << "Sprawd� czy liczba jest pierwsza czy z�o�ona" << std::endl << std::endl
						   << std::setw(65) << "Podaj�c liczb� nieca�kowit� cz�� u�amkowa zostanie uci�ta!" << std::endl
						   << std::setw(56) << "Nie podawaj ujemnych liczb!!! Wynik b�dzie b��dny!" << std::endl;

	std::cout << menu_info.str();

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

		check_if_prime(number);

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
			print_headline_3();
			std::cout << std::endl << std::setw(23) << "3.1) Pierwszo�� liczby" << std::endl;
			std::cout << menu_info.str();
		}
	}

	return 0;
}