/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <rficht@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 13:36:05 by rficht            #+#    #+#             */
/*   Updated: 2024/01/05 09:13:30 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	
// create jean-mi
	try
	{
		Bureaucrat jeanMi = Bureaucrat("Jean-michel", 100);
	}
	catch (Bureaucrat::GradeTooLowException & e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException & e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	Bureaucrat jeanMi = Bureaucrat("Jean-michel", 100);
	
//Create form 1
	try
	{
		Form form_1 = Form("Buy new pens", 125, 90);
	}
	catch (Form::GradeTooLowException & e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	catch (Form::GradeTooHighException & e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	Form form_1 = Form("Buy new pens", 125, 90);

//Create form 2
	try
	{
		Form form_2 = Form("nuclear head launch", 25, 1);
	}
	catch (Form::GradeTooLowException & e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	catch (Form::GradeTooHighException & e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	Form form_2 = Form("nuclear head launch", 25, 1);	

//Try to sign 1
	try
	{
		form_1.beSigned(jeanMi);
	}
	catch (Form::GradeTooLowException & e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	
//Try to sign 2
	try
	{
		form_2.beSigned(jeanMi);
	}
	catch (Form::GradeTooLowException & e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	
	return 0;
}
