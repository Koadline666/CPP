#include "conversion.hpp"

int main( int argc, char** argv )
{
	if (argc != 2)
	{
		std::cout << "ERROR" << std::endl;
		return (1);
	}
	char type = analise(argv[1]);
	char c;
	int i;
	float f;
	double d;
	int flowLvl = calc_flow_lvl(argv[1]);
	switch (type)
	{
		case 'c':
		{
			c = argv[1][0];
			i = (int) c;
			f = (float) c;
			d = (double) c;
			break;
		}
		case 'i':
		{
			i = atoi(argv[1]);
			c = (char) i;
			f = (float) i;
			d = (double) i;
		}
		case 'f':
		{
			f = atof(argv[1]);
			i = (int) f;
			c = (char) f;
			d = (double) f;
		}
		case 'd':
		{
			d = atof(argv[1]);
			c = (char) d;
			f = (float) d;
			i = (int) d;
		}
	}
	bool pseudo =  false;
	std::string input = trim(argv[1]);
	if (check_if_pseudo_double(input) || check_if_pseudo_float(input))
		pseudo = true;
	std::cout << type << std::endl;
	std::cout << "char: ";
	if ((i < 0 || i > 127) || type == 'n' || pseudo)
		std::cout << "impossible" << std::endl;
	else 
		std::cout << c << std::endl;

	std::cout << "int: ";
	if (flowLvl <= 0 && type != 'n' && !pseudo)
 		std::cout << i << std::endl;
	else
		std::cout << "impossible" << std::endl;
	
	std::cout << "float: ";
	if (flowLvl <= 1 && type != 'n')
		std::cout << f << "f" << std::endl;
	else
		std::cout << "impossible" << std::endl;

	std::cout << "double: ";
	if (flowLvl <= 2 && type != 'n')
		std::cout << d << std::endl;
	else
		std::cout << "impossible" << std::endl;
	return (0);
}

