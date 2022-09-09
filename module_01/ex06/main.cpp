/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 12:55:51 by afenzl            #+#    #+#             */
/*   Updated: 2022/09/09 13:13:57 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Harl.hpp"

int main (int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Harl got no input to complain about\n";
		return (1);
	}
	Harl::harlfilter(argv[1]);
	return (0);
}