/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:07:38 by ouakrad           #+#    #+#             */
/*   Updated: 2023/12/19 13:12:49 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form():name("Ouissal"),grad_sign(5),grad_execute(1),is_signed(0)
{
    // std::cout << "Default Constractor Called"<< std::endl;
}

Form::Form(const std::string Name, const int signe_g, const int signe_e):name(Name),grad_sign(signe_g),grad_execute(signe_e),is_signed(0)
{
    // std :: cout << name << " Constructor with parameters called" << std ::endl;
	if (signe_e <= 0 || signe_g <= 0)
		throw Bureaucrat::GradeTooHighException();
	if (signe_e > 150 || signe_g > 150)
		throw Bureaucrat::GradeTooLowException();
}
Form::Form(const Form& copy):name(copy.name),grad_sign(copy.grad_sign),grad_execute(copy.grad_execute),is_signed(copy.is_signed)
{
    // std::cout << "Copy Constractor Called"<< std::endl;
}
Form &Form::operator=(const Form& copy)
{
	if (this != &copy)
		this->is_signed=copy.is_signed;
	return(*this);
}
std::string Form::getName()const
{
	return(this->name);
}
int Form::getGrad_sign() const
{
	return(this->grad_sign);
}
int Form::getGrad_execute() const
{
	return(this->grad_execute);
}
bool Form::getIssigne() const
{
	return(this->is_signed);
}
const char *Form::GradeTooHighException::what() const throw()
{
	return("Form Grade Too High");
}
const char *Form::GradeTooLowException::what() const throw()
{
	return("Form Grade Too Low");
}
void Form::beSigned(Bureaucrat b)
{
	if (b.getGrade() > this->grad_sign)
		throw Form ::GradeTooLowException();
	is_signed = 1;
}
std::ostream &operator<<(std::ostream& out,const Form& a)
{
	out << "Form: " << a.getName() << ", signature grade: " << a.getGrad_sign() << ", execution grade: " << a.getGrad_execute() << std::endl;
	return(out);
}

Form::~Form()
{
    // std::cout << "Destractor Called"<< std::endl;
}