/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 19:32:58 by afenzl            #+#    #+#             */
/*   Updated: 2022/09/09 13:40:51 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Sed.hpp"

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "not the right amount of parameters\n";
		return (1);
	}
	
	return (Sed::sed(argv[1], argv[2], argv[3]));
	
	// Sed input(argv[1], argv[2], argv[3]);
	// input.sed();
	// return (input.get_return_value());
	return (0);
}

// int main(void)
// {
// 	Sed::sed("not_valid_file", "this", "that");
// 	// valid tests
// 	Sed::sed("test1", "no_such_string", "that");
// 	Sed::sed("test1", "", "that");
// 	Sed::sed("test1", "eggs", "EGGS");
// }