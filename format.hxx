
#include <string>

namespace pad{
	void inline left(std::string &str, const char padding , const size_t padding_amount){
		while(padding_amount > str.size()){
			str = padding + str;
		}
	}

	void inline right(std::string &str, const char padding, const size_t padding_amount){
		while(padding_amount > str.size()){
			str += padding ;
		}
	}

	void inline center(std::string &str, const char padding, const size_t padding_amount){
		while(padding_amount > str.size()){
			str += padding;
			str = padding + str;
		}
	}

};

namespace format{
	typedef const char *ANSI;

	static ANSI clear			= "\033[0m";
	static ANSI reset   	    = "\033[0m";

	//Text styling
	static ANSI bold			="\033[1m";
	static ANSI dim				="\033[2m";
	static ANSI italic			="\033[3m";
	static ANSI underline		="\033[4m";
	static ANSI blink			="\033[5m";
	static ANSI invert			="\033[7m";
	static ANSI hidden			="\033[8m";

	//Foreground
	static ANSI fg_black		="\033[30m";
	static ANSI fg_red			="\033[31m";
	static ANSI fg_green		="\033[32m";
	static ANSI fg_yellow		="\033[33m";
	static ANSI fg_blue			="\033[34m";
	static ANSI fg_magenta		="\033[35m";
	static ANSI fg_cyan			="\033[36m";
	static ANSI fg_white		="\033[37m";

	//Background
	static ANSI bg_black		="\033[40m";
	static ANSI bg_red			="\033[41m";
	static ANSI bg_green		="\033[42m";
	static ANSI bg_yellow		="\033[43m";
	static ANSI bg_blue			="\033[44m";
	static ANSI bg_magenta		="\033[45m";
	static ANSI bg_cyan			="\033[46m";
	static ANSI bg_white		="\033[47m";

	typedef std::string formated_string;

	inline formated_string format_string(std::string_view unformated_string, std::initializer_list<ANSI> formats){
		formated_string fs; fs.reserve(formats.size() * 5 + unformated_string.length());
		for (ANSI string_format: formats)
			fs += (string_format);
		fs.append(unformated_string);
		return fs;
	}

	inline void uppercase(std::string &str){
		auto start = str.cbegin();
		for(size_t i = 0; i < str.size(); i++){
			if(str[i] >= 'a' && str[i] <= 'z'){
				// 32 = 'a' - 'A', shift down by 32 to get uppercase
				str[i] = str[i] - 32;
			}
		}
	}

	inline void lowercase(std::string &str){
		auto start = str.cbegin();
		for(size_t i = 0; i < str.size(); i++){
			if(str[i] >= 'A' && str[i] <= 'Z'){
				// 32 = 'a' - 'A', shift up by 32 to get lowercase
				str[i] = str[i] + 32;
			}
		}
	}

};
