
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

	#define ANSI_CLEAR			 "\033[0m"
	#define ANSI_RESET   	     "\033[0m"

	//Text sTYLING
	#define ANSI_BOLD			"\033[1m"
	#define ANSI_DIM			"\033[2m"
	#define ANSI_ITALIC			"\033[3m"
	#define ANSI_UNDERLINE		"\033[4m"
	#define ANSI_BLINK			"\033[5m"
	#define ANSI_INVERT			"\033[7m"
	#define ANSI_HIDDEN			"\033[8m"

	//ForegrOUND
	#define ANSI_FG_BLACK		"\033[30m"
	#define ANSI_FG_RED			"\033[31m"
	#define ANSI_FG_GREEN		"\033[32m"
	#define ANSI_FG_YELLOW		"\033[33m"
	#define ANSI_FG_BLUE		"\033[34m"
	#define ANSI_FG_MAGENTA		"\033[35m"
	#define ANSI_FG_CYAN		"\033[36m"
	#define ANSI_FG_WHITE		"\033[37m"

	//BackgrOUND
	#define ANSI_BG_BLACK		"\033[40m"
	#define ANSI_BG_RED			"\033[41m"
	#define ANSI_BG_GREEN		"\033[42m"
	#define ANSI_BG_YELLOW		"\033[43m"
	#define ANSI_BG_BLUE		"\033[44m"
	#define ANSI_BG_MAGENTA		"\033[45m"
	#define ANSI_BG_CYAN		"\033[46m"
	#define ANSI_BG_WHITE		"\033[47m"

	typedef std::string formated_string;

	inline formated_string format_string(std::string_view unformated_string, std::initializer_list<ANSI> formats){
		formated_string fs; fs.reserve(formats.size() * 5 + unformated_string.length());
		for (ANSI string_format: formats)
			fs += (string_format);
		fs.append(unformated_string);
		return fs;
	}

	inline void uppercase(std::string &str){
		for(size_t i = 0; i < str.size(); i++){
			if(str[i] >= 'a' && str[i] <= 'z'){
				// 32 = 'a' - 'A', shift down by 32 to get uppercase
				str[i] = str[i] - 32;
			}
		}
	}

	inline void lowercase(std::string &str){
		for(size_t i = 0; i < str.size(); i++){
			if(str[i] >= 'A' && str[i] <= 'Z'){
				// 32 = 'a' - 'A', shift up by 32 to get lowercase
				str[i] = str[i] + 32;
			}
		}
	}

};
