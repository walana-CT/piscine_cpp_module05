/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <rficht@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:08:51 by rficht            #+#    #+#             */
/*   Updated: 2024/01/05 09:11:53 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	std::cout << "Bureaucrat constructor called\n";
	if (grade > 150)
		throw (GradeTooLowException());
	if (grade < 1)
		throw (GradeTooHighException());
}

Bureaucrat::Bureaucrat(const Bureaucrat& rhs) : _name(rhs._name), _grade(rhs._grade)
{}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called\n";
}

Bureaucrat & Bureaucrat::operator = (const Bureaucrat& rhs)
{
	if (this != &rhs)
		this->_grade = rhs.getGrade();
	return (*this);
}

std::ostream& operator<<(std::ostream & os, Bureaucrat const & rhs)
{
	os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() ;
	return (os);
}

const std::string& Bureaucrat::getName() const
{	return(this->_name);	}

const int& Bureaucrat::getGrade() const
{	return(this->_grade);	}

void	Bureaucrat::setGrade(const int& newGrade)
{	this->_grade = newGrade;	}

void	Bureaucrat::gradeAug()
{
	int newgrade = this->getGrade();
	newgrade --;
	if (newgrade < 1)
		throw (GradeTooHighException());
	this->setGrade(newgrade);
}

void	Bureaucrat::gradeRed()
{
	int newgrade = this->getGrade();
	newgrade ++;
	if (newgrade > 150)
		throw (GradeTooHighException());
	this->setGrade(newgrade);
}

void	Bureaucrat::signForm(const Form& form) const
{
	if (this->_grade <=  form.getGradeSign())
		std::cout << this->_name << " signed " << form.getName() << "." << std::endl; 
	else
		std::cout << this->_name << " couldn't sign " << form.getName() << " its grade is too low." << std::endl; 		
}
