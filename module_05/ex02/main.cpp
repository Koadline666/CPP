/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:51:01 by afenzl            #+#    #+#             */
/*   Updated: 2022/09/30 18:21:42 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"

int main( void )
{
	try
	{
		Bureaucrat Frank("Frank", 145);
		Bureaucrat Peter("Peter", 137);
		ShrubberyCreationForm paper("duck");

		// Bureaucrat Frank("Frank", 72);
		// Bureaucrat Peter("Peter", 45);
		// RobotomyRequestForm paper("paper");

		std::cout << std::endl << paper << std::endl;
		Frank.signForm(paper);
		std::cout << paper << std::endl;
		paper.execute(Peter);
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return (0);
}