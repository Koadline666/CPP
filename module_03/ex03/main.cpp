/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:14:58 by afenzl            #+#    #+#             */
/*   Updated: 2022/09/14 15:14:59 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap d("Fabibi");

	std::cout << "\nDiamondTrap Fabibi's data:" << std::endl;
	std::cout << "HP" << d.get_hp() << std::endl;
	std::cout << "AD" << d.get_ad() << std::endl;
	std::cout << "EP" << d.get_ep() << std::endl;
	
	std::cout << "\nDiamondTrap Fabibi using his own method:" << std::endl;
	d.whoAmI();

	std::cout << "\nDiamondTrap Fabibi his FragTraps's  method:" << std::endl;
	d.highFivesGuys();

	std::cout << "\nDiamondTrap Fabibi his ScavTraps's  method:" << std::endl;
	d.guardGate();

	std::cout << "\nDiamondTrap Fabibi being destroyed:" << std::endl;
	return (0);
}
