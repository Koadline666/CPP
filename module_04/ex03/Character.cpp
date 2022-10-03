
#include "Character.hpp"


//  ----------- CONSTRUCTORS & DESTRUCTOR -----------
 
Character::Character(): equiped_materia_(0), name_("Randy")
{
	std::cout << "Character " << name_ << " created. --> Default" << std::endl;
}

Character::Character(std::string name): equiped_materia_(0), name_(name)
{
	std::cout << "Character " << name_ << " created." << std::endl;
}


Character::Character(const Character & copy): equiped_materia_(0)
{
	std::cout << "Character " << name_ << " created. -->Copy" << std::endl;
	*this = copy;
}

Character::~Character() 
{
	for (int i = 0; i < this->equiped_materia_; i++)
		delete this->materias[i];
	std::cout << "Character " << name_ << " destroyed." << std::endl;
}

//  -------------- OPERATOR OVERLOAD ----------------

Character & Character::operator= (const Character & src)
{
	this->name_ = src.name_;
	for (int i = 0; i < this->equiped_materia_; i++)
		delete this->materias[i];

	for (int i = 0; i < src.equiped_materia_; i++)
		this->equip(src.materias[i]);
	return (*this);
}

//  -------------- GETTERS --------------------------

std::string const & Character::getName() const
{
	return (name_);
}

void Character::equip(AMateria* m)
{
	if (this->equiped_materia_ >= 4)
	{
		std::cout << name_ << " has a full inventory" << std::endl;
		return ;
	}

	this->materias[this->equiped_materia_] = m->clone();
	this->equiped_materia_++;
	std::cout << name_ << " equiped " << m->getType() << std::endl;
}

void Character::unequip(int idx)
{
	if (idx >= this->equiped_materia_ || idx < 0)
	{
		std::cout << name_ << " couldn't unequip" << std::endl;
		return ;
	}
	
	std::cout << name_ << " unequiped " << this->materias[idx]->getType() << std::endl;
	this->materias[idx] = NULL;
	this->equiped_materia_--;
	for (int i = idx; i < this->equiped_materia_; i++)
	{
		this->materias[i] = this->materias[i + 1];
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= this->equiped_materia_ || idx < 0)
	{
		std::cout << name_ << " couldn't use Materia on " << target.getName() << std::endl;
		return ;
	}

	this->materias[idx]->use(target);
}

