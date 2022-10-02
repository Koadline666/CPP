
#include "Animal.hpp"

//  -------------- CONSTRUCTORS & DESTRUCTOR ----------------

Animal::Animal()
{
	this->type = "not defined Animal";
	std::cout << "Animal has been created." << std::endl;
	this->brain = new Brain();
}

Animal::Animal(std::string type): type(type)
{
	this->brain = new Brain();
	std::cout << "Animal has been created." << std::endl;
}

Animal::Animal(Animal const & copy)
{
	*this = copy;
	std::cout << "Animal has been created. --> Copy" << std::endl;
}

Animal::~Animal()
{
	delete this->brain;
	std::cout << "Animal has been destroyed." << std::endl;
}

//  ----------------------- OPERATOR OVERLOAD -------------

void	Animal::operator= (Animal const & src)
{
	this->type = src.type;
	this->brain = new Brain(*src.brain);
}

//  ----------------------- METHODS -----------------------

std::string	Animal::getType( void) const { return (this->type); }

void Animal::setIdea(std::string idea, int number)
{
	brain->setIdea(number, idea);
}

std::string Animal::getIdea (int number)
{
	return (brain->getIdea(number));
}

void	Animal::makeSound( void ) const
{
	std::cout << "* unidentifiable animal sound *" << std::endl;
}

