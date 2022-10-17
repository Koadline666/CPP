# include "easyfind.hpp"
# include <vector>

int main(void)
{
	std::vector<int> vect;
	std::vector<int>::iterator it;

	vect.push_back(-1);
	vect.push_back(98);
	vect.push_back(201);
	vect.push_back(1);
	vect.push_back(7);
	vect.push_back(61);

	try
	{
		std::cout << "<<<<<<<<<<< PRINTING VALUES >>>>>>>>>>>>>>" << std::endl;
		for(unsigned long i = 0; i < vect.size(); i++)
		std::cout << vect[i] << ",  ";
		std::cout << std::endl;

		std::cout << std::endl << "<<<<<<<<<<< FINDING VALUE  >>>>>>>>>>>>>>>" << std::endl;
		it = easyfind(vect, 201);
		std::cout << "the found value is " << *it << std::endl;

		std::cout << std::endl << "<<<<<<<<< NOT FINDING VALUE  >>>>>>>>>>>>>" << std::endl;
		it = easyfind(vect, 888);
		std::cout << "the found value is " << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	


	return (0);
}