
# include "Convert.hpp"

Convert::Convert() {}

Convert::Convert(Convert const & copy)
{
	*this = copy;
}

Convert::Convert(std::string input)
{
	literal = trim_whitespace(input);
}

Convert &Convert::operator= (Convert const & src)
{
	if (this == &src)
		return (*this);
	return (*this);
}

Convert::~Convert() {}

void Convert::print_types( void )
{
	std::cout << "char: '" << char_c << "'" << std::endl;
	std::cout << "int: " << int_c <<  std::endl;
	std::cout << "float: " << float_c << "f" << std::endl;
	std::cout << "double: " << double_c << std::endl;
}