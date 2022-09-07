/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:54:03 by afenzl            #+#    #+#             */
/*   Updated: 2022/09/07 18:50:27 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

//  a reference cant be reassigned and must be assigned at initialisation
class HumanA
{
	private:
		std::string	name;
		Weapon		weapon_type;
	public:
		HumanA(std::string, Weapon weapon);
		void	attack( void );
		~HumanA();
};

#endif