/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <rficht@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 10:21:57 by rficht            #+#    #+#             */
/*   Updated: 2024/01/20 17:11:26 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default")
{	std::cout << "RobotomyRequestForm default constructor called" << std::endl;	}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{	std::cout << "RobotomyRequestForm constructor called" << std::endl;	}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm deconstructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& rhs) : AForm(rhs)
{
	*this = rhs;
}

RobotomyRequestForm& RobotomyRequestForm::operator = (const RobotomyRequestForm& rhs)
{
	AForm::operator=(rhs);
	if (this != &rhs)
		this->_target = rhs.getTarget();	
	return *this;
}

const std::string& RobotomyRequestForm::getTarget() const
{	return(this->_target);	}

void RobotomyRequestForm::execute(const Bureaucrat& executor)
{
	executor.execForm(*this);
	if (this->getIsSigned() == false)
		throw (UnsignedExeption());
	if (this->getGradeExec() >=  executor.getGrade())
	{
		std::cout << "zzzzzzzz crrshshsh bwwwwwooshhhh bzbzbzbbwzzzzzzzz cricrich crouch shwiiiiii" << std::endl;

		srand((unsigned) time(NULL));
		int random = rand() % 2;
		if (random == 0)
			std::cout << this->_target << " was successfully Robotomised" << std::endl;
		else
			std::cout << this->_target << " robotomy has failed" << std::endl;			
	}
	else
		throw (GradeTooLowException());
}

