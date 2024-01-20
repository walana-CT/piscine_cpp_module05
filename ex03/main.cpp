/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <rficht@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 13:36:05 by rficht            #+#    #+#             */
/*   Updated: 2024/01/20 17:14:01 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"


int main(void)
{
	
	std::cout << "generating office" << std::endl << std::endl;
	
	Bureaucrat jeanMi = Bureaucrat("Jean-michel", 100);
	Bureaucrat president = Bureaucrat("Mister president", 1);
	Bureaucrat jeanClaude = Bureaucrat("Jean-Claude", 145);
	Bureaucrat micheline = Bureaucrat("Micheline", 50);
	Bureaucrat claudine = Bureaucrat("Claudine", 5);

	AForm* form1;
	AForm* form2;
	AForm* form3;

	Intern tim;

	std::cout << std::endl << "Tim doing it's job" << std::endl << std::endl;	

	try
	{	form1 = tim.makeForm("robotomy request", "intern 152");	}
	catch (Intern::UnexistingFormException & e)
	{	std::cerr << "Error: " << e.what() << std::endl;	}

	try
	{	form2 = tim.makeForm("presidential pardon", "intern 54");	}
	catch (Intern::UnexistingFormException & e)
	{	std::cerr << "Error: " << e.what() << std::endl;	}

	try
	{	form3 = tim.makeForm("chreubeuri creation", "boss office");	}
	catch (Intern::UnexistingFormException & e)
	{	std::cerr << "Error: " << e.what() << std::endl;	}

	try
	{	form3 = tim.makeForm("shrubbery creation", "boss office");	}
	catch (Intern::UnexistingFormException & e)
	{	std::cerr << "Error: " << e.what() << std::endl;	}
	
	std::cout << std::endl << "Testing if tim made good forms" << std::endl << std::endl;	

	form1->beSigned(micheline);
	form1->execute(claudine);
	form2->beSigned(claudine);
	form2->execute(president);
	form3->beSigned(jeanClaude);
	form3->execute(jeanMi);

	delete form1;
	delete form2;	
	delete form3;
		
	return 0;
}
