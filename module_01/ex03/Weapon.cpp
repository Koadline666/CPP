/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:50:23 by afenzl            #+#    #+#             */
/*   Updated: 2022/09/07 19:05:11 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->type = type;
}

Weapon::~Weapon(void)
{
	std::cout << "Weapon type " << this->type << " destroyed\n";
}

void	Weapon::setType(std::string type)
{
	this->type = type;
}

const std::string&	Weapon::getType()
{
	std::string& reference = this->type;
	return(reference);
}