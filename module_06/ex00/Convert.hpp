#ifndef CONVERT
# define CONVERT

# include <iostream>
# include <cctype>
# include <string>
# include <cstdlib>
# include <stdlib.h>

class Convert
{
	private:
		std::string literal;

		int		int_c;
		float	float_c;
		double	double_c;
		char	char_c;

		std::string	error;

		char	base_type;

		static std::string trim_whitespace(std::string str);

	public:
		Convert();
		Convert(std::string input);
		Convert(Convert const & copy);

		Convert &operator=(Convert const & src);

		char detect_type( void );
		void convert_to_types( void );
		void print_types( void );

		static char detect_type(std::string literal);


		~Convert();
};

#endif