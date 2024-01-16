/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <rficht@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 09:00:01 by rficht            #+#    #+#             */
/*   Updated: 2024/01/10 10:45:57 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{ 	std::cout << "Intern constructor called\n";	}

Intern::~Intern()
{	std::cout << "Intern destructor called\n";	}

Intern& Intern::operator = (const Intern& rhs)
{	
	(void)rhs;
	return (*this);
}

AForm* Intern::makeForm(const std::string& name, const std::string& target)
{

	if (name == "shrubbery creation")
		return (new ShrubberyCreationForm(target));
	if (name == "robotomy request")
		return (new RobotomyRequestForm(target));
	if (name == "presidential pardon")
		return (new PresidentialPardonForm(target));
	else
		throw (UnexistingFormException());
	return (NULL);
}