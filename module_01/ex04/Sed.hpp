/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 19:45:38 by afenzl            #+#    #+#             */
/*   Updated: 2022/09/08 17:06:03 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP

# include <iostream>
# include <fstream>
# include <string>

class Sed
{
	private:
		std::string filename;
		std::string s1;
		std::string s2;
		std::string content;
		bool		return_value;

		void		open_and_read_infile();
		void		replace_and_write_outfile();

	public:
		Sed(std::string filename, std::string s1, std::string s2);
		
		static int	sed(std::string filename, std::string s1, std::string s2);
		int	sed(void);

		bool	get_return_value();
		
		~Sed();
};

#endif