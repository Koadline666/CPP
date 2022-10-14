# include <iostream>
# include <cstdlib>
# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

#include <sys/time.h>

int i = 5;
float f = (float)i;

long	get_current_time_ms(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}
Base *generate(void)
{
	int rand = get_current_time_ms() % 3;
	switch (rand)
	{
	case 0:
		return (new A);
	case 1:
		return (new B);
	case 2:
		return (new C);
	}
	return (NULL);
}

void identify(Base *p)
{
	if ((dynamic_cast<A *>(p)))
		std::cout << "A" << std::endl;
	else if ((dynamic_cast<B *>(p)))
		std::cout << "B" << std::endl;
	else if ((dynamic_cast<C *>(p)))
		std::cout << "C" << std::endl;
}
void identify(Base &p)
{
	std::string classes[3] = {"A", "B", "C"};
	
	for (size_t i = 0; i < 3; i++)
	{
		try
		{
			dynamic_cast<A &>(p);
		}
		catch(const std::exception& e)
		{
			continue;
		}
		std::cout << classes[i] << " detected!" << std::endl;
	}
	
	
	
}

int main()
{
	A a;
	B b;
	C c;

	identify(generate());
	identify(a);
	identify(b);
	identify(c);
	return (0);
}