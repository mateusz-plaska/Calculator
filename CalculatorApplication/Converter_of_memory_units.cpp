#include "Converter_of_memory_units.h"
#include "Tcontact_with_the_user.h"
#include "Tinvalid_char.h"
#include "Calculator_display.h"

#include <string>
#include <iostream>
#include <iomanip>
#include <locale.h>
#include <sstream>


void print_headline_2()
{
	Calculator_display sub_programme;
	sub_programme.print_headline();
	return;
}

void from_bit(long double number, int precision)
{
	std::string number_as_text{ std::to_string(number) };

	unsigned int width{ number_as_text.length() + precision };

	std::cout << std::endl << std::endl << std::setw(width) << std::fixed << number << " [b] to:" << std::endl << std::endl << std::fixed 
			  << std::setprecision(precision) << std::setw(7) << "["<< number * 0.125 <<"]" << "    B" << std::endl
			  << std::setw(7) << "["<< number * (1.0 / 8192.0) <<"]" << "    kB" << std::endl
			  << std::setw(7) << "["<< number * (1.0 / 8388608.0) <<"]" << "    MB" << std::endl
			  << std::setw(7) << "["<< number * (1.0 / 8589934592.0) <<"]" << "    GB" << std::endl
			  << std::setw(7) << "["<< number * (1.0 / 8796093022208.0) <<"]" << "    TB" << std::endl << std::endl;

	return;
}

void from_byte(long double number, int precision)
{
	std::string number_as_text{ std::to_string(number) };

	unsigned int width{ number_as_text.length() + precision };

	std::cout << std::endl << std::endl << std::setw(width) << std::fixed << number << " [B] to:" << std::endl << std::endl << std::fixed
		<< std::setprecision(precision) << std::setw(7) << "[" << number * 8.0 << "]" << "    b" << std::endl
		<< std::setw(7) << "[" << number * (1.0 / 1024.0) << "]" << "    kB" << std::endl
		<< std::setw(7) << "[" << number * (1.0 / 1048576.0) << "]" << "    MB" << std::endl
		<< std::setw(7) << "[" << number * (1.0 / 1073741824.0) << "]" << "    GB" << std::endl
		<< std::setw(7) << "[" << number * (1.0 / 1099511627776.0) << "]" << "    TB" << std::endl << std::endl;

	return;
}

void from_kilobyte(long double number, int precision)
{
	std::string number_as_text{ std::to_string(number) };

	unsigned int width{ number_as_text.length() + precision };

	std::cout << std::endl << std::endl << std::setw(width) << std::fixed << number << " [kB] to:" << std::endl << std::endl << std::fixed
		<< std::setprecision(precision) << std::setw(7) << "[" << number * 8192.0 << "]" << "    b" << std::endl
		<< std::setw(7) << "[" << number *  1024.0 << "]" << "    B" << std::endl
		<< std::setw(7) << "[" << number * (1.0 / 1024.0) << "]" << "    MB" << std::endl
		<< std::setw(7) << "[" << number * (1.0 / 1048576.0) << "]" << "    GB" << std::endl
		<< std::setw(7) << "[" << number * (1.0 / 1073741824.0) << "]" << "    TB" << std::endl << std::endl;

	return;
}

void from_megabyte(long double number, int precision)
{
	std::string number_as_text{ std::to_string(number) };

	unsigned int width{ number_as_text.length() + precision };

	std::cout << std::endl << std::endl << std::setw(width) << std::fixed << number << " [MB] to:" << std::endl << std::endl << std::fixed
		<< std::setprecision(precision) << std::setw(7) << "[" << number * 8388608.0 << "]" << "    b" << std::endl
		<< std::setw(7) << "[" << number * 1048576.0 << "]" << "    B" << std::endl
		<< std::setw(7) << "[" << number * 1024.0 << "]" << "    kB" << std::endl
		<< std::setw(7) << "[" << number * (1.0 / 1024.0) << "]" << "    GB" << std::endl
		<< std::setw(7) << "[" << number * (1.0 / 1048576.0) << "]" << "    TB" << std::endl << std::endl;

	return;
}

void from_gigabyte(long double number, int precision)
{
	std::string number_as_text{ std::to_string(number) };

	unsigned int width{ number_as_text.length() + precision };

	std::cout << std::endl << std::endl << std::setw(width) << std::fixed << number << " [GB] to:" << std::endl << std::endl << std::fixed
		<< std::setprecision(precision) << std::setw(7) << "[" << number * 8589934592.0 << "]" << "    b" << std::endl
		<< std::setw(7) << "[" << number * 1073741824.0 << "]" << "    B" << std::endl
		<< std::setw(7) << "[" << number * 1048576.0 << "]" << "    kB" << std::endl
		<< std::setw(7) << "[" << number * 1024.0 << "]" << "    MB" << std::endl
		<< std::setw(7) << "[" << number * (1.0 / 1024.0) << "]" << "    TB" << std::endl << std::endl;

	return;
}

