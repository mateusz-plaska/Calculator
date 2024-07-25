#include "Fractions.h"
#include "Calculator_display.h"
#include "Tcontact_with_the_user.h"
#include "Tinvalid_char.h"

#include <iostream>
#include <locale.h>
#include <sstream>
#include <iomanip>
#include <string>

void print_headline_12()
{
	Calculator_display sub_programme;
	sub_programme.print_headline();
	return;
}

long long find_Greatest_Common_Divisor(long long numb_1, long long numb_2)
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

long long find_Least_Common_Multiple(long long numb_1, long long numb_2)
{
	return (numb_1 * numb_2) / find_Greatest_Common_Divisor(numb_1, numb_2);
}

void addition(long long integer_part_first_fraction, long long numerator_first_fraction, long long denominator_first_fraction,
			  long long integer_part_second_fraction, long long numerator_second_fraction, long long denominator_second_fraction)
{
	long long integer_part_result, numerator_result, denominator_result;
	long long lcd_denominators, calculating_integer_part, gcd_numerator_and_denominator;

	const long long orginal_numerator_first_fraction{ numerator_first_fraction };
	const long long orginal_denominator_first_fraction{ denominator_first_fraction };
	const long long orginal_numerator_second_fraction{ numerator_second_fraction };
	const long long orginal_denominator_second_fraction{ denominator_second_fraction };

	integer_part_result = integer_part_first_fraction + integer_part_second_fraction;

	lcd_denominators = find_Least_Common_Multiple(denominator_first_fraction, denominator_second_fraction);

	numerator_first_fraction *= (lcd_denominators / denominator_first_fraction);
	denominator_first_fraction *= (lcd_denominators / denominator_first_fraction);

	numerator_second_fraction *= (lcd_denominators / denominator_second_fraction);
	denominator_second_fraction *= (lcd_denominators / denominator_second_fraction);

	numerator_result = numerator_first_fraction + numerator_second_fraction;
	denominator_result = denominator_first_fraction;

	calculating_integer_part = (numerator_result / denominator_result);

	integer_part_result += calculating_integer_part;

	numerator_result -= (calculating_integer_part * denominator_result);

	gcd_numerator_and_denominator = find_Greatest_Common_Divisor(numerator_result, denominator_result);

	numerator_result /= gcd_numerator_and_denominator;
	denominator_result /= gcd_numerator_and_denominator;

	if (integer_part_result == 0)
	{
		std::cout << std::endl << std::endl << std::setw(9) << "|  " << integer_part_first_fraction << "  " << orginal_numerator_first_fraction << "/"
			<< orginal_denominator_first_fraction << "  +  " << integer_part_second_fraction << "  " << orginal_numerator_second_fraction
			<< "/" << orginal_denominator_second_fraction << "  =  " << numerator_result << "/" << denominator_result << std::endl << std::endl;
		return;
	}
	if (numerator_result == 0 || denominator_result == 0)
	{
		std::cout << std::endl << std::endl << std::setw(9) << "|  " << integer_part_first_fraction << "  " << orginal_numerator_first_fraction << "/"
			<< orginal_denominator_first_fraction << "  +  " << integer_part_second_fraction << "  " << orginal_numerator_second_fraction
			<< "/" << orginal_denominator_second_fraction << "  =  " << integer_part_result << std::endl << std::endl;
		return;
	}

	std::cout << std::endl << std::endl << std::setw(9) << "|  " << integer_part_first_fraction << "  " << orginal_numerator_first_fraction << "/"
			  << orginal_denominator_first_fraction << "  +  " << integer_part_second_fraction << "  " << orginal_numerator_second_fraction
			  << "/" << orginal_denominator_second_fraction << "  =  " << integer_part_result << "  " << numerator_result << "/"
			  << denominator_result << std::endl << std::endl;

	return;
}

