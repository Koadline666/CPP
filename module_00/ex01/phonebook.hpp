/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 19:10:39 by afenzl            #+#    #+#             */
/*   Updated: 2022/09/01 23:28:23 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "contact.hpp"

class PhoneBook
{
	private:
		Contact list[8];
	public:
		PhoneBook()
		{std:: cout << "\n\t\tPHONEBOOK IS CURRENTLY EMPTY\n";}
		Contact *getContact(void)
		{return (list);}
		void add_contact()
	
};

#endif