# include "iter.hpp"
# include <stdlib.h>
# include <sstream>

void print_int(const int &i)
{
	std::cout << "'" << i << "'" << std::endl;
}

void print_str(const std::string &str)
{
	std::cout << "\"" << str << "\"" << std::endl;
}

int main( void )
{
	int len = 5;
	int int_array[len];

	for(int i = 0; i < len; i++)
		int_array[i] = i;
	
	::iter(int_array, len, print_int);

	std::string string_array[len];

	for(int i = 0; i < len; i++)
	{
		std::ostringstream sstream;
		sstream << "-String-" << i;
		string_array[i] = sstream.str();
	}

	::iter(string_array, len, print_str);

	std::cout << std::endl << "instantiated function template " << std::endl;
	::iter(int_array, len, print_whatever);
	::iter(string_array, len, print_whatever);

	return (0);
}

