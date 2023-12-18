/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:01:57 by ouakrad           #+#    #+#             */
/*   Updated: 2023/12/16 16:25:07 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <cstddef>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("Default", 72, 45)
{
	// std::cout << "RobotomyRequestForm : Default Constructor Called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &name)
	: AForm(name, 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj)
	: AForm(obj.getName(), obj.getGrad_execute(), obj.getGrad_sign())
{
}
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj)
{
	if (this != &obj)
		this->setSign(obj.getIssigne());
	return (*this);
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() > this->getGrad_execute())
		throw GradeTooLowException();
	srand(time(NULL));
	if (rand() % 2)
		std::cout << executor.getName() << " has been robotomized successfully." << std::endl;
	else
		std::cout << " The robotomy failed." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	// std::cout << "RobotomyRequestForm : Destructor Called" << std::endl; */
}
