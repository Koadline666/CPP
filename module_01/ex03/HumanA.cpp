/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:08:25 by afenzl            #+#    #+#             */
/*   Updated: 2022/09/07 18:53:30 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon_type)
{
	this->name = name;
	this->weapon_type = weapon_type;
}

HumanA::~HumanA() {}

void	HumanA::attack(void)
{
	std::cout << HumanA::name << " attacks with their " << "hey";
}