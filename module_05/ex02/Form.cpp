/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:19:23 by afenzl            #+#    #+#             */
/*   Updated: 2022/09/30 15:01:46 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Form.hpp"

void announce(std::string name, int grade_sign, int grade_exec)
{
	std::cout << "Form " << name << " created." <<  " g_sign:" << grade_sign << " g_exec:" << grade_exec << std::endl;
}

//  -------------- CONSTRUCTORS & DESTRUCTOR ----------------

Form::Form(): name_("default"), grade_sign_(50), grade_exec_(50), sign_(false)
{ announce(name_, grade_sign_, grade_exec_); }

Form::Form(std::string name): name_(name), grade_sign_(50), grade_exec_(50), sign_(false)
{ announce(name_, grade_sign_, grade_exec_); }

Form::Form(std::string name, int both_grades): name_(name), grade_sign_(both_grades), grade_exec_(both_grades), sign_(false)
{
	std::cout << "Form " << name_ << " ";
	if (both_grades < 1)
		throw GradeTooHighException();
	if (both_grades > 150)
		throw GradeTooLowException();
	std::cout << " created." <<  " g_sign:" << grade_sign_ << " g_exec:" << grade_exec_ << std::endl;
}

Form::Form(std::string name, int grade_sign, int grade_exec): name_(name), grade_sign_(grade_sign), grade_exec_(grade_exec)
{
	std::cout << "Form " << name_ << " ";
	if (grade_sign < 1 | grade_exec < 1)
		throw GradeTooHighException();
	if (grade_sign > 150 | grade_exec > 150)
		throw GradeTooLowException();
	std::cout << " created." <<  " g_sign:" << grade_sign_ << " g_exec:" << grade_exec_ << std::endl;
}

Form::Form(Form const & copy): name_(copy.name_), grade_sign_(copy.getGrade_sign()), grade_exec_(copy.getGrade_exec()), sign_(false)
{ announce(name_, grade_sign_, grade_exec_); }

Form::~Form() {}

//  ----------------------- OPERATOR OVERLOAD -------------

Form& Form::operator= (const Form & src)
{
	if (this != &src)
		return (*this);
	return *this;
}

std::ostream&	operator<<(std::ostream &output, const Form& src)
{
	output << src.getName() << ", grade_sign:" << src.getGrade_sign() << ", grade_exec:" << src.getGrade_exec() << " and its "
		<< (src.getSign() ? "signed" : "not signed");
	return(output);
}

//  ----------------------- GETTERS -----------------------

std::string Form::getName() const { return(this->name_); }

int			Form::getGrade_sign() const { return(this->grade_sign_); }

int			Form::getGrade_exec() const { return(this->grade_exec_); }

bool		Form::getSign() const { return(this->sign_); }

//  ----------------------- METHODS -----------------------

void Form::beSigned(Bureaucrat & worker)
{
	if (worker.getGrade() <= grade_sign_)
		sign_ = true;
	else
		throw GradeTooLowException();
}

//  ----------------------- EXCEPTIONS -------------

const char * Form::GradeTooHighException::what() const throw()
{
	return ("\033[0;31mGrade too High.\033[0m");
}

const char * Form::GradeTooLowException::what() const throw()
{
	return ("\033[0;31mGrade too Low.\033[0m");
}
