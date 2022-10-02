/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:14:42 by afenzl            #+#    #+#             */
/*   Updated: 2022/09/21 14:46:29 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP
# define DIAMONDTRAP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
	private:
		std::string name;
		FragTrap :: hp;
		ScavTrap :: ep;
		FragTrap :: ad;

	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap const & copy);

		void operator= (DiamondTrap const & src);

		ScavTrap :: attack;

		void whoAmI();

		~DiamondTrap();
};

#endif