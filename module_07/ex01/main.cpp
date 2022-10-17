# include "iter.hpp"
# include <stdlib.h>
# include <sstream>

void print_int(const int &i)
{
	std::cout << "'" << i << "'" << std::endl;
}

void print_str(const std::string &str)
{
	std::cout << "\"" << str << "\"" << std::endl;
}

int main( void )
{
	int len = 5;
	int int_array[len];

	for(int i = 0; i < len; i++)
		int_array[i] = i;
	
	::iter(int_array, len, print_int);

	std::string string_array[len];

	for(int i = 0; i < len; i++)
	{
		std::ostringstream sstream;
		sstream << "-String-" << i;
		string_array[i] = sstream.str();
	}

	::iter(string_array, len, print_str);

	std::cout << std::endl << "instantiated function template " << std::endl;
	::iter(int_array, len, print_whatever);
	::iter(string_array, len, print_whatever);

	return (0);
}

// class Awesome
// {
//   public:
//     Awesome( void ) : _n( 42 ) { return; }
//     int get( void ) const { return this->_n; }
//   private:
//     int _n;
// };

// std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

// template< typename T >
// void print( T const & x ) { std::cout << x << std::endl; return; }

// int main() {
//   int tab[] = { 0, 1, 2, 3, 4 };  // <--- I never understood why you can't write int[] tab. Wouldn't that make more sense?
//   Awesome tab2[5];

//   iter( tab, 5, print<int> );
//   iter( tab2, 5, print<Awesome> );

//   return 0;
// }
