## Lightweight Quick String Formatter and ANSI esc

Include the headerfile and use the namespace to assist formating console output.

- Namespace pad
    Use this leftpad, rightpad or center a std::string, doesnt support construction a strirng from const char * since it directly modifies the string to pad it.

- Namespace format
    Has a typedef ANSI which is a simplified version of the 4~5 const char * used for ANSI escaping. It also contains its own predefined constants for standard ANSI
    such as bold, blink, underline and colors for setting the background (terminal color) and (foreground) text color.
    It also has a utility function that returns a string from a const char * with required formating.

- NOTE, clear and reset are the same ANSI value used to clear formatting from the terminal, be sure to input them into streams/strings when you done with the formatting.
- formated_string is just a typedef for std::string for conviniece.

- supports uppercase and lowercase for strings, directly modifies the passed in string.

## Example
- formated_string fs = format::format_string("Bold and underlind", {format::bold, format::underlind}).
  will return a string that is bold and underlined when rendered in the terminal.
- std::cout << " Formatted string: " << fs << format::clear << std::endl;
