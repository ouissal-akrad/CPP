/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:00:44 by ouakrad           #+#    #+#             */
/*   Updated: 2023/12/20 21:37:34 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"
class	Bureaucrat;

class AForm
{
  private:
	const std::string name;
	const int grad_sign;
	const int grad_execute;
	bool is_signed;

  public:
	AForm();
	AForm(const AForm &obj);
	AForm &operator=(const AForm &obj);
	virtual ~AForm();
	AForm(const std::string, const int, const int);
	std::string getName() const;
	int getGrad_sign() const;
	int getGrad_execute() const;
	bool getIssigne() const;
    void setSign(bool);
	void beSigned(Bureaucrat);
	virtual void execute(Bureaucrat const &executor) const = 0;
	class GradeTooHighException : public std ::exception
	{
		const char *what() const throw();
	};
	class GradeTooLowException : public std ::exception
	{
		const char *what() const throw();
	}; 
};
std::ostream &operator<<(std::ostream &out, const AForm &);
#endif