void from_terabyte(long double number, int precision)
{
	std::string number_as_text{ std::to_string(number) };

	unsigned int width{ number_as_text.length() + precision };

	std::cout << std::endl << std::endl << std::setw(width) << std::fixed << number << " [TB] to:" << std::endl << std::endl << std::fixed
		<< std::setprecision(precision) << std::setw(7) << "[" << number * 8796093022208.0 << "]" << "    b" << std::endl
		<< std::setw(7) << "[" << number * 1099511627776.0 << "]" << "    B" << std::endl
		<< std::setw(7) << "[" << number * 1073741824.0 << "]" << "    kB" << std::endl
		<< std::setw(7) << "[" << number * 1048576.0 << "]" << "    MB" << std::endl
		<< std::setw(7) << "[" << number * 1024.0 << "]" << "    GB" << std::endl << std::endl;

	return;
}

int convert_memory_units()
{
	setlocale(LC_CTYPE, "Polish");

	std::ostringstream menu;
	long double number;
	int menu_option,precision;
	char wilgness_to_continue;


	menu << std::endl << std::setw(17) << "1) bit  [b]" << std::endl
		<< std::setw(18) << "2) bajt  [B]" << std::endl
		<< std::setw(23) << "3) kilobajt  [kB]" << std::endl
		<< std::setw(23) << "4) megabajt  [MB]" << std::endl
		<< std::setw(23) << "5) gigabajt  [GB]" << std::endl
		<< std::setw(23) << "6) terabajt  [TB]" << std::endl << std::endl
		<< std::setw(51) << "WprowadŸ liczbê oraz wybierz jednostkê miary," << std::endl
		<< std::setw(68) << "któr¹ chcesz przeliczyæ (podaj numer przy wybranej jednostce)." << std::endl;

	std::cout << menu.str();

	while (1)
	{
		std::cout << std::endl << std::setw(44) << "Podaj liczbê (przecinek jako kropka) : ";
		std::cin >> number;

		if (!std::cin.good())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << std::endl << std::setw(64) << "Error! Nie podano poprawnej liczby, wprowadŸ j¹ jeszcze raz!" << std::endl;
			continue;
		}

		Tcontact_with_the_user input_menu_option;
		std::string help_text;

		try
		{
			std::cin.ignore();
			std::cout << std::endl << std::setw(55) << "Podaj jednostkê miary tej liczby (numer z menu) : ";
			std::getline(std::cin, help_text);
			input_menu_option.copy(help_text);
			input_menu_option.check_if_no_error();
		}
		catch (Tinvalid_char& ex)
		{
			std::cout << ex.what() << std::endl;
			std::cout << std::setw(27) << "Podaj dane jeszcze raz." << std::endl;
			continue;
		}

		menu_option = std::stoi(input_menu_option.str());

		if (menu_option < 1 || menu_option > 6)
		{
			std::cout << std::endl << std::setw(51) << "Nieprawid³owy numer. WprowadŸ dane jeszcze raz." << std::endl;
			continue;
		}

		std::cout << std::endl << std:: setw(63) << "Podaj dok³adnoœæ (iloœæ miejsc po przecniku) od 0 do 12 : ";
		std::cin >> precision;

		if (!std::cin.good())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << std::endl << std::setw(64) << "Error! Nie podano poprawnej liczby, wprowadŸ j¹ jeszcze raz!" << std::endl;
			continue;
		}

		if (precision < 0 || precision > 12)
		{
			std::cout << std::endl << std::setw(51) << "Nieprawid³owy numer. WprowadŸ dane jeszcze raz." << std::endl;
			continue;
		}

		switch (menu_option)
		{
		case 1:
			from_bit(number, precision);
			break;

		case 2:
			from_byte(number, precision);
			break;

		case 3:
			from_kilobyte(number, precision);
			break;

		case 4:
			from_megabyte(number, precision);
			break;

		case 5:
			from_gigabyte(number, precision);
			break;

		case 6:
			from_terabyte(number, precision);
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
			print_headline_2();
			std::cout << std::endl << std::setw(49) << "2) Konwerter jednostek pamiêci (iloœci danych)" << std::endl;
			std::cout << menu.str();
		}
	}

	return 0;
}