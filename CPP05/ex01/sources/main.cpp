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
#include "../includes/Form.hpp"

int main()
{
    std::cout << "\n--------------------------------------------------------------"  << std::endl;
    std::cout << "                         TEST 1"  << std::endl;
    std::cout << "                       sign forms"  << std::endl;
    std::cout << "--------------------------------------------------------------"  << std::endl;
    {
        try
        {
            std::cout << FORM << "\n✅ #1 create a Bureaucrat with grade 10.\n" << RESET << std::endl;
            Bureaucrat B ("Keiko", 10);
            std::cout << B << std::endl;
            
            std::cout << FORM << "\n✅ #2 create two forms, one with required grade to sign 5 and the other 15\n" << RESET << std::endl;
            Form firstForm ("42-B: Existential Approval Request", 5, 5);
            std::cout << firstForm << std::endl;
            std::cout << std::endl;
            
            Form secondForm ("NVM-0: Nevermind Declaration", 15, 15);
            std::cout << secondForm << std::endl; //esta bien asi???
            
            std::cout << FORM << "\n❌ #3 Bureocrat tries to sign the first form and fails\n" << RESET << std::endl;
            B.signForm(firstForm);
            
            std::cout << FORM << "✅ #4 Bureocrat tries to sign the seconds form with success\n" << RESET << std::endl;
            B.signForm(secondForm);
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
    std::cout << "           initializing Form with too high grade"  << std::endl;
    std::cout << "--------------------------------------------------------------"  << std::endl;
    {
        try
        {
            std::cout << FORM << "\n❌ #1 _gradeToSign too high\n" << RESET << std::endl;
            Form firstForm ("42-B: Existential Approval Request", -42, 5);
            std::cout << firstForm << std::endl;
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
    std::cout << "                         TEST 3"  << std::endl;
    std::cout << "            initializing with too low grade"  << std::endl;
    std::cout << "--------------------------------------------------------------"  << std::endl;
    {
        try
        {
            std::cout << FORM << "\n❌ #1 _gradeToSign too low\n" << RESET << std::endl;
            Form firstForm ("42-B: Existential Approval Request", 5, 160);
            std::cout << firstForm << std::endl;
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
    std::cout << "               test the copy constructor"  << std::endl;
    std::cout << "--------------------------------------------------------------"  << std::endl;
    {
        try
        {
            std::cout << FORM << "\n✅ #1 create a Form.\n" << RESET << std::endl;
            Form firstForm ("42-B: Existential Approval Request", 5, 5);
            std::cout << firstForm << std::endl;
            
            std::cout << FORM << "\n✅ #2 create a new Form as a copy of an existing object.\n" << RESET << std::endl;
            Form secondForm (firstForm);
            std::cout << secondForm << std::endl;
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
    std::cout << "                         TEST 5"  << std::endl;
    std::cout << "            test the copy assignment operator"  << std::endl;
    std::cout << "--------------------------------------------------------------"  << std::endl;
    {
        try
        {
            std::cout << FORM << "\n✅ #1 create a first Form.\n" << RESET << std::endl;
            Form firstForm ("42-B: Existential Approval Request", 5, 5);
            std::cout << firstForm << std::endl; //esta bien asi??? 
            
            std::cout << FORM << "\n✅ #2 create a second Form.\n" << RESET << std::endl;
            Form secondForm ("NVM-0: Nevermind Declaration", 15, 15);
            std::cout << secondForm << std::endl;
            
            std::cout << FORM << "\n❌ #3 copies the contents from the first form to the second form.\n" << RESET << std::endl;
            secondForm = firstForm;
            
            std::cout << firstForm << std::endl;
            std::cout << std::endl;
            std::cout << secondForm << std::endl;
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

