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

#include "../includes/Classes.hpp"
#include <cstdlib>  // para rand() y srand()
#include <ctime>    // para time()

Base* generate(void)
{
    int random = rand() % 3;
    switch (random)
    {
        case 0:
            return new A;
        case 1:
            return new B;
        case 2:
            return new C;
        default:
            return NULL;
    }
}

void identify(Base* p)
{
    if(dynamic_cast<A*>(p))
        std::cout << YELLOW << "A" << RESET << std::endl;
    else if(dynamic_cast<B*>(p))
        std::cout << YELLOW << "B" << RESET << std::endl;
    else if(dynamic_cast<C*>(p))
        std::cout << YELLOW << "C" << RESET << std::endl;
    else
        std::cout << RED << "Unknown type!" << RESET << std::endl;
}

void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << YELLOW << "A" << RESET << std::endl;
    }
    catch(...)
    {
       try
       {
            (void)dynamic_cast<B&>(p);
            std::cout << YELLOW << "B" << RESET << std::endl;
       }
       catch(...)
       {
            try
            {
                (void)dynamic_cast<C&>(p);
                std::cout << YELLOW << "C" << RESET << std::endl;
            }
            catch(...)
            {
                std::cout << RED << "Unknown type!" << RESET << std::endl;
            }
       }
    }
}

int main(void)
{
	srand(time(NULL));
	Base* p = generate();
	
	std::cout << FORM << "\n✅ #1 Identified type with pointer.\n" << RESET << std::endl;
	identify(p);  // pointer
	
	std::cout << FORM << "\n✅ #2 Identified type with reference.\n" << RESET << std::endl;
	identify(*p); // reference

	std::cout << std::endl;
	delete p;
	return 0;
}
