/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:34:09 by afenzl            #+#    #+#             */
/*   Updated: 2022/09/01 19:07:02 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

std::string	to_uppercase(std::string text)
{
	int i = 0;

	while (text[i] != '\0')
	{
		text[i] = toupper(text[i]);
		i++;
	}
	return(text);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		std:: cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	else
	{
		for (int i = 1; i < argc; i++)
		{
			std::string line = to_uppercase(argv[i]);
			std:: cout << line;
		}
		std:: cout << "\n";
	}
	return (0);
}