/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <rficht@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:36:04 by rficht            #+#    #+#             */
/*   Updated: 2024/01/05 09:13:21 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class AForm;

#ifndef AFORM_HPP
# define AFORM_HPP 

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class AForm
{
private:
	const std::string	_name;
	bool				_is_signed;
	const int			_grade_sign;
	const int			_grade_exec;

public:
	AForm();
	AForm(std::string name, int grade_sign, int grade_exec);
	AForm(const AForm& rhs);
	virtual ~AForm();

	AForm& operator = (const AForm& rhs);

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{	return ("grade should be lower");	}
	};
	
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{	return("grade should be higher");	}
	};

	class UnsignedExeption : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{	return("form must be signed before exec");	}
	};

	const std::string& getName() const;
	const bool& getIsSigned() const;
	const int& getGradeSign() const;
	const int& getGradeExec() const;

	void beSigned(const Bureaucrat& bureaucrat);
	virtual void execute(const Bureaucrat& executor) = 0;
};

std::ostream& operator<<(std::ostream& os, AForm const & rhs);

#endif
