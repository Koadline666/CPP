/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 14:29:24 by afenzl            #+#    #+#             */
/*   Updated: 2022/09/11 18:55:03 by afenzl           ###   ########.fr       */
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

// ************************* constructor and destructor **************************
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


// ***************************** functions ***********************************
int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called\n";
	return(this->fix_point);
}

void	Fixed::setRawBits(int const raw)
{
	this->fix_point = raw;
}

static float	converttoFloat( const int& fix, int literal)
{
	float ret = fix >> (literal);
	int c = fix % high(2, literal);
	
	for (int i = 0; i < literal; i++)
		ret += ((c % high(2, literal - i)) / high(2, literal - i - 1)) * (1 / (high(2, i + 1) + 0.0f));
	return (ret);
}

float	Fixed::toFloat( void ) const
{
	return(converttoFloat(this->fix_point, this->literal));
}

int Fixed::toInt( void ) const
{
	return (this->fix_point / high(2, this->literal));
}

const Fixed&	Fixed::min(const Fixed& fix1, const Fixed& fix2)
{
	return((fix1.toFloat() < fix2.toFloat())? fix1 : fix2);
}

const Fixed&	Fixed::max(const Fixed& fix1, const Fixed& fix2)
{
	return((fix1.toFloat() > fix2.toFloat())? fix1 : fix2);
}

const int&	Fixed::min(const int& fix1, const int& fix2)
{
	return((converttoFloat(fix1, literal) < converttoFloat(fix2, literal)) ? fix1 : fix2);
}

const int&	Fixed::max(const int& fix1, const int& fix2)
{
	return((converttoFloat(fix1, literal) > converttoFloat(fix2, literal)) ? fix1 : fix2);
}

// ************************* operator overloads *********************************

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

// *********************** comparison overloads ************************************
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

// ******************************* binary arithmetic overloads **********************
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

// ******************************* increment and decrement overloads **********************
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