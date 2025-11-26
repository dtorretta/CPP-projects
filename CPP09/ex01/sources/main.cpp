/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 19:57:27 by marvin            #+#    #+#             */
/*   Updated: 2025/11/24 18:43:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

int main (int ac, char** av)
{
    if (ac != 2)
    {
        std::cout << RED << "Error: usage: \"2 + 3 * 4\"" << RESET << std::endl;
        return 1;
    }    
    try
    {
        RPN rpn; //creamos la instancia
        rpn.processOperation(std::string(av[1]));
        std::cout << rpn.getResult() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }    
    return 0;
}


/*
1) void processOperation(const char* arg);
2) void processOperation(char* arg);
3) void processOperation(const std::string& arg);
    en cuyo caso la llamada sería:
    ProcessOperation(std::string(av[1]));
*/