/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:07:59 by ouakrad           #+#    #+#             */
/*   Updated: 2023/12/15 10:54:27 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREUCRAT_HPP
#define BUREUCRAT_HPP
#include<iostream>
#include <exception>
#include "AForm.hpp"

class AForm;
class Bureaucrat {
private:
  const std::string name;
  int grade;
public :
    Bureaucrat();
    Bureaucrat(const Bureaucrat&);
    ~Bureaucrat();
	Bureaucrat &operator=(const Bureaucrat&);
	std::string getName()const;
	int getGrade() const;
	void setGrade(int);
  	Bureaucrat(std :: string const ,int);
	void inc_Grade();
	void dec_Grade();
    class GradeTooHighException : public std::exception{
			const char *what() const throw();
		};
		class GradeTooLowException : public std::exception{
			const char *what() const throw();
		};
	void signForm(AForm &form);
  	void executeForm(AForm const &form);
};
std ::ostream& operator<<(std::ostream& ,const Bureaucrat&);
#endif