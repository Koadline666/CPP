/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:14:53 by afenzl            #+#    #+#             */
/*   Updated: 2022/09/14 15:14:54 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP
# define FRAGTRAP

#include "ClapTrap.hpp"

class FragTrap: public virtual ClapTrap
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