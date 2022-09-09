/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:53:36 by afenzl            #+#    #+#             */
/*   Updated: 2022/09/07 17:35:34 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	int	N = 10;

	Zombie *zombie = zombieHorde(N, "Karl");
	for (int i = 0; i < N; i++)
		zombie[i].announce();
	delete []zombie;

	system("leaks zombie");
	return (0);
}