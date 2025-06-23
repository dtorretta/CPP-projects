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

int main()
{
    std::cout << "\n--------------------------------------------------------------"  << std::endl;
    std::cout << "                         TEST 1"  << std::endl;
    std::cout << "                   Error in increment"  << std::endl;
    std::cout << "--------------------------------------------------------------"  << std::endl;
    {
        try
        {
            std::cout << FORM << "\n✅ #1 create a Bureaucrat with grade 1.\n" << RESET << std::endl;
            Bureaucrat B ("Keiko", 1);
            std::cout << B << std::endl;
            
            std::cout << FORM << "\n✅ #2 decrement Bureaucrat's grade.\n" << RESET << std::endl;
            B.decrementGrade();
            std::cout << "after decrement: " << B << std::endl; //no error
            
            std::cout << FORM << "\n❌ #3 Increment Bureaucrat's grade until error.\n" << RESET << std::endl;
            while(1)
            {
                B.incrementGrade();
                std::cout << "after increment: " << B << std::endl;
                std::cout << std::endl;
            }
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
    std::cout << "                  Error in decrement"  << std::endl;
    std::cout << "--------------------------------------------------------------"  << std::endl;
    {

        try
        {
            std::cout << FORM << "\n✅ #1 create a Bureaucrat with grade 1.\n" << RESET << std::endl;
            Bureaucrat B ("Keiko", 148);
            std::cout << B << std::endl;
            
            std::cout << FORM << "\n✅ #2 increment Bureaucrat's grade.\n" << RESET << std::endl;
            B.incrementGrade();
            std::cout << "after increment: " << B << std::endl;
                        
            std::cout << FORM << "\n❌ #3 decrement Bureaucrat's grade until error.\n" << RESET << std::endl;
            while (1)
            {
                B.decrementGrade();
                std::cout << "after decrement: " << B << std::endl;
                std::cout << std::endl;
            }
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
    std::cout << "               initializing with too high grade"  << std::endl;
    std::cout << "--------------------------------------------------------------"  << std::endl;
    {
        try
        {
            std::cout << FORM << "\n❌ #1 Bureaucrat's grade too high\n" << RESET << std::endl;
            Bureaucrat B ("Keiko", 0);
        }
        catch (std::exception &e)
        {
            std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
        }
        catch (...) //last resource
        {
            std::cerr << RED << "Caught an unknown exception!" << RESET << std::endl;
        }
    }
    std::cout << "\n--------------------------------------------------------------"  << std::endl;
    std::cout << "                         TEST 4"  << std::endl;
    std::cout << "            initializing with too low grade"  << std::endl;
    std::cout << "--------------------------------------------------------------"  << std::endl;
    {
        try
        {
            std::cout << FORM << "\n❌ #1 Bureaucrat's grade too low\n" << RESET << std::endl;
            Bureaucrat B ("Keiko", 160);
        }
        catch (std::exception &e)
        {
            std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
        }
        catch (...) //last resource
        {
            std::cerr << RED << "Caught an unknown exception!" << RESET << std::endl;
        }
    }
    std::cout << "\n--------------------------------------------------------------"  << std::endl;
    std::cout << "                         TEST 5"  << std::endl;
    std::cout << "              test the copy constructor"  << std::endl;
    std::cout << "--------------------------------------------------------------"  << std::endl;
    {
        try
        {
            std::cout << FORM << "\n✅ #1 create a Bureaucrat.\n" << RESET << std::endl;
            Bureaucrat B ("Keiko", 10);
            std::cout << B << std::endl;
            
            std::cout << FORM << "\n✅ #2 create a new Bureaucrat as a copy of an existing object.\n" << RESET << std::endl;
            Bureaucrat C(B);
            std::cout << C << std::endl;
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
    }
    std::cout << "\n--------------------------------------------------------------"  << std::endl;
    std::cout << "                         TEST 6"  << std::endl;
    std::cout << "              test the copy assignment operator"  << std::endl;
    std::cout << "--------------------------------------------------------------"  << std::endl;
    {
        try
        {
            std::cout << FORM << "\n✅ #1 create a Bureaucrat.\n" << RESET << std::endl;
            Bureaucrat B ("Keiko", 10);
            std::cout << B << std::endl;
            
            std::cout << FORM << "\n✅ #2 create another Bureaucrat.\n" << RESET << std::endl;
            Bureaucrat C ("Amaterasu", 20);
            std::cout << C << std::endl;
            
            std::cout << FORM << "\n✅ #3 copies the contents from the first Bureaucrat into the second.\n" << RESET << std::endl;
            C = B;
          
            std::cout << "\nFirst Bureaucrat: " << B << std::endl;
            std::cout << std::endl;
            std::cout << "Second Bureaucrat: " << C << std::endl;
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
    }
    return 0;
}

