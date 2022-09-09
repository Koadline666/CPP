/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:39:40 by afenzl            #+#    #+#             */
/*   Updated: 2022/09/09 13:19:05 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie stack_zombie;
	stack_zombie.announce();

	Zombie named_stack_zombie("Pfuchs");
	named_stack_zombie.announce();

	Zombie	*heap_zombie = newZombie("Fbindere"); 
	heap_zombie->announce();

	randomChump( "Fabibi" );
	
	delete heap_zombie;
	// system ("leaks zombie");
	return (0);
}
