/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:07:48 by ouakrad           #+#    #+#             */
/*   Updated: 2023/12/14 14:07:37 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H
# include "Bureaucrat.hpp"
# include <exception>
# include <iostream>

class	Bureaucrat;
class Form
{
	private:
	const std::string name;
	const int grad_sign;
	const int grad_execute;
	bool is_signed;

  public:
	Form();
	Form(const std::string, const int, const int);
	Form(const Form &);
	Form &operator=(const Form &);
	std::string getName() const;
	int getGrad_sign() const;
	int getGrad_execute() const;
	bool getIssigne() const;
	~Form();
	class GradeTooHighException : public std ::exception
	{
		const char *what() const throw();
	};
	class GradeTooLowException : public std ::exception
	{
		const char *what() const throw();
	};
	void beSigned(Bureaucrat);
};
std::ostream &operator<<(std::ostream &, const Form &);
#endif