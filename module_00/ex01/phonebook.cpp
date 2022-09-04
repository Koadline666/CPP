/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 19:01:22 by afenzl            #+#    #+#             */
/*   Updated: 2022/09/04 20:04:27 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void	PhoneBook::add_contact(int index)
{
	std::string	input;

	std::cout << "PLEASE ENTER PHONENUMBER:\n>";
	getline(std::cin, input);
	this->list[index].set_phonenumber(input);
	std::cout << "PLEASE ENTER FIRST NAME:\n>";
	getline(std::cin, input);
	this->list[index].set_firstname(input);
	std::cout << "PLEASE ENTER LAST NAME:\n>";
	getline(std::cin, input);
	this->list[index].set_lastname(input);
	std::cout << "PLEASE ENTER NICKNAME:\n>";
	getline(std::cin, input);
	this->list[index].set_nickname(input);
	std::cout << "PLEASE ENTER DARKEST SECRET:\n>";
	getline(std::cin, input);
	this->list[index].set_darkest_secret(input);
	std::cout << "\n\nYOU JUST CREATED THIS CONTACT:\n" << std::endl;
	this->list[index].print_contact();
	std::cout << std::endl << std::endl;
}


void	PhoneBook::search_contact(void)
{
	std::string_view	input;

	std::cout << "AVAILABLE CONTACTS ARE:" << std::endl;
	
	std::cout << "PLEASE ENTER DESIRED CONTACT (INDEX):\n>";
	
	std::cout << "DESIRED CONTACT IS NOT SAVED IN PHONEBOOK" << std::endl;
}