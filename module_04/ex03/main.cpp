
# include "Character.hpp"
# include "Ice.hpp"
# include "Cure.hpp"
# include "MateriaSource.hpp"

int main( void )
{
	std::cout << "Test 1\n" << std::endl;
	{
		Character mark("mark");
		AMateria* ice = new Ice();

		mark.equip(ice);
		mark.use(0, mark);

		delete ice;
	}
	std::cout << "\n\n" << "Test 2\n" << std::endl;
	{
		Character dank("dank");
		Character frank("frank");
		AMateria* c = new Cure();
		frank.equip(c);
		frank.use(0, dank);
		frank.unequip(1);
		frank.unequip(0);
		frank.use(0, dank);

		delete c;
	}
	std::cout << "\n\n" << "Test 3\n" << std::endl;
	{
		AMateria* i = new Ice();
		AMateria* clone = (*i).clone();
		std::cout << clone->getType() << std::endl;
	
		delete i;
		delete clone;
	}
	std::cout << "\n\n" << "Test 4\n" << std::endl;
	{
		AMateria* i = new Ice();
		Character* jef = new Character("jef");
		jef->equip(i);
		Character* jef_v2 = new Character(*jef);

		std::cout << std::endl;
		jef->use(0, *jef_v2);
		jef_v2->use(0, *jef);

		jef->unequip(0);

		jef->use(0, *jef_v2);
		jef_v2->use(0, *jef);
		std::cout << std::endl;

		delete jef;
		delete jef_v2;
		delete i;
	}
	std::cout << "\n\n" << "Test 5\n" << std::endl;
	{
		MateriaSource whatever;
		AMateria* i = new Ice();

		whatever.learnMateria(i);

		delete i;
	}
	std::cout << "\n\n" << "Test 6\n" << std::endl;
	{
		MateriaSource source;
		AMateria* i = new Ice();

		source.learnMateria(i);
		AMateria* copy = source.createMateria("ice");
		std::cout << "Type with 'ice' " << copy->getType() << std::endl;
		delete copy;
		copy = source.createMateria("testing");
		if (!copy)
			std::cout << "copy was not created because no type has string 'testing'" << std::endl;
		delete i;
	}
	std::cout << "\n\n" << "Test 7\n" << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
	}

	system ("leaks ex03");

	return (0);
}

