#include <iostream>
#include <string>
#define YELLOW	"\033[0;33m"
#define RESET	"\033[0m"

int main()
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;
	
	std::cout << YELLOW << "Memory address:" << RESET << std::endl;
	std::cout << &string << " (string)" << std::endl;
	std::cout << stringPTR << " (stringPTR*)" << std::endl;
	std::cout << &stringREF << " (stringREF&)" << std::endl;
    std::cout << std::endl;
    
	std::cout << YELLOW << "Values:" << RESET << std::endl;
	std::cout << string << " (string)" << std::endl;
	std::cout << *stringPTR << " (stringPTR*)" << std::endl;
	std::cout << stringREF << " (stringREF&)" << std::endl;
	std::cout << std::endl;
	
	std::cout << YELLOW << "after changin stringREF value:" << RESET << std::endl;
	stringREF = "MY BRAIN IS KAPUT";
	
	std::cout << &string << " / " << string << "     (string)" << std::endl;
	std::cout << stringPTR << " / " << *stringPTR << "     (stringPTR*)" << std::endl;
	std::cout << &stringREF << " / " << stringREF << "     (stringREF&)" << std::endl;
	
}

/*
para imprimir la direccion de memoria --> &name (excepto paralos pointer que solo pongo el name)

std::string &stringREF
funciona como un alias
No crea una nueva variable, sino que apunta al mismo objeto en memoria.
Esto significa que cualquier cambio que hagas en la referencia, también afectará a la variable original.


*/