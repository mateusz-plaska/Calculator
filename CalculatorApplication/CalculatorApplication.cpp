// CalculatorApplication.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.

#include "Calculator_display.h"
#include "Tinvalid_char.h"
#include "Tcontact_with_the_user.h"

#include "Converter_of_number_systems.h"
#include "Converter_of_memory_units.h"
#include "Prime_numbers.h"
#include "Divisors_of_a_number.h"
#include "Factorization.h"
#include "Reverse_Polish_Notation.h"
#include "GCD_and_LCM.h"
#include "Factorial.h"
#include "Radical.h"
#include "Power.h"
#include "Logarithms.h"
#include "Fractions.h"
#include "Basic_mathematic_operations.h"
#include "Complex_operations.h"

#include <string>
#include <iostream>
#include <iomanip>
#include <locale.h>
#include <sstream>

int main()
{
    setlocale(LC_CTYPE, "Polish");
    system("color 1a");

    Calculator_display calculator;
    
    int selected_action;
    Tcontact_with_the_user input_text_action;

    calculator.print_headline();
    calculator.print_menu();

    while (1)
    {
        try
        {
            std::string help_text;
            std::getline(std::cin, help_text);
            input_text_action.copy(help_text);
            input_text_action.check_if_no_error();
        }
        catch (Tinvalid_char& ex)
        {
            std::cout << ex.what() << std::endl;
            std::cout << std::endl << std::setw(38) << "Wprowadź numer jeszcze raz : ";
            continue;
        }
        

        selected_action = std::stoi(input_text_action.str());

        if (selected_action == 6)
            break;

        switch (selected_action)
        {
        case 0:      // czyszczenie ekranu
        {
            calculator.clear_screen();
            calculator.print_headline();
            calculator.print_menu();
        }
        break;

        case 1:
        {
            calculator.clear_screen();
            calculator.print_headline();

            std::cout << std::endl << std::setw(35) << "1) Konwerter systemów liczbowych" << std::endl;

            convert_number_systems();

            calculator.clear_screen();
            calculator.print_headline();
            calculator.print_menu();
        }
        break;

        case 2:
        {
            calculator.clear_screen();
            calculator.print_headline();

            std::cout << std::endl << std::setw(49) << "2) Konwerter jednostek pamięci (ilości danych)" << std::endl;

            convert_memory_units();

            calculator.clear_screen();
            calculator.print_headline();
            calculator.print_menu();
        }
        break;
        case 31: 
        {
            calculator.clear_screen();
            calculator.print_headline();

            std::cout << std::endl << std::setw(25) << "3.1) Pierwszość liczby" << std::endl;

            check_if_prime();

            calculator.clear_screen();
            calculator.print_headline();
            calculator.print_menu();
        }
        break;
        case 32: 
        {
            calculator.clear_screen();
            calculator.print_headline();

            std::cout << std::endl << std::setw(24) << "3.2) Dzielniki liczby" << std::endl;

            find_divisors();

            calculator.clear_screen();
            calculator.print_headline();
            calculator.print_menu();
        }
        break;
        case 33: 
        {
            calculator.clear_screen();
            calculator.print_headline();

            std::cout << std::endl << std::setw(58) << "3.3) Rozkład liczby na czynniki pierwsze (faktoryzacja)" << std::endl;

            find_prime_factors();

            calculator.clear_screen();
            calculator.print_headline();
            calculator.print_menu();
        }
        break;
        case 34: 
        {
            calculator.clear_screen();
            calculator.print_headline();

            std::cout << std::endl << std::setw(37) << "3.4) ONP (Odwrotna notacja polska)" << std::endl;

            RPN();

            calculator.clear_screen();
            calculator.print_headline();
            calculator.print_menu();
        }
        break;
        case 41: 
        {
            calculator.clear_screen();
            calculator.print_headline();

            std::cout << std::endl << std::setw(16) << "4.1) NWD, NWW" << std::endl;

            gcd_and_lcm();

            calculator.clear_screen();
            calculator.print_headline();
            calculator.print_menu();
        }
        break;
        case 42: 
        {
            calculator.clear_screen();
            calculator.print_headline();

            std::cout << std::endl << std::setw(21) << "4.2) Silnia liczby" << std::endl;
            
            factorial();

            calculator.clear_screen();
            calculator.print_headline();
            calculator.print_menu();
        }
        break;
        case 43: 
        {
            calculator.clear_screen();
            calculator.print_headline();

            std::cout << std::endl << std::setw(19) << "4.3) Pierwiastek" << std::endl;

            radical();

            calculator.clear_screen();
            calculator.print_headline();
            calculator.print_menu();
        }
        break;
        case 44: 
        {
            calculator.clear_screen();
            calculator.print_headline();

            std::cout << std::endl << std::setw(14) << "4.4) Potęga" << std::endl;

            power();

            calculator.clear_screen();
            calculator.print_headline();
            calculator.print_menu();
        }
        break;
        case 45: 
        {
            calculator.clear_screen();
            calculator.print_headline();

            std::cout << std::endl << std::setw(16) << "4.5) Logarytm" << std::endl;

            logarithms();

            calculator.clear_screen();
            calculator.print_headline();
            calculator.print_menu();
        }
        break;
        case 46: 
        {
            calculator.clear_screen();
            calculator.print_headline();

            std::cout << std::endl << std::setw(33) << "4.6) Ułamki - operacje +,-,*,/" << std::endl;

            fractions();

            calculator.clear_screen();
            calculator.print_headline();
            calculator.print_menu();
        }
        break;
        case 47: 
        {
            calculator.clear_screen();
            calculator.print_headline();

            std::cout << std::endl << std::setw(28) << "4.7) Operacje + , -, *, /" << std::endl;

            basic_mathematic_operations();

            calculator.clear_screen();
            calculator.print_headline();
            calculator.print_menu();
        }
        break;
        case 5:
        {
            calculator.clear_screen();
            calculator.print_headline();

            std::cout << std::endl << std::setw(23) << "5) Złożone działania" << std::endl;

            complex_operations();

            calculator.clear_screen();
            calculator.print_headline();
            calculator.print_menu();
        }
        break;
        
        default:
            std::cout << std::endl << std::setw(57) << "Nieprawidłowy numer. Wprowadź numer jeszcze raz : ";
            break;
        }
    }

    calculator.clear_screen();
    calculator.print_thanks_for_using();

    return 0;
}
