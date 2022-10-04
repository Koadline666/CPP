# include "Cure.hpp"

//  -------------- CONSTRUCTORS & DESTRUCTOR ----------------

Cure::Cure()
{
	std::cout << "Cure has been created." << std::endl;
	this->type_ = "cure";
}

Cure::Cure(AMateria const & copy)
{
	std::cout << "Copy constructor for Cure called" << std::endl;
	*this = copy;
}

Cure::~Cure(){ std::cout << "Cure has been destroyed!" << std::endl; }

Cure &Cure::operator=(AMateria const & src)
{
	if (this == &src)
		return (*this);
	return( *this);
}

//  -------------- METHODS ----------------

AMateria* Cure::clone() const
{
	return (new Cure());
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
