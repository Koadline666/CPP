#include "Convert.hpp"





int check_pseudo_double(std::string literal)
{
	if (literal == "nan" || literal == "NaN" || literal == "NAN") return(1);
	if (literal == "-inf" || literal == "-INF") return(2);
	if (literal == "+inf" || literal == "+INF") return(3);
	return (0);
}

int check_pseudo_float(std::string literal)
{
	if (literal == "nanf" || literal == "NaNf" || literal == "NaNF" || literal == "NANF") return(1);
	if (literal == "-inff" || literal == "-INFF") return(2);
	if (literal == "+inff" || literal == "+INFF") return(3);
	return (0);
}

int check_if_double(std::string literal)
{
	if (check_pseudo_double(literal) > 0)
		return (-1);
	size_t i = 0;
	if (literal[i] == '+' || literal[i] == '-')
		i++;
	while(literal[i] == 0)
		i++;
	int found_point = 0;
	if (literal[i] == '.')
		return (-1);
	// while(literal[i] == '0')
	// 	i++;
	int dig_length = 0;
	while(isdigit(literal[i]) || literal[i] == '.')
	{
		if (literal[i] == '.' && literal[i + 1] != '\0')
			found_point++;
		i++;
		dig_length++;
	}
	if (found_point == 1 && i == literal.size() && isdigit(literal[i - 1]) && dig_length < 20)
		return (dig_length);
	return (-1);
}

bool check_if_float(std::string literal)
{
	if (check_pseudo_float(literal) > 0)
		return (true);
	if (literal[literal.size() - 1] == 'f')
	{
		literal = literal.substr(0, literal.size() - 1);
		int check = check_if_double(literal);
		if (check < 10 && check > -1)
			return (true);
	}
	return (false);
}

bool check_if_int(std::string literal)
{
	const std::string DIGITS = "0123456789";

	size_t end_pos = literal.find_last_not_of(DIGITS);
	if (end_pos != std::string::npos && end_pos > 0)
		return (false);
	
	long long overflow = std::atoll(literal.c_str());
	if (overflow < std::numeric_limits<int>::min() || overflow > std::numeric_limits<int>::max())
		return(false);
	
	int res = std::atoi(literal.c_str());
	if (res != 0 || (literal.size() == 1 && literal[0] == '0'))
		return (true);
	
	return (false);
}

char Convert::detect_type( std::string literal )
{
	literal = trim_whitespace(literal);
	if (check_if_char(literal)) return ('c');
	if (check_if_int(literal)) return ('i');
	if (check_if_double(literal) > 0) return ('d');
	if (check_if_float(literal)) return ('f');
	return('n');
}

char Convert::detect_type( void )
{
	char c;
	if (check_if_char(literal)) c = 'c';
	else if (check_if_int(literal)) c = 'i';
	else if (check_if_double(literal) > 0) c = 'd';
	else if (check_if_float(literal)) c = 'f';
	else
		c = 'n';
	base_type = c;
	return(c);
}