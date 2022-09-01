/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 19:20:15 by afenzl            #+#    #+#             */
/*   Updated: 2022/09/01 23:32:12 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	promt(void)
{
	std::cout << "\t      ------------------------------------\n";
	std::cout << "\t      | PLEASE ENTER YOUR DESIRED ACTION: |\n";
	std::cout << "\t      |                                   |\n";
	std::cout << "\t      |  ADD         SEARCH         EXIT  |\n";
	std::cout << "\t      |                                   |\n";
	std::cout << "\t      ------------------------------------\n";
}

int	main(void)
{
	PhoneBook phonebook;
	std::string input;

	while (true)
	{
		promt();
		std:: cout << ">\n";
		std::getline(std::cin, input);
		if (input.compare("ADD") == 0)
			std::cout << "ADD" << std::endl;
		else if (input.compare("SEARCH") == 0)
			std::cout << "SEARCH" << std::endl;
		else if (input.compare("EXIT") == 0)
		{
			std:: cout << "BYE BYE" << std::endl;
			break;
		}
	}
	
	return (0);
}