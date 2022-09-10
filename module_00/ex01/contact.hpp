/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 13:37:23 by afenzl            #+#    #+#             */
/*   Updated: 2022/09/07 14:23:33 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact
{
	private:
		std::string	phonenumber;
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	darkest_secret;
		bool	created;
	public:
		Contact();
		// setters
		void set_phonenumber(std::string phonenumber);
		void set_firstname(std::string first_name);
		void set_lastname(std::string last_name);
		void set_nickname(std::string nickname);
		void set_darkest_secret(std::string darkest_secret);
		void set_created(bool created);
		
		// getters
		std::string get_phonenumber( void );
		std::string get_firstname( void );
		std::string get_lastname( void );
		std::string get_nickname( void );
		std::string get_darkest_secret( void );
		bool get_created( void );

		void print_contact(void);
		~Contact();
};

#endif