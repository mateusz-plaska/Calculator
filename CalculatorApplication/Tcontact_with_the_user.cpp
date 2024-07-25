#include "Tcontact_with_the_user.h"
#include "Tinvalid_char.h"

#include <string>
#include <iostream>
#include <locale.h>
#include <sstream>

Tcontact_with_the_user::Tcontact_with_the_user() : input_action_as_text("")
{}

std::string Tcontact_with_the_user::str()
{
	return input_action_as_text;
}

void Tcontact_with_the_user::copy(const std::string& original)
{
	input_action_as_text = original;
	return;
}

bool Tcontact_with_the_user::check_if_no_error()
{
	setlocale(LC_CTYPE, "Polish");

	int amount_of_chars{ 0 }; // max 9
	bool if_ok{ true };

	Tinvalid_char exception;
	
	amount_of_chars = input_action_as_text.length();
	if (amount_of_chars > 9)
	{
		std::ostringstream text;

		text << "	- Podano za du�o znak�w: " << amount_of_chars << " (dozwolone max: 9)" << std::endl;
		exception.add_error_text(text.str());
	}
	else
	{
		for (int i = 0; i < amount_of_chars; ++i)
		{
			if (input_action_as_text[i] >= 48 && input_action_as_text[i] <= 57) // jest cyfr�
				continue;
			else
				if_ok = false;
		}

		if (if_ok)
			return true;
	}

	for (int i = 0; i < amount_of_chars; ++i)
	{
		if (input_action_as_text[i] == 32) // spacja
		{
			std::ostringstream text;

			text << "	- Podano niedozwolony znak - 'spacja' " << std::endl;
			exception.add_error_text(text.str());
		}

		if (input_action_as_text[i] >= 65 && input_action_as_text[i] <= 90) // du�a litera
		{
			std::ostringstream text;

			text << "	- Podano niedozwolony znak - 'du�a litera' " << std::endl;
			exception.add_error_text(text.str());
		}

		if (input_action_as_text[i] >= 97 && input_action_as_text[i] <= 122) // ma�a litera
		{
			std::ostringstream text;

			text << "	- Podano niedozwolony znak - 'ma�a litera' " << std::endl;
			exception.add_error_text(text.str());
		}
		
		if ((input_action_as_text[i] >= 33 && input_action_as_text[i] <= 47) ||
			(input_action_as_text[i] >= 58 && input_action_as_text[i] <= 64) ||
			(input_action_as_text[i] >= 91 && input_action_as_text[i] <= 96) ||
			(input_action_as_text[i] == 126))										// inny znak
		{
			std::ostringstream text;

			text << "	- Podano niedozwolony znak - 'inny znak'" << std::endl;
			exception.add_error_text(text.str());
		}
	}

	throw exception;
}

std::istream& operator>> (std::istream& input_s, Tcontact_with_the_user& text)
{
	input_s >> text.input_action_as_text;
	return input_s;
}

