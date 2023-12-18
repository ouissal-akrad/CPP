/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:07:57 by ouakrad           #+#    #+#             */
/*   Updated: 2023/12/14 11:58:25 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
    // std::cout << "Default Constractor Called"<< std::endl;
}
Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	this->grade = copy.grade;
    // std::cout << "Copy Constractor Called"<< std::endl;
}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
    // std::cout << "Copy assignment operator called " << std::endl;
	if (this!=&copy)
		this->grade = copy.grade;
	return(*this);
}

Bureaucrat::Bureaucrat(std::string const Name, int Grade):name(Name)
{
    // std :: cout << name << " Constructor with parameters called" << std ::endl;
	if (Grade <= 0)
		throw Bureaucrat::GradeTooHighException();
	if (Grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade = Grade;
}
std::string Bureaucrat::getName()const
{
	return(this->name);
}
int Bureaucrat::getGrade()const
{
	return(this->grade);
}
void Bureaucrat::setGrade(int Grade)
{
	if (Grade <= 0)
		throw Bureaucrat::GradeTooHighException();
	if (Grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade = Grade;
}
void Bureaucrat::inc_Grade()
{
	if (this->grade <= 1)
		throw Bureaucrat::GradeTooLowException();
	this->grade--;
}
void Bureaucrat::dec_Grade()
{
	if (this->grade >= 150)
		throw Bureaucrat::GradeTooHighException();
	this->grade++;
}
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return("Grade Too High");
}
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return("Grade Too Low");
}
std ::ostream& operator<<(std::ostream& out,const Bureaucrat& a)
{
	out << a.getName() << ", bureaucrat grade " << a.getGrade() << std::endl;
	return(out);
}

void Bureaucrat::signForm(Form f)
{
	if (f.getIssigne())
		std::cout << this->name << " signed " << f.getName()  << std::endl;
	else
		std::cout << this->name << "couldn’t sign" << f.getName() << " because they need to work harder." << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    // std::cout << "Destractor Called"<< std::endl;
}