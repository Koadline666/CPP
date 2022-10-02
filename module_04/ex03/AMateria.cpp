
#include "AMateria.hpp"

AMateria::AMateria(): type_("cure") {}

AMateria::AMateria(std::string const & type): type_(type) {}

AMateria::AMateria(const AMateria & copy): type_(copy.getType()) {}

void AMateria::operator= (const AMateria & src)
{
	type_ = src.getType();
}

std::string const & AMateria::getType() const
{
	return (type_);
}

void AMateria::use(ICharacter& target)
{
	if (type_ == "ice")
		std::cout << "* shoots an ice bolt at " << target << " *" << std::endl;
	else if (type_ == "cure")
		std::cout << "* heals " << target << "'s wounds *" << std::endl;
}