#include "../includes/Point.hpp"

// Default constructor
Point::Point(void) : _x(0) , _y(0) {}

Point::Point(const float x, const float y) : _x(x) , _y(y) {}

// The copy constructor creates a new object as a copy of an existing object.
Point::Point(const Point& src) : _x(src._x) , _y(src._y) {} //como 'x' 'y' son const si o si los tengo que inicializar aca y no en el cuerpo

// The copy assignment operator makes nothing as _x and _y are const, we cannot assign them new values
Point& Point::operator=(const Point& src)
{
    (void)src;
    return(*this);
}

Point::~Point(void) {}

Fixed Point::getx(void) const //cuando use bsp, como es una funcion fuera de la clase, no puedo acceder a los atributos privados.
{
    return(_x);
}

Fixed Point::gety(void) const
{
    return(_y);
}

