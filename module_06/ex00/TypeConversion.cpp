
# include "Convert.hpp"

void Convert::convert_to_types( void )
{
	std::cout << "literal is " << literal << " and base type is " << base_type << std::endl;
	if (base_type == 'c')
		char_c = literal[0];
	else if (base_type == 'i')
		int_c = std::atoi(literal.c_str());
	else if (base_type == 'f')
		float_c = std::atof(literal.c_str());
	else if (base_type == 'd')
		double_c = std::stof(literal.c_str());

}