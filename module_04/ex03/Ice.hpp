#ifndef ICE
# define ICE

# include "AMateria.hpp"

class Ice: public AMateria
{
	public:
		Ice();
		Ice(Ice const & copy);

		Ice &operator=(Ice const & src);

		AMateria* clone() const;
		void use(ICharacter& target);

		~Ice();
};

#endif