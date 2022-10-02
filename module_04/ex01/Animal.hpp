
#ifndef ANIMAL
# define ANIMAL

# include <iostream>
# include "Brain.hpp"

class Animal
{
	protected:
		std::string type;
		Brain *brain;

	public:
		Animal();
		Animal(std::string type);
		Animal(Animal const & copy);

		void operator= (Animal const & src);

		void setIdea(std::string idea, int number);
		std::string getIdea (int number);
		std::string getType ( void ) const;

		virtual void makeSound( void ) const;

		virtual ~Animal();
};

#endif