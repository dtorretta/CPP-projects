#include "../includes/Point.hpp"

/*La idea es dividir el triángulo original en tres sub-triángulos usando el punto y comprobar 
si la suma de las áreas de esos tres sub-triángulos es igual al área del triángulo original. 
Si es así, el punto está dentro del triángulo; si no, el punto está fuera.*/
Fixed area(Point const a, Point const b, Point const c)
{
    Fixed area = Fixed(0.5f) * (a.getx() * (b.gety() - c.gety()) 
                + b.getx() * (c.gety() - a.gety()) 
                + c.getx() * (a.gety() - b.gety()));

    if (area < 0)
        area = area * Fixed(-1); //le pongo fixed porque estoy haciendo multiplicacion de objetos, definido como funcion dentro de fixed

    return(area);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{   
    Fixed abc = area(a, b, c);
    Fixed pab = area(point, a, b);
    Fixed pbc = area(point, b, c);
    Fixed pca = area(point, c, a);
    return((pab + pbc + pca) == abc);
}
