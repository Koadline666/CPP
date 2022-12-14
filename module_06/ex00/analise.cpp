#include "conversion.hpp"

std::string trim_whitespace(std::string str)
{
	const std::string WHITESPACE = " \n\r\t\f\v";

	std::size_t start_pos = str.find_first_not_of(WHITESPACE);
	std::size_t end_pos = str.find_last_not_of(WHITESPACE);
	if (start_pos != std::string::npos)
		str = str.substr(0, end_pos + 1).substr(start_pos);
	return (str);
}

std::string trim(std::string str)
{
	str = trim_whitespace(str);
	bool is_float = false;
	bool comma = strchr(str.c_str(), '.');

	if (str[str.size() -1] == 'f')
	{
		str = str.substr(0, str.size() - 1);
		is_float = true;
	}
	while (str[0] == '0' && std::isdigit(str[1]))
		str = str.substr(1);
	while (comma && str[str.size() - 1] == '0' && str[str.size() - 2] != '.')
		str = str.substr(0, str.size() - 1);
	if (is_float)
		str.append("f");
	return(str);
}

bool check_if_char(std::string literal)
{
	if (literal.size() == 1 && !std::isdigit(literal[0]) )
		return (true);
	return (false);
}

bool check_if_int(std::string literal)
{
	const std::string DIGITS = "+-0123456789";

	size_t pos_no_dig = literal.find_last_not_of(DIGITS);
	if(pos_no_dig != std::string::npos && pos_no_dig > 0)
	{
		return (false);
	}
	
	int convert = atoi(literal.c_str());
	if (convert != 0 || (literal.size() == 1 && literal[0] == '0'))
	{
		return (true);
	}
	
	return (false);
}

bool check_if_pseudo_float(std::string literal)
{
	if (literal == "nanf" || literal == "NANF" || literal == "+INFF"
		|| literal == "+inff" || literal== "-inff"|| literal== "-INFF")
		return(true);
	return(false);
}

bool check_if_float(std::string literal)
{
	const std::string DIGITS = "0123456789.f";

	size_t pos_no_dig = literal.find_last_not_of(DIGITS);
	if(pos_no_dig != std::string::npos && pos_no_dig > 0)
		return (false);
	if(literal.find_first_of('f') != (size_t) literal.size() - 1)
		return (false);
	size_t first_comma = literal.find_first_of(".");
	if (first_comma != literal.find_last_of("."))
		return (false);
	if (first_comma == 0 || first_comma == literal.size() - 2)
		return (false);
	
	float convert = atof(literal.c_str());
	if (convert != 0 || ((literal.size() == 4 && literal[0] == '0' && literal[1] == '.' && literal[2] == '0')))
		return (true);
	return (false);
}

bool check_if_pseudo_double(std::string literal)
{
	if (literal == "nan" || literal == "NAN" || literal == "+INF"
		|| literal == "+inf" || literal== "-inf"|| literal== "-INF")
		return(true);
	return(false);
}

bool check_if_double(std::string literal)
{
	const std::string DIGITS = "+-0123456789.";

	size_t pos_no_dig = literal.find_last_not_of(DIGITS);
	if(pos_no_dig != std::string::npos || pos_no_dig == 0 )
		return (false);
	if (literal.find_first_of(".") == std::string::npos)
		return (false);
	size_t first_comma = literal.find_first_of(".");
	if (first_comma != literal.find_last_of("."))
		return (false);
	if (first_comma == 0 || first_comma == literal.size() - 1)
		return (false);
	
	double convert = atof(literal.c_str());
	if (convert != 0 || (literal.size() == 3 && literal[0] == '0' && literal[1] == '.' && literal[2] == '0'))
		return (true);
	return (false);
}

int calc_flow_lvl(std::string literal) // 0 = int | 1 = float | 2 = double | 3 = overflow | 4 pseudo
{
	long double check_overflow = atof(literal.c_str());

	if (check_overflow == std::numeric_limits<double>::infinity() || check_overflow == (std::numeric_limits<double>::infinity()) * -1
		|| check_overflow != check_overflow )
		return(4);
	if (check_overflow > std::numeric_limits<double>::max() || check_overflow < -std::numeric_limits<double>::max())
		return (3);
	if (check_overflow > std::numeric_limits<float>::max() || check_overflow < -std::numeric_limits<float>::max())
		return (2);
	if (check_overflow > std::numeric_limits<int>::max() || check_overflow < -std::numeric_limits<int>::max())
		return (1);
	return (0);
}
char analise(std::string literal, int *flow_lvl)
{
	*flow_lvl = calc_flow_lvl(literal);
	if (check_if_char(literal)) return ('c');
	else if (*flow_lvl <= 0 && check_if_int(literal)) return ('i');
	else if ((*flow_lvl <= 1 && check_if_float(literal)) || (*flow_lvl == 4 && check_if_pseudo_float(literal))) return ('f');
	else if ((*flow_lvl <= 2 && check_if_double(literal)) || *flow_lvl == 4 ) return ('d');
	return ('n');
}