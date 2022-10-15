#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <class T> void print_whatever(T whatever)
{
	std::cout << "-->" << whatever << "<--" << std::endl;
}

template <class T> void iter(T *a, int len, void(*func)(const T t))
{
	if (!a || len <= 0)
		return ;
	for (int i  = 0; i < len; i++)
		func(a[i]);
}

#endif