/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <rficht@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 13:51:32 by rficht            #+#    #+#             */
/*   Updated: 2024/01/02 11:01:08 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP 

# include <iostream>
# include <string>

class Bureaucrat
{
	
private:

	const std::string	_name;
	int					_grade;

public:
	Bureaucrat();
	Bureaucrat(const std::string&  name, int grade);
	Bureaucrat(const Bureaucrat& rhs);
	~Bureaucrat();

	Bureaucrat& operator = (const Bureaucrat& rhs);

	const std::string& getName() const;
	const int& getGrade() const;
	void	setGrade(const int & newGrade);

	void	gradeAug();
	void	gradeRed();

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
			{	return("you should raise your expectations\n");	}
	};
	
};

std::ostream& operator<<(std::ostream& os, Bureaucrat const & rhs);

#endif