void subtraction(long long integer_part_first_fraction, long long numerator_first_fraction, long long denominator_first_fraction,
				 long long integer_part_second_fraction, long long numerator_second_fraction, long long denominator_second_fraction)
{
	long long integer_part_result, numerator_result, denominator_result;
	long long lcd_denominators,gcd_numerator_and_denominator;

	const long long orginal_numerator_first_fraction{ numerator_first_fraction };
	const long long orginal_denominator_first_fraction{ denominator_first_fraction };
	const long long orginal_numerator_second_fraction{ numerator_second_fraction };
	const long long orginal_denominator_second_fraction{ denominator_second_fraction };

	integer_part_result = integer_part_first_fraction - integer_part_second_fraction;

	lcd_denominators = find_Least_Common_Multiple(denominator_first_fraction, denominator_second_fraction);

	numerator_first_fraction *= (lcd_denominators / denominator_first_fraction);
	denominator_first_fraction *= (lcd_denominators / denominator_first_fraction);

	numerator_second_fraction *= (lcd_denominators / denominator_second_fraction);
	denominator_second_fraction *= (lcd_denominators / denominator_second_fraction);

	numerator_result = numerator_first_fraction - numerator_second_fraction;
	denominator_result = denominator_first_fraction;

	numerator_result = (integer_part_result * denominator_result) + numerator_result;

	integer_part_result = (numerator_result / denominator_result);
	
	numerator_result -= (integer_part_result * denominator_result);

	gcd_numerator_and_denominator = find_Greatest_Common_Divisor(numerator_result, denominator_result);

	numerator_result /= gcd_numerator_and_denominator;
	denominator_result /= gcd_numerator_and_denominator;

	if (integer_part_result == 0)
	{
		std::cout << std::endl << std::endl << std::setw(9) << "|  " << integer_part_first_fraction << "  " << orginal_numerator_first_fraction << "/"
			<< orginal_denominator_first_fraction << "  -  " << integer_part_second_fraction << "  " << orginal_numerator_second_fraction
			<< "/" << orginal_denominator_second_fraction << "  =  " << numerator_result << "/" << denominator_result << std::endl << std::endl;
		return;
	}
	if (numerator_result == 0 || denominator_result == 0)
	{
		std::cout << std::endl << std::endl << std::setw(9) << "|  " << integer_part_first_fraction << "  " << orginal_numerator_first_fraction << "/"
			<< orginal_denominator_first_fraction << "  -  " << integer_part_second_fraction << "  " << orginal_numerator_second_fraction
			<< "/" << orginal_denominator_second_fraction << "  =  " << integer_part_result << std::endl << std::endl;
		return;
	}

	std::cout << std::endl << std::endl << std::setw(9) << "|  " << integer_part_first_fraction << "  " << orginal_numerator_first_fraction << "/"
			  << orginal_denominator_first_fraction << "  -  " << integer_part_second_fraction << "  " << orginal_numerator_second_fraction
			  << "/" << orginal_denominator_second_fraction << "  =  " << integer_part_result << "  " << numerator_result << "/"
			  << denominator_result << std::endl << std::endl;

	return;
}

void multiplication(long long integer_part_first_fraction, long long numerator_first_fraction, long long denominator_first_fraction,
					long long integer_part_second_fraction, long long numerator_second_fraction, long long denominator_second_fraction)
{
	long long integer_part_result, numerator_result, denominator_result;
	long long gcd_numerator_and_denominator;

	const long long orginal_numerator_first_fraction{ numerator_first_fraction };
	const long long orginal_denominator_first_fraction{ denominator_first_fraction };
	const long long orginal_numerator_second_fraction{ numerator_second_fraction };
	const long long orginal_denominator_second_fraction{ denominator_second_fraction };

	numerator_first_fraction += (integer_part_first_fraction * denominator_first_fraction);
	numerator_second_fraction += (integer_part_second_fraction * denominator_second_fraction);

	numerator_result = numerator_first_fraction * numerator_second_fraction;
	denominator_result = denominator_first_fraction * denominator_second_fraction;

	integer_part_result = numerator_result / denominator_result;

	numerator_result -= (integer_part_result * denominator_result);

	gcd_numerator_and_denominator = find_Greatest_Common_Divisor(numerator_result, denominator_result);

	numerator_result /= gcd_numerator_and_denominator;
	denominator_result /= gcd_numerator_and_denominator;

	if (integer_part_result == 0)
	{
		std::cout << std::endl << std::endl << std::setw(9) << "|  " << integer_part_first_fraction << "  " << orginal_numerator_first_fraction << "/"
			<< orginal_denominator_first_fraction << "  *  " << integer_part_second_fraction << "  " << orginal_numerator_second_fraction
			<< "/" << orginal_denominator_second_fraction << "  =  " << numerator_result << "/" << denominator_result << std::endl << std::endl;
		return;
	}
	if (numerator_result == 0 || denominator_result == 0)
	{
		std::cout << std::endl << std::endl << std::setw(9) << "|  " << integer_part_first_fraction << "  " << orginal_numerator_first_fraction << "/"
			<< orginal_denominator_first_fraction << "  *  " << integer_part_second_fraction << "  " << orginal_numerator_second_fraction
			<< "/" << orginal_denominator_second_fraction << "  =  " << integer_part_result << std::endl << std::endl;
		return;
	}
	
	std::cout << std::endl << std::endl << std::setw(9) << "|  " << integer_part_first_fraction << "  " << orginal_numerator_first_fraction << "/"
			  << orginal_denominator_first_fraction << "  *  " << integer_part_second_fraction << "  " << orginal_numerator_second_fraction
			  << "/" << orginal_denominator_second_fraction << "  =  " << integer_part_result << "  " << numerator_result << "/"
			  << denominator_result << std::endl << std::endl;
	return;
}

