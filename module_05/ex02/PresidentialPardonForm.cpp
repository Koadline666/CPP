/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:09:19 by afenzl            #+#    #+#             */
/*   Updated: 2022/09/30 19:39:57 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PresidentialPardonForm.hpp"

//  -------------- CONSTRUCTORS & DESTRUCTOR ----------------

PresidentialPardonForm::PresidentialPardonForm(): Form("PresidentialPardonForm", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(std::string target): Form("PresidentialPardonForm", 25, 5), target_(target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & copy): Form(copy) {}

PresidentialPardonForm::~PresidentialPardonForm() {}


//  ----------------------- OPERATOR OVERLOAD -------------

PresidentialPardonForm & PresidentialPardonForm::operator= (const Form & src)
{
	if (this != &src)
		return (*this);
	return *this;
}

//  ----------------------- METHODS -------------

void PresidentialPardonForm::beSigned(Bureaucrat & worker)
{
	if (worker.getGrade() <= 145)
		this->setSign(true);
	else
		throw GradeTooLowException();
}

void PresidentialPardonForm::check_execute(Bureaucrat const & executor) const
{
	if (this->getSign())
		{
			if (executor.getGrade() <= this->getGrade_exec())
			{
				std::cout << target_ << "has been pardoned by Zaphod Beeblebrox" << std::endl;
			}
			else
				throw std::logic_error ("\033[0;31m" + executor.getName() + "'s grade is not high enough to execute RobotomyRequestForm\033[0m");
		}
	else
		throw std::logic_error ("\033[0;31mRobotomyRequestForm " + this->getName() + " is not signed.\033[0m");
}
