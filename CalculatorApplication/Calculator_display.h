#pragma once

#include <sstream>

class Calculator_display
{
	std::ostringstream menu_text;
public:
	Calculator_display();

	int bufferinfo(int& width, int& height);
	void print_headline();
	void print_menu();
	void print_thanks_for_using();
	void clear_screen();
};

