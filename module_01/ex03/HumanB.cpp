/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:54:05 by afenzl            #+#    #+#             */
/*   Updated: 2022/09/07 19:23:37 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name):name(name)
{
	this->weapon = NULL;
}

HumanB::~HumanB(void)
{
	std::cout << name << " died\n";
}

void	HumanB::setWeapon(Weapon weapon)
{
	this->weapon = &weapon;
}
void HumanB::attack(void)
{
	if (weapon == NULL)
		std::cout << name << " has no weapon and can't attack\n";
	else
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}
