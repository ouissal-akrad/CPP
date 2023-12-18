/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:07:59 by ouakrad           #+#    #+#             */
/*   Updated: 2023/12/14 11:25:35 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREUCRAT_HPP
# define BUREUCRAT_HPP
# include <exception>
# include <iostream>

class Bureaucrat
{
  private:
	const std::string name;
	int grade;

  public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat &);
	~Bureaucrat();
	Bureaucrat &operator=(const Bureaucrat &);
	std::string getName() const;
	int getGrade() const;
	void setGrade(int);
	Bureaucrat(std ::string const, int);
	void inc_Grade();
	void dec_Grade();
	class GradeTooHighException : public std::exception
	{
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		const char *what() const throw();
	};
};
std ::ostream &operator<<(std::ostream &, const Bureaucrat &);
#endif