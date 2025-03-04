#include "../includes/Replace.hpp"

Replace::Replace(const std::string file, const std::string s1, const std::string s2)
        : _filename(file), _s1(s1), _s2(s2) {}
        

std::string Replace::getString (const std::string str)
{
    if (str == "s1")
        return(_s1);
    if (str == "s2")
        return(_s2);
    if (str == "name")
        return(_filename);
    return "";
}

std::string Replace::ft_replace (std::string line)
{
    std::string result;
    std::string s1 = getString("s1");
    std::string s2 = getString("s2");
    size_t i = 0;
    
    size_t found = line.find(s1); //Retorna la posición (índice) donde empieza la primera aparición de s1. 
    
    if(found == std::string::npos)
        return line;
    while(found != std::string::npos)
	{
		result.append(line, i, found - i); //agrega hasta la aparicion
		result.append(s2); //agrega s2
		
		i = found + s1.length(); //ahora inicio va a estar despues de s1
		
		found = line.find(s1, i);
	}
	result.append(line, i, found - i); //si no hay mas ocurrencias, agrega lo que queda de la linea
	return result;
}

/*
.append() se usa para agregar contenido al final de un std::string
tiene varios posibles prototipos:
- result.append(s2) //agrega directamnete el string
- result.append(s2, desde, cantidad de char)
- etc

.find() busca un str dentro de otro
tiene varios posibles prototipos:
- text.find(char, pos) const; //se indica desde donde se debe empezar a buscar el char
- text.find(str, pos) const; //se indica desde donde se debe empezar a buscar el string
- text.find(str, pos, N) const; //busca en un str desde POS y va a buscar hasta N caracteres (si hay ocurrencias despues de eso no las tiene en cuenta)
- etc
*/