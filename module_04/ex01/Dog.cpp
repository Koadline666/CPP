
# include "Dog.hpp"


//  -------------- CONSTRUCTORS & DESTRUCTOR ----------------
Dog::Dog(): Animal("Dog")
{
	std::cout << this->type << " has been created." << std::endl;
}

Dog::Dog(Animal const & copy): Animal(copy)
{
	std::cout << this->type << " has been created. --> Copy" << std::endl;
}

Dog::~Dog()
{
	std::cout << this->type << " has been destroyed." << std::endl;
}

//  ----------------------- OPERATOR OVERLOAD -------------
void	Dog::operator= (Animal const & src)
{
	this->type = src.getType();
	this->brain = src.getBrain();
}

//  ----------------------- METHODS -----------------------
void	Dog::makeSound( void ) const
{
	std::cout << "wuff wuff" << std::endl;
}