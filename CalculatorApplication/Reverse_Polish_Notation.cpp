#include "Reverse_Polish_Notation.h"
#include "Tinvalid_char.h"
#include "Tcontact_with_the_user.h"
#include "Calculator_display.h"

#include <iostream>
#include <locale.h>
#include <sstream>
#include <iomanip>
#include <string>
#include <cmath>

constexpr int MAX_STACK_SIZE{ 100 };

void print_headline_6()
{
	Calculator_display sub_programme;
	sub_programme.print_headline();
	return;
}


int Check_Operator_Priority(char which_operator)
{
	switch (which_operator)
	{
	case '+':;
	case '-': return 1;
	case '*':;
	case '/': return 2;
	case '^': return 3;
	}
	return 0;
}

void input_and_change_into_rpn(std::string& rpn_expression, std::string& orginal_classic_expression)
{
    rpn_expression = "";
    orginal_classic_expression = "";
    char operators_stack[MAX_STACK_SIZE];
    int stack_indicator = 0;
    char char_of_expression;
    std::string orginal_expression_as_string;
    int i{ 0 };

    std::getline(std::cin, orginal_expression_as_string);

    while (1)
    {
        char_of_expression = orginal_expression_as_string[i++];

        if (char_of_expression < 48 || char_of_expression > 57)   // nie jest cyfra
        {
            // nie jest       spacja                    =                               (                    )
            if (char_of_expression != 32 && char_of_expression != 61 && char_of_expression != 40 && char_of_expression != 41 &&
                char_of_expression != 43 && char_of_expression != 45 && char_of_expression != 42 && char_of_expression != 47 && char_of_expression != 94)
                //               +                        -                             *                           /                              ^
            {
                throw std::invalid_argument("Error! Podano niedozowolone znaki!!! WprowadŸ dane jeszcze raz.");
            }
        }

        orginal_classic_expression += char_of_expression;

        if (char_of_expression == '=')
        {
            rpn_expression += ' ';
            while (stack_indicator)
            {
                rpn_expression += operators_stack[--stack_indicator];
                rpn_expression += ' ';
            }
            orginal_classic_expression.pop_back();
            break;
        }

        switch (char_of_expression)
        {
        case ' ': 
            break;
        case '(':
            operators_stack[stack_indicator++] = '(';
            break;
        case ')':
            rpn_expression += ' ';
            while (operators_stack[stack_indicator - 1] != '(')
                rpn_expression += operators_stack[--stack_indicator];
            stack_indicator--; // zdejmuje nawias
            break;
        case '+':;
        case '-':;
        case '*':;
        case '/':;
        case '^':
            rpn_expression += ' ';
            while (stack_indicator)
            {
                if (Check_Operator_Priority(char_of_expression) == 3 ||
                    Check_Operator_Priority(char_of_expression) > Check_Operator_Priority(operators_stack[stack_indicator - 1]))
                    break;
                rpn_expression += operators_stack[--stack_indicator]; // na wyjœcie przesy³amy ze stosu wszystkie operatory o >= priorytetach
                rpn_expression += ' ';
            }
            operators_stack[stack_indicator++] = char_of_expression;
            break;
        default:      // jesli to liczba to wypisujemy
            rpn_expression += char_of_expression;
            break;
        }
    }

    return;
}

long long calculate_result(std::string rpn_expression) // liczy wynik z wyra¿enia ONP
{
    long long stack[MAX_STACK_SIZE], x, y;
    int indicator = 0, i;

    for (i = 0; i < rpn_expression.size(); i++)
    {
        if (rpn_expression[i] == ' ')
            continue;
        if (rpn_expression[i] == '=')
            break;
        else if (isdigit(rpn_expression[i]))
        {
            // do spacji odczytuje liczbe
            std::string liczba = "";
            liczba += rpn_expression[i];

            while (isdigit(rpn_expression[++i]))
                liczba += rpn_expression[i];
            --i;

            stack[indicator++] = std::stoll(liczba);
        }
        else
        {
            y = stack[--indicator];
            x = stack[--indicator];
            switch (rpn_expression[i])
            {
            case '+': x += y;
                break;
            case '-': x -= y;
                break;
            case '*': x *= y;
                break;
            case '/': x /= y;
                break;
            case '^': x = std::pow(x, y);
                break;
            }
            stack[indicator++] = x;
        }
    }

    return stack[--indicator];
}

int RPN()
{
	setlocale(LC_CTYPE, "Polish");

	std::ostringstream menu_info_text;
	char wilgness_to_continue;
	int option;
    std::string rpn_exp,orginal_classic_exp,rpn_exp_option_2;

    menu_info_text << std::endl << std::setw(70) << "Mo¿esz zamieniæ wyra¿enia z zapisu infiksowego (zapis klasyczny)" << std::endl
								<< std::setw(67) << "na zapis postfiksowym (ONP) oraz obliczyæ wynik wyra¿enia ONP" << std::endl << std::endl
                                << std::setw(55) << "Mo¿esz podawaæ jedynie dodatnie liczby ca³kowite!" << std::endl
                                << std::setw(73) << "Podaj¹c niepoprwane wyra¿enie (z³e znaki itp.) wynik bêdzie b³êdny!" << std::endl << std::endl
								<< std::setw(49) << "1. Zapis infiksowy (klasyczny) -> Zapis ONP" << std::endl
								<< std::setw(60) << "2. Oblicz wynik wyra¿enia zapisanego postfiksowo (ONP)" << std::endl;

	std::cout << menu_info_text.str();

	while (1)
	{
		std::cout << std::endl << std::setw(38) << "Wybierz opcjê (wpisz 1 lub 2) : ";

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
			std::cout << std::endl << std::setw(38) << "WprowadŸ numer jeszcze raz." << std::endl;
			continue;
		}

		option = std::stoi(input_text_option.str());

		if (option != 1 && option != 2)
		{
			std::cout << std::endl << std::setw(56) << "Nieprawid³owy numer. WprowadŸ numer jeszcze raz." << std::endl;
			continue;
		}

        if (option == 1)
        {
            while (1)
            {
                std::cout << std::endl << std::setw(79) << "Podaj wyra¿enie w zapisie infiksowym, na koñcu dodaj znak \"równa siê\" [=]" << std::endl
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

                std::cout << std::endl << std::setw(9) << "|  " << orginal_classic_exp << " = " << rpn_exp << " = " << calculate_result(rpn_exp) << std::endl;
                break;
            }
        }
        if (option == 2)
        {
            rpn_exp_option_2 = "";
            std::cout << std::endl << std::setw(49) << "Podaj wyra¿enie zapisane postfiksowo (ONP)," << std::endl 
                                   << std::setw(41) << "na koñcu dodaj znak \"równa siê\" [=]" << std::endl
                                   << std::setw(52) << "(mo¿esz u¿ywaæ + , -, *, / , ^ oraz spacji) : " << std::endl << std::endl;
            std::cout << std::setw(9) << "|  ";
            std::getline(std::cin, rpn_exp_option_2);
            std::cout << std::endl << std::setw(9) << "|  " << rpn_exp_option_2 << " " << calculate_result(rpn_exp_option_2) << std::endl;
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
			print_headline_6();
			std::cout << std::endl << std::setw(37) << "3.4) ONP (Odwrotna notacja polska)" << std::endl;
			std::cout << menu_info_text.str();
		}
	}

	return 0;
}