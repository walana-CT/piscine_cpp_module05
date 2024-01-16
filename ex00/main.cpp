/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <rficht@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 13:36:05 by rficht            #+#    #+#             */
/*   Updated: 2024/01/04 10:48:16 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat jeanMi;
	try
	{
		jeanMi = Bureaucrat("Jean-michel", 50);
		std::cerr << jeanMi << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException & e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException & e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}


//Robert test
	Bureaucrat robert = Bureaucrat("Robert", 150);
	try
	{
		robert.gradeRed();
	}
	catch (Bureaucrat::GradeTooLowException & e)
	{
		std::cerr << robert << std::endl;
		std::cerr << "Error: " << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException & e)
	{
		std::cerr << robert << std::endl;
		std::cerr << "Error: " << e.what() << std::endl;
	}

//Micheline test
	Bureaucrat micheline = Bureaucrat("Micheline", 1);
	try
	{
		micheline.gradeAug();
		std::cerr << micheline << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException & e)
	{
		std::cerr << micheline << std::endl;
		std::cerr << "Error: " << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException & e)
	{
		std::cerr << micheline << std::endl;
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}