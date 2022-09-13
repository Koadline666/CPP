/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 18:23:27 by afenzl            #+#    #+#             */
/*   Updated: 2022/09/13 19:29:32 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap Fbindere("Fbindere");
	ClapTrap Random;

	Fbindere.attack("Pfuchs");
	Random.attack("Findere");
	Fbindere.takeDamage(10);
	Fbindere.attack("Pfuchs again");
	Fbindere.beRepaired(10);
	Fbindere.attack("Pfuchs");
	std::cout << std::endl;

	ClapTrap	Fabibi("Fabibi");

	for(int i = 0; i < 10; i++)
		Fabibi.attack("somebody");
	Fabibi.attack("\"anybody else\"");

	return (0);
}