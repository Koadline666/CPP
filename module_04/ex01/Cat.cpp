
# include "Cat.hpp"


//  -------------- CONSTRUCTORS & DESTRUCTOR ----------------
Cat::Cat(): Animal("Cat")
{
	std::cout << this->type << " has been created." << std::endl;
}

Cat::Cat(Animal const & copy): Animal(copy)
{
	std::cout << this->type << " has been created. --> Copy" << std::endl;
}

Cat::~Cat()
{
	std::cout << this->type << " has been destroyed." << std::endl;
}

//  ----------------------- OPERATOR OVERLOAD -------------
void	Cat::operator= (Animal const & src)
{
	this->type = src.getType();
	this->brain = src.getBrain();
}

//  ----------------------- METHODS -----------------------
void	Cat::makeSound( void ) const
{
	std::cout <<"meow meow" << std::endl;
}