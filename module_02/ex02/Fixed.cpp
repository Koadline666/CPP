/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 14:29:24 by afenzl            #+#    #+#             */
/*   Updated: 2022/09/10 16:58:25 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int high(int i, int e)
{
	int n = 1;

	while (e--)
		n *= i;
	return (n);
}

// constructor
Fixed::Fixed()
{
	std::cout << "Default constructor called\n";

	this->fix_point = 0;
}

Fixed::Fixed(const Fixed &fix)
{
	std::cout << "Copy constructor called\n";
	
	*this = fix;
}


Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called\n";
	
	this->fix_point = n * high(2, this->literal);
}

Fixed::Fixed(const float n)
{
	std::cout << "Float constructor called\n";
	
	this->fix_point =  roundf(n);

	float c = n - roundf(n);

	if (c < 0)
	{
		c = 1.0f + c;
		this->fix_point--;
	}
	this->fix_point *= high(2, this->literal);
	for(int i = 0; i < this->literal; i++)
	{
		if (c >= (1.0f / high(2, i + 1)+ 0.0f))
		{
			this->fix_point += high(2, this->literal - i - 1);
			c -= (1.0f / high(2, i + 1)+ 0.0f);
		}
	}
}

// destructor
Fixed::~Fixed(void) {std::cout << "Destructor called\n";}


// functions
int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called\n";
	return(this->fix_point);
}

void	Fixed::setRawBits(int const raw)
{
	this->fix_point = raw;
}

float	Fixed::toFloat( void ) const
{
	// float ret = this->fix_point / high(2, this->literal);
	float ret = this->fix_point >> (this->literal);
	int c = this->fix_point % high(2, this->literal);
	
	for (int i = 0; i < this->literal; i++)
		ret += ((c % high(2, this->literal - i)) / high(2, this->literal - i - 1)) * (1 / (high(2, i + 1) + 0.0f));
	return (ret);
}

int Fixed::toInt( void ) const
{
	return (this->fix_point / high(2, this->literal));
}

Fixed&	Fixed::min(const Fixed& fix1, const Fixed& fix2)
{
	return((fix1 < fix2)? fix1 : fix2);
}












// operator overloads
void Fixed::operator= (const Fixed &fix)
{
	std::cout << "Copy assignment operator called\n";

	this->fix_point = fix.fix_point;
}

std::ostream&	operator<<(std::ostream &output, const Fixed& fix)
{
	output << fix.toFloat();;
	return (output);
}

bool	Fixed::operator < (const Fixed &fix)
{
	if (fix.toFloat() < this->toFloat())
		return (true);
	return(false);
}

bool	Fixed::operator > ( Fixed &fix)
{
	return(fix < *this);
}

bool	Fixed::operator >= (Fixed &fix)
{
	return(!(fix < *this));
}

bool	Fixed::operator <= (Fixed &fix)
{
	return(!(fix > *this));
}

bool	Fixed::operator == (const Fixed &fix)
{
	if (this->toFloat() == fix.toFloat())
		return (true);
	return(false);
}

bool	Fixed::operator != ( Fixed &fix)
{
	return(!(*this == fix));
}

float	Fixed::operator + ( const Fixed &fix)
{
	float ret = this->toFloat() + fix.toFloat();
	return(ret);
}

float	Fixed::operator - ( const Fixed &fix)
{
	float ret = this->toFloat() - fix.toFloat();
	return(ret);
}

float	Fixed::operator * ( const Fixed &fix)
{
	float ret = this->toFloat() * fix.toFloat();
	return(ret);
}

float	Fixed::operator / ( const Fixed &fix)
{
	float ret = this->toFloat() / fix.toFloat();
	return(ret);
}

float	Fixed::operator++ (void)
{
	this->fix_point += 1;
	return (this->toFloat());
}

float	Fixed::operator-- (void)
{
	this->fix_point -= 1;
	return (this->toFloat());
}

float	Fixed::operator++ (int)
{	
	float res = this->toFloat();
	this->fix_point += 1;
	return (res);
}

float	Fixed::operator-- (int)
{
	float res = this->toFloat();
	this->fix_point -= 1;
	return (res);
}