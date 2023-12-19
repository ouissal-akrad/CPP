/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:22:49 by ouakrad           #+#    #+#             */
/*   Updated: 2023/12/19 13:23:51 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("Default", 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &name): AForm(name, 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj): AForm(obj.getName(), obj.getGrad_execute(), obj.getGrad_sign())
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &obj)
{
	if (this != &obj)
		this->setSign(obj.getIssigne());
	return (*this);
}
void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() <= this->getGrad_execute())
		std::cout << executor.getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	else
		throw(GradeTooLowException());
}
PresidentialPardonForm::~PresidentialPardonForm()
{
}

