/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:02:06 by ouakrad           #+#    #+#             */
/*   Updated: 2023/12/15 12:03:54 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
public:
  RobotomyRequestForm();
  RobotomyRequestForm(std::string const &name);
  ~RobotomyRequestForm();
  RobotomyRequestForm(const RobotomyRequestForm &obj);
  RobotomyRequestForm &operator=(const RobotomyRequestForm &obj);
  void execute(Bureaucrat const &executor) const;
};
#endif