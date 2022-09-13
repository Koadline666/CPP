/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 18:23:55 by afenzl            #+#    #+#             */
/*   Updated: 2022/09/13 20:08:39 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"

//  ----------------------- CONSTRUCTORS & DESTRUCTOR -----------------------

ClapTrap::ClapTrap() : name("Random guy"), hp(10), ep(10), ad(0)
{
	std::cout << "ClapTrap \"Random Guy\" created. --> Default" << std::endl;
}


ClapTrap::ClapTrap(std::string name) : name(name), hp(10), ep(10), ad(0)
{
	std::cout << "Claptrap " << name << " created." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	*this = copy;
	std::cout << "Claptrap " << name << " created. --> Copy" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Claptrap " << this->name << " destroyed" << std::endl;
}

//  ----------------------- OPERATOR OVERLOAD -----------------------

void ClapTrap::operator= (const ClapTrap &clap)
{
	this->name = clap.name;
	this->ad = clap.ad;
	this->ep = clap.ep;
	this->hp = clap.hp;
}

//  ----------------------- METHODS -----------------------

void ClapTrap::attack(const std::string& target)
{
	if (this->hp > 0 && this->ep > 0)
	{
		std::cout << this->name << " attacks " << target << ", causing " << this->ad << " points of damage" << std::endl;
		this->ep--;
	}
	else
		std::cout << this->name << " has no energy points to attack " << target << std::endl;

}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << this->name << " took " << amount << " points of damage!" << std::endl;
	this->hp -= amount;
	if (!this->hp)
		std::cout << this->name << " died...   RIP" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->ep > 0 && this->hp > 0)
	{
		std::cout << this->name << " repaires itself " << std::endl;
		this->hp += amount;
		this->ep--;
	}
	else
		std::cout << this->name << " has no energy points or hit points to repair itself " << std::endl;
}

//  ----------------------- GETTER AND SETTER METHODS -----------------------

std::string ClapTrap::get_name( void ) {return ( this->name );}

int	ClapTrap::get_hp( void ) {return ( this->hp );}

int	ClapTrap::get_ep( void ) {return ( this->ep );}

int	ClapTrap::get_ad( void ) {return ( this->ad );}

void ClapTrap::set_name(std::string name)
{
	this->name = name;
}
void ClapTrap::set_hp(int hp)
{
	this->hp = hp;
}

void ClapTrap::set_ep(int ep)
{
	this->ep = ep;
}

void ClapTrap::set_ad(int ad)
{
	this->ad = ad;
}

