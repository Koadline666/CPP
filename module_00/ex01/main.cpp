/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 13:36:51 by afenzl            #+#    #+#             */
/*   Updated: 2022/09/04 20:09:39 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void	promt(void)
{
	std::cout << "\t       ----------------------------------------" << std::endl;
	std::cout << "\t       |   PLEASE ENTER YOUR DESIRED ACTION   |" << std::endl;
	std::cout << "\t       |                                      |" << std::endl;
	std::cout << "\t       |    ADD        SEARCH         EXIT    |" << std::endl;
	std::cout << "\t       |                                      |" << std::endl;
	std::cout << "\t       ----------------------------------------" << std::endl;
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
		std::getline(std::cin, input);
		if (input == "ADD")
		{
			if (index == 8)
				index = 0;
			std::cout << "index is " << index << std::endl;
			phonebook.add_contact(index);
			index++;
		}
		else if (input == "SEARCH")
			phonebook.search_contact();
		else if (input == "EXIT")
			loop = 0;
	}
	std::cout << "BYE BYE ...";
	return (0);
}