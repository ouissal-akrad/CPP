/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:07:54 by ouakrad           #+#    #+#             */
/*   Updated: 2023/12/20 19:01:46 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int	main(void)
{
	try
	{
		{
			Intern someRandomIntern;
			AForm *form;
			form = someRandomIntern.makeForm("Robotomy request", "Bender");
			std::cout << *form << std::endl;
			Bureaucrat mark("Beta", 1);
			mark.signForm(*form);
			std::cout << *form << std::endl;
			mark.executeForm(*form);
			delete form;
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
  	try
	{
		{
			Intern someRandomIntern;
			AForm *form;
			form = someRandomIntern.makeForm("Shrubbery Creation", "Bender");
			Bureaucrat mark("Teta", 1);
			std::cout << *form << std::endl;
			mark.signForm(*form);
			std::cout << *form << std::endl;
			mark.executeForm(*form);
			delete form;
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}    
	try
	{
		{
			Intern someRandomIntern;
			AForm *form;
			form = someRandomIntern.makeForm("Presidential pardon", "Bender");
			Bureaucrat mark("Teta", 1);
			std::cout << *form << std::endl;
			mark.signForm(*form);
			std::cout << *form << std::endl;
			mark.executeForm(*form);
			delete form;
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}