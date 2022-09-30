/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyCreationForm.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:10:42 by afenzl            #+#    #+#             */
/*   Updated: 2022/09/30 19:23:35 by afenzl           ###   ########.fr       */
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

void RobotomyRequestForm::beSigned(Bureaucrat & worker)
{
	if (worker.getGrade() <= 145)
		this->setSign(true);
	else
		throw GradeTooLowException();
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->getSign())
		{
			if (executor.getGrade() <= this->getGrade_exec())
			{
				std::cout << "* drilling noises *";
				int n = rand();
				if (n & 1)
					std::cout << target_ << " has been robotomized successfully.";
				else
					std::cout << "robotomy failed.";
			}
			else
				throw std::logic_error ("\033[0;31m" + executor.getName() + "'s grade is not high enough to execute RobotomyRequestForm\033[0m");
		}
	else
		throw std::logic_error ("\033[0;31mRobotomyRequestForm " + this->getName() + " is not signed.\033[0m");
}