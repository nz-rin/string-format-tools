#include <iostream>

#include "format.hxx"

int main(){
	std::string  str = "Hello world";

	pad::left(str, ' ', strlen("Run successfull"));
	std::cout << format::format_string(str, {format::underline, format::fg_yellow}) << format::clear<< '\n';
	std::cout << format::bold << format::fg_green << "Run successfull" << format::clear << std::endl;
	return 0;
}
