#include "../includes/Point.hpp"
#include <iostream>

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main( void ) 
{
    Point A(0, 0);
    Point B(5, 0);
    Point C(0, 5);
    Point inside(2, 2);
    Point outside(6, 6);
    
    if (bsp(A, B, C, inside)) 
        std::cout << "The point 1 is inside the triangle." << std::endl;
    else
        std::cout << "The point 1 is outside the triangle." << std::endl;
        
    if (bsp(A, B, C, outside)) 
        std::cout << "The point 2 is inside the triangle." << std::endl;
    else
        std::cout << "The point 2 is outside the triangle." << std::endl;
        
    return 0;
}

/*
std::cout << "B _x: " << B.getx() << std::endl;
imprime 5 y no 5 * 256 porque sigue operando el << definido en fixed


si el operador << no estuviera sobrecargado, habria un error de compilacion ya que la consola no sabria que de todo debe imprimirse
cuando se hace << B.getx().

Dentro de la sobrecarga del operador << tengo definidio que debe imprimir el valor almancenado en _fixedPointNumber en formato float



*/