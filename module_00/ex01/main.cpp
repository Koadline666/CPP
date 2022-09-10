/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 13:36:51 by afenzl            #+#    #+#             */
/*   Updated: 2022/09/07 13:53:03 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	promt(void)
{
	std::cout << "\t       ----------------------------------------\n";
	std::cout << "\t       |   PLEASE ENTER YOUR DESIRED ACTION   |\n";
	std::cout << "\t       |                                      |\n";
	std::cout << "\t       |    ADD        SEARCH         EXIT    |\n";
	std::cout << "\t       |                                      |\n";
	std::cout << "\t       ----------------------------------------\n";
}

int	main(void)
{
	PhoneBook	phonebook;
	std::string	input;
	int			loop = 1;
	int			index = 0;

	promt();
	while (loop)
	{
		std::cout << "> ";
		if (!(std::getline(std::cin, input)))
			loop = 0;
		if (input == "ADD")
		{
			if (index == 8)
				index = 0;
			phonebook.add_contact(index);
			index++;
		}
		else if (input == "SEARCH")
			phonebook.search_contact();
		else if (input == "EXIT")
			loop = 0;
	}
	std::cout << "BYE BYE ...\n" << std::endl;
	return (0);
}