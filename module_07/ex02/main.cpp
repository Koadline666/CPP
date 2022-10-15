# include "Array.hpp"

int main( void )
{
	std::cout << std::endl << "DEFAULT CONSTRUCTOR: " << std::endl;
	Array<int> a;
	std::cout << "size of default is " << a.size() << std::endl;

	std::cout << std::endl << "SIZE CONSTRUCTOR: " << std::endl;
	Array<std::string> string(3);
	std::cout << "size of string array is " << string.size() << std::endl;
	string.setValue("\"this is a string\"", 0);
	string.setValue("\"this is a string .1\"", 1);
	string.setValue("\"this is a string .2\"", 2);

	for(int i = 0; i < string.size(); i++)
		std::cout << string[i] << std::endl;

	std::cout << std::endl << "COPY CONSTRUCTOR:" << std::endl;
	Array<int> x(1);
	x[0] = 1;
	Array<int> y(x);
	std::cout << "BEFORE" << std::endl;
	std::cout << "X: " << x[0] << std::endl;
	std::cout << "Y: " << y[0] << std::endl;
	y[0] = 2;
	std::cout << "AFTER" << std::endl;
	std::cout << "X: " << x[0] << std::endl;
	std::cout << "Y: " << y[0] << std::endl;

	std::cout << std::endl << "OUT OF RANGE EXCEPTION:" << std::endl;
	try
	{
		Array<int> a(1);
		std::cout << a[-1] << std::endl;
		std::cout << a[0] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "\033[0;31m" << e.what() << "\033[0m" << '\n';
	}

	return (0);
}
