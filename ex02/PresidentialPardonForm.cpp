/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <rficht@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 09:35:37 by rficht            #+#    #+#             */
/*   Updated: 2024/01/20 17:10:48 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("default")
{	std::cout << "PresidentialPardonForm default constructor called" << std::endl;	}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{	std::cout << "PresidentialPardonForm constructor called" << std::endl;	}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm deconstructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& rhs) : AForm(rhs)
{
	*this = rhs;
}

PresidentialPardonForm& PresidentialPardonForm::operator = (const PresidentialPardonForm& rhs)
{
	AForm::operator=(rhs);
	if (this != &rhs)
		this->_target = rhs.getTarget();	
	return *this;
}

const std::string& PresidentialPardonForm::getTarget() const
{	return(this->_target);	}

void PresidentialPardonForm::execute(const Bureaucrat& executor)
{
	executor.execForm(*this);
	if (this->getIsSigned() == false)
		throw (UnsignedExeption());
	if (this->getGradeExec() >=  executor.getGrade())
		std::cout << this->_target << " is forgived by his highness president Zaphod Beeblebrox" << std::endl;
	else
		throw (GradeTooLowException());
}
