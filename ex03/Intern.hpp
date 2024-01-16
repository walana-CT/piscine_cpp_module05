/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <rficht@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 09:00:05 by rficht            #+#    #+#             */
/*   Updated: 2024/01/10 10:42:33 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Intern;

#ifndef INTERN_HPP
# define INTERN_HPP 

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"


class Intern
{

public:
	Intern();
	~Intern();
	Intern& operator = (const Intern& rhs);

	AForm* makeForm(const std::string& name, const std::string& target);

	class UnexistingFormException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{	return ("this type of form does not exist");	}
	};
};

#endif
