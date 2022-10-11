/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 19:23:38 by afenzl            #+#    #+#             */
/*   Updated: 2022/10/09 19:47:52 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Serialize.hpp"

int main( void )
{
	Data days(7, "the amount of days in a week");
	
	std::cout << days.get_info() << " is " << days.get_data() << std::endl;

	uintptr_t serialized = serialize(&days);
	std::cout << "the serialized version is " << serialized << std::endl;
	return (0);
}