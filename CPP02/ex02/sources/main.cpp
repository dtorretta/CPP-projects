#include "../includes/Fixed.hpp"
#include <iostream>

int main( void ) 
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    
    return 0;
}

// int main() 
// {
//     // Creating Fixed-point numbers
//     Fixed a;
//     Fixed const b(Fixed(5.05f) * Fixed(2));
//     Fixed const c(10);
//     Fixed const d(2.5f);

//     // Displaying initial values
//     std::cout << "a = " << a << std::endl; //0
//     std::cout << "b = " << b << std::endl; //10.1016
//     std::cout << "c = " << c << std::endl; //10
//     std::cout << "d = " << d << std::endl; //2.50

//     // Testing arithmetic operators
//     std::cout << "\nTesting arithmetic operators:" << std::endl;
//     std::cout << "a + b = " << a + b << std::endl; //10.1016
//     std::cout << "c - d = " << c - d << std::endl; //7.5
//     std::cout << "a * b = " << a * b << std::endl; //0
//     std::cout << "c / d = " << c / d << std::endl; //4

//     // Testing comparison operators
//     std::cout << "\nTesting comparison operators:" << std::endl;
//     std::cout << "a > b: " << (a > b ? "True" : "False") << std::endl; //false
//     std::cout << "a < b: " << (a < b ? "True" : "False") << std::endl; //true
//     std::cout << "c >= d: " << (c >= d ? "True" : "False") << std::endl; //true
//     std::cout << "c <= d: " << (c <= d ? "True" : "False") << std::endl; //false
//     std::cout << "c == d: " << (c == d ? "True" : "False") << std::endl; //false
//     std::cout << "c != d: " << (c != d ? "True" : "False") << std::endl; //true

//     // Testing min and max functions
//     std::cout << "\nTesting min and max functions:" << std::endl;
//     std::cout << "min(a, b) = " << Fixed::min(a, b) << std::endl; //a = 0
//     std::cout << "max(c, d) = " << Fixed::max(c, d) << std::endl; //c = 10

//     return 0;
// }
