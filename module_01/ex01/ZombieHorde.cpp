/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:57:12 by afenzl            #+#    #+#             */
/*   Updated: 2022/09/09 13:22:18 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include"Zombie.hpp"

Zombie *zombieHorde( int N, std::string name )
{
	Zombie *new_zombie = new Zombie[N];
	for (int i = 0; i < N; i++)
		new_zombie[i].set_name(name);
	return (new_zombie);
}