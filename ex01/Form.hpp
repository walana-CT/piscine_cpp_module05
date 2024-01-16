/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <rficht@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:36:04 by rficht            #+#    #+#             */
/*   Updated: 2024/01/05 09:13:21 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Form;

#ifndef FORM_HPP
# define FORM_HPP 

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Form
{
private:
	const std::string	_name;
	bool				_is_signed;
	const int			_grade_sign;
	const int			_grade_exec;

public:
	Form();
	Form(std::string name, int grade_sign, int grade_exec);
	Form(const Form& rhs);
	~Form();

	Form& operator = (const Form& rhs);

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

	const std::string& getName() const;
	const bool& getIsSigned() const;
	const int& getGradeSign() const;
	const int& getGradeExec() const;

	void beSigned(const Bureaucrat& bureaucrat);
};

std::ostream& operator<<(std::ostream& os, Form const & rhs);

#endif
