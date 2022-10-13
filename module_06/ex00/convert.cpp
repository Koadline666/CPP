# include "conversion.hpp"

void print_char(char c, int i, bool pseudo, bool no_type)
{
	std::cout << "char: ";
	if ((i < 0 || i > 127) || !no_type || pseudo)
		std::cout << "impossible" << std::endl;
	else if (!std::isprint(c))
		std::cout << "Non displayable" << std::endl;
	else 
		std::cout << "'" << c << "'" << std::endl;
}

void print_int(int i, int flow_lvl, bool pseudo, bool no_type)
{
	std::cout << "int: ";
	if (flow_lvl <= 0 && no_type && !pseudo)
 		std::cout << i << std::endl;
	else
		std::cout << "impossible" << std::endl;
}

void print_float(float f, int flow_lvl, bool no_type)
{
	float dec = f - roundf(f);
	if (dec < 0)
		dec = 1.0f + dec;
	std::cout << "float: ";
	if ((flow_lvl <= 1 && no_type) || (flow_lvl == 4 && no_type))
	{
		std::cout << f ;
		if ((dec == 0 && f < 1000000 && f > -1000000))
			std::cout << ".0";
		std::cout << "f" << std::endl;
	}
	else
		std::cout << "impossible" << std::endl;

}

void print_double(double d, int flow_lvl, bool no_type)
{
	double dec = d - roundf(d);
	if (dec < 0)
		dec = 1.0 + dec;
	std::cout << "double: ";
	if ((flow_lvl <= 2 && no_type)|| (flow_lvl == 4 && no_type))
	{
		std::cout << d;
		if ((dec == 0 && d < 1000000 && d > -1000000))
			std::cout << ".0";
		std::cout << std::endl;
	}
	else
		std::cout << "impossible" << std::endl;
}

void print(char c, int i, float f, double d, int flow_lvl, std::string literal, bool no_type)
{

	bool pseudo =  false;
	if (check_if_pseudo_double(literal) || check_if_pseudo_float(literal))
		pseudo = true;
	print_char(c, i, pseudo, no_type);
	print_int(i, flow_lvl, pseudo, no_type);
	print_float(f, flow_lvl, no_type);
	print_double(d, flow_lvl, no_type);
}

void convert(std::string literal)
{
	int flow_lvl;
	literal = trim(literal);
	char type = analise(literal, &flow_lvl);
	std::cout << "TYPE " << type << std::endl;
	char c;
	int i;
	float f;
	double d;
	switch (type)
	{
		case 'c':
		{
			c = literal[0];
			i = (int) c;
			f = (float) c;
			d = (double) c;
			break;
		}
		case 'i':
		{
			i = atoi(literal.c_str());
			c = (char) i;
			f = (float) i;
			d = (double) i;
		}
		case 'f':
		{
			f = atof(literal.c_str());
			i = (int) f;
			c = (char) f;
			d = (double) f;
		}
		case 'd':
		{
			d = atof(literal.c_str());
			c = (char) d;
			f = (float) d;
			i = (int) d;
		}
	}
	bool no_type = true;
	if (type == 'n')
		no_type = false;
	print(c, i, f, d, flow_lvl, literal, no_type);
}