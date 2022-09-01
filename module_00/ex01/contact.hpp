/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 19:14:28 by afenzl            #+#    #+#             */
/*   Updated: 2022/09/01 19:55:02 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact
{
	private:
		long		phonenumber;
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string darkest_secret;

	public:
		void set_phonenumber(long number)
		{ this->phonenumber = number;}
		void set_first_name(std::string first_name)
		{ this->first_name = first_name;}
		void set_last_name(std::string last_name)
		{ this->last_name = last_name;}
		void set_nickname(std::string nickname)
		{ this->nickname = nickname;}
		void set_darkest_secret(std::string darkest_secret)
		{ this->darkest_secret = darkest_secret;}

		long get_phonenumber(void)
		{ return (this->phonenumber);}
		std::string get_first_name(void)
		{ return (this->first_name);}
		std::string get_last_name(void)
		{ return (this->last_name);}
		std::string get_nickname(void)
		{ return (this->nickname);}
		std::string get_darkest_secret(void)
		{ return (this->darkest_secret);}

};

#endif