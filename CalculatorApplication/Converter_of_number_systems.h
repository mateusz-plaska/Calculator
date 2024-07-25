#pragma once

#include <string>

std::string from_decimal_to_any(int given_number, int base);

int from_any_to_decimal(std::string given_number, int base);

std::string from_any_to_any(std::string given_number, int base_of_number, int desired_based);

int convert_number_systems();

void print_headline_1();