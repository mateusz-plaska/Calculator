#include "Tinvalid_char.h"

#include <string>
#include <iostream>
#include <locale.h>
#include <sstream>

Tinvalid_char::Tinvalid_char() : error_code("")
{}

void Tinvalid_char::add_error_text(const std::string text)
{
	error_code += text;
	return;
}

std::string Tinvalid_char::what()
{
	setlocale(LC_CTYPE, "Polish");

	std::ostringstream info;
	info << std::endl << "ERROR! Informacja b³êdu:"<< std::endl << std::endl << error_code << std::endl;
	
	return info.str();
}