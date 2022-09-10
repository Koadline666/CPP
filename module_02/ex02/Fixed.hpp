/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 14:26:58 by afenzl            #+#    #+#             */
/*   Updated: 2022/09/10 16:58:17 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int						fix_point;
		static const int literal = 8;
	public:

		Fixed();
		Fixed(const int integer);
		Fixed(const Fixed &fix);
		Fixed(const float n);

		int		getRawBits( void ) const;
		void	setRawBits(int const raw);
		float	toFloat( void ) const;
		int		toInt( void ) const;

		static Fixed&	min(const Fixed& fix1, const Fixed& fix2);


		// ******************* operator overloads: ********************
		// constructor overload
		void	operator = (const Fixed &fix);
		// output overload
		friend	std::ostream&	operator <<(std::ostream& output, const Fixed& fix);
		// comparison overloads
		bool	operator < (const Fixed &fix);
		bool	operator > ( Fixed &fix);
		bool	operator <= (Fixed &fix);
		bool	operator >= (Fixed &fix);
		bool	operator == (const Fixed &fix);
		bool	operator != (Fixed &fix);
		// binary arithmetic overloads
		float	operator + (const Fixed &fix);
		float	operator - (const Fixed &fix);
		float	operator * (const Fixed &fix);
		float	operator / (const Fixed &fix);
		// increment and decrement overloads
		float		operator ++ ( void );
		float		operator -- ( void );
		float		operator ++ ( int );
		float		operator -- ( int );

		~Fixed();
};

#endif