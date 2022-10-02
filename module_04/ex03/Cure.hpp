

#ifndef CURE
# define CURE

# include "AMateria.hpp"

class Cure: public AMateria
{
	public:
		Cure();
		Cure(const Cure & copy);

		void operator=(const Cure & src);

		AMateria* clone() const;

		~Cure();
};

#endif
