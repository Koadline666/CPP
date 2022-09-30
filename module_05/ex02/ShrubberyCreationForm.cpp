/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:10:52 by afenzl            #+#    #+#             */
/*   Updated: 2022/09/30 18:22:51 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ShrubberyCreationForm.hpp"

//  -------------- CONSTRUCTORS & DESTRUCTOR ----------------

ShrubberyCreationForm::ShrubberyCreationForm(): Form("ShrubberyCreationForm", 145, 137), target_("target") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): Form("ShrubberyCreationForm", 145, 137 ), target_(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & copy): Form(copy), target_(copy.target_) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}


//  ----------------------- OPERATOR OVERLOAD -------------

ShrubberyCreationForm & ShrubberyCreationForm::operator= (const Form & src)
{
	if (this != &src)
		return (*this);
	return *this;
}

//  ----------------------- METHODS -------------

void ShrubberyCreationForm::beSigned(Bureaucrat & worker)
{
	if (worker.getGrade() <= this->getGrade_sign())
		this->setSign(true);
	else
		throw GradeTooLowException();
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->getSign())
	{
		if (executor.getGrade() <= this->getGrade_exec())
		{
			std::ofstream outfile(executor.getName().append("_shrubbery"), std::ios::app);
			if (outfile.is_open())
			{
				outfile << "                                  # #### ####" << std::endl;
				outfile << "                                ### \\/#|### |/####" << std::endl;
				outfile << "                               ##\\/#/ \\||/##/_/##/_#" << std::endl;
				outfile << "                             ###  \\/###|/ \\/ # ###" << std::endl;
				outfile << "                           ##_\\_#\\_\\## | #/###_/_####" << std::endl;
				outfile << "                          ## #### # \\ #| /  #### ##/##" << std::endl;
				outfile << "                           __#_--###`  |{,###---###-~" << std::endl;
				outfile << "                                     \\ }{" << std::endl;
				outfile << "                                      }}{" << std::endl;
				outfile << "                                      }}{" << std::endl;
				outfile << "                                 ejm  {{}" << std::endl;
				outfile << "                                , -=-~{ .-^- _" << std::endl;
				outfile << "                                      `}" << std::endl;
				outfile << "                                       {" << std::endl;
				outfile.close();
			}
			else
				throw std::logic_error ("\033[0;31m ShrubberyCreationForm " + this->getName() + " couldn't open outfile.\033[0m");
		}
		else
			throw std::logic_error ("\033[0;31m" + executor.getName() + "'s grade is not high enough to execute ShrubberyCreationForm\033[0m");
	}
	else
		throw std::logic_error ("\033[0;31mShrubberyCreationForm " + this->getName() + " is not signed.\033[0m");
}
