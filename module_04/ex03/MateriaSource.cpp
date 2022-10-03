
# include "MateriaSource.hpp"

//  -------------- CONSTRUCTORS & DESTRUCTOR ----------------

MateriaSource::MateriaSource(): materias_learned(0)
{
	std::cout << "MateriaSource created." << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const & copy)
{
	std::cout << "MateriaSource created. --> Copy" << std::endl;
	*this = copy;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < materias_learned; i++)
		delete this->materias[i];

	std::cout << "MateriaSource destroyed." << std::endl;
}

//  -------------- OPERATOR OVERLOAD ----------------

MateriaSource &MateriaSource::operator= (MateriaSource const & src)
{
	this->materias_learned = src.materias_learned;
	for (int i = 0; i < materias_learned; i++)
		this->materias[i] = src.materias[i]->clone();
	return(*this);
}

//  -------------- METHODS ----------------

void MateriaSource::learnMateria(AMateria* m)
{
	if (this->materias_learned >= 4)
	{
		std::cout << "MaterialSource has a full inventory" << std::endl;
		return ;
	}

	this->materias[this->materias_learned] = m->clone();
	this->materias_learned++;
	std::cout << "MateriaSource learned " << m->getType() << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for(int i = materias_learned - 1; i >= 0; i--)
	{
		if (materias[i]->getType() == type)
			return(materias[i]->clone());
	}
	return(NULL);
}