#include "../includes/Harl.hpp"


int main()
{
	Harl harl;
	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	harl.complain("RANDOM");
	   
    return 0;

}

/*
si  void complain( std::string level ); fuera STATIC, podria llamarla en el main mas facilmente:
Harl::complain(level);

pero como no es static tengo que crear un objeto de la clase y ahi llamar a la funcion 
harl.complain(level);
*/



// int main(int ac, char **av)
// {
// 	if (ac != 2)
// 	{
// 		std::cout << "Usage: <Complain>" << std::endl;
// 		std::cout << "DEBUG - INFO - WARNING - ERROR" << std::endl;
// 		return 1;
// 	}
// 	std::string level = av[1];
	
// 	Harl harl;
// 	harl.complain(level);
    
//     return 0;

// }