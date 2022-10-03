#ifndef CHARACTER
# define CHARACTER

# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character: public ICharacter
{
	protected:
		int	equiped_materia_;
		std::string	name_;
		AMateria*	materias[4];

	public:
		Character();
		Character(std::string name);
		Character(const Character & copy);

		Character &operator= (const Character & src);

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		void print_materias(void);
		
		~Character();
};

#endif