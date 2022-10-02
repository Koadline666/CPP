
# include "WrongCat.hpp"

WrongCat::WrongCat()
{
	this->type = "WrongCat";
	std::cout << "Wrong" << this->type << " has been created." << std::endl;
}

WrongCat::WrongCat(WrongCat const & copy)
{
	*this = copy;
	std::cout << "Wrong" << this->type << " has been created. --> Copy" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "Wrong" << this->type << " has been destroyed." << std::endl;
}

void	WrongCat::operator= (WrongCat const & src)
{
	this->type = src.type;
}

// void	WrongCat::makeSound( void ) const
// {
// 	std::cout << "* unidentifiable WrongAnimal sound *" << std::endl;
// }
