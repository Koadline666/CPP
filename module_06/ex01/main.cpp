/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 19:23:38 by afenzl            #+#    #+#             */
/*   Updated: 2022/10/13 15:38:24 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Serialize.hpp"

uintptr_t serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
	return(reinterpret_cast<Data *>(raw));
}

int main( void )
{
	Data d;
	d.name = "Hello";

	std::cout << deserialize(serialize(&d))->name << std::endl;
	return (0);
}