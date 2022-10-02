/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:12:42 by afenzl            #+#    #+#             */
/*   Updated: 2022/09/14 15:12:43 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
	private:
		std::string	name;
		int			hp;
		int			ep;
		int			ad;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& clap);

		void operator= (const ClapTrap& copy);

		void set_name(std::string name);
		void set_hp(int hp);
		void set_ep(int ep);
		void set_ad(int ad);
		
		std::string get_name( void );
		int			get_hp( void );
		int			get_ep( void );
		int			get_ad( void );

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		~ClapTrap();
};

#endif