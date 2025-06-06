#include <iostream>

#include "format.hxx"

int main(){
	std::string  str = "Hello world";
	std::string  end = "Run successfull";

	pad::left(str, ' ', end.size());
	format::uppercase(end);
	std::cout << format::format_string(str, {ANSI_UNDERLINE, ANSI_FG_YELLOW}) << ANSI_CLEAR<< '\n';
	std::cout << ANSI_BOLD << ANSI_FG_GREEN << end << ANSI_CLEAR << std::endl;
	return 0;
}
