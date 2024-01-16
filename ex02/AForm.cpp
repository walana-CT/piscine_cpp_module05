/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <rficht@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 15:44:23 by rficht            #+#    #+#             */
/*   Updated: 2024/01/05 09:12:43 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("default"), _is_signed(false), _grade_sign(1), _grade_exec(1)
{}

AForm::AForm(std::string name, int grade_sign, int grade_exec) : _name(name), _is_signed(false),
												_grade_sign(grade_sign), _grade_exec(grade_exec)
{
	std::cout << "AForm constructor called\n";
	if (grade_sign > 150)
		throw (GradeTooLowException());
	if (grade_sign < 1)
		throw (GradeTooHighException());
	if (grade_exec > 150)
		throw (GradeTooLowException());
	if (grade_exec < 1)
		throw (GradeTooHighException());
}

AForm::~AForm()
{}

AForm::AForm(const AForm& rhs) : _name(rhs.getName()), _is_signed(rhs.getIsSigned()),
				_grade_sign(rhs.getGradeSign()), _grade_exec(rhs.getGradeExec())
{}

const std::string& AForm::getName() const
{	return (this->_name);	}

const bool& AForm::getIsSigned() const
{	return (this->_is_signed);	}

const int& AForm::getGradeSign() const
{	return (this->_grade_sign);	}

const int& AForm::getGradeExec() const
{	return (this->_grade_exec);	}

AForm & AForm::operator = (const AForm& rhs)
{
	if (this != &rhs)
		this->_is_signed = rhs.getIsSigned();
	return (*this);
}

std::ostream& operator<<(std::ostream & os, AForm const & rhs)
{
	os << "AForm " << rhs.getName() << ", grade to sign " << rhs.getGradeSign() << " grade to exec: " << rhs.getGradeExec();
	return (os);
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	bureaucrat.signForm(*this);
	if (this->_grade_sign >=  bureaucrat.getGrade())
		this->_is_signed = true;
	else
		throw (GradeTooLowException());
}
