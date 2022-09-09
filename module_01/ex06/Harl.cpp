/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 12:53:56 by afenzl            #+#    #+#             */
/*   Updated: 2022/09/09 13:14:50 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Harl.hpp"

Harl::Harl() {std::cout << "Harl is born\n";}

Harl::~Harl() {std::cout << "Harl died\n";}

void	Harl::debug(void)
{
	std::cout << "(DEBUG)I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n";
}

void	Harl::info(void)
{
	std::cout << "(INFO) I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void	Harl::warning(void)
{
	std::cout << "(WARNING) I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n";
}

void	Harl::error(void)
{
	std::cout << "(ERROR) This is unacceptable! I want to speak to the manager now.\n";
}

void Harl::harlfilter( std::string level)
{
	Harl harl;
	enum {DEBUG, INFO, WARNING, ERROR};
	std::string msg[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++)
	{
		if (msg[i] == level)
		{
			switch ( i )
			{
				case DEBUG:
					harl.debug();
				case INFO:
					harl.info();
				case WARNING:
					harl.warning();
				case ERROR:
					harl.error();
				return ;
			}
		}
	}
	std::cout << "[ Probably complaining about insignificant problems ]\n";
}