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

Base* generate(void) //retorna un puntero a la clase A, B o C. esta clase se crea DINAMICAMENTE
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

/*
si generate retorno A --> Base* baseptr = new A()
basePtr es un puntero a la clase Base (Base*).
Pero en realidad está apuntando a un objeto A que fue creado con new A().
Usamos dynamic_cast para preguntar: ¿Esto es en realidad un A*?

esto es muy util en polimorfismo
*/
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

/*
lo mismo, pero usando una referencia
aca vamos a encadenar try - catchs
*/
void identify(Base& p) // lo mismo, pero usando una referencia
{
    try
    {
        (void)dynamic_cast<A&>(p); //(void) para ignorar el valor resultante, evita el warning de "unused value".
        std::cout << YELLOW << "A" << RESET << std::endl;
    }
    catch(...) //para capturar cualquier tipo de excepción. solo importa detectar si la conversión falló, sin importar el tipo específico del error.
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
	identify(p);  // por puntero
	
	std::cout << FORM << "\n✅ #2 Identified type with reference.\n" << RESET << std::endl;
	identify(*p); // por referencia

	std::cout << std::endl;
	delete p;
	return 0;
}
