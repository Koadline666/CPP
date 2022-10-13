#include "conversion.hpp"

int main( int argc, char** argv )
{
	if (argc != 2)
	{
		std::cout << "ERROR" << std::endl;
		return (1);
	}
	char type = analise(argv[1]);
	if (type == 'c')
	{
		
	}
	return (0);
}


