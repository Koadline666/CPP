
# include "Cure.hpp"

Cure::Cure():AMateria("cure") {}

Cure(const Cure & copy)
{
	
}

void operator=(const Cure & src)
{

}

virtual AMateria* clone() const;

~Cure();