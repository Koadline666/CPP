/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:13:56 by afenzl            #+#    #+#             */
/*   Updated: 2022/09/14 15:13:57 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP
# define FRAGTRAP

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
	private:
		
	public:
		FragTrap();
		FragTrap(std::string str);
		FragTrap(FragTrap& copy);

		void operator= (FragTrap const & src);

		void highFivesGuys(void);

		~FragTrap();
};



#endif