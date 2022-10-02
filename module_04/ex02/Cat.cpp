
# include "Cat.hpp"

Cat::Cat(): Animal("Cat")
{
	std::cout << this->type << " has been created." << std::endl;
}

Cat::Cat(Cat const & copy): Animal(copy)
{
	std::cout << this->type << " has been created. --> Copy" << std::endl;
}

Cat::~Cat()
{
	std::cout << this->type << " has been destroyed." << std::endl;
}

void	Cat::operator= (Cat const & src)
{
	this->type = src.type;
	this->brain->setIdeas(src.brain->getIdeas());
}

void	Cat::makeSound( void ) const
{
	std::cout <<"meow meow" << std::endl;
}