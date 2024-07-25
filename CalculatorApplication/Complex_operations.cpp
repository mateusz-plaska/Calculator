#include "Complex_operations.h"
#include "Calculator_display.h"
#include "Reverse_Polish_Notation.h"

#include <iostream>
#include <locale.h>
#include <sstream>
#include <iomanip>
#include <string>

void print_headline_14()
{
	Calculator_display sub_programme;
	sub_programme.print_headline();
	return;
}

int complex_operations()
{
	setlocale(LC_CTYPE, "Polish");

	std::ostringstream menu_info_text;
	char wilgness_to_continue;
	std::string rpn_exp, orginal_classic_exp;

	menu_info_text << std::endl << std::setw(55) << "Mo¿esz podawaæ jedynie dodatnie liczby ca³kowite!" << std::endl
								<< std::setw(73) << "Podaj¹c niepoprwane wyra¿enie (z³e znaki itp.) wynik bêdzie b³êdny!" << std::endl << std::endl;



	std::cout << menu_info_text.str();

	while (1)
	{
		std::cout << std::endl << std::setw(58) << "Podaj wyra¿enie, na koñcu dodaj znak \"równa siê\" [=]" << std::endl
							   << std::setw(63) << "(mo¿esz u¿ywaæ + , -, *, / , ^ oraz nawiasów i spacji) : " << std::endl << std::endl;

		std::cout << std::setw(9) << "|  ";

		try
		{
			input_and_change_into_rpn(rpn_exp, orginal_classic_exp);
		}
		catch (std::invalid_argument& ex)
		{
			std::cout << std::endl << std::setw(68) << ex.what() << std::endl;
			continue;
		}
		
		std::cout << std::endl << std::setw(9) << "|  " << orginal_classic_exp << " = " << calculate_result(rpn_exp) << std::endl;

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
			print_headline_14();
			std::cout << std::endl << std::setw(23) << "5) Z³o¿one dzia³ania" << std::endl;
			std::cout << menu_info_text.str();
		}
	}

	return 0;
}
