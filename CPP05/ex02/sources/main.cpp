/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 08:58:02 by dtorrett          #+#    #+#             */
/*   Updated: 2025/03/10 08:58:02 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

int main()
{
    std::cout << "\n--------------------------------------------------------------"  << std::endl;
    std::cout << "                         TEST 1"  << std::endl;
    std::cout << "                ShrubberyCreationForm"  << std::endl;
    std::cout << "--------------------------------------------------------------"  << std::endl;
    {
        try
        {
            std::cout << FORM << "\n✅ #1 create a Bureaucrat with grade 138.\n" << RESET << std::endl;
            Bureaucrat B ("Marvin", 138);
            std::cout << B << std::endl;
                       
            std::cout << FORM << "\n✅ #2 create a Shrubbery form\n" << RESET << std::endl;
            ShrubberyCreationForm F ("home");
            std::cout << F << std::endl;
            
            std::cout << FORM << "\n✅ #3 Bureocrat tries to sign the form with success\n" << RESET << std::endl;
            B.signForm(F);
            
            std::cout << FORM << "\n❌ #4 Bureocrat tries to execute the form and fails\n" << RESET << std::endl;
            B.executeForm(F); //basicamente hace firstForm.toExecute(B);
            
            std::cout << FORM << "\n✅ #5 Increment grade of Bureocrat and try to execute the form again\n" << RESET << std::endl;
            B.incrementGrade();
            B.executeForm(F); //basicamente hace firstForm.toExecute(B);
            std::cout << std::endl;
        }
        catch (std::exception &e)
        {
            std::cerr << RED << "\nException: " << e.what() << RESET << std::endl;
        }
        catch (...) //last resource
        {
            std::cerr << RED << "\nCaught an unknown exception!" << RESET << std::endl;
        }
        /*Cuando se lanza una excepción con throw, c++ destruye automáticamente todos los objetos locales (stack-allocated) 
        creados en el bloque try, hasta el punto donde ocurrió la excepción.
        luego salta al bloque catch, por eso primero se imprime el destructor*/
    }
    std::cout << "\n--------------------------------------------------------------"  << std::endl;
    std::cout << "                         TEST 2"  << std::endl;
    std::cout << "                  RobotomyRequestForm"  << std::endl;
    std::cout << "--------------------------------------------------------------"  << std::endl;
    {
        srand(time(NULL));
        try
        {
            std::cout << FORM << "\n✅ #1 create a Bureaucrat with grade 46.\n" << RESET << std::endl;
            Bureaucrat B ("Marvin", 46);
            std::cout << B << std::endl;
                       
            std::cout << FORM << "\n✅ #2 create a Robotomy Request form\n" << RESET << std::endl;
            RobotomyRequestForm F ("Toaster");
            std::cout << F << std::endl;
            
            std::cout << FORM << "\n✅ #3 Bureocrat tries to sign the form with success\n" << RESET << std::endl;
            B.signForm(F);
            
            std::cout << FORM << "\n❌ #4 Bureocrat tries to execute the form and fails\n" << RESET << std::endl;
            B.executeForm(F); //basicamente hace firstForm.toExecute(B);
            
            std::cout << FORM << "✅ #5 Increment grade of Bureocrat and try to execute the form again\n" << RESET << std::endl;
            B.incrementGrade();
            B.executeForm(F); //basicamente hace firstForm.toExecute(B);
            std::cout << std::endl;
        }
        catch (std::exception &e)
        {
            std::cerr << RED << "\nException: " << e.what() << RESET << std::endl;
        }
        catch (...) //last resource
        {
            std::cerr << RED << "\nCaught an unknown exception!" << RESET << std::endl;
        }
        /*Cuando se lanza una excepción con throw, c++ destruye automáticamente todos los objetos locales (stack-allocated) 
        creados en el bloque try, hasta el punto donde ocurrió la excepción.
        luego salta al bloque catch, por eso primero se imprime el destructor*/
    }
    std::cout << "\n--------------------------------------------------------------"  << std::endl;
    std::cout << "                         TEST 3"  << std::endl;
    std::cout << "                  PresidentialPardonForm"  << std::endl;
    std::cout << "--------------------------------------------------------------"  << std::endl;
    {
        srand(time(NULL));
        try
        {
            std::cout << FORM << "\n✅ #1 create a Bureaucrat with grade 6.\n" << RESET << std::endl;
            Bureaucrat B ("Marvin", 6);
            std::cout << B << std::endl;
                       
            std::cout << FORM << "\n✅ #2 create a Presidential Pardon form\n" << RESET << std::endl;
            PresidentialPardonForm F ("Ford Prefect");
            std::cout << F << std::endl;
            
            std::cout << FORM << "\n✅ #3 Bureocrat tries to sign the form with success\n" << RESET << std::endl;
            B.signForm(F);
            
            std::cout << FORM << "\n❌ #4 Bureocrat tries to execute the form and fails\n" << RESET << std::endl;
            B.executeForm(F); //basicamente hace firstForm.toExecute(B);
            
            std::cout << FORM << "✅ #5 Increment grade of Bureocrat and try to execute the form again\n" << RESET << std::endl;
            B.incrementGrade();
            std::cout << std::endl;
            B.executeForm(F); //basicamente hace firstForm.toExecute(B);
            std::cout << std::endl;
        }
        catch (std::exception &e)
        {
            std::cerr << RED << "\nException: " << e.what() << RESET << std::endl;
        }
        catch (...) //last resource
        {
            std::cerr << RED << "\nCaught an unknown exception!" << RESET << std::endl;
        }
        /*Cuando se lanza una excepción con throw, c++ destruye automáticamente todos los objetos locales (stack-allocated) 
        creados en el bloque try, hasta el punto donde ocurrió la excepción.
        luego salta al bloque catch, por eso primero se imprime el destructor*/
    }
    return 0;
}

