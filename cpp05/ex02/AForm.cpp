/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:29:39 by ouakrad           #+#    #+#             */
/*   Updated: 2023/12/15 11:00:57 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(): name("Default"), grad_sign(1), grad_execute(1)
{
	is_signed = false;
	// std::cout << "AForm : Default Constructor Called" << std::endl;
}

AForm::~AForm()
{
 	//std::cout << "AForm : Destructor Called" << std::endl;
}

AForm::AForm(const AForm &obj): name(obj.name), grad_sign(obj.grad_sign), grad_execute(obj.grad_execute), is_signed(obj.is_signed)
{
    // std::cout << "AForm: Copy Constructor Called" << std::endl;
}

AForm::AForm(const std::string Name, const int signe_g, const int signe_e):name(Name),grad_sign(signe_g),grad_execute(signe_e),is_signed(0)
{
    // std :: cout << " Constructor with parameters called" << std ::endl;
	if (signe_e <= 0 || signe_g <= 0)
		throw Bureaucrat::GradeTooHighException();
	if (signe_e > 150 || signe_g > 150)
		throw Bureaucrat::GradeTooLowException();
}

AForm &AForm::operator=(const AForm &obj)
{
	(this != &obj) && (this->is_signed = obj.is_signed);
	return (*this);
}

void AForm::beSigned(Bureaucrat b)
{
	if (b.getGrade() > this->grad_sign)
		throw AForm ::GradeTooLowException();
	is_signed = 1;
}

std::string AForm::getName() const
{
	return (this->name);
}
int AForm::getGrad_execute() const
{
	return (this->grad_execute);
}

bool AForm::getIssigne() const
{
	return (this->is_signed);
}

int AForm::getGrad_sign() const
{
	return (this->grad_sign);
}

void AForm::setSign(bool sign)
{
	this->is_signed = sign;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade Too High");
}
const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low");
}
std::ostream &operator<<(std::ostream& out,const AForm& a)
{
	out << "Form: " << a.getName() << ", signature grade: " << a.getGrad_sign() << ", execution grade: " << a.getGrad_execute() << std::endl;
	return(out);
}