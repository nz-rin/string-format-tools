#include <iostream>

#include "format.hxx"

int main(){
	std::string  str = "Hello world";
	std::string  end = "Run successfull";

	pad::left(str, ' ', end.size());
	format::uppercase(end);
	std::cout << format::format_string(str, {format::underline, format::fg_yellow}) << format::clear<< '\n';
	std::cout << format::bold << format::fg_green << end << format::clear << std::endl;
	return 0;
}
