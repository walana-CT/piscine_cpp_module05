/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <rficht@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 13:36:05 by rficht            #+#    #+#             */
/*   Updated: 2024/01/06 10:40:26 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
	std::cout << "generating office" << std::endl << std::endl;

	Bureaucrat jeanMi = Bureaucrat("Jean-michel", 100);
	Bureaucrat president = Bureaucrat("Mister president", 1);
	Bureaucrat jeanClaude = Bureaucrat("Jean-Claude", 145);
	Bureaucrat micheline = Bureaucrat("Micheline", 50);
	Bureaucrat claudine = Bureaucrat("Claudine", 5);
		
	ShrubberyCreationForm form1 = ShrubberyCreationForm("Garden");
	PresidentialPardonForm form2 = PresidentialPardonForm("Jean-Claude");
	RobotomyRequestForm form3 = RobotomyRequestForm("Jean-Claude");	

	//TEST 1
	std::cout << std::endl << "Testing ShrubberyCreationForm" << std::endl << std::endl;
	try
	{
		form1.beSigned(jeanClaude);
	}
	catch (AForm::GradeTooLowException & e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
		
	try
	{
		form1.execute(jeanClaude);
	}
	catch (AForm::GradeTooLowException & e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	try
	{
		form1.execute(jeanMi);
	}
	catch (AForm::GradeTooLowException & e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	//TEST 2
	std::cout << std::endl << "Testing PresidentialPardonForm" << std::endl << std::endl;
	try
	{
		form2.beSigned(jeanClaude);
	}
	catch (AForm::GradeTooLowException & e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	try
	{
		form2.beSigned(claudine);
	}
	catch (AForm::GradeTooLowException & e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
		
	try
	{
		form2.execute(jeanClaude);
	}
	catch (AForm::GradeTooLowException & e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	try
	{
		form2.execute(president);
	}
	catch (AForm::GradeTooLowException & e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	//TEST 3
	std::cout << std::endl << "Testing Robotomy" << std::endl << std::endl;
	try
	{
		form3.beSigned(micheline);
	}
	catch (AForm::GradeTooLowException & e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
		
	try
	{
		form3.execute(president);
	}
	catch (AForm::GradeTooLowException & e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl << "deleting office" << std::endl << std::endl;
	return 0;
}
