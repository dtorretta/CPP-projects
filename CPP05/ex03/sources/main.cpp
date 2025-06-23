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
#include "../includes/Intern.hpp"

int main()
{
    std::cout << "\n--------------------------------------------------------------"  << std::endl;
    std::cout << "                         TEST 1"  << std::endl;
    std::cout << "                  Presidental Pardon"  << std::endl;
    std::cout << "--------------------------------------------------------------"  << std::endl;
    {
        try
        {
            std::cout << FORM << "\n✅ #1 create a Intern.\n" << RESET << std::endl;
            Intern someRandomIntern;
            
            std::cout << FORM << "\n✅ #2 create form1 and test the makeform function with \'Presidental Pardon\'\n" << RESET << std::endl;
            AForm* form1 = someRandomIntern.makeForm("presidental pardon", "Bender");
            std::cout << "\n" << *form1 <<  "\n" << std::endl; //tengo que desferenciarlo xq sino imprime un puntero a la direccion de memoria
            delete form1;
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
    std::cout << "                   Robotomy Request"  << std::endl;
    std::cout << "--------------------------------------------------------------"  << std::endl;
    {
        try
        {
            std::cout << FORM << "\n✅ #1 create a Intern.\n" << RESET << std::endl;
            Intern someRandomIntern;

            std::cout << FORM << "\n✅ #2 create form1 and test the makeform function with \'Robotomy Request\'\n" << RESET << std::endl;
            AForm* form2 = someRandomIntern.makeForm("robotomy request", "Bender");
            std::cout << "\n" << *form2 <<  "\n" << std::endl;
            delete form2;
        }
        catch (std::exception &e)
        {
            std::cerr << RED << "\nException: " << e.what() << RESET << std::endl;
        }
        catch (...) //last resource
        {
            std::cerr << RED << "\nCaught an unknown exception!" << RESET << std::endl;
        }
    }
    std::cout << "\n--------------------------------------------------------------"  << std::endl;
    std::cout << "                         TEST 3"  << std::endl;
    std::cout << "                   Shrubbery Creation"  << std::endl;
    std::cout << "--------------------------------------------------------------"  << std::endl;
    {
        try
        {
            std::cout << FORM << "\n✅ #1 create a Intern.\n" << RESET << std::endl;
            Intern someRandomIntern;

            std::cout << FORM << "\n✅ #2 create form1 and test the makeform function with \'Shrubbery Creation\'\n" << RESET << std::endl;
            AForm* form3 = someRandomIntern.makeForm("shrubbery creation", "Bender");
            std::cout << "\n" << *form3 <<  "\n" << std::endl;
            delete form3;
        }
        catch (std::exception &e)
        {
            std::cerr << RED << "\nException: " << e.what() << RESET << std::endl;
        }
        catch (...) //last resource
        {
            std::cerr << RED << "\nCaught an unknown exception!" << RESET << std::endl;
        }
    }
    std::cout << "\n--------------------------------------------------------------"  << std::endl;
    std::cout << "                         TEST 4"  << std::endl;
    std::cout << "                      Random form"  << std::endl;
    std::cout << "--------------------------------------------------------------"  << std::endl;
    {
        try
        {
            std::cout << FORM << "\n✅ #1 create a Intern.\n" << RESET << std::endl;
            Intern someRandomIntern;

            std::cout << FORM << "\n❌ #2 create form1 and test the makeform function with \'Random Request\'\n" << RESET << std::endl;
            AForm* form4 = someRandomIntern.makeForm("random request", "Bender");
            std::cout << "\n" << *form4 <<  "\n" << std::endl; //no llega a ejecutarse porque salta la excepcion
            delete form4;
        }
        catch (std::exception &e)
        {
            std::cerr << RED << "\nException: " << e.what() << RESET << std::endl;
        }
        catch (...) //last resource
        {
            std::cerr << RED << "\nCaught an unknown exception!" << RESET << std::endl;
        }
    }
    return 0;
}

