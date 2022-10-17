#ifndef EASYFIND_TPP
# define EASYFIND_TPP

# include "easyfind.tpp"
# include <exception>
# include <algorithm>

class NotFoundException: public std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return ("Not found");
		}
};

template<class T> typename T::iterator easyfind(T container, int search)
{
	typename T::iterator it = find(container.begin(), container.end(), search);
	if (it == container.end())
		throw NotFoundException();
	return(it);
}

#endif