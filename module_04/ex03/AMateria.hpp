#ifndef AMATERIA
# define AMATERIA

# include <iostream>

class AMateria
{
	protected:
		static const std::string	type_;

	public:
		AMateria();
		AMateria(std::string const & type);
		AMateria(const AMateria & copy);
		
		void operator= (const AMateria & src);

		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		// virtual void use(ICharacter& target);

		virtual ~AMateria();
};

#endif