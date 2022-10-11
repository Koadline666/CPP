
# include "Convert.hpp"
# include <string>


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
	std::size_t last_zero = str.find_first_not_of('0');
	if (std::isdigit(str[last_zero] + 1))
		str.erase(0, std::min(last_zero, str.size() - 1));
	else if (last_zero > 0)
		str.erase(0, std::min(last_zero - 1, str.size() - 1));
	last_zero = str.find_last_not_of('0');
	bool is_float = false;
	if (str[str.size() - 1] == 'f')
	{
		last_zero = str.substr(0, str.size() - 1).find_last_not_of('0');
		is_float = true;
	}
	if (last_zero != std::string::npos && last_zero < str.size() - 1)
	{
		str.erase(last_zero + 2, str.size() - 1);
		std::cout << "STR " << str << std::endl;
		if (is_float)
			str.append("f");
	}
	return(str);
}

bool check_if_char(std::string literal)
{
	if (literal.size() == 1 && !std::isdigit(literal[0]) )
		return (true);
	return (false);
}

// int calc_flow_lvl(std::string literal)
// {
// 	long long check_overflow = std::atoll(literal.c_str());
// 	if (check_overflow > std::numeric_limits<int>::max() || check_overflow > std::numeric_limits<int>::min())

// }

char analise(std::string literal)
{
	literal = trim(literal);
	std::cout << "LITERAL " << literal << std::endl;
	if (check_if_char(literal)) return ('c');

	// int flow_lvl = calc_flow_lvl(literal);
	// else if (check_if_int(literal)) c = 'i';
	// else if (check_if_double(literal) > 0) c = 'd';
	// else if (check_if_float(literal)) c = 'f';
	return 'n';
}

int main( int argc, char** argv )
{
	if (argc != 2)
	{
		std::cout << "ERROR" << std::endl;
		return (1);
	}
	std::cout << "OUTPUT " << analise(argv[1]) << std::endl;
	return (0);
}


