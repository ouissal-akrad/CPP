/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:45:51 by ouakrad           #+#    #+#             */
/*   Updated: 2023/12/19 13:25:46 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Home", 145, 137)
{
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string const &name)
	: AForm(name, 145, 137)
{
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj)
	: AForm(obj.getName(), obj.getGrad_execute(), obj.getGrad_sign())
{
}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj) 
{
  if (this != &obj)
    this->setSign(obj.getIssigne());
  return *this;
}
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::ofstream outfile;
	outfile.open(executor.getName() + "_shrubbery",
					std ::ios::out | std::ios::trunc);
	if (outfile.good())
	{
		outfile << "      *      " << std::endl;
		outfile << "     ***     " << std::endl;
		outfile << "    *****    " << std::endl;
		outfile << "   *******   " << std::endl;
		outfile << "  *********  " << std::endl;
		outfile << " *********** " << std::endl;
		outfile << "*************" << std::endl;
		outfile << "      |      " << std::endl;
	}
	else
		std::cout << "file not created";
	outfile.close();
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
}
