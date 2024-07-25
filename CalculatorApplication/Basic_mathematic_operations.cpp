#include "Basic_mathematic_operations.h"
#include "Calculator_display.h"
#include "Tcontact_with_the_user.h"
#include "Tinvalid_char.h"

#include <iostream>
#include <locale.h>
#include <sstream>
#include <iomanip>
#include <string>

void print_headline_13()
{
	Calculator_display sub_programme;
	sub_programme.print_headline();
	return;
}

int basic_mathematic_operations()
{
	setlocale(LC_CTYPE, "Polish");

	std::ostringstream menu_info_text;
	char wilgness_to_continue;
	int option;
	char operator_char;

	menu_info_text << std::endl << std::setw(38) << "Podstawowe operacje matematyczne" << std::endl << std::endl
								<< std::setw(11) << "Opcje:" << std::endl
								<< std::setw(21) << "1) Dodawanie (+)" << std::endl
								<< std::setw(23) << "2) Odejmowanie (-)" << std::endl
								<< std::setw(20) << "3) Mno¿enie (*)" << std::endl
								<< std::setw(21) << "4) Dzielenie (÷)" << std::endl;

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

		switch (option)
		{
		case 1:
			operator_char = '+';
			break;
		case 2:
			operator_char = '-';
			break;
		case 3:
			operator_char = '*';
			break;
		case 4: 
			operator_char = '÷';
			break;
		}

		std::cout << std::endl << std::setw(79) << "WprowadŸ liczby (max 20), po podaniu liczb wpisz 0.0 aby obliczyæ wynik :" << std::endl;
		std::cout << std::endl << std::setw(12) << "| ->  ";

		long double numbers[20];
		long double result{ 0.0 };

		int amount{ 0 };
		while (amount < 20)
		{
			std::cin >> numbers[amount];

			if (!std::cin.good())
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << std::endl << std::setw(72) << "Error! [Podana liczba nie jest poprawna! Podaj liczbê jeszcze raz.]" << std::endl;
				std::cout << std::endl << std::setw(8) << "| " << operator_char << " ";
				continue;
			}

			if (numbers[amount] == 0.0)
				break;

			std::cout << std::setw(8) << "| " << operator_char << " ";
			++amount;
		}

		for (int i = 0; i < amount; ++i)
		{
			if (i == 0 && numbers[i] == 0.0)
			{
				result = 0;
				break;
			}

			switch (option)
			{
			case 1:
				if (i == 0)
					result = numbers[i];
				else
					result += numbers[i];
				break;
			case 2:
				if (i == 0)
					result = numbers[i];
				else
					result -= numbers[i];
				break;
			case 3:
				if (i == 0)
					result = numbers[i];
				else
					result *= numbers[i];
				break;
			case 4:
				if (i == 0)
					result = numbers[i];
				else
					result /= numbers[i];
				break;
			}
		}

		std::cout << std::endl << std::setw(12) << "|  =  " << result << std::endl;

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
			print_headline_13();
			std::cout << std::endl << std::setw(28) << "4.7) Operacje + , -, *, /" << std::endl;
			std::cout << menu_info_text.str();
		}
	}
	
	return 0;
}