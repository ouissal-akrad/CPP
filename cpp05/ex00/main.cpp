/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:07:54 by ouakrad           #+#    #+#             */
/*   Updated: 2023/12/14 10:32:10 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat d;
	try
	{
		Bureaucrat b(NULL,15);
		b.setGrade(100);
		try
		{
			b.dec_Grade();
			b.inc_Grade();
		}
		catch(const std::exception &e)
		{
			std::cout << e.what() << '\n';
		}
		std::cout << b;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}