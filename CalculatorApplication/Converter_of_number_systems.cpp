#include "Converter_of_number_systems.h"
#include "Tcontact_with_the_user.h"
#include "Tinvalid_char.h"
#include "Calculator_display.h"

#include <string>
#include <iostream>
#include <iomanip>
#include <locale.h>
#include <sstream>


std::string from_decimal_to_any(int given_number, int base)
{
    std::string in_any{};
    int modulo;

    while (given_number > 0)
    {
        modulo = given_number % base;

        if (modulo >= 0 && modulo <= 9)
        {
            modulo += 48;
            in_any += char(modulo);
        }
        else
        {
            modulo += 55;
            in_any += char(modulo);
        }
        given_number /= base;
    }

    std::reverse(in_any.begin(), in_any.end());

    return in_any;
}

int from_any_to_decimal(std::string given_number, int base)
{
    int i, in_decimal{}, help{};

    std::reverse(given_number.begin(), given_number.end());

    for (i = 0; i < given_number.length(); ++i)
    {
        if (given_number[i] <= '9') //from 0 to 9
        {
            help = (int)given_number[i] - 48; //given_number[i]-'0' / '0'==48
        }
        else                     // >=10 so >=A
        {
            help = (int)given_number[i] - 55; //for example: A=65(10) so 65-55=10
        }                                 //given_number[i]-'7' / '7'==55

        in_decimal += help * pow(base, i);
    }

    return in_decimal;
}

std::string from_any_to_any(std::string given_number, int base_of_number, int desired_based)
{
    return from_decimal_to_any(from_any_to_decimal(given_number, base_of_number), desired_based);
}

void print_headline_1()
{
    Calculator_display sub_programme;
    sub_programme.print_headline();
    return;
}

int convert_number_systems()
{
    setlocale(LC_CTYPE, "Polish");

    int base_first{}, base_second{};
    std::string number;
    char wilgness_to_continue;
    std::ostringstream info_text;


    info_text << std::endl << std::setw(69) << "Mo¿esz zamieniæ liczbê z dowolnego systemu pozycyjnego na inny." << std::endl
              << std::setw(50) << "Podana podstawa systemu mo¿e byæ od 2 do 20." << std::endl << std::endl
             
              << std::setw(76) << "Jesli podasz z³e dane w liczbie (cyfry nieistniej¹ce w danym systemie)" << std::endl
              << std::setw(32) << "wynik bedzie niepoprwamny!" << std::endl
              << std::setw(40) << "Upewnij siê ¿e dane s¹ prawid³owe!" << std::endl << std::endl;

    std::cout << info_text.str();

    while (1)
    {
        std::cout << std::endl << std::setw(10) << "Podaj:" << std::endl
                  << std::setw(16) << "1.Liczbê : ";
        std::getline(std::cin, number);

        bool if_space{ false };

        for (int i = 0; i < number.length(); ++i)
        {
            if (number[i] == ' ')
            {
                if_space = true;
                std::cout << std::setw(44) << "Error!  [W liczbie nie mo¿e byæ spacji]" << std::endl << std::endl;
                break;
            }
        }
         
        if (if_space)
            break;

        Tcontact_with_the_user input_text_base;
        std::string help_text;

        try
        {
            std::cout << std::endl << std::setw(37) << "2.Podstawê systemu tej liczby : ";
            std::getline(std::cin, help_text);
            input_text_base.copy(help_text);
            input_text_base.check_if_no_error();
        }
        catch (Tinvalid_char& ex)
        {
            std::cout << ex.what() << std::endl;
            std::cout << std::setw(28) << "Podaj dane jeszcze raz." << std::endl;
            continue;
        }

        base_first = std::stoi(input_text_base.str());

        try
        {
            std::cout << std::endl << std::setw(27) << "3.Docelow¹ podstawê : ";
            std::getline(std::cin, help_text);
            input_text_base.copy(help_text);
            input_text_base.check_if_no_error();
        }
        catch (Tinvalid_char& ex)
        {
            std::cout << ex.what() << std::endl;
            std::cout << std::setw(28) << "Podaj dane jeszcze raz." << std::endl;
            continue;
        }
   
        base_second = std::stoi(input_text_base.str());

        if (base_first < 2 || base_first > 20 || base_second < 2 || base_second > 20)
        {
            std::cout << std::endl << std::endl << std::setw(55) << "Error!  [Podstawa systemu nie jest z zakresu 2:20]" << std::endl << std::endl;
            continue;
        }

        std::cout << std::endl << std::setw(15) << "Wynik :  [" << base_second << "]  " << from_any_to_any(number, base_first, base_second) << std::endl;

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
            print_headline_1();
            std::cout << std::endl << std::setw(35) << "1) Konwerter systemów liczbowych" << std::endl;
            std::cout << info_text.str();
        }
    }

    return 0;
}