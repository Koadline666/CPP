/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 13:37:55 by afenzl            #+#    #+#             */
/*   Updated: 2022/09/05 14:08:55 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "contact.hpp"

void	Contact::set_phonenumber(std::string phonenumber)
{
	this->phonenumber = phonenumber;
}

void	Contact::set_firstname(std::string first_name)
{
	this->first_name = first_name;
}

void	Contact::set_lastname(std::string last_name)
{
	this->last_name = last_name;
}

void	Contact::set_nickname(std::string nickname)
{
	this->nickname = nickname;
}

void	Contact::set_darkest_secret(std::string darkest_secret)
{
	this->darkest_secret = darkest_secret;
}

void	Contact::set_created(bool created)
{
	this->created = created;
}

std::string Contact::get_phonenumber(void)
{
	return(this->phonenumber);
}

std::string Contact::get_firstname(void)
{
	return(this->first_name);
}

std::string Contact::get_lastname(void)
{
	return(this->last_name);
}

std::string Contact::get_nickname(void)
{
	return(this->nickname);
}

std::string Contact::get_darkest_secret(void)
{
	return(this->darkest_secret);
}

bool	Contact::get_created(void)
{
	return(this->created);
}

void	Contact::print_contact(void)
{
	std::cout << "\t\tPHONENUMBER:\t" << this->phonenumber << std::endl;
	std::cout << "\t\tFIRSTNAME:\t" << this->first_name << std::endl;
	std::cout << "\t\tLAST NAME:\t" << this->last_name << std::endl;
	std::cout << "\t\tNICKNAME:\t" << this->nickname << std::endl;
	std::cout << "\t\tDARKEST SECRET:\t" << this->darkest_secret << std::endl;
}