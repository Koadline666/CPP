/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 19:53:01 by afenzl            #+#    #+#             */
/*   Updated: 2022/09/08 17:00:11 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Sed.hpp"

Sed::Sed(std::string filename, std::string s1, std::string s2)
{
	this->filename = filename;
	this->s1 = s1;
	this->s2 = s2;
}

Sed::~Sed(void)
{
	if (this->return_value == true)
		std::cout << "Sed could not be executed\n";
	else
		std::cout << "Sed was executed successfully\n";
}

bool	Sed::get_return_value(void) {return(return_value);}

int	Sed::sed(void)
{
	open_and_read_infile();
	if (get_return_value() == 0)
		replace_and_write_outfile();
	return (get_return_value());
}

int	Sed::sed(std::string filename, std::string s1, std::string s2)
{
	Sed input(filename, s1, s2);

	input.open_and_read_infile();
	if (input.get_return_value() == 0)
		input.replace_and_write_outfile();
	return (input.get_return_value());
}

void	Sed::open_and_read_infile(void)
{
	std::ifstream infile(filename);
	if (infile.is_open())
	{
		std::string line;
		while (infile.good())
		{
			std::getline(infile, line);
			content.append(line + "\n");
		}
	}
	else
	{
		std::cout << "Couldn't open infile\n";
		return_value = true;
	}
}

void	Sed::replace_and_write_outfile(void)
{
	std::ofstream outfile(filename.append(".replace"), std::ios::trunc);
	if (outfile.is_open())
	{
		if (s1 == "")
		{
			outfile << content;
			return ;
		}
		size_t		pos = content.find(s1);
		while (pos != content.npos && content != "")
		{
			for (size_t i = 0; i < pos; i++)
				outfile << content[i];
			outfile << s2;
			content.erase(content.begin(), content.begin() + pos + s1.length());
			pos = content.find(s1);
		}
		for (size_t i = 0; i < content.size(); i++)
				outfile << content[i];
	}
	else
	{
		std::cout << "Couldn't open outfile\n";
		return_value = true;
	}
}

