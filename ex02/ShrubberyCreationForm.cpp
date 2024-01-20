/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <rficht@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 09:27:37 by rficht            #+#    #+#             */
/*   Updated: 2024/01/20 17:10:56 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default")
{	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;	}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{	std::cout << "ShrubberyCreationForm constructor called" << std::endl;	}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm deconstructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& rhs) : AForm(rhs)
{
	*this = rhs;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator = (const ShrubberyCreationForm& rhs)
{
	AForm::operator=(rhs);
	if (this != &rhs)
		this->_target = rhs.getTarget();	
	return *this;
}

const std::string& ShrubberyCreationForm::getTarget() const
{	return(this->_target);	}

void ShrubberyCreationForm::execute(const Bureaucrat& executor)
{
	executor.execForm(*this);
	if (this->getIsSigned() == false)
		throw (UnsignedExeption());
	if (this->getGradeExec() >=  executor.getGrade())
	{
		const char *char_targ = this->_target.c_str();
		std::ofstream outfile(char_targ);
		outfile << "          &&& &&  & &&\n\
	  && &'\'/&'\'|& ()|/ @, &&\n\
      &\\/(/&/&||/& /_/)_&/_&\n\
   &() &\\/&|()|/&\\/ '%\" & ()\n\
  &_\\_&&_\\ |& |&&/&__%_/_& &&\n\
&&   && & &| &| /& & % ()& /&&\n\
 ()&_---()&\\&\\|&&-&&--%---()~\n\
      &&     \\|||\n\
             |||\n\
             |||\n\
             |||\n\
       , -=-~  .-^- _\n" << std::endl;

	   outfile.close();	
	}

	else
		throw (GradeTooLowException());
}

