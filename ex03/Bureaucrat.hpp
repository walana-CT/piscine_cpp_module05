/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <rficht@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 13:51:32 by rficht            #+#    #+#             */
/*   Updated: 2024/01/06 09:25:11 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Bureaucrat;

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP 

# include "AForm.hpp"
# include <iostream>
# include <string>

class Bureaucrat
{
private:

	const std::string	_name;
	int					_grade;

public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat& rhs);
	~Bureaucrat();

	Bureaucrat& operator = (const Bureaucrat& rhs);

	const std::string& getName() const;
	const int& getGrade() const;
	void	setGrade(const int & newGrade);

	void	gradeAug();
	void	gradeRed();
	void	signForm(const AForm& form) const;
	void	execForm(const AForm& form) const;

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{	return ("You should lower your expectations");	}
	};
	
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{	return("you should raise your expectations");	}
	};
};

std::ostream& operator<<(std::ostream& os, Bureaucrat const & rhs);
#endif
