/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyCreationForm.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:10:42 by afenzl            #+#    #+#             */
/*   Updated: 2022/10/10 13:49:00 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RobotomyRequestForm.hpp"

//  -------------- CONSTRUCTORS & DESTRUCTOR ----------------

RobotomyRequestForm::RobotomyRequestForm(): Form ("RobotomyRequestForm", 72, 45), target_("target") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target): Form ("RobotomyRequestForm", 72, 45), target_(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & copy): Form(copy) {}

RobotomyRequestForm::~RobotomyRequestForm() {}


//  ----------------------- OPERATOR OVERLOAD -------------

RobotomyRequestForm & RobotomyRequestForm::operator= (const Form & src)
{
	if (this != &src)
		return (*this);
	return *this;
}

//  ----------------------- METHODS -------------

# include <sys/time.h>

long	get_current_time_ms(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

void RobotomyRequestForm::beSigned(Bureaucrat & worker)
{
	if (worker.getGrade() <= 145)
		this->setSign(true);
	else
		throw GradeTooLowException();
}

# include <chrono>

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	std::cout << "* drilling noises *" << std::endl;
	beExecuted(executor);
	srand(get_current_time_ms());
	if (rand() % 2)
		std::cout << target_ << " has been robotomized successfully." << std::endl;
	else
		std::cout << "robotomy failed." << std::endl;
}