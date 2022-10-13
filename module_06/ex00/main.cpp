#include "conversion.hpp"

int main( int argc, char** argv )
{
	if (argc != 2)
	{
		std::cout << "ERROR" << std::endl;
		return (1);
	}
	convert(argv[1]);
	return (0);
}

