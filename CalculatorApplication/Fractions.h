#pragma once

void print_headline_12();

long long find_Greatest_Common_Divisor(long long numb_1, long long numb_2);

long long find_Least_Common_Multiple(long long numb_1, long long numb_2);

void addition(long long integer_part_first_fraction, long long numerator_first_fraction, long long denominator_first_fraction,
			  long long integer_part_second_fraction, long long numerator_second_fraction, long long denominator_second_fraction);

void subtraction(long long integer_part_first_fraction, long long numerator_first_fraction, long long denominator_first_fraction,
				 long long integer_part_second_fraction, long long numerator_second_fraction, long long denominator_second_fraction);

void multiplication(long long integer_part_first_fraction, long long numerator_first_fraction, long long denominator_first_fraction,
					long long integer_part_second_fraction, long long numerator_second_fraction, long long denominator_second_fraction);

void division(long long integer_part_first_fraction, long long numerator_first_fraction, long long denominator_first_fraction,
			  long long integer_part_second_fraction, long long numerator_second_fraction, long long denominator_second_fraction);

int fractions();