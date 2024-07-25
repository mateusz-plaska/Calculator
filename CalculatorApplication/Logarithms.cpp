#include "Logarithms.h"
#include "Calculator_display.h"
#include "Tinvalid_char.h"
#include "Tcontact_with_the_user.h"

#include <iostream>
#include <locale.h>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <string>

void print_headline_11()
{
	Calculator_display sub_programme;
	sub_programme.print_headline();
	return;
}

long double log_own_based(long double number, long double based)
{
	return log(number) / log(based);
}

int logarithms()
{
	setlocale(LC_CTYPE, "Polish");

	std::ostringstream menu_info_text;
	char wilgness_to_continue;
	std::string help_text;
	int option;
	long double number, based_of_logarithm;

	menu_info_text << std::endl << std::setw(39) << "Sprawd� dowolny logarytm z liczby" << std::endl << std::endl
		<< std::setw(69) << "Podaj�c liczb� nieca�kowit� stosuj zapis dziesi�tny (z kropk�)!" << std::endl
		<< std::setw(66) << "Nie podawaj ujemnych liczb ani zera! Podstwa nie mo�e by� 1!" << std::endl << std::endl
		<< std::setw(11) << "Opcje:" << std::endl
		<< std::setw(26) << "1) Logarytm naturalny" << std::endl
		<< std::setw(27) << "2) Logarytm dziesi�tny" << std::endl
		<< std::setw(37) << "3) Logarytm o dowolnej podstawie" << std::endl;

	std::cout << menu_info_text.str();

	while (1)
	{
		std::cout << std::endl << std::setw(29) << "Wybierz 1, 2 lub 3  :  ";

		Tcontact_with_the_user input_text_option;

		try
		{
			std::getline(std::cin, help_text);
			input_text_option.copy(help_text);
			input_text_option.check_if_no_error();
		}
		catch (Tinvalid_char& ex)
		{
			std::cout << ex.what() << std::endl;
			std::cout << std::setw(35) << "Wprowad� numer jeszcze raz." << std::endl;
			continue;
		}

		option = std::stoi(input_text_option.str());

		if (option != 1 && option != 2 && option != 3)
		{
			std::cout << std::setw(56) << "Nieprawid�owy numer. Wprowad� numer jeszcze raz." << std::endl;
			continue;
		}

		switch (option)
		{
		case 1:
		{
			while (1)
			{
				std::cout << std::endl << std::setw(67) << "Podaj liczb� z jakiej chcesz obliczy� logarytm naturalny  :  ";
				std::cin >> number;

				if (!std::cin.good())
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << std::endl << std::setw(72) << "Error! [Podana liczba nie jest poprawna! Podaj liczb� jeszcze raz.]" << std::endl;
					continue;
				}

				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				if (number < 0)
				{
					std::cout << std::endl << std::setw(66) << "Error! [Podana liczba jest ujemna! Podaj liczb� jeszcze raz.]" << std::endl;
					continue;
				}
				if (number == 0)
				{
					std::cout << std::endl << std::setw(65) << "Error! [Podana liczba jest zerem! Podaj liczb� jeszcze raz.]" << std::endl;
					continue;
				}

				break;
			}

			std::cout << std::endl << std::setw(27) << "Logarytm naturalny z " << number << " to  :  " << log(number) << std::endl;
		}
		break;
	
		case 2:
		{
			while (1)
			{
				std::cout << std::endl << std::setw(68) << "Podaj liczb� z jakiej chcesz obliczy� logarytm dziesi�tny  :  ";
				std::cin >> number;

				if (!std::cin.good())
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << std::endl << std::setw(72) << "Error! [Podana liczba nie jest poprawna! Podaj liczb� jeszcze raz.]" << std::endl;
					continue;
				}

				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				if (number < 0)
				{
					std::cout << std::endl << std::setw(66) << "Error! [Podana liczba jest ujemna! Podaj liczb� jeszcze raz.]" << std::endl;
					continue;
				}
				if (number == 0)
				{
					std::cout << std::endl << std::setw(65) << "Error! [Podana liczba jest zerem! Podaj liczb� jeszcze raz.]" << std::endl;
					continue;
				}

				break;
			}

			std::cout << std::endl << std::setw(28) << "Logarytm dziesi�tny z " << number << " to  :  " << log10l(number) << std::endl;
		}
		break;
		
		case 3:
		{
			while (1)
			{
				std::cout << std::endl << std::setw(35) << "Podaj podstaw� logarytmu  :  ";
				std::cin >> based_of_logarithm;

				if (!std::cin.good())
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << std::endl << std::setw(72) << "Error! [Podana liczba nie jest poprawna! Podaj liczb� jeszcze raz.]" << std::endl;
					continue;
				}

				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				if (based_of_logarithm < 0)
				{
					std::cout << std::endl << std::setw(66) << "Error! [Podana liczba jest ujemna! Podaj liczb� jeszcze raz.]" << std::endl;
					continue;
				}
				if (based_of_logarithm == 0)
				{
					std::cout << std::endl << std::setw(65) << "Error! [Podana liczba jest zerem! Podaj liczb� jeszcze raz.]" << std::endl;
					continue;
				}
				if (based_of_logarithm == 1)
				{
					std::cout << std::endl << std::setw(80) << "Error! [Podstawa logarytmu nie mo�e by� r�wna 1! Podaj liczb� jeszcze raz.]" << std::endl;
					continue;
				}


				std::cout << std::endl << std::setw(57) << "Podaj liczb� z jakiej chcesz obliczy� logarytm  :  ";
				std::cin >> number;

				if (!std::cin.good())
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << std::endl << std::setw(72) << "Error! [Podana liczba nie jest poprawna! Podaj liczb� jeszcze raz.]" << std::endl;
					continue;
				}

				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				if (number < 0)
				{
					std::cout << std::endl << std::setw(66) << "Error! [Podana liczba jest ujemna! Podaj liczb� jeszcze raz.]" << std::endl;
					continue;
				}
				if (number == 0)
				{
					std::cout << std::endl << std::setw(65) << "Error! [Podana liczba jest zerem! Podaj liczb� jeszcze raz.]" << std::endl;
					continue;
				}

				break;
			}

			std::cout << std::endl << std::setw(27) << "Logarytm o podstawie " << based_of_logarithm << " z " << number << " to  :  "
					  << log_own_based(number, based_of_logarithm) << std::endl;
		}
		break;
		}
	
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
			print_headline_11();
			std::cout << std::endl << std::setw(16) << "4.5) Logarytm" << std::endl;
			std::cout << menu_info_text.str();
		}
	}

	return 0;
}