void division(long long integer_part_first_fraction, long long numerator_first_fraction, long long denominator_first_fraction,
			  long long integer_part_second_fraction, long long numerator_second_fraction, long long denominator_second_fraction)
{
	long long integer_part_result, numerator_result, denominator_result;
	long long gcd_numerator_and_denominator;

	const long long orginal_numerator_first_fraction{ numerator_first_fraction };
	const long long orginal_denominator_first_fraction{ denominator_first_fraction };
	const long long orginal_numerator_second_fraction{ numerator_second_fraction };
	const long long orginal_denominator_second_fraction{ denominator_second_fraction };

	numerator_first_fraction += (integer_part_first_fraction * denominator_first_fraction);
	numerator_second_fraction += (integer_part_second_fraction * denominator_second_fraction);

	denominator_second_fraction = numerator_second_fraction;
	numerator_second_fraction = orginal_denominator_second_fraction;

	numerator_result = numerator_first_fraction * numerator_second_fraction;
	denominator_result = denominator_first_fraction * denominator_second_fraction;

	integer_part_result = numerator_result / denominator_result;

	numerator_result -= (integer_part_result * denominator_result);

	gcd_numerator_and_denominator = find_Greatest_Common_Divisor(numerator_result, denominator_result);

	numerator_result /= gcd_numerator_and_denominator;
	denominator_result /= gcd_numerator_and_denominator;

	if (integer_part_result == 0)
	{
		std::cout << std::endl << std::endl << std::setw(9) << "|  " << integer_part_first_fraction << "  " << orginal_numerator_first_fraction << "/"
			<< orginal_denominator_first_fraction << "  ÷  " << integer_part_second_fraction << "  " << orginal_numerator_second_fraction
			<< "/" << orginal_denominator_second_fraction << "  =  " << numerator_result << "/" << denominator_result << std::endl << std::endl;
		return;
	}
	if (numerator_result == 0 || denominator_result == 0)
	{
		std::cout << std::endl << std::endl << std::setw(9) << "|  " << integer_part_first_fraction << "  " << orginal_numerator_first_fraction << "/"
			<< orginal_denominator_first_fraction << "  ÷  " << integer_part_second_fraction << "  " << orginal_numerator_second_fraction
			<< "/" << orginal_denominator_second_fraction << "  =  " << integer_part_result << std::endl << std::endl;
		return;
	}

	std::cout << std::endl << std::endl << std::setw(9) << "|  " << integer_part_first_fraction << "  " << orginal_numerator_first_fraction << "/"
		<< orginal_denominator_first_fraction << "  ÷  " << integer_part_second_fraction << "  " << orginal_numerator_second_fraction
		<< "/" << orginal_denominator_second_fraction << "  =  " << integer_part_result << "  " << numerator_result << "/"
		<< denominator_result << std::endl << std::endl;
	return;
}

