/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 19:01:22 by afenzl            #+#    #+#             */
/*   Updated: 2022/09/06 18:23:03 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

// using std::cout;
// using std::cin;

std::string	remove_whitespace(std::string input)
{
	std::string whitespace = " \t\v\n\v\f";

	size_t	first = input.find_first_not_of(whitespace);
	if (first == std::string::npos)
		return ("");
	size_t	last = input.find_last_not_of(whitespace);
	input = input.substr(first, last - first + 1);
	return (input);
}

std::string	get_input(std::string message)
{
	std::string input;

	std::cout << message << std::endl;
	do
	{
		if (!std::cin|| !std::getline(std::cin, input))
		{
			std::cout << "BYE BYE ..." << std::endl;
			exit(1);
		}
		input = remove_whitespace(input);
	} while (input == "");
	return(input);
}

int	check_for_digit(std::string phonenumber)
{
	for(size_t i = 0; i < phonenumber.size(); i++)
	{
		if (!std::isdigit(phonenumber[i]))
			return (1);
	}
	return (0);
}

void	PhoneBook::add_contact(int index)
{
	Contact	new_contact;
	std::string	input;

	input = get_input("PLEASE ENTER PHONENUMBER:");
	if (check_for_digit(input) == 1)
	{
		add_contact(index);
		return ;	
	}
	new_contact.set_phonenumber(input);
	input = get_input("PLEASE ENTER FIRST NAME:");
	new_contact.set_firstname(input);
	input = get_input("PLEASE ENTER LAST NAME:");
	new_contact.set_lastname(input);
	input = get_input("PLEASE ENTER NICKNAME:");
	new_contact.set_nickname(input);
	input = get_input("PLEASE ENTER DARKEST SECRET:");
	new_contact.set_darkest_secret(input);
	this->list[index] = new_contact;
	this->list[index].set_created(true);
	std::cout << "\n\nYOU JUST CREATED THIS CONTACT:\n\n";
	this->list[index].print_contact();
	std::cout << "\n\n";
}

void	print_name(std::string name)
{
	if (name.size() > 10)
		std::cout << name.substr(0, 9) << ".|";
	else
		std::cout << std::setw(10) << name << "|";
}

void	display_contacts(Contact contact)
{
	print_name(contact.get_firstname());
	print_name(contact.get_lastname());
	print_name(contact.get_nickname());
	std::cout << "\n";
}

void	display_list(Contact *list)
{
	std::cout << "\t\tAVAILABLE CONTACTS ARE:\n\n";
	std::cout << "\t\t|   INDEX  | FIRSTNAME| LASTNAME | NICKNAME |\n";
	for (int i = 0; i < 8; i++)
	{
		std::cout << "\t\t|" << std::setw(10) << i + 1 << "|";
		display_contacts(list[i]);
	}
	std::cout << "\n\n";
}

void	PhoneBook::search_contact(void)
{
	if (list[0].get_created() == false)
	{
		std::cout << "NO AVAILABLE CONTACTS YET\n" << std::endl;
		return ;
	}
	display_list(list);
	std::string input = get_input("PLEASE ENTER INDEX OF DESIRED CONTACT");
	if (input.size() == 1 && input[0] >= '1' && input[0] <= '8')
	{
		int	index = input[0] - '0' - 1;
		if (list[index].get_created() == false)
		{
			std::cout << "CONTACT IS NOT ADDED YET, TRY AGAIN\n\n";
			search_contact();
			return ;
		}
		else
			list[index].print_contact();
	}
	else
	{
		std::cout << "INPUT NOT VALID, TRY AGAIN\n\n";
		search_contact();
	}
}