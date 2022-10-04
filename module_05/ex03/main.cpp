/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:51:01 by afenzl            #+#    #+#             */
/*   Updated: 2022/10/04 17:44:25 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "Intern.hpp"

int main( void )
{
	try
	{
		Intern someRandomIntern;
		Form* rrf;
		Bureaucrat Peter("Peter");
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");

		rrf->beSigned(Peter);
		rrf->beExecuted(Peter);
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return (0);
}