int fractions()
{
	setlocale(LC_CTYPE, "Polish");

	std::ostringstream menu_info_text;
	char wilgness_to_continue;
	int option;
	long long integer_part_first_fraction, numerator_first_fraction, denominator_first_fraction;
	long long integer_part_second_fraction, numerator_second_fraction, denominator_second_fraction;

	menu_info_text << std::endl << std::setw(37) << "Podstawowe operacje na u³amkach" << std::endl << std::endl
								<< std::setw(52) << "Dozwolone jedynie dodatnie liczby ca³kowite!!!" << std::endl << std::endl
								<< std::setw(11) << "Opcje:" << std::endl
								<< std::setw(35) << "1) Dodawanie dwóch u³amków (+)" << std::endl
								<< std::setw(37) << "2) Odejmowanie dwóch u³amków (-)" << std::endl
								<< std::setw(34) << "3) Mno¿enie dwóch u³amków (*)" << std::endl
								<< std::setw(35) << "4) Dzielenie dwóch u³amków (÷)" << std::endl;

	std::cout << menu_info_text.str();

	while (1)
	{
		std::cout << std::endl << std::setw(47) << "Wybierz dzia³anie (odpowiedni numer)  :  ";

		Tcontact_with_the_user input_text_option;
		std::string help_text;

		try
		{
			std::getline(std::cin, help_text);
			input_text_option.copy(help_text);
			input_text_option.check_if_no_error();
		}
		catch (Tinvalid_char& ex)
		{
			std::cout << ex.what() << std::endl;
			std::cout << std::setw(35) << "WprowadŸ numer jeszcze raz." << std::endl;
			continue;
		}

		option = std::stoi(input_text_option.str());

		if (option != 1 && option != 2 && option != 3 && option != 4)
		{
			std::cout << std::setw(56) << "Nieprawid³owy numer. WprowadŸ numer jeszcze raz." << std::endl;
			continue;
		}

		/////////////////////////////////////////////////////////////////////////////////////

		while (1)
		{
			std::cout << ::std::endl << std::endl << std::setw(50) << "Podaj czêœæ ca³kowit¹ pierwszego u³amka  :  ";
			std::cin >> integer_part_first_fraction;

			if (!std::cin.good())
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << std::endl << std::setw(72) << "Error! [Podana liczba nie jest poprawna! Podaj liczbê jeszcze raz.]" << std::endl;
				continue;
			}

			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			if (integer_part_first_fraction < 0)
			{
				std::cout << std::endl << std::setw(66) << "Error! [Podana liczba jest ujemna! Podaj liczbê jeszcze raz.]" << std::endl;
				continue;
			}
			if (integer_part_first_fraction > 99999)
			{
				std::cout << std::endl << std::setw(67) << "Error! [Podana liczba jest za du¿a! Podaj liczbê jeszcze raz.]" << std::endl;
				continue;
			}

			break;
		}

		///////////////////////////////////////////////////////////////////////////////////////////

		while (1)
		{
			std::cout << ::std::endl << std::setw(42) << "Podaj licznik pierwszego u³amka  :  ";
			std::cin >> numerator_first_fraction;

			if (!std::cin.good())
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << std::endl << std::setw(72) << "Error! [Podana liczba nie jest poprawna! Podaj liczbê jeszcze raz.]" << std::endl;
				continue;
			}

			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			if (numerator_first_fraction < 0)
			{
				std::cout << std::endl << std::setw(66) << "Error! [Podana liczba jest ujemna! Podaj liczbê jeszcze raz.]" << std::endl;
				continue;
			}
			if (numerator_first_fraction == 0)
			{
				std::cout << std::endl << std::setw(65) << "Error! [Podana liczba jest zerem! Podaj liczbê jeszcze raz.]" << std::endl;
				continue;
			}
			if (numerator_first_fraction > 9999)
			{
				std::cout << std::endl << std::setw(67) << "Error! [Podana liczba jest za du¿a! Podaj liczbê jeszcze raz.]" << std::endl;
				continue;
			}

			break;
		}

		///////////////////////////////////////////////////////////////////////////////////////////////

		while (1)
		{
			std::cout << ::std::endl << std::setw(44) << "Podaj mianownik pierwszego u³amka  :  ";
			std::cin >> denominator_first_fraction;

			if (!std::cin.good())
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << std::endl << std::setw(72) << "Error! [Podana liczba nie jest poprawna! Podaj liczbê jeszcze raz.]" << std::endl;
				continue;
			}

			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			if (denominator_first_fraction < 0)
			{
				std::cout << std::endl << std::setw(66) << "Error! [Podana liczba jest ujemna! Podaj liczbê jeszcze raz.]" << std::endl;
				continue;
			}
			if (denominator_first_fraction == 0)
			{
				std::cout << std::endl << std::setw(65) << "Error! [Podana liczba jest zerem! Podaj liczbê jeszcze raz.]" << std::endl;
				continue;
			}
			if (denominator_first_fraction > 9999)
			{
				std::cout << std::endl << std::setw(67) << "Error! [Podana liczba jest za du¿a! Podaj liczbê jeszcze raz.]" << std::endl;
				continue;
			}

			break;
		}


		////////////////////////////////////////----------------------------------------------------------------////////////////////////////////


		while (1)
		{
			std::cout << ::std::endl << std::endl << std::setw(48) << "Podaj czêœæ ca³kowit¹ drugiego u³amka  :  ";
			std::cin >> integer_part_second_fraction;

			if (!std::cin.good())
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << std::endl << std::setw(72) << "Error! [Podana liczba nie jest poprawna! Podaj liczbê jeszcze raz.]" << std::endl;
				continue;
			}

			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			if (integer_part_second_fraction < 0)
			{
				std::cout << std::endl << std::setw(66) << "Error! [Podana liczba jest ujemna! Podaj liczbê jeszcze raz.]" << std::endl;
				continue;
			}
			if (integer_part_second_fraction > 99999)
			{
				std::cout << std::endl << std::setw(67) << "Error! [Podana liczba jest za du¿a! Podaj liczbê jeszcze raz.]" << std::endl;
				continue;
			}

			break;
		}

		///////////////////////////////////////////////////////////////////////////////////////////

		while (1)
		{
			std::cout << ::std::endl << std::setw(40) << "Podaj licznik drugiego u³amka  :  ";
			std::cin >> numerator_second_fraction;

			if (!std::cin.good())
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << std::endl << std::setw(72) << "Error! [Podana liczba nie jest poprawna! Podaj liczbê jeszcze raz.]" << std::endl;
				continue;
			}

			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			if (numerator_second_fraction < 0)
			{
				std::cout << std::endl << std::setw(66) << "Error! [Podana liczba jest ujemna! Podaj liczbê jeszcze raz.]" << std::endl;
				continue;
			}
			if (numerator_second_fraction == 0)
			{
				std::cout << std::endl << std::setw(65) << "Error! [Podana liczba jest zerem! Podaj liczbê jeszcze raz.]" << std::endl;
				continue;
			}
			if (numerator_second_fraction > 9999)
			{
				std::cout << std::endl << std::setw(67) << "Error! [Podana liczba jest za du¿a! Podaj liczbê jeszcze raz.]" << std::endl;
				continue;
			}

			break;
		}

		///////////////////////////////////////////////////////////////////////////////////////////////

		while (1)
		{
			std::cout << ::std::endl << std::setw(42) << "Podaj mianownik drugiego u³amka  :  ";
			std::cin >> denominator_second_fraction;

			if (!std::cin.good())
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << std::endl << std::setw(72) << "Error! [Podana liczba nie jest poprawna! Podaj liczbê jeszcze raz.]" << std::endl;
				continue;
			}

			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			if (denominator_second_fraction < 0)
			{
				std::cout << std::endl << std::setw(66) << "Error! [Podana liczba jest ujemna! Podaj liczbê jeszcze raz.]" << std::endl;
				continue;
			}
			if (denominator_second_fraction == 0)
			{
				std::cout << std::endl << std::setw(65) << "Error! [Podana liczba jest zerem! Podaj liczbê jeszcze raz.]" << std::endl;
				continue;
			}
			if (denominator_second_fraction > 9999)
			{
				std::cout << std::endl << std::setw(67) << "Error! [Podana liczba jest za du¿a! Podaj liczbê jeszcze raz.]" << std::endl;
				continue;
			}

			break;
		}

		////////////////////////////////////////----------------------------------------------------------------////////////////////////////////

		switch (option)
		{
		case 1:
			addition(integer_part_first_fraction, numerator_first_fraction, denominator_first_fraction, 
					 integer_part_second_fraction, numerator_second_fraction, denominator_second_fraction);
			break;
		case 2:
			subtraction(integer_part_first_fraction, numerator_first_fraction, denominator_first_fraction,
						integer_part_second_fraction, numerator_second_fraction, denominator_second_fraction);
			break;
		case 3:
			multiplication(integer_part_first_fraction, numerator_first_fraction, denominator_first_fraction,
						   integer_part_second_fraction, numerator_second_fraction, denominator_second_fraction);
			break;
		case 4:
			division(integer_part_first_fraction, numerator_first_fraction, denominator_first_fraction,
					 integer_part_second_fraction, numerator_second_fraction, denominator_second_fraction);
			break;
		}

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
			print_headline_12();
			std::cout << std::endl << std::setw(33) << "4.6) U³amki - operacje +,-,*,/" << std::endl;
			std::cout << menu_info_text.str();
		}
	}

	return 0;
}