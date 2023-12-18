/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:07:54 by ouakrad           #+#    #+#             */
/*   Updated: 2023/12/16 19:34:26 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main() {
  try {
    PresidentialPardonForm F("PARDON FORM");
    Bureaucrat bu("b1", 4);
    bu.signForm(F);
    bu.executeForm(F);
  } catch (std::exception &e) {
    std::cout << e.what();
  }
  try{
    RobotomyRequestForm F("ROBOT");
    Bureaucrat bu("b2", 13);
    std::cout << F << std::endl;
    bu.signForm(F);
    std::cout << F << std::endl;
    bu.executeForm(F);
  }
  catch (std::exception &e) {
    std::cout << e.what();
  }
  try{
    ShrubberyCreationForm F("chajra");
    Bureaucrat bu("b3", 13);
    bu.signForm(F);
    bu.executeForm(F);
  }
  catch (std::exception &e) {
    std::cout << e.what();
  }
}