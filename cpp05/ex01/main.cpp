/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:07:54 by ouakrad           #+#    #+#             */
/*   Updated: 2023/12/14 11:51:07 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main()
{
	Bureaucrat d;
	Bureaucrat c("Bureaucrat",12);
	Form f("Bureaucrat2",1,2);
	Form a;
	a = f;
	std::cout << a.getName() << std::endl;
	try
	{
		Bureaucrat b("Bureaucrat3",12);
		Form f("Bureaucrat4",13,24);
		f.beSigned(b);
		b.signForm(f);
		std :: cout << f;
		b.setGrade(100);
		try{
			b.dec_Grade();
			b.inc_Grade();
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
		std::cout << b;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << c;
}