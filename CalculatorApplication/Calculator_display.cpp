#include "Calculator_display.h"

#include <Windows.h>
#include <string>
#include <iostream>
#include <iomanip>
#include <locale.h>
#include <sstream>

Calculator_display::Calculator_display()
{
    setlocale(LC_CTYPE, "Polish");

    menu_text << std::endl << std::setw(25) << "Dostepne funkcje: " << std::endl
        << std::setw(36) << "1) Zamiana systemow liczbowych" << std::endl
        << std::setw(34) << "2) Zamiana jednostek pamieci" << std::endl
        << std::setw(20) << "3) Dzialania: " << std::endl
        << std::setw(35) << "3.1) Pierwszosc liczby" << std::endl
        << std::setw(34) << "3.2) Dzielniki liczby" << std::endl
        << std::setw(53) << "3.3) Rozklad liczby na czynniki pierwsze" << std::endl
        << std::setw(47) << "3.4) ONP (Odwrotna notacja polska)" << std::endl
        << std::setw(43) << "4)Pojedyncze dzialanie (obliczenie): " << std::endl
        << std::setw(26) << "4.1) NWD, NWW" << std::endl
        << std::setw(31) << "4.2) Silnia liczby" << std::endl
        << std::setw(29) << "4.3) Pierwiastek" << std::endl
        << std::setw(24) << "4.4) Potega" << std::endl
        << std::setw(26) << "4.5) Logarytm" << std::endl
        << std::setw(43) << "4.6) Ulamki - operacje +,-,*,/" << std::endl
        << std::setw(34) << "4.7) Operacje +,-,*,/" << std::endl
        << std::setw(26) << "5) Zlozone dzialania" << std::endl
        << std::setw(26) << "6) Wylacz kalkulator" << std::endl
        << std::endl << std::setw(46) << "*Chcac wyczyscic ekran wpisz cyfre zero*" << std::endl
        << std::endl << std::setw(40) << "Wpisz numer znajdujacy sie przy" << std::endl
        << std::setw(60) << "wybranym dzialaniu aby je wykonać (pomin kropki) : ";
}

int Calculator_display::bufferinfo(int& width, int& height)
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	HANDLE hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut, &csbi);
	width = csbi.dwSize.X;
	height = csbi.dwSize.Y;

	return 0;
}

void Calculator_display::print_headline()
{
	int width_console, height_console;
	std::string headline("KALKULATOR MATEMATYCZNO - INFORMATYCZNY");

	bufferinfo(width_console, height_console);
	std::cout << std::setw((headline.length() + width_console) / 2) << headline << std::endl;

	return;
}

void Calculator_display::print_menu()
{
    std::cout << menu_text.str();
	return;
}

void Calculator_display::print_thanks_for_using()
{
    setlocale(LC_CTYPE, "Polish");

    int width_console, height_console;
    std::string thanks("Dziękujemy za skorzystanie z kalkulatora");

    bufferinfo(width_console, height_console);
    std::cout<< std::endl << std::endl << std::setw((thanks.length() + width_console) / 2) << thanks << std::endl << std::endl;

    return;
}

void Calculator_display::clear_screen()
{
    system("cls");
    return;
}
