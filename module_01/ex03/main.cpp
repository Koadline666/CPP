/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:00:37 by afenzl            #+#    #+#             */
/*   Updated: 2022/09/07 18:45:53 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void)
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		// club.setType("some other type of club");
		bob.attack();
	}
	// {
		// Weapon club = Weapon("crude spiked club");
		// HumanB jim("Jim");
		// // jim.setWeapon(club);
		// jim.attack();
		// // club.setType("some other type of club");
		// jim.attack();
	// }
	return (0);
}