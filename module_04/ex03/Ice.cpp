# include "Ice.hpp"

//  -------------- CONSTRUCTORS & DESTRUCTOR ----------------

Ice::Ice()
{
	std::cout << "Ice has been created." << std::endl;
	this->type_ = "ice";
}

Ice::Ice(Ice const & copy)
{
	std::cout << "Copy constructor for Ice called" << std::endl;
	*this = copy;
	return;
}

Ice::~Ice(){ std::cout << "Ice has been destroyed!" << std::endl; }


Ice &Ice::operator=(Ice const & src)
{
	if (this == &src)
		return (*this);
	return( *this);
}

//  -------------- METHODS ----------------

AMateria* Ice::clone() const
{
	return (new Ice());
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
