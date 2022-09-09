/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:36:14 by afenzl            #+#    #+#             */
/*   Updated: 2022/09/09 13:23:33 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string string_var = "HI THIS IS BRAIN";
	std::string* stringPtr = &string_var;
	std::string& stringRef = string_var;

	std::cout << "memory address of string_var: " << &string_var << std::endl;
	std::cout << "memory address held by stringPtr: " << stringPtr << std::endl;
	std::cout << "memory address held by stringRef: " << &stringRef << std::endl;
	std::cout << "\n";
	std::cout << "value of string_var is: " << string_var << std::endl;
	std::cout << "value pointed to by stringPtr: " << *stringPtr << std::endl;
	std::cout << "value pointed to by stringRef: " << string_var << std::endl;
	
	return (0);
}